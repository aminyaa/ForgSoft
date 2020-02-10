#pragma once
#ifndef _FrgMarine_Ship01_Params_Header
#define _FrgMarine_Ship01_Params_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

namespace tnbLib
{
	class LegModel_DispNo1;
}

BeginForgMarineLib

class FrgMarine_Ship01Params_Dimensions;
class FrgMarine_Ship01Params_Hull;
class FrgMarine_Ship01Params_Keel;
class FrgMarine_Ship01Params_Stem;
class FrgMarine_Ship01Params_Transom;

class FORGMARINE_EXPORT FrgMarine_Ship01_Params
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgMarine_Ship01_Params
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree,
		std::shared_ptr<tnbLib::LegModel_DispNo1> model
	);

private:

	std::shared_ptr<tnbLib::LegModel_DispNo1> theModel;

	FrgMarine_Ship01Params_Dimensions* theDimension_ = NullPtr;
	FrgMarine_Ship01Params_Hull* theHull_ = NullPtr;
	FrgMarine_Ship01Params_Keel* theKeel_ = NullPtr;
	FrgMarine_Ship01Params_Stem* theStem_ = NullPtr;
	FrgMarine_Ship01Params_Transom* theTransom_ = NullPtr;
};

EndForgMarineLib

#endif // !_FrgMarine_Ship01_Params_Header
