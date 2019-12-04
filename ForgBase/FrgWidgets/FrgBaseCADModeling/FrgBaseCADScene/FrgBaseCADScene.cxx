#include <FrgBaseCADScene.hxx>

#include <FrgBaseTree.hxx>
#include <FrgBaseMainWindow.hxx>
#include <FrgBaseInteractorStyle.hxx>
#include <FrgBasePlot2D.hxx>
#include <FrgBaseMenu.hxx>
#include <FrgMenu_View.hxx>
#include <FrgBaseGlobalsICONS.hxx>
#include <QtWidgets/QAction>
#include <QtWidgets/QToolBar>

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
#include <vtkLine.h>
#include <vtkUnsignedCharArray.h>
#include <vtkCellData.h>

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
	CreateMenus();
	CreateContextMenuInScene();
}

ForgBaseLib::GridActor::GridActor(int nbMajorDivision, int nbMinorDivision, double MajorColor[3], double MinorColor[3])
{
	theNbMajorDivision_ = nbMajorDivision;
	theNbMinorDivision_ = nbMinorDivision;

	theMajorActor_ = vtkSmartPointer<vtkActor>::New();
	theMinorActor_ = vtkSmartPointer<vtkActor>::New();
	theMiddleLines_ = vtkSmartPointer<vtkActor>::New();

	theMajorActor_->GetProperty()->SetColor(MajorColor);
	theMinorActor_->GetProperty()->SetColor(MinorColor);
}

