#pragma once
#ifndef _FrgCAD2D_Scene_TItem_Header
#define _FrgCAD2D_Scene_TItem_Header

#include <FrgCAD2D_Global.hxx>
#include <FrgVisual_Scene_TItem.hxx>

BeginForgCAD2DLib

class FORGCAD2D_EXPORT FrgCAD2D_Scene_TItem
	: public ForgVisualLib::FrgVisual_Scene_TItem<2>
{

	Q_OBJECT

public:

	FrgCAD2D_Scene_TItem
	(
		const QString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	void FormTItem();
};

EndForgCAD2DLib

#endif // !_FrgCAD2D_Scene_TItem_Header
