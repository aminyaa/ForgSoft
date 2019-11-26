#pragma once
#ifndef _WindowButton_Header
#define _WindowButton_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QAbstractButton>
#include <QtGui/QPixmap>

BeginFrgBaseLib

class WindowButton : public QAbstractButton
{
	Q_OBJECT

public:
	enum ButtonType
	{
		BUTTON_MINIMIZE, BUTTON_MAXIMIZE, BUTTON_CLOSE
	};

	WindowButton(ButtonType type, QWidget* parent = 0);
	~WindowButton();

protected:
	void resizeEvent(QResizeEvent* event);
	void paintEvent(QPaintEvent* event);

	void enterEvent(QEvent* event);
	void leaveEvent(QEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);

private:
	enum ButtonState
	{
		STATE_NORMAL, STATE_HOVERED, STATE_CLICKED
	};

	ButtonType  m_Type;
	ButtonState m_State;
	QPixmap* m_Normal;
	QPixmap* m_Hovered;
	QPixmap* m_Clicked;

	void InitPixmaps();
	void InitPixmap(QPixmap** pixmap);
	void InitMinimize();
	void InitMaximize();
	void InitClose();
};

EndFrgBaseLib

#endif // !_WindowButton_Header
