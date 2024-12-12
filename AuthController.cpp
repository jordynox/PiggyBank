#include "AuthController.h"
#include <QDebug>

AuthController::AuthController() : loggedIn(false) {
    // Constructor can initialize variables
}

void AuthController::authenticate() {
    if (loggedIn) {
        qDebug() << "Already logged in.";
        logout();
    } else {
        qDebug() << "Not logged in, proceeding with login...";
        login();
    }
}

void AuthController::login() {
    // Simulate login process, e.g., checking credentials
    // For a real application, you'd likely interact with a database or API here
    loggedIn = true;  // Assuming login is successful for now
    qDebug() << "User logged in successfully.";
}

void AuthController::signup() {
    // Handle signup logic (e.g., check if user already exists, etc.)
    qDebug() << "Signing up the user...";
    // Here, you'd typically send data to a server to create an account
}

void AuthController::logout() {
    // Handle logout logic (e.g., remove session, reset UI, etc.)
    loggedIn = false;
    qDebug() << "User logged out.";
}

bool AuthController::isLoggedIn() const {
    return loggedIn;
}

AuthController::~AuthController() {
    // Cleanup if needed
}
