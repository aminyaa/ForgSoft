#pragma once
#ifndef _CustomWindow_Header
#define _CustomWindow_Header

#include <FrgBaseGlobals.hxx>
#include <QtWidgets/QWidget>

class QGridLayout;
class QSizeGrip;

BeginFrgBaseLib

class WindowTitleBar;

class CustomWindow : public QWidget
{
	Q_OBJECT

public:
	CustomWindow(QWidget* parent = 0);
	~CustomWindow();

	void paintEvent(QPaintEvent* event);

	void setWindowTitle(const QString& title);

signals:

	void WindowTitleChanged();

protected:
	void showEvent(QShowEvent* event);
	void resizeEvent(QResizeEvent* event);

private:
	void CenterOnScreen();

	WindowTitleBar* m_TitleBar = FrgNullPtr; 
	QGridLayout* m_MainLayout = FrgNullPtr;
	QSizeGrip* m_SizeGrip = FrgNullPtr;
};

EndFrgBaseLib

#endif // !_CustomWindow_Header
