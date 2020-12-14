/****************************************************************************
        Author:  Brandon Perry
   Last Update:  December 12, 2020
         Class:  CSI-230
      Filename:  main.cpp
   Description:
            This is a C++ program written on my windows machine with the
            intent for it to be run in linux that allows the user to browse
            files, create folders, delete folders and files while logging
            all changes in a .txt file. This program is supposed to
            represent my ability to use external libraries in order to
            create a program that can be executed on a linux system.
****************************************************************************/
//includes
#include <QApplication>
#include <QFileSystemModel>

#include "mainwindow.h"

//main function
int main(int argc, char *argv[])
{
    QT_USE_NAMESPACE

    //creates the window
    QApplication a(argc, argv);
    MainWindow window;
    window.show();

    return a.exec();
}
