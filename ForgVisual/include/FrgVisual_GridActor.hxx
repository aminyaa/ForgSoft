#pragma once
#ifndef _FrgVisual_2DGridActor_Header
#define _FrgVisual_2DGridActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_CurveActor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

namespace ForgBaseLib
{
	template<int Dim>
	class FrgBase_Pnt;
}

BeginForgVisualLib

template<int Dim>
class FrgVisual_LineActor;

class FORGVISUAL_EXPORT FrgVisual_GridActor
	: public FrgVisual_CurveActor<2>
{

	typedef FrgVisual_CurveActor<2> SuperClass;

public:

	FrgVisual_GridActor();

	static FrgVisual_GridActor* New();
	vtkTypeMacro(FrgVisual_GridActor, FrgVisual_CurveActor<2>);

	~FrgVisual_GridActor();

	const std::shared_ptr<ForgBaseLib::FrgBase_Pnt<2>>& GetCenter() const { return theCenter_; }
	
	double GetL1() const { return theL1_; }
	double GetL2() const { return theL2_; }

	int GetNumberOfDivisions1() const { return theNumberOfDivisions1_; }
	int GetNumberOfDivisions2() const { return theNumberOfDivisions2_; }

	void SetData(const std::shared_ptr<ForgBaseLib::FrgBase_Pnt<2>>& center, double L1, double L2, int numberOfDivisions1, int numberOfDivisions2, bool XYLines = false);
	void SetData(double xCenter, double yCenter, double L1, double L2, int numberOfDivisions1, int numberOfDivisions2, bool XYLines = false);

	FrgVisual_LineActor<2>* GetXLine() const { return theXLine_; }
	FrgVisual_LineActor<2>* GetYLine() const { return theYLine_; }

	void SetVisibility(vtkTypeBool _arg) override;
	void VisibilityOn() override;
	void VisibilityOff() override;

	ActorType GetActorType() const override;
	std::vector<ActorType> GetActorTypes() const override;
	ActorDimension GetActorDimension() const override;

private:

	DECLARE_SAVE_LOAD_HEADER( )

protected:

	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<2>> theCenter_;
	FrgVisual_LineActor<2>* theXLine_ = nullptr;
	FrgVisual_LineActor<2>* theYLine_ = nullptr;

	double theL1_;
	double theL2_;

	int theNumberOfDivisions1_;
	int theNumberOfDivisions2_;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_GridActor)

#endif // !_FrgVisual_2DGridActor_Header
