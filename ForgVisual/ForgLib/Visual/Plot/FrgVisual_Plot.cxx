#include <FrgVisual_Plot.hxx>
#include <FrgVisual_Plot2D_ChartXY.hxx>
#include <FrgBase_MainWindow.hxx>

#include <vtkContextView.h>
#include <vtkAutoInit.h>

VTK_MODULE_INIT(vtkRenderingContextOpenGL2)
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)
VTK_MODULE_INIT(vtkRenderingFreeType)
VTK_MODULE_INIT(vtkRenderingGL2PSOpenGL2)

ForgVisualLib::FrgVisual_Plot::FrgVisual_Plot
(
	ForgBaseLib::FrgBase_MainWindow * parentMainWindow
)
	: QVTKOpenGLNativeWidget(parentMainWindow)
	, theParentMainWindow_(parentMainWindow)
{
	
}

void ForgVisualLib::FrgVisual_Plot::RenderView() const
{
	if (theView_)
	{
		theView_->Render();
		theChart_->FitWindowToBoundingBox();
	}
}

bool ForgVisualLib::FrgVisual_Plot::RemovePlot(vtkPlot * plot)
{
	if (theChart_)
	{
		bool ok = theChart_->RemovePlotInstance(plot);
		theChart_->RecalculateAndUpdateBoundingBox();

		return ok;
	}

	return false;
}

void ForgVisualLib::FrgVisual_Plot::SetParentMainWindow(ForgBaseLib::FrgBase_MainWindow * parentMainWindow)
{
	theParentMainWindow_ = parentMainWindow;
	this->setParent(parentMainWindow);

	SetThemeDark(parentMainWindow->IsThemeDark());
}