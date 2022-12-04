#pragma once
#ifndef _FrgBase_FieldFunctionsTreeWidget_Header
#define _FrgBase_FieldFunctionsTreeWidget_Header

#include <FrgBase_Global.hxx>

#include <QTreeWidget>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_FieldFunctionsTreeWidget
	: public QTreeWidget
{
	
	Q_OBJECT

public:

	FrgBase_FieldFunctionsTreeWidget(QWidget* parent = nullptr);

	Q_SIGNAL void ItemDoubleClickedSignal(const QString name);


protected slots:
	
	void ItemDoubleClickedSlot(QTreeWidgetItem* item, int column);

protected:

	void SetupLayout();
};

EndForgBaseLib

#endif // !_FrgBase_FieldFunctionsTreeWidget_Header
