#pragma once
#ifndef _FrgVisual_MeshActor_Header
#define _FrgVisual_MeshActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_BaseActor.hxx>
#include <FrgBase_Pnt.hxx>

#include <FrgVisual_Serialization_Global.hxx>

#include <vtkSmartPointer.h>

namespace ForgBaseLib
{
	template<int Dim>
	class FrgBase_Pnt;
}

class vtkPolyData;

BeginForgVisualLib

class FrgViusal_LookUpTable;

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
		std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> pts,
		std::vector<std::tuple<int, int, int>> connectivity
	);

	ActorType GetActorType() const override;
	std::vector<ActorType> GetActorTypes() const override;
	ActorDimension GetActorDimension() const override;

	const auto& GetPoints() const { return thePoints_; }
	const auto& GetConnectivity() const { return theConnectivity_; }

	void SetMeshVisible(bool condition);
	void SetMeshColor(const QColor& color);

	void SetScalarModeToUseCellData();
	void SetScalarModeToUsePointData();

	FrgViusal_LookUpTable* GetLookUpTable();
	void SetLookUpTable(FrgViusal_LookUpTable* lut);

	void SetScalarVisibility(bool condition);

	void SetScalarRange(double minValue, double maxValue);

	void SetScalarValues(const std::vector<double>& values);

private:

	DECLARE_SAVE_LOAD_HEADER( )

protected:

	bool CanSetScalarValues(const int valuesSize);

protected:

	std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> thePoints_;
	std::vector<std::tuple<int, int, int>> theConnectivity_;

	vtkSmartPointer<vtkPolyData> thePolyData_ = nullptr;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_MeshActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_MeshActor<3>)

#include <FrgVisual_MeshActorI.hxx>

#endif // !_FrgVisual_MeshActor_Header
