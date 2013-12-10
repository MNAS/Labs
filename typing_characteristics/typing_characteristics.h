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


class typing_characteristics : public QMainWindow
{
    Q_OBJECT
    
public:
    typing_characteristics();
    virtual ~typing_characteristics();
    
private slots:
     void sampleText();
     void setupText();
     void testText();
     
     void setupTextEdited(const QString & text);
     void testTextEdited(const QString & text);
     
private:
  QDateTime dateTimeSetupStart;
  qint64 deltaTimeSetup;
  QDateTime dateTimeTestStart;
  qint64 deltaTimeTest;
  
  QList<qint64> delaySetup;
  QList<qint64> delayTest; 
  
  double get_M_Setup();
  double get_M_Test();
  
  void delaySetupToDelta();
  void delayTestToDelta();

private:
     void setupUI();
     void createActions();
     void createMenus();
     void createToolBars();
     void createStatusBar();
    
private:
    QMenu *fileMenu;
    QAction *sampleTextAct; // Задание нового примера для ввода текста
    QAction *setupTextAct; //
    QAction *testTextAct; //
    
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
   
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    
};

#endif // typing_characteristics_H
