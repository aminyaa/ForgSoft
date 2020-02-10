#pragma once
#ifndef _FrgMarine_Ship01Params_Dimensions_Header
#define _FrgMarine_Ship01Params_Dimensions_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_PrptsVrntDouble.hxx>
#include <FrgBase_PrptsVrntInt.hxx>

namespace tnbLib
{
	class LegModel_DispNo1;
}

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_Ship01Params_Dimensions
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* Draft READ GetDraft WRITE SetDraft)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* TransomHeight READ GetTransomHeight WRITE SetTransomHeight)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* DepthAtBow READ GetDepthAtBow WRITE SetDepthAtBow)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* DepthAtTransom READ GetDepthAtTransom WRITE SetDepthAtTransom)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* BeamOnDeck READ GetBeamOnDeck WRITE SetBeamOnDeck)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* LengthOnDeck READ GetLengthOnDeck WRITE SetLengthOnDeck)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntInt* NbNetRows READ GetNbNetRows WRITE SetNbNetRows)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntInt* NbNetColumns READ GetNbNetColumns WRITE SetNbNetColumns)

public:

	FrgMarine_Ship01Params_Dimensions
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree,
		std::shared_ptr<tnbLib::LegModel_DispNo1> model
	);

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetDraft() const { return theDraft_; }
	void SetDraft(ForgBaseLib::FrgBase_PrptsVrntDouble* draft) { theDraft_ = draft; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetTransomHeight() const { return theTransomHeight_; }
	void SetTransomHeight(ForgBaseLib::FrgBase_PrptsVrntDouble* transomHeight) { theTransomHeight_ = transomHeight; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetDepthAtBow() const { return theDepthAtBow_; }
	void SetDepthAtBow(ForgBaseLib::FrgBase_PrptsVrntDouble* depthAtBow) { theDepthAtBow_ = depthAtBow; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetDepthAtTransom() const { return theDepthAtTransom_; }
	void SetDepthAtTransom(ForgBaseLib::FrgBase_PrptsVrntDouble* depthAtTransom) { theDepthAtTransom_ = depthAtTransom; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetBeamOnDeck() const { return theBeamOnDeck_; }
	void SetBeamOnDeck(ForgBaseLib::FrgBase_PrptsVrntDouble* beamOnDeck) { theBeamOnDeck_ = beamOnDeck; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetLengthOnDeck() const { return theLengthOnDeck_; }
	void SetLengthOnDeck(ForgBaseLib::FrgBase_PrptsVrntDouble* lengthOnDeck) { theLengthOnDeck_ = lengthOnDeck; }

	ForgBaseLib::FrgBase_PrptsVrntInt* GetNbNetRows() const { return theNbNetRows_; }
	void SetNbNetRows(ForgBaseLib::FrgBase_PrptsVrntInt* nbNetRows) { theNbNetRows_ = nbNetRows; }

	ForgBaseLib::FrgBase_PrptsVrntInt* GetNbNetColumns() const { return theNbNetColumns_; }
	void SetNbNetColumns(ForgBaseLib::FrgBase_PrptsVrntInt* nbNetColumns) { theNbNetColumns_ = nbNetColumns; }

private:

	std::shared_ptr<tnbLib::LegModel_DispNo1> theModel_;

	ForgBaseLib::FrgBase_PrptsVrntDouble* theDraft_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theTransomHeight_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theDepthAtBow_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theDepthAtTransom_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theBeamOnDeck_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theLengthOnDeck_ = NullPtr;

	ForgBaseLib::FrgBase_PrptsVrntInt* theNbNetRows_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntInt* theNbNetColumns_ = NullPtr;

private slots:

	void DraftValueChangedSlot();
	void TransomHeightValueChangedSlot();
	void DepthAtBowValueChangedSlot();
	void DepthAtTransomValueChangedSlot();
	void BeamOnDeckValueChangedSlot();
	void LengthOnDeckValueChangedSlot();
	void NbNetRowsValueChangedSlot();
	void NbNetColumnsValueChangedSlot();

	void PerformToPreview();
};

EndForgMarineLib

#endif // !_FrgMarine_Ship01Params_Dimensions_Header
