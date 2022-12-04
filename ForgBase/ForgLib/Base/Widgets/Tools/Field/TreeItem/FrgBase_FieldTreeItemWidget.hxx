#pragma once
#ifndef _FrgBase_FieldTreeItemWidget_Header
#define _FrgBase_FieldTreeItemWidget_Header

#include <FrgBase_Global.hxx>

#include <QTreeWidgetItem>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_FieldTreeItemWidget
	: public QTreeWidgetItem
{

public:

	FrgBase_FieldTreeItemWidget();

	const bool IsSelectable() const { return theIsSelectable_; }
	void SetSelectable(const bool c);

	void SetType(const std::string& typeAsString);

	QString GetFieldFullPresentationName() const { return theFieldFullPresentationName_; }
	void SetFieldFullPresentationName(const QString& name) { theFieldFullPresentationName_ = name; }

protected:

	bool theIsSelectable_ = true;

	QString theFieldFullPresentationName_ = "";
};

EndForgBaseLib

#endif // !_FrgBase_FieldTreeItemWidget_Header
