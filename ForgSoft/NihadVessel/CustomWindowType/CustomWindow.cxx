#include <CustomWindow.hxx>
#include <QtWidgets/QDesktopWidget>
#include <QtGui/QPainter>
#include <QtWidgets/QGridLayout>
#include <WindowTitleBar.hxx>
#include <QtWidgets/QSizeGrip>

ForgBaseLib::CustomWindow::CustomWindow(QWidget* parent) : QWidget(parent)
{
	m_TitleBar = FrgNew WindowTitleBar(this);
	m_MainLayout = FrgNew QGridLayout(this);
	m_SizeGrip = FrgNew QSizeGrip(this);

	connect(this, SIGNAL(WindowTitleChanged()),
		m_TitleBar, SLOT(UpdateWindowTitle()));

	resize(512, 512);
	setWindowTitle(tr("Tutorial Qt: CustomWindow"));

	setWindowFlags(Qt::FramelessWindowHint);
	m_MainLayout->setMargin(0);  // No space between window's element and the border
	m_MainLayout->setSpacing(0); // No space between window's element
	setLayout(m_MainLayout);
	m_MainLayout->addWidget(m_TitleBar, 0, 0, 1, 1);
				
	m_MainLayout->setRowStretch(1, 1); // Put the title bar at the top of the window
}

ForgBaseLib::CustomWindow::~CustomWindow()
{

}

void ForgBaseLib::CustomWindow::showEvent(QShowEvent* event)
{
	Q_UNUSED(event);

	CenterOnScreen();
}

void ForgBaseLib::CustomWindow::CenterOnScreen()
{
	QDesktopWidget screen;

	QRect screenGeom = screen.screenGeometry(this);

	int screenCenterX = screenGeom.center().x();
	int screenCenterY = screenGeom.center().y();

	move(screenCenterX - width() / 2,
		screenCenterY - height() / 2);
}

void ForgBaseLib::CustomWindow::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);

	QBrush background(QColor(169, 169, 169));

	painter.setBrush(background);
	painter.setPen(Qt::NoPen); // No stroke

	painter.drawRect(0, 0, width(), height());
}

void ForgBaseLib::CustomWindow::setWindowTitle(const QString& title)
{
	QWidget::setWindowTitle(title);

	emit WindowTitleChanged();
}

void ForgBaseLib::CustomWindow::resizeEvent(QResizeEvent* event)
{
	m_SizeGrip->move(width() - 32, height() - 32);
	m_SizeGrip->resize(32, 32);
}