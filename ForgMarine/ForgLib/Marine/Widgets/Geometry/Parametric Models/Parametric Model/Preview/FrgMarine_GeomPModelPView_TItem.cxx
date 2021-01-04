#include <FrgMarine_GeomPModelPView_TItem.hxx>
#include <FrgVisual_Scene3D.hxx>
#include <FrgMarine_MainWindow.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_TabWidget.hxx>
#include <FrgVisual_BoxActor.hxx>
#include <FrgVisual_LineActor.hxx>

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

	this->RemoveRenameOptionInContextMenu();
	this->RemoveDeleteOptionInContextMenu();

	/*auto myMainWindow = dynamic_cast<FrgMarine_MainWindow*>(GetParentMainWindow());
	if (myMainWindow)
	{
		myMainWindow->ShowTabWidget(theScene_, parentItem->text(0) + " " + this->text(0));
		connect(parentItem, SIGNAL(TItemNameChanged(const QString&)), this, SLOT(TItemNameToTabTitleChangedSlot(const QString&)));
	}*/
}

ForgMarineLib::FrgMarine_GeomPModelPView_TItem::~FrgMarine_GeomPModelPView_TItem()
{
	FreePointer(theFastDiscrete_Angle_);
	FreePointer(theFastDiscrete_Deflection_);
	FreePointer(theFastDiscrete_MinSize_);
	FreePointer(theFastDiscrete_InParallel_);
	FreePointer(theFastDiscrete_Relative_);
	FreePointer(theFastDiscrete_AdaptiveMin_);
	FreePointer(theFastDiscrete_InternalVerticesMode_);
	FreePointer(theFastDiscrete_ControlSurfaceDeflection_);
}

void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::FormTItem()
{
	FrgMarine_Scene3D_TItem::FormTItem();

	theFastDiscreteParams_ = std::make_shared<tnbLib::FastDiscrete_Params>();
	theFastDiscreteParams_->Angle = 1.0;

	FormFastDiscreteParams();

	UpdatePreviewSlot();
	theScene_->RenderScene(true);

	ConnectVrntsToSlots();
}

#include <FrgBase_Pnt3d.hxx>

