#include <NihadVesselScenePartTreeItem.hxx>
#include <NihadVesselGeometryTreeItem.hxx>
#include <NihadVesselPartTreeItem.hxx>
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

#include <vtkPolyData.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkPolyDataMapper.h>
#include <vtkIdTypeArray.h>
#include <vtkRenderer.h>
#include <vtkCamera.h>
#include <vtkTextActor.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>

#include <TopoDS.hxx>
#include <TopExp_Explorer.hxx>
#include <BRep_Tool.hxx>
#include <array>

#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkTriangleFilter.h>
#include <vtkTriangleMeshPointNormals.h>

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
	theViewPorts_ = FrgNew ViewPorts(GetParentMainWindow());
	theViewPorts_->SetLogoText("Tonb");

	if (theDiscreteParametersBool_)
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
	}
	else
	{
		CADScene* scene01 = new CADScene(GetParentTree());

		theViewPorts_->AddScene(scene01, Qt::FramelessWindowHint);

		theViewPorts_->tileSubWindows();

		GetParentMainWindow()->GetTabWidget()->addTab(theViewPorts_, this->text(0));
		GetParentMainWindow()->GetTabWidget()->setCurrentWidget(theViewPorts_);
	}
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

void ForgBaseLib::NihadVesselScenePartTreeItem::RenderSceneSlot()
{

	CreateActor();

	theViewPorts_->SetLogoText("Tonb");

	theViewPorts_->RenderScenes();

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
	scene->GetRenderer()->ResetCamera();
	scene->GetRenderWindow()->Render();

	scene = theViewPorts_->GetScenes()[2];
	camera = scene->GetFrgBaseCamera();
	camera->SetPosition(0, 0, -1);
	camera->SetFocalPoint(0, 0, 0);
	camera->SetViewUp(0, -1, 0);
	camera->Azimuth(-180);
	scene->GetRenderer()->ResetCamera();
	scene->GetRenderWindow()->Render();

	//GetParentMainWindow()->GetTabWidget()->addTab(this, this->text(0));
	//GetParentMainWindow()->GetTabWidget()->setCurrentWidget(this);
}

//void ForgBaseLib::NihadVesselScenePartTreeItem::AddActorToTheRenderer(vtkSmartPointer<vtkActor> actor)
//{
//	GetRenderer()->AddActor(actor);
//}

