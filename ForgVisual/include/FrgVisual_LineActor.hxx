#pragma once
#ifndef _FrgVisual_LineActor_Header
#define _FrgVisual_LineActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_PolylineActor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

namespace ForgBaseLib
{
	template<int Dim>
	class FrgBase_Pnt;
}

BeginForgVisualLib

template<int Dim>
class FORGVISUAL_EXPORT FrgVisual_LineActor
	: public FrgVisual_PolylineActor<Dim>
{

	typedef FrgVisual_PolylineActor<Dim> SuperClass;

public:

	FrgVisual_LineActor();

	static FrgVisual_LineActor* New();
	vtkTypeMacro(FrgVisual_LineActor, FrgVisual_PolylineActor<Dim>);

	//void SetData(std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> P0, std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> P1);
	void SetData(ForgBaseLib::FrgBase_Pnt<Dim> P0, ForgBaseLib::FrgBase_Pnt<Dim> P1);

	template <typename = std::enable_if_t<Dim == 2>>
	void SetData(double P0_X, double P0_Y, double P1_X, double P1_Y);
	template <typename = std::enable_if_t<Dim == 3>>
	void SetData(double P0_X, double P0_Y, double P0_Z, double P1_X, double P1_Y, double P1_Z);

	std::vector<ActorType> GetActorTypes() const override;
	ActorDimension GetActorDimension() const override;

	//void UpdateActor() override;

	//std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> GetP0() const { return theP0_; }
	//std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> GetP1() const { return theP1_; }

private:

	DECLARE_SAVE_LOAD_HEADER( )

private:

	//std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> theP0_;
	//std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> theP1_;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_LineActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_LineActor<3>)

#include <FrgVisual_LineActorI.hxx>

#endif // !_FrgVisual_LineActor_Header
