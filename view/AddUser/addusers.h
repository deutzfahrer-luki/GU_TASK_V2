#ifndef ADDUSERS_H
#define ADDUSERS_H

#include <QDialog>

namespace Ui {
class AddUsers;
}

class AddUsers : public QDialog
{
    Q_OBJECT

public:
    explicit AddUsers(QWidget *parent = nullptr);
    ~AddUsers();

private:
    Ui::AddUsers *ui;
};

#endif // ADDUSERS_H
