#include <FrgVisual_CurveActor.hxx>

#include <vtkProperty.h>
#include <vtkDoubleArray.h>
#include <vtkImageData.h>
#include <vtkTexture.h>
#include <vtkPolyData.h>
#include <vtkPointData.h>
#include <vtkMapper.h>

#include <GeomTools.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Curve.hxx>

#include <istream>
#include <fstream>
#include <sstream>

#include <vtkObjectFactory.h>

//template<int Dim>
//vtkStandardNewMacro(ForgVisualLib::FrgVisual_CurveActor<Dim>);

template<int Dim>
inline ForgVisualLib::FrgVisual_CurveActor<Dim>::FrgVisual_CurveActor()
{
	theIsStippled_ = false;
	theLineStipplePattern_ = 50;
}

template<int Dim>
inline
void ForgVisualLib::FrgVisual_CurveActor<Dim>::SetLineWidth(float width)
{
	GetProperty()->SetLineWidth(width);
	theLineWidth_ = width;
}

template<int Dim>
float ForgVisualLib::FrgVisual_CurveActor<Dim>::GetSelectionLineWidth() const
{
	return theSelectionLineWidth_;
}

template<int Dim>
void ForgVisualLib::FrgVisual_CurveActor<Dim>::SetSelectionLineWidth(float width)
{
	theSelectionLineWidth_ = width;
}

template<int Dim>
float ForgVisualLib::FrgVisual_CurveActor<Dim>::GetLineWidth() const
{
	return theLineWidth_;
}

template<int Dim>
bool ForgVisualLib::FrgVisual_CurveActor<Dim>::IsRenderLinesAsTubes() const
{
	return theRenderLinesAsTubes_;
}

template<int Dim>
inline
void ForgVisualLib::FrgVisual_CurveActor<Dim>::SetRenderLinesAsTubes(bool condition)
{
	theRenderLinesAsTubes_ = condition;
	
	GetProperty()->SetRenderLinesAsTubes(condition);
}

template<int Dim>
inline
void ForgVisualLib::FrgVisual_CurveActor<Dim>::SetStippledLine(int lineStipplePattern, bool condition)
{
	theIsStippled_ = condition;
	theLineStipplePattern_ = lineStipplePattern;

	vtkSmartPointer<vtkDoubleArray> tcoords =
		vtkSmartPointer<vtkDoubleArray>::New();
	vtkSmartPointer<vtkImageData> image =
		vtkSmartPointer<vtkImageData>::New();
	vtkSmartPointer<vtkTexture> texture =
		vtkSmartPointer<vtkTexture>::New();

	// Create texture
	int dimension = lineStipplePattern;

	image->SetDimensions(dimension, 1, 1);
	image->AllocateScalars(VTK_UNSIGNED_CHAR, 4);
	image->SetExtent(0, dimension - 1, 0, 0, 0, 0);
	unsigned char* pixel;
	pixel = static_cast<unsigned char*>(image->GetScalarPointer());
	unsigned char on = 255;
	unsigned char off = 0;
	for (int i = 0; i < dimension; ++i)
	{
		if (i % 2 == 0)
		{
			*pixel = on;
			*(pixel + 1) = on;
			*(pixel + 2) = on;
			if (condition)
				*(pixel + 3) = off;
			else
				*(pixel + 3) = on;
			pixel += 4;
		}
		else
		{
			*pixel = on;
			*(pixel + 1) = on;
			*(pixel + 2) = on;
			*(pixel + 3) = on;
			pixel += 4;
		}
	}
	vtkPolyData* polyData = vtkPolyData::SafeDownCast(this->GetMapper()->GetInput());

	// Create texture coordinates
	tcoords->SetNumberOfComponents(1);
	tcoords->SetNumberOfTuples(polyData->GetNumberOfPoints());
	for (int i = 0; i < polyData->GetNumberOfPoints(); ++i)
	{
		double value = static_cast<double>(i) * .5;
		tcoords->SetTypedTuple(i, &value);
	}

	polyData->GetPointData()->SetTCoords(tcoords);
	texture->SetInputData(image);
	texture->InterpolateOff();
	texture->RepeatOn();

	if (condition)
		this->SetTexture(texture);
	else
		this->SetTexture(nullptr);
}

template<int Dim>
inline
bool ForgVisualLib::FrgVisual_CurveActor<Dim>::SelectActor(const QColor& color)
{
	if (!FrgVisual_BaseActor<Dim>::SelectActor(color))
		return false;

	GetProperty()->SetLineWidth(theSelectionLineWidth_);

	/*GetProperty()->SetLineWidth(2.0 * GetProperty()->GetLineWidth());*/

	return true;
}

template<int Dim>
inline bool ForgVisualLib::FrgVisual_CurveActor<Dim>::UnSelectActor()
{
	if (!FrgVisual_BaseActor<Dim>::UnSelectActor())
		return false;

	/*GetProperty()->SetLineWidth(0.5 * GetProperty()->GetLineWidth());*/

	return true;
}

#define CurveType2D "CurveActor_2D"
#define CurveType3D "CurveActor_3D"
#define CurveTypeNone "CurveActor_None"

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_CurveActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);

	ar& theIsStippled_;
	ar& theLineStipplePattern_;
	ar& theLineWidth_;
	ar& theSelectionLineWidth_;
	ar& theRenderLinesAsTubes_;

	std::string curveType;

	auto my2dCurve = opencascade::handle<Geom2d_Curve>::DownCast(theCurve_);
	auto my3dCurve = opencascade::handle<Geom_Curve>::DownCast(theCurve_);

	if (my2dCurve)
		curveType = CurveType2D;
	else if (my3dCurve)
		curveType = CurveType3D;
	else
		curveType = CurveTypeNone;

	ar& curveType;

	if (my2dCurve)
	{
		std::ostringstream st;
		st.precision(16);
		GeomTools::Write(my2dCurve, st);

		std::string s = st.str();
		ar & s;
	}
	else if (my3dCurve)
	{
		std::ostringstream st;
		st.precision(16);
		GeomTools::Write(my3dCurve, st);

		std::string s = st.str();
		ar & s;
	}
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_CurveActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);

	ar& theIsStippled_;
	ar& theLineStipplePattern_;
	ar& theLineWidth_;
	ar& theSelectionLineWidth_;
	ar& theRenderLinesAsTubes_;

	std::string curveType;

	ar& curveType;

	if (curveType == CurveType2D)
	{
		std::string s;
		ar& s;

		std::stringstream st;
		st << s;
		
		Handle(Geom2d_Curve) curve;
		GeomTools::Read(curve, st);

		theCurve_ = curve;
	}
	else if (curveType == CurveType3D)
	{
		std::string s;
		ar& s;

		std::stringstream st;
		st << s;

		Handle(Geom_Curve) curve;
		GeomTools::Read(curve, st);

		theCurve_ = curve;
	}

	//SetStippledLine(theLineStipplePattern_, theIsStippled_);
	SetLineWidth(theLineWidth_);
	SetRenderLinesAsTubes(theRenderLinesAsTubes_);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_CurveActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_CurveActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_CurveActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_CurveActor<3>;