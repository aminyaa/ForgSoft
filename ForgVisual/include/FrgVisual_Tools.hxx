#pragma once
#ifndef _FrgVisual_Tools_Header
#define _FrgVisual_Tools_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_Object.hxx>

#include <BRepMesh_FastDiscret.hxx>
#include <vtkSmartPointer.h>

namespace ForgBaseLib
{
	template <int Dim>
	class FrgBase_Pnt;
}

class TopoDS_Shape;
class TopoDS_Edge;
class vtkPolyData;

BeginForgVisualLib

class FrgVisual_Tools
	: public ForgBaseLib::FrgBase_Object
{

public:

	static vtkSmartPointer<vtkPolyData> ShapeToVTK(const TopoDS_Shape& shape);

	/*static std::vector
		<
		std::tuple
		<
		std::vector<ForgBaseLib::FrgBase_Pnt<3>>,
		std::vector<std::tuple<int, int, int>>
		>
		>
		GetMeshOnSurfacesFromShape(const TopoDS_Shape& shape);

	static BRepMesh_FastDiscret::Parameters CalcDiscreteParamsUsingShape(const TopoDS_Shape& shape);

	static
		std::vector
		<
		std::tuple
		<
		std::vector<ForgBaseLib::FrgBase_Pnt<3>>,
		std::vector<std::tuple<int, int, int>>
		>
		>
		GetMeshOnEdgesFromShape(const TopoDS_Shape& shape);

	static std::vector<ForgBaseLib::FrgBase_Pnt<3>> GeneratePoints;

protected:

	static std::vector<TopoDS_Edge> RetrieveEdgesOfShape(const TopoDS_Shape& shape);

	static
		std::tuple
		<
		std::vector<ForgBaseLib::FrgBase_Pnt<3>>,
		std::vector<std::tuple<int, int, int>>
		> ConvertPolyLineToMesh(std::vector<ForgBaseLib::FrgBase_Pnt<3>> poly);*/
};

EndForgVisualLib

#endif // !_FrgVisual_Tools_Header
