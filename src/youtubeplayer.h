

#ifndef YOUTUBEPLAYER_H
#define YOUTUBEPLAYER_H
#include "ui_youtubeplayer.h"
#include <iostream>
using namespace std;

#include "qmplayer.h"

class YoutubePlayer : public QWidget, public Ui_YoutubePlayer
{
    Q_OBJECT
public:
    YoutubePlayer( QWidget *parent = 0, Qt::WFlags f = 0 );
    ~YoutubePlayer();

private slots:
    void SearchButton_clicked();
    void newLine();
private:
   QMplayer * m_v;
   QProcess* m_Process;
   QStringList a;
  QStringList b; 

};

#endif
