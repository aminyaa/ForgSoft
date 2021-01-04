#include <FrgVisual_SolidActor.hxx>

#include <vtkObjectFactory.h>

//template<int Dim>
//vtkStandardNewMacro(ForgVisualLib::FrgVisual_SolidActor<Dim>);

template<int Dim>
inline ForgVisualLib::FrgVisual_SolidActor<Dim>::FrgVisual_SolidActor()
{

}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_SolidActor<Dim>)
{
	ar & boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_SolidActor<Dim>)
{
	ar & boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_SolidActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_SolidActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_SolidActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_SolidActor<3>;