#pragma once
#ifndef _MainWindow_Header
#define _MainWindow_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_MainWindow.hxx>

class MainWindow
	: public ForgBaseLib::FrgBase_MainWindow
{

	Q_OBJECT

public:

	MainWindow(QWidget* parent = nullptr);

	void InitTree() override;
};

#endif // !_MainWindow_Header
