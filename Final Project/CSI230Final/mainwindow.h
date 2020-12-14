/****************************************************************************
        Author:  Brandon Perry
   Last Update:  December 12, 2020
         Class:  CSI-230
      Filename:  mainwindow.h
   Description:
            This is a C++ program written on my windows machine with the
            intent for it to be run in linux that allows the user to browse
            files, create folders, delete folders and files while logging
            all changes in a .txt file. This program is supposed to
            represent my ability to use external libraries in order to
            create a program that can be executed on a linux system.
****************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//includes
#include <QMainWindow>
#include <QFileSystemModel>
#include <QtCore>
#include <QtGui>
#include <QInputDialog>
#include <QFileInfo>
#include <fstream>

QT_BEGIN_NAMESPACE

//establishes the class that is used in mainwindow.cpp
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private slots:
    void on_quitButton_clicked();

    void on_pushButton_5_clicked();

    void on_startButton_clicked();

private:
    void updateUi();
    Ui::MainWindow *ui = nullptr;
    QFileSystemModel *model;
};

#endif // MAINWINDOW_H
