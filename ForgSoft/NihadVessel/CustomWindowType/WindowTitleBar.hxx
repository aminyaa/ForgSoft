#pragma once
#ifndef _WindowTitleBar_Header
#define _WindowTitleBar_Header

#include <FrgBaseGlobals.hxx>
#include <QtWidgets/QWidget>

class QPixmap;
class QResizeEvent;
class QPaintEvent;
class QLabel;

BeginFrgBaseLib

class WindowButton;

class WindowTitleBar : public QWidget
{
	Q_OBJECT

public:

	WindowTitleBar(QWidget* parent = 0);

	~WindowTitleBar();

	FrgGetMacro(QLabel*, Title, m_Title);

public slots:

	void UpdateWindowTitle();
	void Minimized();
	void Maximized();
	void Quit();

protected:

	void resizeEvent(QResizeEvent* event);

	void paintEvent(QPaintEvent* event);

private:

	QPixmap* m_Cache = FrgNullPtr;

	QLabel* m_Title = FrgNullPtr;

	WindowButton* m_Minimize = FrgNullPtr;
	WindowButton* m_Maximize = FrgNullPtr;
	WindowButton* m_Close = FrgNullPtr;
};

EndFrgBaseLib

#endif // !_WindowTitleBar_Header
