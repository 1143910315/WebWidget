#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QString curPath = QDir::currentPath();
    view = new QWebEngineView(this);
    view->setGeometry(this->geometry());
    // view->load(QUrl("http://www.baidu.com/"));
    view->load(QUrl::fromLocalFile(curPath + "/../WebWidget/html/index.html"));
    webChannel = new QWebChannel();
    webMessage = new WebMessage();
    webChannel->registerObject("api", webMessage);
    view->page()->setWebChannel(webChannel);
    view->show();
}

MainWindow::~MainWindow() {
    view->load(QUrl(""));
    delete ui;
}
