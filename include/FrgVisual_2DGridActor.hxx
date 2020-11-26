//#pragma once
//#ifndef _FrgVisual_2DGridActor_Header
//#define _FrgVisual_2DGridActor_Header
//
//#include <FrgVisual_Global.hxx>
//#include <FrgVisual_GridActor.hxx>
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
//class FrgVisual_2DLineActor;
//
//class FORGVISUAL_EXPORT FrgVisual_2DGridActor
//	: public FrgVisual_GridActor
//{
//
//	typedef FrgVisual_GridActor SuperClass;
//
//public:
//
//	FrgVisual_2DGridActor();
//
//	static FrgVisual_2DGridActor* New();
//	vtkTypeMacro(FrgVisual_2DGridActor, FrgVisual_GridActor);
//
//	~FrgVisual_2DGridActor();
//
//	std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d> GetCenter() const { return theCenter_; }
//
//	void SetData(std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d> center, double L1, double L2, int numberOfDivisions1, int numberOfDivisions2, bool XYLines = false);
//	void SetData(double xCenter, double yCenter, double L1, double L2, int numberOfDivisions1, int numberOfDivisions2, bool XYLines = false);
//
//	FrgVisual_2DLineActor* GetXLine() const { return theXLine_; }
//	FrgVisual_2DLineActor* GetYLine() const { return theYLine_; }
//
//	void SetVisibility(vtkTypeBool _arg) override;
//	void VisibilityOn() override;
//	void VisibilityOff() override;
//
//private:
//
//	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)
//
//private:
//
//	std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d> theCenter_;
//	FrgVisual_2DLineActor* theXLine_ = nullptr;
//	FrgVisual_2DLineActor* theYLine_ = nullptr;
//};
//
//EndForgVisualLib
//
//BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_2DGridActor)
//
//#endif // !_FrgVisual_2DGridActor_Header
