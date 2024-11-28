#include "users.h"

Users::Users(QString account, QString password) {
    this->account = account;
    this->password = password;
}
bool Users::matchAccountPassword(const QString &account,const QString &password ,const QMap<QString, QString> &users) {
    if (users.contains(account)) {
        if (password == users[account]) {
            return true;
        }
    }
    return false;
}
