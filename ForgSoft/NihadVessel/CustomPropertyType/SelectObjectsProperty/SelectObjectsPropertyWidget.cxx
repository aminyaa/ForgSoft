#include <SelectObjectsPropertyWidget.hxx>
#include <QtWidgets/QTreeWidgetItem>
#include <SelectObjectsPropertyManager.hxx>
#include <SelectObjectsDlg.hxx>

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>

ForgBaseLib::SelectObjectsPropertyWidget::SelectObjectsPropertyWidget(QWidget* parent, QTreeWidgetItem* treeItemSelection)
	: QWidget(parent)
	, theTreeItemSelection_(treeItemSelection)
{
	QHBoxLayout* layout = new QHBoxLayout(this);
	layout->setMargin(0);
	layout->setSpacing(0);
	theLabel_ = new QLabel(this);
	theLabel_->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));
	QToolButton* button = new QToolButton(this);
	button->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred));
	button->setText(QLatin1String("..."));
	layout->addWidget(theLabel_);
	layout->addWidget(button);
	setFocusProxy(theLabel_);
	setFocusPolicy(Qt::StrongFocus);
	setAttribute(Qt::WA_InputMethodEnabled);

	connect(button, SIGNAL(clicked()),
		this, SLOT(buttonClicked()));
}

void ForgBaseLib::SelectObjectsPropertyWidget::SetObjectsLabel(QList<QTreeWidgetItem*> value)
{
	QString str = "";

	if (!value.isEmpty())
	{
		for (int i = 0; i < value.size() - 1; i++)
		{
			str = str + value.at(i)->text(0) + " | ";
		}

		str = str + value.at(value.size() - 1)->text(0);
	}

	theLabel_->setText(str);
}

void ForgBaseLib::SelectObjectsPropertyWidget::buttonClicked()
{
	FrgSharedPtr<SelectObjectsDlg> dlg = FrgMakeSharedPtr(SelectObjectsDlg)(this, theTreeItemSelection_);

	if (dlg->exec() == QDialog::Accepted)
	{
		SetObjectsLabel(dlg->GetSelectedObjects());
	}
}