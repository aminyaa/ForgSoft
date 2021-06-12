#pragma once
#ifndef _FrgVisual_PlaneActor_Header
#define _FrgVisual_PlaneActor_Header

#include <FrgVisual_SurfaceActor.hxx>

#include <vtkSmartPointer.h>

class vtkPolyDataMapper;
class vtkPlaneSource;

namespace ForgBaseLib
{
	template <int Dim>
	class FrgBase_Pnt;
}

BeginForgVisualLib

template <int Dim>
class FORGVISUAL_EXPORT FrgVisual_PlaneActor
	: public FrgVisual_SurfaceActor<Dim>
{
	typedef FrgVisual_SurfaceActor<Dim> SuperClass;

public:

	FrgVisual_PlaneActor();

	static FrgVisual_PlaneActor* New();
	vtkTypeMacro(FrgVisual_PlaneActor, FrgVisual_SurfaceActor<Dim>);

	void SetData(const ForgBaseLib::FrgBase_Pnt<Dim>& center, const ForgBaseLib::FrgBase_Pnt<Dim>& normal);
	void SetData(const ForgBaseLib::FrgBase_Pnt<Dim>& origin, const ForgBaseLib::FrgBase_Pnt<Dim>& P1, const ForgBaseLib::FrgBase_Pnt<Dim>& P2);

	const ForgBaseLib::FrgBase_Pnt<Dim>& GetOrigin() const;
	const ForgBaseLib::FrgBase_Pnt<Dim>& GetCenter() const;
	const ForgBaseLib::FrgBase_Pnt<Dim>& GetNormal() const;
	const ForgBaseLib::FrgBase_Pnt<Dim>& GetPoint1() const;
	const ForgBaseLib::FrgBase_Pnt<Dim>& GetPoint2() const;

	void SetOrigin(const ForgBaseLib::FrgBase_Pnt<Dim>& origin);
	void SetCenter(const ForgBaseLib::FrgBase_Pnt<Dim>& center);
	void SetNormal(const ForgBaseLib::FrgBase_Pnt<Dim>& normal);
	void SetPoint1(const ForgBaseLib::FrgBase_Pnt<Dim>& p1);
	void SetPoint2(const ForgBaseLib::FrgBase_Pnt<Dim>& p2);

	ActorType GetActorType() const override;
	std::vector<ActorType> GetActorTypes() const override;
	ActorDimension GetActorDimension() const override;

private:

	DECLARE_SAVE_LOAD_HEADER()

protected:

	vtkSmartPointer<vtkPolyDataMapper> theMapper_ = nullptr;
	vtkSmartPointer<vtkPlaneSource> thePlaneSource_ = nullptr;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_PlaneActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_PlaneActor<3>)

#endif // !_FrgVisual_PlaneActor_Header
