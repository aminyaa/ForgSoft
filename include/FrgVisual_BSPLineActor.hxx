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
class FrgVisual_BSPLineActor
	: public FrgVisual_BSPLineActor_Entity
	, public FrgVisual_PolylineActor<Dim>
{

	typedef FrgVisual_PolylineActor<Dim> SuperClass;

public:

	FORGVISUAL_EXPORT FrgVisual_BSPLineActor();

	FORGVISUAL_EXPORT ~FrgVisual_BSPLineActor();

	static FORGVISUAL_EXPORT FrgVisual_BSPLineActor* New();
	vtkTypeMacro(FrgVisual_BSPLineActor, FrgVisual_PolylineActor<Dim>);

	FORGVISUAL_EXPORT void SetData(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> ctrlPts, int degree, bool drawCtrlPts = true);

	FORGVISUAL_EXPORT void UpdateActor() override;

	FORGVISUAL_EXPORT void DrawCtrlPts(bool drawCtrlPts = true);

	FORGVISUAL_EXPORT void TranslateActor(double dx, double dy) override;
	FORGVISUAL_EXPORT void TranslateActor(double dx, double dy, double dz) override;

	FORGVISUAL_EXPORT bool SelectActor(const QColor& color) override;
	FORGVISUAL_EXPORT bool UnSelectActor() override;

	FrgVisual_PolylineActor<Dim>* GetCtrlPtsPolyLine() const { return theCtrlPtsPolyLine_; }

	FORGVISUAL_EXPORT void SetRenderer(vtkRenderer* renderer) override;

	FORGVISUAL_EXPORT void SetSelectable(bool selectable = true) override;

	FORGVISUAL_EXPORT void RemoveActors(vtkRenderer* renderer) override;

	int GetNumberOfDiscretization() const { return theNumberOfDiscretization_; }
	void SetNumberOfDiscretization(int nb) { theNumberOfDiscretization_ = nb; }

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)

protected:
	
	FORGVISUAL_EXPORT void CtrlPtsSelectionHasChangedSlot() override;
	FORGVISUAL_EXPORT void CtrlPtsDataHasChangedSlot() override;

private:

	FORGVISUAL_EXPORT void CalculateKnotsAndMultiplicities(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> ctrlPts);
	FORGVISUAL_EXPORT void CreateBSPLineCurve(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> ctrlPts, std::vector<double> theKnots, std::vector<int> theMultiplicities);
	FORGVISUAL_EXPORT std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> CalculatePointsOnCurve() const;

	FORGVISUAL_EXPORT std::vector<ForgVisualLib::FrgVisual_PointActor<Dim>*> GetCtrlPts() const;

private:

	int theDegree_;
	int theNumberOfDiscretization_;

	std::vector<double> theKnots_;
	std::vector<int> theMultiplicities_;

	Standard_Transient* theBSPLineCurve_ = nullptr;

	FrgVisual_PolylineActor<Dim>* theCtrlPtsPolyLine_ = nullptr;
};
EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_BSPLineActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_BSPLineActor<3>)

#include <FrgVisual_BSPLineActorI.hxx>

#endif // !_FrgVisual_BSPLineActor_Header
