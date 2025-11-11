#include <FrgVisual_Scene.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgVisual_Scene_InterStyle.hxx>
#include <FrgVisual_SceneRegistry.hxx>

#include <FrgBase_SerialSpec_QString.hxx>
#include <FrgBase_SerialSpec_QColor.hxx>

#include <FrgVisual_PointActor.hxx>
#include <FrgVisual_PickingPointActor.hxx>
#include <FrgVisual_LineActor.hxx>
#include <FrgVisual_PolylineActor.hxx>
#include <FrgVisual_MeshActor.hxx>
#include <FrgVisual_MeshPolyhedralActor.hxx>
#include <FrgVisual_BSPLineActor.hxx>
#include <FrgVisual_RectangleActor.hxx>
#include <FrgVisual_CircleActor.hxx>
#include <FrgVisual_GridActor.hxx>
#include <FrgVisual_BoxActor.hxx>
#include <FrgVisual_CylinderActor.hxx>
#include <FrgVisual_ShapeActor.hxx>
#include <FrgVisual_SphereActor.hxx>
#include <FrgVisual_TextActor.hxx>
#include <FrgVisual_PlaneActor.hxx>
#include <FrgVisual_Scene_InterStyle2D.hxx>
#include <FrgVisual_Scene_InterStyle3D.hxx>
#include <Tools/Ruler/FrgVisual_Scene_Ruler.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgBase_Pnt.hxx>
#include <FrgBase_TabWidget.hxx>

#include <filesystem>

#include <QVTKOpenGLNativeWidget.h>
#include <QFile.h>
#include <QTextStream.h>
#include <QApplication>

#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkAxesActor.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkLight.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkCamera.h>
#include <vtkLineSource.h>
#include <vtkPolyLine.h>
#include <vtkCubeSource.h>
#include <vtkAssemblyPath.h>
#include <vtkCollection.h>
#include <vtkCameraInterpolator.h>
#include <vtkFXAAOptions.h>
#include <vtkLogoRepresentation.h>
#include <vtkPNGReader.h>
#include <vtkProperty2D.h>

#include <vtkSequencePass.h>
#include <vtkOpaquePass.h>
#include <vtkLightsPass.h>
#include <vtkDepthPeelingPass.h>
#include <vtkTranslucentPass.h>
#include <vtkCameraPass.h>
#include <vtkShadowMapBakerPass.h>
#include <vtkShadowMapPass.h>
#include <vtkVolumetricPass.h>
#include <vtkRenderPassCollection.h>
#include <vtkOverlayPass.h>

#include <QToolBar>
#include <QToolButton>

#include <vtkAutoInit.h>

#define IS_FRGVISUAL_ACTOR "IS_FRGVISUAL_ACTOR"
#define IS_NOT_FRGVISUAL_ACTOR "IS_NOT_FRGVISUAL_ACTOR"

VTK_MODULE_INIT(vtkRenderingContextOpenGL2)
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)
VTK_MODULE_INIT(vtkRenderingFreeType)
VTK_MODULE_INIT(vtkRenderingGL2PSOpenGL2)

ForgVisualLib::FrgVisual_Scene_Entity::FrgVisual_Scene_Entity
(
	ForgBaseLib::FrgBase_MainWindow* parentMainWindow
)
	: QMainWindow(parentMainWindow)
	, theParentMainWindow_(parentMainWindow)
{
	theRegistry_ = new FrgVisual_SceneRegistry(this);

	theOpenGLWidget_ = new QVTKOpenGLNativeWidget(parentMainWindow);
	theOpenGLWidget_->setEnableHiDPI(true);

	theContextMenuInScene_ = new ForgBaseLib::FrgBase_Menu("Scene Settings", parentMainWindow, false);
	theContextMenuInScene_->SetToolBarHidden(true);

	connect(theContextMenuInScene_, &ForgBaseLib::FrgBase_Menu::aboutToHide, [this]() {ContextMenuAboutToHide(theContextMenuInScene_); });

	/*auto hideAction = theContextMenuInScene_->AddItem("Hide", false);
	auto unHideAction = theContextMenuInScene_->AddItem("UnHide", false);*/

	connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(customContextMenuRequestedSlot(const QPoint&)));

	this->setCentralWidget(theOpenGLWidget_);

	if (theParentMainWindow_)
	{
		connect(theParentMainWindow_, &ForgBaseLib::FrgBase_MainWindow::TabWidgetActivated, [this](QWidget* w, bool isActive)
			{
				if (w == this && isActive == true)
				RenderScene(false, false);
			});
		//connect(theParentMainWindow_->GetTabWidget(), &ForgBaseLib::FrgBase_TabWidget::currentChanged, this, &FrgVisual_Scene_Entity::CurrentTabChangedSlot);
	}

	theInitiated_ = false;

	connect(this, &FrgVisual_Scene_Entity::RenderScene, this, &FrgVisual_Scene_Entity::RenderSceneSlot, Qt::QueuedConnection);

	theLogoActor_ = vtkSmartPointer<vtkTextActor>::New();
	theLogoActor_->SetInput("Forg Soft");

	connect
	(
		this,
		&FrgVisual_Scene_Entity::RemoveActor,
		this,
		&FrgVisual_Scene_Entity::RemoveActorSlot,
		Qt::QueuedConnection
	);

	//SetParentMainWindow(parentMainWindow);
}

ForgVisualLib::FrgVisual_Scene_Entity::~FrgVisual_Scene_Entity()
{
	RemoveAllActors();

	FreePointer(theRegistry_);
}

bool ForgVisualLib::FrgVisual_Scene_Entity::IsThemeDark() const
{
	if (theParentMainWindow_)
		return theParentMainWindow_->IsThemeDark();

	return false;
}

void ForgVisualLib::FrgVisual_Scene_Entity::SetThemeDark
(
	const bool isDark
)
{
	if (!theRenderer_)
		return;

	if (Is2D())
	{
		if(IsThemeDark())
			theRenderer_->SetBackground(0.2, 0.2, 0.2);
		else
			theRenderer_->SetBackground(1.0, 1.0, 1.0);

		theRenderer_->SetGradientBackground(false);
	}
	else if (Is3D())
	{
		theRenderer_->SetBackground(1.0, 1.0, 1.0);
		theRenderer_->SetBackground2(0.7, 0.7, 0.7);

		theRenderer_->SetGradientBackground(true);
	}

	RenderScene(false, false);
}

void ForgVisualLib::FrgVisual_Scene_Entity::RemoveAllActors()
{
	if (theRenderer_)
	{
		vtkActorCollection* ac = theRenderer_->GetActors();
		vtkCollectionSimpleIterator ait;
		vtkActor* anActor, * aPart;
		vtkAssemblyPath* path;
		for (ac->InitTraversal(ait); (anActor = ac->GetNextActor(ait)); )
		{
			const auto& frgActor = dynamic_cast<FrgVisual_BaseActor_Entity*>(anActor);
			if (frgActor)
				RemoveActor(frgActor);
		}
	}
}

void ForgVisualLib::FrgVisual_Scene_Entity::SetLogoText(const char* logoText)
{
	if (theLogoActor_)
	{
		theLogoActor_->SetInput(logoText);
		RenderScene(false);
	}
}

void ForgVisualLib::FrgVisual_Scene_Entity::SetParentMainWindow(ForgBaseLib::FrgBase_MainWindow* parentMainWindow)
{
	this->setParent(parentMainWindow);
	theParentMainWindow_ = parentMainWindow;

	if (theParentMainWindow_)
	{
		connect(theParentMainWindow_, &ForgBaseLib::FrgBase_MainWindow::TabWidgetActivated, [this](QWidget* w, bool isActive)
			{
				if (w == this && isActive == true)
				RenderScene(false, false);
			});

		if(Is2D())
			SetThemeDark(IsThemeDark());
	}

	//connect(theParentMainWindow_->GetTabWidget(), &ForgBaseLib::FrgBase_TabWidget::currentChanged, this, &FrgVisual_Scene_Entity::CurrentTabChangedSlot);
}

