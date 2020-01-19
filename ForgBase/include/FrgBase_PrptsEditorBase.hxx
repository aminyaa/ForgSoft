#pragma once
#ifndef _FrgBase_PrptsEditorBase_Header
#define _FrgBase_PrptsEditorBase_Header

#include <FrgBase_Global.hxx>
#include <QtWidgets/QWidget>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsEditorBase
	: public QWidget
{
	Q_OBJECT

public:

	FrgBase_PrptsEditorBase(QWidget* parent = nullptr);

	/*QVariant GetVariant() const { return theVariant_; }
	void SetVariant(const QVariant& variant) { theVariant_ = variant; }

	QVariant::Type GetVariantType() const { return theType_; }
	void SetVariantType(QVariant::Type type) { theType_ = type; }*/

signals:

	//void editingFinished();

private:

	/*QVariant theVariant_;
	QVariant::Type theType_;*/
};

EndForgBaseLib

#endif // !_FrgBase_PrptsEditorBase_Header
