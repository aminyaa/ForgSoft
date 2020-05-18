#include <FrgVisual_Scene3D.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgVisual_Scene_InterStyle3D.hxx>
#include <FrgBase_Pnt3d.hxx>
#include <FrgVisual_PointActor.hxx>
#include <FrgVisual_LineActor.hxx>
#include <FrgVisual_PolylineActor.hxx>
#include <FrgVisual_BoxActor.hxx>

#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkAxesActor.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkCamera.h>
#include <vtkLineSource.h>
#include <vtkPolyLine.h>
#include <vtkCubeSource.h>
#include <vtkAssemblyPath.h>

ForgVisualLib::FrgVisual_Scene3D::FrgVisual_Scene3D
(ForgBaseLib::FrgBase_MainWindow* parentMainWindow)
	: FrgVisual_Scene(parentMainWindow)
{
	
}

void ForgVisualLib::FrgVisual_Scene3D::Init()
{
	theRenderer_ = vtkSmartPointer<vtkRenderer>::New();
	theRenderer_->SetBackground(1.0, 1.0, 1.0);
	theRenderer_->SetBackground2(0.7, 0.7, 0.7);
	theRenderer_->SetGradientBackground(true);

	theRenderWindow_ = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();

	theRenderWindow_->AddRenderer(theRenderer_);

	theRenderWindowInteractor_ = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	theRenderWindowInteractor_->SetRenderWindow(theRenderWindow_);

	theInteractorStyle_ = vtkSmartPointer<FrgVisual_Scene_InterStyle3D>::New();
	//FrgVisual_Scene_InterStyle3D::SafeDownCast(theInteractorStyle_)->AddManipulator(FrgVisual_Scene_CameraManip::New());

	//theInteractorStyle_->SetParent(this);

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
	theLogoActor_->SetInput("Forg Soft");
	vtkTextProperty* tprop = theLogoActor_->GetTextProperty();
	tprop->SetFontFamilyToArial();
	tprop->ShadowOff();

	tprop->SetLineSpacing(1.0);
	tprop->SetFontSize(24);
	//tprop->SetFontFamilyToArial();
	tprop->BoldOn();
	tprop->SetFontFile(":/Fonts/swissek.ttf");
	tprop->ShadowOn();
	tprop->SetColor(0.91, 0.91, 0.91); // (Black) Color

	theLogoActor_->SetDisplayPosition(20, 20);
	theRenderer_->AddActor2D(theLogoActor_);
	//theRenderer_->AddActor(axes);

	theCamera_ = vtkSmartPointer<vtkCamera>::New();
	theRenderer_->LightFollowCameraOn();
	theRenderer_->TwoSidedLightingOn();

	RenderScene(true);
}

void ForgVisualLib::FrgVisual_Scene3D::RenderScene(bool resetCamera)
{
	if (resetCamera)
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
	else
		theRenderWindow_->Render();
}

ForgVisualLib::FrgVisual_PointActor* ForgVisualLib::FrgVisual_Scene3D::AddPoint
(
	ForgBaseLib::FrgBase_Pnt3d * pt,
	bool render
)
{
	if (!pt)
	{
		std::cout << "pt is null in ForgVisualLib::FrgVisual_PointActor* ForgVisualLib::FrgVisual_Scene3D::AddPoint\n";
		return nullptr;
	}

	return AddPoint(pt->X(), pt->Y(), pt->Z(), render);
}

ForgVisualLib::FrgVisual_PointActor* ForgVisualLib::FrgVisual_Scene3D::AddPoint
(
	double x,
	double y,
	double z,
	bool render
)
{
	// Create the geometry of a point (the coordinate)
	vtkSmartPointer<vtkPoints> points =
		vtkSmartPointer<vtkPoints>::New();

	// Create the topology of the point (a vertex)
	vtkSmartPointer<vtkCellArray> vertices =
		vtkSmartPointer<vtkCellArray>::New();
	// We need an an array of point id's for InsertNextCell.
	vtkIdType pid[1];
	pid[0] = points->InsertNextPoint(x, y, z);
	vertices->InsertNextCell(1, pid);

	// Create a polydata object
	vtkSmartPointer<vtkPolyData> point =
		vtkSmartPointer<vtkPolyData>::New();

	// Set the points and vertices we created as the geometry and topology of the polydata
	point->SetPoints(points);
	point->SetVerts(vertices);

	// Visualize
	vtkSmartPointer<vtkPolyDataMapper> mapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputData(point);

	vtkSmartPointer<FrgVisual_PointActor> actor =
		vtkSmartPointer<FrgVisual_PointActor>::New();

	//actor->SetP(pt);
	actor->SetMapper(mapper);
	actor->GetProperty()->SetColor(1.0, 0.0, 0.0);
	actor->GetProperty()->SetPointSize(5);
	actor->GetProperty()->SetRepresentationToPoints();
	actor->GetProperty()->SetRenderPointsAsSpheres(true);

	theRenderer_->AddActor(actor);

	if (render)
		RenderScene(false);

	return actor;
}

