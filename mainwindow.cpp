#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDialog>
#include <QDebug>
#include <QLabel>
#include <QFile>
#include <QFileInfo>

#include <QAudioFormat>
#include <QAudioOutput>
#include <QVideoWidget>
#include <qmediaplayer.h>

#include <iostream>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player_=new QMediaPlayer(this);
    vw=new QVideoWidget(this);
    player_->setVideoOutput(vw);
    this->setCentralWidget(vw);
    slider =  new QSlider(this);
    bar = new QProgressBar(this);

	volumeSlider = new QSlider(this);
	volumeSlider->setOrientation(Qt::Horizontal);
    slider->setOrientation(Qt::Horizontal);
	ui->statusBar->addPermanentWidget(new QLabel("Volume"));
	ui->statusBar->addPermanentWidget(volumeSlider);
	ui->statusBar->addPermanentWidget(new QLabel("Duration"));
	ui->statusBar->addPermanentWidget(slider);
	ui->statusBar->addPermanentWidget(bar);

	status = 0;
	player_->setVolume(volumeSlider->value());


    connect (player_,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect (player_,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
    connect (slider,&QSlider::sliderMoved,player_,&QMediaPlayer::setPosition);



    connect (player_,&QMediaPlayer::durationChanged,bar,&QProgressBar::setMaximum);
    connect (player_,&QMediaPlayer::positionChanged,bar,&QProgressBar::setValue);
	connect(volumeSlider, SIGNAL(valueChanged(int)), player_, SLOT(setVolume(int)));




}

MainWindow::~MainWindow()
{
    delete player_;
    delete ui;
}


void MainWindow::on_actionPlay_triggered()
{
   

    player_->play();

	if (player_->state() == QMediaPlayer::PlayingState){
		status = 1;
		ui->statusBar->showMessage("Playing");
	}
}

void MainWindow::on_actionStop_triggered()
{


    player_->stop();
	if (player_->state() == QMediaPlayer::StoppedState){
			status = 0;
		 ui->statusBar->showMessage("Stopped");
	}

}

void MainWindow::on_actionPause_triggered()
{
  

    player_->pause();
	if (player_->state() == QMediaPlayer::PausedState){
		 status = 2;
		 ui->statusBar->showMessage("Paused");
	}
}

void MainWindow::on_actionRewind_triggered()
{
    if (!player_->isAudioAvailable()) {
          ui->statusBar->showMessage("Error");
        return;
    }
	
    player_->stop();
    player_->play();

}

int MainWindow::getStatus(){
	
		
	return status;

}

int MainWindow::getProgress(){
	return bar->value();
}

QMediaPlayer* MainWindow::getPlayer(){
	
	return player_;
}

void MainWindow::on_actionOpen_triggered()
{
    filename_ = QFileDialog::getOpenFileName(this, tr("Open file"), "", tr(""));
    if (filename_.isEmpty()) {
        return;
    }

	

    player_->setMedia(QUrl::fromLocalFile(filename_));
	
 
    if (!player_->isVideoAvailable()){
		status = 4;
		
        this->setFixedSize(481, 90);;
        ui->statusBar->showMessage("OnlyAudio");
  

    }
	

    player_->play();
}



void MainWindow::on_actionOpen_triggered(QString s)
{
	
	player_->setMedia(QUrl::fromLocalFile(s));
	if (!player_->isVideoAvailable()){
		status = 4;
	}
	player_->play();
}

