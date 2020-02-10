#pragma once
#ifndef _FrgMarine_TItemGeom_Preview_Header
#define _FrgMarine_TItemGeom_Preview_Header

#include <FrgMarine_Global.hxx>
#include <FrgVisual_Scene3DTItem.hxx>
#include <FrgBase_PrptsVrntDouble.hxx>
#include <FrgBase_PrptsVrntBool.hxx>

namespace tnbLib
{
	class CadModel_Entity;
	class FastDiscrete_Params;
}

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_TItemGeomParMdls_Preview
	: public ForgVisualLib::FrgVisual_Scene3DTItem
{

	Q_OBJECT

		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* FastDiscrete_Angle READ GetFastDiscrete_Angle WRITE SetFastDiscrete_Angle)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* FastDiscrete_Deflection READ GetFastDiscrete_Deflection WRITE SetFastDiscrete_Deflection)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* FastDiscrete_MinSize READ GetFastDiscrete_MinSize WRITE SetFastDiscrete_MinSize)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntBool* FastDiscrete_InParallel READ GetFastDiscrete_InParallel WRITE SetFastDiscrete_InParallel)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntBool* FastDiscrete_Relative READ GetFastDiscrete_Relative WRITE SetFastDiscrete_Relative)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntBool* FastDiscrete_AdaptiveMin READ GetFastDiscrete_AdaptiveMin WRITE SetFastDiscrete_AdaptiveMin)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntBool* FastDiscrete_InternalVerticesMode READ GetFastDiscrete_InternalVerticesMode WRITE SetFastDiscrete_InternalVerticesMode)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntBool* FastDiscrete_ControlSurfaceDeflection READ GetFastDiscrete_ControlSurfaceDeflection WRITE SetFastDiscrete_ControlSurfaceDeflection)

public:

	FrgMarine_TItemGeomParMdls_Preview
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree,
		std::shared_ptr<tnbLib::CadModel_Entity> modelEntity
	);

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetFastDiscrete_Angle() const { return theFastDiscrete_Angle_; }
	void SetFastDiscrete_Angle(ForgBaseLib::FrgBase_PrptsVrntDouble* angle) { theFastDiscrete_Angle_ = angle; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetFastDiscrete_Deflection() const { return theFastDiscrete_Deflection_; }
	void SetFastDiscrete_Deflection(ForgBaseLib::FrgBase_PrptsVrntDouble* deflection) { theFastDiscrete_Deflection_ = deflection; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetFastDiscrete_MinSize() const { return theFastDiscrete_MinSize_; }
	void SetFastDiscrete_MinSize(ForgBaseLib::FrgBase_PrptsVrntDouble* minSize) { theFastDiscrete_MinSize_ = minSize; }

	ForgBaseLib::FrgBase_PrptsVrntBool* GetFastDiscrete_InParallel() const { return theFastDiscrete_InParallel_; }
	void SetFastDiscrete_InParallel(ForgBaseLib::FrgBase_PrptsVrntBool* inParallel) { theFastDiscrete_InParallel_ = inParallel; }

	ForgBaseLib::FrgBase_PrptsVrntBool* GetFastDiscrete_Relative() const { return theFastDiscrete_Relative_; }
	void SetFastDiscrete_Relative(ForgBaseLib::FrgBase_PrptsVrntBool* relative) { theFastDiscrete_Relative_ = relative; }

	ForgBaseLib::FrgBase_PrptsVrntBool* GetFastDiscrete_AdaptiveMin() const { return theFastDiscrete_AdaptiveMin_; }
	void SetFastDiscrete_AdaptiveMin(ForgBaseLib::FrgBase_PrptsVrntBool* adaptiveMin) { theFastDiscrete_AdaptiveMin_ = adaptiveMin; }

	ForgBaseLib::FrgBase_PrptsVrntBool* GetFastDiscrete_InternalVerticesMode() const { return theFastDiscrete_InternalVerticesMode_; }
	void SetFastDiscrete_InternalVerticesMode(ForgBaseLib::FrgBase_PrptsVrntBool* internalVerticesMode) { theFastDiscrete_InternalVerticesMode_ = internalVerticesMode; }

	ForgBaseLib::FrgBase_PrptsVrntBool* GetFastDiscrete_ControlSurfaceDeflection() const { return theFastDiscrete_ControlSurfaceDeflection_; }
	void SetFastDiscrete_ControlSurfaceDeflection(ForgBaseLib::FrgBase_PrptsVrntBool* controlSurfaceDeflection) { theFastDiscrete_ControlSurfaceDeflection_ = controlSurfaceDeflection; }

	void ShowTabWidget();

public slots:

	void UpdatePreviewSlot();
	void TItemDoubleClickedSlot() override;

private:

	ForgBaseLib::FrgBase_PrptsVrntDouble* theFastDiscrete_Angle_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theFastDiscrete_Deflection_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theFastDiscrete_MinSize_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntBool* theFastDiscrete_InParallel_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntBool* theFastDiscrete_Relative_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntBool* theFastDiscrete_AdaptiveMin_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntBool* theFastDiscrete_InternalVerticesMode_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntBool* theFastDiscrete_ControlSurfaceDeflection_ = NullPtr;

	std::shared_ptr<tnbLib::CadModel_Entity> theModelEntity_;
	std::shared_ptr<tnbLib::FastDiscrete_Params> theFastDiscreteParams_;

private:

	void FormFastDiscreteParams();
	void ConnectVrntsToSlots();
	void DisconnectVrntsToSlots();

private slots:

	void FDiscAngleValueChangedSlot();
	void FDiscDeflectionValueChangedSlot();
	void FDiscMinSizeValueChangedSlot();
	void FDiscInParallelValueChangedSlot();
	void FDiscRelativeValueChangedSlot();
	void FDiscAdaptiveMinValueChangedSlot();
	void FDiscInternalVerticesModeMinValueChangedSlot();
	void FDiscControlSurfaceDeflectionMinValueChangedSlot();

	void TItemNameToTabTitleChangedSlot(const QString& title);
};

EndForgMarineLib

#endif // !_FrgMarine_TItemGeom_Preview_Header
