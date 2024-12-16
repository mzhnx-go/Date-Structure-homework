QT += core gui testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += tst_file_test.cpp \
           ../global.cpp \
    ../user/optioncourse.cpp \
    ../user/score.cpp \
           ../user/student.cpp \
           ../user/course.cpp \
           ../filehandler.cpp \
    ../user/tableattribute.cpp \
    ../utils.cpp

# 添加头文件搜索路径
INCLUDEPATH += $$PWD/../user \
               $$PWD/../

# 添加头文件
HEADERS += \
        ../global.h \
    ../user/optioncourse.h \
    ../user/score.h \
        ../user/student.h \
        ../user/course.h \
        ../filehandler.h \
    ../user/tableattribute.h \
    ../utils.h

# 添加测试文件
TESTS += tst_file_test.cpp
