#pragma once
#ifndef _FrgVisual_CylinderActor_Header
#define _FrgVisual_CylinderActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_ConicActor.hxx>
#include <FrgBase_Pnt.hxx>

#include <FrgVisual_Serialization_Global.hxx>

namespace ForgBaseLib
{
	template<int Dim>
	class FrgBase_Pnt;
}

namespace ForgVisualLib
{
	template <int Dim>
	class FrgVisual_MeshActor;
}

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_CylinderActor
	: public FrgVisual_ConicActor<3>
{
	typedef FrgVisual_ConicActor<3> SuperClass;

public:

	FrgVisual_CylinderActor();

	static FrgVisual_CylinderActor* New();
	vtkTypeMacro(FrgVisual_CylinderActor, FrgVisual_ConicActor<3>);

	void SetRepresentationToSurface();
	void SetRepresentationToWireframe();

	bool IsRepresentationToSurface() const { return theIsRepresentationToSurface_; }
	bool IsRepresentationToWireframe() const { return !theIsRepresentationToSurface_; }

	void SetEdgeColor(double red, double green, double blue);

	void SetData(ForgBaseLib::FrgBase_Pnt<3> Start, ForgBaseLib::FrgBase_Pnt<3> End, double radius);
	void SetData(double Start_x, double Start_y, double Start_z, double End_x, double End_y, double End_z, double radius);

	ActorType GetActorType() const override;
	std::vector<ActorType> GetActorTypes() const override;
	ActorDimension GetActorDimension() const override;

	const auto& GetStart() const { return theStart_; }
	const auto& GetEnd() const { return theEnd_; }
	double GetRadius() const { return theRadius_; }

	void AddActors(vtkRenderer* renderer) override;
	void RemoveActors(vtkRenderer* renderer) override;

	bool IsSelectable() const override;
	void SetSelectable(bool selectable = true) override;

	bool IsSelected() const override;

	void SetColor(double red, double green, double blue) override;
	void SetColor(double a[3]) override;
	void SetColor(const QColor& color) override;

	void SetSelectingColor(const QColor& color) override;
	QColor GetSelectingColor() const override;

	double* GetColor() override;
	void GetColor(double rgb[3]) override;
	void GetColor(double& r, double& g, double& b) override;

	bool SelectActor(const QColor& color) override;
	bool SelectActor() override;
	bool UnSelectActor() override;

	bool HideActor() override;
	bool UnHideActor() override;

	void SetVisibility(vtkTypeBool _arg) override;
	void VisibilityOn() override;
	void VisibilityOff() override;

	double GetOpacity() override;
	void SetOpacity(double opacity) override;

private:

	DECLARE_SAVE_LOAD_HEADER()

protected:

	ForgBaseLib::FrgBase_Pnt<3> theStart_;
	ForgBaseLib::FrgBase_Pnt<3> theEnd_;
	double theRadius_ = 0.0;

	bool theIsRepresentationToSurface_ = true;

	std::vector<ForgVisualLib::FrgVisual_MeshActor<3>*> theMesh_;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_CylinderActor)

#endif // !_FrgVisual_CylinderActor_Header
