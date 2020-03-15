#pragma once
#ifndef _FrgVisual_Plot2D_Header
#define _FrgVisual_Plot2D_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Plot.hxx>

class vtkPlot;

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_Plot2D
	: public FrgVisual_Plot
{

public:

	FrgVisual_Plot2D
	(
		ForgBaseLib::FrgBase_MainWindow* parentMainWindow
	);

	vtkPlot* AddPlot(QList<double>& x, QList<double>& y,const char* title);
	vtkPlot* AddPlot(std::vector<double>& x, std::vector<double>& y, const char* title);

	// Add some predefined function such as Sin(x), Cos(x)
	vtkPlot* AddSinX(const char* title);
	vtkPlot* AddCosX(const char* title);

	void SetLegendVisible(bool condition);
	void SetBottomTitle(const char* title);
	void SetLeftTitle(const char* title);

protected:

	void Init() override;
};

EndForgVisualLib


#endif // !_FrgVisual_Plot2D_Header
