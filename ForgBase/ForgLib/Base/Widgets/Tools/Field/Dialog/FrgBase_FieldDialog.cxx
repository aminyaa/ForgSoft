#include "FrgBase_FieldDialog.hxx"

#include <FrgBase_FieldTextEdit.hxx>
#include <FrgBase_FieldTreeWidget.hxx>
#include <FrgBase_FieldFunctionsTreeWidget.hxx>
#include <FrgBase_Field.hxx>
#include <FrgBase_ToolsWidgets.hxx>

#include <QLayout>
#include <QPushButton>

ForgBaseLib::FrgBase_FieldDialog::FrgBase_FieldDialog
(
	const std::shared_ptr<FrgBase_Field_Entity>& field,
	QWidget* parent
)
	: QDialog(parent)
	, theField_(field)
{
	this->setWindowTitle("Field Expression Definition Dialog");

	SetupLayout();

	SetGeometry(60, 40);
}

void ForgBaseLib::FrgBase_FieldDialog::SetupLayout()
{
	// TextEdit
	{
		theTextEdit_ = new FrgBase_FieldTextEdit(theField_);

		connect
		(
			theTextEdit_,
			&FrgBase_FieldTextEdit::TextEditTextChangedSignal,
			this,
			&FrgBase_FieldDialog::UpdateButtons
		);
	}

	// TreeWidget
	{
		theTreeWidget_ =
			new FrgBase_FieldTreeWidget(theField_->RetrieveSymbolTablesIncludingExternals());

		connect
		(
			theTreeWidget_,
			&FrgBase_FieldTreeWidget::ItemDoubleClickedSignal,
			this,
			&FrgBase_FieldDialog::InsertFieldNameToTextEditSlot
		);
	}

	// Functions TreeWidget
	{
		theFunctionsTreeWidget_ = new FrgBase_FieldFunctionsTreeWidget;

		connect
		(
			theFunctionsTreeWidget_,
			&FrgBase_FieldFunctionsTreeWidget::ItemDoubleClickedSignal,
			this,
			&FrgBase_FieldDialog::InsertFunctionNameToTextEditSlot
		);
	}

	// Buttons
	{
		theButtonsLayout_ = new QHBoxLayout;

		theOKButton_ = new QPushButton("OK");
		theCancelButton_ = new QPushButton("Cancel");

		theButtonsLayout_->addStretch(1);
		theButtonsLayout_->addWidget(theOKButton_);
		theButtonsLayout_->addWidget(theCancelButton_);

		connect
		(
			theOKButton_,
			&QPushButton::clicked,
			this,
			&FrgBase_FieldDialog::OKClickedSlot
		);

		connect
		(
			theCancelButton_,
			&QPushButton::clicked,
			this,
			&FrgBase_FieldDialog::CancelClickedSlot
		);
	}

	// Inner Layout
	{
		theInnerLayout_ = new QVBoxLayout;

		theInnerLayout_->addWidget(theTextEdit_);
		theInnerLayout_->addWidget(theFunctionsTreeWidget_);
	}

	// Outer Layout
	{
		theOuterLayout_ = new QHBoxLayout;

		theOuterLayout_->addLayout(theInnerLayout_);
		theOuterLayout_->addWidget(theTreeWidget_);
	}

	// Main Layout
	{
		theMainLayout_ = new QVBoxLayout;

		theMainLayout_->addLayout(theOuterLayout_);
		theMainLayout_->addLayout(theButtonsLayout_);
	}

	this->setLayout(theMainLayout_);

	UpdateButtons();
}

void ForgBaseLib::FrgBase_FieldDialog::SetGeometry
(
	const int PercentageOfScreenW,
	const int PercentageOfScreenH
)
{
	FrgBase_ToolsWidgets::SetGeometry
	(
		this,
		PercentageOfScreenW,
		PercentageOfScreenH
	);
}

void ForgBaseLib::FrgBase_FieldDialog::UpdateButtons()
{
	auto ms =
		theTextEdit_->GetMessageState();

	theOKButton_->setEnabled
	(
		ms == FrgBase_FieldTextEdit::MessageState::OK
	);
}

void ForgBaseLib::FrgBase_FieldDialog::OKClickedSlot()
{
	auto e =
		theTextEdit_->GetUnDecorizedExpression();

	theField_->SetExpression(e);

	accept();
}

void ForgBaseLib::FrgBase_FieldDialog::CancelClickedSlot()
{
	theField_->SetExpression(theTextEdit_->GetTmpExpression());

	reject();
}

void ForgBaseLib::FrgBase_FieldDialog::InsertFieldNameToTextEditSlot
(
	const QString& name
)
{
	theTextEdit_->InsertTextAtCursor(name);
}

void ForgBaseLib::FrgBase_FieldDialog::InsertFunctionNameToTextEditSlot
(
	const QString& name
)
{
	theTextEdit_->InsertTextAtCursor(name);
}