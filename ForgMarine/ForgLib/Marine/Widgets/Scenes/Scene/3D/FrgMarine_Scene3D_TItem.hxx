#ifndef _FrgMarine_Scene3D_TItem_Header
#define _FrgMarine_Scene3D_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgVisual_Scene3D_TItem.hxx>

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_Scene3D_TItem
	: public ForgVisualLib::FrgVisual_Scene3D_TItem
{
	Q_OBJECT

public:

	FrgMarine_Scene3D_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);
};

EndForgMarineLib

#endif // !_FrgMarine_Scene3D_TItem_Header
