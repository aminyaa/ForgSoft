#pragma once
#ifndef _FrgBase_FramelessWindow_Header
#define _FrgBase_FramelessWindow_Header

#include <FrgBase_Global.hxx>

#include <QtWidgets/QWidget>

class QVBoxLayout;
class QHBoxLayout;
class QLabel;
class QToolButton;

BeginForgBaseLib

class FrgBase_WindowDragger;

class FORGBASE_EXPORT FrgBase_FramelessWindow
	: public QWidget
{

	Q_OBJECT

public:

	explicit FrgBase_FramelessWindow(QWidget* parent = Q_NULLPTR);
	virtual ~FrgBase_FramelessWindow();
	void setContent(QWidget* w);

	void SetGeometry(int PercentageOfScreen);

private:

	bool leftBorderHit(const QPoint& pos);
	bool rightBorderHit(const QPoint& pos);
	bool topBorderHit(const QPoint& pos);
	bool bottomBorderHit(const QPoint& pos);
	void styleWindow(bool bActive, bool bNoState);

	void RetranslateUi();
	void SetupUi();

public slots:

	void setWindowTitle(const QString& text);
	void setWindowIcon(const QIcon& ico);

private slots:

	void on_applicationStateChanged(Qt::ApplicationState state);
	void on_minimizeButton_clicked();
	void on_restoreButton_clicked();
	void on_maximizeButton_clicked();
	void on_closeButton_clicked();
	void on_windowTitlebar_doubleClicked();

protected:

	virtual void changeEvent(QEvent* event);
	virtual void mouseDoubleClickEvent(QMouseEvent* event);
	virtual void checkBorderDragging(QMouseEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseReleaseEvent(QMouseEvent* event);
	virtual bool eventFilter(QObject* obj, QEvent* event);

private:

	QRect m_StartGeometry;
	const quint8 CONST_DRAG_BORDER_SIZE = 15;
	bool m_bMousePressed;
	bool m_bDragTop;
	bool m_bDragLeft;
	bool m_bDragRight;
	bool m_bDragBottom;

protected:

	QVBoxLayout* verticalLayout_2;
	QWidget* windowFrame;
	QVBoxLayout* verticalLayout;
	ForgBaseLib::FrgBase_WindowDragger* windowTitlebar;
	QHBoxLayout* horizontalLayout;
	QLabel* spacer;
	QLabel* icon;
	QLabel* titleText;
	QToolButton* minimizeButton;
	QToolButton* restoreButton;
	QToolButton* maximizeButton;
	QToolButton* closeButton;
	QWidget* windowContent;
	QVBoxLayout* verticalLayout_3;
};

EndForgBaseLib

#endif // !_FrgBase_FramelessWindow_Header
