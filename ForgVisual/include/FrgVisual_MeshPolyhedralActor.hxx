#pragma once
#ifndef _FrgVisual_MeshPolyhedralActor_Header
#define _FrgVisual_MeshPolyhedralActor_Header

#include <FrgVisual_MeshActor.hxx>

BeginForgVisualLib

template <int Dim>
class FORGVISUAL_EXPORT FrgVisual_MeshPolyhedralActor
	: public FrgVisual_MeshActor<Dim>
{
	typedef FrgVisual_MeshActor<Dim> SuperClass;

public:

	FrgVisual_MeshPolyhedralActor();

	static FrgVisual_MeshPolyhedralActor* New();
	vtkTypeMacro(FrgVisual_MeshPolyhedralActor, FrgVisual_MeshActor<Dim>);

	void SetDataPolyhedral
	(
		const std::vector<ForgBaseLib::FrgBase_Pnt<Dim>>& pts,
		const std::vector<std::vector<int>>& connectivity
	);

	ActorType GetActorType() const override;
	std::vector<ActorType> GetActorTypes() const override;
	ActorDimension GetActorDimension() const override;

	const auto& GetPoints() const { return thePoints_; }
	const auto& GetConnectivity() const { return theConnectivity_; }

private:

	DECLARE_SAVE_LOAD_HEADER()

protected:

	std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> thePoints_;
	std::vector<std::vector<int>> theConnectivity_;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_MeshPolyhedralActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_MeshPolyhedralActor<3>)

#endif // !_FrgVisual_MeshPolyhedralActor_Header
