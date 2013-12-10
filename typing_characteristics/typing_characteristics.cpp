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
    connect(sampleTextAct, SIGNAL(triggered()), this, SLOT(sampleText()));

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
        deltaTimeSetup=dateTimeSetupStart.msecsTo( QDateTime::currentDateTime());
        delaySetup.append(dateTimeSetupStart.msecsTo( QDateTime::currentDateTime()));
	delaySetupToDelta();
	
        statusBar()->showMessage(QString::fromUtf8("Δτ[ms]=")+QString::number(deltaTimeSetup));

        testTextLineEdit->setFocus();
        testTextLineEdit->setText("");
//        statusBar()->showMessage(QString("Inpus the test text."));
    }
    else
    {
        if (i==1)
        {
            dateTimeSetupStart=QDateTime::currentDateTime();
            delaySetup.clear();
        }
        else
        {
            delaySetup.append(dateTimeSetupStart.msecsTo( QDateTime::currentDateTime()));
        }
        statusBar()->showMessage(QString("Setup_Length=")+QString::number(i));
    }
}

void typing_characteristics::testTextEdited(const QString & text)
{
    int i = text.size();
    if (text==SampleTextLineEdit->text())
    {
        deltaTimeTest=dateTimeTestStart.msecsTo( QDateTime::currentDateTime());
	delayTest.append(dateTimeTestStart.msecsTo( QDateTime::currentDateTime()));
	delayTestToDelta();
	
        statusBar()->showMessage(QString::fromUtf8("Δτ[ms]=")+QString::number(deltaTimeTest));

        testTextLineEdit->setFocus();
        testTextLineEdit->setText("");
        double SetupTemp=double (deltaTimeSetup)/double (i);
        double TestTemp=double (deltaTimeTest)/double (i);
        double partTest_Setup=TestTemp/SetupTemp;
        double precision=0.1;
        if(1.0-precision <= partTest_Setup && partTest_Setup <= 1.0+precision )
            statusBar()->showMessage(QString("All right! It's You! ")+QString::number(partTest_Setup));
        else
            statusBar()->showMessage(QString("So! So! It's not You! ")+QString::number(partTest_Setup));
    }
    else
    {
        if (i==1)
        {
            dateTimeTestStart=QDateTime::currentDateTime();
	    delayTest.clear();
        }
        else
        {
	  delayTest.append(dateTimeTestStart.msecsTo( QDateTime::currentDateTime()));
	}
        statusBar()->showMessage(QString("Test_Length=")+QString::number(i));
    }
}

void typing_characteristics::sampleText()
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
}

void typing_characteristics::createToolBars()
{}

void typing_characteristics::createStatusBar()
{}

double typing_characteristics::get_M_Setup()
{  
}

double typing_characteristics::get_M_Test()
{  
}
  
void typing_characteristics::delaySetupToDelta()
{
  qint64 delay_summ = 0;
  for(int i=0;i<delaySetup.size();++i)
  {
    qint64 delta=delaySetup.at(i);
    delaySetup[i]-=delay_summ;
    delay_summ=delta;
  }
}

void typing_characteristics::delayTestToDelta()
{
    qint64 delay_summ = 0;
  for(int i=0;i<delayTest.size();++i)
  {
    qint64 delta=delayTest.at(i);
    delayTest[i]-=delay_summ;
    delay_summ=delta;
  }
}

#include "typing_characteristics.moc"
