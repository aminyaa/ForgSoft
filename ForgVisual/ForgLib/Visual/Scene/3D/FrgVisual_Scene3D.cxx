#include <FrgVisual_Scene3D.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgVisual_Scene_InterStyle3D.hxx>
#include <FrgVisual_GridActor.hxx>
#include <FrgVisual_Global_Icons.hxx>

#include <FrgBase_SerialSpec_QString.hxx>
#include <FrgBase_SerialSpec_QColor.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgBase_TabWidget.hxx>
#include <FrgBase_StylesMenuItemStyle.hxx>
#include <FrgBase_Global_Thread.hxx>

#include <vtkCameraInterpolator.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkCamera.h>
#include <vtkAssemblyPath.h>
#include <vtkDataSetMapper.h>
#include <vtkCellData.h>

#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>

#define IS_FRGVISUAL_ACTOR "IS_FRGVISUAL_ACTOR"
#define IS_NOT_FRGVISUAL_ACTOR "IS_NOT_FRGVISUAL_ACTOR"

ForgVisualLib::FrgVisual_Scene3D::FrgVisual_Scene3D
(ForgBaseLib::FrgBase_MainWindow* parentMainWindow)
	: ForgVisualLib::FrgVisual_Scene<3>(parentMainWindow)
{
	theMajorGridColor_.setRgb(154, 162, 169);
	theMinorGridColor_.setRgb(119, 175, 230);

	connect(this, SIGNAL(RenderSceneSignal(double)), this, SLOT(RenderSceneSlot(double)));
}

//void ForgVisualLib::FrgVisual_Scene3D::Init()
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
//	theInteractorStyle_ = FrgVisual_Scene_InterStyle3D::New();
//
//	auto castedInteractorStyle = FrgVisual_Scene_InterStyle3D::SafeDownCast((FrgVisual_Scene_InterStyle3D::SuperClass*)(theInteractorStyle_));
//	castedInteractorStyle->SetParentScene(this);
//	castedInteractorStyle->SetCurrentRenderer(theRenderer_);
//	//FrgVisual_Scene_InterStyle3D::SafeDownCast(theInteractorStyle_)->AddManipulator(FrgVisual_Scene_CameraManip::New());
//
//	//theInteractorStyle_->SetParent(this);
//
//	castedInteractorStyle->SetMouseWheelMotionFactor(0.5);
//
//	theRenderWindowInteractor_->SetInteractorStyle(castedInteractorStyle);
//
//	theAxesActor_ = vtkAxesActor::New();
//
//	theAxesActor_->PickableOff();
//	theAxesActor_->SetShaftTypeToLine();
//	theAxesActor_->SetOrigin(0.0, 0.0, 0.0);
//	theAxesActor_->SetScale(10.0);
//
//	vtkOrientationMarkerWidget* widget = vtkOrientationMarkerWidget::New();
//
//	widget->SetOutlineColor(0.9300, 0.5700, 0.1300);
//	widget->SetOrientationMarker(theAxesActor_);
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
//	theRenderWindowInteractor_->Initialize();
//	theRenderer_->SetActiveCamera(theCamera_);
//
//	this->SetRenderWindow(theRenderWindow_);
//
//	RenderScene(true);
//}

void ForgVisualLib::FrgVisual_Scene3D::RenderSceneSlot(bool resetCamera, bool resetView)
{
	if(!theInitiated_)
	{
		theCamera_->SetPosition(0, -1, 0);
		theCamera_->SetFocalPoint(0, 0, 0);
		theCamera_->SetViewUp(0, 0, 1);
		theCamera_->Azimuth(45);
		theCamera_->Elevation(25);
	}
	
	/*if (theParentMainWindow_->GetTabWidget()->currentWidget() != this)
		return;*/

	if (resetCamera)
	{
		if (resetView)
		{
			theCamera_->SetPosition(0, -1, 0);
			theCamera_->SetFocalPoint(0, 0, 0);
			theCamera_->SetViewUp(0, 0, 1);
			theCamera_->Azimuth(45);
			theCamera_->Elevation(25);
		}

		auto my3DStyle = FrgVisual_Scene_InterStyle3D::SafeDownCast((FrgVisual_Scene_InterStyle3D::SuperClass*)(theInteractorStyle_));

		auto myActors = my3DStyle->GetAllActors();
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
		my3DStyle->SetCenterOfRotation(centerOfRotation);

		for (auto myGrid : myGrids)
		{
			myGrid->VisibilityOn();
		}

		//theCamera_->Elevation(15);
		theCamera_->Dolly(1.5);
		theCamera_->OrthogonalizeViewUp();

		theRenderer_->ResetCameraClippingRange();

		theRenderWindow_->Render();
	}
	else
		theRenderWindow_->Render();
}

#define AddViewsToMenu(viewsMenu, MenuTitle, proxyStyle, I1, I1Title, I2, I2Title, I3, I3Title, I4, I4Title) \
	{\
	ForgBaseLib::FrgBase_Menu* Menu = new ForgBaseLib::FrgBase_Menu(MenuTitle, theParentMainWindow_); \
	Menu->setStyle(proxyStyle); \
	auto I1Action = Menu->AddItem(QIcon(I1), I1Title, false); \
	auto I2Action = Menu->AddItem(QIcon(I2), I2Title, false); \
	auto I3Action = Menu->AddItem(QIcon(I3), I3Title, false); \
	auto I4Action = Menu->AddItem(QIcon(I4), I4Title, false); \
	connect(I1Action, SIGNAL(triggered(bool)), this, SLOT(SetViewToSlot(bool))); \
	connect(I2Action, SIGNAL(triggered(bool)), this, SLOT(SetViewToSlot(bool))); \
	connect(I3Action, SIGNAL(triggered(bool)), this, SLOT(SetViewToSlot(bool))); \
	connect(I4Action, SIGNAL(triggered(bool)), this, SLOT(SetViewToSlot(bool))); \
	(viewsMenu)->addMenu(Menu); \
	}