void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::UpdatePreviewSlot()
{
	if (theModelEntity_)
	{
		ShowTabWidget();

		const auto& myPreviewShape = theModelEntity_->PreviewEntity();

		auto b0 = tnbLib::Cad_Tools::BoundingBox(myPreviewShape);
		auto box = tnbLib::Cad_Tools::BoundingBox(b0);

		theFastDiscreteParams_->Deflection = 1.0e-4 * box.Diameter();

		DisconnectVrntsToSlots();
		theFastDiscrete_Deflection_->SetValue(theFastDiscreteParams_->Deflection);
		ConnectVrntsToSlots();

		tnbLib::Cad_FastDiscrete::Triangulation(myPreviewShape, *theFastDiscreteParams_.get());

		auto myTris = tnbLib::Cad_Tools::RetrieveTriangulation(myPreviewShape);

		theScene_->RemoveAllActors();
		auto myScene = dynamic_cast<ForgVisualLib::FrgVisual_Scene3D*>(theScene_);
		if (myScene)
		{
			//myScene->DrawGrid(0.0, 0.0, 150.0, 150.0, 30, 30);

			for (int iMesh = 0; iMesh < myTris.size(); iMesh++)
			{
				auto myMesh = myTris[iMesh];

				if (myMesh.IsNull())
					continue;

				auto myMeshNodes = myMesh->Nodes();
				std::vector<ForgBaseLib::FrgBase_Pnt<3>> myMeshPoints;
				for (int iPt = 0; iPt < myMeshNodes.Size(); iPt++)
				{
					auto x = myMeshNodes.Value(iPt + 1).X();
					auto y = myMeshNodes.Value(iPt + 1).Y();
					auto z = myMeshNodes.Value(iPt + 1).Z();
					myMeshPoints.push_back(ForgBaseLib::FrgBase_Pnt3d(x, y, z));
				}

				auto myTrianglesNodes = myMesh->Triangles();
				std::vector<std::tuple<int, int, int>> myTriangles;

				for (int iTri = 0; iTri < myTrianglesNodes.Size(); iTri++)
				{
					int I1 = myTrianglesNodes.Value(iTri + 1).Value(1);
					int I2 = myTrianglesNodes.Value(iTri + 1).Value(2);
					int I3 = myTrianglesNodes.Value(iTri + 1).Value(3);
					std::tuple<int, int, int> myData = std::make_tuple(I1, I2, I3);
					myTriangles.push_back(std::tuple<int, int, int>(myData));
				}

				myScene->AddTriangulation(myMeshPoints, myTriangles);
			}

			//myScene->AddTriangulations<opencascade::handle<Poly_Triangulation>>(myTris, true);
			//myScene->AddBox(0.0, -15.0, 0.0, 100.0, 20.0, 15.0)->SetColor(0.7, 0.7, 0.7);
			//myScene->AddPoint(0.0, 0.0, 0.0);
			//myScene->AddLine(0.0, 0.0, 0.0, 0.0, 0.0, 20.0);

			//std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<3>>> myBSPPts;
			//myBSPPts.push_back(std::make_shared<ForgBaseLib::FrgBase_Pnt<3>>(0.0, 0.0, 0.0));
			//myBSPPts.push_back(std::make_shared<ForgBaseLib::FrgBase_Pnt<3>>(0.0, 0.0, 5.0));
			//myBSPPts.push_back(std::make_shared<ForgBaseLib::FrgBase_Pnt<3>>(50.0, 0.0, 5.0));
			//myBSPPts.push_back(std::make_shared<ForgBaseLib::FrgBase_Pnt<3>>(50.0, 0.0, 10.0));
			//myBSPPts.push_back(std::make_shared<ForgBaseLib::FrgBase_Pnt<3>>(100.0, 0.0, 10.0));
			//myScene->AddBSPLine(myBSPPts, 2, false);

			//double t0 = 0.0;
			//double tn = PI;
			//int nt = 20;
			//double dt = (tn - t0) / (nt);

			//double phi0 = 0.0;
			//double phin = 2.0*PI;
			//int nphi = 20;
			//double dphi = (phin - phi0) / (nphi);

			//double a = 20.0;
			//double b = 20.0;
			//double c = 20.0;

			//for (int i = 0; i <= nt; i++)
			//{
			//	std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d>> myPts;

			//	double theta = i * dt + t0;
			//	for (int j = 0; j <= nphi; j++)
			//	{
			//		double phi = j * dphi + phi0;

			//		auto pt = std::make_shared<ForgBaseLib::FrgBase_Pnt3d>(a*sin(theta)*cos(phi), b*sin(theta)*sin(phi), c*cos(theta));
			//		myPts.push_back(pt);
			//		auto ptActor = myScene->AddPoint(pt, false);
			//		ptActor->SetColor(sin(i), sin(j), sin(i + j));
			//	}
			//	//myScene->AddPolyline(myPts);
			//}

			
		}
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

	thePropertiesPanel_->AddRow(theFastDiscrete_Angle_);
	thePropertiesPanel_->AddRow(theFastDiscrete_Deflection_);
	thePropertiesPanel_->AddRow(theFastDiscrete_MinSize_);
	thePropertiesPanel_->AddRow(theFastDiscrete_InParallel_);
	thePropertiesPanel_->AddRow(theFastDiscrete_Relative_);
	thePropertiesPanel_->AddRow(theFastDiscrete_AdaptiveMin_);
	thePropertiesPanel_->AddRow(theFastDiscrete_InternalVerticesMode_);
	thePropertiesPanel_->AddRow(theFastDiscrete_ControlSurfaceDeflection_);
	//FormPropertiesPanel();
	//thePropertiesPanel_ = new ForgBaseLib::FrgBase_PropertiesPanel(GetParentMainWindow(), this);
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

DECLARE_SAVE_IMP(ForgMarineLib::FrgMarine_GeomPModelPView_TItem)
{
	ar& boost::serialization::base_object<FrgMarine_Scene3D_TItem>(*this);

	ar& theFastDiscrete_Angle_;
	ar& theFastDiscrete_Deflection_;
	ar& theFastDiscrete_MinSize_;
	ar& theFastDiscrete_InParallel_;
	ar& theFastDiscrete_Relative_;
	ar& theFastDiscrete_AdaptiveMin_;
	ar& theFastDiscrete_InternalVerticesMode_;
	ar& theFastDiscrete_ControlSurfaceDeflection_;
}

DECLARE_LOAD_IMP(ForgMarineLib::FrgMarine_GeomPModelPView_TItem)
{
	ar& boost::serialization::base_object<FrgMarine_Scene3D_TItem>(*this);

	ar& theFastDiscrete_Angle_;
	ar& theFastDiscrete_Deflection_;
	ar& theFastDiscrete_MinSize_;
	ar& theFastDiscrete_InParallel_;
	ar& theFastDiscrete_Relative_;
	ar& theFastDiscrete_AdaptiveMin_;
	ar& theFastDiscrete_InternalVerticesMode_;
	ar& theFastDiscrete_ControlSurfaceDeflection_;

	thePropertiesPanel_->AddRow(theFastDiscrete_Angle_);
	thePropertiesPanel_->AddRow(theFastDiscrete_Deflection_);
	thePropertiesPanel_->AddRow(theFastDiscrete_MinSize_);
	thePropertiesPanel_->AddRow(theFastDiscrete_InParallel_);
	thePropertiesPanel_->AddRow(theFastDiscrete_Relative_);
	thePropertiesPanel_->AddRow(theFastDiscrete_AdaptiveMin_);
	thePropertiesPanel_->AddRow(theFastDiscrete_InternalVerticesMode_);
	thePropertiesPanel_->AddRow(theFastDiscrete_ControlSurfaceDeflection_);

	ConnectVrntsToSlots();
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPModelPView_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_GeomPModelPView_TItem);
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPModelPView_TItem)
{
	QString myTItemTitle;
	ar& myTItemTitle;

	QString parentTItemIsNull;
	ForgBaseLib::FrgBase_TreeItem* parentTItem;

	ar& parentTItemIsNull;

	if (parentTItemIsNull == "PARENT_TITEM_IS_NULL")
		parentTItem = nullptr;
	else if (parentTItemIsNull == "PARENT_TITEM_IS_NOT_NULL")
		ar& parentTItem;

	QString parentTreeIsNull;
	ForgBaseLib::FrgBase_Tree* parentTree;

	ar& parentTreeIsNull;

	if (parentTreeIsNull == "PARENT_TREE_IS_NULL")
		parentTree = nullptr;
	else if (parentTreeIsNull == "PARENT_TREE_IS_NOT_NULL")
		ar& parentTree;

	::new(t)ForgMarineLib::FrgMarine_GeomPModelPView_TItem(myTItemTitle, parentTItem, parentTree, nullptr);
}

BOOST_CLASS_EXPORT_CXX(ForgMarineLib::FrgMarine_GeomPModelPView_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPModelPView_TItem)

//void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::TItemNameToTabTitleChangedSlot(const QString & title)
//{
//	auto myMainWindow = dynamic_cast<FrgMarine_MainWindow*>(GetParentMainWindow());
//	if (myMainWindow)
//		myMainWindow->SetTabText(theScene_, title + " " + this->text(0));
//}
//
//void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::ShowTabWidget()
//{
//	auto myMainWindow = dynamic_cast<FrgMarine_MainWindow*>(GetParentMainWindow());
//	if (myMainWindow)
//		myMainWindow->ShowTabWidget(theScene_, dynamic_cast<QTreeWidgetItem*>(this)->parent()->text(0) + " " + this->text(0));
//}
//
//void ForgMarineLib::FrgMarine_GeomPModelPView_TItem::TItemDoubleClickedSlot()
//{
//	ShowTabWidget();
//}