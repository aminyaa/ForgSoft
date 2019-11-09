#include <NihadVesselScenePartTreeItem.hxx>
#include <NihadVesselGeometryTreeItem.hxx>
#include <NihadVesselPartTreeItem.hxx>
#include <SelectObjectsPropertyManager.hxx>
#include <SelectObjectsPropertyFactory.hxx>
#include <FrgBaseTreeItemProperties.hxx>
#include <FrgBaseInteractorStyle.hxx>
#include <NihadTree.hxx>

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
//#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkCamera.h>
#include <vtkTextActor.h>
#include <vtkProperty.h>

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
	FrgBaseTree* parentTree,
	FrgBaseMainWindow* parentMainwindow,
	FrgBool discreteParameters
)
	: FrgBaseSceneTreeItem(title, parent, parentTree, parentMainwindow)
	, theDiscreteParametersBool_(discreteParameters)
{

}

void ForgBaseLib::NihadVesselScenePartTreeItem::DoAfterConstruct()
{
	SelectObjectsPropertyManager* manager = FrgNew SelectObjectsPropertyManager();

	FrgBaseTreeItem* sharedToParts = (GetParentTree())->GetTreeItem("Parts");

	QtProperty* prop = manager->addProperty("Parts List");

	QtAbstractEditorFactory<SelectObjectsPropertyManager>* factory = FrgNew SelectObjectsPropertyFactory(FrgNullPtr, sharedToParts);

	((QtTreePropertyBrowser*)(GetProperties()->GetPropertyBrowser()))->setFactoryForManager(manager, factory);
	((QtTreePropertyBrowser*)(GetProperties()->GetPropertyBrowser()))->addProperty(prop);
	//this->GetProperties()->AddProperty("Parts List", manager, factory);

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

	connect(factory, SIGNAL(ObjectsSelectedUpdate(QList<QTreeWidgetItem*>)),
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

	GetLogoActor()->SetInput("Tonb");

	Render();

	GetParentMainWindow()->GetTabWidget()->addTab(this, this->text(0));
	GetParentMainWindow()->GetTabWidget()->setCurrentWidget(this);
}

void ForgBaseLib::NihadVesselScenePartTreeItem::AddActorToTheRenderer(vtkSmartPointer<vtkActor> actor)
{
	GetRenderer()->AddActor(actor);
}

void ForgBaseLib::NihadVesselScenePartTreeItem::CreateActor()
{

	for (int iParts = 0; iParts < thePartsPointer_.size(); iParts++)
	{
		if (((NihadVesselPartTreeItem*)(thePartsPointer_.at(iParts)))->GetTModel())
		{
			auto model = ((NihadVesselPartTreeItem*)(thePartsPointer_.at(iParts)))->GetTModel();

			std::vector<std::shared_ptr<AutLib::TModel_Surface>> TModelSurfaces;
			model->RetrieveFacesTo(TModelSurfaces);

			AutLib::FastDiscrete::Triangulation(model->Shape(), *(FrgFastParameters));
			std::vector<Handle(Poly_Triangulation)> Triangulation = AutLib::Cad_Tools::RetrieveTriangulation(model->Shape());

			for (int iSurface = 0; iSurface < Triangulation.size(); iSurface++)
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
				//vtkSmartPointer<NihadVTKActor> actor = vtkSmartPointer<NihadVTKActor>::New();

				//actor->SetMapper(HullMapper);

				// Create a transform to rescale model
				double center[3];
				Hull->GetCenter(center);
				double bounds[6];
				Hull->GetBounds(bounds);
				double maxBound =
					std::max(std::max(bounds[1] - bounds[0], bounds[3] - bounds[2]),
						bounds[5] - bounds[4]);

				auto userTransform = vtkSmartPointer<vtkTransform>::New();
				/*userTransform->Translate(-center[0], -center[1], -center[2]);
				userTransform->Scale(1.0 / maxBound, 1.0 / maxBound, 1.0 / maxBound);*/
				auto transform = vtkSmartPointer<vtkTransformPolyDataFilter>::New();
				transform->SetTransform(userTransform);
				transform->SetInputData(Hull);

				auto triangles = vtkSmartPointer<vtkTriangleFilter>::New();
				triangles->SetInputConnection(transform->GetOutputPort());

				auto norms = vtkSmartPointer<vtkTriangleMeshPointNormals>::New();
				norms->SetInputConnection(triangles->GetOutputPort());

				HullMapper->SetInputConnection(norms->GetOutputPort());
				HullMapper->ScalarVisibilityOff();

				//AddActorToTheRenderer(actor);

				GetActors().push_back(actor);
				GetActors().at(GetActors().size() - 1)->SetMapper(HullMapper);

				AddActorToTheRenderer(actor);

				theActorToTModelEntity_.insert(actor, TModelSurfaces.at(iSurface));

				std::cout << TModelSurfaces.at(iSurface)->Index() << std::endl;
			}
		}
	}
}