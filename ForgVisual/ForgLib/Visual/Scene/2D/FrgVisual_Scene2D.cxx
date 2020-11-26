#include <FrgVisual_Scene2D.hxx>
#include <FrgBase_MainWindow.hxx>

#include <FrgVisual_Scene_InterStyle2D.hxx>
#include <FrgVisual_BaseActor.hxx>
#include <FrgVisual_GridActor.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgBase_TabWidget.hxx>

#include <QVTKOpenGLNativeWidget.h>
#include <vtkRenderer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkCamera.h>
#include <vtkCubeSource.h>

ForgVisualLib::FrgVisual_Scene2D::FrgVisual_Scene2D
(ForgBaseLib::FrgBase_MainWindow* parentMainWindow)
	: FrgVisual_Scene(parentMainWindow)
{
	theMajorGridColor_.setRgb(154, 162, 169);
	theMinorGridColor_.setRgb(119, 175, 230);
}

//void ForgVisualLib::FrgVisual_Scene2D::Init()
//{
//	theRenderer_ = vtkSmartPointer<vtkRenderer>::New();
//	theRenderer_->SetBackground(1.0, 1.0, 1.0);
//	theRenderer_->SetBackground2(0.7, 0.7, 0.7);
//	theRenderer_->SetGradientBackground(true);
//
//	theRenderWindow_ = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
//
//	theRenderWindow_->AddRenderer(theRenderer_);
//
//	theRenderWindowInteractor_ = vtkSmartPointer<vtkRenderWindowInteractor>::New();
//	theRenderWindowInteractor_->SetRenderWindow(theRenderWindow_);
//
//	theInteractorStyle_ = FrgVisual_Scene_InterStyle2D::New();
//
//	auto castedInteractorStyle = FrgVisual_Scene_InterStyle2D::SafeDownCast((FrgVisual_Scene_InterStyle2D::SuperClass*)(theInteractorStyle_));
//	castedInteractorStyle->SetParentScene(this);
//	//FrgVisual_Scene_InterStyle3D::SafeDownCast(theInteractorStyle_)->AddManipulator(FrgVisual_Scene_CameraManip::New());
//
//	//theInteractorStyle_->SetParent(this);
//
//	castedInteractorStyle->SetMouseWheelMotionFactor(0.5);
//
//	theRenderWindowInteractor_->SetInteractorStyle(castedInteractorStyle);
//
//	vtkAxesActor* axes = vtkAxesActor::New();
//
//	axes->PickableOff();
//	axes->SetShaftTypeToLine();
//	axes->SetZAxisLabelText("");
//	axes->GetZAxisShaftProperty()->SetAmbient(0.0);
//	axes->GetZAxisTipProperty()->SetAmbient(0.0);
//
//	vtkOrientationMarkerWidget* widget = vtkOrientationMarkerWidget::New();
//
//	widget->SetOutlineColor(0.9300, 0.5700, 0.1300);
//	widget->SetOrientationMarker(axes);
//	widget->SetInteractor(theRenderWindowInteractor_);
//	widget->SetViewport(0.0, 0.0, 0.4, 0.4);
//	widget->SetEnabled(1);
//	widget->InteractiveOff();
//
//	// Create a TextActor
//	theLogoActor_ = vtkSmartPointer<vtkTextActor>::New();
//	theLogoActor_->SetInput("Forg Soft");
//	vtkTextProperty* tprop = theLogoActor_->GetTextProperty();
//	tprop->SetFontFamilyToArial();
//	tprop->ShadowOff();
//
//	tprop->SetLineSpacing(1.0);
//	tprop->SetFontSize(24);
//	//tprop->SetFontFamilyToArial();
//	tprop->BoldOn();
//	tprop->SetFontFile(":/Fonts/swissek.ttf");
//	tprop->ShadowOn();
//	tprop->SetColor(0.91, 0.91, 0.91); // (Black) Color
//
//	theLogoActor_->SetDisplayPosition(20, 20);
//	theRenderer_->AddActor2D(theLogoActor_);
//	//theRenderer_->AddActor(axes);
//
//	theCamera_ = vtkSmartPointer<vtkCamera>::New();
//	theRenderer_->LightFollowCameraOn();
//	theRenderer_->TwoSidedLightingOn();
//
//	connect(theContextMenuInScene_->GetItem("Hide"), SIGNAL(triggered()), theInteractorStyle_, SLOT(HideActionIsCalledSlot()));
//	connect(theContextMenuInScene_->GetItem("UnHide"), SIGNAL(triggered()), theInteractorStyle_, SLOT(UnHideActionIsCalledSlot()));
//
//	RenderScene(true);
//}

void ForgVisualLib::FrgVisual_Scene2D::RenderSceneSlot(bool resetCamera, bool resetView)
{
	if (!theInitiated_)
	{
		theCamera_->SetPosition(0, 0, 1);
		theCamera_->SetFocalPoint(0, 0, 0);
		theCamera_->SetViewUp(0, 1, 0);
		theCamera_->SetParallelProjection(true);
	}

	if (theParentMainWindow_->GetTabWidget()->currentWidget() != this)
		return;
	
	if (resetCamera)
	{
		if(resetView)
		{
			theCamera_->SetPosition(0, 0, 1);
			theCamera_->SetFocalPoint(0, 0, 0);
			theCamera_->SetViewUp(0, 1, 0);
			theCamera_->SetParallelProjection(true);
		}

		theRenderer_->SetActiveCamera(theCamera_);

		auto my2DStyle = FrgVisual_Scene_InterStyle2D::SafeDownCast((FrgVisual_Scene_InterStyle2D::SuperClass*)(theInteractorStyle_));

		auto myActors = my2DStyle->GetAllActors();
		std::vector<FrgVisual_GridActor*> myGrids;
		for (auto myActor : myActors)
		{
			auto myGrid = dynamic_cast<FrgVisual_GridActor*>(myActor);
			if (myGrid)
			{
				myGrids.push_back(myGrid);
				myGrid->VisibilityOff();
			}
		}

		theRenderer_->ResetCamera();

		double myBounds[6];
		theRenderer_->ComputeVisiblePropBounds(myBounds);

		double centerOfRotation[3];
		centerOfRotation[0] = (myBounds[1] - myBounds[0]) / 2.0;
		centerOfRotation[1] = (myBounds[3] - myBounds[2]) / 2.0;
		centerOfRotation[2] = (myBounds[5] - myBounds[4]) / 2.0;
		my2DStyle->SetCenterOfRotation(centerOfRotation);

		for (auto myGrid : myGrids)
		{
			myGrid->VisibilityOn();
		}

		//theCamera_->Elevation(15);
		theCamera_->OrthogonalizeViewUp();

		theRenderer_->ResetCameraClippingRange();

		theOpenGLWidget_->SetRenderWindow(theRenderWindow_);

		theRenderWindow_->Render();
		theRenderWindowInteractor_->Initialize();
	}
	else
		theRenderWindow_->Render();
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Scene2D)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_Scene<2>>(*this);
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Scene2D)
{
	Init();

	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_Scene<2>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Scene2D)