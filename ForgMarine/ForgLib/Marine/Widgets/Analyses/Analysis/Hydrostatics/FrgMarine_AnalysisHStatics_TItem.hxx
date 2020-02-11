#pragma once
#ifndef _FrgMarine_TItemAnlys_Hydrostatics_Header
#define _FrgMarine_TItemAnlys_Hydrostatics_Header

#include <FrgMarine_Global.hxx>
#include <FrgMarine_Analysis_TItem.hxx>

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_AnalysisHStatics_TItem
	: public FrgMarine_Analysis_TItem
{
	Q_OBJECT

public:

	FrgMarine_AnalysisHStatics_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);
};

EndForgMarineLib

#endif // !_FrgMarine_TItemAnlys_Hydrostatics_Header
