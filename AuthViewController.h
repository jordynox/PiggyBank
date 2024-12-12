// AuthViewController.h
#ifndef AUTHVIEWCONTROLLER_H
#define AUTHVIEWCONTROLLER_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>

class AuthViewController : public QDialog {
    Q_OBJECT

public:
    explicit AuthViewController(QWidget *parent = nullptr);

    private slots:
        void onLoginClicked();

private:
    QLineEdit *usernameInput;
    QLineEdit *passwordInput;
    QPushButton *loginButton;
    QVBoxLayout *layout;
};

#endif // AUTHVIEWCONTROLLER_H
