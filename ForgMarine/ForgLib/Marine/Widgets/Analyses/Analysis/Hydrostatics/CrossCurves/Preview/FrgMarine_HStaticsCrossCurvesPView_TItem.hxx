#pragma once
#ifndef _FrgMarine_HStaticsCrossCurvesPView_TItem_Header
#define _FrgMarine_HStaticsCrossCurvesPView_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgMarine_Scene3D_TItem.hxx>

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_HStaticsCrossCurvesPView_TItem
	: public FrgMarine_Scene3D_TItem
{
	Q_OBJECT

public:

	FrgMarine_HStaticsCrossCurvesPView_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);
};

EndForgMarineLib

#endif // !_FrgMarine_HStaticsCrossCurvesPView_TItem_Header
