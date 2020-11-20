#include <FrgBase_FramelessWindow.hxx>
#include <FrgBase_WindowDragger.hxx>

#include <QApplication>
#include <QDesktopWidget>
#include <QGraphicsDropShadowEffect>
#include <QScreen>
#include <QMouseEvent>

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

ForgBaseLib::FrgBase_FramelessWindow::FrgBase_FramelessWindow(QWidget* parent)
	: QWidget(parent)
	, m_bMousePressed(false)
	, m_bDragTop(false)
	, m_bDragLeft(false)
	, m_bDragRight(false)
	, m_bDragBottom(false)
{
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
	// append minimize button flag in case of windows,
	// for correct windows native handling of minimize function
#if defined(Q_OS_WIN)
	setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
#endif
	setAttribute(Qt::WA_NoSystemBackground, true);
	setAttribute(Qt::WA_TranslucentBackground);

	SetupUi();
	restoreButton->setVisible(false);

	// shadow under window title text
	QGraphicsDropShadowEffect* textShadow = new QGraphicsDropShadowEffect;
	textShadow->setBlurRadius(4.0);
	textShadow->setColor(QColor(0, 0, 0));
	textShadow->setOffset(0.0);
	titleText->setGraphicsEffect(textShadow);

	// window shadow
	QGraphicsDropShadowEffect* windowShadow = new QGraphicsDropShadowEffect;
	windowShadow->setBlurRadius(9.0);
	windowShadow->setColor(palette().color(QPalette::Highlight));
	windowShadow->setOffset(0.0);
	windowFrame->setGraphicsEffect(windowShadow);

	QObject::connect(qApp, &QGuiApplication::applicationStateChanged, this,
		&FrgBase_FramelessWindow::on_applicationStateChanged);
	setMouseTracking(true);

	// important to watch mouse move from all child widgets
	QApplication::instance()->installEventFilter(this);
}

ForgBaseLib::FrgBase_FramelessWindow::~FrgBase_FramelessWindow()
{

}

void ForgBaseLib::FrgBase_FramelessWindow::on_restoreButton_clicked()
{
	restoreButton->setVisible(false);

	maximizeButton->setVisible(true);
	setWindowState(Qt::WindowNoState);
	// on MacOS this hack makes sure the
	// background window is repaint correctly
	hide();
	show();
}

void ForgBaseLib::FrgBase_FramelessWindow::on_maximizeButton_clicked()
{
	restoreButton->setVisible(true);
	maximizeButton->setVisible(false);
	this->setWindowState(Qt::WindowMaximized);
	this->showMaximized();
	styleWindow(true, false);
}

void ForgBaseLib::FrgBase_FramelessWindow::changeEvent(QEvent* event)
{
	if (event->type() == QEvent::WindowStateChange) {
		if (windowState().testFlag(Qt::WindowNoState)) {
			restoreButton->setVisible(false);
			maximizeButton->setVisible(true);
			styleWindow(true, true);
			event->ignore();
		}
		else if (windowState().testFlag(Qt::WindowMaximized)) {
			restoreButton->setVisible(true);
			maximizeButton->setVisible(false);
			styleWindow(true, false);
			event->ignore();
		}
	}
	event->accept();
}

void ForgBaseLib::FrgBase_FramelessWindow::setContent(QWidget* w)
{
	windowContent->layout()->addWidget(w);
}

