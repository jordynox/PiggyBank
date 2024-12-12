#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>

// Forward declaration of AuthController class
class AuthController;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    private slots:
        void onDepositClicked();
    void onWithdrawClicked();
    void toggleFullScreen(); // Slot for full-screen toggle
    void openAuthDialog();

private:
    QLabel *balanceLabel;
    QLineEdit *amountInput;
    QPushButton *depositButton;
    QPushButton *withdrawButton;
    QPushButton *fullScreenButton; // Button to toggle full-screen
    double balance;
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *inputLayout;

    AuthController *authController; // Pointer to AuthController for login
};

#endif // MAINWINDOW_H
