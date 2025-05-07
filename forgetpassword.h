#ifndef FORGETPASSWORD_H
#define FORGETPASSWORD_H
#include <QTimer>
#include <QDialog>
#include <QLineEdit>

namespace Ui {
class forgetpassword;
}

class forgetpassword : public QDialog
{
    Q_OBJECT

public:
    explicit forgetpassword(QWidget *parent = nullptr);
    void sendVerificationEmail(const QString &recipientEmail, const QString &verificationCode);

    ~forgetpassword();

private slots:
    void on_pushButton_3_clicked();

    void on_verifyButton_clicked();

    void updateCountdown();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
private:
    Ui::forgetpassword *ui;
    QTimer *countdownTimer;
    int remainingSeconds;
    QList<QLineEdit*> codeFields;
    void handleInputAndFocus(QLineEdit *current, QLineEdit *next);
    QString generatedCode;
    void sendVerificationCode(const QString& email);
    QString generateRandomCode();
    QString getEnteredCode();
    QString verificationCode;
};

#endif // FORGETPASSWORD_H
