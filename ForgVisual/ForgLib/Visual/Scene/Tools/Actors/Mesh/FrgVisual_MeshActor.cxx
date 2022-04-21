#include <FrgVisual_MeshActor.hxx>
#include <FrgViusal_LookUpTable.hxx>
#include <FrgVisual_ContoursLUTable_Rainbow.hxx>

#include <FrgBase_Pnt.hxx>
#include <FrgBase_SerialSpec_Tuple.hxx>

#include <vtkObjectFactory.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkTriangleFilter.h>
#include <vtkTriangleMeshPointNormals.h>
#include <vtkTransform.h>
#include <vtkProperty.h>
#include <vtkUnsignedCharArray.h>
#include <vtkPointData.h>
#include <vtkCellData.h>
#include <vtkCellDataToPointData.h>
#include <vtkDoubleArray.h>

#include <array>

#include <vtkObjectFactory.h>

#define SCALARMODE_POINTDATA VTK_SCALAR_MODE_USE_POINT_FIELD_DATA
#define SCALARMODE_CELLDATA VTK_SCALAR_MODE_USE_CELL_FIELD_DATA

//#define SCALARMODE_POINTDATA VTK_SCALAR_MODE_USE_POINT_DATA
//#define SCALARMODE_CELLDATA VTK_SCALAR_MODE_USE_CELL_DATA

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
		int I1, I2, I3;
		I1 = std::get<0>(connectivity[i]);
		I2 = std::get<1>(connectivity[i]);
		I3 = std::get<2>(connectivity[i]);

		std::array<std::array<vtkIdType, 3>, 1> order = { { {I1 - 1,I2 - 1,I3 - 1 } } };
		polys->InsertNextCell(vtkIdType(3), order[0].data());
	}
	thePolyData_->SetPoints(points);
	thePolyData_->SetPolys(polys);

	// Now we'll look at it.
	auto HullMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	this->SetMapper(HullMapper);

	HullMapper->SetInputData(thePolyData_);

	auto lut = vtkSmartPointer<FrgVisual_ContoursLUTable_Rainbow>::New();
	lut->SetRange(0.0, 1.0);

	SetLookUpTable(lut);
	SetScalarModeToUseCellData();

	// Create a transform to rescale model
	/*double center[3];
	thePolyData_->GetCenter(center);
	double bounds[6];
	thePolyData_->GetBounds(bounds);
	double maxBound =
		std::max(std::max(bounds[1] - bounds[0], bounds[3] - bounds[2]),
			bounds[5] - bounds[4]);*/

	auto userTransform = vtkSmartPointer<vtkTransform>::New();
	auto transform = vtkSmartPointer<vtkTransformPolyDataFilter>::New();
	transform->SetTransform(userTransform);
	transform->SetInputData(thePolyData_);

	auto triangles = vtkSmartPointer<vtkTriangleFilter>::New();
	triangles->SetInputConnection(transform->GetOutputPort());

	auto norms = vtkSmartPointer<vtkTriangleMeshPointNormals>::New();
	norms->SetInputConnection(triangles->GetOutputPort());

	HullMapper->SetInputConnection(norms->GetOutputPort());
	SetScalarVisibility(false);

	HullMapper->InterpolateScalarsBeforeMappingOn();
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
void ForgVisualLib::FrgVisual_MeshActor<Dim>::SetMeshVisible(bool condition)
{
	this->GetProperty()->SetEdgeVisibility(condition);
}

template<int Dim>
void ForgVisualLib::FrgVisual_MeshActor<Dim>::SetMeshColor(const QColor& color)
{
	this->GetProperty()->SetEdgeColor(color.redF(), color.greenF(), color.blueF());
}

template<int Dim>
void ForgVisualLib::FrgVisual_MeshActor<Dim>::SetScalarModeToUseCellData()
{
	const auto& myMapper = this->GetMapper();

	if (myMapper)
		myMapper->SetScalarMode(SCALARMODE_CELLDATA);
}

template<int Dim>
void ForgVisualLib::FrgVisual_MeshActor<Dim>::SetScalarModeToUsePointData()
{
	const auto& myMapper = this->GetMapper();

	if (myMapper)
		myMapper->SetScalarMode(SCALARMODE_POINTDATA);
}

template<int Dim>
ForgVisualLib::FrgViusal_LookUpTable* ForgVisualLib::FrgVisual_MeshActor<Dim>::GetLookUpTable()
{
	const auto& myMapper = this->GetMapper();

	if (myMapper)
	{
		auto lut = dynamic_cast<FrgViusal_LookUpTable*>(myMapper->GetLookupTable());

		if (!lut)
			lut = vtkSmartPointer<FrgVisual_ContoursLUTable_Rainbow>::New();

		return lut;
	}

	return nullptr;
}

