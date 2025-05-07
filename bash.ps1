param (
    [string]$message = "Testing speech output"
)

# Setup
Add-Type -AssemblyName System.Speech
$speak = New-Object System.Speech.Synthesis.SpeechSynthesizer
$speak.SelectVoice("Microsoft Zira Desktop")
$speak.Rate = 1
$speak.Volume = 100

$tempFolder = "C:\temp"
$tempWav = "$tempFolder\speech_original.wav"
$finalWav = "$tempFolder\speech_8khz.wav"

# Ensure folder exists
New-Item -ItemType Directory -Force -Path $tempFolder | Out-Null

# Speak to WAV
$speak.SetOutputToWaveFile($tempWav)
$speak.Speak($message)
$speak.Dispose()

# Convert to 16-bit 8kHz mono using ffmpeg
& ffmpeg -y -i $tempWav -ar 8000 -ac 1 -sample_fmt s16 $finalWav

# Read raw PCM (skip 44-byte header)
$raw = [System.IO.File]::ReadAllBytes($finalWav)[44..-1]

# Parse to signed 16-bit and send via Serial
$port = new-Object System.IO.Ports.SerialPort COM4, 115200, None, 8, one
$port.Open()

for ($i = 0; $i -lt $raw.Length; $i += 2) {
    $sample = [BitConverter]::ToInt16($raw, $i)
    $text = "$sample,"
    $port.WriteLine($text)
}

$port.WriteLine("END") # signal end of transmission
$port.Close()

Write-Host "Done. Speech sent to Arduino."
