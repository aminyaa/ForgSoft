#pragma once
#ifndef _FrgBase_Tools_TItem_Header
#define _FrgBase_Tools_TItem_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_TreeItem.hxx>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_Tools_TItem
	: public FrgBase_TreeItem
{

	Q_OBJECT

public:

	FrgBase_Tools_TItem
	(
		const QString& itemTitle,
		FrgBase_TreeItem* parentItem,
		FrgBase_Tree* parentTree
	);

	void FormTItem() override;
};

EndForgBaseLib

#endif // !_FrgBase_Tools_TItem_Header
