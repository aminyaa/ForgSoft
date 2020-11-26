//#pragma once
//#ifndef _FrgVisual_2DPolylineActor_Header
//#define _FrgVisual_2DPolylineActor_Header
//
//#include <FrgVisual_Global.hxx>
//#include <FrgVisual_2DCurveActor.hxx>
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
//class FrgVisual_2DPointActor;
//
//class FORGVISUAL_EXPORT FrgVisual_2DPolylineActor
//	: public FrgVisual_2DCurveActor
//{
//	typedef FrgVisual_2DCurveActor SuperClass;
//
//public:
//
//	FrgVisual_2DPolylineActor();
//
//	~FrgVisual_2DPolylineActor();
//
//	static FrgVisual_2DPolylineActor* New();
//	vtkTypeMacro(FrgVisual_2DPolylineActor, FrgVisual_2DCurveActor);
//
//	void SetData(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d>> pts);
//	void SetData(std::vector<FrgVisual_2DPointActor*> ptsActors);
//
//	std::vector<FrgVisual_2DPointActor*> GetPts() const { return thePts_; }
//
//	void TranslateActor(double dx, double dy, double dz) override;
//
//private:
//
//	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)
//
//private:
//
//	std::vector<FrgVisual_2DPointActor*> thePts_;
//
//};
//
//EndForgVisualLib
//
//BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_2DPolylineActor)
//
//#endif // !_FrgVisual_2DPolylineActor_Header
