#pragma once
#ifndef _FrgVisual_PolylineActor_Header
#define _FrgVisual_PolylineActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_CurveActor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

namespace ForgBaseLib
{
	template<int Dim>
	class FrgBase_Pnt;
}

BeginForgVisualLib

template<int Dim>
class FrgVisual_PointActor;

template<int Dim>
class FrgVisual_BSPLineActor;

template<int Dim>
class FORGVISUAL_EXPORT FrgVisual_PolylineActor
	: public FrgVisual_CurveActor<Dim>
{
	typedef FrgVisual_CurveActor<Dim> SuperClass;

public:

	FrgVisual_PolylineActor();

	~FrgVisual_PolylineActor();

	static FrgVisual_PolylineActor* New();
	vtkTypeMacro(FrgVisual_PolylineActor, FrgVisual_CurveActor<Dim>);

	void SetData(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> pts);
	void SetData(std::vector<FrgVisual_PointActor<Dim>*> ptsActors);

	std::vector<FrgVisual_PointActor<Dim>*> GetPts() const { return thePts_; }

	void TranslateActor(double dx, double dy) override;
	void TranslateActor(double dx, double dy, double dz) override;

	void UpdateActor() override;

	void SetRenderer(vtkRenderer* renderer) override;

	FrgVisual_BSPLineActor<Dim>* GetParentBSPLineActor() const { return theParentBSPLineActor_; }
	void SetParentBSPLineActor(FrgVisual_BSPLineActor<Dim>* parentBSPLineActor);

	void SetSelectable(bool selectable = true) override;

	void RemoveActors(vtkRenderer* renderer) override;

private:

	DECLARE_SAVE_LOAD_HEADER( )

private:

	std::vector<FrgVisual_PointActor<Dim>*> thePts_;

	FrgVisual_BSPLineActor<Dim>* theParentBSPLineActor_ = nullptr;

};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_PolylineActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_PolylineActor<3>)

#include <FrgVisual_PolylineActorI.hxx>

#endif // !_FrgVisual_PolylineActor_Header
