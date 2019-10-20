#include <NihadVesselSceneTreeItem.hxx>
#include <FrgBaseTreeItem.hxx>
#include <FrgBaseTree.hxx>
#include <FrgBaseMainWindow.hxx>
#include <FrgBaseTreeItemProperties.hxx>
#include <FrgBaseTabWidget.hxx>
#include <NihadVesselGeometryTreeItem.hxx>
#include <NihadVesselPartTreeItem.hxx>

#include <array>

#include <NihadTree.hxx>
#include <Leg_Vessel_Nihad2.hxx>

#include <QtWidgets/QPushButton>

#include <TopoDS.hxx>
#include <TopExp_Explorer.hxx>
#include <BRep_Tool.hxx>

#include <vtkPolyData.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkPolyDataMapper.h>
#include <vtkIdTypeArray.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkCamera.h>
#include <vtkTextActor.h>

#include <vector>

#include <Poly_Triangulation.hxx>

#include <vtkActor.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <QVTKInteractor.h>

class VTK_Helper {
public:
	VTK_Helper();
	vtkSmartPointer<vtkPolyData> cascade_to_vtk(const std::vector<Handle(Poly_Triangulation)>& cascade_data);
	void colour_original_faces();
private:
	std::vector<int> break_points;
	vtkSmartPointer<vtkPolyData> poly_data;
};

void normalise_vtk_actor(vtkSmartPointer<vtkActor> actor);

//std
#include <map>
#include <set>
#include <utility>

// OpenCASCADE
#include <gp_Pnt.hxx>
#include <Poly_Triangle.hxx>
#include <TColgp_Array1OfPnt.hxx>

//  VTK
#include <vtkCellArray.h>
#include <vtkCellData.h>
#include <vtkDataSetAttributes.h>
#include <vtkUnsignedCharArray.h>
#include <vtkTriangle.h>

struct vertex {
	double x;
	double y;
	double z;

