#include <FrgVisual_MeshPolyhedralActor.hxx>
#include <FrgVisual_ContoursLUTable_Rainbow.hxx>

#include <FrgBase_Pnt.hxx>
#include <FrgBase_SerialSpec_Tuple.hxx>

#include <vtkObjectFactory.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkPolyDataNormals.h>
#include <vtkTransform.h>
#include <vtkLookupTable.h>
#include <vtkUnsignedCharArray.h>
#include <vtkPointData.h>
#include <vtkCellData.h>
#include <vtkDoubleArray.h>
#include <vtkElevationFilter.h>

#include <set>
#include <array>

#include <vtkObjectFactory.h>

template<int Dim>
vtkStandardNewMacro(ForgVisualLib::FrgVisual_MeshPolyhedralActor<Dim>);

template<int Dim>
inline ForgVisualLib::FrgVisual_MeshPolyhedralActor<Dim>::FrgVisual_MeshPolyhedralActor()
{

}

template<int Dim>
inline void ForgVisualLib::FrgVisual_MeshPolyhedralActor<Dim>::SetDataPolyhedral
(
	const std::vector<ForgBaseLib::FrgBase_Pnt<Dim>>& pts,
	const std::vector<std::vector<int>>& connectivity
)
{
	thePoints_.clear();
	theConnectivity_.clear();

	if (pts.empty() || connectivity.empty())
		return;

	thePoints_ = pts;
	theConnectivity_ = connectivity;

	thePolyData_ = vtkSmartPointer<vtkPolyData>::New();
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
		const auto nPoly = connectivity[i].size();
		if (nPoly == 0)
			continue;

		std::vector<vtkIdType> datas;
		for (const auto& xin : connectivity[i])
			datas.push_back(vtkIdType(xin - 1));

		vtkIdType* data = &datas[0];

		polys->InsertNextCell(vtkIdType(nPoly), data);
	}

	thePolyData_->SetPoints(points);
	thePolyData_->SetPolys(polys);

	// Now we'll look at it.
	auto HullMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	this->SetMapper(HullMapper);

	//HullMapper->SetInputData(thePolyData_);
	/*vtkSmartPointer<vtkButterflySubdivisionFilter> butterflyFilter = vtkSmartPointer<vtkButterflySubdivisionFilter>::New();
	butterflyFilter->SetInputData(thePolyData_);
	butterflyFilter->SetNumberOfSubdivisions(3);
	butterflyFilter->Update();*/

	//HullMapper->SetInputData(butterflyFilter->GetOutput());

	// Create a transform to rescale model
	auto userTransform = vtkSmartPointer<vtkTransform>::New();
	auto transform = vtkSmartPointer<vtkTransformPolyDataFilter>::New();
	transform->SetTransform(userTransform);
	transform->SetInputData(thePolyData_);
	//transform->SetInputData(butterflyFilter->GetOutput());

	auto norms = vtkSmartPointer<vtkPolyDataNormals>::New();
	norms->SetInputConnection(transform->GetOutputPort());

	HullMapper->SetInputConnection(norms->GetOutputPort());

	auto lut = vtkSmartPointer<FrgVisual_ContoursLUTable_Rainbow>::New();
	lut->SetRampToSQRT();
	lut->SetRange(0.0, 1.0);

	SetLookUpTable(lut);
	SetScalarModeToUsePointData();

	SetScalarVisibility(false);

	HullMapper->SetUseLookupTableScalarRange(true);
	HullMapper->InterpolateScalarsBeforeMappingOff();
	HullMapper->SetColorModeToDirectScalars();
	HullMapper->SelectColorArray("Colors");

	/*vtkSmartPointer<vtkElevationFilter> elFilter = vtkSmartPointer<vtkElevationFilter>::New();
	elFilter->SetInputConnection(norms->GetOutputPort());
	elFilter->SetLowPoint(0.0, 0.0, 0.0);
	elFilter->SetHighPoint(0.0, 1.99, 0.0);
	elFilter->SetScalarRange(0.0, 1.99);
	elFilter->Update();*/
	
	//HullMapper->SetInputConnection(elFilter->GetOutputPort());

	// =======================================================
	//AdjustEdgeCurvatures(thePolyData_, "ABC", 1.0e-08);

	/*std::cout << "Is Here 0\n";
	auto arrayName = "ABC";
	std::cout << "Is Here 1\n";
	thePolyData_->GetPointData()->SetActiveScalars(arrayName);
	std::cout << "Is Here 2\n";
	auto array = thePolyData_->GetPointData()->GetAbstractArray(arrayName);
	std::cout << "Is Here 3\n";
	std::vector<double> curvatures;
	std::cout << "Is Here 4\n";
	for (vtkIdType i = 0; i < thePolyData_->GetNumberOfPoints(); ++i)
	{
	std::cout << "Is Here 5\n";
		curvatures.push_back(array->GetVariantValue(i).ToDouble());
	std::cout << "Is Here 6\n";
	}
	std::cout << "Is Here 7\n";
	vtkNew<vtkDoubleArray> adjustedCurvatures;
	std::cout << "Is Here 8\n";
	adjustedCurvatures->SetName(arrayName);
	std::cout << "Is Here 9\n";
	for (auto curvature : curvatures)
	{
	std::cout << "Is Here 10\n";
		adjustedCurvatures->InsertNextTuple1(curvature);
	std::cout << "Is Here 11\n";
	}
	std::cout << "Is Here 12\n";
	thePolyData_->GetPointData()->AddArray(adjustedCurvatures);
	std::cout << "Is Here 13\n";
	thePolyData_->GetPointData()->SetActiveScalars(arrayName);
	std::cout << "Is Here 14\n";*/


	//// Generate the colors for each point based on the color map
	//vtkSmartPointer<vtkUnsignedCharArray> colors =
	//	vtkSmartPointer<vtkUnsignedCharArray>::New();
	//colors->SetNumberOfComponents(3);
	//colors->SetName("Colors");

	//double bounds[6];
	//thePolyData_->GetBounds(bounds);

	//double l = bounds[1] - bounds[0];

	//double dxx = 1.0 / (thePolyData_->GetNumberOfCells() - 1);
	//for (int i = 0; i < thePolyData_->GetNumberOfCells(); i++)
	//{
	//	auto cell = thePolyData_->GetCell(i);
	//	auto myPoints = cell->GetPoints();

	//	double* Center;
	//	Center = myPoints->GetPoint(0);

	//	double value = (Center[0] + bounds[0]) / l;

	//	double dcolor[3];
	//	lut->GetColor(value, dcolor);
	//	unsigned char color[3];
	//	for (unsigned int j = 0; j < 3; j++)
	//	{
	//		color[j] = static_cast<unsigned char>(255.0 * dcolor[j]);
	//	}

	//	colors->InsertNextTypedTuple(color);
	//}

	//HullMapper->SetScalarModeToUseCellData();
	//thePolyData_->GetCellData()->SetScalars(colors);
}

