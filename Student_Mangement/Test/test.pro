QT += core gui testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += tst_file_test.cpp \
           ../global.cpp \
           ../user/student.cpp \
           ../filehandler.cpp \

# 添加头文件搜索路径
INCLUDEPATH += $$PWD/../user \
               $$PWD/../

# 添加头文件
HEADERS += \
        ../global.h \
        ../user/student.h \
        ../filehandler.h \

# 添加测试文件
TESTS += tst_file_test.cpp
