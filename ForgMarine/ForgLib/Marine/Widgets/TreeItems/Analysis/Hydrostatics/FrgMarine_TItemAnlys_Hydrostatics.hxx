#pragma once
#ifndef _FrgMarine_TItemAnlys_Hydrostatics_Header
#define _FrgMarine_TItemAnlys_Hydrostatics_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_TItemAnlys_Hydrostatics
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgMarine_TItemAnlys_Hydrostatics
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);
};

EndForgMarineLib

#endif // !_FrgMarine_TItemAnlys_Hydrostatics_Header
