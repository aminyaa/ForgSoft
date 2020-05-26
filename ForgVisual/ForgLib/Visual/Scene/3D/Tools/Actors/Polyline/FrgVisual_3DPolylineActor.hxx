#pragma once
#ifndef _FrgVisual_3DPolylineActor_Header
#define _FrgVisual_3DPolylineActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_3DBaseActor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

namespace ForgBaseLib
{
	class FrgBase_Pnt3d;
}

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_3DPolylineActor
	: public FrgVisual_3DBaseActor
{
	typedef FrgVisual_3DBaseActor SuperClass;

public:

	FrgVisual_3DPolylineActor();

	~FrgVisual_3DPolylineActor();

	static FrgVisual_3DPolylineActor* New();
	vtkTypeMacro(FrgVisual_3DPolylineActor, FrgVisual_3DBaseActor);

	void SetData(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d>> pts);

private:

	DECLARE_SAVE_LOAD_HEADER

private:

	std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d>> thePts_;

};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_3DPolylineActor)

#endif // !_FrgVisual_3DPolylineActor_Header
