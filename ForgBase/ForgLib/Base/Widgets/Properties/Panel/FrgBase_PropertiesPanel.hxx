#pragma once
#ifndef _FrgBase_PropertiesPanel_Header
#define _FrgBase_PropertiesPanel_Header

#include <FrgBase_Global.hxx>
#include <QtWidgets/QTableWidget>

BeginForgBaseLib

class FrgBase_PrptsVrnt;

class FORGBASE_EXPORT FrgBase_PropertiesPanel
	: public QTableWidget
{
	Q_OBJECT

public:

	FrgBase_PropertiesPanel
	(
		QWidget* parentMainWindow,
		QObject* parentObject
	);

	~FrgBase_PropertiesPanel();

	QWidget* GetParentWidget() const { return theParentWidget_; }

	template<typename T>
	void AddRow(FrgBase_PrptsVrnt* frgVairant, int row);
	template<typename T>
	void AddRow(FrgBase_PrptsVrnt* frgVairant);

signals:

	void valueChanged(const QString&);

private:

	QWidget* theParentWidget_ = nullptr;
	QObject* theParentObject_ = nullptr;

	void FormTableData();
	void SetTableData(int row, int role, const QVariant& value);

public:

	//bool eventFilter(QObject *obj, QEvent *event) override;
};

EndForgBaseLib

#include <FrgBase_PropertiesPanelI.hxx>

#endif // !_FrgBase_PropertiesPanel_Header
