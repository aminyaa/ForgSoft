#pragma once
#ifndef _FrgVisual_Scene3DTItem_Header
#define _FrgVisual_Scene3DTItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>

BeginForgVisualLib

class FrgVisual_Scene3D;

class FORGVISUAL_EXPORT FrgVisual_Scene3DTItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	//Q_OBJECT

public:

	FrgVisual_Scene3DTItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

protected:

	FrgVisual_Scene3D* theScene_ = NullPtr;

};

EndForgVisualLib

#endif // !_FrgVisual_Scene3DTItem_Header
