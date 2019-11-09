#include <SelectObjectsDlg.hxx>

#include <QtWidgets/QWidget>
#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtGui/QKeyEvent>

ForgBaseLib::SelectObjectsDlg::SelectObjectsDlg(QWidget* parent, QTreeWidgetItem* item)
	: QDialog(parent)
{
	this->setMinimumSize(QSize(450, 600));
	this->setModal(true);
	QString title = "Select" + item->text(0);
	this->setWindowTitle(QMainWindow::tr(title.toLocal8Bit().data()));

	//setWindowIcon(QIcon(":/Icons/Menus/File/New.png"));

	theTree_ = FrgNew QTreeWidget;

	if (item)
	{
		QList<QTreeWidgetItem*> items;// = item->takeChildren();

		for (int i = 0; i < item->childCount(); i++)
		{
			items.push_back(new QTreeWidgetItem(*item->child(i)));
			theTreeItemsToOriginalItems_.insert(items.at(i), item->child(i));
		}
		theTree_->addTopLevelItems(items);

		theTree_->setHeaderLabel(item->text(0));
	}

	theTree_->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);

	setupLayout();
}

void ForgBaseLib::SelectObjectsDlg::setupLayout()
{
	theButtonOK_ = FrgNew QPushButton("OK");
	theButtonCancel_ = FrgNew QPushButton("Cancel");

	theButtonLayout_ = FrgNew QHBoxLayout;
	theButtonLayout_->addStretch(1);
	theButtonLayout_->addWidget(theButtonOK_);
	theButtonLayout_->addWidget(theButtonCancel_);

	theGridLayout_ = FrgNew QGridLayout(this);
	theGridLayout_->addWidget(theTree_, 0, 0, 3, 3);

	theGridLayout_->addLayout(theButtonLayout_, 3, 1, 1, 2);
	//theGridLayout_->setColumnStretch(0, 1);

	//this->setLayout(theGridLayout_);

	connect(this->theButtonOK_, SIGNAL(clicked()), this, SLOT(onOK()));
	connect(this->theButtonCancel_, SIGNAL(clicked()), this, SLOT(reject()));
}

void ForgBaseLib::SelectObjectsDlg::onOK()
{
	accept();

	QList<QTreeWidgetItem*> selectedItems = theTree_->selectedItems();

	for (int i = 0; i < selectedItems.size(); i++)
	{
		theSelectedObjects_.push_back(theTreeItemsToOriginalItems_.value(selectedItems.at(i)));
	}

	if (!theSelectedObjects_.isEmpty())
	{
		emit ObjectsSelectedUpdate(theSelectedObjects_);
	}
}

void ForgBaseLib::SelectObjectsDlg::keyPressEvent(QKeyEvent* event)
{
	switch (event->key())
	{
	case Qt::Key_Escape:
	{
		done(0);
		break;
	}
	case Qt::Key_Return:
	case Qt::Key_Enter:
	{
		QDialog::accept();

		break;
	}
	default:
		event->ignore();
	}
}