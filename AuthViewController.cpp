// AuthViewController.cpp
#include "AuthViewController.h"

AuthViewController::AuthViewController(QWidget *parent)
    : QDialog(parent) {

    setWindowTitle("Login");
    setFixedSize(300, 200);

    // Create input fields and button
    usernameInput = new QLineEdit(this);
    usernameInput->setPlaceholderText("Username");

    passwordInput = new QLineEdit(this);
    passwordInput->setEchoMode(QLineEdit::Password);
    passwordInput->setPlaceholderText("Password");

    loginButton = new QPushButton("Login", this);
    loginButton->setStyleSheet("background-color: #28a745; color: white;");
    connect(loginButton, &QPushButton::clicked, this, &AuthViewController::onLoginClicked);

    // Set up layout
    layout = new QVBoxLayout();
    layout->addWidget(usernameInput);
    layout->addWidget(passwordInput);
    layout->addWidget(loginButton);
    setLayout(layout);
}

void AuthViewController::onLoginClicked() {
    // Check credentials (simple example, replace with real logic)
    if (usernameInput->text() == "admin" && passwordInput->text() == "password") {
        accept(); // Close the dialog and indicate success
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}
