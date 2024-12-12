cmake_minimum_required(VERSION 3.30)
project(PiggyBank)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Specify Qt installation path
set(QT5_DIR /opt/homebrew/opt/qt@5)
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
        PATHS ${QT5_DIR}
)

# QXlsx Library Configuration
set(QXLSX_DIR /Users/jordanponomarenko/QXlsx/QXlsx)
include_directories(${QXLSX_DIR})

# Add QXlsx source files
file(GLOB QXLSX_SRC_FILES ${QXLSX_DIR}/*.cpp)

# Add QXlsx as a static library
add_library(QXlsx STATIC ${QXLSX_SRC_FILES})

# Project source files
set(SOURCE_FILES
        main.cpp
        mainWindow.cpp
        mainWindow.h
        AuthController.cpp
        AuthController.h
        AuthViewController.cpp
        AuthViewController.h
        WebConnectivityController.cpp
        WebConnectivityController.h
)

# Create the executable
add_executable(PiggyBank ${SOURCE_FILES}
        AuthController.cpp
        AuthController.h
        AuthViewController.cpp
        AuthViewController.h
        WebConnectivityController.cpp
        WebConnectivityController.h)


# Include paths
include_directories(
        ${QT5_DIR}/lib/QtCore.framework/Headers
        ${QT5_DIR}/lib/QtGui.framework/Headers
        ${QT5_DIR}/lib/QtWidgets.framework/Headers
        /Library/Developer/CommandLineTools/SDKs/MacOSX15.1.sdk/usr/include
)

# Link libraries
target_link_libraries(PiggyBank
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets

        QXlsx
)
