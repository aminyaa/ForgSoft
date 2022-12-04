#include "FrgBase_FieldTextEdit.hxx"

#include <FrgBase_FieldTools.hxx>
#include <FrgBase_Field.hxx>

#include <QLayout>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

ForgBaseLib::FrgBase_FieldTextEdit::FrgBase_FieldTextEdit
(
	const std::shared_ptr<FrgBase_Field_Entity>& field,
	QWidget* parent
)
	: QWidget(parent)
	, theField_(field)
{
	if (!field)
		throw std::exception("Field is null in " __FUNCSIG__);

	SetupLayout();

	this->setWindowTitle("Field Expression Definition TextEdit");
}

void ForgBaseLib::FrgBase_FieldTextEdit::SetupLayout()
{
	// LineEdit
	{
		theTextEdit_ = new QTextEdit;

		theTmpExpression_ = theField_->GetExpression();

		theTextEdit_->setText
		(
			DecorizeExpression()
		);

		QTextCursor newCursor(theTextEdit_->document());
		newCursor.movePosition(QTextCursor::End);
		theTextEdit_->setTextCursor(newCursor);

		theTextEdit_->setSizePolicy
		(
			QSizePolicy::Expanding,
			QSizePolicy::Expanding
		);

		theTextEdit_->setAlignment
		(
			Qt::AlignmentFlag::AlignTop | Qt::AlignmentFlag::AlignLeft
		);

		connect
		(
			theTextEdit_,
			&QTextEdit::textChanged,
			this,
			&FrgBase_FieldTextEdit::TextEditTextChangedSlot
		);
	}

	// Message Label
	{
		theMessageLabel_ = new QLabel("");

		theMessageLabel_->setWordWrap(true);
	}

	// Main Layout
	{
		theMainLayout_ = new QVBoxLayout;

		theMainLayout_->addWidget(theTextEdit_);
		theMainLayout_->addWidget(theMessageLabel_);
	}

	this->setLayout(theMainLayout_);

	TextEditTextChangedSlot();
}

QString ForgBaseLib::FrgBase_FieldTextEdit::DecorizeExpression() const
{
	auto e = FrgBase_FieldTools::DecorizeExpression(theField_);

	return QString::fromStdString(e);
}

std::string ForgBaseLib::FrgBase_FieldTextEdit::UnDecorizeExpression
(
	const std::string& expression
) const
{
	auto e = FrgBase_FieldTools::UnDecorizeExpression
	(
		expression,
		theField_->GetRegistry()
	);

	return e;
}

std::string ForgBaseLib::FrgBase_FieldTextEdit::GetUnDecorizedExpression() const
{
	return UnDecorizeExpression
	(
		theTextEdit_->toPlainText().toStdString()
	);
}

void ForgBaseLib::FrgBase_FieldTextEdit::InsertTextAtCursor
(
	const QString text
)
{
	theTextEdit_->insertPlainText(text);
}

void ForgBaseLib::FrgBase_FieldTextEdit::CompileExpression()
{
	FrgBase_FieldParser::CompileExpression
	(
		theField_
	);
}

void ForgBaseLib::FrgBase_FieldTextEdit::TextEditTextChangedSlot()
{
	auto expression = theTextEdit_->toPlainText().toStdString();

	try
	{
		auto undec = UnDecorizeExpression(expression);
		theField_->SetExpression
		(
			undec
		);

		CompileExpression();

		SetMessageLabelText("Compiled successfully.", MessageState::OK);
	}
	catch (const std::exception& ex)
	{
		auto message =
			QString::fromStdString(ex.what());

		SetMessageLabelText(message, MessageState::Error);
	}

	emit TextEditTextChangedSignal();
}

void ForgBaseLib::FrgBase_FieldTextEdit::SetMessageLabelText
(
	const QString& text,
	MessageState state
)
{
	theMessageState_ = state;
	
	QString color =
		(state == MessageState::OK ? "green" : "red");

	QString style =
		"QLabel {color: " + color + "; }";

	theMessageLabel_->setStyleSheet(style);
	theMessageLabel_->setText(text);
}

QString ForgBaseLib::FrgBase_FieldTextEdit::GetMessageLabelString() const
{
	return theMessageLabel_->text();
}