#pragma once
#ifndef _FrgVisual_Plot2D_Header
#define _FrgVisual_Plot2D_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Plot.hxx>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_Plot2D
	: public FrgVisual_Plot
{

public:

	FrgVisual_Plot2D
	(
		ForgBaseLib::FrgBase_MainWindow* parentMainWindow
	);

	void AddChart(QList<double>& x, QList<double>& y, FrgString xTitle, FrgString yTitle);

	// Add some predefined function such as Sin(x), Cos(x)
	void AddSinX();
	void AddCosX();

protected:

	void Init() override;
};

EndForgVisualLib


#endif // !_FrgVisual_Plot2D_Header