void ForgBaseLib::FrgBase_FramelessWindow::SetGeometry(int PercentageOfScreen)
{
	int x, y, w, h;
	QRect rect = QApplication::desktop()->screenGeometry();
	int screen_width = rect.width();
	int screen_height = rect.height();

	//Represent Percentage in decimals
	float PercentageOfScreenFloat = (float)PercentageOfScreen / 100;

	//Calculate w and h
	w = (PercentageOfScreenFloat * screen_width);
	h = (PercentageOfScreenFloat * screen_height);

	//Check for max and min size hints
	int minW = this->minimumWidth();
	int minH = this->minimumHeight();

	int maxW = this->maximumWidth();
	int maxH = this->maximumHeight();

	if (w < minW || h < minH)
	{
		w = minW;
		h = minH;
	}
	else if (w > maxW || h > maxH)
	{
		w = maxW;
		h = maxH;
	}

	//Now Calculate x and y
	x = screen_width / 2;
	x = x - w / 2;

	y = screen_height / 2;
	y = y - h / 2;

	this->setGeometry(x, y, w, h);
	windowContent->setGeometry(x, y, w, h);
	windowFrame->setGeometry(x, y, w, h);
	layout()->setGeometry(QRect(x, y, w, h));
}

void ForgBaseLib::FrgBase_FramelessWindow::setWindowTitle(const QString& text)
{
	titleText->setText(text);
}

void ForgBaseLib::FrgBase_FramelessWindow::setWindowIcon(const QIcon& ico)
{
	icon->setPixmap(ico.pixmap(16, 16));
}

void ForgBaseLib::FrgBase_FramelessWindow::styleWindow(bool bActive, bool bNoState)
{
	if (bActive) {
		if (bNoState) {
			layout()->setMargin(15);
			windowTitlebar->setStyleSheet(QStringLiteral(
				"#windowTitlebar{border: 0px none palette(shadow); "
				"border-top-left-radius:5px; border-top-right-radius:5px; "
				"background-color:palette(shadow); height:20px;}"));
			windowFrame->setStyleSheet(QStringLiteral(
				"#windowFrame{border:1px solid palette(highlight); border-radius:5px "
				"5px 5px 5px; background-color:palette(Window);}"));
			QGraphicsEffect* oldShadow = windowFrame->graphicsEffect();
			if (oldShadow) delete oldShadow;
			QGraphicsDropShadowEffect* windowShadow = new QGraphicsDropShadowEffect;
			windowShadow->setBlurRadius(9.0);
			windowShadow->setColor(palette().color(QPalette::Highlight));
			windowShadow->setOffset(0.0);
			windowFrame->setGraphicsEffect(windowShadow);
		}
		else {
			layout()->setMargin(0);
			windowTitlebar->setStyleSheet(QStringLiteral(
				"#windowTitlebar{border: 0px none palette(shadow); "
				"border-top-left-radius:0px; border-top-right-radius:0px; "
				"background-color:palette(shadow); height:20px;}"));
			windowFrame->setStyleSheet(QStringLiteral(
				"#windowFrame{border:1px solid palette(dark); border-radius:0px 0px "
				"0px 0px; background-color:palette(Window);}"));
			QGraphicsEffect* oldShadow = windowFrame->graphicsEffect();
			if (oldShadow) delete oldShadow;
			windowFrame->setGraphicsEffect(nullptr);
		}  // if (bNoState) else maximize
	}
	else {
		if (bNoState) {
			layout()->setMargin(15);
			windowTitlebar->setStyleSheet(QStringLiteral(
				"#windowTitlebar{border: 0px none palette(shadow); "
				"border-top-left-radius:5px; border-top-right-radius:5px; "
				"background-color:palette(dark); height:20px;}"));
			windowFrame->setStyleSheet(QStringLiteral(
				"#windowFrame{border:1px solid #000000; border-radius:5px 5px 5px "
				"5px; background-color:palette(Window);}"));
			QGraphicsEffect* oldShadow = windowFrame->graphicsEffect();
			if (oldShadow) delete oldShadow;
			QGraphicsDropShadowEffect* windowShadow = new QGraphicsDropShadowEffect;
			windowShadow->setBlurRadius(9.0);
			windowShadow->setColor(palette().color(QPalette::Shadow));
			windowShadow->setOffset(0.0);
			windowFrame->setGraphicsEffect(windowShadow);
		}
		else {
			layout()->setMargin(0);
			windowTitlebar->setStyleSheet(QStringLiteral(
				"#titlebarWidget{border: 0px none palette(shadow); "
				"border-top-left-radius:0px; border-top-right-radius:0px; "
				"background-color:palette(dark); height:20px;}"));
			windowFrame->setStyleSheet(QStringLiteral(
				"#windowFrame{border:1px solid palette(shadow); border-radius:0px "
				"0px 0px 0px; background-color:palette(Window);}"));
			QGraphicsEffect* oldShadow = windowFrame->graphicsEffect();
			if (oldShadow) delete oldShadow;
			windowFrame->setGraphicsEffect(nullptr);
		}  // if (bNoState) { else maximize
	}    // if (bActive) { else no focus
}

