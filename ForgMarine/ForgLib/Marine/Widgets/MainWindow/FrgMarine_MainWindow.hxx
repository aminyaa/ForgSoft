#pragma once
#ifndef _FrgMarine_MainWindow_Header
#define _FrgMarine_MainWindow_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_MainWindow.hxx>

namespace ForgBaseLib
{
	class FrgBase_TabWidget;
}

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_MainWindow
	: public ForgBaseLib::FrgBase_MainWindow
{
	Q_OBJECT

public:

	FrgMarine_MainWindow(QWidget* parent = NullPtr);

	ForgBaseLib::FrgBase_TabWidget* GetTabWidget() const { return theTabWidget_; }

	void ShowTabWidget(QWidget* widget, const QString& title);
	void SetTabText(QWidget* widget, const QString& title);
	void SetTabText(int index, const QString& title);

protected:

	void InitMainWindow() override;

private:

	ForgBaseLib::FrgBase_TabWidget* theTabWidget_ = NullPtr;
};

EndForgMarineLib

#endif // !_FrgMarine_MainWindow_Header