void ForgBaseLib::FrgBaseCADScene::Init()
{
	theRenderer_ = vtkSmartPointer<vtkRenderer>::New();
	//theRenderer_->SetBackground(0.95, 0.95, 0.95); // (Gainsboro) Color
	theRenderer_->SetBackground(1.0, 1.0, 1.0);
	theRenderer_->SetBackground2(0.7, 0.7, 0.7);
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

void ForgBaseLib::FrgBaseCADScene::DrawGrid(int nbMajorDivision, int nbMinorDivision, GridDrawPlane plane)
{
	double majorColor[3] = { 0.604, 0.635, 0.663 };
	double minorColor[3] = { 0.467, 0.686, 0.902 };
	theGridActor_ = FrgNew GridActor(nbMajorDivision, nbMinorDivision, majorColor, minorColor);

	const auto& bounds = GetRenderer()->ComputeVisiblePropBounds();
	DrawGrid(theGridActor_->theMajorActor_, nbMajorDivision, FrgTrue, bounds, plane);
	DrawGrid(theGridActor_->theMinorActor_, nbMajorDivision * nbMinorDivision, FrgFalse, bounds, plane);

	DrawGridMiddleLines(theGridActor_->theMiddleLines_, bounds, plane);
}

void ForgBaseLib::FrgBaseCADScene::DrawGrid(vtkSmartPointer<vtkActor> actor, int nbDivision, FrgBool isMajor, double* bounds, GridDrawPlane plane)
{
	double Xmin = bounds[0], Xmax = bounds[1];
	double Ymin = bounds[2], Ymax = bounds[3];
	double Zmin = bounds[4], Zmax = bounds[5];

	double LX = abs(Xmax - Xmin);
	double LY = abs(Ymax - Ymin);
	double LZ = abs(Zmax - Zmin);

	double L;

	if (plane == XY)
		L = LX > LY ? LX : LY;
	else if (plane == XZ)
		L = LX > LZ ? LX : LZ;
	else if (plane == YZ)
		L = LY > LZ ? LY : LZ;

	double d = 2.0 * L / (double)nbDivision;

	vtkSmartPointer<vtkDoubleArray> xCoords =
		vtkSmartPointer<vtkDoubleArray>::New();
	vtkSmartPointer<vtkDoubleArray> yCoords =
		vtkSmartPointer<vtkDoubleArray>::New();
	vtkSmartPointer<vtkDoubleArray> zCoords =
		vtkSmartPointer<vtkDoubleArray>::New();

	for (int i = 0; i <= nbDivision; i++)
	{
		if (plane == XY)
		{
			xCoords->InsertNextValue(i * d + (Xmin + LX / 2.0) - L);
			yCoords->InsertNextValue(i * d + (Ymin + LY / 2.0) - L);
		}
		else if (plane == XZ)
		{
			xCoords->InsertNextValue(i * d + (Xmin + LX / 2.0) - L);
			yCoords->InsertNextValue(i * d + (Zmin + LZ / 2.0) - L);
		}
		else if (plane == YZ)
		{
			xCoords->InsertNextValue(i * d + (Ymin + LY / 2.0) - L);
			yCoords->InsertNextValue(i * d + (Zmin + LZ / 2.0) - L);
		}
	}

	zCoords->InsertNextValue(0.0);

	vtkSmartPointer<vtkRectilinearGrid> rgrid =
		vtkSmartPointer<vtkRectilinearGrid>::New();

	if (plane == XY)
	{
		rgrid->SetDimensions(nbDivision + 1, nbDivision + 1, 1);
		rgrid->SetXCoordinates(xCoords);
		rgrid->SetYCoordinates(yCoords);
		rgrid->SetZCoordinates(zCoords);
	}
	else if (plane == XZ)
	{
		rgrid->SetDimensions(nbDivision + 1, 1, nbDivision + 1);
		rgrid->SetXCoordinates(xCoords);
		rgrid->SetYCoordinates(zCoords);
		rgrid->SetZCoordinates(yCoords);
	}
	else if (plane == YZ)
	{
		rgrid->SetDimensions(1, nbDivision + 1, nbDivision + 1);
		rgrid->SetXCoordinates(zCoords);
		rgrid->SetYCoordinates(xCoords);
		rgrid->SetZCoordinates(yCoords);
	}

	vtkSmartPointer<vtkDataSetMapper> rgridMapper =
		vtkSmartPointer<vtkDataSetMapper>::New();
	rgridMapper->SetInputData(rgrid);

	actor->SetMapper(rgridMapper);
	actor->GetProperty()->SetRepresentationToWireframe();
	if(isMajor)
		actor->GetProperty()->SetLineWidth(2.0);
	else
		actor->GetProperty()->SetLineWidth(1.0);
	actor->GetProperty()->EdgeVisibilityOn();
	//actor->GetProperty()->SetEdgeColor(1.0, 0.0, 0.0);
	actor->GetProperty()->SetRenderLinesAsTubes(true);
	actor->GetProperty()->SetAmbient(0.0);
	//actor->GetProperty()->SetDiffuse(0.0);
	actor->GetProperty()->SetSpecular(0.0);
	actor->GetProperty()->ShadingOn();
	actor->PickableOff();

	GetRenderer()->AddActor(actor);
}

void ForgBaseLib::FrgBaseCADScene::DrawGridMiddleLines(vtkSmartPointer<vtkActor> actor, double* bounds, GridDrawPlane plane)
{
	double Xmin = bounds[0], Xmax = bounds[1];
	double Ymin = bounds[2], Ymax = bounds[3];
	double Zmin = bounds[4], Zmax = bounds[5];
	
	double LX = abs(Xmax - Xmin);
	double LY = abs(Ymax - Ymin);
	double LZ = abs(Zmax - Zmin);

	double L = 0.0;
	if (plane == XY)
		L = LX > LY ? LX : LY;
	else if (plane == XZ)
		L = LX > LZ ? LX : LZ;
	else if (plane == YZ)
		L = LY > LZ ? LY : LZ;

	// Create two colors - one for each line
	unsigned char axis1Color[3];
	unsigned char axis2Color[3];

	vtkSmartPointer<vtkPolyData> linesPolyData =
		vtkSmartPointer<vtkPolyData>::New();

	double p0[3], p1[3], p2[3];
	if (plane == XY)
	{
		p0[0] = Xmin + LX / 2.0;
		p0[1] = Ymin + LY / 2.0;
		p0[2] = 0.0;

		p1[0] = p0[0] + L;
		p1[1] = p0[1];
		p1[2] = p0[2];

		p2[0] = p0[0];
		p2[1] = p0[1] + L;
		p2[2] = p0[2];

		axis1Color[0] = 255; axis1Color[1] = 0; axis1Color[2] = 0;
		axis2Color[0] = 0; axis2Color[1] = 255; axis2Color[2] = 0;
	}

	else if (plane == XZ)
	{
		p0[0] = Xmin + LX / 2.0;
		p0[1] = 0.0;
		p0[2] = Zmin + LZ / 2.0;

		p1[0] = p0[0] + L;
		p1[1] = p0[1];
		p1[2] = p0[2];

		p2[0] = p0[0];
		p2[1] = p0[1];
		p2[2] = p0[2] + L;

		axis1Color[0] = 255; axis1Color[1] = 0; axis1Color[2] = 0;
		axis2Color[0] = 0; axis2Color[1] = 0; axis2Color[2] = 255;
	}

	else if (plane == YZ)
	{
		p0[0] = Xmin + LX / 2.0;
		p0[1] = 0.0;
		p0[2] = Zmin + LZ / 2.0;

		p1[0] = p0[0];
		p1[1] = p0[1] + L;
		p1[2] = p0[2];

		p2[0] = p0[0];
		p2[1] = p0[1];
		p2[2] = p0[2] + L;

		axis1Color[0] = 0; axis1Color[1] = 255; axis1Color[2] = 0;
		axis2Color[0] = 0; axis2Color[1] = 0; axis2Color[2] = 255;
	}

	// Create a vtkPoints container and store the points in it
	vtkSmartPointer<vtkPoints> pts =
		vtkSmartPointer<vtkPoints>::New();
	pts->InsertNextPoint(p0);
	pts->InsertNextPoint(p1);
	pts->InsertNextPoint(p2);

	// Add the points to the polydata container
	linesPolyData->SetPoints(pts);

	// Create the first line (between Origin and P0)
	vtkSmartPointer<vtkLine> line0 =
		vtkSmartPointer<vtkLine>::New();
	line0->GetPointIds()->SetId(0, 0); // the second 0 is the index of the Origin in linesPolyData's points
	line0->GetPointIds()->SetId(1, 1); // the second 1 is the index of P0 in linesPolyData's points

	// Create the second line (between Origin and P1)
	vtkSmartPointer<vtkLine> line1 =
		vtkSmartPointer<vtkLine>::New();
	line1->GetPointIds()->SetId(0, 0); // the second 0 is the index of the Origin in linesPolyData's points
	line1->GetPointIds()->SetId(1, 2); // 2 is the index of P1 in linesPolyData's points

	// Create a vtkCellArray container and store the lines in it
	vtkSmartPointer<vtkCellArray> lines =
		vtkSmartPointer<vtkCellArray>::New();
	lines->InsertNextCell(line0);
	lines->InsertNextCell(line1);

	// Add the lines to the polydata container
	linesPolyData->SetLines(lines);

	// Create a vtkUnsignedCharArray container and store the colors in it
	vtkSmartPointer<vtkUnsignedCharArray> colors =
		vtkSmartPointer<vtkUnsignedCharArray>::New();
	colors->SetNumberOfComponents(3);
	colors->InsertNextTypedTuple(axis1Color);
	colors->InsertNextTypedTuple(axis2Color);

	// Color the lines
	linesPolyData->GetCellData()->SetScalars(colors);

	// Setup the visualization pipeline
	vtkSmartPointer<vtkPolyDataMapper> mapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();

	mapper->SetInputData(linesPolyData);

	actor->SetMapper(mapper);
	actor->GetProperty()->SetLineWidth(3.0);
	actor->GetProperty()->SetRenderLinesAsTubes(true);
	actor->GetProperty()->SetAmbient(0.0);
	actor->GetProperty()->SetSpecular(0.0);
	actor->GetProperty()->ShadingOn();
	actor->PickableOff();

	GetRenderer()->AddActor(actor);
}

void ForgBaseLib::FrgBaseCADScene::customContextMenuRequestedSlot(const QPoint& pos)
{
	theContextMenuInScene_->exec(this->mapToGlobal(pos));
}

void ForgBaseLib::FrgBaseCADScene::CreateContextMenuInScene()
{
	//FrgMenu_View* viewMenu = FrgNew FrgMenu_View(GetParentTree()->GetParentMainWindow());

	theContextMenuInScene_ = FrgNew FrgBaseMenu(GetParentTree()->GetParentMainWindow());

	for (int i = 0; i < theMenus_.size(); i++)
	{
		theContextMenuInScene_->addActions(theMenus_[i]->actions());
		theContextMenuInScene_->addSeparator();
	}
	
	connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(customContextMenuRequestedSlot(const QPoint&)));
}

