#pragma once
#ifndef _FrgBase_FieldLineEdit_Header
#define _FrgBase_FieldLineEdit_Header

#include<FrgBase_Global.hxx>

#include<QMainWindow>

class QVBoxLayout;
class QHBoxLayout;
class QLineEdit;
class QLabel;
class QPushButton;
//class QTimer;

BeginForgBaseLib

class FrgBase_Field_Entity;

class FORGBASE_EXPORT FrgBase_FieldLineEdit
	: public QMainWindow
{

	Q_OBJECT

public:

	enum class MessageState
	{
		OK,
		Error
	};

	FrgBase_FieldLineEdit
	(
		const std::shared_ptr<FrgBase_Field_Entity>& field,
		QWidget* parent
	);

	void SetGeometry
	(
		const int PercentageOfScreenW,
		const int PercentageOfScreenH
	);

protected:

	void SetupLayout();

	QString DecorizeExpression() const;
	
	std::string UnDecorizeExpression
	(
		const std::string& expression
	) const;

	void CompileExpression();

	void UpdateButtons();

	//void ResetTimer();

protected slots:
	
	void LineEditTextChangedSlot(const QString& text);
	void OKClickedSlot();
	void CancelClickedSlot();

	void SetMessageLabelText
	(
		const QString& text,
		MessageState state
	);

	//void TimerTimeoutSlot();

protected:

	std::shared_ptr<FrgBase_Field_Entity> theField_;

	QVBoxLayout* theMainLayout_ = nullptr;

	QLineEdit* theLineEdit_ = nullptr;

	QLabel* theMessageLabel_ = nullptr;

	QHBoxLayout* theButtonsLayout_ = nullptr;
	QPushButton* theOKButton_ = nullptr;
	QPushButton* theCancelButton_ = nullptr;

	MessageState theMessageState_ = MessageState::OK;

	//QTimer* theTimer_ = nullptr;

	std::string theTmpExpression_ = "";
};

EndForgBaseLib

#endif // !_FrgBase_FieldLineEdit_Header
