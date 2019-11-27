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
#include <vtkCaptionActor2D.h>
#include <vtkAxisActor2D.h>
#include <vtkProperty2D.h>

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
	//theRenderer_->SetBackground(0.95, 0.95, 0.95); // (Gainsboro) Color
	theRenderer_->SetBackground(1.0, 1.0, 1.0);
	theRenderer_->SetBackground2(0.8, 0.8, 0.8);
	theRenderer_->SetGradientBackground(true);

	theRenderWindow_ = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();

	theRenderWindow_->AddRenderer(theRenderer_);

	theRenderWindowInteractor_ = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	theRenderWindowInteractor_->SetRenderWindow(theRenderWindow_);

	theInteractorStyle_ = vtkSmartPointer<FrgBaseInteractorStyle>::New();

	theInteractorStyle_->SetParent(this);

	theInteractorStyle_->SetMouseWheelMotionFactor(0.5);

	theRenderWindowInteractor_->SetInteractorStyle(theInteractorStyle_);

	vtkAxesActor* axes = vtkAxesActor::New();

	axes->PickableOff();
	axes->SetShaftTypeToLine();

	vtkOrientationMarkerWidget* widget = vtkOrientationMarkerWidget::New();

	widget->SetOutlineColor(0.9300, 0.5700, 0.1300);
	widget->SetOrientationMarker(axes);
	widget->SetInteractor(theRenderWindowInteractor_);
	widget->SetViewport(0.0, 0.0, 0.4, 0.4);
	widget->SetEnabled(1);
	widget->InteractiveOff();

	// Create a TextActor
	theLogoActor_ = vtkSmartPointer<vtkTextActor>::New();
	theLogoActor_->SetInput("Forg");
	vtkTextProperty* tprop = theLogoActor_->GetTextProperty();
	tprop->SetFontFamilyToArial();
	tprop->ShadowOff();

	tprop->SetLineSpacing(1.0);
	tprop->SetFontSize(20);
	tprop->SetFontFamilyToArial();
	tprop->ShadowOn();
	tprop->SetColor(0, 0, 0); // (Black) Color

	theLogoActor_->SetDisplayPosition(20, 20);
	theRenderer_->AddActor2D(theLogoActor_);
	//theRenderer_->AddActor(axes);

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

void ForgBaseLib::FrgBaseCADScene::DrawGrid(int nbMajorDivision, int nbMinorDivision)
{
	const auto& bounds = GetRenderer()->ComputeVisiblePropBounds();
	DrawGrid(nbMajorDivision, FrgTrue, bounds);
	DrawGrid(nbMajorDivision*nbMinorDivision, FrgFalse, bounds);
}

void ForgBaseLib::FrgBaseCADScene::DrawGrid(int nbDivision, FrgBool isMajor, double* bounds)
{
	double Xmin = bounds[0], Xmax = bounds[1];
	double Ymin = bounds[2], Ymax = bounds[3];

	double LX = abs(Xmax - Xmin);
	double LY = abs(Ymax - Ymin);

	double L = LX > LY ? LX : LY;

	double d = 2.0 * L / (double)nbDivision;

	vtkSmartPointer<vtkDoubleArray> xCoords =
		vtkSmartPointer<vtkDoubleArray>::New();
	for (int i = 0; i <= nbDivision; i++)
		xCoords->InsertNextValue(i * d + (Xmin + LX / 2.0) - L);

	vtkSmartPointer<vtkDoubleArray> yCoords =
		vtkSmartPointer<vtkDoubleArray>::New();
	for (int i = 0; i <= nbDivision; i++)
		yCoords->InsertNextValue(i * d + (Ymin + LY / 2.0) - L);

	vtkSmartPointer<vtkDoubleArray> zCoords =
		vtkSmartPointer<vtkDoubleArray>::New();
	zCoords->InsertNextValue(0.0);

	vtkSmartPointer<vtkRectilinearGrid> rgrid =
		vtkSmartPointer<vtkRectilinearGrid>::New();
	rgrid->SetDimensions(nbDivision + 1, nbDivision + 1, 1);
	rgrid->SetXCoordinates(xCoords);
	rgrid->SetYCoordinates(yCoords);
	rgrid->SetZCoordinates(zCoords);

	vtkSmartPointer<vtkDataSetMapper> rgridMapper =
		vtkSmartPointer<vtkDataSetMapper>::New();
	rgridMapper->SetInputData(rgrid);

	vtkSmartPointer<vtkActor> wireActor =
		vtkSmartPointer<vtkActor>::New();
	wireActor->SetMapper(rgridMapper);
	wireActor->GetProperty()->SetRepresentationToWireframe();
	if(isMajor)
		wireActor->GetProperty()->SetLineWidth(2.0);
	else
		wireActor->GetProperty()->SetLineWidth(1.0);
	wireActor->GetProperty()->EdgeVisibilityOn();
	wireActor->GetProperty()->SetEdgeColor(1.0, 0.0, 0.0);
	wireActor->GetProperty()->SetRenderLinesAsTubes(true);
	wireActor->GetProperty()->SetAmbient(0.0);
	wireActor->GetProperty()->SetDiffuse(0.0);
	wireActor->GetProperty()->SetSpecular(0.0);

	GetRenderer()->AddActor(wireActor);
	GetActors().push_back(wireActor);
}