void ForgBaseLib::FrgBase_FramelessWindow::RetranslateUi()
{
	this->setWindowTitle(QString());
	titleText->setText(QApplication::translate("FramelessWindow", "Frameless Window (Dark Style)", nullptr));
	minimizeButton->setText(QString());
	restoreButton->setText(QString());
	maximizeButton->setText(QString());
}

void ForgBaseLib::FrgBase_FramelessWindow::SetupUi()
{
	QFont allFont = QFont();
	allFont.setFamily(allFont.defaultFamily());
	allFont.setStyleHint(QFont::Monospace);
	allFont.setPointSize(allFont.pointSize() - 1);
	QApplication::setFont(allFont);

	if (this->objectName().isEmpty())
		this->setObjectName(QString::fromUtf8("FramelessWindow"));
	this->resize(560, 398);
	this->setAutoFillBackground(false);
	verticalLayout_2 = new QVBoxLayout(this);
	verticalLayout_2->setSpacing(0);
	verticalLayout_2->setContentsMargins(11, 11, 11, 11);
	verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
	verticalLayout_2->setContentsMargins(5, 5, 5, 5);
	windowFrame = new QWidget(this);
	windowFrame->setObjectName(QString::fromUtf8("windowFrame"));
	windowFrame->setAutoFillBackground(false);
	windowFrame->setStyleSheet(QString::fromUtf8("#windowFrame{border:1px solid palette(highlight); border-radius:5px 5px 5px 5px; background-color:palette(Window);}"));
	verticalLayout = new QVBoxLayout(windowFrame);
	verticalLayout->setSpacing(0);
	verticalLayout->setContentsMargins(11, 11, 11, 11);
	verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
	verticalLayout->setContentsMargins(1, 1, 1, 1);
	windowTitlebar = new ForgBaseLib::FrgBase_WindowDragger(windowFrame);
	windowTitlebar->setObjectName(QString::fromUtf8("windowTitlebar"));
	QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);
	sizePolicy.setHeightForWidth(windowTitlebar->sizePolicy().hasHeightForWidth());
	windowTitlebar->setSizePolicy(sizePolicy);
	windowTitlebar->setMinimumSize(QSize(0, 0));
	windowTitlebar->setAutoFillBackground(false);
	windowTitlebar->setStyleSheet(QString::fromUtf8("#windowTitlebar{border: 0px none palette(base); border-top-left-radius:5px; border-top-right-radius:5px; background-color:palette(shadow); height:20px;}"));
	horizontalLayout = new QHBoxLayout(windowTitlebar);
	horizontalLayout->setSpacing(0);
	horizontalLayout->setContentsMargins(11, 11, 11, 11);
	horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
	horizontalLayout->setContentsMargins(0, 0, 0, 0);
	spacer = new QLabel(windowTitlebar);
	spacer->setObjectName(QString::fromUtf8("spacer"));
	spacer->setMinimumSize(QSize(4, 0));
	spacer->setMaximumSize(QSize(4, 16777215));

	horizontalLayout->addWidget(spacer);

	icon = new QLabel(windowTitlebar);
	icon->setObjectName(QString::fromUtf8("icon"));
	icon->setMinimumSize(QSize(16, 16));
	icon->setMaximumSize(QSize(16, 16));
	icon->setContextMenuPolicy(Qt::NoContextMenu);
	icon->setStyleSheet(QString::fromUtf8("#icon {background-color:palette(shadow);}"));

	horizontalLayout->addWidget(icon);

	titleText = new QLabel(windowTitlebar);
	titleText->setObjectName(QString::fromUtf8("titleText"));
	QFont font;
	font.setBold(true);
	font.setWeight(75);
	titleText->setFont(font);
	titleText->setStyleSheet(QString::fromUtf8("  padding-left:5px;\n"
		"  color:rgb(153,153,153);"));
	titleText->setAlignment(Qt::AlignLeading | Qt::AlignLeft | Qt::AlignVCenter);

	horizontalLayout->addWidget(titleText);

	minimizeButton = new QToolButton(windowTitlebar);
	minimizeButton->setObjectName(QString::fromUtf8("minimizeButton"));
	minimizeButton->setFont(font);
	minimizeButton->setStyleSheet(QString::fromUtf8("#minimizeButton{\n"
		"  background-color:none;\n"
		"  border:none;\n"
		"  width:16px;\n"
		"  height:16px;\n"
		"  padding:4px;\n"
		"  image:url(:/styles/DarkStyle/images/icon_window_minimize.png);\n"
		"}\n"
		"#minimizeButton:hover{\n"
		"  background-color:palette(alternate-base);\n"
		"}\n"
		"#minimizeButton:pressed{\n"
		"  background-color:palette(highlight);\n"
		"}"));

	horizontalLayout->addWidget(minimizeButton);

	restoreButton = new QToolButton(windowTitlebar);
	restoreButton->setObjectName(QString::fromUtf8("restoreButton"));
	restoreButton->setStyleSheet(QString::fromUtf8("#restoreButton{\n"
		"  background-color:none;\n"
		"  border:none;\n"
		"  width:16px;\n"
		"  height:16px;\n"
		"  padding:4px;\n"
		"  image:url(:/styles/DarkStyle/images/icon_window_restore.png);\n"
		"}\n"
		"#restoreButton:hover{\n"
		"  background-color:palette(alternate-base);\n"
		"}\n"
		"#restoreButton:pressed{\n"
		"  background-color:palette(highlight);\n"
		"}"));

	horizontalLayout->addWidget(restoreButton);

	maximizeButton = new QToolButton(windowTitlebar);
	maximizeButton->setObjectName(QString::fromUtf8("maximizeButton"));
	maximizeButton->setStyleSheet(QString::fromUtf8("#maximizeButton{\n"
		"  background-color:none;\n"
		"  border:none;\n"
		"  width:16px;\n"
		"  height:16px;\n"
		"  padding:4px;\n"
		"  image:url(:/styles/DarkStyle/images/icon_window_maximize.png);\n"
		"}\n"
		"#maximizeButton:hover{\n"
		"  background-color:palette(alternate-base);\n"
		"}\n"
		"##maximizeButton:pressed{\n"
		"  background-color:palette(highlight);\n"
		"}"));

	horizontalLayout->addWidget(maximizeButton);

	closeButton = new QToolButton(windowTitlebar);
	closeButton->setObjectName(QString::fromUtf8("closeButton"));
	closeButton->setFont(font);
	closeButton->setStyleSheet(QString::fromUtf8("#closeButton{\n"
		"  background-color:none;\n"
		"  border:none;\n"
		"  width:16px;\n"
		"  height:16px;\n"
		"  padding:4px;\n"
		"  image:url(:/styles/DarkStyle/images/icon_window_close.png);\n"
		"  border-top-right-radius: 5px;\n"
		"}\n"
		"#closeButton:hover{\n"
		"  background-color:palette(alternate-base);\n"
		"}\n"
		"##closeButton:pressed{\n"
		"  background-color:palette(highlight);\n"
		"}"));

	horizontalLayout->addWidget(closeButton);

	horizontalLayout->setStretch(2, 1);

	verticalLayout->addWidget(windowTitlebar);

	windowContent = new QWidget(windowFrame);
	windowContent->setObjectName(QString::fromUtf8("windowContent"));
	windowContent->setAutoFillBackground(false);
	windowContent->setStyleSheet(QString::fromUtf8("#windowContent{\n"
		"  border: 0px none palette(base);\n"
		"  border-radius:0px 0px 5px 5px;\n"
		"}"));
	verticalLayout_3 = new QVBoxLayout(windowContent);
	verticalLayout_3->setSpacing(0);
	verticalLayout_3->setContentsMargins(11, 11, 11, 11);
	verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
	verticalLayout_3->setContentsMargins(0, 0, 0, 0);

	verticalLayout->addWidget(windowContent);


	verticalLayout_2->addWidget(windowFrame);


	//RetranslateUi();

	QMetaObject::connectSlotsByName(this);
}

