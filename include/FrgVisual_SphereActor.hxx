#pragma once
#ifndef _FrgVisual_SphereActor_Header
#define _FrgVisual_SphereActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_ConicActor.hxx>
#include <FrgBase_Pnt.hxx>

#include <FrgVisual_Serialization_Global.hxx>

class vtkSphereSource;

namespace ForgBaseLib
{
	template<int Dim>
	class FrgBase_Pnt;
}

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_SphereActor
	: public FrgVisual_ConicActor<3>
{
	typedef FrgVisual_ConicActor<3> SuperClass;

public:

	FrgVisual_SphereActor();

	static FrgVisual_SphereActor* New();
	vtkTypeMacro(FrgVisual_SphereActor, FrgVisual_ConicActor<3>);

	void SetRepresentationToPoints();
	void SetRepresentationToSurface();
	void SetRepresentationToWireframe();

	void SetEdgeColor(double red, double green, double blue);

	void SetData(const ForgBaseLib::FrgBase_Pnt<3>& center, const double radius);

	ActorType GetActorType() const override;
	std::vector<ActorType> GetActorTypes() const override;
	ActorDimension GetActorDimension() const override;

	auto GetCenter() const { return theCenter_; }
	auto GetRadius() const { return theRadius_; }

	void SetCenter(const ForgBaseLib::FrgBase_Pnt<3>& center);
	void SetRadius(const double radius);

	void SetPhiResolution(const int value);
	void SetThetaResolution(const int value);

private:

	DECLARE_SAVE_LOAD_HEADER()

protected:

	ForgBaseLib::FrgBase_Pnt<3> theCenter_;
	double theRadius_ = 0.0;

	vtkSmartPointer<vtkSphereSource> theSource_;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_SphereActor)

#endif // !_FrgVisual_SphereActor_Header
