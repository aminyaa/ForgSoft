#include "FrgBase_FieldTreeItemWidget.hxx"

#include <FrgBase_Global_Icons.hxx>

ForgBaseLib::FrgBase_FieldTreeItemWidget::FrgBase_FieldTreeItemWidget()
	: QTreeWidgetItem()
{
	SetSelectable(theIsSelectable_);
}

void ForgBaseLib::FrgBase_FieldTreeItemWidget::SetSelectable
(
	const bool c
)
{
	theIsSelectable_ = c;

	QString m =
		(
			theIsSelectable_ ?
			QString::fromUtf8(u8"\u2705") : // tick icon
			QString::fromUtf8(u8"\u274C") // cross icon
			);

	this->setText
	(
		2,
		m
	);

	if (theIsSelectable_)
		this->setIcon(0, QIcon(":/Icons/TreeStyle/Field.png"));
	else
		this->setIcon(0, QIcon(ICON_Menu_File_Load));
}

void ForgBaseLib::FrgBase_FieldTreeItemWidget::SetType
(
	const std::string& typeAsString
)
{
	this->setText
	(
		1,
		QString::fromStdString(typeAsString)
	);
}