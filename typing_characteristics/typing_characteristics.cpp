#include "typing_characteristics.h"

#include <QtGui/QLabel>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QAction>
#include <QtGui/QFormLayout>
#include <QtGui/QLineEdit>

typing_characteristics::typing_characteristics()
{



    if (objectName().isEmpty())
        setObjectName(QString::fromUtf8("MainWindow"));
    this->setWindowTitle(QString::fromUtf8("Оценка компьютерного почетка"));
    resize(300, 100);
    centralwidget = new QWidget(this);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    verticalLayout = new QVBoxLayout(centralwidget);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

    formLayout = new QFormLayout();
    formLayout->setObjectName(QString::fromUtf8("formLayout"));
    formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);

    Label = new QLabel(centralwidget);
    Label->setText(QString::fromUtf8("Ναμε"));
    Label->setObjectName(QString::fromUtf8("Label"));
    formLayout->setWidget(1, QFormLayout::LabelRole, Label);
    
    LineEdit = new QLineEdit(centralwidget);
    LineEdit->setText(QString::fromUtf8("Ναμε"));
    LineEdit->setObjectName(QString::fromUtf8("LineEdit"));
    formLayout->setWidget(1, QFormLayout::FieldRole, LineEdit);
    

    sdfsdfsLabel = new QLabel(centralwidget);
    sdfsdfsLabel->setObjectName(QString::fromUtf8("sdfsdfsLabel"));
    formLayout->setWidget(2, QFormLayout::LabelRole, sdfsdfsLabel);
    sdfsdfsLineEdit = new QLineEdit(centralwidget);
    sdfsdfsLineEdit->setObjectName(QString::fromUtf8("sdfsdfsLineEdit"));
    formLayout->setWidget(2, QFormLayout::FieldRole, sdfsdfsLineEdit);

    verticalLayout->addLayout(formLayout);

    verticalSpacer = new QSpacerItem(20, 258, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout->addItem(verticalSpacer);

    pushButton = new QPushButton(centralwidget);
    pushButton->setText(QString::fromUtf8("Κνοπκα"));
    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    verticalLayout->addWidget(pushButton);

    setCentralWidget(centralwidget);

    menubar = new QMenuBar(this);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 800, 20));

    setMenuBar(menubar);
    statusbar = new QStatusBar(this);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));

    setStatusBar(statusbar);

//     retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(this);
}



typing_characteristics::~typing_characteristics()
{}

#include "typing_characteristics.moc"
