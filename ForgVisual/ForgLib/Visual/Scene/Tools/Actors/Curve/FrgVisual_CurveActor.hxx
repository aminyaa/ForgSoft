#pragma once
#ifndef _FrgVisual_CurveActor_Header
#define _FrgVisual_CurveActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_BaseActor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

#include <Standard_Handle.hxx>

BeginForgVisualLib

template<int Dim>
class FORGVISUAL_EXPORT FrgVisual_CurveActor
	: public FrgVisual_BaseActor<Dim>
{
	typedef FrgVisual_BaseActor<Dim> SuperClass;

public:

	FrgVisual_CurveActor();

	//static FrgVisual_CurveActor* New();
	vtkTypeMacro(FrgVisual_CurveActor, FrgVisual_BaseActor<Dim>);

	virtual float GetLineWidth() const;
	virtual void SetLineWidth(float width);

	virtual float GetSelectionLineWidth() const;
	virtual void SetSelectionLineWidth(float width);

	virtual bool IsRenderLinesAsTubes() const;
	virtual void SetRenderLinesAsTubes(bool condition);

	void SetStippledLine(int lineStipplePattern, bool condition = true);

	bool SelectActor(const QColor& color) override;
	bool UnSelectActor() override;

	const bool& IsStippled() const { return theIsStippled_; }
	const int& GetLineStipplePattern() const { return theLineStipplePattern_; }

	virtual const opencascade::handle<Standard_Transient>& GetCurve() const { return theCurve_; }

private:

	DECLARE_SAVE_LOAD_HEADER()

protected:

	opencascade::handle<Standard_Transient> theCurve_ = nullptr;

protected:

	bool theIsStippled_;
	int theLineStipplePattern_;
	float theLineWidth_ = 1.0f;
	float theSelectionLineWidth_ = 1.5f;
	bool theRenderLinesAsTubes_ = false;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_CurveActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_CurveActor<3>)

#include <FrgVisual_CurveActorI.hxx>

#endif // !_FrgVisual_CurveActor_Header