void ForgBaseLib::FrgBaseCADScene::CreateMenus()
{
	theMenus_.push_back(FrgNew FrgMenu_View(GetParentTree()->GetParentMainWindow()));
	connect(theMenus_.last()->GetItem("Set View to XY Plane"), SIGNAL(triggered(bool)), this, SLOT(SetViewToXYPlaneSlot(bool)));
	connect(theMenus_.last()->GetItem("Set View to XZ Plane"), SIGNAL(triggered(bool)), this, SLOT(SetViewToXZPlaneSlot(bool)));
	connect(theMenus_.last()->GetItem("Set View to YZ Plane"), SIGNAL(triggered(bool)), this, SLOT(SetViewToYZPlaneSlot(bool)));
	connect(theMenus_.last()->GetItem("Set View to XYZ"), SIGNAL(triggered(bool)), this, SLOT(SetViewToXYZSlot(bool)));

	theMenus_.push_back(FrgNew FrgBaseMenu(GetParentTree()->GetParentMainWindow()));
	theMenus_.last()->GetToolBar()->setHidden(FrgTrue);
	theMenus_.last()->AddItem(FrgICON_Menu_View_Grid, "Draw Grid");
	theMenus_.last()->GetItem("Draw Grid")->setCheckable(FrgTrue);
	theMenus_.last()->GetItem("Draw Grid")->setChecked(FrgTrue);

	connect(theMenus_.last()->GetItem("Draw Grid"), SIGNAL(triggered(bool)), this, SLOT(DrawGridSlot(bool)));
}

