#pragma once
#ifndef _FrgBase_FieldDialog_Header
#define _FrgBase_FieldDialog_Header

#include <FrgBase_Global.hxx>

#include <QDialog>

class QHBoxLayout;
class QVBoxLayout;
class QPushButton;

BeginForgBaseLib

class FrgBase_Field_Entity;
class FrgBase_FieldTextEdit;
class FrgBase_FieldTreeWidget;
class FrgBase_FieldFunctionsTreeWidget;

class FORGBASE_EXPORT FrgBase_FieldDialog
	: public QDialog
{

	Q_OBJECT

public:

	FrgBase_FieldDialog
	(
		const std::shared_ptr<FrgBase_Field_Entity>& field,
		QWidget* parent = nullptr
	);

	void SetGeometry
	(
		const int PercentageOfScreenW,
		const int PercentageOfScreenH
	);

protected:

	void SetupLayout();

	void UpdateButtons();

protected slots:

	void OKClickedSlot();
	void CancelClickedSlot();
	void InsertFieldNameToTextEditSlot(const QString& name);
	void InsertFunctionNameToTextEditSlot(const QString& name);

protected:

	std::shared_ptr<FrgBase_Field_Entity> theField_;

	QVBoxLayout* theMainLayout_ = nullptr;
	QHBoxLayout* theOuterLayout_ = nullptr;
	QVBoxLayout* theInnerLayout_ = nullptr;

	FrgBase_FieldTextEdit* theTextEdit_ = nullptr;
	FrgBase_FieldTreeWidget* theTreeWidget_ = nullptr;
	FrgBase_FieldFunctionsTreeWidget* theFunctionsTreeWidget_ = nullptr;

	QHBoxLayout* theButtonsLayout_ = nullptr;
	QPushButton* theOKButton_ = nullptr;
	QPushButton* theCancelButton_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_FieldDialog_Header
