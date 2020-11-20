#pragma once
#ifndef _FrgVisual_CurveActor_Header
#define _FrgVisual_CurveActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_BaseActor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

BeginForgVisualLib

template<int Dim>
class FORGVISUAL_EXPORT FrgVisual_CurveActor
	: public FrgVisual_BaseActor<Dim>
{
	typedef FrgVisual_BaseActor<Dim> SuperClass;

public:

	FrgVisual_CurveActor();

	static FrgVisual_CurveActor* New();
	vtkTypeMacro(FrgVisual_CurveActor, FrgVisual_BaseActor<Dim>);

	virtual void SetLineWidth(float width);
	virtual float GetLineWidth();
	virtual void SetRenderLinesAsTubes(bool condition);

	void SetStippledLine(int lineStipplePattern, bool condition = true);

	bool SelectActor(const QColor& color) override;
	bool UnSelectActor() override;

	const bool& IsStippled() const { return theIsStippled_; }
	const int& GetLineStipplePattern() const { return theLineStipplePattern_; }

private:

	DECLARE_SAVE_LOAD_HEADER( )

protected:

	bool theIsStippled_;
	int theLineStipplePattern_;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_CurveActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_CurveActor<3>)

#include <FrgVisual_CurveActorI.hxx>

#endif // !_FrgVisual_CurveActor_Header
