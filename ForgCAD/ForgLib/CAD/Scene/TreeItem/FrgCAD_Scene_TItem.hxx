#pragma once
#ifndef _FrgCAD_Scene_TItem_Header
#define _FrgCAD_Scene_TItem_Header

#include <FrgCAD_Global.hxx>
#include <FrgVisual_Scene_TItem.hxx>

BeginForgCADLib

class FORGCAD_EXPORT FrgCAD_Scene_TItem
	: public ForgVisualLib::FrgVisual_Scene_TItem<2>
{

	Q_OBJECT

public:

	FrgCAD_Scene_TItem
	(
		const QString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	void FormTItem();
};

EndForgCADLib

#endif // !_FrgCAD_Scene_TItem_Header