void ForgVisualLib::FrgVisual_Scene3D::FormToolBar()
{
	FrgVisual_Scene<3>::FormToolBar();

	if (theToolBar_)
	{
		auto* cameraViews = new QToolButton();
		cameraViews->setIcon(QIcon(":/ForgVisual/Resources/Scene/Camera.png"));
		cameraViews->setPopupMode(QToolButton::ToolButtonPopupMode::InstantPopup);
		cameraViews->setToolTip("Camera Views");

		auto* cameraViewsMenu = new ForgBaseLib::FrgBase_Menu("Camera Views", theParentMainWindow_);
		auto* projectionModeMenu = new ForgBaseLib::FrgBase_Menu("Projection Mode", theParentMainWindow_);
		auto* perspectiveAction = projectionModeMenu->AddItem("Perspective", false);
		auto* parallelAction = projectionModeMenu->AddItem("Parallel", false);
		auto* projectionModeGroup = new QActionGroup(theParentMainWindow_);
		projectionModeGroup->addAction(perspectiveAction);
		projectionModeGroup->addAction(parallelAction);
		projectionModeGroup->setExclusive(true);
		perspectiveAction->setCheckable(true);
		parallelAction->setCheckable(true);
		perspectiveAction->setChecked(true);

		connect(projectionModeGroup, SIGNAL(triggered(QAction*)), this, SLOT(SetProjectionModeSlot(QAction*)));

		auto* viewsMenu = new ForgBaseLib::FrgBase_Menu("Views", theParentMainWindow_);
		auto* myProxyStyle = new ForgBaseLib::FrgBase_StylesMenuItemStyle(viewsMenu->style());
		myProxyStyle->SetIconSize(35);

		AddViewsToMenu
		(
			viewsMenu,
			"+X",
			myProxyStyle,
			ICON_FRGVISUAL_SCENE_VIEW_PLUSX_UPPLUSZ,
			"Up +Z",
			ICON_FRGVISUAL_SCENE_VIEW_PLUSX_UPMINUSZ,
			"Up -Z",
			ICON_FRGVISUAL_SCENE_VIEW_PLUSX_UPPLUSY,
			"Up +Y",
			ICON_FRGVISUAL_SCENE_VIEW_PLUSX_UPMINUSY,
			"Up -Y"
		);

		AddViewsToMenu
		(
			viewsMenu,
			"-X",
			myProxyStyle,
			ICON_FRGVISUAL_SCENE_VIEW_MINUSX_UPPLUSZ,
			"Up +Z",
			ICON_FRGVISUAL_SCENE_VIEW_MINUSX_UPMINUSZ,
			"Up -Z",
			ICON_FRGVISUAL_SCENE_VIEW_MINUSX_UPPLUSY,
			"Up +Y",
			ICON_FRGVISUAL_SCENE_VIEW_MINUSX_UPMINUSY,
			"Up -Y"
		);

		AddViewsToMenu
		(
			viewsMenu,
			"+Y",
			myProxyStyle,
			ICON_FRGVISUAL_SCENE_VIEW_PLUSY_UPPLUSZ,
			"Up +Z",
			ICON_FRGVISUAL_SCENE_VIEW_PLUSY_UPMINUSZ,
			"Up -Z",
			ICON_FRGVISUAL_SCENE_VIEW_PLUSY_UPPLUSX,
			"Up +X",
			ICON_FRGVISUAL_SCENE_VIEW_PLUSY_UPMINUSX,
			"Up -X"
		);

		AddViewsToMenu
		(
			viewsMenu,
			"-Y",
			myProxyStyle,
			ICON_FRGVISUAL_SCENE_VIEW_MINUSY_UPPLUSZ,
			"Up +Z",
			ICON_FRGVISUAL_SCENE_VIEW_MINUSY_UPMINUSZ,
			"Up -Z",
			ICON_FRGVISUAL_SCENE_VIEW_MINUSY_UPPLUSX,
			"Up +X",
			ICON_FRGVISUAL_SCENE_VIEW_MINUSY_UPMINUSX,
			"Up -X"
		);

		AddViewsToMenu
		(
			viewsMenu,
			"+Z",
			myProxyStyle,
			ICON_FRGVISUAL_SCENE_VIEW_PLUSZ_UPPLUSY,
			"Up +Y",
			ICON_FRGVISUAL_SCENE_VIEW_PLUSZ_UPMINUSY,
			"Up -Y",
			ICON_FRGVISUAL_SCENE_VIEW_PLUSZ_UPPLUSX,
			"Up +X",
			ICON_FRGVISUAL_SCENE_VIEW_PLUSZ_UPMINUSX,
			"Up -X"
		);

		AddViewsToMenu
		(
			viewsMenu,
			"-Z",
			myProxyStyle,
			ICON_FRGVISUAL_SCENE_VIEW_MINUSZ_UPPLUSY,
			"Up +Y",
			ICON_FRGVISUAL_SCENE_VIEW_MINUSZ_UPMINUSY,
			"Up -Y",
			ICON_FRGVISUAL_SCENE_VIEW_MINUSZ_UPPLUSX,
			"Up +X",
			ICON_FRGVISUAL_SCENE_VIEW_MINUSZ_UPMINUSX,
			"Up -X"
		);

		auto* standardViewsMenu = new ForgBaseLib::FrgBase_Menu("Standard Views", theParentMainWindow_);
		standardViewsMenu->setStyle(myProxyStyle);
		auto* rightViewAction = standardViewsMenu->AddItem(QIcon(ICON_FRGVISUAL_SCENE_VIEW_PLUSY_UPPLUSZ), "(+Y) right", false);
		auto* leftViewAction = standardViewsMenu->AddItem(QIcon(ICON_FRGVISUAL_SCENE_VIEW_MINUSY_UPPLUSZ), "(-Y) left", false);
		standardViewsMenu->addSeparator();
		auto* topViewAction = standardViewsMenu->AddItem(QIcon(ICON_FRGVISUAL_SCENE_VIEW_PLUSZ_UPPLUSY), "(+Z) top", false);
		auto* bottomViewAction = standardViewsMenu->AddItem(QIcon(ICON_FRGVISUAL_SCENE_VIEW_MINUSZ_UPPLUSY), "(-Z) bottom", false);
		standardViewsMenu->addSeparator();
		auto* frontViewAction = standardViewsMenu->AddItem(QIcon(ICON_FRGVISUAL_SCENE_VIEW_MINUSX_UPPLUSZ), "(-X) front", false);
		auto* backViewAction = standardViewsMenu->AddItem(QIcon(ICON_FRGVISUAL_SCENE_VIEW_PLUSX_UPPLUSZ), "(+X) back", false);

		connect(rightViewAction, SIGNAL(triggered(bool)), this, SLOT(SetViewToSlot(bool)));
		connect(leftViewAction, SIGNAL(triggered(bool)), this, SLOT(SetViewToSlot(bool)));
		connect(topViewAction, SIGNAL(triggered(bool)), this, SLOT(SetViewToSlot(bool)));
		connect(bottomViewAction, SIGNAL(triggered(bool)), this, SLOT(SetViewToSlot(bool)));
		connect(frontViewAction, SIGNAL(triggered(bool)), this, SLOT(SetViewToSlot(bool)));
		connect(backViewAction, SIGNAL(triggered(bool)), this, SLOT(SetViewToSlot(bool)));

		cameraViewsMenu->addMenu(projectionModeMenu);
		cameraViewsMenu->addSeparator();
		cameraViewsMenu->addMenu(viewsMenu);
		cameraViewsMenu->addSeparator();
		cameraViewsMenu->addMenu(standardViewsMenu);

		cameraViews->setMenu(cameraViewsMenu);

		theToolBar_->addWidget(cameraViews);
	}
}

