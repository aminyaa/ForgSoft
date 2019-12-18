#include <NihadVesselScenePartTreeItem.hxx>
#include <NihadVesselGeometryTreeItem.hxx>
//#include <NihadVesselPartTreeItem.hxx>
#include <FrgBaseCADPart.hxx>
#include <SelectObjectsPropertyManager.hxx>
#include <SelectObjectsPropertyFactory.hxx>
#include <FrgBaseTreeItemProperties.hxx>
#include <FrgBaseInteractorStyle.hxx>
#include <FrgBaseCADPartFeatures.hxx>
#include <NihadTree.hxx>
#include <FrgBaseGlobalsThread.hxx>
#include <CADScene.hxx>

#include <FrgBaseMainWindow.hxx>
#include <FrgBaseTabWidget.hxx>
#include <Leg_Vessel_Nihad2.hxx>
#include <Cad3d_TModel.hxx>
#include <TModel_Surface.hxx>
#include <Cad_Tools.hxx>
#include <FastDiscrete.hxx>
#include <FastDiscrete_Params.hxx>
#include <NihadVTKActor.hxx>

#include <QtDoublePropertyManager>
#include <QtDoubleSpinBoxFactory>
#include <ViewPorts.hxx>
#include <QtWidgets/QMdiSubWindow>

std::shared_ptr<AutLib::FastDiscrete_Params> FrgFastParameters = std::make_shared<AutLib::FastDiscrete_Params>();

#define FrgFastParameters_AngleID "FrgFastParameters_Angle"
#define FrgFastParameters_DeflectionID "FrgFastParameters_Deflection"
#define FrgFastParameters_MinSizeID "FrgFastParameters_MinSize"
#define FrgFastParameters_InParallelID "FrgFastParameters_InParallel"
#define FrgFastParameters_RelativeID "FrgFastParameters_Relative"
#define FrgFastParameters_AdaptiveMinID "FrgFastParameters_AdaptiveMin"
#define FrgFastParameters_InternalVerticesModeID "FrgFastParameters_InternalVerticesMode"
#define FrgFastParameters_ControlSurfaceDeflectionID "FrgFastParameters_ControlSurfaceDeflection"

ForgBaseLib::NihadVesselScenePartTreeItem::NihadVesselScenePartTreeItem
(
	const FrgString& title,
	FrgBaseTreeItem* parent,
	FrgBool discreteParameters
)
	: FrgBase_CADScene_TreeItem(title, parent)
	, theDiscreteParametersBool_(discreteParameters)
{
	theViewPorts_ = FrgNew ViewPorts(this, GetParentMainWindow());
	theViewPorts_->SetLogoText("Tonb");

	/*if (theDiscreteParametersBool_)
	{
		CADScene* scene01 = new CADScene(GetParentTree());
		CADScene* scene02 = new CADScene(GetParentTree());
		CADScene* scene03 = new CADScene(GetParentTree());
		CADScene* scene04 = new CADScene(GetParentTree());

		theViewPorts_->AddScene(scene01, Qt::WindowMaximizeButtonHint);
		theViewPorts_->AddScene(scene02, Qt::WindowMaximizeButtonHint);
		theViewPorts_->AddScene(scene03, Qt::WindowMaximizeButtonHint);
		theViewPorts_->AddScene(scene04, Qt::WindowMaximizeButtonHint);

		theViewPorts_->tileSubWindows();

		GetParentMainWindow()->GetTabWidget()->addTab(theViewPorts_, this->text(0));
		GetParentMainWindow()->GetTabWidget()->setCurrentWidget(theViewPorts_);

		theViewPorts_->subWindowList()[0]->setWindowTitle("Perspective");
		theViewPorts_->subWindowList()[1]->setWindowTitle("Front");
		theViewPorts_->subWindowList()[2]->setWindowTitle("Top");
		theViewPorts_->subWindowList()[3]->setWindowTitle("Side");
	}*/
	//else
	//{

		/*GetParentMainWindow()->GetTabWidget()->addTab(theViewPorts_, this->text(0));
		GetParentMainWindow()->GetTabWidget()->setCurrentWidget(theViewPorts_);*/
	//}
}