void ForgBaseLib::FrgBase_FramelessWindow::on_applicationStateChanged(Qt::ApplicationState state)
{
	if (windowState().testFlag(Qt::WindowNoState)) {
		if (state == Qt::ApplicationActive) {
			styleWindow(true, true);
		}
		else {
			styleWindow(false, true);
		}
	}
	else if (windowState().testFlag(Qt::WindowFullScreen)) {
		if (state == Qt::ApplicationActive) {
			styleWindow(true, false);
		}
		else {
			styleWindow(false, false);
		}
	}
}

void ForgBaseLib::FrgBase_FramelessWindow::on_minimizeButton_clicked()
{
	setWindowState(Qt::WindowMinimized);
}

void ForgBaseLib::FrgBase_FramelessWindow::on_closeButton_clicked()
{
	close();
}

void ForgBaseLib::FrgBase_FramelessWindow::on_windowTitlebar_doubleClicked()
{
	if (windowState().testFlag(Qt::WindowNoState)) {
		on_maximizeButton_clicked();
	}
	else if (windowState().testFlag(Qt::WindowFullScreen)) {
		on_restoreButton_clicked();
	}
}

void ForgBaseLib::FrgBase_FramelessWindow::mouseDoubleClickEvent(QMouseEvent* event)
{
	Q_UNUSED(event);
}

