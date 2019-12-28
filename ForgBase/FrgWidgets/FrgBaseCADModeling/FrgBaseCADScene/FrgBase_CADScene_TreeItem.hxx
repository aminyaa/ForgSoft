#ifndef _FrgBase_CADScene_TreeItem_Header
#define _FrgBase_CADScene_TreeItem_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTreeItem.hxx>

BeginFrgBaseLib

class FrgBaseCADScene;

class FORGBASE_EXPORT FrgBase_CADScene_TreeItem : public FrgBaseTreeItem
{

public:

	FrgBase_CADScene_TreeItem
	(
		const FrgString& title,
		FrgBaseTreeItem* parent
	);

	virtual ~FrgBase_CADScene_TreeItem()
	{}
};

EndFrgBaseLib

#endif // !_FrgBase_CADScene_TreeItem_Header