void ForgVisualLib::FrgVisual_Scene3D::InitInteractorStyle()
{
	theInteractorStyle_ = FrgVisual_Scene_InterStyle3D::New();

	auto castedInteractorStyle = FrgVisual_Scene_InterStyle3D::SafeDownCast((FrgVisual_Scene_InterStyle3D::SuperClass*)(theInteractorStyle_));
	castedInteractorStyle->SetParentScene(this);
	castedInteractorStyle->SetCurrentRenderer(theRenderer_);
	castedInteractorStyle->SetMouseWheelMotionFactor(0.5);
	theRenderWindowInteractor_->SetInteractorStyle(castedInteractorStyle);
}

void ForgVisualLib::FrgVisual_Scene3D::SetCameraView(const QString& firstDir, const QString& secondDir)
{
	if(firstDir == "Standard Views")
	{
		if (secondDir == "(+Y) right")
			SetCameraView("+Y", "Up +Z");
		else if (secondDir == "(-Y) left")
			SetCameraView("-Y", "Up +Z");
		else if (secondDir == "(+Z) top")
			SetCameraView("+Z", "Up +Y");
		else if (secondDir == "(-Z) bottom")
			SetCameraView("-Z", "Up +Y");
		else if (secondDir == "(-X) front")
			SetCameraView("-X", "Up +Z");
		else if (secondDir == "(+X) back")
			SetCameraView("+X", "Up +Z");

		return;
	}
	
	double fPoint[3];
	double fOldPoint[3];
	theCamera_->GetFocalPoint(fPoint);
	theCamera_->GetFocalPoint(fOldPoint);

	vtkCamera* cam1 = vtkCamera::New();
	cam1->DeepCopy(theCamera_);

	if(firstDir == "+X")
		fPoint[0] += theCamera_->GetDistance();
	else if(firstDir == "-X")
		fPoint[0] -= theCamera_->GetDistance();
	else if (firstDir == "+Y")
		fPoint[1] += theCamera_->GetDistance();
	else if (firstDir == "-Y")
		fPoint[1] -= theCamera_->GetDistance();
	else if (firstDir == "+Z")
		fPoint[2] += theCamera_->GetDistance();
	else if (firstDir == "-Z")
		fPoint[2] -= theCamera_->GetDistance();
	
	theCamera_->SetPosition(fPoint);
	theCamera_->SetFocalPoint(fOldPoint);
	theCamera_->OrthogonalizeViewUp();

	if (secondDir == "Up +Z")
		theCamera_->SetViewUp(0.0, 0.0, 1.0);
	if (secondDir == "Up -Z")
		theCamera_->SetViewUp(0.0, 0.0, -1.0);
	if (secondDir == "Up +Y")
		theCamera_->SetViewUp(0.0, 1.0, 0.0);
	if (secondDir == "Up -Y")
		theCamera_->SetViewUp(0.0, -1.0, 0.0);
	if (secondDir == "Up +X")
		theCamera_->SetViewUp(1.0, 0.0, 0.0);
	if (secondDir == "Up -X")
		theCamera_->SetViewUp(-1.0, 0.0, 0.0);

	MoveCameraFromTo(cam1, theCamera_, 0.5, 60);

	cam1->Delete();
}

void ForgVisualLib::FrgVisual_Scene3D::MoveCameraFromTo(vtkCamera* from, vtkCamera* to, double time, int fps)
{
	theCameraInterpolator_->Initialize();
	theCameraInterpolator_->SetInterpolationTypeToSpline();
	theCameraInterpolator_->AddCamera(0.0, from);
	theCameraInterpolator_->AddCamera(time, to);

	QMutex* mutex = new QMutex();
	ExecuteFunctionInProcess
	(
		nullptr,
		{
			const int nt = time * fps;
	const double dt = time / static_cast<double>(nt);
			for (int i = 0; i <= nt; i++)
			{
				const double t = i * dt;
				emit RenderSceneSignal(t);
				QThread::msleep(1000.0 / static_cast<double>(fps));
			}
		},
		mutex,
			[]() {}
		);

	delete mutex;
}

std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity*> ForgVisualLib::FrgVisual_Scene3D::GetSelectedActors() const
{
	const auto& my3DStyle = FrgVisual_Scene_InterStyle3D::SafeDownCast((FrgVisual_Scene_InterStyle3D::SuperClass*)(theInteractorStyle_));
	if (my3DStyle)
		return my3DStyle->GetSelectedActors();

	return std::vector<FrgVisual_BaseActor_Entity*>();
}

std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity*> ForgVisualLib::FrgVisual_Scene3D::GetHiddenActors() const
{
	const auto& my3DStyle = FrgVisual_Scene_InterStyle3D::SafeDownCast((FrgVisual_Scene_InterStyle3D::SuperClass*)(theInteractorStyle_));
	if (my3DStyle)
		return my3DStyle->GetHiddenActors();

	return std::vector<FrgVisual_BaseActor_Entity*>();
}

void ForgVisualLib::FrgVisual_Scene3D::SelectActor(FrgVisual_BaseActor_Entity* actor, int isControlKeyPressed, bool render)
{
	const auto& my3DStyle = FrgVisual_Scene_InterStyle3D::SafeDownCast((FrgVisual_Scene_InterStyle3D::SuperClass*)(theInteractorStyle_));
	if (my3DStyle)
		my3DStyle->SelectActor(actor, isControlKeyPressed, render);
}

void ForgVisualLib::FrgVisual_Scene3D::SelectActor(std::vector<FrgVisual_BaseActor_Entity*> actors, int isControlKeyPressed, bool render)
{
	if (!isControlKeyPressed)
		UnSelectAllActors();

	const auto& my3DStyle = FrgVisual_Scene_InterStyle3D::SafeDownCast((FrgVisual_Scene_InterStyle3D::SuperClass*)(theInteractorStyle_));
	if (my3DStyle)
	{
		for (const auto& actor : actors)
		{
			my3DStyle->SelectActor(actor, true, render);
		}
	}
}

