#include "ship_main.h"
#include <QFileDialog>
#include <QMessageBox>


ship_main::ship_main() {
    view = new QTableView;
    model=0;

    setupUi();
    createActions();
    createMenus();
}

ship_main::~ship_main() {
}

void ship_main::setupUi() {

    if ( this->objectName().isEmpty() )
        this->setObjectName ( QStringLiteral ( "MainWindow" ) );
    this->resize ( 800, 600 );

    centralwidget = view;
    centralwidget->setObjectName ( QStringLiteral ( "centralwidget" ) );
    view->hide();

    this->setCentralWidget ( centralwidget );

    menubar = new QMenuBar ( this );
    menubar->setObjectName ( QStringLiteral ( "menubar" ) );
    menubar->setGeometry ( QRect ( 0, 0, 800, 21 ) );
    this->setMenuBar ( menubar );
    statusbar = new QStatusBar ( this );
    statusbar->setObjectName ( QStringLiteral ( "statusbar" ) );
    this->setStatusBar ( statusbar );

    //    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName ( this );
}

void ship_main::createActions() {
    connectDbaseAct = new QAction ( QIcon ( ":/images/open.png" ), tr ( "&Connect" ), this );
    connectDbaseAct->setShortcut ( QKeySequence ( Qt::CTRL + Qt::Key_C ) );
    connectDbaseAct->setStatusTip ( tr ( "Connect to database." ) );
    connect ( connectDbaseAct, SIGNAL ( triggered() ), this, SLOT ( connectDbaseSlot() ) );


    disConnectDbaseAct = new QAction ( QIcon ( ":/images/open.png" ), tr ( "&Disconnect" ), this );
    disConnectDbaseAct->setShortcut ( QKeySequence ( Qt::CTRL+ Qt::ALT+ Qt::SHIFT + Qt::Key_D ) );
    disConnectDbaseAct->setStatusTip ( tr ( "Disconnect from database." ) );
    connect ( disConnectDbaseAct, SIGNAL ( triggered() ), this, SLOT ( disConnectDbaseSlot() ) );

    saveDbaseAct = new QAction ( QIcon ( ":/images/open.png" ), tr ( "&Save" ), this );
    saveDbaseAct->setShortcut ( QKeySequence ( Qt::CTRL + Qt::Key_S ) );
    saveDbaseAct->setStatusTip ( tr ( "Save current data base state." ) );
    connect ( saveDbaseAct, SIGNAL ( triggered() ), this, SLOT ( saveDbaseSlot() ) );


    testTextAct = new QAction ( QIcon ( ":/images/open.png" ), tr ( "E&xit" ), this );
    testTextAct ->setShortcut ( QKeySequence ( Qt::CTRL + Qt::Key_X ) );
    testTextAct ->setStatusTip ( tr ( "Exit" ) );
    connect ( testTextAct, SIGNAL ( triggered() ), this, SLOT ( exitSlot() ) );


    insertRowAct = new QAction ( QIcon ( ":/images/open.png" ), tr ( "&Insert" ), this );
    insertRowAct ->setShortcut ( QKeySequence ( Qt::CTRL + Qt::Key_I ) );
    insertRowAct ->setStatusTip ( tr ( "Insert row into database" ) );
    connect ( insertRowAct , SIGNAL ( triggered() ), this, SLOT ( insertSlot() ) );

    deleteRowAct = new QAction ( QIcon ( ":/images/open.png" ), tr ( "&Delete" ), this );
    deleteRowAct ->setShortcut ( QKeySequence ( Qt::CTRL + Qt::Key_Delete ) );
    deleteRowAct ->setStatusTip ( tr ( "Delete row from database" ) );
    connect ( deleteRowAct , SIGNAL ( triggered() ), this, SLOT ( deleteSlot() ) );
}

void ship_main::createMenus() {
    fileMenu = menuBar()->addMenu ( tr ( "&File" ) );
    fileMenu->addAction ( connectDbaseAct );
    fileMenu->addAction ( disConnectDbaseAct );
    fileMenu->addAction ( saveDbaseAct );
    fileMenu->addAction ( testTextAct );

    editMenu = menuBar()->addMenu ( tr ( "&Edit" ) );
    editMenu->addAction ( insertRowAct );
    editMenu->addAction ( deleteRowAct );
}

void ship_main::exitSlot() {
    this->close();
}

void ship_main::insertSlot() {
    this->statusBar()->showMessage ( QString ( "void ship_main::insertSlot()" ) );
    model->insertRows(0,1);
}

void ship_main::deleteSlot() {
    this->statusBar()->showMessage ( QString ( "void ship_main::deleteSlot()" ) );
}

