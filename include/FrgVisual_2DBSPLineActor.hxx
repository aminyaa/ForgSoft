//#pragma once
//#ifndef _FrgVisual_2DBSPLineActor_Header
//#define _FrgVisual_2DBSPLineActor_Header
//
//#include <FrgVisual_Global.hxx>
//#include <FrgVisual_2DPolylineActor.hxx>
//
//#include <FrgVisual_Serialization_Global.hxx>
//
//class Geom2d_BSplineCurve;
//
//namespace ForgBaseLib
//{
//	class FrgBase_Pnt2d;
//}
//
//BeginForgVisualLib
//
//class FORGVISUAL_EXPORT FrgVisual_2DBSPLineActor
//	: public FrgVisual_2DPolylineActor
//{
//
//	Q_OBJECT
//
//	typedef FrgVisual_2DPolylineActor SuperClass;
//
//public:
//
//	FrgVisual_2DBSPLineActor();
//
//	~FrgVisual_2DBSPLineActor();
//
//	static FrgVisual_2DBSPLineActor* New();
//	vtkTypeMacro(FrgVisual_2DBSPLineActor, FrgVisual_2DPolylineActor);
//
//	void SetLineWidth(float width);
//	void SetRenderLinesAsTubes(bool condition);
//
//	void SetData(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d>> ctrlPts, int degree, bool drawCtrlPts = true);
//
//	void DrawCtrlPts(bool drawCtrlPts = true);
//
//	void TranslateActor(double dx, double dy, double dz) override;
//
//	bool SelectActor(const QColor& color) override;
//	bool UnSelectActor() override;
//
//private:
//
//	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)
//
//private:
//
//	void CalculateKnots(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d>> ctrlPts);
//	void CalculateMultiplicities(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d>> ctrlPts);
//
//	std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d>> GetCtrlPts() const;
//
//public slots:
//
//	void CtrlPtsSelectionHasChangedSlot();
//	void CtrlPtsDataHasChangedSlot();
//
//private:
//
//	int theDegree_;
//
//	//std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt2d>> theCtrlPts_;
//	Geom2d_BSplineCurve* theBSPLineCurve_ = nullptr;
//
//	std::vector<double> theKnots_;
//	std::vector<int> theMultiplicities_;
//
//	int theNumberOfDiscretization_;
//
//	FrgVisual_2DPolylineActor* theCtrlPtsPolyLine_ = nullptr;
//};
//
//EndForgVisualLib
//
//BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_2DBSPLineActor)
//
//#endif // !_FrgVisual_2DBSPLineActor_Header
