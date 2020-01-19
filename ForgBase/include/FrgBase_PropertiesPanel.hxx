#pragma once
#ifndef _FrgBase_PropertiesPanel_Header
#define _FrgBase_PropertiesPanel_Header

#include <FrgBase_Global.hxx>
#include <QtWidgets/QTableWidget>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PropertiesPanel
	: public QTableWidget
{
	Q_OBJECT

public:

	FrgBase_PropertiesPanel(QWidget* parentWidget);

signals:

	void valueChanged(const QString&);

private:

	QWidget* theParentWidget_ = nullptr;

	void SetTableData(int row, const char* name, int role, const QVariant& value);
};

EndForgBaseLib

#endif // !_FrgBase_PropertiesPanel_Header
