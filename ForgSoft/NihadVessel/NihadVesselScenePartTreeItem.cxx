#include <NihadVesselScenePartTreeItem.hxx>
#include <NihadVesselGeometryTreeItem.hxx>
#include <NihadVesselPartTreeItem.hxx>

#include <FrgBaseMainWindow.hxx>
#include <FrgBaseTabWidget.hxx>
#include <Leg_Vessel_Nihad2.hxx>

#include <vtkPolyData.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkPolyDataMapper.h>
#include <vtkIdTypeArray.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkCamera.h>
#include <vtkTextActor.h>

#include <TopoDS.hxx>
#include <TopExp_Explorer.hxx>
#include <BRep_Tool.hxx>
#include <array>

#include <vtkProperty.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkTriangleFilter.h>
#include <vtkTriangleMeshPointNormals.h>

ForgBaseLib::NihadVesselScenePartTreeItem::NihadVesselScenePartTreeItem
(
	const FrgString& title,
	FrgBaseTreeItem* parent,
	FrgBaseTree* parentTree,
	FrgBaseMainWindow* parentMainwindow
)
	: FrgBaseSceneTreeItem(title, parent, parentTree, parentMainwindow)
{
	//theOKButton_ = new QPushButton("OK");

	//connect(theOKButton_, SIGNAL(clicked(bool)), this, SLOT(RenderSceneSlot()));

	//GetProperties()->Add
}

void ForgBaseLib::NihadVesselScenePartTreeItem::RenderSceneSlot()
{
	for (int i = 0; i < thePartsPointer_.size(); i++)
	{
		(std::dynamic_pointer_cast<NihadVesselPartTreeItem>(thePartsPointer_.at(i)))->GetGeometryPointer()->GetPatch()->Discrete();
	}
	//StartScene();

	CreateActor();

	GetLogoActor()->SetInput("Nihad");

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

			actor->SetMapper(HullMapper);

			// Create a transform to rescale model
			double center[3];
			Hull->GetCenter(center);
			double bounds[6];
			Hull->GetBounds(bounds);
			double maxBound =
				std::max(std::max(bounds[1] - bounds[0], bounds[3] - bounds[2]),
					bounds[5] - bounds[4]);

			auto userTransform = vtkSmartPointer<vtkTransform>::New();
			userTransform->Translate(-center[0], -center[1], -center[2]);
			userTransform->Scale(1.0 / maxBound, 1.0 / maxBound, 1.0 / maxBound);
			auto transform = vtkSmartPointer<vtkTransformPolyDataFilter>::New();
			transform->SetTransform(userTransform);
			transform->SetInputData(Hull);

			auto triangles = vtkSmartPointer<vtkTriangleFilter>::New();
			triangles->SetInputConnection(transform->GetOutputPort());

			auto norms = vtkSmartPointer<vtkTriangleMeshPointNormals>::New();
			norms->SetInputConnection(triangles->GetOutputPort());

			HullMapper->SetInputConnection(norms->GetOutputPort());
			HullMapper->ScalarVisibilityOff();

			AddActorToTheRenderer(actor);
		}
	}
}