void ForgVisualLib::FrgVisual_Scene3D::UnSelectActor(FrgVisual_BaseActor_Entity* actor, bool render)
{
	const auto& my3DStyle = FrgVisual_Scene_InterStyle3D::SafeDownCast((FrgVisual_Scene_InterStyle3D::SuperClass*)(theInteractorStyle_));
	if (my3DStyle)
		my3DStyle->UnSelectActor(actor, render);
}

void ForgVisualLib::FrgVisual_Scene3D::SelectAllActors(bool render)
{
	const auto& my3DStyle = FrgVisual_Scene_InterStyle3D::SafeDownCast((FrgVisual_Scene_InterStyle3D::SuperClass*)(theInteractorStyle_));
	if (my3DStyle)
		my3DStyle->SelectAllActors(render);
}

void ForgVisualLib::FrgVisual_Scene3D::UnSelectAllActors(bool render)
{
	const auto& my3DStyle = FrgVisual_Scene_InterStyle3D::SafeDownCast((FrgVisual_Scene_InterStyle3D::SuperClass*)(theInteractorStyle_));
	if (my3DStyle)
		my3DStyle->UnSelectAllActors(render);
}

void ForgVisualLib::FrgVisual_Scene3D::SetProjectionModeSlot(QAction* action)
{
	if (!action || !theCamera_)
		return;

	if (action->isChecked())
	{
		if (action->text() == "Perspective")
		{
			theCamera_->ParallelProjectionOff();
		}
		else if (action->text() == "Parallel")
		{
			theCamera_->ParallelProjectionOn();
		}

		RenderScene(false);
	}
}

void ForgVisualLib::FrgVisual_Scene3D::SetViewToSlot(bool)
{
	if (!theCamera_)
		return;

	const auto& myAction = dynamic_cast<QAction*>(sender());
	if (myAction)
	{
		const auto& myMenu = dynamic_cast<QMenu*>(myAction->parentWidget());
		if (myMenu)
		{
			SetCameraView(myMenu->title(), myAction->text());
			
			//theParentMainWindow_->PrintInfoToConsole("From \"" + myMenu->title() + "\" the \"" + myAction->text() + "\" was clicked.");
			RenderScene(false);
		}
	}
}

void ForgVisualLib::FrgVisual_Scene3D::RenderSceneSlot(double t)
{
	theCameraInterpolator_->InterpolateCamera(t, theCamera_);
	theCamera_->OrthogonalizeViewUp();
	theRenderer_->ResetCameraClippingRange();
	RenderScene(false);
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Scene3D)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_Scene<3>>(*this);

	double mouseWheelMotionFactor = FrgVisual_Scene_InterStyle3D::SafeDownCast((FrgVisual_Scene_InterStyle3D::SuperClass*)(theInteractorStyle_))->GetMouseWheelMotionFactor();
	ar& mouseWheelMotionFactor;

	vtkActorCollection* ac;
	vtkActor* anActor;
	FrgVisual_BaseActor_Entity* aPart;

	int numberOfItems = theRenderer_->GetActors()->GetNumberOfItems();
	ar& numberOfItems;

	ac = theRenderer_->GetActors();
	vtkCollectionSimpleIterator ait;
	for (ac->InitTraversal(ait); (anActor = ac->GetNextActor(ait)); )
	{
		aPart = dynamic_cast<FrgVisual_BaseActor_Entity*>(anActor);
		QString isFrgVisualActor;

		if (aPart)
		{
			isFrgVisualActor = IS_FRGVISUAL_ACTOR;

			ar& isFrgVisualActor;
			ar& aPart;
		}
		else
		{
			isFrgVisualActor = IS_NOT_FRGVISUAL_ACTOR;

			ar& isFrgVisualActor;
		}
	}

	ar& theMajorGridColor_;
	ar& theMinorGridColor_;
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Scene3D)
{
	Init();

	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_Scene<3>>(*this);

	double mouseWheelMotionFactor;
	ar& mouseWheelMotionFactor;

	int numberOfItems;
	ar& numberOfItems;

	for (int i = 0; i < numberOfItems; i++)
	{
		QString isFrgVisualActor;

		ar& isFrgVisualActor;

		if (isFrgVisualActor == IS_FRGVISUAL_ACTOR)
		{
			FrgVisual_BaseActor_Entity* aPart;
			ar& aPart;

			//theRenderer_->AddActor(aPart);

			/*auto myGrid = dynamic_cast<FrgVisual_2DGridActor*>(aPart);
			if (myGrid)
			{
				if (myGrid->GetXLine())
					theMajorGridActor_ = myGrid;
				else
					theMinorGridActor_ = myGrid;
			}*/
		}
		else if (isFrgVisualActor == IS_NOT_FRGVISUAL_ACTOR)
		{

		}
	}

	ar& theMajorGridColor_;
	ar& theMinorGridColor_;

	this->RenderScene(false);
}

//DECLARE_SAVE_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Scene3D)
//{
//
//}
//
//DECLARE_LOAD_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Scene3D)
//{
//
//}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Scene3D)

