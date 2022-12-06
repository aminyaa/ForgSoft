#pragma once
#ifndef _FrgBase_FieldTextEdit_Header
#define _FrgBase_FieldTextEdit_Header

#include<FrgBase_Global.hxx>

#include<QWidget>

class QVBoxLayout;
class QHBoxLayout;
class QTextEdit;
class QLabel;
class QPushButton;

BeginForgBaseLib

class FrgBase_Field_Entity;

class FORGBASE_EXPORT FrgBase_FieldTextEdit
	: public QWidget
{

	Q_OBJECT

public:

	enum class MessageState
	{
		OK,
		Error
	};

	FrgBase_FieldTextEdit
	(
		const std::shared_ptr<FrgBase_Field_Entity>& field,
		QWidget* parent = nullptr
	);

	MessageState GetMessageState() const { return theMessageState_; }

	QString GetMessageLabelString() const;

	std::string GetUnDecorizedExpression() const;

	std::string GetTmpExpression() const { return theTmpExpression_; }

	void InsertTextAtCursor(const QString text);

	Q_SIGNAL void TextEditTextChangedSignal();

	QWidget* GetWidgetToFocus() const;

protected:

	void SetupLayout();

	QString DecorizeExpression() const;
	
	std::string UnDecorizeExpression
	(
		const std::string& expression
	) const;

	void CompileExpression();

protected slots:
	
	void TextEditTextChangedSlot();

	void SetMessageLabelText
	(
		const QString& text,
		MessageState state
	);

protected:

	std::shared_ptr<FrgBase_Field_Entity> theField_;

	QVBoxLayout* theMainLayout_ = nullptr;
	QTextEdit* theTextEdit_ = nullptr;
	QLabel* theMessageLabel_ = nullptr;

	MessageState theMessageState_ = MessageState::OK;

	std::string theTmpExpression_ = "";
};

EndForgBaseLib

#endif // !_FrgBase_FieldTextEdit_Header
