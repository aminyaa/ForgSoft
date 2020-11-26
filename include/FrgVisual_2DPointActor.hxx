//#pragma once
//#ifndef _FrgVisual_2DPointActor_Header
//#define _FrgVisual_2DPointActor_Header
//
//#include <FrgVisual_Global.hxx>
//#include <FrgVisual_PointActor.hxx>
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
//class FORGVISUAL_EXPORT FrgVisual_2DPointActor
//	: public FrgVisual_PointActor
//{
//
//	typedef FrgVisual_PointActor SuperClass;
//
//public:
//
//	static FrgVisual_2DPointActor* New();
//	vtkTypeMacro(FrgVisual_2DPointActor, FrgVisual_PointActor);
//
//	~FrgVisual_2DPointActor();
//
//	void SetData(std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d> pt);
//	void SetData(double x, double y);
//
//	std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d> GetData() const { return theP_; }
//
//	void TranslateActor(double dx, double dy, double dz) override;
//
//private:
//
//	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)
//
//protected:
//
//	FrgVisual_2DPointActor();
//
//	std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d> theP_;
//};
//
//EndForgVisualLib
//
//BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_2DPointActor)
//
//#endif // !_FrgVisual_2DPointActor_Header
