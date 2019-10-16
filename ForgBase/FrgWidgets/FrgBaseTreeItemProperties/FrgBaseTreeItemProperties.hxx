#pragma once
#ifndef _FrgBaseTreeItemProperties_Header
#define _FrgBaseTreeItemProperties_Header

#include <FrgBaseGlobals.hxx>

#include <QtGui/QVector2D>
#include <QtGui/QVector3D>
#include <QtGui/QVector4D>

#include <qttreepropertybrowser.h>
#include <qtvariantproperty.h>

class QtVariantPropertyManager;
class QtVariantEditorFactory;
class QtVariantProperty;
class QtProperty;

BeginFrgBaseLib

typedef FrgInt Int;
typedef FrgDouble Double;
typedef FrgString String;
typedef QPointF PointF;
//typedef QVector3D Vector2D;
//typedef QVector3D Vector3D;
//typedef QVector3D Vector4D;

#define AddPropertyMACRO(type)\
void ForgBaseLib::FrgBaseTreeItemProperties::AddProperty##type(const FrgString& topProperty, const FrgString& name, const type& value, const FrgString& propertyId = "")\
{\
	QtVariantProperty* item = AddProperty(topProperty, QVariant::type, name, propertyId);\
\
	item->setValue(value);\
}

class FrgBaseTreeItem;

class FORGBASE_EXPORT FrgBaseTreeItemProperties
{

private:

	QtAbstractPropertyBrowser* thePropertyBrowser_ = FrgNullPtr;

	QtAbstractPropertyManager* theAbstractPropertyManager_ = FrgNullPtr;
	QtAbstractEditorFactory<QtAbstractPropertyManager>* theAbstractEditorFactory_ = FrgNullPtr;

	QtVariantPropertyManager* theVariantPropertyManager_ = FrgNullPtr;
	QtVariantEditorFactory* theVariantEditorFactory_ = FrgNullPtr;

	FrgVector<QtProperty*> theTopProperties_;

	FrgBaseTreeItem* theParentTreeItem_ = FrgNullPtr;

public:

	FrgBaseTreeItemProperties(FrgBaseTreeItem* parent);

	FrgGetMacro(FrgVector<QtProperty*>, Properties, theTopProperties_);

	QtProperty* GetTopProperty(const FrgString& name);

	QtProperty* GetProperty(const FrgString& name);

	void AddTopProperty(const FrgString& name, const FrgString& topProperty = "");

	QtVariantProperty* AddProperty(const FrgString& topProperty, FrgInt propertyType, const FrgString& name, const FrgString& propertyId = "");

	/*void AddPropertyString(const FrgString& topProperty, const FrgString& name, const FrgString& value);

	void AddPropertyDouble(const FrgString& topProperty, const FrgString& name, FrgDouble value);

	void AddPropertyInt(const FrgString& topProperty, const FrgString& name, FrgInt value);*/

	void SetEnabled(const FrgString& name, FrgBool condition = FrgTrue);

	void SetExpanded(const FrgString& title, FrgBool condition);

	FrgGetMacro(QtAbstractPropertyBrowser*, PropertyBrowser, thePropertyBrowser_);
	FrgGetMacro(QtVariantPropertyManager*, PropertyManager, theVariantPropertyManager_);
	FrgGetMacro(FrgBaseTreeItem*, ParentTreeItem, theParentTreeItem_);
	FrgGetMacro(QtAbstractPropertyManager*, AbstractPropertyManager, theAbstractPropertyManager_);
	FrgGetMacro(QtAbstractEditorFactory<QtAbstractPropertyManager>*, AbstractEditorFactory, theAbstractEditorFactory_);

	AddPropertyMACRO(Int);
	AddPropertyMACRO(Double);
	AddPropertyMACRO(String);
	AddPropertyMACRO(PointF);

	template<class PropertyManager>
	void AddProperty(const FrgString& title, PropertyManager* manager, QtAbstractEditorFactory<PropertyManager>* factory)
	{
		thePropertyBrowser_->setFactoryForManager<PropertyManager>(manager, factory);

		QtProperty* item = manager->addProperty(title);
		thePropertyBrowser_->addProperty(item);
	}

	void AddPropertyFlagType(const FrgString& topProperty, const FrgString& name, QStringList flagNames, const FrgString& propertyId = "");

	/*AddPropertyMACRO(Vector2D);
	AddPropertyMACRO(Vector3D);
	AddPropertyMACRO(Vector4D);*/
};

EndFrgBaseLib

#endif // !_FrgBaseTreeItemProperties_Header