void ForgVisualLib::FrgVisual_Scene_Entity::SetMajorGridColor(const QColor& color)
{
	theMajorGridColor_ = color;
	if (theMajorGridActor_)
	{
		theMajorGridActor_->SetColor(color.redF(), color.greenF(), color.blueF());
		RenderScene(false, false);
	}
}

void ForgVisualLib::FrgVisual_Scene_Entity::SetMinorGridColor(const QColor& color)
{
	theMinorGridColor_ = color;
	if (theMinorGridActor_)
	{
		theMinorGridActor_->SetColor(color.redF(), color.greenF(), color.blueF());
		RenderScene(false, false);
	}
}

int ForgVisualLib::FrgVisual_Scene_Entity::AddActorToScene(FrgVisual_BaseActor_Entity* actor)
{
	int index = theRegistry_->AddActor(actor);
	if (index >= 0 || index == -2)
	{
		if (theRenderer_)
		{
			actor->SetRenderer(theRenderer_);
			actor->AddActors(theRenderer_);
			theRenderer_->AddActor(actor);
		}
	}

	emit ActorAddedSignal(actor);

	return index;
}

void ForgVisualLib::FrgVisual_Scene_Entity::RemoveActorSlot(FrgVisual_BaseActor_Entity* actor)
{
	if (!actor)
		return;

	if (theRenderer_)
	{
		emit ActorIsGoingToBeDeletedSignal(actor);

		actor->RemoveActors(theRenderer_);

		UnSelectActor(actor, false);

		theRegistry_->RemoveActor(actor);
		theRenderer_->RemoveActor(actor);
	}
}

std::vector<ForgVisualLib::FrgVisual_GridActor*> ForgVisualLib::FrgVisual_Scene_Entity::DrawGrid
(
	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<2>> center,
	double L1,
	double L2,
	int numberOfDivisions1,
	int numberOfDivisions2,
	bool render
)
{
	std::vector<ForgVisualLib::FrgVisual_GridActor*> myGrids;

	if (center == nullptr)
		return myGrids;

	if (theMajorGridActor_ || theMinorGridActor_)
		ClearGrid();

	theMajorGridActor_ = FrgVisual_GridActor::New();
	theMinorGridActor_ = FrgVisual_GridActor::New();
	theMajorGridActor_->SetRenderer(theRenderer_);
	theMinorGridActor_->SetRenderer(theRenderer_);

	theMajorGridActor_->SetData(center, L1, L2, numberOfDivisions1, numberOfDivisions2, true);
	theMajorGridActor_->SetColor(theMajorGridColor_.redF(), theMajorGridColor_.greenF(), theMajorGridColor_.blueF());
	theMajorGridActor_->SetLineWidth(2.0f);

	theMinorGridActor_->SetData(center, L1, L2, numberOfDivisions1 * 2, numberOfDivisions2 * 2);
	theMinorGridActor_->SetColor(theMinorGridColor_.redF(), theMinorGridColor_.greenF(), theMinorGridColor_.blueF());
	theMinorGridActor_->SetLineWidth(1.0f);

	auto myXLine = theMajorGridActor_->GetXLine();
	auto myYLine = theMajorGridActor_->GetYLine();

	AddActorToScene(theMajorGridActor_);
	AddActorToScene(theMinorGridActor_);
	AddActorToScene(myXLine);
	AddActorToScene(myYLine);

	if (render)
		RenderScene(false);

	myGrids.push_back(theMajorGridActor_);
	myGrids.push_back(theMinorGridActor_);

	return myGrids;
}

std::vector<ForgVisualLib::FrgVisual_GridActor*> ForgVisualLib::FrgVisual_Scene_Entity::DrawGrid
(
	double xCenter,
	double yCenter,
	double L1,
	double L2,
	int numberOfDivisions1,
	int numberOfDivisions2,
	bool render
)
{
	return DrawGrid(std::make_shared<ForgBaseLib::FrgBase_Pnt<2>>(xCenter, yCenter), L1, L2, numberOfDivisions1, numberOfDivisions2);
}

void ForgVisualLib::FrgVisual_Scene_Entity::ClearGrid()
{
	if (theMajorGridActor_)
	{
		theRenderer_->RemoveActor(theMajorGridActor_->GetXLine());
		theRenderer_->RemoveActor(theMajorGridActor_->GetYLine());
		theRenderer_->RemoveActor(theMajorGridActor_);

		FreePointer(theMajorGridActor_);
	}

	if (theMinorGridActor_)
	{
		theRenderer_->RemoveActor(theMinorGridActor_->GetXLine());
		theRenderer_->RemoveActor(theMinorGridActor_->GetYLine());
		theRenderer_->RemoveActor(theMinorGridActor_);

		FreePointer(theMinorGridActor_);
	}
}

ForgVisualLib::FrgVisual_TextActor<2>* ForgVisualLib::FrgVisual_Scene_Entity::AddText
(
	const QString& value,
	double posx,
	double posy,
	bool render
)
{
	// Actor
	vtkNew<FrgVisual_TextActor<2>> actor;
	//actor->SetRenderer(theRenderer_);

	actor->SetData(value, posx, posy);

	AddActorToScene(actor);

	if (render)
		RenderScene(false);

	return std::move(actor);
}

ForgVisualLib::FrgVisual_TextActor<3>* ForgVisualLib::FrgVisual_Scene_Entity::AddText
(
	const QString& value,
	double posx,
	double posy,
	double posz,
	bool render
)
{
	// Actor
	vtkNew<FrgVisual_TextActor<3>> actor;
	//actor->SetRenderer(theRenderer_);

	actor->SetData(value, posx, posy, posz);

	AddActorToScene(actor);

	if (render)
		RenderScene(false);

	return std::move(actor);
}

void ForgVisualLib::FrgVisual_Scene_Entity::SetLogoImage(const vtkSmartPointer<vtkLogoRepresentation>& logoImage)
{
	if (!logoImage)
		return;

	if (theLogoImage_)
	{
		theRenderer_->RemoveViewProp(theLogoImage_);
	}

	theLogoImage_ = logoImage;

	theRenderer_->AddViewProp(theLogoImage_);
	theLogoImage_->SetRenderer(theRenderer_);

	RenderScene(false, false);
}

std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity*>
ForgVisualLib::FrgVisual_Scene_Entity::GetAllActors(const bool everything) const
{
	std::vector<FrgVisual_BaseActor_Entity*> actors;

	if(everything)
	{
		vtkRenderWindowInteractor* rwi = theRenderWindowInteractor_;
		vtkActorCollection* ac;
		vtkActor* anActor;
		if (theRenderer_ != nullptr)
		{
			ac = theRenderer_->GetActors();
			vtkCollectionSimpleIterator ait;
			for (ac->InitTraversal(ait); (anActor = ac->GetNextActor(ait)); )
			{
				auto aPart = dynamic_cast<FrgVisual_BaseActor_Entity*>(anActor);
				if (aPart)
					actors.push_back(aPart);
			}
		}
	}
	else
	{
		auto actorsMap = theRegistry_->GetAllActors();
		for (auto [index, actor] : actorsMap)
			actors.push_back(actor);
	}

	return actors;
}

void ForgVisualLib::FrgVisual_Scene_Entity::SetLogoImageFileAddress(const std::string& fileName)
{
	InitLogoImage(fileName);
}

void ForgVisualLib::FrgVisual_Scene_Entity::SetLogoImageHidden(bool condition)
{
	if (theLogoImage_)
	{
		if (!condition)
			theRenderer_->RemoveViewProp(theLogoImage_);
		else
		{
			if (!theRenderer_->HasViewProp(theLogoImage_))
				theRenderer_->AddViewProp(theLogoImage_);
		}
	}
}

std::pair<ForgBaseLib::FrgBase_Pnt<3>, ForgBaseLib::FrgBase_Pnt<3>>
ForgVisualLib::FrgVisual_Scene_Entity::ComputeVisibleBoundingBox() const
{
	double bounds[6];
	ComputeVisiblePropBounds(bounds);

	ForgBaseLib::FrgBase_Pnt<3> minPoint(bounds[0], bounds[2], bounds[4]);
	ForgBaseLib::FrgBase_Pnt<3> maxPoint(bounds[1], bounds[3], bounds[5]);

	//delete bounds;

	return std::make_pair(minPoint, maxPoint);
}