ForgVisualLib::FrgVisual_LineActor * ForgVisualLib::FrgVisual_Scene3D::AddLine
(
	ForgBaseLib::FrgBase_Pnt3d * P0,
	ForgBaseLib::FrgBase_Pnt3d * P1,
	bool render
)
{
	if (!P0 || !P1)
	{
		std::cout << "P0 or P1 or both of them is/are null in ForgVisualLib::FrgVisual_LineActor * ForgVisualLib::FrgVisual_Scene3D::AddLine()\n";
		return nullptr;
	}

	return AddLine(P0->X(), P0->Y(), P0->Z(), P1->X(), P1->Y(), P1->Z(), render);
}

ForgVisualLib::FrgVisual_LineActor * ForgVisualLib::FrgVisual_Scene3D::AddLine
(
	double P0_X,
	double P0_Y,
	double P0_Z,
	double P1_X,
	double P1_Y,
	double P1_Z,
	bool render
)
{
	vtkSmartPointer<vtkLineSource> lineSource =
		vtkSmartPointer<vtkLineSource>::New();
	lineSource->SetPoint1(P0_X, P0_Y, P0_Z);
	lineSource->SetPoint2(P1_X, P1_Y, P1_Z);

	vtkSmartPointer<vtkPolyDataMapper> mapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputConnection(lineSource->GetOutputPort());
	vtkSmartPointer<FrgVisual_LineActor> actor =
		vtkSmartPointer<FrgVisual_LineActor>::New();
	//actor->SetP0(P0);
	//actor->SetP1(P1);
	actor->SetMapper(mapper);
	actor->GetProperty()->SetLineWidth(1);
	actor->GetProperty()->SetColor(1.0, 0.0, 0.0);
	actor->GetProperty()->SetRenderLinesAsTubes(true);
	actor->GetProperty()->SetRepresentationToWireframe();

	theRenderer_->AddActor(actor);

	if (render)
		RenderScene(false);

	return actor;
}

ForgVisualLib::FrgVisual_PolylineActor * ForgVisualLib::FrgVisual_Scene3D::AddPolyline
(
	std::vector<ForgBaseLib::FrgBase_Pnt3d*> pts,
	bool render
)
{
	if (pts.size() == 0)
	{
		std::cout << "pts vector is empty in ForgVisualLib::FrgVisual_PolylineActor * ForgVisualLib::FrgVisual_Scene3D::AddPolyline()\n";
		return nullptr;
	}

	vtkSmartPointer<vtkPoints> points =
		vtkSmartPointer<vtkPoints>::New();

	for (int iPoint = 0; iPoint < pts.size(); iPoint++)
		points->InsertNextPoint(pts[iPoint]->X(), pts[iPoint]->Y(), pts[iPoint]->Z());

	vtkSmartPointer<vtkPolyLine> polyLine =
		vtkSmartPointer<vtkPolyLine>::New();
	polyLine->GetPointIds()->SetNumberOfIds(pts.size());
	for (unsigned int i = 0; i < pts.size(); i++)
		polyLine->GetPointIds()->SetId(i, i);

	// Create a cell array to store the lines in and add the lines to it
	vtkSmartPointer<vtkCellArray> cells =
		vtkSmartPointer<vtkCellArray>::New();
	cells->InsertNextCell(polyLine);

	// Create a polydata to store everything in
	vtkSmartPointer<vtkPolyData> polyData =
		vtkSmartPointer<vtkPolyData>::New();

	// Add the points to the dataset
	polyData->SetPoints(points);

	// Add the lines to the dataset
	polyData->SetLines(cells);

	// Setup actor and mapper
	vtkSmartPointer<vtkPolyDataMapper> mapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputData(polyData);

	vtkSmartPointer<FrgVisual_PolylineActor> actor =
		vtkSmartPointer<FrgVisual_PolylineActor>::New();
	//actor->SetPoints(pts);
	actor->SetMapper(mapper);
	actor->GetProperty()->SetColor(1.0, 0.0, 0.0);

	theRenderer_->AddActor(actor);
	
	if (render)
		RenderScene(false);

	return actor;
}

ForgVisualLib::FrgVisual_BoxActor * ForgVisualLib::FrgVisual_Scene3D::AddBox
(
	ForgBaseLib::FrgBase_Pnt3d * P0,
	ForgBaseLib::FrgBase_Pnt3d * P1,
	bool render
)
{
	if (!P0 || !P1)
	{
		std::cout << "P0 or P1 or both of them is/are null in ForgVisualLib::FrgVisual_BoxActor * ForgVisualLib::FrgVisual_Scene3D::AddBox()\n";
		return nullptr;
	}

	return AddBox(P0->X(), P0->Y(), P0->Z(), P1->X(), P1->Y(), P1->Z(), render);
}

