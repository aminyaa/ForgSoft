#include <NihadVesselScenePreviewTreeItem.hxx>
#include <FrgBaseMainWindow.hxx>
#include <FrgBaseTabWidget.hxx>

#include <Entity3d_Triangulation.hxx>

#include <vtkRenderer.h>
#include <vtkPolyData.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkPolyDataMapper.h>
#include <vtkIdTypeArray.h>
#include <vtkActor.h>
#include <vtkTextActor.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkTriangleFilter.h>
#include <vtkTriangleMeshPointNormals.h>
#include <vtkProperty.h>
#include <vtkGenericOpenGLRenderWindow.h>

#include <array>

ForgBaseLib::NihadVesselScenePreviewTreeItem::NihadVesselScenePreviewTreeItem
(
	const FrgString& title,
	FrgBaseTreeItem* parent,
	FrgBaseTree* parentTree,
	FrgBaseMainWindow* parentMainwindow
)
	: NihadVesselScenePartTreeItem(title, parent, parentTree, parentMainwindow)
{
	
}

void ForgBaseLib::NihadVesselScenePreviewTreeItem::AddActorToTheRenderer(vtkSmartPointer<vtkActor> actor)
{
	GetRenderer()->AddActor(actor);
}

void ForgBaseLib::NihadVesselScenePreviewTreeItem::CreateActor()
{
	auto Triangulation = theEntityTriangulation_;

	vtkNew<vtkPolyData> Hull;
	vtkNew<vtkPoints> points;
	vtkNew<vtkCellArray> polys;

	int nbNodes = Triangulation->NbPoints();
	int nbElements = Triangulation->NbConnectivity();

	auto Triangulation_Pts = Triangulation->Points();
	for (auto i = 0ul; i < nbNodes; ++i)
	{
		points->InsertPoint(i, Triangulation_Pts.at(i).X(), Triangulation_Pts.at(i).Y(), Triangulation_Pts.at(i).Z());
	}

	auto Triangulation_Element_Connectivity = theEntityTriangulation_->Connectivity();
	for (int i = 0; i < nbElements; i++)
	{
		int I1, I2, I3;
		I1 = Triangulation_Element_Connectivity.at(i).Value(0);
		I2 = Triangulation_Element_Connectivity.at(i).Value(1);
		I3 = Triangulation_Element_Connectivity.at(i).Value(2);
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

	actor->GetProperty()->EdgeVisibilityOn();
	actor->GetProperty()->SetLineWidth(2.0);

	if (GetRenderer()->GetActors()->GetNumberOfItems() != 0)
	{
		GetRenderer()->RemoveActor(GetActors().at(0));
		GetActors().removeAt(0);
	}

	GetActors().insert(0, actor);
	GetActors().at(0)->SetMapper(HullMapper);

	for (int iActor = 1; iActor < GetActors().size(); iActor++)
	{
		GetActors().at(iActor)->GetProperty()->SetOpacity(0.5);
	}

	AddActorToTheRenderer(actor);
}

void ForgBaseLib::NihadVesselScenePreviewTreeItem::RenderSceneSlot()
{
	static int i = 0;
	//StartScene();

	CreateActor();

	GetLogoActor()->SetInput("Tonb");
	if (i == 0)
	{
		Render();

		GetParentMainWindow()->GetTabWidget()->addTab(this, this->text(0));
		GetParentMainWindow()->GetTabWidget()->setCurrentWidget(this);
		i++;
	}
	else
	{
		//GetRenderer()->ResetCamera();
		GetRenderer()->ResetCameraClippingRange();
		GetRenderWindow()->Render();
	}
}