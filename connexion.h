#ifndef CONNEXION_H
#define CONNEXION_H

#include <QObject>

class Connexion : public QObject
{
    Q_OBJECT
public:
    Connexion(QObject *parent = 0);
};

#endif // CONNEXION_H