ForgVisualLib::FrgVisual_BoxActor * ForgVisualLib::FrgVisual_Scene3D::AddBox
(
	double P0_X,
	double P0_Y,
	double P0_Z,
	double P1_X,
	double P1_Y,
	double P1_Z,
	bool render
)
{
	// Create a cube.
	vtkNew<vtkCubeSource> cube;
	cube->SetBounds(P0_X, P1_X, P0_Y, P1_Y, P0_Z, P1_Z);
	cube->Update();

	// mapper
	vtkNew<vtkPolyDataMapper> cubeMapper;
	cubeMapper->SetInputData(cube->GetOutput());

	// Actor.
	vtkNew<FrgVisual_BoxActor> cubeActor;
	//cubeActor->SetP0(P0);
	//cubeActor->SetP1(P1);
	cubeActor->SetMapper(cubeMapper);
	cubeActor->GetProperty()->SetColor(1.0, 0.0, 0.0);

	theRenderer_->AddActor(cubeActor);

	if (render)
		RenderScene(false);

	return cubeActor;
}

void ForgVisualLib::FrgVisual_Scene3D::ClearAllPoints()
{
	ClearAllDataType<FrgVisual_PointActor>();
}

void ForgVisualLib::FrgVisual_Scene3D::ClearAllLines()
{
	ClearAllDataType<FrgVisual_LineActor>();
}

void ForgVisualLib::FrgVisual_Scene3D::ClearAllPolylines()
{
	ClearAllDataType<FrgVisual_PolylineActor>();
}

