//#pragma once
//#ifndef _FrgVisual_3DPolylineActor_Header
//#define _FrgVisual_3DPolylineActor_Header
//
//#include <FrgVisual_Global.hxx>
//#include <FrgVisual_3DCurveActor.hxx>
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
//class FrgVisual_3DPointActor;
//
//class FORGVISUAL_EXPORT FrgVisual_3DPolylineActor
//	: public FrgVisual_3DCurveActor
//{
//	typedef FrgVisual_3DCurveActor SuperClass;
//
//public:
//
//	FrgVisual_3DPolylineActor();
//
//	~FrgVisual_3DPolylineActor();
//
//	static FrgVisual_3DPolylineActor* New();
//	vtkTypeMacro(FrgVisual_3DPolylineActor, FrgVisual_3DCurveActor);
//
//	void SetData(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d>> pts);
//	void SetData(std::vector<FrgVisual_3DPointActor*> ptsActors);
//
//	std::vector<FrgVisual_3DPointActor*> GetPts() const { return thePts_; }
//
//private:
//
//	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)
//
//private:
//
//	std::vector<FrgVisual_3DPointActor*> thePts_;
//
//};
//
//EndForgVisualLib
//
//BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_3DPolylineActor)
//
//#endif // !_FrgVisual_3DPolylineActor_Header
