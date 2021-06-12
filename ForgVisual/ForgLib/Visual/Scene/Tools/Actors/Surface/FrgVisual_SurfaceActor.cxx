#include <FrgVisual_SurfaceActor.hxx>

#include <vtkObjectFactory.h>
#include <vtkProperty.h>

//vtkStandardNewMacro(ForgVisualLib::FrgVisual_SurfaceActor);

template<int Dim>
ForgVisualLib::FrgVisual_SurfaceActor<Dim>::FrgVisual_SurfaceActor()
{

}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_SurfaceActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_SurfaceActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_SurfaceActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_SurfaceActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_SurfaceActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_SurfaceActor<3>;