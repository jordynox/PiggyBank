#ifndef AUTHCONTROLLER_H
#define AUTHCONTROLLER_H

#include <QString>
#include <QObject>

class AuthController : public QObject {

    Q_OBJECT

public:
    AuthController();

    AuthController(QWidget *parent);

    ~AuthController();

    void authenticate();  // General method to trigger auth actions (login/signup)
    bool isLoggedIn() const;  // Check login status

    private slots:
        void login();   // Method for logging in
    void signup();  // Method for signing up
    void logout();  // Method for logging out

private:
    bool loggedIn;  // Track whether the user is logged in or not
};

#endif // AUTHCONTROLLER_H
