#ifndef _FrgVisual_3DLineActor_Header
#define _FrgVisual_3DLineActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_3DBaseActor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

namespace ForgBaseLib
{
	class FrgBase_Pnt3d;
}

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_3DLineActor
	: public FrgVisual_3DBaseActor
{

	typedef FrgVisual_3DBaseActor SuperClass;

public:

	FrgVisual_3DLineActor();

	~FrgVisual_3DLineActor();

	static FrgVisual_3DLineActor* New();
	vtkTypeMacro(FrgVisual_3DLineActor, FrgVisual_3DBaseActor);

	void SetLineWidth(float width);
	void SetRenderLinesAsTubes(bool condition);

	void SetData(std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> P0, std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> P1);
	void SetData(double P0_X, double P0_Y, double P0_Z, double P1_X, double P1_Y, double P1_Z);

	std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> GetP0() const { return theP0_; }
	std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> GetP1() const { return theP1_; }

private:

	DECLARE_SAVE_LOAD_HEADER

private:

	std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> theP0_;
	std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> theP1_;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_3DLineActor)

#endif // !_FrgVisual_3DLineActor_Header
#pragma once
