#include <QtTest>

// add necessary includes here

class file_test : public QObject
{
    Q_OBJECT

public:
    file_test();
    ~file_test();

private slots:
    void test_case1();
};

file_test::file_test() {}

file_test::~file_test() {}

void file_test::test_case1() {}

QTEST_APPLESS_MAIN(file_test)

#include "tst_file_test.moc"
