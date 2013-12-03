#ifndef typing_characteristics_H
#define typing_characteristics_H

#include <QtGui/QMainWindow>

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>


class typing_characteristics : public QMainWindow
{
    Q_OBJECT
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *Label;
    QLineEdit *LineEdit;
    QLabel *sdfsdfsLabel;
    QLineEdit *sdfsdfsLineEdit;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

public:
    typing_characteristics();
    virtual ~typing_characteristics();
};

#endif // typing_characteristics_H