void ForgBaseLib::NihadVesselScenePartTreeItem::CreateActor()
{
	theViewPorts_->ClearScenes();

	//FrgFastParameters->Angle = 0.2;
	//FrgFastParameters->Deflection = 0.01;
	FrgFastParameters->InParallel = true;

	for (int iParts = 0; iParts < thePartsPointer_.size(); iParts++)
	{
		const auto& part = dynamic_cast<NihadVesselPartTreeItem*>(thePartsPointer_.at(iParts));

		theViewPorts_->CreateActor(part);

		/*if (part->GetModel())
		{
			const auto& model = part->GetModel();

			std::vector<std::shared_ptr<AutLib::TModel_Surface>> TModelSurfaces;
			std::vector<std::shared_ptr<AutLib::TModel_Paired>> TModelCurves;
			model->RetrieveFacesTo(TModelSurfaces);
			model->RetrieveSegmentsTo(TModelCurves);

			if (!part->GetIsTriangulated())
			{
				FrgExecuteFunctionInProcess(GetParentMainWindow(), AutLib::FastDiscrete::Triangulation(model->Shape(), *(FrgFastParameters)););
				part->GetIsTriangulated() = FrgTrue;
			}

			std::vector<Handle(Poly_Triangulation)> Triangulation = AutLib::Cad_Tools::RetrieveTriangulation(model->Shape());

			auto part = thePartsPointer_.at(iParts);

			for (int iSurface = 0; iSurface < TModelSurfaces.size(); iSurface++)
			{
				vtkNew<vtkPolyData> Hull;
				vtkNew<vtkPoints> points;
				vtkNew<vtkCellArray> polys;

				if (Triangulation.at(iSurface).IsNull()) continue;

				int nbNodes = Triangulation.at(iSurface)->Nodes().Size();
				int nbElements = Triangulation.at(iSurface)->Triangles().Size();

				for (auto i = 0ul; i < nbNodes; ++i)
				{
					points->InsertPoint(i, Triangulation.at(iSurface)->Nodes().Value(i + 1).X(), Triangulation.at(iSurface)->Nodes().Value(i + 1).Y(), Triangulation.at(iSurface)->Nodes().Value(i + 1).Z());
				}

				for (int i = 0; i < nbElements; i++)
				{
					int I1, I2, I3;
					Triangulation.at(iSurface)->Triangles().Value(i + 1).Get(I1, I2, I3);
					std::array<std::array<vtkIdType, 3>, 1> order = { { {I1 - 1,I2 - 1,I3 - 1 } } };
					polys->InsertNextCell(vtkIdType(3), order[0].data());
				}
				Hull->SetPoints(points);
				Hull->SetPolys(polys);

				// Now we'll look at it.
				vtkNew<vtkPolyDataMapper> HullMapper;
				HullMapper->SetInputData(Hull);

				vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();

				// Create a transform to rescale model
				double center[3];
				Hull->GetCenter(center);
				double bounds[6];
				Hull->GetBounds(bounds);
				double maxBound =
					std::max(std::max(bounds[1] - bounds[0], bounds[3] - bounds[2]),
						bounds[5] - bounds[4]);

				auto userTransform = vtkSmartPointer<vtkTransform>::New();

				auto transform = vtkSmartPointer<vtkTransformPolyDataFilter>::New();
				transform->SetTransform(userTransform);
				transform->SetInputData(Hull);

				auto triangles = vtkSmartPointer<vtkTriangleFilter>::New();
				triangles->SetInputConnection(transform->GetOutputPort());

				auto norms = vtkSmartPointer<vtkTriangleMeshPointNormals>::New();
				norms->SetInputConnection(triangles->GetOutputPort());

				HullMapper->SetInputConnection(norms->GetOutputPort());
				HullMapper->ScalarVisibilityOff();

				GetActors().push_back(actor);
				GetActors().at(GetActors().size() - 1)->SetMapper(HullMapper);

				AddActorToTheRenderer(actor);

				for (int i = 0; i < part->GetSurfaces().size(); i++)
				{
					if (part->GetSurfaces().at(i) == TModelSurfaces.at(iSurface))
					{
						GetActorToPartFeature().insert(actor, part->GetFeatures()->GetSurfacesEntity()->GetFeatureEntity(i));
						GetPartFeatureToActor().insert(part->GetFeatures()->GetSurfacesEntity()->GetFeatureEntity(i), actor);
						auto& scenes = part->GetFeatures()->GetSurfacesEntity()->GetFeatureEntity(i)->GetPointerToScenes();

						if (scenes.isEmpty())
							scenes.push_back(this);
						else
						{
							for (int iScene = 0; iScene < scenes.size(); iScene++)
							{
								if (scenes.at(iScene) == this)
									continue;
								scenes.push_back(this);
							}
						}
					}
				}
			}

			for (int iCurve = 0; iCurve < TModelCurves.size(); iCurve++)
			{

				vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();

				for (int i = 0; i < part->GetCurves().size(); i++)
				{
					if (part->GetCurves().at(i) == TModelCurves.at(iCurve))
					{
						GetActorToPartFeature().insert(actor, part->GetFeatures()->GetCurvesEntity()->GetFeatureEntity(i));
						GetPartFeatureToActor().insert(part->GetFeatures()->GetCurvesEntity()->GetFeatureEntity(i), actor);
						auto scenes = part->GetFeatures()->GetCurvesEntity()->GetFeatureEntity(i)->GetPointerToScenes();

						if (scenes.isEmpty())
							scenes.push_back(this);
						else
						{
							for (int iScene = 0; iScene < scenes.size(); iScene++)
							{
								if (scenes.at(iScene) == this)
									continue;
								scenes.push_back(this);
							}
						}
					}
				}
			}
		}*/
	}
}