void ForgBaseLib::FrgBase_FramelessWindow::checkBorderDragging(QMouseEvent* event)
{
	if (isMaximized()) {
		return;
	}

	QPoint globalMousePos = event->globalPos();
	if (m_bMousePressed) {
		QScreen* screen = QGuiApplication::primaryScreen();
		// available geometry excludes taskbar
		QRect availGeometry = screen->availableGeometry();
		int h = availGeometry.height();
		int w = availGeometry.width();
		QList<QScreen*> screenlist = screen->virtualSiblings();
		if (screenlist.contains(screen)) {
			QSize sz = QApplication::desktop()->size();
			h = sz.height();
			w = sz.width();
		}

		// top right corner
		if (m_bDragTop && m_bDragRight) {
			int diff =
				globalMousePos.x() - (m_StartGeometry.x() + m_StartGeometry.width());
			int neww = m_StartGeometry.width() + diff;
			diff = globalMousePos.y() - m_StartGeometry.y();
			int newy = m_StartGeometry.y() + diff;
			if (neww > 0 && newy > 0 && newy < h - 50) {
				QRect newg = m_StartGeometry;
				newg.setWidth(neww);
				newg.setX(m_StartGeometry.x());
				newg.setY(newy);
				setGeometry(newg);
			}
		}
		// top left corner
		else if (m_bDragTop && m_bDragLeft) {
			int diff = globalMousePos.y() - m_StartGeometry.y();
			int newy = m_StartGeometry.y() + diff;
			diff = globalMousePos.x() - m_StartGeometry.x();
			int newx = m_StartGeometry.x() + diff;
			if (newy > 0 && newx > 0) {
				QRect newg = m_StartGeometry;
				newg.setY(newy);
				newg.setX(newx);
				setGeometry(newg);
			}
		}
		// bottom right corner
		else if (m_bDragBottom && m_bDragLeft) {
			int diff =
				globalMousePos.y() - (m_StartGeometry.y() + m_StartGeometry.height());
			int newh = m_StartGeometry.height() + diff;
			diff = globalMousePos.x() - m_StartGeometry.x();
			int newx = m_StartGeometry.x() + diff;
			if (newh > 0 && newx > 0) {
				QRect newg = m_StartGeometry;
				newg.setX(newx);
				newg.setHeight(newh);
				setGeometry(newg);
			}
		}
		else if (m_bDragTop) {
			int diff = globalMousePos.y() - m_StartGeometry.y();
			int newy = m_StartGeometry.y() + diff;
			if (newy > 0 && newy < h - 50) {
				QRect newg = m_StartGeometry;
				newg.setY(newy);
				setGeometry(newg);
			}
		}
		else if (m_bDragLeft) {
			int diff = globalMousePos.x() - m_StartGeometry.x();
			int newx = m_StartGeometry.x() + diff;
			if (newx > 0 && newx < w - 50) {
				QRect newg = m_StartGeometry;
				newg.setX(newx);
				setGeometry(newg);
			}
		}
		else if (m_bDragRight) {
			int diff =
				globalMousePos.x() - (m_StartGeometry.x() + m_StartGeometry.width());
			int neww = m_StartGeometry.width() + diff;
			if (neww > 0) {
				QRect newg = m_StartGeometry;
				newg.setWidth(neww);
				newg.setX(m_StartGeometry.x());
				setGeometry(newg);
			}
		}
		else if (m_bDragBottom) {
			int diff =
				globalMousePos.y() - (m_StartGeometry.y() + m_StartGeometry.height());
			int newh = m_StartGeometry.height() + diff;
			if (newh > 0) {
				QRect newg = m_StartGeometry;
				newg.setHeight(newh);
				newg.setY(m_StartGeometry.y());
				setGeometry(newg);
			}
		}
	}
	else {
		// no mouse pressed
		if (leftBorderHit(globalMousePos) && topBorderHit(globalMousePos)) {
			setCursor(Qt::SizeFDiagCursor);
		}
		else if (rightBorderHit(globalMousePos) && topBorderHit(globalMousePos)) {
			setCursor(Qt::SizeBDiagCursor);
		}
		else if (leftBorderHit(globalMousePos) &&
			bottomBorderHit(globalMousePos)) {
			setCursor(Qt::SizeBDiagCursor);
		}
		else {
			if (topBorderHit(globalMousePos)) {
				setCursor(Qt::SizeVerCursor);
			}
			else if (leftBorderHit(globalMousePos)) {
				setCursor(Qt::SizeHorCursor);
			}
			else if (rightBorderHit(globalMousePos)) {
				setCursor(Qt::SizeHorCursor);
			}
			else if (bottomBorderHit(globalMousePos)) {
				setCursor(Qt::SizeVerCursor);
			}
			else {
				m_bDragTop = false;
				m_bDragLeft = false;
				m_bDragRight = false;
				m_bDragBottom = false;
				setCursor(Qt::ArrowCursor);
			}
		}
	}
}