template<int Dim>
ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType ForgVisualLib::FrgVisual_MeshPolyhedralActor<Dim>::GetActorType() const
{
	return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Mesh;
}

template<int Dim>
std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType> ForgVisualLib::FrgVisual_MeshPolyhedralActor<Dim>::GetActorTypes() const
{
	std::vector<ActorType> types;

	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Mesh);
	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Polyhedral);

	return types;
}

template<int Dim>
ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension ForgVisualLib::FrgVisual_MeshPolyhedralActor<Dim>::GetActorDimension() const
{
	if constexpr (Dim == 2)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::TwoDim;
	if constexpr (Dim == 3)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::ThreeDim;
}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_MeshPolyhedralActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);

	VOID_CAST_REGISTER(ForgVisualLib::FrgVisual_MeshPolyhedralActor<Dim>, ForgVisualLib::FrgVisual_MeshActor<Dim>);

	ar& thePoints_;
	ar& theConnectivity_;
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_MeshPolyhedralActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);

	VOID_CAST_REGISTER(ForgVisualLib::FrgVisual_MeshPolyhedralActor<Dim>, ForgVisualLib::FrgVisual_MeshActor<Dim>);

	std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> pts;
	std::vector<std::vector<int>> connectivity;

	ar& pts;
	ar& connectivity;

	SetDataPolyhedral(pts, connectivity);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_MeshPolyhedralActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_MeshPolyhedralActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_MeshPolyhedralActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_MeshPolyhedralActor<3>;