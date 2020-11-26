#pragma once
#ifndef _FrgBase_PrptsWdSelectTItem_Tree_Header
#define _FrgBase_PrptsWdSelectTItem_Tree_Header

#include <FrgBase_Global.hxx>
#include <QtWidgets/QTreeWidget>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsWdgSelectTItem_Tree
	: public QTreeWidget
{
	Q_OBJECT

public:

	FrgBase_PrptsWdgSelectTItem_Tree();

	~FrgBase_PrptsWdgSelectTItem_Tree();
};

EndForgBaseLib

#endif // !_FrgBase_PrptsVrntSelectTItem_Tree_Header