void ForgVisualLib::FrgVisual_Scene_Entity::ComputeVisiblePropBounds(double bounds[6]) const
{
	std::vector<FrgVisual_BaseActor_Entity*> myActorsShouldBeHidden;
	for (auto myActor : GetAllActors(true))
	{
		const bool isAxesActor = dynamic_cast<vtkAxesActor*>(myActor);

		if (myActor->IsGrid() || myActor->IsText() || isAxesActor)
		{
			myActorsShouldBeHidden.push_back(myActor);
			myActor->VisibilityOff();
		}
	}

	theRenderer_->ComputeVisiblePropBounds(bounds);

	for (auto myActorShouldBeHidden : myActorsShouldBeHidden)
	{
		myActorShouldBeHidden->VisibilityOn();
	}
}

static std::string GenerateRandomName
(
	unsigned int length,
	const std::string& prefix = "",
	const std::string& suffix = "",
	const std::string& contains = ""
)
{
	std::string alphanum =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	alphanum += contains;

	int stringLength = (int)alphanum.size();
	std::string Str = prefix;

	unsigned int i;
	for (i = 0; i < length; ++i)
	{
		auto a = rand();

		Str += alphanum[a % stringLength];
	}

	Str += suffix;
	return Str;
}

void ForgVisualLib::FrgVisual_Scene_Entity::InitLogoImage(const std::string& fileName)
{
	if (fileName.empty())
	{
		if (theLogoImage_)
			theRenderer_->RemoveViewProp(theLogoImage_);

		RenderScene(false, false);

		return;
	}

	std::string imageFileName = GenerateRandomName(10, "Tonb-", ".png");
	//auto newFileAddress = QApplication::instance()->applicationDirPath() + "/" + QString::fromStdString(imageFileName);
	std::filesystem::path tmp_dir_path{ std::filesystem::temp_directory_path() /= std::tmpnam(nullptr) };
	std::filesystem::create_directories(tmp_dir_path);

	QString newFileAddress = QString::fromStdString(tmp_dir_path.string());
	newFileAddress = newFileAddress.replace("\\", "/");
	newFileAddress += ("/" + QString::fromStdString(imageFileName));

	if (QFile::exists(newFileAddress))
	{
		QFile f;
		f.setFileName(newFileAddress);
		f.setPermissions(QFileDevice::Permission::WriteOwner);
		f.remove();
		f.close();
	}

	if (!QFile::copy(QString::fromStdString(fileName), newFileAddress))
	{
		std::cout << "Cannot copy\n";
		return;
	}

	auto pngReader = vtkSmartPointer<vtkPNGReader>::New();
	pngReader->SetFileName(newFileAddress.toStdString().c_str());
	pngReader->Update();

	auto logoInput = pngReader->GetOutput();

	if (theLogoImage_)
		theRenderer_->RemoveViewProp(theLogoImage_);

	theLogoImage_ = vtkSmartPointer<vtkLogoRepresentation>::New();
	theLogoImage_->SetImage(logoInput);
	theLogoImage_->ProportionalResizeOn();
	theLogoImage_->SetPosition(0.0, 0.85);
	theLogoImage_->SetPosition2(0.15, 0.15);
	theLogoImage_->GetImageProperty()->SetOpacity(1.0);
	theLogoImage_->GetImageProperty()->SetDisplayLocationToForeground();
	theRenderer_->AddViewProp(theLogoImage_);
	theLogoImage_->SetRenderer(theRenderer_);

	//std::remove(imageFileName);
	{
		QFile f;
		f.setFileName(newFileAddress);
		f.setPermissions(QFileDevice::Permission::WriteOwner);
		f.remove();
		f.close();
	}

	RenderScene(false, false);
}

void ForgVisualLib::FrgVisual_Scene_Entity::FormToolBar()
{
	if (!theToolBar_)
	{
		theToolBar_ = new QToolBar("Visual");
		theToolBar_->setAllowedAreas(Qt::ToolBarArea::TopToolBarArea);
		theToolBar_->setFloatable(false);
		theToolBar_->setMovable(false);
		theToolBar_->setContextMenuPolicy(Qt::PreventContextMenu);

		auto* resetView = new QToolButton();
		resetView->setIcon(QIcon(ICON_FRGVISUAL_SCENE_RESETVIEW));
		resetView->setShortcut(QKeySequence(Qt::Key_R));
		resetView->setToolTip("Reset View (R)");
		connect(resetView, &QToolButton::clicked, [this]() {RenderScene(true); });

		theToolBar_->addWidget(resetView);

		this->addToolBar(theToolBar_);
	}
}

void ForgVisualLib::FrgVisual_Scene_Entity::customContextMenuRequestedSlot(const QPoint& pos)
{
	theContextMenuPosition_ = this->mapToGlobal(pos);

	if (theCopyContextMenuInScene_)
	{
		emit ContextMenuAboutToShow(theCopyContextMenuInScene_);

		if (theIsContextMenuExecutable_)
		{
			if (!theCopyContextMenuInScene_->actions().isEmpty())
				theCopyContextMenuInScene_->exec(this->mapToGlobal(pos));
		}
	}
	else if (theContextMenuInScene_)
	{
		emit ContextMenuAboutToShow(theContextMenuInScene_);

		if (theIsContextMenuExecutable_)
		{
			if (!theContextMenuInScene_->actions().isEmpty())
				theContextMenuInScene_->exec(this->mapToGlobal(pos));
		}
	}
}

void ForgVisualLib::FrgVisual_Scene_Entity::HideAxesCenterWorldActor(const bool condition)
{
	if (theAxesCenterWorldActor_)
	{
		theRenderer_->RemoveActor(theAxesCenterWorldActor_);

		if (!condition)
			theRenderer_->AddActor(theAxesCenterWorldActor_);

		RenderScene(false, false);
	}
}

bool ForgVisualLib::FrgVisual_Scene_Entity::HasAxesCenterWorldActor() const
{
	if (theRenderer_)
		return theRenderer_->HasViewProp(theAxesCenterWorldActor_);

	return false;
}

void ForgVisualLib::FrgVisual_Scene_Entity::SetContextMenuInScene(ForgBaseLib::FrgBase_Menu* menu)
{
	theCopyContextMenuInScene_ = menu;

	if (theCopyContextMenuInScene_)
		connect(theCopyContextMenuInScene_, &ForgBaseLib::FrgBase_Menu::aboutToHide, [this]() {ContextMenuAboutToHide(theCopyContextMenuInScene_); });

}

void ForgVisualLib::FrgVisual_Scene_Entity::HideActionIsCalledSlot()
{

}

void ForgVisualLib::FrgVisual_Scene_Entity::UnHideActionIsCalledSlot()
{

}

void ForgVisualLib::FrgVisual_Scene_Entity::CurrentTabChangedSlot(int index)
{
	/*if (theParentMainWindow_->GetTabWidget()->widget(index) == this)
		RenderScene(false);*/
}

void ForgVisualLib::FrgVisual_Scene_Entity::RenderSceneSlot
(
	bool resetCamera,
	bool resetView
)
{
	if(theAxesCenterWorldActor_)
	{
		auto [mi, ma] = ComputeVisibleBoundingBox();

		const auto dx = std::abs(mi.X() - ma.X());
		const auto dy = std::abs(mi.Y() - ma.Y());
		const auto dz = std::abs(mi.Z() - ma.Z());

		auto d = 0.2 * std::min(dx, std::min(dy, dz));

		if (d == 0.0)
			d = 1.0;

		theAxesCenterWorldActor_->SetTotalLength(d, d, d);
	}
}

template<int Dim>
ForgVisualLib::FrgVisual_Scene<Dim>::FrgVisual_Scene(ForgBaseLib::FrgBase_MainWindow* parentMainWindow)
	: FrgVisual_Scene_Entity(parentMainWindow)
{

}

