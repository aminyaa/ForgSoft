#pragma once
#ifndef _FrgVisual_Plot2D_Header
#define _FrgVisual_Plot2D_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Plot.hxx>

class vtkPlot;
class QColor;

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

	void SetBottomAxisTitle(const char* title);
	void SetLeftAxisTitle(const char* title);

	void SetBottomAxisVisible(bool condition);
	void SetLeftAxisVisible(bool condition);

	void SetBottomAxisTitleVisible(bool condition);
	void SetLeftAxisTitleVisible(bool condition);

	void SetBottomAxisLogarithmic(bool condition);
	void SetLeftAxisLogarithmic(bool condition);

	void SetBottomAxisTitleRotation(int degree);
	void SetLeftAxisTitleRotation(int degree);

	void HighlightBottomAxisTitle(bool condition);
	void HighlightLeftAxisTitle(bool condition);

	void HighlightBottomAxis(bool condition);
	void HighlightLeftAxis(bool condition);

protected:

	void Init() override;

private:

	void SetAxisVisible(int axisNumber, bool condition);
	void SetAxisTitleVisible(int axisNumber, bool condition);
	void SetAxisLogarithmic(int axisNumber, bool condition);
	void SetAxisTitleRotation(int axisNumber, int degree);
	void HighlightAxisTitle(int axisNumber, bool condition);
	void HighlightAxis(int axisNumber, bool condition);

	static QColor* theHighlightColor_;

	//vtkTextProperty* theAxisTitlePropertyCopy_ = nullptr;
	QColor* theHighlightBottomAxisTitleColor_ = nullptr;
	QColor* theHighlightLeftAxisTitleColor_ = nullptr;

	QColor* theHighlightBottomAxisColor_ = nullptr;
	QColor* theHighlightLeftAxisColor_ = nullptr;
};

EndForgVisualLib


#endif // !_FrgVisual_Plot2D_Header
