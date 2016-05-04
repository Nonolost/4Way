#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class Client;

class ClientWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief ClientWidget::ClientWidget
     * @param parent
     * @param client objet Client lié au Widget
     */
    ClientWidget(QWidget *parent = Q_NULLPTR, Client *client = 0);

    /**
     * @brief ClientWidget::setEtat
     * @param etat
     */
    void setEtat(QString etat);
    QLabel *getEtat();

private slots:
    /**
     * @brief ClientWidget::checkSaisie
     * verifie si les information on été rentré pour activer le bouton de validation
     */
    void checkSaisie();

    /**
     * @brief ClientWidget::startConnexion
     * essaye de se connecter au serveur
     */
    void startConnexion();

    /**
     * @brief ClientWidget::closeConnexion
     */
    void closeConnexion();

private:
    QLineEdit *pseudo;
    QLineEdit *ip_serveur, *port_serveur;
    QLabel *etat_connexion;
    QPushButton *connexion_bouton;
    Client *client;
};

#endif // CLIENTWIDGET_H
