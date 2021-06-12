#pragma once
#ifndef _FrgBase_PrptsWdgSelectTItemFromTItem_Tree_Header
#define _FrgBase_PrptsWdgSelectTItemFromTItem_Tree_Header

#include <FrgBase_Global.hxx>
#include <QtWidgets/QTreeWidget>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsWdgSelectTItemFromTItem_Tree
	: public QTreeWidget
{
	Q_OBJECT

public:

	FrgBase_PrptsWdgSelectTItemFromTItem_Tree();

	~FrgBase_PrptsWdgSelectTItemFromTItem_Tree();
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgSelectTItemFromTItem_Tree_Header
