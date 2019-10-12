#pragma once
#ifndef _FrgBaseTreeItemProperty_Header
#define _FrgBaseTreeItemProperty_Header

#include <FrgBaseGlobals.hxx>

#include <QtGui/QVector2D>
#include <QtGui/QVector3D>
#include <QtGui/QVector4D>

#include <qttreepropertybrowser.h>
#include <qtvariantproperty.h>

class QtTreePropertyBrowser;
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
void ForgBaseLib::FrgBaseTreeItemProperty::AddProperty##type(const FrgString& topProperty, const FrgString& name, const type& value)\
{\
	QtVariantProperty* item = AddProperty(topProperty, QVariant::type, name);\
\
	item->setValue(value);\
	item->setPropertyId(item->propertyName());\
}

class FrgBaseTreeItem;

class FrgBaseTreeItemProperty
{

private:

	QtTreePropertyBrowser* thePropertyBrowser_;
	QtVariantPropertyManager* theVariantPropertyManager_;
	QtVariantEditorFactory* theVariantEditorFactory_;

	FrgVector<QtProperty*> theTopProperties_;

	FrgBaseTreeItem* theParentTreeItem_ = FrgNullPtr;

public:

	FrgBaseTreeItemProperty(FrgBaseTreeItem* parent);

	FrgGetMacro(FrgVector<QtProperty*>, Properties, theTopProperties_);

	QtProperty* GetTopProperty(const FrgString& name);

	QtProperty* GetProperty(const FrgString& name);

	void AddTopProperty(const FrgString& name);

	QtVariantProperty* AddProperty(const FrgString& topProperty, FrgInt propertyType, const FrgString& name);

	/*void AddPropertyString(const FrgString& topProperty, const FrgString& name, const FrgString& value);

	void AddPropertyDouble(const FrgString& topProperty, const FrgString& name, FrgDouble value);

	void AddPropertyInt(const FrgString& topProperty, const FrgString& name, FrgInt value);*/

	void SetEnabled(const FrgString& name, FrgBool condition = FrgTrue);

	FrgGetMacro(QtTreePropertyBrowser*, PropertyBrowser, thePropertyBrowser_);

	AddPropertyMACRO(Int);
	AddPropertyMACRO(Double);
	AddPropertyMACRO(String);
	AddPropertyMACRO(PointF);
	/*AddPropertyMACRO(Vector2D);
	AddPropertyMACRO(Vector3D);
	AddPropertyMACRO(Vector4D);*/
};

EndFrgBaseLib

#endif // !_FrgBaseTreeItemProperty_Header
