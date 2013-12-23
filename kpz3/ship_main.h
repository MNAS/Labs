#ifndef SHIP_MAIN_H
#define SHIP_MAIN_H

#include <QMainWindow>
#include <QApplication>
#include <QSqlDatabase>
#include <QTextStream>
#include <QSqlQuery>
#include <QMainWindow>
#include <QtSql>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMenuBar>
#include <QStatusBar>
#include <QTableView>


class ship_main: public QMainWindow {
    Q_OBJECT

public:
    ship_main();
    virtual ~ship_main();

private slots:

    void exitSlot();
    void insertSlot();
    void deleteSlot();
    bool connectDbaseSlot();
    bool disConnectDbaseSlot();    
    void saveDbaseSlot();

private:
    void setupUi();
    void createActions();
    void createMenus();

private:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QTableView *view;
private:
    QSqlDatabase db;
    QSqlTableModel *model;

private:
    QMenu *fileMenu;
    QMenu *editMenu;

    QAction *connectDbaseAct; // Задание нового примера для ввода текста
    QAction *disConnectDbaseAct; // Задание нового примера для ввода текста
    QAction *saveDbaseAct; //
    QAction *testTextAct; //

    QAction *insertRowAct; //
    QAction *deleteRowAct; //

};

#endif // SHIP_MAIN_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
