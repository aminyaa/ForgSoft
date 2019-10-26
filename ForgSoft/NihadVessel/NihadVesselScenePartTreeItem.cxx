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

#include <vtkPolyData.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkPolyDataMapper.h>
#include <vtkIdTypeArray.h>
#include <vtkActor.h>
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

std::shared_ptr<AutLib::FastDiscrete_Params> FrgFastParameters = std::make_shared<AutLib::FastDiscrete_Params>();

ForgBaseLib::NihadVesselScenePartTreeItem::NihadVesselScenePartTreeItem
(
	const FrgString& title,
	FrgBaseTreeItem* parent,
	FrgBaseTree* parentTree,
	FrgBaseMainWindow* parentMainwindow
)
	: FrgBaseSceneTreeItem(title, parent, parentTree, parentMainwindow)
{
	SelectObjectsPropertyManager* manager = FrgNew SelectObjectsPropertyManager();

	FrgBaseTreeItem* sharedToParts = ((NihadTree*)parentTree)->GetTreeItem("Parts");

	SelectObjectsPropertyFactory* factory = FrgNew SelectObjectsPropertyFactory(FrgNullPtr, sharedToParts);

	this->GetProperties()->AddProperty<SelectObjectsPropertyManager>("Parts List", manager, factory);
	QtProperty* partsListProperty = manager->addProperty("Parts List");

	QtAbstractPropertyBrowser* browser = new QtTreePropertyBrowser();
	browser->setFactoryForManager(manager, factory);
	browser->addProperty(partsListProperty);
	this->GetProperties()->GetPropertyBrowser() = browser;

	connect(factory, SIGNAL(ObjectsSelectedUpdate(QList<QTreeWidgetItem*>)),
		((NihadTree*)parentTree), SLOT(ObjectsSelectedUpdateInSceneSlot(QList<QTreeWidgetItem*>)));

	/*connect
	(
		this->GetProperties()->GetPropertyManager()
		, SIGNAL(valueChanged(QtProperty*, const QVariant&))
		, this
		, SLOT(GeometryPropertyValueChangedSlot(QtProperty*, const QVariant&))
	);*/
}

