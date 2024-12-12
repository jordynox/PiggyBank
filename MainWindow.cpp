#include "MainWindow.h"
#include <QMessageBox>
#include <QStyleFactory>
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include "AuthController.h"
#include "AuthViewController.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      balance(0) {
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Create UI components
    balanceLabel = new QLabel("Current Balance: $0.00", this);
    balanceLabel->setAlignment(Qt::AlignCenter);
    balanceLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: #1b1f23;");

    amountInput = new QLineEdit(this);
    amountInput->setPlaceholderText("Enter amount...");
    amountInput->setStyleSheet("padding: 10px; border-radius: 5px; border: 1px solid #ccc; font-size: 16px;");

    depositButton = new QPushButton("Deposit", this);
    depositButton->setStyleSheet(
        "background-color: #0070ba; color: white; padding: 10px 20px; font-size: 16px; "
        "border-radius: 5px; border: none;");
    depositButton->setCursor(Qt::PointingHandCursor);

    withdrawButton = new QPushButton("Withdraw", this);
    withdrawButton->setStyleSheet(
        "background-color: #d9534f; color: white; padding: 10px 20px; font-size: 16px; "
        "border-radius: 5px; border: none;");
    withdrawButton->setCursor(Qt::PointingHandCursor);

    // Full-Screen Toggle Button
    fullScreenButton = new QPushButton("Toggle Full-Screen", this);
    fullScreenButton->setStyleSheet(
        "background-color: #28a745; color: white; padding: 10px 20px; font-size: 16px; "
        "border-radius: 5px; border: none;");
    fullScreenButton->setCursor(Qt::PointingHandCursor);
    connect(fullScreenButton, &QPushButton::clicked, this, &MainWindow::toggleFullScreen);

    // Connect button signals to slots
    connect(depositButton, &QPushButton::clicked, this, &MainWindow::onDepositClicked);
    connect(withdrawButton, &QPushButton::clicked, this, &MainWindow::onWithdrawClicked);

    // Layout setup
    mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addWidget(balanceLabel);

    inputLayout = new QHBoxLayout();
    inputLayout->addWidget(amountInput);
    inputLayout->addWidget(depositButton);
    inputLayout->addWidget(withdrawButton);

    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(fullScreenButton);

    setWindowTitle("Piggy Bank");

    // Set a clean look
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    centralWidget->setStyleSheet("background-color: #f7f7f7;");

    // Make the window resizable
    setMinimumSize(400, 250);
    setMaximumSize(800, 600);  // Adjust max size as needed
}

MainWindow::~MainWindow() {}

void MainWindow::onDepositClicked() {
    bool ok;
    double amount = amountInput->text().toDouble(&ok);
    if (ok && amount > 0) {
        balance += amount;
        balanceLabel->setText(QString("Current Balance: $%1").arg(balance, 0, 'f', 2));
        amountInput->clear();
    } else {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid amount to deposit.");
    }
}

void MainWindow::onWithdrawClicked() {
    bool ok;
    double amount = amountInput->text().toDouble(&ok);
    if (ok && amount > 0) {
        if (amount <= balance) {
            balance -= amount;
            balanceLabel->setText(QString("Current Balance: $%1").arg(balance, 0, 'f', 2));
            amountInput->clear();
        } else {
            QMessageBox::warning(this, "Insufficient Funds", "You do not have enough money in your piggy bank.");
        }
    } else {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid amount to withdraw.");
    }
}

// Full-Screen Toggle
void MainWindow::toggleFullScreen() {
    if (isFullScreen()) {
        showNormal();
    } else {
        showFullScreen();
    }
}
void MainWindow::openAuthDialog() {
    // Create an instance of AuthViewController (login dialog)
    AuthViewController authView;

    // Execute the dialog and check if it was accepted
    if (authView.exec() == QDialog::Accepted) {
        // Handle successful login (if the user clicked "Login" and credentials were correct)
        qDebug() << "Login successful!";
        // Proceed with main window initialization or other logic
    } else {
        // Handle failed login (if the user clicked "Cancel" or entered incorrect credentials)
        qDebug() << "Login failed!";
    }
}