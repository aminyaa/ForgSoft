#pragma once
#ifndef _FrgMenu_Globals_Header
#define _FrgMenu_Globals_Header

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QAction>
#include <QtGui/QIcon>

#include <FrgBaseGlobals.hxx>

BeginFrgBaseLib

#define CreateAction(Action, IconAddress, Text, Parent, Shortcut, StatusTip)\
Action = new QAction(QIcon(IconAddress), QMainWindow::tr(Text), Parent);\
Action->setShortcut(QMainWindow::tr(Shortcut));\
Action->setStatusTip(QMainWindow::tr(StatusTip));

EndFrgBaseLib

#endif // !_FrgMenu_Globals_Header
