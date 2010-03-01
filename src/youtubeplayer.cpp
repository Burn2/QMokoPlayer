

#include "youtubeplayer.h"
#include <qpushbutton.h>
#include <qsoftmenubar.h>
#include <QAction>
#include <QMenu>
#include <QDir>
#include <QProcess>
#include <QString>
#include <QMessageBox>

/*
 *  Constructs a Example which is a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'
 */
YoutubePlayer::YoutubePlayer(QWidget *parent, Qt::WFlags f)
    : QWidget(parent, f)
{
	setupUi(this); // reads the .ui file to determine widgets and layout
    // Construct context menu, available to the user via Qtopia's soft menu bar.
    QMenu *menu = QSoftMenuBar::menuFor(this);
	QAction *actionClose = new QAction(QIcon("close"),tr("Close"),this);
    connect(actionClose,SIGNAL(triggered()), this, SLOT(close()));
    connect(SearchButton,SIGNAL(clicked()), this, SLOT(SearchButton_clicked()));
    menu->addAction(actionClose);
    QSoftMenuBar::setHelpEnabled(this,false);
    
    

}


//fonction to convert a string in a char*
char* convertSToC(string str)
 {
    size_t size = str.size() + 1;
    char * buffer = new char[ size ];
    strncpy( buffer, str.c_str(), size );
    return buffer;
 }




/*
 *  Destroys the object and frees any allocated resources
 */
YoutubePlayer::~YoutubePlayer()
{
    // no need to delete child widgets, Qt does it all for us
}


/*
 *  Every time the RadioButton button is clicked, this slot will be invoked
 *  (see QMetaObject::connectSlotsByName()).
 */
void YoutubePlayer::SearchButton_clicked()
{
	
 if (QFile::exists("/usr/bin/python2.5"))
	{
	 //We put use a pipe to use the script to find the link and add all the title and stock all the url	
	 a.clear();
	 b.clear();
	 m_Process=new QProcess();
	 connect(m_Process,SIGNAL(readyReadStandardOutput ()),this,  SLOT(newLine()));
	 //m_Process->setProcessChannelMode(QProcess::ForwardedChannels);
	 m_Process->setReadChannel ( QProcess::StandardOutput );
	 QStringList args;
	 args<<"-g"<<"-e"<<"-m"<<"ytsearch10:"+ lineEditText->text().remove('\n').remove ('\r')+" ";
	 m_Process->start("youtube-dl", args, QIODevice::ReadWrite);
	 
	 
	 
	 m_Process->waitForFinished();
	 
	 
	 //a.insert(0,"Goldman puisque tu pars");
	 //b.insert(0,"http://v1.cache3.c.youtube.com/videoplayback?ip=0.0.0.0&sparams=id%2Cexpire%2Cip%2Cipbits%2Citag%2Calgorithm%2Cburst%2Cfactor&fexp=903201&algorithm=throttle-factor&itag=17&ipbits=0&burst=40&sver=3&expire=1263258000&key=yt1&signature=B43D929AD21FA5E74F5AB6DA8FDBEA7394D08B1C.6CFC389DAAFE5D9800169C7C790D92701B460596&factor=1.25&id=bd6625114e7a463e&redirect_counter=1");	
	  m_v = new QMplayer();
	  m_v->setList(a,b);
	  m_v->show();
	}
  else
  {
	
   QMessageBox::critical(this, tr("QMokoPlayer"), tr("You must install python by doing \"apt-get update\" and then \"apt-get install python\" and confirm."));	  
  }
}
void YoutubePlayer::newLine()
{
  m_Process->setReadChannel ( QProcess::StandardOutput );
	while (m_Process->canReadLine ())
	{
		
	
	  a<<QString(m_Process->readLine()).remove('\n').remove ('\r')	;
	  b<<QString(m_Process->readLine()).remove('\n').remove ('\r');
	}
}
