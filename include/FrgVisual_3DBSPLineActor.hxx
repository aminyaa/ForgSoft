//#pragma once
//#ifndef _FrgVisual_3DBSPLineActor_Header
//#define _FrgVisual_3DBSPLineActor_Header
//
//#include <FrgVisual_Global.hxx>
//#include <FrgVisual_3DPolylineActor.hxx>
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
//class FORGVISUAL_EXPORT FrgVisual_3DBSPLineActor
//	: public FrgVisual_3DPolylineActor
//{
//
//	typedef FrgVisual_3DPolylineActor SuperClass;
//
//public:
//
//	FrgVisual_3DBSPLineActor();
//
//	~FrgVisual_3DBSPLineActor();
//
//	static FrgVisual_3DBSPLineActor* New();
//	vtkTypeMacro(FrgVisual_3DBSPLineActor, FrgVisual_3DPolylineActor);
//
//	void SetLineWidth(float width);
//	void SetRenderLinesAsTubes(bool condition);
//
//	void SetData(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d>> ctrlPts, int degree, bool drawCtrlPts = true);
//
//	void DrawCtrlPts(bool drawCtrlPts = true);
//
//	std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d>> GetCtrlPts() const { return theCtrlPts_; }
//
//private:
//
//	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)
//
//	void CalculateKnots();
//	void CalculateMultiplicities();
//
//private:
//
//	int theDegree_;
//
//	std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d>> theCtrlPts_;
//
//	std::vector<double> theKnots_;
//	std::vector<int> theMultiplicities_;
//
//	int theNumberOfDiscretization_;
//
//	FrgVisual_3DPolylineActor* theCtrlPtsPolyLine_;
//};
//
//EndForgVisualLib
//
//BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_3DBSPLineActor)
//
//#endif // !_FrgVisual_3DBSPLineActor_Header
