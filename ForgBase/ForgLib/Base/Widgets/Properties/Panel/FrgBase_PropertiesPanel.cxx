#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_PrptsVrnt_Include.hxx>
#include <FrgBase_PrptsWdg_Include.hxx>

#include <QtCore/QMetaObject>
#include <QtCore/QMetaProperty>
#include <QtWidgets/QTableWidgetItem>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QCheckBox>
#include <QtCore/QEvent>

ForgBaseLib::FrgBase_PropertiesPanel::FrgBase_PropertiesPanel(QWidget* parentMainWindow, QObject* parentObject)
	: QTableWidget(parentMainWindow)
	, theParentWidget_(parentMainWindow)
	, theParentObject_(parentObject)
{
	if (parentObject == nullptr)
		return;

	this->setSelectionMode(QAbstractItemView::SingleSelection);
	this->setColumnCount(2);
	this->setHorizontalHeaderLabels({ "Property", "Value" });

	this->setHidden(true);

	//FormTableData();
}

ForgBaseLib::FrgBase_PropertiesPanel::~FrgBase_PropertiesPanel()
{
	theParentWidget_ = NullPtr;
	theParentObject_ = NullPtr;
}

void ForgBaseLib::FrgBase_PropertiesPanel::FormTableData()
{
	const QMetaObject *metaobject = theParentObject_->metaObject();
	int nbRow = metaobject->propertyCount() - metaobject->propertyOffset();

	int I;
	if (metaobject->indexOfProperty("TItemName") - metaobject->propertyOffset() == 0)
	{
		this->setRowCount(nbRow);
		I = 0;
	}
	else
	{
		this->setRowCount(nbRow + 1);
		SetTableData(0, 0, theParentObject_->property("TItemName"));
		this->cellWidget(0, 1)->setEnabled(false);
		I = 1;
	}

	for (int i = 0; i < nbRow; i++, I++)
	{
		QMetaProperty metaproperty = metaobject->property(i + metaobject->propertyOffset());
		const char* name = metaproperty.name();
		QVariant value = theParentObject_->property(name);

		SetTableData(I, 0, value);
	}

	for (int i = 0; i < this->rowCount(); i++)
	{
		for (int j = 0; j < this->columnCount(); j++)
		{
			if (this->item(i, j))
			{
				this->item(i, j)->setFlags(Qt::ItemIsEnabled);

				if (i % 2 == 0)
					this->item(i, j)->setBackgroundColor(QColor(240, 240, 240));
			}
		}

	}
}

void ForgBaseLib::FrgBase_PropertiesPanel::SetTableData(int row, int role, const QVariant & value)
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

		if (myVariant->GetDisplayName() ==  "Name")
		{
			this->cellWidget(row, 1)->setEnabled(false);
		}
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
	else if (value.canConvert<FrgBase_PrptsVrntSelectTItems*>())
	{
		FrgBase_PrptsVrntSelectTItems* myVariant = qvariant_cast<FrgBase_PrptsVrntSelectTItems*>(value);

		QTableWidgetItem* propertyName = new QTableWidgetItem(myVariant->GetDisplayName());
		this->setItem(row, 0, propertyName);

		QTableWidgetItem* item = new QTableWidgetItem;
		FrgBase_PrptsWdgSelectTItems* myWidget = new FrgBase_PrptsWdgSelectTItems(this, myVariant);
		this->setItem(row, 1, item);
		this->setCellWidget(row, 1, myWidget);
		myWidget->installEventFilter(this);
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