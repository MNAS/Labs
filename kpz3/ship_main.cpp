#include "ship_main.h"


ship_main::ship_main()
{
    model= new QSqlTableModel;

    view = new QTableView;
    view->setModel(model);
    view->setWindowTitle(QString("Table"));

    setupUi();
    createActions();
    createMenus();
}

ship_main::~ship_main()
{
}

void ship_main::setupUi()
{

    if (this->objectName().isEmpty())
        this->setObjectName(QStringLiteral("MainWindow"));
    this->resize(800, 600);

    centralwidget = view;
    centralwidget->setObjectName(QStringLiteral("centralwidget"));
    verticalLayout = new QVBoxLayout(centralwidget);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    pushButton_2 = new QPushButton(centralwidget);
    pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

    verticalLayout->addWidget(pushButton_2);

    pushButton = new QPushButton(centralwidget);
    pushButton->setObjectName(QStringLiteral("pushButton"));

    verticalLayout->addWidget(pushButton);

    this->setCentralWidget(centralwidget);
    menubar = new QMenuBar(this);
    menubar->setObjectName(QStringLiteral("menubar"));
    menubar->setGeometry(QRect(0, 0, 800, 21));
    this->setMenuBar(menubar);
    statusbar = new QStatusBar(this);
    statusbar->setObjectName(QStringLiteral("statusbar"));
    this->setStatusBar(statusbar);

    //    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(this);


}

void ship_main::createActions()
{
    openDbaseAct = new QAction(QIcon(":/images/open.png"), tr("&Open"), this);
    openDbaseAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    openDbaseAct->setStatusTip(tr("Open database file."));
    connect(openDbaseAct, SIGNAL(triggered()), this, SLOT(openDbaseSlot()));

    saveDbaseAct = new QAction(QIcon(":/images/open.png"), tr("&Save"), this);
    saveDbaseAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    saveDbaseAct->setStatusTip(tr("Save current data base state."));
    connect(saveDbaseAct, SIGNAL(triggered()), this, SLOT(saveDbaseSlot()));


    testTextAct = new QAction(QIcon(":/images/open.png"), tr("E&xit"), this);
    testTextAct ->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_X));
    testTextAct ->setStatusTip(tr("Exit"));
    connect(testTextAct, SIGNAL(triggered()), this, SLOT(exitSlot()));


    insertRowAct = new QAction(QIcon(":/images/open.png"), tr("&Insert"), this);
    insertRowAct ->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_I));
    insertRowAct ->setStatusTip(tr("Insert row into database"));
    connect(insertRowAct , SIGNAL(triggered()), this, SLOT(insertSlot()));

    deleteRowAct = new QAction(QIcon(":/images/open.png"), tr("&Delete"), this);
    deleteRowAct ->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Delete));
    deleteRowAct ->setStatusTip(tr("Delete row from database"));
    connect(deleteRowAct , SIGNAL(triggered()), this, SLOT(deleteSlot()));
}

void ship_main::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openDbaseAct);
    fileMenu->addAction(saveDbaseAct);
    fileMenu->addAction(testTextAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(insertRowAct);
    editMenu->addAction(deleteRowAct);
}

void ship_main::exitSlot()
{
    this->close();
}

void ship_main::insertSlot()
{
    this->statusBar()->showMessage(QString("void ship_main::insertSlot()"));
}

void ship_main::deleteSlot()
{
    this->statusBar()->showMessage(QString("void ship_main::deleteSlot()"));
}

void ship_main::openDbaseSlot()
{
    this->statusBar()->showMessage(QString("void ship_main::openDbaseSlot()"));
}

void ship_main::saveDbaseSlot()
{
    this->statusBar()->showMessage(QString("void ship_main::saveDbaseSlot()"));
}