// pos in global virtual desktop coordinates
bool ForgBaseLib::FrgBase_FramelessWindow::leftBorderHit(const QPoint& pos)
{
	const QRect& rect = this->geometry();
	if (pos.x() >= rect.x() && pos.x() <= rect.x() + CONST_DRAG_BORDER_SIZE) {
		return true;
	}
	return false;
}

bool ForgBaseLib::FrgBase_FramelessWindow::rightBorderHit(const QPoint& pos)
{
	const QRect& rect = this->geometry();
	int tmp = rect.x() + rect.width();
	if (pos.x() <= tmp && pos.x() >= (tmp - CONST_DRAG_BORDER_SIZE)) {
		return true;
	}
	return false;
}

bool ForgBaseLib::FrgBase_FramelessWindow::topBorderHit(const QPoint& pos)
{
	const QRect& rect = this->geometry();
	if (pos.y() >= rect.y() && pos.y() <= rect.y() + CONST_DRAG_BORDER_SIZE) {
		return true;
	}
	return false;
}

bool ForgBaseLib::FrgBase_FramelessWindow::bottomBorderHit(const QPoint& pos)
{
	const QRect& rect = this->geometry();
	int tmp = rect.y() + rect.height();
	if (pos.y() <= tmp && pos.y() >= (tmp - CONST_DRAG_BORDER_SIZE)) {
		return true;
	}
	return false;
}

