#ifndef CONNEXION_H
#define CONNEXION_H

#include <QObject>

class Connexion : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Connexion::Connexion
     * @param parent
     */
    Connexion(QObject *parent = 0);
};

#endif // CONNEXION_H
