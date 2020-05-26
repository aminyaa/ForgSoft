#pragma once
#ifndef _FrgVisual_3DPointActor_Header
#define _FrgVisual_3DPointActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_3DBaseActor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

namespace ForgBaseLib
{
	class FrgBase_Pnt3d;
}

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_3DPointActor
	: public FrgVisual_3DBaseActor
{

	typedef FrgVisual_3DBaseActor SuperClass;

public:

	static FrgVisual_3DPointActor* New();
	vtkTypeMacro(FrgVisual_3DPointActor, FrgVisual_3DBaseActor);

	~FrgVisual_3DPointActor();
	double* GetColor();

	void SetSize(float size);
	float GetSize();

	void SetRenderPointsAsSpheres(bool condition);

	void SetData(std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> pt);
	void SetData(double x, double y, double z);

	std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> GetData() const { return theP_; }

private:

	DECLARE_SAVE_LOAD_HEADER

protected:

	FrgVisual_3DPointActor();

private:

	std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> theP_;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_3DPointActor)

#endif // !_FrgVisual_3DPointActor_Header
