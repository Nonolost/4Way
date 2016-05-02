#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include <QBoxLayout>
#include "connexion.h"

class MenuWindow : public QWidget
{
    Q_OBJECT
public:
    MenuWindow(QWidget *parent = Q_NULLPTR);

private slots:
    void preparerServeur();
    void preparerClient();

private:
    QBoxLayout *vlay;
    Connexion *conn;
};

#endif // MENUWINDOW_H
