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


    setCentralWidget(centralWidget);

}





typing_characteristics::~typing_characteristics()
{}





void typing_characteristics::createActions()
{


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

        delaySetup.append(dateTimeSetupStart.msecsTo( QDateTime::currentDateTime()));//вычисляет милисекунды от первого введенного символа до текущего
	delaySetupToDelta();
	

        testTextLineEdit->setFocus();//устанавливается курсор(фокус ввода) в тестовое окно
        testTextLineEdit->setText("");//тестовая строка очищается после установки курсора(в случае,если там что-то было)
        calc_S_Setup();
    }
    else
    {
        if (i==1)//введен первый символ
        {
            dateTimeSetupStart=QDateTime::currentDateTime();//засекается текущее время
            delaySetup.clear();//очищается массив временных интервалов,в случае,если он был заполнен
        }
        else
        {
            delaySetup.append(dateTimeSetupStart.msecsTo( QDateTime::currentDateTime()));
        }
        statusBar()->showMessage(QString("Setup_Length=")+QString::number(i));//выводится количество напечатанных символов
    }
}






void typing_characteristics::testTextEdited(const QString & text)
{
    int i = text.size();
    if (text==SampleTextLineEdit->text())
    {
	delayTest.append(dateTimeTestStart.msecsTo( QDateTime::currentDateTime()));
	delayTestToDelta();
	

        testTextLineEdit->setFocus();
        testTextLineEdit->setText("");
	calc_S_Test();
	compare_setupS_testS();

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








void typing_characteristics::calc_M_Setup()
{  
  setupM=0;
  for(int i=0;i<delaySetup.size();i++)
  {
   setupM+=delaySetup[i]; 
  }
    setupM/=(delaySetup.size()+1);
    
  statusBar()->showMessage(QString("SetupM ")+QString::number(setupM));
}







void typing_characteristics::calc_M_Test()
{  
  testM=0;
  for(int i=0;i<delayTest.size();i++)
  {
   testM+=delayTest[i]; 
  }
    testM/=(delayTest.size()+1);
    
}






void typing_characteristics::calc_S_Setup()
{
  
  calc_M_Setup();
  setupS=0;
  for(int i=0;i<delaySetup.size();i++)
  {
    setupS+=sqrt((delaySetup[i]-setupM)*(delaySetup[i]-setupM));
  }
  setupS/=delaySetup.size();
    statusBar()->showMessage(QString("SetupS ")+QString::number(setupS));
}





void typing_characteristics::calc_S_Test()
{
  calc_M_Test();
  testS=0;
  for(int i=0;i<delayTest.size();i++)
  {
    testS+=sqrt((delayTest[i]-testM)*(delayTest[i]-testM));
  }
  testS/=delayTest.size();
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

void typing_characteristics::compare_setupS_testS()
{
  double precision=0.2;
  double otnosh=setupS/testS;
  if(1.0-precision <= otnosh && otnosh <= 1.0+precision )
    statusBar()->showMessage(QString("All right! It's You! ")+QString::number(otnosh));
        else
            statusBar()->showMessage(QString(" It's not You! ")+QString::number(otnosh));
}


#include "typing_characteristics.moc"
