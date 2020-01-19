#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_PrptsWdgDouble.hxx>
#include <FrgBase_PrptsWdgInt.hxx>
#include <FrgBase_PrptsWdgString.hxx>
#include <FrgBase_PrptsVrntDouble.hxx>
#include <FrgBase_PrptsVrntInt.hxx>
#include <FrgBase_PrptsVrntString.hxx>

#include <QtCore/QMetaObject>
#include <QtCore/QMetaProperty>
#include <QtWidgets/QTableWidgetItem>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHeaderView>

ForgBaseLib::FrgBase_PropertiesPanel::FrgBase_PropertiesPanel(QWidget* parentWidget)
	: QTableWidget(parentWidget)
	, theParentWidget_(parentWidget)
{
	this->setSelectionMode(QAbstractItemView::SingleSelection);

	const QMetaObject *metaobject = theParentWidget_->metaObject();
	int nbRow = metaobject->propertyCount() - metaobject->propertyOffset();
	int nbColumn = 2;

	this->setRowCount(nbRow + 1);
	this->setColumnCount(nbColumn);
	this->setHorizontalHeaderLabels({ "Property", "Value" });

	SetTableData(0, "Name", 0, theParentWidget_->property("objectName"));

	for (int i = 0; i < nbRow; ++i)
	{
		QMetaProperty metaproperty = metaobject->property(i + metaobject->propertyOffset());
		const char* name = metaproperty.name();
		QVariant value = theParentWidget_->property(name);

		std::cout << i << std::endl;

		SetTableData(i + 1, name, 0, value);
	}

	for (int i = 0; i < nbRow + 1; i++)
	{
		this->item(i, 0)->setFlags(Qt::ItemIsEnabled);
		this->item(i, 1)->setFlags(Qt::ItemIsEnabled);
	}

	this->resizeColumnsToContents();
	this->resizeRowsToContents();

	this->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
}

void ForgBaseLib::FrgBase_PropertiesPanel::SetTableData(int row, const char * name, int role, const QVariant & value)
{
	QTableWidgetItem* propertyName = new QTableWidgetItem(name);
	this->setItem(row, 0, propertyName);

	if (value.canConvert<FrgBase_PrptsVrntDouble*>())
	{
		QTableWidgetItem* item = new QTableWidgetItem;
		FrgBase_PrptsVrntDouble* myVariant = qvariant_cast<FrgBase_PrptsVrntDouble*>(value);
		FrgBase_PrptsWdgDouble* myWidget = new FrgBase_PrptsWdgDouble(this, myVariant);

		this->setItem(row, 1, item);
		this->setCellWidget(row, 1, myWidget);
	}
	else if (value.canConvert<FrgBase_PrptsVrntInt*>())
	{
		QTableWidgetItem* item = new QTableWidgetItem;
		FrgBase_PrptsVrntInt* myVariant = qvariant_cast<FrgBase_PrptsVrntInt*>(value);
		FrgBase_PrptsWdgInt* myWidget = new FrgBase_PrptsWdgInt(this, myVariant);

		this->setItem(row, 1, item);
		this->setCellWidget(row, 1, myWidget);
	}
	else if (value.canConvert<FrgBase_PrptsVrntString*>())
	{
		QTableWidgetItem* item = new QTableWidgetItem;
		FrgBase_PrptsVrntString* myVariant = qvariant_cast<FrgBase_PrptsVrntString*>(value);
		FrgBase_PrptsWdgString* myWidget = new FrgBase_PrptsWdgString(this, myVariant);

		this->setItem(row, 1, item);
		this->setCellWidget(row, 1, myWidget);
	}
	else if (value.type() == QVariant::String)
	{
		QTableWidgetItem* item = new QTableWidgetItem;
		FrgBase_PrptsVrntString* myVariant = new FrgBase_PrptsVrntString(value.toString().toStdString().c_str());
		FrgBase_PrptsWdgString* myWidget = new FrgBase_PrptsWdgString(this, myVariant);

		this->setItem(row, 1, item);
		this->setCellWidget(row, 1, myWidget);
	}
	else
	{
		QTableWidgetItem* propertyValue = new QTableWidgetItem;
		propertyValue->setData(role, value);
		this->setItem(row, 1, propertyValue);
	}
}