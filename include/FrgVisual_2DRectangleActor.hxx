//#pragma once
//#ifndef _FrgVisual_2DRectangleActor_Header
//#define _FrgVisual_2DRectangleActor_Header
//
//#include <FrgVisual_Global.hxx>
//#include <FrgVisual_2DConicActor.hxx>
//
//#include <FrgVisual_Serialization_Global.hxx>
//
//namespace ForgBaseLib
//{
//	class FrgBase_Pnt2d;
//}
//
//BeginForgVisualLib
//
//class FORGVISUAL_EXPORT FrgVisual_2DRectangleActor
//	: public FrgVisual_2DConicActor
//{
//	typedef FrgVisual_2DConicActor SuperClass;
//
//public:
//
//	FrgVisual_2DRectangleActor();
//
//	static FrgVisual_2DRectangleActor* New();
//	vtkTypeMacro(FrgVisual_2DRectangleActor, FrgVisual_2DConicActor);
//
//	void SetRepresentationToPoints();
//	void SetRepresentationToSurface();
//	void SetRepresentationToWireframe();
//
//	void SetEdgeColor(double red, double green, double blue);
//
//	void SetData(std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d> P0, std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d> P1);
//
//private:
//
//	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)
//
//private:
//
//	std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d> theP0_;
//	std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d> theP1_;
//};
//
//EndForgVisualLib
//
//BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_2DRectangleActor)
//
//#endif // !_FrgVisual_2DRectangleActor_Header
