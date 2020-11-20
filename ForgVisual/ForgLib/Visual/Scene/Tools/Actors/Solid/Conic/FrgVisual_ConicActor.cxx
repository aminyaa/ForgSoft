#include <FrgVisual_ConicActor.hxx>

#include <vtkObjectFactory.h>

template<int Dim>
vtkStandardNewMacro(ForgVisualLib::FrgVisual_ConicActor<Dim>);

template<int Dim>
inline ForgVisualLib::FrgVisual_ConicActor<Dim>::FrgVisual_ConicActor()
{

}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_ConicActor<Dim>)
{
	ar & boost::serialization::base_object<ForgVisualLib::FrgVisual_SolidActor<Dim>>(*this);
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_ConicActor<Dim>)
{
	ar & boost::serialization::base_object<ForgVisualLib::FrgVisual_SolidActor<Dim>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_ConicActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_ConicActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_ConicActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_ConicActor<3>;