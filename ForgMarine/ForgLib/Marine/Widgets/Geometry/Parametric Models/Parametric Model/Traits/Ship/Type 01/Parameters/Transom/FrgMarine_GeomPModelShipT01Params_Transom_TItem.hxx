#pragma once
#ifndef _FrgMarine_Ship01Params_Transom_Header
#define _FrgMarine_Ship01Params_Transom_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_PrptsVrntDouble.hxx>

namespace tnbLib
{
	class LegModel_DispNo1;
}

BeginForgMarineLib

class FrgMarine_GeomPModelShipT01Params_TItem;

class FORGMARINE_EXPORT FrgMarine_GeomPModelShipT01Params_Transom_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* Rake READ GetRake WRITE SetRake)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* Width READ GetWidth WRITE SetWidth)

public:

	FrgMarine_GeomPModelShipT01Params_Transom_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree,
		std::shared_ptr<tnbLib::LegModel_DispNo1> model,
		FrgMarine_GeomPModelShipT01Params_TItem* parametersTItem
	);

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetRake() const { return theRake_; }
	void SetRake(ForgBaseLib::FrgBase_PrptsVrntDouble* rake) { theRake_ = rake; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetWidth() const { return theWidth_; }
	void SetWidth(ForgBaseLib::FrgBase_PrptsVrntDouble* width) { theWidth_ = width; }

private:

	std::shared_ptr<tnbLib::LegModel_DispNo1> theModel_;

	ForgBaseLib::FrgBase_PrptsVrntDouble* theRake_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theWidth_ = NullPtr;

	FrgMarine_GeomPModelShipT01Params_TItem* theParametersTItem_ = NullPtr;

private slots:

	void RakeValueChangedSlot();
	void WidthValueChangedSlot();

	void PerformToPreview();
};

EndForgMarineLib

#endif // !_FrgMarine_Ship01Params_Transom_Header
