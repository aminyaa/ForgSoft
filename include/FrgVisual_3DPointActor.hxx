//#pragma once
//#ifndef _FrgVisual_3DPointActor_Header
//#define _FrgVisual_3DPointActor_Header
//
//#include <FrgVisual_Global.hxx>
//#include <FrgVisual_PointActor.hxx>
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
//class FORGVISUAL_EXPORT FrgVisual_3DPointActor
//	: public FrgVisual_PointActor
//{
//
//	typedef FrgVisual_PointActor SuperClass;
//
//public:
//
//	static FrgVisual_3DPointActor* New();
//	vtkTypeMacro(FrgVisual_3DPointActor, FrgVisual_PointActor);
//
//	~FrgVisual_3DPointActor();
//
//	void SetData(std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> pt);
//	void SetData(double x, double y, double z);
//
//	std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> GetData() const { return theP_; }
//
//	void TranslateActor(double dx, double dy, double dz) override;
//
//private:
//
//	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)
//
//protected:
//
//	FrgVisual_3DPointActor();
//
//private:
//
//	std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> theP_;
//};
//
//EndForgVisualLib
//
//BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_3DPointActor)
//
//#endif // !_FrgVisual_3DPointActor_Header
