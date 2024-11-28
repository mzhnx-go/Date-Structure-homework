#ifndef USERS_H
#define USERS_H
#include <QString>
#include <QMap>
/*
 * 用户类
 * 账号密码使用字典存储
 */
class Users
{
private:
    QString account;
    QString password;

public:
    Users(QString account, QString password);
    bool matchAccountPassword(const QString &account,const QString &password ,const QMap<QString, QString> &users); //匹配账号密码是否相同
};

#endif // USERS_H