//#include <FrgVisual_Scene3D.hxx>
//#include <FrgVisual_Scene_InterStyle3D.hxx>
//#include <FrgBase_Menu.hxx>
//#include <FrgBase_Tree.hxx>
//#include <FrgBase_Global_Icons.hxx>
//#include <FrgBase_MainWindow.hxx>
//
//#include <QtWidgets/QFileDialog>
//#include <QtWidgets/QMainWindow>
//
//#include <vtkActor.h>
//#include <vtkProperty.h>
//#include <vtkRenderer.h>
//#include <vtkGenericOpenGLRenderWindow.h>
//#include <vtkAxesActor.h>
//#include <vtkOrientationMarkerWidget.h>
//#include <vtkTextActor.h>
//#include <vtkTextProperty.h>
//#include <vtkCamera.h>
//#include <vtkDoubleArray.h>
//#include <vtkRectilinearGrid.h>
//#include <vtkDataSetMapper.h>
//#include<vtkPoints.h>
//#include <vtkPolyData.h>
//#include <vtkLine.h>
//#include <vtkCellData.h>
//#include <vtkPolyDataMapper.h>
//#include <vtkWindowToImageFilter.h>
//#include <vtkImageWriter.h>
//#include <vtkJPEGWriter.h>
//#include <vtkPNGWriter.h>
//#include <vtkBMPWriter.h>
//#include <vtkPNMWriter.h>
//#include <vtkPostScriptWriter.h>
//
//#include <vtkAutoInit.h>
//
//VTK_MODULE_INIT(vtkRenderingContextOpenGL2)
//VTK_MODULE_INIT(vtkRenderingOpenGL2)
//VTK_MODULE_INIT(vtkInteractionStyle)
//VTK_MODULE_INIT(vtkRenderingFreeType)
//
//ForgVisualLib::FrgVisual_Scene3D::FrgVisual_Scene3D(FrgBase_MainWindow * parentMainWindow)
//	: QVTKOpenGLNativeWidget(parentMainWindow)
//{
//
//}
//
//ForgVisualLib::FrgVisual_Scene3D::GridActor::GridActor(int nbMajorDivision, int nbMinorDivision, double MajorColor[3], double MinorColor[3])
//{
//	theNbMajorDivision_ = nbMajorDivision;
//	theNbMinorDivision_ = nbMinorDivision;
//
//	theMajorActor_ = vtkSmartPointer<vtkActor>::New();
//	theMinorActor_ = vtkSmartPointer<vtkActor>::New();
//	theMiddleLines_ = vtkSmartPointer<vtkActor>::New();
//
//	theMajorActor_->GetProperty()->SetColor(MajorColor);
//	theMinorActor_->GetProperty()->SetColor(MinorColor);
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::Init()
//{
//	theRenderer_ = vtkSmartPointer<vtkRenderer>::New();
//	theRenderer_->SetBackground(1.0, 1.0, 1.0);
//	theRenderer_->SetBackground2(0.7, 0.7, 0.7);
//	theRenderer_->SetGradientBackground(true);
//
//	theRenderWindow_ = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
//
//	theRenderWindow_->AddRenderer(theRenderer_);
//
//	theRenderWindowInteractor_ = vtkSmartPointer<vtkRenderWindowInteractor>::New();
//	theRenderWindowInteractor_->SetRenderWindow(theRenderWindow_);
//
//	theInteractorStyle_ = vtkSmartPointer<FrgVisual_Scene_InterStyle3D>::New();
//
//	theInteractorStyle_->SetParent(this);
//
//	theInteractorStyle_->SetMouseWheelMotionFactor(0.5);
//
//	theRenderWindowInteractor_->SetInteractorStyle(theInteractorStyle_);
//
//	vtkAxesActor* axes = vtkAxesActor::New();
//
//	axes->PickableOff();
//	axes->SetShaftTypeToLine();
//
//	vtkOrientationMarkerWidget* widget = vtkOrientationMarkerWidget::New();
//
//	widget->SetOutlineColor(0.9300, 0.5700, 0.1300);
//	widget->SetOrientationMarker(axes);
//	widget->SetInteractor(theRenderWindowInteractor_);
//	widget->SetViewport(0.0, 0.0, 0.4, 0.4);
//	widget->SetEnabled(1);
//	widget->InteractiveOff();
//
//	// Create a TextActor
//	theLogoActor_ = vtkSmartPointer<vtkTextActor>::New();
//	theLogoActor_->SetInput("Forg");
//	vtkTextProperty* tprop = theLogoActor_->GetTextProperty();
//	tprop->SetFontFamilyToArial();
//	tprop->ShadowOff();
//
//	tprop->SetLineSpacing(1.0);
//	tprop->SetFontSize(24);
//	//tprop->SetFontFamilyToArial();
//	tprop->BoldOn();
//	tprop->SetFontFile(":/Fonts/swissek.ttf");
//	tprop->ShadowOn();
//	tprop->SetColor(0.91, 0.91, 0.91); // (Black) Color
//
//	theLogoActor_->SetDisplayPosition(20, 20);
//	theRenderer_->AddActor2D(theLogoActor_);
//	//theRenderer_->AddActor(axes);
//
//	theCamera_ = vtkSmartPointer<vtkCamera>::New();
//	theRenderer_->LightFollowCameraOn();
//	theRenderer_->TwoSidedLightingOn();
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::Render(FrgBool resetCamera)
//{
//	if (resetCamera)
//	{
//		theCamera_->SetPosition(0, 1, 0);
//		theCamera_->SetFocalPoint(0, 0, 0);
//		theCamera_->SetViewUp(0, 0, 1);
//		theCamera_->Azimuth(-180);
//
//		theRenderer_->SetActiveCamera(theCamera_);
//		theRenderer_->ResetCamera();
//		theRenderer_->ResetCameraClippingRange();
//
//		this->SetRenderWindow(theRenderWindow_);
//
//		theRenderWindow_->Render();
//		theRenderWindowInteractor_->Initialize();
//	}
//	else
//	{
//		theRenderWindow_->Render();
//	}
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::StartScene()
//{
//
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::DrawGrid(int nbMajorDivision, int nbMinorDivision, GridDrawPlane plane)
//{
//	double majorColor[3] = { 0.604, 0.635, 0.663 };
//	double minorColor[3] = { 0.467, 0.686, 0.902 };
//	theGridActor_ = FrgNew GridActor(nbMajorDivision, nbMinorDivision, majorColor, minorColor);
//
//	const auto& bounds = GetRenderer()->ComputeVisiblePropBounds();
//	DrawGrid(theGridActor_->theMajorActor_, nbMajorDivision, FrgTrue, bounds, plane);
//	DrawGrid(theGridActor_->theMinorActor_, nbMajorDivision * nbMinorDivision, FrgFalse, bounds, plane);
//
//	DrawGridMiddleLines(theGridActor_->theMiddleLines_, bounds, plane);
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::DrawGrid(vtkSmartPointer<vtkActor> actor, int nbDivision, FrgBool isMajor, double* bounds, GridDrawPlane plane)
//{
//	double Xmin = bounds[0], Xmax = bounds[1];
//	double Ymin = bounds[2], Ymax = bounds[3];
//	double Zmin = bounds[4], Zmax = bounds[5];
//
//	double LX = abs(Xmax - Xmin);
//	double LY = abs(Ymax - Ymin);
//	double LZ = abs(Zmax - Zmin);
//
//	double L;
//
//	if (plane == XY)
//		L = LX > LY ? LX : LY;
//	else if (plane == XZ)
//		L = LX > LZ ? LX : LZ;
//	else if (plane == YZ)
//		L = LY > LZ ? LY : LZ;
//
//	L = sqrt(LX * LX + LY * LY + LZ * LZ);
//
//	double d = 2.0 * L / (double)nbDivision;
//
//	vtkSmartPointer<vtkDoubleArray> xCoords =
//		vtkSmartPointer<vtkDoubleArray>::New();
//	vtkSmartPointer<vtkDoubleArray> yCoords =
//		vtkSmartPointer<vtkDoubleArray>::New();
//	vtkSmartPointer<vtkDoubleArray> zCoords =
//		vtkSmartPointer<vtkDoubleArray>::New();
//
//	for (int i = 0; i <= nbDivision; i++)
//	{
//		if (plane == XY)
//		{
//			xCoords->InsertNextValue(i * d - L);
//			yCoords->InsertNextValue(i * d - L);
//		}
//		else if (plane == XZ)
//		{
//			xCoords->InsertNextValue(i * d - L);
//			yCoords->InsertNextValue(i * d - L);
//		}
//		else if (plane == YZ)
//		{
//			xCoords->InsertNextValue(i * d - L);
//			yCoords->InsertNextValue(i * d - L);
//		}
//	}
//
//	zCoords->InsertNextValue(0.0);
//
//	vtkSmartPointer<vtkRectilinearGrid> rgrid =
//		vtkSmartPointer<vtkRectilinearGrid>::New();
//
//	if (plane == XY)
//	{
//		rgrid->SetDimensions(nbDivision + 1, nbDivision + 1, 1);
//		rgrid->SetXCoordinates(xCoords);
//		rgrid->SetYCoordinates(yCoords);
//		rgrid->SetZCoordinates(zCoords);
//	}
//	else if (plane == XZ)
//	{
//		rgrid->SetDimensions(nbDivision + 1, 1, nbDivision + 1);
//		rgrid->SetXCoordinates(xCoords);
//		rgrid->SetYCoordinates(zCoords);
//		rgrid->SetZCoordinates(yCoords);
//	}
//	else if (plane == YZ)
//	{
//		rgrid->SetDimensions(1, nbDivision + 1, nbDivision + 1);
//		rgrid->SetXCoordinates(zCoords);
//		rgrid->SetYCoordinates(xCoords);
//		rgrid->SetZCoordinates(yCoords);
//	}
//
//	vtkSmartPointer<vtkDataSetMapper> rgridMapper =
//		vtkSmartPointer<vtkDataSetMapper>::New();
//	rgridMapper->SetInputData(rgrid);
//
//	actor->SetMapper(rgridMapper);
//	actor->GetProperty()->SetRepresentationToWireframe();
//	if (isMajor)
//		actor->GetProperty()->SetLineWidth(2.0f);
//	else
//		actor->GetProperty()->SetLineWidth(1.0f);
//	actor->GetProperty()->EdgeVisibilityOn();
//	//actor->GetProperty()->SetEdgeColor(1.0, 0.0, 0.0);
//	//actor->GetProperty()->SetRenderLinesAsTubes(true);
//	actor->GetProperty()->SetAmbient(0.0);
//	//actor->GetProperty()->SetDiffuse(0.0);
//	actor->GetProperty()->SetSpecular(0.0);
//	actor->GetProperty()->ShadingOn();
//	actor->PickableOff();
//
//	GetRenderer()->AddActor(actor);
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::DrawGridMiddleLines(vtkSmartPointer<vtkActor> actor, double* bounds, GridDrawPlane plane)
//{
//	double Xmin = bounds[0], Xmax = bounds[1];
//	double Ymin = bounds[2], Ymax = bounds[3];
//	double Zmin = bounds[4], Zmax = bounds[5];
//
//	double LX = abs(Xmax - Xmin);
//	double LY = abs(Ymax - Ymin);
//	double LZ = abs(Zmax - Zmin);
//
//	double L = 0.0;
//	if (plane == XY)
//		L = LX > LY ? LX : LY;
//	else if (plane == XZ)
//		L = LX > LZ ? LX : LZ;
//	else if (plane == YZ)
//		L = LY > LZ ? LY : LZ;
//
//	L = sqrt(LX * LX + LY * LY + LZ * LZ);
//
//	// Create two colors - one for each line
//	unsigned char axis1Color[3];
//	unsigned char axis2Color[3];
//
//	vtkSmartPointer<vtkPolyData> linesPolyData =
//		vtkSmartPointer<vtkPolyData>::New();
//
//	double p0[3], p1[3], p2[3];
//	if (plane == XY)
//	{
//		p0[0] = Xmin + LX / 2.0;
//		p0[1] = Ymin + LY / 2.0;
//		p0[2] = 0.0;
//
//		p1[0] = p0[0] + L;
//		p1[1] = p0[1];
//		p1[2] = p0[2];
//
//		p2[0] = p0[0];
//		p2[1] = p0[1] + L;
//		p2[2] = p0[2];
//
//		axis1Color[0] = 255; axis1Color[1] = 0; axis1Color[2] = 0;
//		axis2Color[0] = 0; axis2Color[1] = 255; axis2Color[2] = 0;
//	}
//
//	else if (plane == XZ)
//	{
//		p0[0] = Xmin + LX / 2.0;
//		p0[1] = 0.0;
//		p0[2] = Zmin + LZ / 2.0;
//
//		p1[0] = p0[0] + L;
//		p1[1] = p0[1];
//		p1[2] = p0[2];
//
//		p2[0] = p0[0];
//		p2[1] = p0[1];
//		p2[2] = p0[2] + L;
//
//		axis1Color[0] = 255; axis1Color[1] = 0; axis1Color[2] = 0;
//		axis2Color[0] = 0; axis2Color[1] = 0; axis2Color[2] = 255;
//	}
//
//	else if (plane == YZ)
//	{
//		p0[0] = Xmin + LX / 2.0;
//		p0[1] = 0.0;
//		p0[2] = Zmin + LZ / 2.0;
//
//		p1[0] = p0[0];
//		p1[1] = p0[1] + L;
//		p1[2] = p0[2];
//
//		p2[0] = p0[0];
//		p2[1] = p0[1];
//		p2[2] = p0[2] + L;
//
//		axis1Color[0] = 0; axis1Color[1] = 255; axis1Color[2] = 0;
//		axis2Color[0] = 0; axis2Color[1] = 0; axis2Color[2] = 255;
//	}
//
//	// Create a vtkPoints container and store the points in it
//	vtkSmartPointer<vtkPoints> pts =
//		vtkSmartPointer<vtkPoints>::New();
//	pts->InsertNextPoint(p0);
//	pts->InsertNextPoint(p1);
//	pts->InsertNextPoint(p2);
//
//	// Add the points to the polydata container
//	linesPolyData->SetPoints(pts);
//
//	// Create the first line (between Origin and P0)
//	vtkSmartPointer<vtkLine> line0 =
//		vtkSmartPointer<vtkLine>::New();
//	line0->GetPointIds()->SetId(0, 0); // the second 0 is the index of the Origin in linesPolyData's points
//	line0->GetPointIds()->SetId(1, 1); // the second 1 is the index of P0 in linesPolyData's points
//
//	// Create the second line (between Origin and P1)
//	vtkSmartPointer<vtkLine> line1 =
//		vtkSmartPointer<vtkLine>::New();
//	line1->GetPointIds()->SetId(0, 0); // the second 0 is the index of the Origin in linesPolyData's points
//	line1->GetPointIds()->SetId(1, 2); // 2 is the index of P1 in linesPolyData's points
//
//	// Create a vtkCellArray container and store the lines in it
//	vtkSmartPointer<vtkCellArray> lines =
//		vtkSmartPointer<vtkCellArray>::New();
//	lines->InsertNextCell(line0);
//	lines->InsertNextCell(line1);
//
//	// Add the lines to the polydata container
//	linesPolyData->SetLines(lines);
//
//	// Create a vtkUnsignedCharArray container and store the colors in it
//	vtkSmartPointer<vtkUnsignedCharArray> colors =
//		vtkSmartPointer<vtkUnsignedCharArray>::New();
//	colors->SetNumberOfComponents(3);
//	colors->InsertNextTypedTuple(axis1Color);
//	colors->InsertNextTypedTuple(axis2Color);
//
//	// Color the lines
//	linesPolyData->GetCellData()->SetScalars(colors);
//
//	// Setup the visualization pipeline
//	vtkSmartPointer<vtkPolyDataMapper> mapper =
//		vtkSmartPointer<vtkPolyDataMapper>::New();
//
//	mapper->SetInputData(linesPolyData);
//
//	actor->SetMapper(mapper);
//	actor->GetProperty()->SetLineWidth(3.0f);
//	//actor->GetProperty()->SetRenderLinesAsTubes(true);
//	actor->GetProperty()->SetAmbient(0.0);
//	actor->GetProperty()->SetSpecular(0.0);
//	actor->GetProperty()->ShadingOn();
//	actor->PickableOff();
//
//	GetRenderer()->AddActor(actor);
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::customContextMenuRequestedSlot(const QPoint& pos)
//{
//	theContextMenuInScene_->exec(this->mapToGlobal(pos));
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::CreateContextMenuInScene()
//{
//	//FrgMenu_View* viewMenu = FrgNew FrgMenu_View(GetParentTree()->GetParentMainWindow());
//
//	theContextMenuInScene_ = FrgNew FrgBase_Menu(GetParentTree()->GetParentMainWindow());
//
//	for (int i = 0; i < theMenus_.size(); i++)
//	{
//		theContextMenuInScene_->addActions(theMenus_[i]->actions());
//		theContextMenuInScene_->addSeparator();
//	}
//
//	connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(customContextMenuRequestedSlot(const QPoint&)));
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::CreateMenus()
//{
//
//}
//
//QAction* ForgVisualLib::FrgVisual_Scene3D::GetActionItemInScene(FrgString actionName)
//{
//	QAction* result = nullptr;
//
//	for (int iMenu = 0; iMenu < theMenus_.size(); iMenu++)
//	{
//		result = theMenus_[iMenu]->GetItem(actionName);
//		if (result)
//			break;
//	}
//	return result;
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::ClearGrid()
//{
//	if (theGridActor_)
//	{
//		theRenderer_->RemoveActor(theGridActor_->theMajorActor_);
//		theRenderer_->RemoveActor(theGridActor_->theMinorActor_);
//		theRenderer_->RemoveActor(theGridActor_->theMiddleLines_);
//
//		delete theGridActor_;
//		theGridActor_ = FrgNullPtr;
//	}
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::RemoveActor(vtkProp* prop)
//{
//	theRenderer_->RemoveActor(prop);
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::SetViewToXYPlaneSlot(bool)
//{
//	if (theGridActor_)
//	{
//		double opacity = theGridActor_->theMajorActor_->GetProperty()->GetOpacity();
//		int nbMajorDivision = theGridActor_->theNbMajorDivision_;
//		int nbMinorDivision = theGridActor_->theNbMinorDivision_;
//
//		ClearGrid();
//
//		DrawGrid(nbMajorDivision, nbMinorDivision, XY);
//
//		GridOpacityChangedSlot(opacity * 100);
//
//		for (int i = 0; i < theContextMenuInScene_->actions().size(); i++)
//			if (theContextMenuInScene_->actions()[i]->text() == "Draw Grid")
//				DrawGridSlot(theContextMenuInScene_->actions()[i]->isChecked());
//	}
//	theInteractorStyle_->SetViewToXYPlane();
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::SetViewToXZPlaneSlot(bool)
//{
//	if (theGridActor_)
//	{
//		double opacity = theGridActor_->theMajorActor_->GetProperty()->GetOpacity();
//		int nbMajorDivision = theGridActor_->theNbMajorDivision_;
//		int nbMinorDivision = theGridActor_->theNbMinorDivision_;
//
//		ClearGrid();
//
//		DrawGrid(nbMajorDivision, nbMinorDivision, XZ);
//
//		GridOpacityChangedSlot(opacity * 100);
//
//		for (int i = 0; i < theContextMenuInScene_->actions().size(); i++)
//			if (theContextMenuInScene_->actions()[i]->text() == "Draw Grid")
//				DrawGridSlot(theContextMenuInScene_->actions()[i]->isChecked());
//	}
//	theInteractorStyle_->SetViewToXZPlane();
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::SetViewToYZPlaneSlot(bool)
//{
//	if (theGridActor_)
//	{
//		double opacity = theGridActor_->theMajorActor_->GetProperty()->GetOpacity();
//		int nbMajorDivision = theGridActor_->theNbMajorDivision_;
//		int nbMinorDivision = theGridActor_->theNbMinorDivision_;
//
//		ClearGrid();
//
//		DrawGrid(nbMajorDivision, nbMinorDivision, YZ);
//
//		GridOpacityChangedSlot(opacity * 100);
//
//		for (int i = 0; i < theContextMenuInScene_->actions().size(); i++)
//			if (theContextMenuInScene_->actions()[i]->text() == "Draw Grid")
//				DrawGridSlot(theContextMenuInScene_->actions()[i]->isChecked());
//	}
//	theInteractorStyle_->SetViewToYZPlane();
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::SetViewToXYZSlot(bool)
//{
//	if (theGridActor_)
//	{
//		double opacity = theGridActor_->theMajorActor_->GetProperty()->GetOpacity();
//		int nbMajorDivision = theGridActor_->theNbMajorDivision_;
//		int nbMinorDivision = theGridActor_->theNbMinorDivision_;
//
//		ClearGrid();
//
//		DrawGrid(nbMajorDivision, nbMinorDivision, XY);
//
//		GridOpacityChangedSlot(opacity * 100);
//
//		for (int i = 0; i < theContextMenuInScene_->actions().size(); i++)
//			if (theContextMenuInScene_->actions()[i]->text() == "Draw Grid")
//				DrawGridSlot(theContextMenuInScene_->actions()[i]->isChecked());
//	}
//	theInteractorStyle_->SetViewToXYZ();
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::GridOpacityChangedSlot(int val)
//{
//	if (theGridActor_)
//	{
//		theGridActor_->theMajorActor_->GetProperty()->SetOpacity((double)val / 100.0);
//		theGridActor_->theMinorActor_->GetProperty()->SetOpacity((double)val / 100.0);
//		theGridActor_->theMiddleLines_->GetProperty()->SetOpacity((double)val / 100.0);
//
//		theRenderWindow_->Render();
//	}
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::DrawGridSlot(bool checked)
//{
//	if (theGridActor_)
//	{
//		theGridActor_->theMajorActor_->SetVisibility(checked);
//		theGridActor_->theMinorActor_->SetVisibility(checked);
//		theGridActor_->theMiddleLines_->SetVisibility(checked);
//
//		theRenderWindow_->Render();
//	}
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::ScreenshotSlot(bool)
//{
//	QList<QString> QfileTypes;
//	QfileTypes.push_back("JPEG (*.jpg; *.jpeg)");
//	QfileTypes.push_back("PNG (*.png)");
//	QfileTypes.push_back("BMP (*.bmp)");
//	QfileTypes.push_back("PNM (*.pnm)");
//	QfileTypes.push_back("Post Script (*.ps)");
//
//	QString fileTypes;
//	for (int i = 0; i < QfileTypes.size() - 1; i++)
//	{
//		fileTypes += QfileTypes.at(i);
//		fileTypes += ";;";
//	}
//	fileTypes += QfileTypes.at(QfileTypes.size() - 1);
//
//	QString* ext = new QString("PNG");
//	QString fileName = QFileDialog::getSaveFileName(GetParentTree()->GetParentMainWindow(),
//		QMainWindow::tr("Export Part"), "",
//		fileTypes, ext);
//
//	if (fileName.isEmpty())
//		return;
//	else
//	{
//		// Screenshot  
//		vtkSmartPointer<vtkWindowToImageFilter> windowToImageFilter =
//			vtkSmartPointer<vtkWindowToImageFilter>::New();
//		windowToImageFilter->SetInput(theRenderWindow_);
//
//		int Magnification = 2;
//
//		//windowToImageFilter->SetScale(1366 / theRenderWindow_->GetSize()[0], 768 / theRenderWindow_->GetSize()[1]); // image quality
//		windowToImageFilter->SetScale(Magnification); // image quality
//
//		theLogoActor_->GetTextProperty()->SetFontSize(Magnification * theLogoActor_->GetTextProperty()->GetFontSize());
//		theLogoActor_->GetTextProperty()->SetShadowOffset
//		(
//			Magnification * theLogoActor_->GetTextProperty()->GetShadowOffset()[0],
//			Magnification * theLogoActor_->GetTextProperty()->GetShadowOffset()[1]
//		);
//
//		/*for (int i = 0; i < theGeometry_.size(); i++)
//			theGeometry_[i]->GetProperty()->SetLineWidth((float)Magnification*theGeometry_[i]->GetProperty()->GetLineWidth());*/
//
//		windowToImageFilter->ReadFrontBufferOff(); // read from the back buffer
//		windowToImageFilter->Update();
//
//		vtkSmartPointer<vtkImageWriter> writer;// = vtkSmartPointer<vtkJPEGWriter>::New();
//
//		if (*ext == "JPEG (*.jpg; *.jpeg)")
//		{
//			writer = vtkSmartPointer<vtkJPEGWriter>::New();
//		}
//		else if (*ext == "PNG (*.png)")
//		{
//			writer = vtkSmartPointer<vtkPNGWriter>::New();
//		}
//		else if (*ext == "BMP (*.bmp)")
//		{
//			writer = vtkSmartPointer<vtkBMPWriter>::New();
//		}
//		else if (*ext == "PNM (*.pnm)")
//		{
//			writer = vtkSmartPointer<vtkPNMWriter>::New();
//		}
//		else if (*ext == "Post Script (*.ps)")
//		{
//			writer = vtkSmartPointer<vtkPostScriptWriter>::New();
//		}
//
//		writer->SetFileName(fileName.toStdString().c_str());
//		writer->SetInputConnection(windowToImageFilter->GetOutputPort());
//		//writer->SetQuality(100);
//		writer->Write();
//
//		theLogoActor_->GetTextProperty()->SetFontSize((1.0 / (float)Magnification) * theLogoActor_->GetTextProperty()->GetFontSize());
//		theLogoActor_->GetTextProperty()->SetShadowOffset
//		(
//			(1.0 / (float)Magnification) * theLogoActor_->GetTextProperty()->GetShadowOffset()[0],
//			(1.0 / (float)Magnification) * theLogoActor_->GetTextProperty()->GetShadowOffset()[1]
//		);
//
//		/*for (int i = 0; i < theGeometry_.size(); i++)
//			theGeometry_[i]->GetProperty()->SetLineWidth((1.0 / (float)Magnification)*theGeometry_[i]->GetProperty()->GetLineWidth());*/
//
//		theRenderWindow_->Render();
//	}
//}
//
//inline QVector<QColor> rndColors(int count) {
//	QVector<QColor> colors;
//	float currentHue = 0.0;
//	for (int i = 0; i < count; i++)
//	{
//		colors.push_back(QColor::fromHslF(currentHue, 1.0, 0.5));
//		currentHue += 0.618033988749895f;
//		currentHue = std::fmod(currentHue, 1.0f);
//	}
//	return colors;
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::RandomColorsSlot(bool checked)
//{
//	auto actors = GetActors();
//
//	if (!checked)
//	{
//		for (int iActor = 0; iActor < actors.size(); iActor++)
//		{
//			actors[iActor]->GetProperty()->SetColor
//			(
//				FrgBaseInteractorStyle::GeometryColorRGB.redF(),
//				FrgBaseInteractorStyle::GeometryColorRGB.greenF(),
//				FrgBaseInteractorStyle::GeometryColorRGB.blueF()
//			);
//		}
//	}
//	else
//	{
//		QVector<QColor> colors = rndColors(actors.size());
//
//		for (int iActor = 0; iActor < actors.size(); iActor++)
//		{
//			actors[iActor]->GetProperty()->SetColor(colors.at(iActor).redF(), colors.at(iActor).greenF(), colors.at(iActor).blueF());
//
//			theRenderWindow_->Render();
//		}
//	}
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::ShowMeshSlot(bool condition)
//{
//	theInteractorStyle_->ShowMesh(condition);
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::HideActorsSlot(bool)
//{
//	theInteractorStyle_->HideSelectedActors();
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::ShowHiddenPartsSlot(bool)
//{
//	theInteractorStyle_->ShowAllActors();
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::SelectIconSelectedSlot(bool)
//{
//	GetParentTree()->GetParentMainWindow()->setCursor(QCursor());
//
//	theInteractorStyle_->GetSelectedIconFromScene() = Cursor;
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::MoveIconSelectedSlot(bool)
//{
//	QPixmap cursor_pixmap = QPixmap(ICON_Menu_Scene_Move);
//	QCursor cursor_default = QCursor(cursor_pixmap, 0, 0);
//	GetParentTree()->GetParentMainWindow()->setCursor(cursor_default);
//
//	theInteractorStyle_->GetSelectedIconFromScene() = FrgVisual_Scene_InterStyle3D::Move;
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::RotateXIconSelectedSlot(bool)
//{
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::RotateYIconSelectedSlot(bool)
//{
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::RotateZIconSelectedSlot(bool)
//{
//}
//
//void ForgVisualLib::FrgVisual_Scene3D::RotateXYZIconSelectedSlot(bool)
//{
//	QPixmap cursor_pixmap = QPixmap(ICON_Menu_Scene_RotateXYZ);
//	QCursor cursor_default = QCursor(cursor_pixmap, 0, 0);
//	GetParentTree()->GetParentMainWindow()->setCursor(cursor_default);
//
//	theInteractorStyle_->GetSelectedIconFromScene() = FrgVisual_Scene_InterStyle3D::RotateXYZ;
//}