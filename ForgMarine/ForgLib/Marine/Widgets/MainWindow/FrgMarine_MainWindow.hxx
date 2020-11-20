#pragma once
#ifndef _FrgMarine_MainWindow_Header
#define _FrgMarine_MainWindow_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_MainWindow.hxx>

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_MainWindow
	: public ForgBaseLib::FrgBase_MainWindow
{
	Q_OBJECT

public:

	FrgMarine_MainWindow(QWidget* parent = nullptr);

protected:
	
	void InitTree() override;
};

EndForgMarineLib

#endif // !_FrgMarine_MainWindow_Header
