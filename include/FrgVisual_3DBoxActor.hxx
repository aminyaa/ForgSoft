//#pragma once
//#ifndef _FrgVisual_3DBoxActor_Header
//#define _FrgVisual_3DBoxActor_Header
//
//#include <FrgVisual_Global.hxx>
//#include <FrgVisual_3DConicActor.hxx>
//
//#include <FrgVisual_Serialization_Global.hxx>
//
//namespace ForgBaseLib
//{
//	class FrgBase_Pnt3d;
//}
//
//BeginForgVisualLib
//
//class FORGVISUAL_EXPORT FrgVisual_3DBoxActor
//	: public FrgVisual_3DConicActor
//{
//	typedef FrgVisual_3DConicActor SuperClass;
//
//public:
//
//	FrgVisual_3DBoxActor();
//
//	static FrgVisual_3DBoxActor* New();
//	vtkTypeMacro(FrgVisual_3DBoxActor, FrgVisual_3DConicActor);
//
//	void SetRepresentationToPoints();
//	void SetRepresentationToSurface();
//	void SetRepresentationToWireframe();
//
//	void SetEdgeColor(double red, double green, double blue);
//
//	void SetData(std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> P0, std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> P1);
//
//private:
//
//	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)
//
//private:
//
//	std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> theP0_;
//	std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> theP1_;
//};
//
//EndForgVisualLib
//
//BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_3DBoxActor)
//
//#endif // !_FrgVisual_3DBoxActor_Header
