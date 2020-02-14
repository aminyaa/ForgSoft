#include <FrgMarine_GeomPModelPView_TItem.hxx>
#include <FrgVisual_Scene3D.hxx>
#include <FrgMarine_MainWindow.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_TabWidget.hxx>

#include <CadModel_Entity.hxx>
#include <Cad_Tools.hxx>
#include <FastDiscrete_Params.hxx>
#include <Cad_FastDiscrete.hxx>
#include <Bnd_Box.hxx>
#include <Entity3d_Box.hxx>
#include <Poly_Triangulation.hxx>

#include <vtkRenderer.h>
#include <vtkActorCollection.h>
#include <vtkAssemblyPath.h>

ForgMarineLib::FrgMarine_GeomPModelPView_TItem::FrgMarine_GeomPModelPView_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree,
	std::shared_ptr<tnbLib::CadModel_Entity> modelEntity
)
	: FrgMarine_Scene3D_TItem(itemTitle, parentItem, parentTree)
	, theModelEntity_(modelEntity)
{
	this->setIcon(0, QIcon(ICONTreeItemEye));

	DeleteRenameOptionInContextMenu();

	auto myMainWindow = dynamic_cast<FrgMarine_MainWindow*>(GetParentMainWindow());
	if (myMainWindow)
	{
		myMainWindow->ShowTabWidget(theScene_, parentItem->text(0) + " " + this->text(0));
		connect(parentItem, SIGNAL(TItemNameChanged(const QString&)), this, SLOT(TItemNameToTabTitleChangedSlot(const QString&)));
	}

	theFastDiscreteParams_ = std::make_shared<tnbLib::FastDiscrete_Params>();
	theFastDiscreteParams_->Angle = 1.0;

	FormFastDiscreteParams();

	UpdatePreviewSlot();
	theScene_->RenderScene(true);

	ConnectVrntsToSlots();
}

void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::UpdatePreviewSlot()
{
	if (theModelEntity_)
	{
		ShowTabWidget();

		const auto& myPreviewShape = theModelEntity_->PreviewEntity();

		auto b0 = tnbLib::Cad_Tools::BoundingBox(myPreviewShape);
		auto box = tnbLib::Cad_Tools::BoundingBox(b0);

		theFastDiscreteParams_->Deflection = 1.0e-4*box.Diameter();

		DisconnectVrntsToSlots();
		theFastDiscrete_Deflection_->SetValue(theFastDiscreteParams_->Deflection);
		ConnectVrntsToSlots();

		tnbLib::Cad_FastDiscrete::Triangulation(myPreviewShape, *theFastDiscreteParams_.get());

		auto myTris = tnbLib::Cad_Tools::RetrieveTriangulation(myPreviewShape);

		theScene_->RemoveAllActors();
		dynamic_cast<ForgVisualLib::FrgVisual_Scene3D*>(theScene_)->AddTriangulations<opencascade::handle<Poly_Triangulation>>(myTris, false);
	}
}

void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::FormFastDiscreteParams()
{
	theFastDiscrete_Angle_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Angle", theFastDiscreteParams_->Angle, 1.0, 360.0, 1.0, "", "[deg]");

	theFastDiscrete_Deflection_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Deflection", theFastDiscreteParams_->Deflection, 0.0, 10.0, 1.0E-8);

	theFastDiscrete_MinSize_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Minimum Size", theFastDiscreteParams_->MinSize, 0.0, 10.0, 1.0E-8);

	theFastDiscrete_InParallel_ = new ForgBaseLib::FrgBase_PrptsVrntBool
	("Execute in Parallel", theFastDiscreteParams_->InParallel);

	theFastDiscrete_Relative_ = new ForgBaseLib::FrgBase_PrptsVrntBool
	("Relative", theFastDiscreteParams_->Relative);

	theFastDiscrete_AdaptiveMin_ = new ForgBaseLib::FrgBase_PrptsVrntBool
	("Adaptive Minimum", theFastDiscreteParams_->AdaptiveMin);

	theFastDiscrete_InternalVerticesMode_ = new ForgBaseLib::FrgBase_PrptsVrntBool
	("Internal Vertices Mode", theFastDiscreteParams_->InternalVerticesMode);

	theFastDiscrete_ControlSurfaceDeflection_ = new ForgBaseLib::FrgBase_PrptsVrntBool
	("Control Surface Deflection", theFastDiscreteParams_->ControlSurfaceDeflection);

	thePropertiesPanel_ = new ForgBaseLib::FrgBase_PropertiesPanel(GetParentMainWindow(), this);
}

void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::ConnectVrntsToSlots()
{
	connect(theFastDiscrete_Angle_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(FDiscAngleValueChangedSlot()));
	connect(theFastDiscrete_Deflection_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(FDiscDeflectionValueChangedSlot()));
	connect(theFastDiscrete_MinSize_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(FDiscMinSizeValueChangedSlot()));
	connect(theFastDiscrete_InParallel_, SIGNAL(ValueChangedSignal(const bool&)), this, SLOT(FDiscInParallelValueChangedSlot()));
	connect(theFastDiscrete_Relative_, SIGNAL(ValueChangedSignal(const bool&)), this, SLOT(FDiscRelativeValueChangedSlot()));
	connect(theFastDiscrete_AdaptiveMin_, SIGNAL(ValueChangedSignal(const bool&)), this, SLOT(FDiscAdaptiveMinValueChangedSlot()));
	connect(theFastDiscrete_InternalVerticesMode_, SIGNAL(ValueChangedSignal(const bool&)), this, SLOT(FDiscInternalVerticesModeMinValueChangedSlot()));
	connect(theFastDiscrete_ControlSurfaceDeflection_, SIGNAL(ValueChangedSignal(const bool&)), this, SLOT(FDiscControlSurfaceDeflectionMinValueChangedSlot()));
}

