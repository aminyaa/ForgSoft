#pragma once
#ifndef _FrgVisual_BSPLineActor_Header
#define _FrgVisual_BSPLineActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_PolylineActor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

class Standard_Transient;

namespace ForgBaseLib
{
	template<int Dim>
	class FrgBase_Pnt;
}

namespace opencascade
{
	template <class T>
	class handle;
}

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_BSPLineActor_Entity
	: public QObject
{

	Q_OBJECT

public:

	FrgVisual_BSPLineActor_Entity();

protected slots:

	virtual void CtrlPtsSelectionHasChangedSlot() {}
	virtual void CtrlPtsDataHasChangedSlot() {}


};

template<int Dim>
class FORGVISUAL_EXPORT FrgVisual_BSPLineActor
	: public FrgVisual_BSPLineActor_Entity
	, public FrgVisual_PolylineActor<Dim>
{

	typedef FrgVisual_PolylineActor<Dim> SuperClass;

public:

	FrgVisual_BSPLineActor();

	~FrgVisual_BSPLineActor();

	static FrgVisual_BSPLineActor* New();
	vtkTypeMacro(FrgVisual_BSPLineActor, FrgVisual_PolylineActor<Dim>);

	//void SetData(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> ctrlPts, int degree, bool drawCtrlPts = true);
	void SetData(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ctrlPts, int degree);

	void SetDataInterpolate(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> pts, int degree);

	void AddNextPoint(ForgBaseLib::FrgBase_Pnt<Dim> pt) override;
	void SetLastPoint(ForgBaseLib::FrgBase_Pnt<Dim> pt) override;

	template <typename = typename std::enable_if_t<Dim == 2>>
	void AddNextPoint(double x, double y);
	template <typename = typename std::enable_if_t<Dim == 2>>
	void SetLastPoint(double x, double y);

	template <typename = typename std::enable_if_t<Dim == 3>>
	void AddNextPoint(double x, double y, double z);
	template <typename = typename std::enable_if_t<Dim == 3>>
	void SetLastPoint(double x, double y, double z);

	void RemoveLastPoint() override;
	void ShowPoints(bool condition = true) override;

	long long GetNumberOfCtrlPts();

	//void UpdateActor() override;

	//void DrawCtrlPts(bool drawCtrlPts = true);

	//void TranslateActor(double dx, double dy) override;
	//void TranslateActor(double dx, double dy, double dz) override;

	//bool SelectActor(const QColor& color) override;
	//bool UnSelectActor() override;

	//FrgVisual_PolylineActor<Dim>* GetCtrlPtsPolyLine() const { return theCtrlPtsPolyLine_; }

	void SetRenderer(vtkRenderer* renderer) override;
	void SetSelectable(bool selectable = true) override;
	void RemoveActors(vtkRenderer* renderer) override;

	ActorType GetActorType() const override;
	std::vector<ActorType> GetActorTypes() const override;
	ActorDimension GetActorDimension() const override;

private:

	DECLARE_SAVE_LOAD_HEADER( )

protected:
	
	//void CtrlPtsSelectionHasChangedSlot() override;
	//void CtrlPtsDataHasChangedSlot() override;

private:

	std::vector<double> CalculateKnots(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ctrlPts, int degree, bool isPeriodic);
	std::vector<int> CalculateMultiplicities(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ctrlPts, int degree, bool isPeriodic);
	//void CalculateKnotsAndMultiplicities(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> ctrlPts);
	//void CreateBSPLineCurve(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> ctrlPts, std::vector<double> theKnots, std::vector<int> theMultiplicities);
	void CreateBSPLineCurve(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ctrlPts, std::vector<double> theKnots, std::vector<int> theMultiplicities, int degree, bool isPerodic);
	//std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> CalculatePointsOnCurve() const;
	std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> CalculatePointsOnCurve();
	//std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> CalculatePointsOnCurve(double epsilon);

	//std::vector<ForgVisualLib::FrgVisual_PointActor<Dim>*> GetCtrlPts() const;
	std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> GetCtrlPts();

	std::vector<double> CalcBasisFunctionVector(std::vector<double> knots, int i, int p, double u) const;
	double CalcBasisFunction(std::vector<double> knots, int i, int p, double u) const;

	int FindSpan(int n, int p, double u, std::vector<double> knots);

	std::vector<double> CalcKnotBarEquallySpaced(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> Q);
	std::vector<double> CalcKnotBarChordLength(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> Q);
	std::vector<double> CalcKnotBarCentripetal(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> Q);
	std::vector<double> CalcKnotVector(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> Q, std::vector<double> knotsBar, int degree);
	std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> Interpolate(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> Q, int degree);

private:

	int theDegree_;

	//std::vector<double> theKnots_;
	//std::vector<int> theMultiplicities_;

	std::vector<FrgVisual_PointActor<Dim>*> theCtrlPts_;
	//std::vector<FrgVisual_PointActor<Dim>*> thePts_;
	FrgVisual_PolylineActor<Dim>* theCtrlPtsPolyLine_ = nullptr;
};
EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_BSPLineActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_BSPLineActor<3>)

#include <FrgVisual_BSPLineActorI.hxx>

#endif // !_FrgVisual_BSPLineActor_Header