void ForgBaseLib::NihadVesselScenePartTreeItem::RenderSceneSlot()
{
	/*for (int i = 0; i < thePartsPointer_.size(); i++)
	{
		if (std::dynamic_pointer_cast<NihadVesselPartTreeItem>(thePartsPointer_.at(i))->GetGeometryPointer())
			(std::dynamic_pointer_cast<NihadVesselPartTreeItem>(thePartsPointer_.at(i)))->GetGeometryPointer()->GetPatch()->Discrete();
	}*/
	//StartScene();

	CreateActor();

	GetLogoActor()->SetInput("Tonb");

	//for (int i = 0; i < theActors_.size(); i++)
	//{
	//	//AddActorToTheRenderer(theActors_.at(i));
	//	GetRenderer()->AddActor(theActors_.at(i));
	//}

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
		/*if (std::dynamic_pointer_cast<NihadVesselPartTreeItem>(thePartsPointer_.at(iParts))->GetGeometryPointer())
		{
			int it = 0;
			for
				(
					TopExp_Explorer Explorer(std::dynamic_pointer_cast<NihadVesselPartTreeItem>(thePartsPointer_.at(iParts))->GetGeometryPointer()->GetPatch()->Entity(), TopAbs_FACE);
					Explorer.More();
					Explorer.Next(), it++
					)
			{
				vtkNew<vtkPolyData> Hull;
				vtkNew<vtkPoints> points;
				vtkNew<vtkCellArray> polys;

				TopLoc_Location Loc;
				Handle(Poly_Triangulation) Triangulation =
					BRep_Tool::Triangulation(TopoDS::Face(Explorer.Current()), Loc);

				if (Triangulation.IsNull()) continue;

				int nbNodes = Triangulation->Nodes().Size();
				int nbElements = Triangulation->Triangles().Size();

				for (auto i = 0ul; i < nbNodes; ++i)
				{
					points->InsertPoint(i, Triangulation->Nodes().Value(i + 1).X(), Triangulation->Nodes().Value(i + 1).Y(), Triangulation->Nodes().Value(i + 1).Z());
				}

				for (int i = 0; i < nbElements; i++)
				{
					int I1, I2, I3;
					Triangulation->Triangles().Value(i + 1).Get(I1, I2, I3);
					std::array<std::array<vtkIdType, 3>, 1> order = { { {I1 - 1,I2 - 1,I3 - 1 } } };
					polys->InsertNextCell(vtkIdType(3), order[0].data());
				}
				Hull->SetPoints(points);
				Hull->SetPolys(polys);

				// Now we'll look at it.
				vtkNew<vtkPolyDataMapper> HullMapper;
				HullMapper->SetInputData(Hull);

				vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();

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

				//auto color = GetInteractorStyle()->GeometryColorRGB;
				//actor->GetProperty()->SetAmbientColor(color.redF(), color.greenF(), color.blueF());
				//actor->GetProperty()->SetDiffuseColor(color.redF(), color.greenF(), color.blueF());
				//actor->GetProperty()->SetSpecularColor(1.0, 1.0, 1.0);
				//actor->GetProperty()->SetSpecular(0.5);
				//actor->GetProperty()->SetDiffuse(0.7);
				//actor->GetProperty()->SetAmbient(0.5);
				//actor->GetProperty()->SetSpecularPower(20.0);
				//actor->GetProperty()->SetOpacity(1.0);

				AddActorToTheRenderer(actor);
			}
		}*/

		if (std::dynamic_pointer_cast<NihadVesselPartTreeItem>(thePartsPointer_.at(iParts))->GetTModel())
		{
			auto model = std::dynamic_pointer_cast<NihadVesselPartTreeItem>(thePartsPointer_.at(iParts))->GetTModel();

			std::vector<std::shared_ptr<AutLib::TModel_Surface>> surfaces;

			model->RetrieveFacesTo(surfaces);
			for (int iSurface = 0; iSurface < surfaces.size(); iSurface++)
			{
				vtkNew<vtkPolyData> Hull;
				vtkNew<vtkPoints> points;
				vtkNew<vtkCellArray> polys;

				AutLib::FastDiscrete::Triangulation(surfaces.at(iSurface)->Face(), *(FrgFastParameters));

				//TopLoc_Location Loc;
				//Handle(Poly_Triangulation) Triangulation = surfaces.at(iSurface)->Triangulation();
				Handle(Poly_Triangulation) Triangulation = AutLib::Cad_Tools::RetrieveTriangulation(surfaces.at(iSurface)->Face());
				//BRep_Tool::Triangulation(surfaces.at(iSurface)->Face(), Loc);

				std::cout << "triangulation Is Null = " << Triangulation.IsNull() << std::endl;

				if (Triangulation.IsNull()) continue;

				int nbNodes = Triangulation->Nodes().Size();
				int nbElements = Triangulation->Triangles().Size();

				for (auto i = 0ul; i < nbNodes; ++i)
				{
					points->InsertPoint(i, Triangulation->Nodes().Value(i + 1).X(), Triangulation->Nodes().Value(i + 1).Y(), Triangulation->Nodes().Value(i + 1).Z());
				}

				for (int i = 0; i < nbElements; i++)
				{
					int I1, I2, I3;
					Triangulation->Triangles().Value(i + 1).Get(I1, I2, I3);
					std::array<std::array<vtkIdType, 3>, 1> order = { { {I1 - 1,I2 - 1,I3 - 1 } } };
					polys->InsertNextCell(vtkIdType(3), order[0].data());
				}
				Hull->SetPoints(points);
				Hull->SetPolys(polys);

				// Now we'll look at it.
				vtkNew<vtkPolyDataMapper> HullMapper;
				HullMapper->SetInputData(Hull);

				vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();

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
			}
		}
	}
}