void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::DisconnectVrntsToSlots()
{
	disconnect(theFastDiscrete_Angle_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(FDiscAngleValueChangedSlot()));
	disconnect(theFastDiscrete_Deflection_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(FDiscDeflectionValueChangedSlot()));
	disconnect(theFastDiscrete_MinSize_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(FDiscMinSizeValueChangedSlot()));
	disconnect(theFastDiscrete_InParallel_, SIGNAL(ValueChangedSignal(const bool&)), this, SLOT(FDiscInParallelValueChangedSlot()));
	disconnect(theFastDiscrete_Relative_, SIGNAL(ValueChangedSignal(const bool&)), this, SLOT(FDiscRelativeValueChangedSlot()));
	disconnect(theFastDiscrete_AdaptiveMin_, SIGNAL(ValueChangedSignal(const bool&)), this, SLOT(FDiscAdaptiveMinValueChangedSlot()));
	disconnect(theFastDiscrete_InternalVerticesMode_, SIGNAL(ValueChangedSignal(const bool&)), this, SLOT(FDiscInternalVerticesModeMinValueChangedSlot()));
	disconnect(theFastDiscrete_ControlSurfaceDeflection_, SIGNAL(ValueChangedSignal(const bool&)), this, SLOT(FDiscControlSurfaceDeflectionMinValueChangedSlot()));
}

void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::FDiscAngleValueChangedSlot()
{
	if (theFastDiscreteParams_->Angle != theFastDiscrete_Angle_->GetValue())
	{
		theFastDiscreteParams_->Angle = theFastDiscrete_Angle_->GetValue();
		theModelEntity_->PerformToPreview();
		UpdatePreviewSlot();
	}
}

void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::FDiscDeflectionValueChangedSlot()
{
	if (theFastDiscreteParams_->Deflection != theFastDiscrete_Deflection_->GetValue())
	{
		theFastDiscreteParams_->Deflection = theFastDiscrete_Deflection_->GetValue();
		theModelEntity_->PerformToPreview();
		UpdatePreviewSlot();
	}
}

void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::FDiscMinSizeValueChangedSlot()
{
	if (theFastDiscreteParams_->MinSize != theFastDiscrete_MinSize_->GetValue())
	{
		theFastDiscreteParams_->MinSize = theFastDiscrete_MinSize_->GetValue();
		theModelEntity_->PerformToPreview();
		UpdatePreviewSlot();
	}
}

void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::FDiscInParallelValueChangedSlot()
{
	if (theFastDiscreteParams_->InParallel != theFastDiscrete_InParallel_->GetValue())
	{
		theFastDiscreteParams_->InParallel = theFastDiscrete_InParallel_->GetValue();
		/*theModelEntity_->PerformToPreview();
		UpdatePreviewSlot();*/
	}
}

void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::FDiscRelativeValueChangedSlot()
{
	if (theFastDiscreteParams_->Relative != theFastDiscrete_Relative_->GetValue())
	{
		theFastDiscreteParams_->Relative = theFastDiscrete_Relative_->GetValue();
		theModelEntity_->PerformToPreview();
		UpdatePreviewSlot();
	}
}

void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::FDiscAdaptiveMinValueChangedSlot()
{
	if (theFastDiscreteParams_->AdaptiveMin != theFastDiscrete_AdaptiveMin_->GetValue())
	{
		theFastDiscreteParams_->AdaptiveMin = theFastDiscrete_AdaptiveMin_->GetValue();
		theModelEntity_->PerformToPreview();
		UpdatePreviewSlot();
	}
}

void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::FDiscInternalVerticesModeMinValueChangedSlot()
{
	if (theFastDiscreteParams_->InternalVerticesMode != theFastDiscrete_InternalVerticesMode_->GetValue())
	{
		theFastDiscreteParams_->InternalVerticesMode = theFastDiscrete_InternalVerticesMode_->GetValue();
		theModelEntity_->PerformToPreview();
		UpdatePreviewSlot();
	}
}

void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::FDiscControlSurfaceDeflectionMinValueChangedSlot()
{
	if (theFastDiscreteParams_->ControlSurfaceDeflection != theFastDiscrete_ControlSurfaceDeflection_->GetValue())
	{
		theFastDiscreteParams_->ControlSurfaceDeflection = theFastDiscrete_ControlSurfaceDeflection_->GetValue();
		theModelEntity_->PerformToPreview();
		UpdatePreviewSlot();
	}
}

void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::TItemNameToTabTitleChangedSlot(const QString & title)
{
	auto myMainWindow = dynamic_cast<FrgMarine_MainWindow*>(GetParentMainWindow());
	if (myMainWindow)
		myMainWindow->SetTabText(theScene_, title + " " + this->text(0));
}

void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::ShowTabWidget()
{
	auto myMainWindow = dynamic_cast<FrgMarine_MainWindow*>(GetParentMainWindow());
	if (myMainWindow)
		myMainWindow->ShowTabWidget(theScene_, dynamic_cast<QTreeWidgetItem*>(this)->parent()->text(0) + " " + this->text(0));
}

void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::TItemDoubleClickedSlot()
{
	ShowTabWidget();
}