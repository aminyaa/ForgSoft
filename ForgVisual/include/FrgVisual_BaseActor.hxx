#pragma once
#ifndef _FrgVisual_BaseActor_Header
#define _FrgVisual_BaseActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_BaseActor_Entity.hxx>

class Standard_Transient;

namespace ForgBaseLib
{
	template <int Dim>
	class FrgBase_Pnt;
}

namespace opencascade
{
	template <class T>
	class handle;
}

BeginForgVisualLib

template<int Dim>
class FORGVISUAL_EXPORT FrgVisual_BaseActor
	: public FrgVisual_BaseActor_Entity
{

	typedef FrgVisual_BaseActor_Entity SuperClass;

public:

	FrgVisual_BaseActor();

	//static FrgVisual_BaseActor* New();
	vtkTypeMacro(FrgVisual_BaseActor, FrgVisual_BaseActor_Entity);

	~FrgVisual_BaseActor();

	virtual void TranslateActor(double dx, double dy);
	virtual void TranslateActor(double dx, double dy, double dz);

	static std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> DiscreteCurve(opencascade::handle<Standard_Transient> curve, const double degree = 3.0);

private:

	DECLARE_SAVE_LOAD_HEADER( )
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_BaseActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_BaseActor<3>)

#include <FrgVisual_BaseActorI.hxx>

#endif // !_FrgVisual_BaseActor_Header
