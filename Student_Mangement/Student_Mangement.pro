QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    filehandler.cpp \
    global.cpp \
    main.cpp \
    mainwindow.cpp \
    page_login.cpp \
    page_modify.cpp \
    show_optional_course.cpp \
    studentwindow.cpp \
    teacherwindow.cpp \
    user/course.cpp \
    user/optioncourse.cpp \
    user/score.cpp \
    user/student.cpp \
    user/tableattribute.cpp \
    user/users.cpp \
    utils.cpp

HEADERS += \
    filehandler.h \
    global.h \
    mainwindow.h \
    page_login.h \
    page_modify.h \
    show_optional_course.h \
    studentwindow.h \
    teacherwindow.h \
    user/course.h \
    user/optioncourse.h \
    user/score.h \
    user/student.h \
    user/tableattribute.h \
    user/users.h \
    utils.h

FORMS += \
    mainwindow.ui \
    page_login.ui \
    page_modify.ui \
    show_optional_course.ui \
    studentwindow.ui \
    teacherwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/resource.qrc

QT += core gui testlib

SUBDIRS += \
    Test/stu_test/stu_test.pro
