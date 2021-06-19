#include <FrgVisual_MeshActor.hxx>

#include <FrgBase_Pnt.hxx>
#include <FrgBase_SerialSpec_Tuple.hxx>

#include <vtkObjectFactory.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkTriangleFilter.h>
#include <vtkTriangleMeshPointNormals.h>
#include <vtkTransform.h>

#include <array>

#include <vtkObjectFactory.h>

template<int Dim>
vtkStandardNewMacro(ForgVisualLib::FrgVisual_MeshActor<Dim>);

template<int Dim>
inline ForgVisualLib::FrgVisual_MeshActor<Dim>::FrgVisual_MeshActor()
{

}

template<int Dim>
inline void ForgVisualLib::FrgVisual_MeshActor<Dim>::SetDataTriangulation
(
	std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> pts,
	std::vector<std::tuple<int, int, int>> connectivity
)
{
	thePoints_.clear();
	theConnectivity_.clear();

	thePoints_ = pts;
	theConnectivity_ = connectivity;

	auto Hull = vtkSmartPointer<vtkPolyData>::New();
	auto points = vtkSmartPointer<vtkPoints>::New();
	auto polys = vtkSmartPointer<vtkCellArray>::New();

	int nbNodes = pts.size();
	int nbElements = connectivity.size();

	for (auto i = 0ul; i < nbNodes; ++i)
	{
		if constexpr (Dim == 2)
			points->InsertPoint(i, pts[i].X(), pts[i].Y(), 0.0);
		else if constexpr (Dim == 3)
			points->InsertPoint(i, pts[i].X(), pts[i].Y(), pts[i].Z());
	}

	for (int i = 0; i < nbElements; i++)
	{
		int I1, I2, I3;
		I1 = std::get<0>(connectivity[i]);
		I2 = std::get<1>(connectivity[i]);
		I3 = std::get<2>(connectivity[i]);

		std::array<std::array<vtkIdType, 3>, 1> order = { { {I1 - 1,I2 - 1,I3 - 1 } } };
		polys->InsertNextCell(vtkIdType(3), order[0].data());
	}
	Hull->SetPoints(points);
	Hull->SetPolys(polys);

	// Now we'll look at it.
	auto HullMapper = vtkSmartPointer<vtkPolyDataMapper>::New();

	HullMapper->SetInputData(Hull);

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

	this->SetMapper(HullMapper);
}

template<int Dim>
ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType ForgVisualLib::FrgVisual_MeshActor<Dim>::GetActorType() const
{
	return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Mesh;
}

template<int Dim>
std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType> ForgVisualLib::FrgVisual_MeshActor<Dim>::GetActorTypes() const
{
	std::vector<ActorType> types;

	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Mesh);

	return types;
}

template<int Dim>
ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension ForgVisualLib::FrgVisual_MeshActor<Dim>::GetActorDimension() const
{
	if constexpr (Dim == 2)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::TwoDim;
	if constexpr (Dim == 3)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::ThreeDim;
}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_MeshActor<Dim>)
{
	ar & boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);

	ar & thePoints_;
	ar & theConnectivity_;
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_MeshActor<Dim>)
{
	ar & boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);

	ar & thePoints_;
	ar & theConnectivity_;

	SetDataTriangulation(thePoints_, theConnectivity_);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_MeshActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_MeshActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_MeshActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_MeshActor<3>;