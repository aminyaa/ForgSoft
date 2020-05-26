#include <FrgVisual_Plot.hxx>
#include <FrgBase_MainWindow.hxx>

#include <vtkContextView.h>
#include <vtkAutoInit.h>
#include <vtkChartXY.h>

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
{
	
}

void ForgVisualLib::FrgVisual_Plot::RenderView() const
{
	if (theView_)
		theView_->Render();
}

bool ForgVisualLib::FrgVisual_Plot::RemovePlot(vtkPlot * plot)
{
	if (theChart_)
	{
		return theChart_->RemovePlotInstance(plot);
	}
}