//#pragma once
//#ifndef _FrgVisual_2DLineActor_Header
//#define _FrgVisual_2DLineActor_Header
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
//class FORGVISUAL_EXPORT FrgVisual_2DLineActor
//	: public FrgVisual_2DCurveActor
//{
//
//	typedef FrgVisual_2DCurveActor SuperClass;
//
//public:
//
//	FrgVisual_2DLineActor();
//
//	~FrgVisual_2DLineActor();
//
//	static FrgVisual_2DLineActor* New();
//	vtkTypeMacro(FrgVisual_2DLineActor, FrgVisual_2DCurveActor);
//
//	void SetData(std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d> P0, std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d> P1);
//	void SetData(double P0_X, double P0_Y, double P1_X, double P1_Y);
//
//	std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d> GetP0() const { return theP0_; }
//	std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d> GetP1() const { return theP1_; }
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
//BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_2DLineActor)
//
//#endif // !_FrgVisual_2DLineActor_Header