void ForgBaseLib::FrgBase_FramelessWindow::mousePressEvent(QMouseEvent* event)
{
	if (isMaximized()) {
		return;
	}

	m_bMousePressed = true;
	m_StartGeometry = this->geometry();

	QPoint globalMousePos = mapToGlobal(QPoint(event->x(), event->y()));

	if (leftBorderHit(globalMousePos) && topBorderHit(globalMousePos)) {
		m_bDragTop = true;
		m_bDragLeft = true;
		setCursor(Qt::SizeFDiagCursor);
	}
	else if (rightBorderHit(globalMousePos) && topBorderHit(globalMousePos)) {
		m_bDragRight = true;
		m_bDragTop = true;
		setCursor(Qt::SizeBDiagCursor);
	}
	else if (leftBorderHit(globalMousePos) && bottomBorderHit(globalMousePos)) {
		m_bDragLeft = true;
		m_bDragBottom = true;
		setCursor(Qt::SizeBDiagCursor);
	}
	else {
		if (topBorderHit(globalMousePos)) {
			m_bDragTop = true;
			setCursor(Qt::SizeVerCursor);
		}
		else if (leftBorderHit(globalMousePos)) {
			m_bDragLeft = true;
			setCursor(Qt::SizeHorCursor);
		}
		else if (rightBorderHit(globalMousePos)) {
			m_bDragRight = true;
			setCursor(Qt::SizeHorCursor);
		}
		else if (bottomBorderHit(globalMousePos)) {
			m_bDragBottom = true;
			setCursor(Qt::SizeVerCursor);
		}
	}
}

void ForgBaseLib::FrgBase_FramelessWindow::mouseReleaseEvent(QMouseEvent* event)
{
	Q_UNUSED(event);
	if (isMaximized()) {
		return;
	}

	m_bMousePressed = false;
	bool bSwitchBackCursorNeeded =
		m_bDragTop || m_bDragLeft || m_bDragRight || m_bDragBottom;
	m_bDragTop = false;
	m_bDragLeft = false;
	m_bDragRight = false;
	m_bDragBottom = false;
	if (bSwitchBackCursorNeeded) {
		setCursor(Qt::ArrowCursor);
	}
}

bool ForgBaseLib::FrgBase_FramelessWindow::eventFilter(QObject* obj, QEvent* event)
{
	if (isMaximized()) {
		return QWidget::eventFilter(obj, event);
	}

	// check mouse move event when mouse is moved on any object
	if (event->type() == QEvent::MouseMove) {
		QMouseEvent* pMouse = dynamic_cast<QMouseEvent*>(event);
		if (pMouse) {
			checkBorderDragging(pMouse);
		}
	}
	// press is triggered only on frame window
	else if (event->type() == QEvent::MouseButtonPress && obj == this) {
		QMouseEvent* pMouse = dynamic_cast<QMouseEvent*>(event);
		if (pMouse) {
			mousePressEvent(pMouse);
		}
	}
	else if (event->type() == QEvent::MouseButtonRelease) {
		if (m_bMousePressed) {
			QMouseEvent* pMouse = dynamic_cast<QMouseEvent*>(event);
			if (pMouse) {
				mouseReleaseEvent(pMouse);
			}
		}
	}

	return QWidget::eventFilter(obj, event);
}