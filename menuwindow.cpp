#include "menuwindow.h"

#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include "serveurwidget.h"
#include "server.h"
#include "client.h"
#include "clientwidget.h"
/**
 * @brief MenuWindow::MenuWindow
 * @param parent
 */
MenuWindow::MenuWindow(QWidget *parent) : QWidget(parent)
{
    setFixedSize(1000,500);
    vlay = new QVBoxLayout(this);

    QBoxLayout *vlay_bouton = new QHBoxLayout();

    QPushButton *server_button = new QPushButton("Héberger une partie");
    vlay_bouton->addWidget(server_button);
    connect(server_button, SIGNAL(clicked()),this, SLOT(preparerServeur()));

    QPushButton *client_button = new QPushButton("Rejoindre une partie");
    vlay_bouton->addWidget(client_button);
    connect(client_button, SIGNAL(clicked()),this, SLOT(preparerClient()));

    vlay->addLayout(vlay_bouton);
}
/**
 * @brief MenuWindow::preparerServeur
 */
void MenuWindow::preparerServeur()
{
    conn = new Server();
    vlay->addWidget(new ServeurWidget(this, (Server*) conn));
}

/**
 * @brief MenuWindow::preparerClient
 */
void MenuWindow::preparerClient()
{
    conn = new Client();
    vlay->addWidget(new ClientWidget(this, (Client*) conn));
}
