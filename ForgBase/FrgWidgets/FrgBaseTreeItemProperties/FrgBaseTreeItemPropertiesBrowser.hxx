#pragma once
#ifndef _FrgBaseTreeItemPropertiesBrowser_Header
#define _FrgBaseTreeItemPropertiesBrowser_Header

#include <FrgBaseGlobals.hxx>

#include <qttreepropertybrowser.h>

BeginFrgBaseLib

class FrgBaseTreeItemProperties;

class FORGBASE_EXPORT FrgBaseTreeItemPropertiesBrowser : public QtTreePropertyBrowser
{

private:

	FrgBaseTreeItemProperties* theParentProperties_ = FrgNullPtr;

public:

	FrgBaseTreeItemPropertiesBrowser(FrgBaseTreeItemProperties* parent = FrgNullPtr);

	FrgGetMacro(FrgBaseTreeItemProperties*, ParentProperties, theParentProperties_);
};

EndFrgBaseLib

#endif // !_FrgBaseTreeItemPropertiesBrowser_Header