void ForgBaseLib::NihadVesselScenePartTreeItem::DoAfterConstruct()
{
	SelectObjectsPropertyManager* manager = FrgNew SelectObjectsPropertyManager();

	FrgBaseTreeItem* sharedToParts = (GetParentTree())->GetTreeItem("Parts");

	QtProperty* prop = manager->addProperty("Parts List");

	QtAbstractEditorFactory<SelectObjectsPropertyManager>* factory = FrgNew SelectObjectsPropertyFactory(FrgNullPtr, sharedToParts);

	((QtTreePropertyBrowser*)(GetProperties()->GetPropertyBrowser()))->setFactoryForManager(manager, factory);
	((QtTreePropertyBrowser*)(GetProperties()->GetPropertyBrowser()))->addProperty(prop);

	QtAbstractPropertyBrowser* browser = new QtTreePropertyBrowser();
	browser->setFactoryForManager(manager, factory);
	browser->addProperty(prop);
	this->GetProperties()->GetPropertyBrowser() = browser;
	//browser->show();
	//this->GetProperties()->GetPropertyBrowser() = browser;

	/*QtDoublePropertyManager* undecoratedManager = new QtDoublePropertyManager();
	QtProperty* undecoratedProperty = undecoratedManager->addProperty("Undecorated");
	undecoratedManager->setValue(undecoratedProperty, 123.45);

	QtDoubleSpinBoxFactory* undecoratedFactory = new QtDoubleSpinBoxFactory();

	((QtTreePropertyBrowser*)(GetProperties()->GetPropertyBrowser()))->setFactoryForManager(undecoratedManager, undecoratedFactory);
	((QtTreePropertyBrowser*)(GetProperties()->GetPropertyBrowser()))->addProperty(undecoratedProperty);*/

	QObject::connect(factory, SIGNAL(ObjectsSelectedUpdate(QList<QTreeWidgetItem*>)),
		(GetParentTree()), SLOT(ObjectsSelectedUpdateInSceneSlot(QList<QTreeWidgetItem*>)));

	if (theDiscreteParametersBool_)
	{
		this->GetProperties()->AddTopProperty("Discrete parameters");

		this->GetProperties()->AddProperty<double>("Discrete parameters", "Angle", FrgFastParameters->Angle, FrgFastParameters_AngleID, 0.01, 360.0, 1.0);
		this->GetProperties()->AddProperty<double>("Discrete parameters", "Deflection", FrgFastParameters->Deflection, FrgFastParameters_DeflectionID);
		this->GetProperties()->AddProperty<double>("Discrete parameters", "MinSize", FrgFastParameters->MinSize, FrgFastParameters_MinSizeID);
		this->GetProperties()->AddProperty<bool>("Discrete parameters", "InParallel", FrgFastParameters->InParallel, FrgFastParameters_InParallelID);
		this->GetProperties()->AddProperty<bool>("Discrete parameters", "Relative", FrgFastParameters->Relative, FrgFastParameters_RelativeID);
		this->GetProperties()->AddProperty<bool>("Discrete parameters", "AdaptiveMin", FrgFastParameters->AdaptiveMin, FrgFastParameters_AdaptiveMinID);
		this->GetProperties()->AddProperty<bool>("Discrete parameters", "InternalVerticesMode", FrgFastParameters->InternalVerticesMode, FrgFastParameters_InternalVerticesModeID);
		this->GetProperties()->AddProperty<bool>("Discrete parameters", "ControlSurfaceDeflection", FrgFastParameters->ControlSurfaceDeflection, FrgFastParameters_ControlSurfaceDeflectionID);
	}
}

void ForgBaseLib::NihadVesselScenePartTreeItem::RenderSceneSlot(FrgBool resetCamera)
{

	CreateActor();

	theViewPorts_->SetLogoText("TONB");

	theViewPorts_->RenderScenes(resetCamera);

	/*if (theViewPorts_->GetScenes().size() > 1)
	{
		auto scene = theViewPorts_->GetScenes()[0];
		auto camera = scene->GetFrgBaseCamera();
		camera->SetPosition(1, 0, 1);
		camera->SetFocalPoint(0, 0, 0);
		camera->SetViewUp(0, 0, 1);
		camera->Azimuth(-50);
		scene->GetRenderer()->ResetCamera();
		scene->GetRenderWindow()->Render();

		scene = theViewPorts_->GetScenes()[1];
		camera = scene->GetFrgBaseCamera();
		camera->SetPosition(1, 0, 0);
		camera->SetFocalPoint(0, 0, 0);
		camera->SetViewUp(0, 0, 1);
		camera->Azimuth(-180);
		camera->ParallelProjectionOn();
		scene->GetRenderer()->ResetCamera();
		scene->GetRenderWindow()->Render();

		scene = theViewPorts_->GetScenes()[2];
		camera = scene->GetFrgBaseCamera();
		camera->SetPosition(0, 0, -1);
		camera->SetFocalPoint(0, 0, 0);
		camera->SetViewUp(0, -1, 0);
		camera->Azimuth(-180);
		camera->ParallelProjectionOn();
		scene->GetRenderer()->ResetCamera();
		scene->GetRenderWindow()->Render();

		theViewPorts_->GetScenes()[3]->GetFrgBaseCamera()->ParallelProjectionOn();
	}*/
}

void ForgBaseLib::NihadVesselScenePartTreeItem::CreateActor()
{
	theViewPorts_->ClearScenes();

	//FrgFastParameters->Angle = 0.2;
	//FrgFastParameters->Deflection = 0.01;
	FrgFastParameters->InParallel = true;

	for (int iParts = 0; iParts < thePartsPointer_.size(); iParts++)
	{
		const auto& part = dynamic_cast<FrgBaseCADPart_Entity*>(thePartsPointer_.at(iParts));

		if(part)
			theViewPorts_->CreateActor(part);
	}

	for (auto scene : theViewPorts_->GetScenes())
	{
		auto action = scene->GetActionItemInScene("Draw Grid");
		if (action)
		{
			if(action->isChecked())
				scene->DrawGrid(10, 5);
		}
	}
}