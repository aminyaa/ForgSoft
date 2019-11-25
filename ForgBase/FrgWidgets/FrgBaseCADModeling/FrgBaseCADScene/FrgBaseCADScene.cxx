#include <FrgBaseCADScene.hxx>

#include <FrgBaseTree.hxx>
#include <FrgBaseMainWindow.hxx>
#include <FrgBaseInteractorStyle.hxx>
#include <FrgBasePlot2D.hxx>

#include <vtkRenderer.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkRenderWindow.h>
#include <vtkCamera.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkProperty.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkAxesActor.h>
#include <vtkTransform.h>
#include<vtkOrientationMarkerWidget.h>
#include <vtkUnstructuredGrid.h>
#include <vtkDataSetMapper.h>
#include <vtkCellType.h>
#include <vtkDoubleArray.h>
#include <vtkRectilinearGrid.h>
#include <vtkRectilinearGridGeometryFilter.h>
#include <vtkPolyDataMapper.h>

#include <vtkAutoInit.h>

VTK_MODULE_INIT(vtkRenderingContextOpenGL2)
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)
VTK_MODULE_INIT(vtkRenderingFreeType)

ForgBaseLib::FrgBaseCADScene::FrgBaseCADScene(FrgBaseTree* parentTree)
	: QVTKOpenGLNativeWidget(parentTree->GetParentMainWindow())
	, theParentTree_(parentTree)
{
	Init();
}

void ForgBaseLib::FrgBaseCADScene::Init()
{
	theRenderer_ = vtkSmartPointer<vtkRenderer>::New();
	theRenderer_->SetBackground(0.862, 0.862, 0.862); // (Gainsboro) Color

	theRenderWindow_ = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();

	theRenderWindow_->AddRenderer(theRenderer_);

	theRenderWindowInteractor_ = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	theRenderWindowInteractor_->SetRenderWindow(theRenderWindow_);

	theInteractorStyle_ = vtkSmartPointer<FrgBaseInteractorStyle>::New();

	theInteractorStyle_->SetParent(this);

	theInteractorStyle_->SetMouseWheelMotionFactor(0.5);

	theRenderWindowInteractor_->SetInteractorStyle(theInteractorStyle_);

	vtkSmartPointer<vtkAxesActor> axes =
		vtkSmartPointer<vtkAxesActor>::New();

	axes->PickableOff();

	vtkSmartPointer<vtkOrientationMarkerWidget> widget =
		vtkSmartPointer<vtkOrientationMarkerWidget>::New();

	widget->SetOutlineColor(0.9300, 0.5700, 0.1300);
	widget->SetOrientationMarker(axes);
	widget->SetInteractor(theRenderWindowInteractor_);
	widget->SetViewport(0.0, 0.0, 0.25, 0.25);
	widget->SetEnabled(1);
	widget->InteractiveOn();

	// Create a TextActor
	theLogoActor_ = vtkSmartPointer<vtkTextActor>::New();
	theLogoActor_->SetInput("Forg++");
	vtkTextProperty* tprop = theLogoActor_->GetTextProperty();
	tprop->SetFontFamilyToArial();
	tprop->ShadowOff();

	tprop->SetLineSpacing(1.0);
	tprop->SetFontSize(24);
	tprop->SetFontFamilyToArial();
	tprop->ShadowOn();
	tprop->SetColor(0, 0, 0); // (Black) Color

	theLogoActor_->SetDisplayPosition(20, 20);
	theRenderer_->AddActor2D(theLogoActor_);

	theCamera_ = vtkSmartPointer<vtkCamera>::New();
	theRenderer_->LightFollowCameraOn();
	theRenderer_->TwoSidedLightingOn();
}

void ForgBaseLib::FrgBaseCADScene::Render()
{
	theCamera_->SetPosition(0, 1, 0);
	theCamera_->SetFocalPoint(0, 0, 0);
	theCamera_->SetViewUp(0, 0, 1);
	theCamera_->Azimuth(-180);

	theRenderer_->SetActiveCamera(theCamera_);
	theRenderer_->ResetCamera();
	theRenderer_->ResetCameraClippingRange();

	this->SetRenderWindow(theRenderWindow_);

	theRenderWindow_->Render();
	theRenderWindowInteractor_->Initialize();
}

void ForgBaseLib::FrgBaseCADScene::StartScene()
{

}

void ForgBaseLib::FrgBaseCADScene::DrawGrid(int nX, int nY)
{
	const auto& bounds = GetRenderer()->ComputeVisiblePropBounds();
	double Xmin = bounds[0], Xmax = bounds[1];
	double Ymin = bounds[2], Ymax = bounds[3];
	double MaxDiff = (Xmax - Xmin) > (Ymax - Ymin) ? (Xmax - Xmin) : (Ymax - Ymin);
	double dX = (Xmax - Xmin) / ((double)(nX - 1));
	double dY = (Ymax - Ymin) / ((double)(nY - 1));

	dX = dY = dX > dY ? dX : dY;

	vtkSmartPointer<vtkDoubleArray> xCoords =
		vtkSmartPointer<vtkDoubleArray>::New();
	for (int i = 0; i < nX; i++)
	{
		xCoords->InsertNextValue(i*dX - (MaxDiff / 2.0));
	}
	vtkSmartPointer<vtkDoubleArray> yCoords =
		vtkSmartPointer<vtkDoubleArray>::New();
	for (int i = 0; i < nY; i++)
	{
		yCoords->InsertNextValue(i*dY - (MaxDiff / 2.0));
	}
	vtkSmartPointer<vtkDoubleArray> zCoords =
		vtkSmartPointer<vtkDoubleArray>::New();
	for (int i = 0; i < 1; i++)
	{
		zCoords->InsertNextValue(0.0);
	}

	// The coordinates are assigned to the rectilinear grid. Make sure that
  // the number of values in each of the XCoordinates, YCoordinates,
  // and ZCoordinates is equal to what is defined in SetDimensions().
	vtkSmartPointer<vtkRectilinearGrid> rgrid =
		vtkSmartPointer<vtkRectilinearGrid>::New();
	rgrid->SetDimensions(nX, nY, 1);
	rgrid->SetXCoordinates(xCoords);
	rgrid->SetYCoordinates(yCoords);
	rgrid->SetZCoordinates(zCoords);

	vtkSmartPointer<vtkDataSetMapper> rgridMapper =
		vtkSmartPointer<vtkDataSetMapper>::New();
	//rgridMapper->SetInputConnection(plane->GetOutputPort());
	rgridMapper->SetInputData(rgrid);

	vtkSmartPointer<vtkNamedColors> colors =
		vtkSmartPointer<vtkNamedColors>::New();

	vtkSmartPointer<vtkActor> wireActor =
		vtkSmartPointer<vtkActor>::New();
	wireActor->SetMapper(rgridMapper);
	wireActor->GetProperty()->SetColor(colors->GetColor3d("alice_blue").GetData());
	wireActor->GetProperty()->EdgeVisibilityOn();

	GetRenderer()->AddActor(wireActor);
}