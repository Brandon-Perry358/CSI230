/****************************************************************************
        Author:  Brandon Perry
   Last Update:  December 12, 2020
         Class:  CSI-230
      Filename:  README.md
   Description:
            This is a C++ program written on my windows machine with the
            intent for it to be run in linux that allows the user to browse
            files, create folders, delete folders and files while logging
            all changes in a .txt file. This program is supposed to
            represent my ability to use external libraries in order to
            create a program that can be executed on a linux system.
****************************************************************************/

Original proposal for the final project:
GENERAL CONCEPT:
I want to be able to grab the information of files stored on a linux media server 
on my local network and save a list of that info to a file while also having a 
program to browse those files. 

MEDIA SERVER:
I will create a media server with either a raspberry pi or another linux vm with 
a tool called Samba that will allow other devices on my network to be able to 
access the network drive. I have used Samba before to create a network drive 
accessible from a windows machine, but not a linux machine. I doubt that it will 
be much different, but it will still be something I need to learn.

EXTERNAL LIBRARY:
I will use the Qt library to create a program that is able to read, display, 
and open different file types and their information with a GUI. This will be 
the hard part of the project for me because I haven’t really worked with any 
major library before aside from the last two labs, and those were already kinda 
complicated for me. 

MY OWN LIBRARY & INPUTS/OUTPUTS:
I will create a library that is able to grab file information from the network 
drive and save it to a text file. This will run at the start and will overwrite 
the previous file’s information in order to provide a more accurate list.

SYSTEM:
I will write and run all of this code from my Ubuntu VM (which seems to be more
stable than the PopOS one I had been using for the majority of the class, so it
should be easier to work with) If I have more time to implement more features, 
I would like to be able to launch programs from within my main program like VLC
and a program like paint on the Ubuntu system so that files can be used all from
within my program.



Deviations from the original proposal:
-Decided not to use a linux media server as it would be a waste of time
-was forced to develop on my windows machine becasue I didn't have enough space
in any of my VMs for the installation of Qt and its IDE, but it's universal, so
it can run on a linux machine
-had to limit some features like the log of file activities due to complications
with the libraries.
-entire system's files act as input as opposed to a random txt file


There are three main C++ files in the project:
main.cpp
mainwindow.cpp
mainwindow.h

Qt Libraries used in the program:
QMainWindow
QFileSystemModel
QtCore
QtGui
QInputDialog
QFileInfo

Program is very simple to start up and use. Once it is run, there will be a window
that appears with a treeView of your systems files and info relating to them, as
well as three buttons: Make Directory, Delete, and Quit. These buttons are pretty
self-explanatory. The Make Directory button will create a folder wherever you may
want it in your system. You will be prompted to enter a name for the new folder,
and then it will be created. The creation of Folders is logged in the DirLog.txt
file. The Delete button will delete files and folders from your system, and
deletion is also logged in DirLog.txt. Lastly, the Quit button exits the program.
