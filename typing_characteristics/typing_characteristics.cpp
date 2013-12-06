#include "typing_characteristics.h"

#include <QtGui/QLabel>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QAction>
#include <QtGui/QFormLayout>
#include <QtGui/QLineEdit>

typing_characteristics::typing_characteristics()
{
    setupUI();
    createActions();
    createMenus();

    statusbar = new QStatusBar(this);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));

    setStatusBar(statusbar);


//     retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(this);
}

void typing_characteristics::setupUI()
{
    if (objectName().isEmpty())
        setObjectName(QString::fromUtf8("MainWindow"));
    this->setWindowTitle(QString::fromUtf8("Оценка компьютерного почетка"));
    resize(450, 110);
    centralWidget = new QWidget(this);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    verticalLayout = new QVBoxLayout(centralWidget);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

    formLayout = new QFormLayout();
    formLayout->setObjectName(QString::fromUtf8("formLayout"));
    formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);

    SampleTextLabel = new QLabel(centralWidget);
    SampleTextLabel->setText(QString::fromUtf8("Sample"));
    SampleTextLabel->setObjectName(QString::fromUtf8("SampleTextLabel"));
    formLayout->setWidget(1, QFormLayout::LabelRole, SampleTextLabel);

    SampleTextLineEdit = new QLineEdit(centralWidget);
    SampleTextLineEdit->setText(QString::fromUtf8("Sample Text"));
    SampleTextLineEdit->setObjectName(QString::fromUtf8("SampleTextLineEdit"));
    formLayout->setWidget(1, QFormLayout::FieldRole, SampleTextLineEdit);

    
    setupTextLabel = new QLabel(centralWidget);
    setupTextLabel->setText(QString::fromUtf8("Setup"));
    setupTextLabel->setObjectName(QString::fromUtf8("setupTextLabel"));
    formLayout->setWidget(2, QFormLayout::LabelRole, setupTextLabel);
    
    setupTextLineEdit = new QLineEdit(centralWidget);
    setupTextLineEdit->setText(QString::fromUtf8(""));
    setupTextLineEdit->setObjectName(QString::fromUtf8("setupTextLineEdit"));
    formLayout->setWidget(2, QFormLayout::FieldRole, setupTextLineEdit);
    
    
    testTextLabel = new QLabel(centralWidget);
    testTextLabel->setText(QString::fromUtf8("Test"));
    testTextLabel->setObjectName(QString::fromUtf8("testTextLabel"));
    formLayout->setWidget(3, QFormLayout::LabelRole, testTextLabel);
    
    testTextLineEdit = new QLineEdit(centralWidget);
    testTextLineEdit->setText(QString::fromUtf8(""));
    testTextLineEdit->setObjectName(QString::fromUtf8("testTextLineEdit"));
    formLayout->setWidget(3, QFormLayout::FieldRole, testTextLineEdit);
    

    verticalLayout->addLayout(formLayout);
    verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayout->addItem(verticalSpacer);

    pushButton = new QPushButton(centralWidget);
    pushButton->setText(QString::fromUtf8("Κνοπκα"));
    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    verticalLayout->addWidget(pushButton);

    setCentralWidget(centralWidget);

}

typing_characteristics::~typing_characteristics()
{}

void typing_characteristics::createActions()
{
    sampleTextAct = new QAction(QIcon(":/images/open.png"), tr("&New Sample Text..."), this);
    sampleTextAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
    sampleTextAct->setStatusTip(tr("Show the Sample Text"));
    connect(sampleTextAct, SIGNAL(triggered()), this, SLOT(newSampleText()));
    
    setupTextAct = new QAction(QIcon(":/images/open.png"), tr("&Setup..."), this);
    setupTextAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    setupTextAct->setStatusTip(tr("Show the Sample Text"));
    connect(setupTextAct, SIGNAL(triggered()), this, SLOT(setupText()));

    
    testTextAct = new QAction(QIcon(":/images/open.png"), tr("&Test..."), this);
    testTextAct ->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_T));
    testTextAct ->setStatusTip(tr("Show the Sample Text"));
    connect(testTextAct, SIGNAL(triggered()), this, SLOT(testText()));
   
    connect(setupTextLineEdit, SIGNAL(textEdited (QString)), this, SLOT(setupTextEdited(QString)));
    connect(testTextLineEdit, SIGNAL(textEdited (QString)), this, SLOT(testTextEdited(QString)));
    
//    textChanged(QString)), MainWindow, SLOT(slot1(QString)));

//   fileToolBar->addAction(openAct);
}

void typing_characteristics::setupTextEdited(const QString & text)
{
  int i = text.size();
  if (text==SampleTextLineEdit->text())
  {
    testTextLineEdit->setFocus();
    testTextLineEdit->setText("");
    statusBar()->showMessage(QString("Inpus the test text."));
  }
  else
    statusBar()->showMessage(QString("Setup_Length=")+QString::number(i));
}

void typing_characteristics::testTextEdited(const QString & text)
{
  int i = text.size();
  if (text==SampleTextLineEdit->text())
  {
    testTextLineEdit->setFocus();
    testTextLineEdit->setText("");
    statusBar()->showMessage(QString("All right! It's you!"));
  }
  else
    statusBar()->showMessage(QString("Test_Length=")+QString::number(i));
}

void typing_characteristics::newSampleText()
{
    SampleTextLineEdit->setText(QString::fromUtf8("Новый образец!"));
    setupTextLineEdit->setFocus();
}

void typing_characteristics::setupText()
{
  this->setupTextLineEdit->setText(QString::fromUtf8(""));
  setupTextLineEdit->setFocus();
}

void typing_characteristics::testText()
{
  this->testTextLineEdit->setText(QString::fromUtf8(""));
  testTextLineEdit->setFocus();
}

void typing_characteristics::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&New Sample"));
    fileMenu->addAction(sampleTextAct);
    fileMenu->addAction(setupTextAct);
    fileMenu->addAction(testTextAct);
    
//     fileMenu = menuBar()->addMenu(tr("&Setup"));
//     fileMenu->addAction(sampleTextAct);
//     
//     fileMenu = menuBar()->addMenu(tr("&Test"));
//     fileMenu->addAction(sampleTextAct);
}

// void MainWindow::createMenus()
//  {
//      fileMenu = menuBar()->addMenu(tr("&File"));
//      fileMenu->addAction(newAct);
//      fileMenu->addAction(openAct);
//      fileMenu->addAction(saveAct);
//      fileMenu->addAction(saveAsAct);
//      fileMenu->addSeparator();
//      fileMenu->addAction(exitAct);
//
//      editMenu = menuBar()->addMenu(tr("&Edit"));
//      editMenu->addAction(cutAct);
//      editMenu->addAction(copyAct);
//      editMenu->addAction(pasteAct);
//
//      menuBar()->addSeparator();
//
//      helpMenu = menuBar()->addMenu(tr("&Help"));
//      helpMenu->addAction(aboutAct);
//      helpMenu->addAction(aboutQtAct);
//  }

void typing_characteristics::createToolBars()
{}

void typing_characteristics::createStatusBar()
{}

#include "typing_characteristics.moc"
