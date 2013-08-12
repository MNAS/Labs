#include "berkunsky-kosynka.h"

#include <QtGui/QLabel>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QAction>
#include "card.h"

berkunsky_kosynka::berkunsky_kosynka()
{
    QLabel* l = new QLabel( this );
    l->setText( "Hello World!" );
    setCentralWidget( l );
    
    QMenu* menuFile=menuBar()->addMenu( "File" );
    QMenu* menuHelp=menuBar()->addMenu( "Help" );
    
    QAction* a = new QAction(this);
    a->setText( "Quit" );
    connect(a, SIGNAL(triggered()), SLOT(close()) );

    
    QAction* b = new QAction(this);
    b->setText( "New Game" );
    connect(b, SIGNAL(triggered()), SLOT(close()) );
    
    QAction* h = new QAction(this);
    h->setText( "Help" );
    connect(h, SIGNAL(triggered()), SLOT(close()) );
    
    menuFile->addAction( b );
    menuFile->addAction( a );
    
    menuHelp->addAction( h );
    
}

berkunsky_kosynka::~berkunsky_kosynka()
{}

#include "berkunsky-kosynka.moc"
