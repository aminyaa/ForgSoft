#include <FrgVisual_CurveActor.hxx>

#include <vtkProperty.h>
#include <vtkDoubleArray.h>
#include <vtkImageData.h>
#include <vtkTexture.h>
#include <vtkPolyData.h>
#include <vtkPointData.h>
#include <vtkMapper.h>

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
}

template<int Dim>
float ForgVisualLib::FrgVisual_CurveActor<Dim>::GetLineWidth()
{
	return GetProperty()->GetLineWidth();
}

template<int Dim>
inline
void ForgVisualLib::FrgVisual_CurveActor<Dim>::SetRenderLinesAsTubes(bool condition)
{
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

	SetLineWidth(3.0 * theCopyProperty_->GetLineWidth());

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

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_CurveActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);

	ar& theIsStippled_;
	ar& theLineStipplePattern_;
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_CurveActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);

	ar& theIsStippled_;
	ar& theLineStipplePattern_;
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_CurveActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_CurveActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_CurveActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_CurveActor<3>;