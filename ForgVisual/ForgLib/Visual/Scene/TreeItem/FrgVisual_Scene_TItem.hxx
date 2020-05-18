#pragma once
#ifndef _FrgVisual_Scene_TItem_Header
#define _FrgVisual_Scene_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>

BeginForgVisualLib

class FrgVisual_Scene;

class FORGVISUAL_EXPORT FrgVisual_Scene_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgVisual_Scene_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	~FrgVisual_Scene_TItem();

	FrgVisual_Scene* GetScene() const { return theScene_; }

protected:

	FrgVisual_Scene* theScene_ = NullPtr;
};

EndForgVisualLib

#endif // !_FrgVisual_Scene_TItem_Header
