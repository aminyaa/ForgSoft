#pragma once
#ifndef _FrgVisual_MeshActor_Header
#define _FrgVisual_MeshActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_BaseActor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

namespace ForgBaseLib
{
	template<int Dim>
	class FrgBase_Pnt;
}

BeginForgVisualLib

template<int Dim>
class FORGVISUAL_EXPORT FrgVisual_MeshActor
	: public FrgVisual_BaseActor<Dim>
{
	typedef FrgVisual_BaseActor<Dim> SuperClass;

public:

	FrgVisual_MeshActor();

	static FrgVisual_MeshActor* New();
	vtkTypeMacro(FrgVisual_MeshActor, FrgVisual_BaseActor<Dim>);

	void SetDataTriangulation
	(
		std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> pts,
		std::vector<std::shared_ptr<std::tuple<int, int, int>>> connectivity
	);

private:

	DECLARE_SAVE_LOAD_HEADER( )

protected:

	std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> thePoints_;
	std::vector<std::shared_ptr<std::tuple<int, int, int>>> theConnectivity_;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_MeshActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_MeshActor<3>)

#include <FrgVisual_MeshActorI.hxx>

#endif // !_FrgVisual_MeshActor_Header
