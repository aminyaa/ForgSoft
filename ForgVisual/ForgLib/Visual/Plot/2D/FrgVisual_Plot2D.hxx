#pragma once
#ifndef _FrgVisual_Plot2D_Header
#define _FrgVisual_Plot2D_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Plot.hxx>

#include <FrgVisual_Serialization_Global.hxx>

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
	bool GetLegendVisible() const;

	void SetBottomAxisTitle(const char* title);
	const char* GetBottomAxisTitle() const;

	void SetLeftAxisTitle(const char* title);
	const char* GetLeftAxisTitle() const;

	void SetBottomAxisVisible(bool condition);
	bool GetBottomAxisVisible() const;

	void SetLeftAxisVisible(bool condition);
	bool GetLeftAxisVisible() const;

	void SetBottomAxisTitleVisible(bool condition);
	bool GetBottomAxisTitleVisible() const;

	void SetLeftAxisTitleVisible(bool condition);
	bool GetLeftAxisTitleVisible() const;

	void SetBottomAxisLogarithmic(bool condition);
	bool GetBottomAxisLogarithmic() const;

	void SetLeftAxisLogarithmic(bool condition);
	bool GetLeftAxisLogarithmic() const;

	void SetBottomAxisTitleRotation(int degree);
	int GetBottomAxisTitleRotation() const;

	void SetLeftAxisTitleRotation(int degree);
	int GetLeftAxisTitleRotation() const;

	void HighlightBottomAxisTitle(bool condition);
	void HighlightLeftAxisTitle(bool condition);

	void HighlightBottomAxis(bool condition);
	void HighlightLeftAxis(bool condition);

	void SetLegendPosition(LEGEND_POSITION_ENUM position);
	LEGEND_POSITION_ENUM GetLegendPosition() const;

	bool ExportDataAsCSV(std::string myFileName);
	bool ExportDataAsImage(QString myFileName);

protected:

	void Init() override;

private:

	void SetAxisVisible(int axisNumber, bool condition);
	bool GetAxisVisible(int axisNumber) const;

	void SetAxisTitleVisible(int axisNumber, bool condition);
	bool GetAxisTitleVisible(int axisNumber) const;

	void SetAxisLogarithmic(int axisNumber, bool condition);
	bool GetAxisLogarithmic(int axisNumber) const;

	void SetAxisTitleRotation(int axisNumber, int degree);
	int GetAxisTitleRotation(int axisNumber) const;

	void HighlightAxisTitle(int axisNumber, bool condition);

	void HighlightAxis(int axisNumber, bool condition);

	static QColor* theHighlightColor_;

	//vtkTextProperty* theAxisTitlePropertyCopy_ = nullptr;
	QColor* theHighlightBottomAxisTitleColor_ = nullptr;
	QColor* theHighlightLeftAxisTitleColor_ = nullptr;

	QColor* theHighlightBottomAxisColor_ = nullptr;
	QColor* theHighlightLeftAxisColor_ = nullptr;

	QString theBottomAxisTitle_;
	QString theLeftAxisTitle_;
};

EndForgVisualLib


#endif // !_FrgVisual_Plot2D_Header
