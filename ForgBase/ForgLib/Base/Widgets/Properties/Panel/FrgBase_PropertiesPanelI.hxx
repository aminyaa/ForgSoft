#pragma once
#ifndef _FrgBase_PropertiesPanelI_Header
#define _FrgBase_PropertiesPanelI_Header

#include <FrgBase_PrptsVrnt_Include.hxx>
#include <FrgBase_PrptsWdg_Include.hxx>

#include <QtCore/QMetaObject>
#include <QtCore/QMetaProperty>
#include <QtWidgets/QTableWidgetItem>
#include <QtWidgets/QHeaderView>

template<typename T>
inline void ForgBaseLib::FrgBase_PropertiesPanel::AddRow
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
	this->setItem(row, 1, item);
	this->setCellWidget(row, 1, myWidget);

	for (int j = 0; j < this->columnCount(); j++)
	{
		if (this->item(row, j))
		{
			this->item(row, j)->setFlags(Qt::ItemIsEnabled);

			if (row % 2 == 0)
				this->item(row, j)->setBackgroundColor(QColor(240, 240, 240));
		}
	}

	if (!std::strcmp(frgVairant->GetDisplayName(), "Name"))
		this->cellWidget(row, 1)->setEnabled(false);

	this->resizeColumnsToContents();
	this->resizeRowsToContents();

	this->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	this->horizontalHeader()->setStretchLastSection(true);
}

template<typename T>
inline void ForgBaseLib::FrgBase_PropertiesPanel::AddRow
(
	T* frgVairant
)
{
	this->AddRow<T>(frgVairant, this->rowCount());
}

#endif // !_FrgBase_PropertiesPanel_Header
