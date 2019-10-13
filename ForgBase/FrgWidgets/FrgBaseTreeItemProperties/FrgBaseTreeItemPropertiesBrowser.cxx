#include <FrgBaseTreeItemPropertiesBrowser.hxx>

ForgBaseLib::FrgBaseTreeItemPropertiesBrowser::FrgBaseTreeItemPropertiesBrowser(FrgBaseTreeItemProperties* parent)
	: QtTreePropertyBrowser(),
	theParentProperties_(parent)
{
	// empty body
}