#pragma once
#ifndef _FrgBase_PropertiesPanel_Header
#define _FrgBase_PropertiesPanel_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Object.hxx>
#include <QtWidgets/QTableWidget>

#include <FrgBase_PrptsVrnt_Include.hxx>
#include <FrgBase_PrptsWdg_Include.hxx>

BeginForgBaseLib

class FrgBase_PrptsVrnt;

class FORGBASE_EXPORT FrgBase_PropertiesPanel
	: public QTableWidget
	, public FrgBase_Object
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
	QObject* GetParentObject() const { return theParentObject_; }

	void SetParentWidget(QWidget* parentWidget) { theParentWidget_ = parentWidget; }
	void SetParentObject(QObject* parentObject) { theParentObject_ = parentObject; }

	template <typename T>
	auto AddRow(T* frgVairant, int row);
	template <typename T>
	auto AddRow(T* frgVairant);

	template <typename T>
	void RemoveRow(T* frgVariant);

	template <typename T>
	auto GetWidgetFromVariant(T* frgVariant);

	// returns -1 if the variant was not found
	template <typename T>
	int GetRowFromVariant(T* frgVariant) const;

signals:

	void valueChanged(const QString&);

protected slots:

	void DisplayNameChangedSlot(const QString& name);

protected:

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