bool ship_main::disConnectDbaseSlot() {
    this->statusBar()->showMessage ( QString ( "bool ship_main::disConnectDbaseSlot() - stub." ) );
    view->hide();
    view->setModel ( 0 );
    delete model;
    model = 0;
    db.close();
}

bool ship_main::connectDbaseSlot() {
    this->statusBar()->showMessage ( QString ( "Connecting to DB..." ) );
    QString fileName = QFileDialog::getOpenFileName ( this,
                       tr ( "Open DB" ),
                       "/home/namatv/MyDoc/git/MNAS/Labs/kpz3",
                       tr ( "DataBase Files (*.db)" ) );

    db = QSqlDatabase::addDatabase ( "QSQLITE" );
    db.setHostName ( "localhost" );
    db.setDatabaseName ( fileName );

    if ( !db.open() ) {
        QMessageBox::critical ( 0, qApp->tr ( "Cannot open database" ),
                                qApp->tr ( "Unable to establish a database connection.\n"
                                           "This example needs SQLite support. Please read "
                                           "the Qt SQL driver documentation for information how "
                                           "to build it.\n\n"
                                           "Click Cancel to exit." ), QMessageBox::Cancel );
        return false;
    }
    model=new QSqlTableModel;

    model->setTable ( "t2" );
    model->setEditStrategy ( QSqlTableModel::OnFieldChange ); //QSqlTableModel::OnManualSubmit

    model->select();

    model->setHeaderData ( 0, Qt::Horizontal, QObject::tr ( "Name" ) );
    model->setHeaderData ( 1, Qt::Horizontal, QObject::tr ( "Country" ) );
    model->setHeaderData ( 2, Qt::Horizontal, QObject::tr ( "Year" ) );

    model->setHeaderData ( 3, Qt::Horizontal, QObject::tr ( "Genre" ) );
    model->setHeaderData ( 4, Qt::Horizontal, QObject::tr ( "Producer" ) );
    model->setHeaderData ( 5, Qt::Horizontal, QObject::tr ( "Budget" ) );


    view->setModel ( model );
    view->setWindowTitle ( QString ( "t2" ) );
    view->show();

    return true;
}

bool ship_main::connectDbase_t1_Slot() {
    this->statusBar()->showMessage ( QString ( "Connecting to DB..." ) );
    QString fileName = QFileDialog::getOpenFileName ( this,
                       tr ( "Open DB" ),
                       "/home/namatv/MyDoc/git/MNAS/Labs/kpz3",
                       tr ( "DataBase Files (*.db)" ) );

    db = QSqlDatabase::addDatabase ( "QSQLITE" );
    db.setHostName ( "localhost" );
    db.setDatabaseName ( fileName );

    if ( !db.open() ) {
        QMessageBox::critical ( 0, qApp->tr ( "Cannot open database" ),
                                qApp->tr ( "Unable to establish a database connection.\n"
                                           "This example needs SQLite support. Please read "
                                           "the Qt SQL driver documentation for information how "
                                           "to build it.\n\n"
                                           "Click Cancel to exit." ), QMessageBox::Cancel );
        return false;
    }
    model=new QSqlTableModel;

    model->setTable ( "t1" );
    model->setEditStrategy ( QSqlTableModel::OnFieldChange ); //QSqlTableModel::OnManualSubmit

    model->select();

    model->setHeaderData ( 0, Qt::Horizontal, QObject::tr ( "name" ) );
    model->setHeaderData ( 1, Qt::Horizontal, QObject::tr ( "country" ) );
    model->setHeaderData ( 2, Qt::Horizontal, QObject::tr ( "type" ) );

    model->setHeaderData ( 3, Qt::Horizontal, QObject::tr ( "length" ) );
    model->setHeaderData ( 4, Qt::Horizontal, QObject::tr ( "width" ) );
    model->setHeaderData ( 5, Qt::Horizontal, QObject::tr ( "draft" ) );

    model->setHeaderData ( 6, Qt::Horizontal, QObject::tr ( "cargo" ) );
    model->setHeaderData ( 7, Qt::Horizontal, QObject::tr ( "transportation" ) );
    model->setHeaderData ( 8, Qt::Horizontal, QObject::tr ( "quantity" ) );

    model->setHeaderData ( 9, Qt::Horizontal, QObject::tr ( "berth" ) );
    model->setHeaderData ( 10, Qt::Horizontal, QObject::tr ( "poc" ) );
    model->setHeaderData ( 11, Qt::Horizontal, QObject::tr ( "exit" ) );

    view->setModel ( model );
    view->setWindowTitle ( QString ( "t1" ) );
    view->show();

    return true;
}

void ship_main::saveDbaseSlot() {
    this->statusBar()->showMessage ( QString ( "void ship_main::saveDbaseSlot()" ) );
}
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; ;
