#include <FrgVisual_BaseActor.hxx>

#include <vtkObjectFactory.h>

template<int Dim>
vtkStandardNewMacro(ForgVisualLib::FrgVisual_BaseActor<Dim>);

template<int Dim>
inline ForgVisualLib::FrgVisual_BaseActor<Dim>::FrgVisual_BaseActor()
{

}

template<int Dim>
inline ForgVisualLib::FrgVisual_BaseActor<Dim>::~FrgVisual_BaseActor()
{

}

template<int Dim>
//template<typename>
inline void ForgVisualLib::FrgVisual_BaseActor<Dim>::TranslateActor(double dx, double dy)
{
	this->AddPosition(dx, dy, 0.0);

	emit DataChangedSignal();
}

template<int Dim>
//template<typename>
inline void ForgVisualLib::FrgVisual_BaseActor<Dim>::TranslateActor(double dx, double dy, double dz)
{
	this->AddPosition(dx, dy, dz);

	emit DataChangedSignal();
}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_BaseActor<Dim>)
{
	ar& boost::serialization::base_object<FrgVisual_BaseActor_Entity>(*this);
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_BaseActor<Dim>)
{
	ar& boost::serialization::base_object<FrgVisual_BaseActor_Entity>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_BaseActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_BaseActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_BaseActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_BaseActor<3>;