	vertex(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {
	}

	bool operator<(const vertex& other) const
	{
		if (x != other.x)
			return (x < other.x);

		if (y != other.y)
			return (y < other.y);

		return (z < other.z);
	}
};

vtkSmartPointer<vtkPolyData> VTK_Helper::cascade_to_vtk(const std::vector<Handle(Poly_Triangulation)>& cascade_data) {
	int point_counter = 0; // fix this
	int face_counter = 0;

	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
	vtkSmartPointer<vtkCellArray> cells = vtkSmartPointer<vtkCellArray>::New();

	std::map<vertex, int> point_map;
	std::map<int, std::vector< vtkSmartPointer<vtkTriangle> > > faces;
	for (std::vector<Handle(Poly_Triangulation)>::const_iterator it = cascade_data.begin();
		it != cascade_data.end();
		++it) {
		std::vector< vtkSmartPointer<vtkTriangle> > triangles;

		//Nodes are 1 indexed WTF?! why?
		for (int i = 1; i <= (*it)->NbNodes(); i++) {
			gp_Pnt point = (*it)->Nodes().Value(i);
			vertex p(point.X(), point.Y(), point.Z());
			if (!point_map.count(p)) {
				point_map.insert(std::make_pair(p, point_counter));
				point_counter++;
				points->InsertNextPoint(p.x, p.y, p.z);
			}
		}


		//as are triangles
		for (int i = 1; i <= (*it)->NbTriangles(); i++) {
			vtkSmartPointer<vtkTriangle> triangle = vtkSmartPointer<vtkTriangle>::New();
			Poly_Triangle pt = (*it)->Triangles().Value(i);
			int index0, index1, index2;
			pt.Get(index0, index1, index2);

			gp_Pnt point0 = (*it)->Nodes().Value(index0);
			vertex p0(point0.X(), point0.Y(), point0.Z());
			index0 = point_map[p0];
			triangle->GetPointIds()->SetId(0, index0);

			gp_Pnt point1 = (*it)->Nodes().Value(index1);
			vertex p1(point1.X(), point1.Y(), point1.Z());
			index1 = point_map[p1];
			triangle->GetPointIds()->SetId(1, index1);

			gp_Pnt point2 = (*it)->Nodes().Value(index2);
			vertex p2(point2.X(), point2.Y(), point2.Z());
			index2 = point_map[p2];
			triangle->GetPointIds()->SetId(2, index2);
			triangles.push_back(triangle);
			cells->InsertNextCell(triangle);
		}
		faces.insert(std::make_pair(face_counter, triangles));
		face_counter++;
		break_points.push_back((*it)->NbTriangles());
	}
	poly_data->SetPoints(points);
	poly_data->SetPolys(cells);
	return poly_data;
}

VTK_Helper::VTK_Helper() {
	poly_data = vtkSmartPointer<vtkPolyData>::New();
}

void VTK_Helper::colour_original_faces() {
	//Colour Faces
	vtkSmartPointer<vtkUnsignedCharArray> colours = vtkSmartPointer<vtkUnsignedCharArray>::New();
	colours->SetNumberOfComponents(3);
	colours->SetName("Colours");
	for (std::vector<int>::iterator it = break_points.begin(); it != break_points.end(); ++it) {
		unsigned char red = rand() % 256;
		unsigned char green = rand() % 256;
		unsigned char blue = rand() % 256;
		for (int i = 0; i < *it; i++) {
			colours->InsertNextTuple3(red, green, blue);
		}
	}
	//poly_data->GetCellData()->SetScalars(colours);
}

void normalise_vtk_actor(vtkSmartPointer<vtkActor> actor) {
	double* bounds;
	bounds = actor->GetBounds();
	double largest = 0;
	for (int i = 0; i < 3; i++) {
		double size = fabs(bounds[i * 2 + 1] - bounds[i * 2]);
		largest = std::max(largest, size);
	}
	actor->SetScale(1 / largest);
}

#include <Poly_Triangulation.hxx>
#include <TopoDS_Shape.hxx>

std::vector<Handle(Poly_Triangulation)> triangulate(const TopoDS_Shape& shape);

#include <BRepMesh.hxx>
#include <BRep_Tool.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Face.hxx>
#include <TopExp_Explorer.hxx>
#include <BRepMesh_IncrementalMesh.hxx>

std::vector<Handle(Poly_Triangulation)> triangulate(const TopoDS_Shape& shape) {
	BRepMesh_IncrementalMesh(shape, 0.001);
	std::vector<Handle(Poly_Triangulation)> triangulated_faces;
	for (TopExp_Explorer ex(shape, TopAbs_FACE); ex.More(); ex.Next()) {
		TopoDS_Face face = TopoDS::Face(ex.Current());
		TopLoc_Location location;
		Handle(Poly_Triangulation) face_triangles = BRep_Tool::Triangulation(face, location);
		triangulated_faces.push_back(face_triangles);
	}
	return triangulated_faces;
}

ForgBaseLib::NihadVesselSceneTreeItem::NihadVesselSceneTreeItem
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

void ForgBaseLib::NihadVesselSceneTreeItem::RenderSceneSlot()
{
	for (int i = 0; i < thePartsPointer_.size(); i++)
	{
		thePartsPointer_.at(i)->GetGeometryPointer()->GetPatch()->Discrete();
	}
	//StartScene();

	CreateActor();

	GetLogoActor()->SetInput("Nihad");

	Render();

	GetParentMainWindow()->GetTabWidget()->addTab(this, this->text(0));
	GetParentMainWindow()->GetTabWidget()->setCurrentWidget(this);
}

void ForgBaseLib::NihadVesselSceneTreeItem::AddActorToTheRenderer(vtkSmartPointer<vtkActor> actor)
{
	GetRenderer()->AddActor(actor);
}

#include <vtkProperty.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkTriangleFilter.h>
#include <vtkTriangleMeshPointNormals.h>

void ForgBaseLib::NihadVesselSceneTreeItem::CreateActor()
{

	for (int iParts = 0; iParts < thePartsPointer_.size(); iParts++)
	{
		int it = 0;
		for
			(
				TopExp_Explorer Explorer(thePartsPointer_.at(iParts)->GetGeometryPointer()->GetPatch()->Entity(), TopAbs_FACE);
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

void ForgBaseLib::NihadVesselSceneTreeItem::CreateActor2()
{
	VTK_Helper helper;
	vtkSmartPointer<vtkPolyData> polydata = helper.cascade_to_vtk(triangulate(thePartsPointer_.at(0)->GetGeometryPointer()->GetPatch()->Entity()));

	helper.colour_original_faces();

	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputData(polydata);
	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();

	// Create a transform to rescale model
	double center[3];
	polydata->GetCenter(center);
	double bounds[6];
	polydata->GetBounds(bounds);
	double maxBound =
		std::max(std::max(bounds[1] - bounds[0], bounds[3] - bounds[2]),
			bounds[5] - bounds[4]);

	auto userTransform = vtkSmartPointer<vtkTransform>::New();
	userTransform->Translate(-center[0], -center[1], -center[2]);
	userTransform->Scale(1.0 / maxBound, 1.0 / maxBound, 1.0 / maxBound);
	auto transform = vtkSmartPointer<vtkTransformPolyDataFilter>::New();
	transform->SetTransform(userTransform);
	transform->SetInputData(polydata);

	auto triangles = vtkSmartPointer<vtkTriangleFilter>::New();
	triangles->SetInputConnection(transform->GetOutputPort());

	auto norms = vtkSmartPointer<vtkTriangleMeshPointNormals>::New();
	norms->SetInputConnection(triangles->GetOutputPort());

	mapper->SetInputConnection(norms->GetOutputPort());
	mapper->ScalarVisibilityOff();

	actor->SetMapper(mapper);
	actor->SetPosition(2 * (1 % 5), -floor(1 / 5), 0);
	normalise_vtk_actor(actor);
	GetRenderer()->AddActor(actor);
	GetRenderer()->ResetCamera();
}