//#include <FrgVisual_Scene3D.hxx>
//#include <FrgVisual_Scene_InterStyle3D.hxx>
//#include <FrgBase_Menu.hxx>
//#include <FrgBase_Tree.hxx>
//#include <FrgBase_Global_Icons.hxx>
//#include <FrgBase_MainWindow.hxx>
//
//#include <QtWidgets/QFileDialog>
//#include <QtWidgets/QMainWindow>
//
//#include <vtkActor.h>
//#include <vtkProperty.h>
//#include <vtkRenderer.h>
//#include <vtkGenericOpenGLRenderWindow.h>
//#include <vtkAxesActor.h>
//#include <vtkOrientationMarkerWidget.h>
//#include <vtkTextActor.h>
//#include <vtkTextProperty.h>
//#include <vtkCamera.h>
//#include <vtkDoubleArray.h>
//#include <vtkRectilinearGrid.h>
//#include <vtkDataSetMapper.h>
//#include<vtkPoints.h>
//#include <vtkPolyData.h>
//#include <vtkLine.h>
//#include <vtkCellData.h>
//#include <vtkPolyDataMapper.h>
//#include <vtkWindowToImageFilter.h>
//#include <vtkImageWriter.h>
//#include <vtkJPEGWriter.h>
//#include <vtkPNGWriter.h>
//#include <vtkBMPWriter.h>
//#include <vtkPNMWriter.h>
//#include <vtkPostScriptWriter.h>
//
//#include <vtkAutoInit.h>
//
//VTK_MODULE_INIT(vtkRenderingContextOpenGL2)
//VTK_MODULE_INIT(vtkRenderingOpenGL2)
//VTK_MODULE_INIT(vtkInteractionStyle)
//VTK_MODULE_INIT(vtkRenderingFreeType)
//
//ForgVisualLib::FrgVisual_Scene3D::FrgVisual_Scene3D(FrgBase_MainWindow * parentMainWindow)
//	: QVTKOpenGLNativeWidget(parentMainWindow)
//{
//
//}
//
//ForgVisualLib::FrgVisual_Scene3D::GridActor::GridActor(int nbMajorDivision, int nbMinorDivision, double MajorColor[3], double MinorColor[3])
//{
//	theNbMajorDivision_ = nbMajorDivision;
//	theNbMinorDivision_ = nbMinorDivision;
//
//	theMajorActor_ = vtkSmartPointer<vtkActor>::New();
//	theMinorActor_ = vtkSmartPointer<vtkActor>::New();
//	theMiddleLines_ = vtkSmartPointer<vtkActor>::New();
//
//	theMajorActor_->GetProperty()->SetColor(MajorColor);
//	theMinorActor_->GetProperty()->SetColor(MinorColor);
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::Init()
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
//	theInteractorStyle_ = vtkSmartPointer<FrgVisual_Scene_InterStyle3D>::New();
//
//	theInteractorStyle_->SetParent(this);
//
//	theInteractorStyle_->SetMouseWheelMotionFactor(0.5);
//
//	theRenderWindowInteractor_->SetInteractorStyle(theInteractorStyle_);
//
//	vtkAxesActor* axes = vtkAxesActor::New();
//
//	axes->PickableOff();
//	axes->SetShaftTypeToLine();
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
//	theLogoActor_->SetInput("Forg");
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
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::Render(FrgBool resetCamera)
//{
//	if (resetCamera)
//	{
//		theCamera_->SetPosition(0, 1, 0);
//		theCamera_->SetFocalPoint(0, 0, 0);
//		theCamera_->SetViewUp(0, 0, 1);
//		theCamera_->Azimuth(-180);
//
//		theRenderer_->SetActiveCamera(theCamera_);
//		theRenderer_->ResetCamera();
//		theRenderer_->ResetCameraClippingRange();
//
//		this->SetRenderWindow(theRenderWindow_);
//
//		theRenderWindow_->Render();
//		theRenderWindowInteractor_->Initialize();
//	}
//	else
//	{
//		theRenderWindow_->Render();
//	}
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::StartScene()
//{
//
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::DrawGrid(int nbMajorDivision, int nbMinorDivision, GridDrawPlane plane)
//{
//	double majorColor[3] = { 0.604, 0.635, 0.663 };
//	double minorColor[3] = { 0.467, 0.686, 0.902 };
//	theGridActor_ = FrgNew GridActor(nbMajorDivision, nbMinorDivision, majorColor, minorColor);
//
//	const auto& bounds = GetRenderer()->ComputeVisiblePropBounds();
//	DrawGrid(theGridActor_->theMajorActor_, nbMajorDivision, FrgTrue, bounds, plane);
//	DrawGrid(theGridActor_->theMinorActor_, nbMajorDivision * nbMinorDivision, FrgFalse, bounds, plane);
//
//	DrawGridMiddleLines(theGridActor_->theMiddleLines_, bounds, plane);
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::DrawGrid(vtkSmartPointer<vtkActor> actor, int nbDivision, FrgBool isMajor, double* bounds, GridDrawPlane plane)
//{
//	double Xmin = bounds[0], Xmax = bounds[1];
//	double Ymin = bounds[2], Ymax = bounds[3];
//	double Zmin = bounds[4], Zmax = bounds[5];
//
//	double LX = abs(Xmax - Xmin);
//	double LY = abs(Ymax - Ymin);
//	double LZ = abs(Zmax - Zmin);
//
//	double L;
//
//	if (plane == XY)
//		L = LX > LY ? LX : LY;
//	else if (plane == XZ)
//		L = LX > LZ ? LX : LZ;
//	else if (plane == YZ)
//		L = LY > LZ ? LY : LZ;
//
//	L = sqrt(LX * LX + LY * LY + LZ * LZ);
//
//	double d = 2.0 * L / (double)nbDivision;
//
//	vtkSmartPointer<vtkDoubleArray> xCoords =
//		vtkSmartPointer<vtkDoubleArray>::New();
//	vtkSmartPointer<vtkDoubleArray> yCoords =
//		vtkSmartPointer<vtkDoubleArray>::New();
//	vtkSmartPointer<vtkDoubleArray> zCoords =
//		vtkSmartPointer<vtkDoubleArray>::New();
//
//	for (int i = 0; i <= nbDivision; i++)
//	{
//		if (plane == XY)
//		{
//			xCoords->InsertNextValue(i * d - L);
//			yCoords->InsertNextValue(i * d - L);
//		}
//		else if (plane == XZ)
//		{
//			xCoords->InsertNextValue(i * d - L);
//			yCoords->InsertNextValue(i * d - L);
//		}
//		else if (plane == YZ)
//		{
//			xCoords->InsertNextValue(i * d - L);
//			yCoords->InsertNextValue(i * d - L);
//		}
//	}
//
//	zCoords->InsertNextValue(0.0);
//
//	vtkSmartPointer<vtkRectilinearGrid> rgrid =
//		vtkSmartPointer<vtkRectilinearGrid>::New();
//
//	if (plane == XY)
//	{
//		rgrid->SetDimensions(nbDivision + 1, nbDivision + 1, 1);
//		rgrid->SetXCoordinates(xCoords);
//		rgrid->SetYCoordinates(yCoords);
//		rgrid->SetZCoordinates(zCoords);
//	}
//	else if (plane == XZ)
//	{
//		rgrid->SetDimensions(nbDivision + 1, 1, nbDivision + 1);
//		rgrid->SetXCoordinates(xCoords);
//		rgrid->SetYCoordinates(zCoords);
//		rgrid->SetZCoordinates(yCoords);
//	}
//	else if (plane == YZ)
//	{
//		rgrid->SetDimensions(1, nbDivision + 1, nbDivision + 1);
//		rgrid->SetXCoordinates(zCoords);
//		rgrid->SetYCoordinates(xCoords);
//		rgrid->SetZCoordinates(yCoords);
//	}
//
//	vtkSmartPointer<vtkDataSetMapper> rgridMapper =
//		vtkSmartPointer<vtkDataSetMapper>::New();
//	rgridMapper->SetInputData(rgrid);
//
//	actor->SetMapper(rgridMapper);
//	actor->GetProperty()->SetRepresentationToWireframe();
//	if (isMajor)
//		actor->GetProperty()->SetLineWidth(2.0f);
//	else
//		actor->GetProperty()->SetLineWidth(1.0f);
//	actor->GetProperty()->EdgeVisibilityOn();
//	//actor->GetProperty()->SetEdgeColor(1.0, 0.0, 0.0);
//	//actor->GetProperty()->SetRenderLinesAsTubes(true);
//	actor->GetProperty()->SetAmbient(0.0);
//	//actor->GetProperty()->SetDiffuse(0.0);
//	actor->GetProperty()->SetSpecular(0.0);
//	actor->GetProperty()->ShadingOn();
//	actor->PickableOff();
//
//	GetRenderer()->AddActor(actor);
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::DrawGridMiddleLines(vtkSmartPointer<vtkActor> actor, double* bounds, GridDrawPlane plane)
//{
//	double Xmin = bounds[0], Xmax = bounds[1];
//	double Ymin = bounds[2], Ymax = bounds[3];
//	double Zmin = bounds[4], Zmax = bounds[5];
//
//	double LX = abs(Xmax - Xmin);
//	double LY = abs(Ymax - Ymin);
//	double LZ = abs(Zmax - Zmin);
//
//	double L = 0.0;
//	if (plane == XY)
//		L = LX > LY ? LX : LY;
//	else if (plane == XZ)
//		L = LX > LZ ? LX : LZ;
//	else if (plane == YZ)
//		L = LY > LZ ? LY : LZ;
//
//	L = sqrt(LX * LX + LY * LY + LZ * LZ);
//
//	// Create two colors - one for each line
//	unsigned char axis1Color[3];
//	unsigned char axis2Color[3];
//
//	vtkSmartPointer<vtkPolyData> linesPolyData =
//		vtkSmartPointer<vtkPolyData>::New();
//
//	double p0[3], p1[3], p2[3];
//	if (plane == XY)
//	{
//		p0[0] = Xmin + LX / 2.0;
//		p0[1] = Ymin + LY / 2.0;
//		p0[2] = 0.0;
//
//		p1[0] = p0[0] + L;
//		p1[1] = p0[1];
//		p1[2] = p0[2];
//
//		p2[0] = p0[0];
//		p2[1] = p0[1] + L;
//		p2[2] = p0[2];
//
//		axis1Color[0] = 255; axis1Color[1] = 0; axis1Color[2] = 0;
//		axis2Color[0] = 0; axis2Color[1] = 255; axis2Color[2] = 0;
//	}
//
//	else if (plane == XZ)
//	{
//		p0[0] = Xmin + LX / 2.0;
//		p0[1] = 0.0;
//		p0[2] = Zmin + LZ / 2.0;
//
//		p1[0] = p0[0] + L;
//		p1[1] = p0[1];
//		p1[2] = p0[2];
//
//		p2[0] = p0[0];
//		p2[1] = p0[1];
//		p2[2] = p0[2] + L;
//
//		axis1Color[0] = 255; axis1Color[1] = 0; axis1Color[2] = 0;
//		axis2Color[0] = 0; axis2Color[1] = 0; axis2Color[2] = 255;
//	}
//
//	else if (plane == YZ)
//	{
//		p0[0] = Xmin + LX / 2.0;
//		p0[1] = 0.0;
//		p0[2] = Zmin + LZ / 2.0;
//
//		p1[0] = p0[0];
//		p1[1] = p0[1] + L;
//		p1[2] = p0[2];
//
//		p2[0] = p0[0];
//		p2[1] = p0[1];
//		p2[2] = p0[2] + L;
//
//		axis1Color[0] = 0; axis1Color[1] = 255; axis1Color[2] = 0;
//		axis2Color[0] = 0; axis2Color[1] = 0; axis2Color[2] = 255;
//	}
//
//	// Create a vtkPoints container and store the points in it
//	vtkSmartPointer<vtkPoints> pts =
//		vtkSmartPointer<vtkPoints>::New();
//	pts->InsertNextPoint(p0);
//	pts->InsertNextPoint(p1);
//	pts->InsertNextPoint(p2);
//
//	// Add the points to the polydata container
//	linesPolyData->SetPoints(pts);
//
//	// Create the first line (between Origin and P0)
//	vtkSmartPointer<vtkLine> line0 =
//		vtkSmartPointer<vtkLine>::New();
//	line0->GetPointIds()->SetId(0, 0); // the second 0 is the index of the Origin in linesPolyData's points
//	line0->GetPointIds()->SetId(1, 1); // the second 1 is the index of P0 in linesPolyData's points
//
//	// Create the second line (between Origin and P1)
//	vtkSmartPointer<vtkLine> line1 =
//		vtkSmartPointer<vtkLine>::New();
//	line1->GetPointIds()->SetId(0, 0); // the second 0 is the index of the Origin in linesPolyData's points
//	line1->GetPointIds()->SetId(1, 2); // 2 is the index of P1 in linesPolyData's points
//
//	// Create a vtkCellArray container and store the lines in it
//	vtkSmartPointer<vtkCellArray> lines =
//		vtkSmartPointer<vtkCellArray>::New();
//	lines->InsertNextCell(line0);
//	lines->InsertNextCell(line1);
//
//	// Add the lines to the polydata container
//	linesPolyData->SetLines(lines);
//
//	// Create a vtkUnsignedCharArray container and store the colors in it
//	vtkSmartPointer<vtkUnsignedCharArray> colors =
//		vtkSmartPointer<vtkUnsignedCharArray>::New();
//	colors->SetNumberOfComponents(3);
//	colors->InsertNextTypedTuple(axis1Color);
//	colors->InsertNextTypedTuple(axis2Color);
//
//	// Color the lines
//	linesPolyData->GetCellData()->SetScalars(colors);
//
//	// Setup the visualization pipeline
//	vtkSmartPointer<vtkPolyDataMapper> mapper =
//		vtkSmartPointer<vtkPolyDataMapper>::New();
//
//	mapper->SetInputData(linesPolyData);
//
//	actor->SetMapper(mapper);
//	actor->GetProperty()->SetLineWidth(3.0f);
//	//actor->GetProperty()->SetRenderLinesAsTubes(true);
//	actor->GetProperty()->SetAmbient(0.0);
//	actor->GetProperty()->SetSpecular(0.0);
//	actor->GetProperty()->ShadingOn();
//	actor->PickableOff();
//
//	GetRenderer()->AddActor(actor);
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::customContextMenuRequestedSlot(const QPoint& pos)
//{
//	theContextMenuInScene_->exec(this->mapToGlobal(pos));
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::CreateContextMenuInScene()
//{
//	//FrgMenu_View* viewMenu = FrgNew FrgMenu_View(GetParentTree()->GetParentMainWindow());
//
//	theContextMenuInScene_ = FrgNew FrgBase_Menu(GetParentTree()->GetParentMainWindow());
//
//	for (int i = 0; i < theMenus_.size(); i++)
//	{
//		theContextMenuInScene_->addActions(theMenus_[i]->actions());
//		theContextMenuInScene_->addSeparator();
//	}
//
//	connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(customContextMenuRequestedSlot(const QPoint&)));
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::CreateMenus()
//{
//
//}
//
//QAction* ForgVisualLib::FrgVisual_Scene3D::GetActionItemInScene(FrgString actionName)
//{
//	QAction* result = nullptr;
//
//	for (int iMenu = 0; iMenu < theMenus_.size(); iMenu++)
//	{
//		result = theMenus_[iMenu]->GetItem(actionName);
//		if (result)
//			break;
//	}
//	return result;
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::ClearGrid()
//{
//	if (theGridActor_)
//	{
//		theRenderer_->RemoveActor(theGridActor_->theMajorActor_);
//		theRenderer_->RemoveActor(theGridActor_->theMinorActor_);
//		theRenderer_->RemoveActor(theGridActor_->theMiddleLines_);
//
//		delete theGridActor_;
//		theGridActor_ = FrgNullPtr;
//	}
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::RemoveActor(vtkProp* prop)
//{
//	theRenderer_->RemoveActor(prop);
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::SetViewToXYPlaneSlot(bool)
//{
//	if (theGridActor_)
//	{
//		double opacity = theGridActor_->theMajorActor_->GetProperty()->GetOpacity();
//		int nbMajorDivision = theGridActor_->theNbMajorDivision_;
//		int nbMinorDivision = theGridActor_->theNbMinorDivision_;
//
//		ClearGrid();
//
//		DrawGrid(nbMajorDivision, nbMinorDivision, XY);
//
//		GridOpacityChangedSlot(opacity * 100);
//
//		for (int i = 0; i < theContextMenuInScene_->actions().size(); i++)
//			if (theContextMenuInScene_->actions()[i]->text() == "Draw Grid")
//				DrawGridSlot(theContextMenuInScene_->actions()[i]->isChecked());
//	}
//	theInteractorStyle_->SetViewToXYPlane();
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::SetViewToXZPlaneSlot(bool)
//{
//	if (theGridActor_)
//	{
//		double opacity = theGridActor_->theMajorActor_->GetProperty()->GetOpacity();
//		int nbMajorDivision = theGridActor_->theNbMajorDivision_;
//		int nbMinorDivision = theGridActor_->theNbMinorDivision_;
//
//		ClearGrid();
//
//		DrawGrid(nbMajorDivision, nbMinorDivision, XZ);
//
//		GridOpacityChangedSlot(opacity * 100);
//
//		for (int i = 0; i < theContextMenuInScene_->actions().size(); i++)
//			if (theContextMenuInScene_->actions()[i]->text() == "Draw Grid")
//				DrawGridSlot(theContextMenuInScene_->actions()[i]->isChecked());
//	}
//	theInteractorStyle_->SetViewToXZPlane();
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::SetViewToYZPlaneSlot(bool)
//{
//	if (theGridActor_)
//	{
//		double opacity = theGridActor_->theMajorActor_->GetProperty()->GetOpacity();
//		int nbMajorDivision = theGridActor_->theNbMajorDivision_;
//		int nbMinorDivision = theGridActor_->theNbMinorDivision_;
//
//		ClearGrid();
//
//		DrawGrid(nbMajorDivision, nbMinorDivision, YZ);
//
//		GridOpacityChangedSlot(opacity * 100);
//
//		for (int i = 0; i < theContextMenuInScene_->actions().size(); i++)
//			if (theContextMenuInScene_->actions()[i]->text() == "Draw Grid")
//				DrawGridSlot(theContextMenuInScene_->actions()[i]->isChecked());
//	}
//	theInteractorStyle_->SetViewToYZPlane();
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::SetViewToXYZSlot(bool)
//{
//	if (theGridActor_)
//	{
//		double opacity = theGridActor_->theMajorActor_->GetProperty()->GetOpacity();
//		int nbMajorDivision = theGridActor_->theNbMajorDivision_;
//		int nbMinorDivision = theGridActor_->theNbMinorDivision_;
//
//		ClearGrid();
//
//		DrawGrid(nbMajorDivision, nbMinorDivision, XY);
//
//		GridOpacityChangedSlot(opacity * 100);
//
//		for (int i = 0; i < theContextMenuInScene_->actions().size(); i++)
//			if (theContextMenuInScene_->actions()[i]->text() == "Draw Grid")
//				DrawGridSlot(theContextMenuInScene_->actions()[i]->isChecked());
//	}
//	theInteractorStyle_->SetViewToXYZ();
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::GridOpacityChangedSlot(int val)
//{
//	if (theGridActor_)
//	{
//		theGridActor_->theMajorActor_->GetProperty()->SetOpacity((double)val / 100.0);
//		theGridActor_->theMinorActor_->GetProperty()->SetOpacity((double)val / 100.0);
//		theGridActor_->theMiddleLines_->GetProperty()->SetOpacity((double)val / 100.0);
//
//		theRenderWindow_->Render();
//	}
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::DrawGridSlot(bool checked)
//{
//	if (theGridActor_)
//	{
//		theGridActor_->theMajorActor_->SetVisibility(checked);
//		theGridActor_->theMinorActor_->SetVisibility(checked);
//		theGridActor_->theMiddleLines_->SetVisibility(checked);
//
//		theRenderWindow_->Render();
//	}
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::ScreenshotSlot(bool)
//{
//	QList<QString> QfileTypes;
//	QfileTypes.push_back("JPEG (*.jpg; *.jpeg)");
//	QfileTypes.push_back("PNG (*.png)");
//	QfileTypes.push_back("BMP (*.bmp)");
//	QfileTypes.push_back("PNM (*.pnm)");
//	QfileTypes.push_back("Post Script (*.ps)");
//
//	QString fileTypes;
//	for (int i = 0; i < QfileTypes.size() - 1; i++)
//	{
//		fileTypes += QfileTypes.at(i);
//		fileTypes += ";;";
//	}
//	fileTypes += QfileTypes.at(QfileTypes.size() - 1);
//
//	QString* ext = new QString("PNG");
//	QString fileName = QFileDialog::getSaveFileName(GetParentTree()->GetParentMainWindow(),
//		QMainWindow::tr("Export Part"), "",
//		fileTypes, ext);
//
//	if (fileName.isEmpty())
//		return;
//	else
//	{
//		// Screenshot  
//		vtkSmartPointer<vtkWindowToImageFilter> windowToImageFilter =
//			vtkSmartPointer<vtkWindowToImageFilter>::New();
//		windowToImageFilter->SetInput(theRenderWindow_);
//
//		int Magnification = 2;
//
//		//windowToImageFilter->SetScale(1366 / theRenderWindow_->GetSize()[0], 768 / theRenderWindow_->GetSize()[1]); // image quality
//		windowToImageFilter->SetScale(Magnification); // image quality
//
//		theLogoActor_->GetTextProperty()->SetFontSize(Magnification * theLogoActor_->GetTextProperty()->GetFontSize());
//		theLogoActor_->GetTextProperty()->SetShadowOffset
//		(
//			Magnification * theLogoActor_->GetTextProperty()->GetShadowOffset()[0],
//			Magnification * theLogoActor_->GetTextProperty()->GetShadowOffset()[1]
//		);
//
//		/*for (int i = 0; i < theGeometry_.size(); i++)
//			theGeometry_[i]->GetProperty()->SetLineWidth((float)Magnification*theGeometry_[i]->GetProperty()->GetLineWidth());*/
//
//		windowToImageFilter->ReadFrontBufferOff(); // read from the back buffer
//		windowToImageFilter->Update();
//
//		vtkSmartPointer<vtkImageWriter> writer;// = vtkSmartPointer<vtkJPEGWriter>::New();
//
//		if (*ext == "JPEG (*.jpg; *.jpeg)")
//		{
//			writer = vtkSmartPointer<vtkJPEGWriter>::New();
//		}
//		else if (*ext == "PNG (*.png)")
//		{
//			writer = vtkSmartPointer<vtkPNGWriter>::New();
//		}
//		else if (*ext == "BMP (*.bmp)")
//		{
//			writer = vtkSmartPointer<vtkBMPWriter>::New();
//		}
//		else if (*ext == "PNM (*.pnm)")
//		{
//			writer = vtkSmartPointer<vtkPNMWriter>::New();
//		}
//		else if (*ext == "Post Script (*.ps)")
//		{
//			writer = vtkSmartPointer<vtkPostScriptWriter>::New();
//		}
//
//		writer->SetFileName(fileName.toStdString().c_str());
//		writer->SetInputConnection(windowToImageFilter->GetOutputPort());
//		//writer->SetQuality(100);
//		writer->Write();
//
//		theLogoActor_->GetTextProperty()->SetFontSize((1.0 / (float)Magnification) * theLogoActor_->GetTextProperty()->GetFontSize());
//		theLogoActor_->GetTextProperty()->SetShadowOffset
//		(
//			(1.0 / (float)Magnification) * theLogoActor_->GetTextProperty()->GetShadowOffset()[0],
//			(1.0 / (float)Magnification) * theLogoActor_->GetTextProperty()->GetShadowOffset()[1]
//		);
//
//		/*for (int i = 0; i < theGeometry_.size(); i++)
//			theGeometry_[i]->GetProperty()->SetLineWidth((1.0 / (float)Magnification)*theGeometry_[i]->GetProperty()->GetLineWidth());*/
//
//		theRenderWindow_->Render();
//	}
//}
//
//inline QVector<QColor> rndColors(int count) {
//	QVector<QColor> colors;
//	float currentHue = 0.0;
//	for (int i = 0; i < count; i++)
//	{
//		colors.push_back(QColor::fromHslF(currentHue, 1.0, 0.5));
//		currentHue += 0.618033988749895f;
//		currentHue = std::fmod(currentHue, 1.0f);
//	}
//	return colors;
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::RandomColorsSlot(bool checked)
//{
//	auto actors = GetActors();
//
//	if (!checked)
//	{
//		for (int iActor = 0; iActor < actors.size(); iActor++)
//		{
//			actors[iActor]->GetProperty()->SetColor
//			(
//				FrgBaseInteractorStyle::GeometryColorRGB.redF(),
//				FrgBaseInteractorStyle::GeometryColorRGB.greenF(),
//				FrgBaseInteractorStyle::GeometryColorRGB.blueF()
//			);
//		}
//	}
//	else
//	{
//		QVector<QColor> colors = rndColors(actors.size());
//
//		for (int iActor = 0; iActor < actors.size(); iActor++)
//		{
//			actors[iActor]->GetProperty()->SetColor(colors.at(iActor).redF(), colors.at(iActor).greenF(), colors.at(iActor).blueF());
//
//			theRenderWindow_->Render();
//		}
//	}
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::ShowMeshSlot(bool condition)
//{
//	theInteractorStyle_->ShowMesh(condition);
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::HideActorsSlot(bool)
//{
//	theInteractorStyle_->HideSelectedActors();
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::ShowHiddenPartsSlot(bool)
//{
//	theInteractorStyle_->ShowAllActors();
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::SelectIconSelectedSlot(bool)
//{
//	GetParentTree()->GetParentMainWindow()->setCursor(QCursor());
//
//	theInteractorStyle_->GetSelectedIconFromScene() = Cursor;
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::MoveIconSelectedSlot(bool)
//{
//	QPixmap cursor_pixmap = QPixmap(ICON_Menu_Scene_Move);
//	QCursor cursor_default = QCursor(cursor_pixmap, 0, 0);
//	GetParentTree()->GetParentMainWindow()->setCursor(cursor_default);
//
//	theInteractorStyle_->GetSelectedIconFromScene() = FrgVisual_Scene_InterStyle3D::Move;
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::RotateXIconSelectedSlot(bool)
//{
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::RotateYIconSelectedSlot(bool)
//{
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::RotateZIconSelectedSlot(bool)
//{
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::RotateXYZIconSelectedSlot(bool)
//{
//	QPixmap cursor_pixmap = QPixmap(ICON_Menu_Scene_RotateXYZ);
//	QCursor cursor_default = QCursor(cursor_pixmap, 0, 0);
//	GetParentTree()->GetParentMainWindow()->setCursor(cursor_default);
//
//	theInteractorStyle_->GetSelectedIconFromScene() = FrgVisual_Scene_InterStyle3D::RotateXYZ;
//}