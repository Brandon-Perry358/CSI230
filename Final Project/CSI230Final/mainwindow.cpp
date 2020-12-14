/****************************************************************************
        Author:  Brandon Perry
   Last Update:  December 12, 2020
         Class:  CSI-230
      Filename:  mainwindow.cpp
   Description:
            This is a C++ program written on my windows machine with the
            intent for it to be run in linux that allows the user to browse
            files, create folders, delete folders and files while logging
            all changes in a .txt file. This program is supposed to
            represent my ability to use external libraries in order to
            create a program that can be executed on a linux system.
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

// The main window is where all the GUI elements are shown
MainWindow::MainWindow()
    : ui(new Ui::MainWindow)
{
    //This sets up the file explorer-like treeView
    ui->setupUi(this);
    model = new QFileSystemModel(this);
    //allows for files to be deleted
    model->setReadOnly(false);
    model->setRootPath(QDir::currentPath());

    ui->treeView->setModel(model);

    updateUi();
}

//basic destructor
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_quitButton_clicked()
{
    //when the quit button is clicked, the program will exit
    QCoreApplication::exit(0);
}

void MainWindow::updateUi()
{
    //updateUi was meant to push changes made to the UI due to many factors. It's now an empty function

}

//! [0]
const QString colorizer(QStringLiteral("<font color=\"%1\">%2</font><br>"));
//! [0]

// this function is related to the make directory button.
void MainWindow::on_pushButton_5_clicked()
{
    // make directory
    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid()) return;

    //this creates a prompt to name the new folder
    QString name = QInputDialog::getText(this,"Name","Enter a Name");

    if(name.isEmpty()) return;

    model->mkdir(index,name);

    //this logs the creation of the folder
    std::ofstream fout ("DirLog.txt", std::ofstream::out | std::ofstream::app);

    fout << "Directory Created: " << name.toStdString() << std::endl;

    fout.close();
}

//this function is related to the delete button
void MainWindow::on_startButton_clicked()
{
    //delete
    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid()) return;

    //checks to see if the object being deleted is a directory of a file.
    if(model->fileInfo(index).isDir()) {
        //dir
        //logs to a file that the directory is deleted
        std::ofstream fout ("DirLog.txt", std::ofstream::out | std::ofstream::app);

        //was originally going to output the name of the directory to be deleted, but there wasn't a way of doing that
        fout << "A directory was deleted." << std::endl;

        fout.close();

        //deletes the directory
        model->rmdir(index);
    }
    else {
        //file
        //logs to a file that the file is deleted
        std::ofstream fout ("DirLog.txt", std::ofstream::out | std::ofstream::app);

        //was originally going to output the name of the file to be deleted, but there wasn't a way of doing that
        fout << "A file was deleted." << std::endl;

        fout.close();

        //deletes the file
        model->remove(index);
    }
}