void ForgBaseLib::FrgBaseCADScene::ClearGrid()
{
	if (theGridActor_)
	{
		theRenderer_->RemoveActor(theGridActor_->theMajorActor_);
		theRenderer_->RemoveActor(theGridActor_->theMinorActor_);
		theRenderer_->RemoveActor(theGridActor_->theMiddleLines_);

		delete theGridActor_;
		theGridActor_ = FrgNullPtr;
	}
}

void ForgBaseLib::FrgBaseCADScene::RemoveActor(vtkProp* prop)
{
	theRenderer_->RemoveActor(prop);
}

void ForgBaseLib::FrgBaseCADScene::SetViewToXYPlaneSlot(bool)
{
	if (theGridActor_)
	{
		double opacity = theGridActor_->theMajorActor_->GetProperty()->GetOpacity();
		int nbMajorDivision = theGridActor_->theNbMajorDivision_;
		int nbMinorDivision = theGridActor_->theNbMinorDivision_;

		ClearGrid();

		DrawGrid(nbMajorDivision, nbMinorDivision, XY);

		GridOpacityChangedSlot(opacity * 100);

		for (int i = 0; i < theContextMenuInScene_->actions().size(); i++)
			if (theContextMenuInScene_->actions()[i]->text() == "Draw Grid")
				DrawGridSlot(theContextMenuInScene_->actions()[i]->isChecked());
	}
	theInteractorStyle_->SetViewToXYPlane();
}

void ForgBaseLib::FrgBaseCADScene::SetViewToXZPlaneSlot(bool)
{
	if (theGridActor_)
	{
		double opacity = theGridActor_->theMajorActor_->GetProperty()->GetOpacity();
		int nbMajorDivision = theGridActor_->theNbMajorDivision_;
		int nbMinorDivision = theGridActor_->theNbMinorDivision_;

		ClearGrid();

		DrawGrid(nbMajorDivision, nbMinorDivision, XZ);

		GridOpacityChangedSlot(opacity * 100);

		for (int i = 0; i < theContextMenuInScene_->actions().size(); i++)
			if (theContextMenuInScene_->actions()[i]->text() == "Draw Grid")
				DrawGridSlot(theContextMenuInScene_->actions()[i]->isChecked());
	}
	theInteractorStyle_->SetViewToXZPlane();
}