template<int Dim>
void ForgVisualLib::FrgVisual_MeshActor<Dim>::SetLookUpTable(FrgViusal_LookUpTable* lut)
{
	if (!lut)
		return;

	const auto& myMapper = this->GetMapper();

	if (myMapper)
	{
		myMapper->SetLookupTable(lut);
		myMapper->SetScalarRange(lut->GetRange());
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_MeshActor<Dim>::SetScalarVisibility(bool condition)
{
	const auto& myMapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
	if (myMapper)
	{
		myMapper->SetScalarVisibility(condition);
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_MeshActor<Dim>::SetScalarRange(double minValue, double maxValue)
{
	const auto& lut = GetLookUpTable();
	if (lut)
	{
		lut->SetRange(minValue, maxValue);
	}

	SetLookUpTable(lut);
}

template<int Dim>
void ForgVisualLib::FrgVisual_MeshActor<Dim>::SetScalarValues(const std::vector<double>& values)
{
	const auto& myMapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
	if (myMapper)
	{
		auto scalarMode = myMapper->GetScalarMode();

		if (!CanSetScalarValues(values.size()))
			return;

		const auto& lut = GetLookUpTable();
		auto colors = vtkSmartPointer<vtkUnsignedCharArray>::New();
		colors->SetNumberOfComponents(3);
		colors->SetName("Colors");

		for (const auto& value : values)
		{
			auto color = FrgViusal_LookUpTable::MapScalarToColor(value, lut);
			colors->InsertNextTypedTuple(color);
		}

		if (scalarMode == SCALARMODE_POINTDATA)
			thePolyData_->GetPointData()->SetScalars(colors);
		else if (scalarMode == SCALARMODE_CELLDATA)
			thePolyData_->GetCellData()->SetScalars(colors);
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_MeshActor<Dim>::SetScalarScaleToLinear()
{
	const auto& lut = GetLookUpTable();
	if (lut)
	{
		lut->SetScaleToLinear();
	}

	UpdateScalarValues();
}

template<int Dim>
void ForgVisualLib::FrgVisual_MeshActor<Dim>::SetScalarScaleToLog10()
{
	const auto& lut = GetLookUpTable();
	if (lut)
	{
		lut->SetScaleToLog10();
	}

	UpdateScalarValues();
}

template<int Dim>
void ForgVisualLib::FrgVisual_MeshActor<Dim>::UpdateScalarValues()
{
	const auto& myMapper = GetMapper();
	if (thePolyData_ && myMapper)
	{
		auto scalarMode = myMapper->GetScalarMode();

		if (scalarMode == SCALARMODE_POINTDATA)
		{
			auto scalars = thePolyData_->GetPointData()->GetScalars();
			thePolyData_->GetPointData()->SetScalars(scalars);
		}
		else if (scalarMode == SCALARMODE_CELLDATA)
		{
			auto scalars = thePolyData_->GetCellData()->GetScalars();
			thePolyData_->GetCellData()->SetScalars(scalars);
		}

		myMapper->Update();
	}
}

template<int Dim>
std::vector<double> ForgVisualLib::FrgVisual_MeshActor<Dim>::ConvertCellDataToPointData(const std::vector<double>& values)
{
	auto myArray = vtkSmartPointer<vtkDoubleArray>::New();
	myArray->SetNumberOfComponents(1);
	myArray->SetName("MyArray");
	for (const auto& v : values)
	{
		auto d = new double(v);
		myArray->InsertNextTypedTuple(d);
	}

	thePolyData_->GetCellData()->SetScalars(myArray);

	auto convertor = vtkSmartPointer<vtkCellDataToPointData>::New();
	convertor->SetInputData(thePolyData_);
	convertor->Update();

	std::vector<double> pointsData;
	auto pointsScalarData = convertor->GetPolyDataOutput()->GetPointData()->GetScalars();
	for (int i = 0; i < pointsScalarData->GetNumberOfValues(); i++)
		pointsData.push_back(pointsScalarData->GetVariantValue(i).ToDouble());

	return pointsData;
}

template<int Dim>
bool ForgVisualLib::FrgVisual_MeshActor<Dim>::CanSetScalarValues(const int valuesSize)
{
	if (valuesSize == 0)
		return false;

	const auto& myMapper = vtkPolyDataMapper::SafeDownCast(GetMapper());
	if (myMapper && thePolyData_)
	{
		auto scalarMode = myMapper->GetScalarMode();

		if (scalarMode == SCALARMODE_POINTDATA)
		{
			if (thePolyData_->GetNumberOfPoints() != valuesSize)
				return false;

			return true;
		}
		else if (scalarMode == SCALARMODE_CELLDATA)
		{
			if (thePolyData_->GetNumberOfCells() != valuesSize)
				return false;

			return true;
		}
	}

	return false;
}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_MeshActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);

	ar& thePoints_;
	ar& theConnectivity_;
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_MeshActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);

	ar& thePoints_;
	ar& theConnectivity_;

	SetDataTriangulation(thePoints_, theConnectivity_);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_MeshActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_MeshActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_MeshActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_MeshActor<3>;