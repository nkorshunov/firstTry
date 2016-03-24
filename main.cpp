#include "mainwindow.h"
#include <QApplication>
#include "gtest/gtest.h"
#include <iostream>

#include <qfiledialog.h>
#include <windows.h>




int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
   
    

	w.show();
	
	
	
	return a.exec();
}

int my_argc;
char** my_argv;



/*TEST(OneMoreTry, OpenTest){
	
	QApplication a(my_argc, my_argv);
	MainWindow w;
	QMediaPlayer player = w.getPlayer();
	/*QString filename_ = QFileDialog::getOpenFileName(&w, w.tr("Open file"), "", w.tr(""));
	if (filename_.isEmpty()) {
		return;
	}*/



	/*player.setMedia(QUrl::fromLocalFile("D:\\1.mp4"));

	ASSERT_TRUE(player.isAvailable());
	a.exit();


};*/


/*int main(int argc, char *argv[])
{
	//QCoreApplication a(argc, argv);
	my_argc = argc;
	my_argv = argv;
	testing::InitGoogleTest(&argc, argv);

	//a.exec;
	return RUN_ALL_TESTS();
}


TEST(OneMoreTry, PlayingTest){

	QApplication a(my_argc, my_argv);
	MainWindow w;
	w.on_actionOpen_triggered("D:\\1.mp4");
	w.on_actionPlay_triggered();
	ASSERT_EQ(w.getStatus(), 1);
	a.exit();


};



TEST(OneMoreTry, PausedTest){

	QApplication a(my_argc, my_argv);
	MainWindow w;
	w.on_actionOpen_triggered("D:\\1.mp4");
	w.on_actionPlay_triggered();
	w.on_actionPause_triggered();
	ASSERT_EQ(w.getStatus(), 2);
	a.exit();


};



TEST(OneMoreTry, StoppedTest){

	QApplication a(my_argc, my_argv);
	MainWindow w;
	w.on_actionOpen_triggered("D:\\1.mp4");
	w.on_actionStop_triggered();
	ASSERT_EQ(w.getStatus(), 0);
	a.exit();


};*/