template<int Dim>
ForgVisualLib::FrgVisual_Scene<Dim>::~FrgVisual_Scene()
{

}

#include <vtkAxisActor2D.h>

template<int Dim>
void ForgVisualLib::FrgVisual_Scene<Dim>::Init()
{
	theRenderer_ = vtkSmartPointer<vtkRenderer>::New();

	SetThemeDark(IsThemeDark());

	theRenderWindow_ = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();

	theRenderWindow_->SetAlphaBitPlanes(1);
	theRenderWindow_->SetMultiSamples(0);

	theRenderWindow_->AddRenderer(theRenderer_);

	theRenderWindowInteractor_ = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	theRenderWindowInteractor_->SetRenderWindow(theRenderWindow_);

	theRenderWindowInteractor_->LightFollowCameraOff();

	InitInteractorStyle();
	theInteractorStyle_->FormInterStyle();

	/*if constexpr (Dim == 2)
		theInteractorStyle_ = FrgVisual_Scene_InterStyle2D::New();
	else if constexpr (Dim == 3)
		theInteractorStyle_ = FrgVisual_Scene_InterStyle3D::New();*/

		/*if constexpr (Dim == 2)
		{
			auto castedInteractorStyle = FrgVisual_Scene_InterStyle2D::SafeDownCast((FrgVisual_Scene_InterStyle2D::SuperClass*)(theInteractorStyle_));
			castedInteractorStyle->SetParentScene(this);
			castedInteractorStyle->SetCurrentRenderer(theRenderer_);
			castedInteractorStyle->SetMouseWheelMotionFactor(0.5);
			theRenderWindowInteractor_->SetInteractorStyle(castedInteractorStyle);
		}
		else if constexpr (Dim == 3)
		{
			auto castedInteractorStyle = FrgVisual_Scene_InterStyle3D::SafeDownCast((FrgVisual_Scene_InterStyle3D::SuperClass*)(theInteractorStyle_));
			castedInteractorStyle->SetParentScene(this);
			castedInteractorStyle->SetCurrentRenderer(theRenderer_);
			castedInteractorStyle->SetMouseWheelMotionFactor(0.5);
			theRenderWindowInteractor_->SetInteractorStyle(castedInteractorStyle);
		}*/

	theAxesActor_ = vtkAxesActor::New();

	theAxesActor_->PickableOff();
	theAxesActor_->SetShaftTypeToLine();
	theAxesActor_->SetOrigin(0.0, 0.0, 0.0);
	theAxesActor_->SetScale(10.0);

	if constexpr (Dim == 2)
	{
		theAxesActor_->SetZAxisLabelText("");
		theAxesActor_->GetZAxisShaftProperty()->SetAmbient(0.0);
		theAxesActor_->GetZAxisTipProperty()->SetAmbient(0.0);
	}

	vtkOrientationMarkerWidget* widget = vtkOrientationMarkerWidget::New();

	widget->SetOutlineColor(0.9300, 0.5700, 0.1300);
	widget->SetOrientationMarker(theAxesActor_);
	widget->SetInteractor(theRenderWindowInteractor_);
	widget->SetViewport(0.0, 0.0, 0.4, 0.4);
	widget->SetEnabled(1);
	widget->InteractiveOff();

	// Create a TextActor
	/*theLogoActor_ = vtkSmartPointer<vtkTextActor>::New();
	theLogoActor_->SetInput("Forg Soft");*/
	vtkTextProperty* tprop = theLogoActor_->GetTextProperty();
	tprop->SetFontFamilyToArial();
	tprop->ShadowOff();

	tprop->SetLineSpacing(1.0);
	tprop->SetFontSize(24);
	//tprop->SetFontFamilyToArial();
	tprop->BoldOn();
	tprop->SetFontFile(":/Fonts/swissek.ttf");
	tprop->ShadowOn();
	tprop->SetColor(0.91, 0.91, 0.91); // (Black) Color

	theLogoActor_->SetDisplayPosition(20, 20);
	theRenderer_->AddActor2D(theLogoActor_);

	theCamera_ = vtkSmartPointer<vtkCamera>::New();
	//theCamera_ = vtkSmartPointer<vtkCameraPass>::New();
	theRenderer_->LightFollowCameraOn();
	theRenderer_->TwoSidedLightingOn();

	/*theRenderer_->SetUseDepthPeeling(true);
	theRenderer_->SetMaximumNumberOfPeels(8);
	theRenderer_->SetOcclusionRatio(0.0);*/

	//theRenderer_->SetUseFXAA(true);
	//theRenderer_->GetFXAAOptions()->SetRelativeContrastThreshold(1.0 / 8.0);
	//theRenderer_->SetUseShadows(true);

	const auto& hideAction = theContextMenuInScene_->GetItem("Hide");
	const auto& unHideAction = theContextMenuInScene_->GetItem("UnHide");

	if (hideAction)
		connect(hideAction, SIGNAL(triggered()), theInteractorStyle_, SLOT(HideActionIsCalledSlot()));
	if (unHideAction)
		connect(unHideAction, SIGNAL(triggered()), theInteractorStyle_, SLOT(UnHideActionIsCalledSlot()));

	if (hideAction)
		connect(hideAction, SIGNAL(triggered()), theInteractorStyle_, SLOT(HideActionIsCalledSlot()));
	if (unHideAction)
		connect(unHideAction, SIGNAL(triggered()), theInteractorStyle_, SLOT(UnHideActionIsCalledSlot()));

	theRenderWindowInteractor_->Initialize();

	theRenderer_->SetActiveCamera(theCamera_);

	theOpenGLWidget_->SetRenderWindow(theRenderWindow_);

	RenderScene(true, true);

	FormToolBar();

	theCameraInterpolator_ = vtkCameraInterpolator::New();

	if (theLights_.empty())
	{
		auto myLight1 = vtkSmartPointer<vtkLight>::New();
		auto myLight2 = vtkSmartPointer<vtkLight>::New();
		auto myLight3 = vtkSmartPointer<vtkLight>::New();
		auto myLight4 = vtkSmartPointer<vtkLight>::New();

		myLight1->SetLightTypeToCameraLight();
		myLight1->SetColor(1.0, 1.0, 1.0);
		myLight1->SetDirectionAngle(45.0, 45.0);
		myLight1->SetIntensity(0.4);
		myLight1->SetConeAngle(30.0);

		myLight2->SetLightTypeToCameraLight();
		myLight2->SetColor(1.0, 1.0, 1.0);
		myLight2->SetDirectionAngle(60.0, -30.0);
		myLight2->SetIntensity(0.4);
		myLight2->SetConeAngle(30.0);

		myLight3->SetLightTypeToCameraLight();
		myLight3->SetColor(1.0, 1.0, 1.0);
		myLight3->SetDirectionAngle(-60.0, -30.0);
		myLight3->SetIntensity(0.4);
		myLight3->SetConeAngle(30.0);

		myLight4->SetLightTypeToCameraLight();
		myLight4->SetColor(1.0, 1.0, 1.0);
		myLight4->SetDirectionAngle(-45.0, 45.0);
		myLight4->SetIntensity(0.4);
		myLight4->SetConeAngle(30.0);

		theLights_.push_back(myLight1);
		theLights_.push_back(myLight2);
		theLights_.push_back(myLight3);
		theLights_.push_back(myLight4);
	}

	for (const auto& light : theLights_)
		GetRenderer()->AddLight(light);

	InitLogoImage();

	if (false)
	{
		auto opaque_sequence = vtkSmartPointer<vtkSequencePass>::New();
		auto passes2 = vtkSmartPointer<vtkRenderPassCollection>::New();
		auto opaque = vtkSmartPointer<vtkOpaquePass>::New();
		auto peeling = vtkSmartPointer<vtkDepthPeelingPass>::New();
		auto translucent = vtkSmartPointer<vtkTranslucentPass>::New();
		peeling->SetTranslucentPass(translucent);
		peeling->SetOcclusionRatio(0.0);
		passes2->AddItem(opaque);
		opaque_sequence->SetPasses(passes2);
		auto opaque_camera_pass = vtkSmartPointer<vtkCameraPass>::New();
		opaque_camera_pass->SetDelegatePass(opaque_sequence);

		auto shadow_baker = vtkSmartPointer<vtkShadowMapBakerPass>::New();
		shadow_baker->SetOpaqueSequence(opaque_camera_pass);

		shadow_baker->SetResolution(std::pow(2.0, 9));
		//shadow_baker->SetPolygonOffsetFactor(3.1);
		//shadow_baker->SetPolygonOffsetUnits(10.0);

		auto shadows = vtkSmartPointer<vtkShadowMapPass>::New();
		shadows->SetShadowMapBakerPass(shadow_baker);
		shadows->SetOpaqueSequence(opaque_sequence);
		shadows->SetShadowMapBakerPass(shadow_baker);

		auto seq = vtkSmartPointer<vtkSequencePass>::New();
		auto passes = vtkSmartPointer<vtkRenderPassCollection>::New();
		seq->SetPasses(passes);
		//passes->AddItem(shadow_baker);
		passes->AddItem(shadows);

		passes->AddItem(peeling);
		passes->AddItem(vtkSmartPointer<vtkVolumetricPass>::New());
		passes->AddItem(vtkSmartPointer<vtkOverlayPass>::New());

		auto cameraP = vtkSmartPointer<vtkCameraPass>::New();
		cameraP->SetDelegatePass(seq);

		auto lights = vtkSmartPointer<vtkLightsPass>::New();

		passes2->AddItem(lights);
		passes->AddItem(lights);

		theRenderer_->SetPass(cameraP);

		theRenderer_->SetOcclusionRatio(0.0);

		theRenderWindow_->OffScreenRenderingOn();
	}

	// Init theLegendScaleActor_
	if constexpr (Dim == 3)
	{
		theRuler_ = vtkSmartPointer<FrgVisual_Scene_Ruler>::New();
		theRuler_->SetParentScene(this);
		theRuler_->TurnOff(false);

		theRenderer_->AddActor2D(theRuler_);
	}

	// Init theAxesCenterWorldActor_
	if constexpr (Dim == 3)
	{
		theAxesCenterWorldActor_ = vtkAxesActor::New();
		theAxesCenterWorldActor_->SetShaftTypeToLine();
		theAxesCenterWorldActor_->SetOrigin(0.0, 0.0, 0.0);
		theAxesCenterWorldActor_->SetXAxisLabelText("");
		theAxesCenterWorldActor_->SetYAxisLabelText("");
		theAxesCenterWorldActor_->SetZAxisLabelText("");
		theAxesCenterWorldActor_->PickableOff();
		theAxesCenterWorldActor_->SetTotalLength(1.0, 1.0, 1.0);
		theAxesCenterWorldActor_->SetShaftTypeToCylinder();

		theRenderer_->AddActor(theAxesCenterWorldActor_);
	}

	theInitiated_ = true;
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene<Dim>::RenderSceneSlot(bool resetCamera, bool resetView)
{
	FrgVisual_Scene_Entity::RenderSceneSlot(resetCamera, resetView);
}

template<int Dim>
ForgVisualLib::FrgVisual_PointActor<Dim>* ForgVisualLib::FrgVisual_Scene<Dim>::AddPoint(
	const ForgBaseLib::FrgBase_Pnt<Dim>& pt,
	bool render
)
{
	/*if (!pt)
	{
		std::exception myException("Pt cannot be null in order to add a point.");
		throw myException;
	}*/

	vtkSmartPointer<FrgVisual_PointActor<Dim>> actor =
		vtkSmartPointer<FrgVisual_PointActor<Dim>>::New();
	//actor->SetRenderer(theRenderer_);

	actor->SetData(pt);
	actor->SetColor(1.0, 0.0, 0.0);
	actor->SetSize(5);

	AddActorToScene(actor);

	if (render)
		RenderScene(false);

	return std::move(actor);
}

template<int Dim>
template<typename>
ForgVisualLib::FrgVisual_PointActor<2>* ForgVisualLib::FrgVisual_Scene<Dim>::AddPoint
(
	double x,
	double y,
	bool render
)
{
	return std::move(AddPoint(ForgBaseLib::FrgBase_Pnt<Dim>(x, y), render));
}

template<int Dim>
template<typename>
ForgVisualLib::FrgVisual_PointActor<3>* ForgVisualLib::FrgVisual_Scene<Dim>::AddPoint
(
	double x,
	double y,
	double z,
	bool render
)
{
	return std::move(AddPoint(ForgBaseLib::FrgBase_Pnt<Dim>(x, y, z), render));
}

template<int Dim>
ForgVisualLib::FrgVisual_PickingPointActor<Dim>* ForgVisualLib::FrgVisual_Scene<Dim>::AddPickingPoint
(
	const ForgBaseLib::FrgBase_Pnt<Dim>& pt,
	bool render
)
{
	auto actor =
		vtkSmartPointer<FrgVisual_PickingPointActor<Dim>>::New();
	//actor->SetRenderer(theRenderer_);

	actor->SetData(pt);

	AddActorToScene(actor);

	if (render)
		RenderScene(false);

	return std::move(actor);
}

template<int Dim>
ForgVisualLib::FrgVisual_LineActor<Dim>* ForgVisualLib::FrgVisual_Scene<Dim>::AddLine
(
	const ForgBaseLib::FrgBase_Pnt<Dim>& P0,
	const ForgBaseLib::FrgBase_Pnt<Dim>& P1,
	bool render
)
{
	/*if (!P0 || !P1)
	{
		std::exception myException("P0 or P1 is null in order to add line.");
		throw myException;
	}*/

	vtkSmartPointer<FrgVisual_LineActor<Dim>> actor =
		vtkSmartPointer<FrgVisual_LineActor<Dim>>::New();
	//actor->SetRenderer(theRenderer_);

	actor->SetData(P0, P1);
	actor->SetLineWidth(1);
	actor->SetColor(1.0, 0.0, 0.0);

	AddActorToScene(actor);

	if (render)
		RenderScene(false);

	return std::move(actor);
}

template<int Dim>
template<typename>
ForgVisualLib::FrgVisual_LineActor<2>* ForgVisualLib::FrgVisual_Scene<Dim>::AddLine
(
	double P0_X,
	double P0_Y,
	double P1_X,
	double P1_Y,
	bool render
)
{
	return std::move(AddLine(ForgBaseLib::FrgBase_Pnt<Dim>(P0_X, P0_Y), ForgBaseLib::FrgBase_Pnt<Dim>(P1_X, P1_Y), render));
}

template<int Dim>
template<typename>
ForgVisualLib::FrgVisual_LineActor<3>* ForgVisualLib::FrgVisual_Scene<Dim>::AddLine
(
	double P0_X,
	double P0_Y,
	double P0_Z,
	double P1_X,
	double P1_Y,
	double P1_Z,
	bool render
)
{
	return std::move(AddLine(ForgBaseLib::FrgBase_Pnt<Dim>(P0_X, P0_Y, P0_Z), ForgBaseLib::FrgBase_Pnt<Dim>(P1_X, P1_Y, P1_Z), render));
}

template<int Dim>
ForgVisualLib::FrgVisual_PolylineActor<Dim>* ForgVisualLib::FrgVisual_Scene<Dim>::AddPolyline
(
	const std::vector<ForgBaseLib::FrgBase_Pnt<Dim>>& pts,
	bool render
)
{
	if (pts.size() == 0)
	{
		std::exception myException("Pts vector is empty in order to add polyline.");
		throw myException;
	}


	vtkSmartPointer<FrgVisual_PolylineActor<Dim>> actor =
		vtkSmartPointer<FrgVisual_PolylineActor<Dim>>::New();
	//actor->SetRenderer(theRenderer_);

	actor->SetData(pts);
	actor->SetColor(1.0, 0.0, 0.0);

	AddActorToScene(actor);

	if (render)
		RenderScene(false);

	return std::move(actor);
}

template<int Dim>
template<typename>
ForgVisualLib::FrgVisual_RectangleActor* ForgVisualLib::FrgVisual_Scene<Dim>::AddRectangle
(
	const ForgBaseLib::FrgBase_Pnt<2>& P0,
	const ForgBaseLib::FrgBase_Pnt<2>& P1,
	bool render
)
{
	return std::move(AddRectangle(P0.X(), P0.Y(), P1.X(), P1.Y()));
}

template<int Dim>
template<typename>
ForgVisualLib::FrgVisual_RectangleActor* ForgVisualLib::FrgVisual_Scene<Dim>::AddRectangle
(
	double P0_X,
	double P0_Y,
	double P1_X,
	double P1_Y,
	bool render
)
{
	// Actor
	auto actor = vtkSmartPointer<FrgVisual_RectangleActor>::New();
	//actor->SetRenderer(theRenderer_);

	actor->SetData(P0_X, P0_Y, P1_X, P1_Y);
	actor->SetColor(1.0, 0.0, 0.0);

	AddActorToScene(actor);

	if (render)
		RenderScene(false);

	return std::move(actor);
}

template<int Dim>
template<typename>
ForgVisualLib::FrgVisual_CircleActor* ForgVisualLib::FrgVisual_Scene<Dim>::AddCircle
(
	const ForgBaseLib::FrgBase_Pnt<2>& center,
	double radius,
	bool render
)
{
	// Actor
	auto actor = vtkSmartPointer<FrgVisual_CircleActor>::New();
	//actor->SetRenderer(theRenderer_);

	actor->SetData(center, radius);
	actor->SetColor(1.0, 0.0, 0.0);

	AddActorToScene(actor);

	if (render)
		RenderScene(false);

	return std::move(actor);
}

template<int Dim>
template<typename>
ForgVisualLib::FrgVisual_CircleActor* ForgVisualLib::FrgVisual_Scene<Dim>::AddCircleUsingCenterAndPointOnCurve
(
	const ForgBaseLib::FrgBase_Pnt<2>& center,
	const ForgBaseLib::FrgBase_Pnt<2>& pointOnCurve,
	bool render
)
{
	// Actor
	auto actor = vtkSmartPointer<FrgVisual_CircleActor>::New();
	//actor->SetRenderer(theRenderer_);

	actor->SetDataCenterAndPointOnCurve(center, pointOnCurve);
	actor->SetColor(1.0, 0.0, 0.0);

	AddActorToScene(actor);

	if (render)
		RenderScene(false);

	return std::move(actor);
}

template<int Dim>
template<typename Triangulation>
void ForgVisualLib::FrgVisual_Scene<Dim>::AddTriangulations
(
	const std::vector<Triangulation>& triangulations,
	bool render
)
{
}

template<int Dim>
ForgVisualLib::FrgVisual_MeshActor<Dim>* ForgVisualLib::FrgVisual_Scene<Dim>::AddTriangulation
(
	const std::vector<ForgBaseLib::FrgBase_Pnt<Dim>>& pts,
	const std::vector<std::tuple<int, int, int>>& connectivity,
	bool render
)
{
	if (pts.size() == 0 || connectivity.size() == 0)
	{
		std::exception myException("pts or connectivity vector is empty in order to add rectangle.");
		throw myException;
	}

	vtkSmartPointer<FrgVisual_MeshActor<Dim>> actor =
		vtkSmartPointer<FrgVisual_MeshActor<Dim>>::New();
	//actor->SetRenderer(theRenderer_);

	actor->SetDataTriangulation(pts, connectivity);

	AddActorToScene(actor);

	if (render)
		RenderScene(false);

	return std::move(actor);
}

template<int Dim>
ForgVisualLib::FrgVisual_MeshPolyhedralActor<Dim>* ForgVisualLib::FrgVisual_Scene<Dim>::AddPolyhedral
(
	const std::vector<ForgBaseLib::FrgBase_Pnt<Dim>>& pts,
	const std::vector<std::vector<int>>& connectivity,
	bool render
)
{
	if (pts.size() == 0 || connectivity.size() == 0)
	{
		std::exception myException("pts or connectivity vector is empty in order to add polyhedral.");
		throw myException;
	}

	vtkSmartPointer<FrgVisual_MeshPolyhedralActor<Dim>> actor =
		vtkSmartPointer<FrgVisual_MeshPolyhedralActor<Dim>>::New();
	//actor->SetRenderer(theRenderer_);

	actor->SetDataPolyhedral(pts, connectivity);

	AddActorToScene(actor);

	if (render)
		RenderScene(false);

	return actor;
}

template<int Dim>
ForgVisualLib::FrgVisual_BSPLineActor<Dim>* ForgVisualLib::FrgVisual_Scene<Dim>::AddBSPLine
(
	const std::vector<ForgBaseLib::FrgBase_Pnt<Dim>>& ctrlPts,
	int degree,
	bool render
)
{
	// Actor
	vtkSmartPointer<FrgVisual_BSPLineActor<Dim>> actor = nullptr;

	try
	{
		actor = vtkSmartPointer<FrgVisual_BSPLineActor<Dim>>::New();

		//actor->SetRenderer(theRenderer_);

		actor->SetData(ctrlPts, degree);
		actor->SetColor(1.0, 0.0, 0.0);

		AddActorToScene(actor);
		//theRenderer_->AddActor(actor->GetCtrlPtsPolyLine());

		if (render)
			RenderScene(false);
	}
	catch (const std::exception& catchedException)
	{
		if (theParentMainWindow_)
			theParentMainWindow_->PrintErrorToConsole(QString(catchedException.what()));

		return nullptr;
	}

	return std::move(actor);
}

template<int Dim>
ForgVisualLib::FrgVisual_BSPLineActor<Dim>* ForgVisualLib::FrgVisual_Scene<Dim>::AddBSPLineThroughPoints
(
	const std::vector<ForgBaseLib::FrgBase_Pnt<Dim>>& pts,
	int degree,
	bool render
)
{
	auto actor = vtkSmartPointer<FrgVisual_BSPLineActor<Dim>>::New();

	//actor->SetRenderer(theRenderer_);

	actor->SetDataInterpolate(pts, degree);
	actor->SetColor(1.0, 0.0, 0.0);

	AddActorToScene(actor);
	//theRenderer_->AddActor(actor->GetCtrlPtsPolyLine());

	if (render)
		RenderScene(false);

	return std::move(actor);
}

template<int Dim>
template<typename>
ForgVisualLib::FrgVisual_BoxActor* ForgVisualLib::FrgVisual_Scene<Dim>::AddBox
(
	const ForgBaseLib::FrgBase_Pnt<3>& P0,
	const ForgBaseLib::FrgBase_Pnt<3>& P1,
	bool render
)
{
	return AddBox(P0.X(), P0.Y(), P0.Z(), P1.X(), P1.Y(), P1.Z(), render);
}

template<int Dim>
template<typename>
ForgVisualLib::FrgVisual_BoxActor* ForgVisualLib::FrgVisual_Scene<Dim>::AddBox
(
	double P0_X,
	double P0_Y,
	double P0_Z,
	double P1_X,
	double P1_Y,
	double P1_Z,
	bool render
)
{
	// Actor
	auto actor = vtkSmartPointer<FrgVisual_BoxActor>::New();
	//actor->SetRenderer(theRenderer_);

	actor->SetData(P0_X, P0_Y, P0_Z, P1_X, P1_Y, P1_Z);
	actor->SetColor(1.0, 1.0, 1.0);

	AddActorToScene(actor);

	if (render)
		RenderScene(false);

	return std::move(actor);
}

template<int Dim>
template<typename>
ForgVisualLib::FrgVisual_CylinderActor* ForgVisualLib::FrgVisual_Scene<Dim>::AddCylinder
(
	const ForgBaseLib::FrgBase_Pnt<3>& Start,
	const ForgBaseLib::FrgBase_Pnt<3>& End,
	double radius,
	bool render
)
{
	if (radius <= 0.0)
	{
		std::exception myException("Radius cannot be smaller than or equal to 0.0");
		throw myException;
	}

	if (Start.IsEqual(End))
	{
		std::exception myException("The cylinder should have a height");
		throw myException;
	}

	// Actor
	auto actor = vtkSmartPointer<FrgVisual_CylinderActor>::New();
	//actor->SetRenderer(theRenderer_);

	actor->SetData(Start, End, radius);
	actor->SetColor(1.0, 1.0, 1.0);

	AddActorToScene(actor);

	if (render)
		RenderScene(false);

	return std::move(actor);
}

template<int Dim>
template<typename>
ForgVisualLib::FrgVisual_CylinderActor* ForgVisualLib::FrgVisual_Scene<Dim>::AddCylinder
(
	double Start_X,
	double Start_Y,
	double Start_Z,
	double End_X,
	double End_Y,
	double End_Z,
	double radius,
	bool render
)
{
	if (radius <= 0.0)
	{
		std::exception myException("Radius cannot be smaller than or equal to 0.0");
		throw myException;
	}

	ForgBaseLib::FrgBase_Pnt<3> Start(Start_X, Start_Y, Start_Z);
	ForgBaseLib::FrgBase_Pnt<3> End(End_X, End_Y, End_Z);

	if (Start == End)
	{
		std::exception myException("The cylinder should have a height");
		throw myException;
	}

	// Actor
	auto actor = vtkSmartPointer<FrgVisual_CylinderActor>::New();
	//actor->SetRenderer(theRenderer_);

	actor->SetData(Start_X, Start_Y, Start_Z, End_X, End_Y, End_Z, radius);
	//actor->SetColor(1.0, 1.0, 1.0);

	AddActorToScene(actor);

	if (render)
		RenderScene(false);

	return std::move(actor);
}

template<int Dim>
template <typename>
ForgVisualLib::FrgVisual_ShapeActor*
ForgVisualLib::FrgVisual_Scene<Dim>::AddShape
(
	const TopoDS_Shape& shape,
	bool render
)
{
	// Actor
	auto actor = vtkSmartPointer<FrgVisual_ShapeActor>::New();
	//actor->SetRenderer(theRenderer_);

	actor->SetData(shape);
	//actor->SetColor(1.0, 1.0, 1.0);

	AddActorToScene(actor);

	if (render)
		RenderScene(false);

	return std::move(actor);
}

template <int Dim>
template <typename>
ForgVisualLib::FrgVisual_SphereActor*
ForgVisualLib::FrgVisual_Scene<Dim>::AddSphere
(
	const ForgBaseLib::FrgBase_Pnt<3>& center,
	const double radius,
	bool render
)
{
	if (radius <= 0.0)
	{
		std::exception myException("Radius cannot be smaller than or equal to 0.0");
		throw myException;
	}

	// Actor
	auto actor = vtkSmartPointer<FrgVisual_SphereActor>::New();

	actor->SetData(center, radius);

	AddActorToScene(actor);

	if (render)
		RenderScene(false);

	return std::move(actor);
}

template<int Dim>
ForgVisualLib::FrgVisual_PlaneActor<Dim>* ForgVisualLib::FrgVisual_Scene<Dim>::AddPlane
(
	const ForgBaseLib::FrgBase_Pnt<Dim>& center,
	const ForgBaseLib::FrgBase_Pnt<Dim>& normal,
	bool render
)
{
	// Actor
	vtkNew<FrgVisual_PlaneActor<Dim>> actor;
	//actor->SetRenderer(theRenderer_);

	actor->SetData(center, normal);

	AddActorToScene(actor);

	if (render)
		RenderScene(false);

	return std::move(actor);
}

template<int Dim>
ForgVisualLib::FrgVisual_PlaneActor<Dim>* ForgVisualLib::FrgVisual_Scene<Dim>::AddPlane
(
	const ForgBaseLib::FrgBase_Pnt<Dim>& origin,
	const ForgBaseLib::FrgBase_Pnt<Dim>& P1,
	const ForgBaseLib::FrgBase_Pnt<Dim>& P2,
	bool render
)
{
	// Actor
	vtkNew<FrgVisual_PlaneActor<Dim>> actor;
	//actor->SetRenderer(theRenderer_);

	actor->SetData(origin, P1, P2);

	AddActorToScene(actor);

	if (render)
		RenderScene(false);

	return std::move(actor);
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene<Dim>::ClearAllPoints()
{
	ClearAllDataType<FrgVisual_PointActor<Dim>>();
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene<Dim>::ClearAllLines()
{
	ClearAllDataType<FrgVisual_LineActor<Dim>>();
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene<Dim>::ClearAllPolylines()
{
	ClearAllDataType<FrgVisual_PolylineActor<Dim>>();
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Scene_Entity)
{
	double redBackground, greenBackground, blueBackground;
	double redBackground2, greenBackground2, blueBackground2;
	bool isGradientBackground;
	double xCameraPosition, yCameraPosition, zCameraPosition;
	double xFocalPoint, yFocalPoint, zFocalPoint;
	double xViewUp, yViewUp, zViewUp;

	theRenderer_->GetBackground(redBackground, greenBackground, blueBackground);
	theRenderer_->GetBackground2(redBackground2, greenBackground2, blueBackground2);
	isGradientBackground = theRenderer_->GetGradientBackground();
	theCamera_->GetPosition(xCameraPosition, yCameraPosition, zCameraPosition);
	theCamera_->GetFocalPoint(xFocalPoint, yFocalPoint, zFocalPoint);
	theCamera_->GetViewUp(xViewUp, yViewUp, zViewUp);

	ar& redBackground;
	ar& greenBackground;
	ar& blueBackground;

	ar& redBackground2;
	ar& greenBackground2;
	ar& blueBackground2;

	ar& isGradientBackground;

	ar& xCameraPosition;
	ar& yCameraPosition;
	ar& zCameraPosition;

	ar& xFocalPoint;
	ar& yFocalPoint;
	ar& zFocalPoint;

	ar& xViewUp;
	ar& yViewUp;
	ar& zViewUp;

	ar& theIsContextMenuExecutable_;

	ar& theMajorGridActor_;
	ar& theMinorGridActor_;
	ar& theMajorGridColor_;
	ar& theMinorGridColor_;

	if (theLogoActor_)
	{
		QString logo = QString::fromStdString(theLogoActor_->GetInput());
		ar& logo;
	}

	int sizeOfLights = theLights_.size();
	ar& sizeOfLights;

	for (const auto& light : theLights_)
	{
		double color[3];
		double position[3];
		double fp[3];
		bool positional;
		double intensity;
		double coneAngle;

		light->GetSpecularColor(color);
		light->GetPosition(position);
		light->GetFocalPoint(fp);
		positional = light->GetPositional();
		intensity = light->GetIntensity();
		coneAngle = light->GetConeAngle();

		ar& color[0];
		ar& color[1];
		ar& color[2];

		ar& position[0];
		ar& position[1];
		ar& position[2];

		ar& fp[0];
		ar& fp[1];
		ar& fp[2];

		ar& positional;

		ar& intensity;

		ar& coneAngle;
	}
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Scene_Entity)
{
	double redBackground, greenBackground, blueBackground;
	double redBackground2, greenBackground2, blueBackground2;
	bool isGradientBackground;
	double xCameraPosition, yCameraPosition, zCameraPosition;
	double xFocalPoint, yFocalPoint, zFocalPoint;
	double xViewUp, yViewUp, zViewUp;

	ar& redBackground;
	ar& greenBackground;
	ar& blueBackground;

	ar& redBackground2;
	ar& greenBackground2;
	ar& blueBackground2;

	ar& isGradientBackground;

	ar& xCameraPosition;
	ar& yCameraPosition;
	ar& zCameraPosition;

	ar& xFocalPoint;
	ar& yFocalPoint;
	ar& zFocalPoint;

	ar& xViewUp;
	ar& yViewUp;
	ar& zViewUp;

	ar& theIsContextMenuExecutable_;

	ar& theMajorGridActor_;
	ar& theMinorGridActor_;
	ar& theMajorGridColor_;
	ar& theMinorGridColor_;

	theRenderer_->SetBackground(redBackground, greenBackground, blueBackground);
	theRenderer_->SetBackground2(redBackground2, greenBackground2, blueBackground2);
	theRenderer_->SetGradientBackground(isGradientBackground);
	theCamera_->SetPosition(xCameraPosition, yCameraPosition, zCameraPosition);
	theCamera_->SetFocalPoint(xFocalPoint, yFocalPoint, zFocalPoint);
	theCamera_->SetViewUp(xViewUp, yViewUp, zViewUp);

	QString logo;
	ar& logo;

	theLogoActor_->SetInput(logo.toStdString().c_str());

	int sizeOfLights;
	ar& sizeOfLights;

	for (int i = 0; i < sizeOfLights; i++)
	{
		double color0;
		double color1;
		double color2;
		double position0;
		double position1;
		double position2;
		double fp0;
		double fp1;
		double fp2;
		bool positional;
		double intensity;
		double coneAngle;

		ar& color0;
		ar& color1;
		ar& color2;

		ar& position0;
		ar& position1;
		ar& position2;

		ar& fp0;
		ar& fp1;
		ar& fp2;

		ar& positional;

		ar& intensity;

		ar& coneAngle;

		auto light = vtkSmartPointer<vtkLight>::New();

		light->SetLightTypeToCameraLight();
		light->SetColor(color0, color1, color2);
		light->SetPosition(position0, position1, position2);
		light->SetFocalPoint(fp0, fp1, fp2);
		light->SetPositional(positional);
		light->SetIntensity(intensity);
		light->SetConeAngle(coneAngle);

		theLights_.push_back(light);
	}

	InitLogoImage();
}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Scene<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_Scene_Entity>(*this);

	double mouseWheelMotionFactor;
	if constexpr (Dim == 2)
		mouseWheelMotionFactor = FrgVisual_Scene_InterStyle2D::SafeDownCast((FrgVisual_Scene_InterStyle2D::SuperClass*)(theInteractorStyle_))->GetMouseWheelMotionFactor();
	else if constexpr (Dim == 3)
		mouseWheelMotionFactor = FrgVisual_Scene_InterStyle3D::SafeDownCast((FrgVisual_Scene_InterStyle3D::SuperClass*)(theInteractorStyle_))->GetMouseWheelMotionFactor();

	ar& mouseWheelMotionFactor;

	ar& theRegistry_;

	/*vtkActorCollection* ac;
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

			bool isIndependent = aPart->IsIndependent();
			ar& isIndependent;

			if (isIndependent)
				ar& aPart;
		}
		else
		{
			isFrgVisualActor = IS_NOT_FRGVISUAL_ACTOR;

			ar& isFrgVisualActor;
		}
	}*/
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Scene<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_Scene_Entity>(*this);

	double mouseWheelMotionFactor;
	ar& mouseWheelMotionFactor;

	if constexpr (Dim == 2)
		FrgVisual_Scene_InterStyle2D::SafeDownCast((FrgVisual_Scene_InterStyle2D::SuperClass*)(theInteractorStyle_))->SetMouseWheelMotionFactor(mouseWheelMotionFactor);
	else if constexpr (Dim == 3)
		FrgVisual_Scene_InterStyle3D::SafeDownCast((FrgVisual_Scene_InterStyle3D::SuperClass*)(theInteractorStyle_))->SetMouseWheelMotionFactor(mouseWheelMotionFactor);

	ar& theRegistry_;

	//int numberOfItems;
	//ar& numberOfItems;

	//for (int i = 0; i < numberOfItems; i++)
	//{
	//	QString isFrgVisualActor;

	//	ar& isFrgVisualActor;

	//	if (isFrgVisualActor == IS_FRGVISUAL_ACTOR)
	//	{
	//		bool isIndependent;
	//		ar& isIndependent;

	//		if (isIndependent)
	//		{
	//			FrgVisual_BaseActor_Entity* aPart;
	//			ar& aPart;

	//			aPart->SetRenderer(theRenderer_);

	//			theRenderer_->AddActor(aPart);
	//		}

	//		/*auto myGrid = dynamic_cast<FrgVisual_GridActor*>(aPart);
	//		if (myGrid)
	//		{
	//			if (myGrid->GetXLine())
	//				theMajorGridActor_ = myGrid;
	//			else
	//				theMinorGridActor_ = myGrid;
	//		}*/
	//	}
	//	else if (isFrgVisualActor == IS_NOT_FRGVISUAL_ACTOR)
	//	{

	//	}
	//}

	int i = 0;
	for (const auto& actor : theRegistry_->GetAllActors())
	{
		actor.second->SetIndex(actor.first);
		AddActorToScene(actor.second);
	}

	//this->RenderScene(false, false);

	if (theRenderWindow_)
		theRenderWindow_->Render();

	/*if (theRenderer_)
		theRenderer_->Render();*/
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Scene_Entity)

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Scene<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Scene<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_Scene<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_Scene<3>;

template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_PointActor<2>* ForgVisualLib::FrgVisual_Scene<2>::AddPoint(double x, double y, bool render);
template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_PointActor<3>* ForgVisualLib::FrgVisual_Scene<3>::AddPoint(double x, double y, double z, bool render);

template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_LineActor<2>* ForgVisualLib::FrgVisual_Scene<2>::AddLine(double P0_X, double P0_Y, double P1_X, double P1_Y, bool render);
template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_LineActor<3>* ForgVisualLib::FrgVisual_Scene<3>::AddLine(double P0_X, double P0_Y, double P0_Z, double P1_X, double P1_Y, double P1_Z, bool render);

template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_RectangleActor* ForgVisualLib::FrgVisual_Scene<2>::AddRectangle(const ForgBaseLib::FrgBase_Pnt<2>& P0, const ForgBaseLib::FrgBase_Pnt<2>& P1, bool render);
template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_RectangleActor* ForgVisualLib::FrgVisual_Scene<2>::AddRectangle(double P0_X, double P0_Y, double P1_X, double P1_Y, bool render);

template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_CircleActor* ForgVisualLib::FrgVisual_Scene<2>::AddCircle(const ForgBaseLib::FrgBase_Pnt<2>& center, double radius, bool render);
template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_CircleActor* ForgVisualLib::FrgVisual_Scene<2>::AddCircleUsingCenterAndPointOnCurve(const ForgBaseLib::FrgBase_Pnt<2>& center, const ForgBaseLib::FrgBase_Pnt<2>& pointOnCurve, bool render);

template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_BoxActor* ForgVisualLib::FrgVisual_Scene<3>::AddBox(const ForgBaseLib::FrgBase_Pnt<3>& P0, const ForgBaseLib::FrgBase_Pnt<3>& P1, bool render);
template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_BoxActor* ForgVisualLib::FrgVisual_Scene<3>::AddBox(double P0_X, double P0_Y, double P0_Z, double P1_X, double P1_Y, double P1_Z, bool render);

template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_CylinderActor* ForgVisualLib::FrgVisual_Scene<3>::AddCylinder(const ForgBaseLib::FrgBase_Pnt<3>& Start, const ForgBaseLib::FrgBase_Pnt<3>& End, double radius, bool render);
template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_CylinderActor* ForgVisualLib::FrgVisual_Scene<3>::AddCylinder(double Start_X, double Start_Y, double Start_Z, double End_X, double End_Y, double End_Z, double radius, bool render);

template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_ShapeActor* ForgVisualLib::FrgVisual_Scene<3>::AddShape(const TopoDS_Shape& shape, bool render);

template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_SphereActor* ForgVisualLib::FrgVisual_Scene<3>::AddSphere(const ForgBaseLib::FrgBase_Pnt<3>& Center, double radius, bool render);

//template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_TextActor<2>* ForgVisualLib::FrgVisual_Scene<2>::AddText(const QString& value, double posx, double posy, bool render);
//template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_TextActor<3>* ForgVisualLib::FrgVisual_Scene<3>::AddText(const QString& value, double posx, double posy, double posz, bool render);