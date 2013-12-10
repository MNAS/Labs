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
#include <QtCore/QDateTime>
#include <math.h>


class typing_characteristics : public QMainWindow
{
    Q_OBJECT
    
public:
    typing_characteristics();
    virtual ~typing_characteristics();
    
private slots:
     
     void setupTextEdited(const QString & text);//
     void testTextEdited(const QString & text);//
     
private:
  QDateTime dateTimeSetupStart;///<содержит время начала набора символов администратора
  QDateTime dateTimeTestStart;

  
  QList<qint64> delaySetup;
  QList<qint64> delayTest;///<содержит при наборе вреям задержки от первого символа до каждого следующего,а после преобразования - время задержки между каждым символом 
  
  void calc_M_Setup();
  void calc_M_Test();
  void calc_S_Setup();
  void calc_S_Test();
  void compare_setupS_testS();
  
  void delaySetupToDelta();///<функция преобразовывает время от 1 символа до каждого последующего во время задержки между любыми символами
  void delayTestToDelta();

private:
     void setupUI();
     void createActions();
     void createToolBars();
     void createStatusBar();
    

public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    
    QLabel *SampleTextLabel;
    QLineEdit *SampleTextLineEdit;
    
    QLabel *setupTextLabel;
    QLineEdit *setupTextLineEdit;
    
    QLabel *testTextLabel;
    QLineEdit *testTextLineEdit;
   
//    QSpacerItem *verticalSpacer;
    QStatusBar *statusbar;
    
private:
    double setupM;//переменная М - чсреднее значения для ввода символа (для ввода администратора)
    double testM;// для ввода пользователя
    double setupS;
    double testS;
};

#endif // typing_characteristics_H