void ForgBaseLib::FrgBaseCADScene::SetViewToYZPlaneSlot(bool)
{
	if (theGridActor_)
	{
		double opacity = theGridActor_->theMajorActor_->GetProperty()->GetOpacity();
		int nbMajorDivision = theGridActor_->theNbMajorDivision_;
		int nbMinorDivision = theGridActor_->theNbMinorDivision_;

		ClearGrid();

		DrawGrid(nbMajorDivision, nbMinorDivision, YZ);

		GridOpacityChangedSlot(opacity * 100);

		for (int i = 0; i < theContextMenuInScene_->actions().size(); i++)
			if (theContextMenuInScene_->actions()[i]->text() == "Draw Grid")
				DrawGridSlot(theContextMenuInScene_->actions()[i]->isChecked());
	}
	theInteractorStyle_->SetViewToYZPlane();
}

void ForgBaseLib::FrgBaseCADScene::SetViewToXYZSlot(bool)
{
	if (theGridActor_)
	{
		double opacity = theGridActor_->theMajorActor_->GetProperty()->GetOpacity();
		int nbMajorDivision = theGridActor_->theNbMajorDivision_;
		int nbMinorDivision = theGridActor_->theNbMinorDivision_;

		ClearGrid();

		DrawGrid(nbMajorDivision, nbMinorDivision, XY);

		GridOpacityChangedSlot(opacity * 100);

		for (int i = 0; i < theContextMenuInScene_->actions().size(); i++)
			if (theContextMenuInScene_->actions()[i]->text() == "Draw Grid")
				DrawGridSlot(theContextMenuInScene_->actions()[i]->isChecked());
	}
	theInteractorStyle_->SetViewToXYZ();
}

void ForgBaseLib::FrgBaseCADScene::GridOpacityChangedSlot(int val)
{
	if (theGridActor_)
	{
		theGridActor_->theMajorActor_->GetProperty()->SetOpacity((double)val / 100.0);
		theGridActor_->theMinorActor_->GetProperty()->SetOpacity((double)val / 100.0);
		theGridActor_->theMiddleLines_->GetProperty()->SetOpacity((double)val / 100.0);

		theRenderWindow_->Render();
	}
}

void ForgBaseLib::FrgBaseCADScene::DrawGridSlot(bool checked)
{
	if (theGridActor_)
	{
		theGridActor_->theMajorActor_->SetVisibility(checked);
		theGridActor_->theMinorActor_->SetVisibility(checked);
		theGridActor_->theMiddleLines_->SetVisibility(checked);

		theRenderWindow_->Render();
	}
}

void ForgBaseLib::FrgBaseCADScene::SelectIconSelectedSlot(bool)
{
	GetParentTree()->GetParentMainWindow()->setCursor(QCursor());

	theInteractorStyle_->GetSelectedIconFromScene() = Cursor;
}

void ForgBaseLib::FrgBaseCADScene::MoveIconSelectedSlot(bool)
{
	QPixmap cursor_pixmap = QPixmap(FrgICON_Menu_Scene_Move);
	QCursor cursor_default = QCursor(cursor_pixmap, 0, 0);
	GetParentTree()->GetParentMainWindow()->setCursor(cursor_default);

	theInteractorStyle_->GetSelectedIconFromScene() = Move;
}

void ForgBaseLib::FrgBaseCADScene::RotateXIconSelectedSlot(bool)
{
}

void ForgBaseLib::FrgBaseCADScene::RotateYIconSelectedSlot(bool)
{
}

void ForgBaseLib::FrgBaseCADScene::RotateZIconSelectedSlot(bool)
{
}

void ForgBaseLib::FrgBaseCADScene::RotateXYZIconSelectedSlot(bool)
{
	QPixmap cursor_pixmap = QPixmap(FrgICON_Menu_Scene_RotateXYZ);
	QCursor cursor_default = QCursor(cursor_pixmap, 0, 0);
	GetParentTree()->GetParentMainWindow()->setCursor(cursor_default);

	theInteractorStyle_->GetSelectedIconFromScene() = RotateXYZ;
}