#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QProgressBar>
#include <QSlider>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
	QMediaPlayer *player_;

public slots:


    void on_actionPlay_triggered();

    void on_actionStop_triggered();

    void on_actionPause_triggered();

    void on_actionRewind_triggered();

    void on_actionOpen_triggered();
	void on_actionOpen_triggered(QString s);
	
	QMediaPlayer* getPlayer();

	int getStatus();
	int getProgress();

private:
    Ui::MainWindow *ui;
	int status;
    
    QVideoWidget *vw;
	QSlider *volumeSlider;
    QProgressBar *bar;
    QSlider *slider;
    QString filename_;
};

#endif // MAINWINDOW_H
