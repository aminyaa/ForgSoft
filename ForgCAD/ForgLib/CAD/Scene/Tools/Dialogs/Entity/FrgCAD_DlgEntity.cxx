#include <FrgCAD_DlgEntity.hxx>

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtGui/QResizeEvent>

ForgCADLib::FrgCAD_DlgEntity::FrgCAD_DlgEntity(QWidget* parent /* = nullptr */)
	: QWidget(nullptr)
	, theParent_(parent)
	, theIsInEditing_(false)
{
	this->setWindowFlags(Qt::WindowType::FramelessWindowHint);

	theLayout_ = new QVBoxLayout;
	theLayout_->setContentsMargins(0, 0, 0, 0);
	this->setLayout(theLayout_);
	theParent_->installEventFilter(this);
}

void ForgCADLib::FrgCAD_DlgEntity::FormDlg()
{
	theOKButton_ = new QPushButton("OK");
	theCancelButton_ = new QPushButton("Cancel");

	connect(theOKButton_, &QPushButton::clicked, this, &FrgCAD_DlgEntity::OKClickedSignal);
	connect(theCancelButton_, &QPushButton::clicked, this, &FrgCAD_DlgEntity::CancelClickedSignal);

	QHBoxLayout* lay = new QHBoxLayout;
	lay->addWidget(theOKButton_);
	lay->addWidget(theCancelButton_);
	theLayout_->addLayout(lay);

	int w = this->sizeHint().width();
	int h = this->sizeHint().height();

	this->setParent(theParent_);
	QWidget::setParent(theParent_);

	SetGeometry(w, h);

	this->show();
}

void ForgCADLib::FrgCAD_DlgEntity::SetGeometry(int w, int h)
{
	int x = theParent_->width() - w - 20;
	int y = theParent_->height() - h - 20;

	auto mainWindow = dynamic_cast<QMainWindow*>(theParent_);
	if (mainWindow)
		y -= mainWindow->statusBar()->height();

	this->setGeometry(x, y, w, h);
}

void ForgCADLib::FrgCAD_DlgEntity::enterEvent(QEvent* event)
{
	theTmpCursor_ = parentWidget()->cursor();
	parentWidget()->setCursor(Qt::CursorShape::ArrowCursor);

	QWidget::enterEvent(event);
}

void ForgCADLib::FrgCAD_DlgEntity::leaveEvent(QEvent* event)
{
	parentWidget()->setCursor(theTmpCursor_);

	QWidget::leaveEvent(event);
}

void ForgCADLib::FrgCAD_DlgEntity::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Escape)
	{
		theIsInEditing_ = false;
		emit IsInEditingSignal(false);

		event->accept();
	}

	QWidget::keyPressEvent(event);
}

bool ForgCADLib::FrgCAD_DlgEntity::eventFilter(QObject* watched, QEvent* event)
{
	if (watched == theParent_)
	{
		if (event->type() == QEvent::Resize)
		{
			SetGeometry(this->sizeHint().width(), this->sizeHint().height());
		}
	}

	return QWidget::eventFilter(watched, event);
}