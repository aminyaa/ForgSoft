#pragma once
#ifndef _FrgBase_PropertiesPanelI_Header
#define _FrgBase_PropertiesPanelI_Header

#include <FrgBase_TreeItem.hxx>

#include <QtCore/QMetaObject>
#include <QtCore/QMetaProperty>
#include <QtWidgets/QTableWidgetItem>
#include <QtWidgets/QHeaderView>

template<typename T>
inline auto ForgBaseLib::FrgBase_PropertiesPanel::AddRow
(
	T* frgVairant,
	int row
)
{
	this->insertRow(row);

	QTableWidgetItem* propertyName = new QTableWidgetItem(frgVairant->GetDisplayName());
	this->setItem(row, 0, propertyName);

	QTableWidgetItem* item = new QTableWidgetItem;
	get_widget_type_from_variant<T>::type* myWidget = new get_widget_type_from_variant<T>::type(this, frgVairant);
	myWidget->FormWidget();
	myWidget->SetParentTItem(dynamic_cast<FrgBase_TreeItem*>(this->GetParentObject()));
	this->setItem(row, 1, item);
	this->setCellWidget(row, 1, myWidget);

	for (int j = 0; j < this->columnCount(); j++)
	{
		if (this->item(row, j))
		{
			this->item(row, j)->setFlags(Qt::ItemIsEnabled);

			/*if (row % 2 == 0)
				this->item(row, j)->setBackgroundColor(QColor(240, 240, 240));*/
		}
	}

	if (frgVairant->GetDisplayName() == "Name")
		this->cellWidget(row, 1)->setEnabled(false);

	this->resizeColumnsToContents();
	this->resizeRowsToContents();

	this->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	this->horizontalHeader()->setStretchLastSection(true);

	return myWidget;
}

template<typename T>
inline auto ForgBaseLib::FrgBase_PropertiesPanel::AddRow
(
	T* frgVairant
)
{
	return this->AddRow<T>(frgVairant, this->rowCount());
}

template<typename T>
inline void ForgBaseLib::FrgBase_PropertiesPanel::RemoveRow(T* frgVariant)
{
	for (int i = 0; i < this->rowCount(); i++)
	{
		auto myCastedWidget = dynamic_cast<get_widget_type_from_variant<T>::type*>(this->cellWidget(i, 1));
		if (myCastedWidget)
		{
			if (this->item(i, 0)->data(0).toString() == frgVariant->GetDisplayName())
				this->removeRow(i);
		}
	}
}

template<typename T>
inline auto ForgBaseLib::FrgBase_PropertiesPanel::GetWidgetFromVariant(T* frgVariant)
{
	for (int i = 0; i < this->rowCount(); i++)
	{
		auto myCastedWidget = dynamic_cast<get_widget_type_from_variant<T>::type*>(this->cellWidget(i, 1));
		if (myCastedWidget)
		{
			if(this->item(i, 0)->data(0).toString() == frgVariant->GetDisplayName())
				return myCastedWidget;
		}
	}

	return (get_widget_type_from_variant<T>::type*)(nullptr);
}

#endif // !_FrgBase_PropertiesPanel_Header