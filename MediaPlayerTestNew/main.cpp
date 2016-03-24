
#include <mainwindow.h>
#include <QtWidgets\qapplication.h>

#include "gtest/gtest.h"
#include <iostream>



#include <windows.h>


int new_my_argc;
char** new_my_argv;

int main(int argc, char *argv[])
{

	new_my_argc = argc;
	new_my_argv = argv;
	testing::InitGoogleTest(&argc, argv);

	//a.exec;
	return RUN_ALL_TESTS();
}


TEST(MainWindow, PlayingTest){

	QApplication a(new_my_argc, new_my_argv);
	MainWindow w;
	
	w.on_actionOpen_triggered("D:\\1.mp4");
	w.on_actionPlay_triggered();
	ASSERT_EQ(w.getStatus(), 1);
	a.exit();


};



TEST(MainWindow, PausedTest){

	QApplication a(new_my_argc, new_my_argv);
	MainWindow w;
	w.on_actionOpen_triggered("D:\\1.mp4");
	w.on_actionPlay_triggered();
	w.on_actionPause_triggered();
	ASSERT_EQ(w.getStatus(), 2);
	a.exit();


};


TEST(MainWindow, RewindTest){

	QApplication a(new_my_argc, new_my_argv);
	MainWindow w;
	w.on_actionOpen_triggered("D:\\1.mp4");
	w.on_actionPlay_triggered();
	Sleep(5000);
	w.on_actionRewind_triggered();
	
	ASSERT_EQ(w.getProgress(),0);
	a.exit();


};



TEST(MainWindow, StoppedTest){

	QApplication a(new_my_argc, new_my_argv);
	MainWindow w;
	w.on_actionOpen_triggered("D:\\1.mp4");
	w.on_actionStop_triggered();
	ASSERT_EQ(w.getStatus(), 0);
	a.exit();


};

TEST(MainWindow, ErrorTest){

	QApplication a(new_my_argc, new_my_argv);
	MainWindow w;
	w.on_actionOpen_triggered("D:\\2.txt");

	ASSERT_EQ(w.getStatus(), 4);
	a.exit();


};


