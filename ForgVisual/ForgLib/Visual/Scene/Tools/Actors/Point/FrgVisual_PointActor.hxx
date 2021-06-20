#pragma once
#ifndef _FrgVisual_PointActor_Header
#define _FrgVisual_PointActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_BaseActor.hxx>
#include <FrgBase_Pnt.hxx>

#include <FrgVisual_Serialization_Global.hxx>

namespace ForgBaseLib
{
	template<int Dim>
	class FrgBase_Pnt;
}

BeginForgVisualLib

template<int Dim>
class FrgVisual_PolylineActor;

template<int Dim>
class FORGVISUAL_EXPORT FrgVisual_PointActor
	: public FrgVisual_BaseActor<Dim>
{
	typedef FrgVisual_BaseActor<Dim> SuperClass;

public:

	FrgVisual_PointActor();

	virtual float GetSize() const;
	virtual void SetSize(float size);

	virtual float GetSelectionSize() const;
	virtual void SetSelectionSize(float size);

	virtual bool IsRenderPointsAsSpheres() const { return theRenderPointsAsSpheres_; }
	virtual void SetRenderPointsAsSpheres(bool condition);

	static FrgVisual_PointActor* New();
	vtkTypeMacro(FrgVisual_PointActor, FrgVisual_BaseActor<Dim>);

	//std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> GetData() const { return theP_; }

	//void TranslateActor(double dx, double dy) override;
	//void TranslateActor(double dx, double dy, double dz) override;

	bool SelectActor(const QColor& color) override;
	bool UnSelectActor() override;

	void SetData(ForgBaseLib::FrgBase_Pnt<Dim> pt);
	const auto& GetData() const { return theP_; }

	//void UpdateActor();

	template <typename = std::enable_if_t<Dim == 2>>
	void SetData(double x, double y);
	template <typename = std::enable_if_t<Dim == 3>>
	void SetData(double x, double y, double z);

	ActorType GetActorType() const override;
	std::vector<ActorType> GetActorTypes() const override;
	ActorDimension GetActorDimension() const override;

	//virtual FrgVisual_PolylineActor<Dim>* GetParentPolylineActor() const { return theParentPolyLineActor_; }
	//virtual void SetParentPolylineActor(FrgVisual_PolylineActor<Dim>* parentPolyLineActor) { theParentPolyLineActor_ = parentPolyLineActor; }

private:

	DECLARE_SAVE_LOAD_HEADER( )

protected:

	ForgBaseLib::FrgBase_Pnt<Dim> theP_;

	float theSize_ = 1.0f;
	float theSelectionSize_ = 2.0f;
	bool theRenderPointsAsSpheres_ = false;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_PointActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_PointActor<3>)

#include <FrgVisual_PointActorI.hxx>

#endif // !_FrgVisual_PointActor_Header
