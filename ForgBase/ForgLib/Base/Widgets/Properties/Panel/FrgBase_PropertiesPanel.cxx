#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_PrptsWdgDouble.hxx>
#include <FrgBase_PrptsWdgInt.hxx>
#include <FrgBase_PrptsWdgString.hxx>
#include <FrgBase_PrptsWdgBool.hxx>
#include <FrgBase_PrptsVrntDouble.hxx>
#include <FrgBase_PrptsVrntInt.hxx>
#include <FrgBase_PrptsVrntString.hxx>
#include <FrgBase_PrptsVrntBool.hxx>

#include <QtCore/QMetaObject>
#include <QtCore/QMetaProperty>
#include <QtWidgets/QTableWidgetItem>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QCheckBox>
#include <QtCore/QEvent>

ForgBaseLib::FrgBase_PropertiesPanel::FrgBase_PropertiesPanel(QWidget* parentMainWindow, QObject* parentObject)
	: QTableWidget(parentMainWindow)
	, theParentWidget_(parentMainWindow)
{
	this->setSelectionMode(QAbstractItemView::SingleSelection);

	if (parentObject == nullptr)
		return;

	const QMetaObject *metaobject = parentObject->metaObject();
	int nbRow = metaobject->propertyCount() - metaobject->propertyOffset();
	int nbColumn = 2;

	this->setRowCount(nbRow + 1);
	this->setColumnCount(nbColumn);
	this->setHorizontalHeaderLabels({ "Property", "Value" });

	SetTableData(0, "Name", 0, parentObject->property("objectName"));
	this->cellWidget(0, 1)->setEnabled(false);

	for (int i = 0; i < nbRow; ++i)
	{
		QMetaProperty metaproperty = metaobject->property(i + metaobject->propertyOffset());
		const char* name = metaproperty.name();
		QVariant value = parentObject->property(name);

		SetTableData(i + 1, name, 0, value);
	}

	for (int i = 0; i < this->rowCount(); i++)
	{
		for (int j = 0; j < this->columnCount(); j++)
		{
			this->item(i, 0)->setFlags(Qt::ItemIsEnabled);
			this->item(i, 1)->setFlags(Qt::ItemIsEnabled);

			if (i % 2 == 0)
				this->item(i, j)->setBackgroundColor(QColor(220, 220, 220));
		}

	}

	this->resizeColumnsToContents();
	this->resizeRowsToContents();

	this->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

	this->setHidden(true);
}

void ForgBaseLib::FrgBase_PropertiesPanel::SetTableData(int row, const char * name, int role, const QVariant & value)
{

	if (value.canConvert<FrgBase_PrptsVrntDouble*>())
	{
		FrgBase_PrptsVrntDouble* myVariant = qvariant_cast<FrgBase_PrptsVrntDouble*>(value);

		QTableWidgetItem* propertyName = new QTableWidgetItem(myVariant->GetDisplayName());
		this->setItem(row, 0, propertyName);

		QTableWidgetItem* item = new QTableWidgetItem;
		FrgBase_PrptsWdgDouble* myWidget = new FrgBase_PrptsWdgDouble(this, myVariant);
		this->setItem(row, 1, item);
		this->setCellWidget(row, 1, myWidget);
	}
	else if (value.canConvert<FrgBase_PrptsVrntInt*>())
	{
		FrgBase_PrptsVrntInt* myVariant = qvariant_cast<FrgBase_PrptsVrntInt*>(value);

		QTableWidgetItem* propertyName = new QTableWidgetItem(myVariant->GetDisplayName());
		this->setItem(row, 0, propertyName);

		QTableWidgetItem* item = new QTableWidgetItem;
		FrgBase_PrptsWdgInt* myWidget = new FrgBase_PrptsWdgInt(this, myVariant);
		this->setItem(row, 1, item);
		this->setCellWidget(row, 1, myWidget);

		//this->installEventFilter(myWidget);
	}
	else if (value.canConvert<FrgBase_PrptsVrntString*>())
	{
		FrgBase_PrptsVrntString* myVariant = qvariant_cast<FrgBase_PrptsVrntString*>(value);

		QTableWidgetItem* propertyName = new QTableWidgetItem(myVariant->GetDisplayName());
		this->setItem(row, 0, propertyName);

		QTableWidgetItem* item = new QTableWidgetItem;
		FrgBase_PrptsWdgString* myWidget = new FrgBase_PrptsWdgString(this, myVariant);
		this->setItem(row, 1, item);
		this->setCellWidget(row, 1, myWidget);
	}
	else if (value.canConvert<FrgBase_PrptsVrntBool*>())
	{
		FrgBase_PrptsVrntBool* myVariant = qvariant_cast<FrgBase_PrptsVrntBool*>(value);

		QTableWidgetItem* propertyName = new QTableWidgetItem(myVariant->GetDisplayName());
		this->setItem(row, 0, propertyName);

		QTableWidgetItem* item = new QTableWidgetItem;
		FrgBase_PrptsWdgBool* myWidget = new FrgBase_PrptsWdgBool(this, myVariant);
		this->setItem(row, 1, item);
		this->setCellWidget(row, 1, myWidget);
		myWidget->installEventFilter(this);
	}
	else if (value.type() == QVariant::String)
	{
		QTableWidgetItem* propertyName = new QTableWidgetItem(name);
		this->setItem(row, 0, propertyName);

		QTableWidgetItem* item = new QTableWidgetItem;
		FrgBase_PrptsVrntString* myVariant = new FrgBase_PrptsVrntString("", value.toString().toStdString().c_str());
		std::cout << value.toString().toStdString() << std::endl;
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

//bool ForgBaseLib::FrgBase_PropertiesPanel::eventFilter(QObject * obj, QEvent * event)
//{
//	if (event->type() == QEvent::MouseButtonRelease)
//	{
//		FrgBase_PrptsWdgBool* boolObj = dynamic_cast<FrgBase_PrptsWdgBool*>(obj);
//		if (boolObj)
//		{
//			std::cout << obj->metaObject()->className() << " = " << boolObj->GetValue() << std::endl;
//			//std::cout << "From PrptsPanel() " << obj->metaObject()->className() << std::endl;
//			return true;
//		}
//	}
//
//	return QTableWidget::eventFilter(obj, event);
//}