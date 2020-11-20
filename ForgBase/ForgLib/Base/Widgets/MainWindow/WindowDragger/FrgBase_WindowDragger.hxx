#pragma once
#ifndef _FrgBase_WindowDragger_Header
#define _FrgBase_WindowDragger_Header

#include <FrgBase_Global.hxx>

#include <QWidget>

class QMouseEvent;

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_WindowDragger
	: public QWidget
{

	Q_OBJECT

public:

	explicit FrgBase_WindowDragger(QWidget* parent = Q_NULLPTR);
	virtual ~FrgBase_WindowDragger() {}

signals:

	void doubleClicked();

protected:

	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void mouseDoubleClickEvent(QMouseEvent* event);
	void paintEvent(QPaintEvent* event);

protected:

	QPoint mousePos;
	QPoint wndPos;
	bool mousePressed;
};

EndForgBaseLib

#endif // !_FrgBase_WindowDragger_Header
