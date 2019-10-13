#include <FrgBaseSceneTreeItem.hxx>
#include <FrgBaseMainWindow.hxx>
#include <FrgBaseTreeItem.hxx>
#include <FrgBaseTreeItemProperties.hxx>
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

#include <vtkAutoInit.h>

VTK_MODULE_INIT(vtkRenderingContextOpenGL2)
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)
VTK_MODULE_INIT(vtkRenderingFreeType)

ForgBaseLib::FrgBaseSceneTreeItem::FrgBaseSceneTreeItem(const FrgString& title, FrgBaseTreeItem* parent, FrgBaseTree* parentTree, FrgBaseMainWindow* parentMainWindow)
	: FrgBaseTreeItem(title, parent, parentTree, parentMainWindow)
	, QVTKOpenGLNativeWidget(parentMainWindow)
{
	setIcon(0, QIcon(":/Icons/Scenes/Geometry_Scene_Icon.png"));

	GetProperties()->SetEnabled("Name", FrgTrue);

	//StartScene();
	//StartScene2();
	//StartSceneNihad();
}

//void ForgBaseLib::FrgBaseSceneTreeItem::StartScene()
//{
//	theRenderer_ = vtkSmartPointer<vtkRenderer>::New();
//	theRenderer_->SetBackground(0.862, 0.862, 0.862); // (Gainsboro) Color
//
//	vtkSmartPointer<vtkProperty> bprop =
//		vtkSmartPointer<vtkProperty>::New();
//	bprop->SetColor
//	(
//		theInteractorStyle_->GeometryColorRGB.redF(),
//		theInteractorStyle_->GeometryColorRGB.greenF(),
//		theInteractorStyle_->GeometryColorRGB.blueF()
//	);
//
//	static double x[27][3] = { {0,0,0}, {1,0,0}, {2,0,0}, {0,1,0}, {1,1,0}, {2,1,0},
//							{0,0,1}, {1,0,1}, {2,0,1}, {0,1,1}, {1,1,1}, {2,1,1},
//							{0,1,2}, {1,1,2}, {2,1,2}, {0,1,3}, {1,1,3}, {2,1,3},
//							{0,1,4}, {1,1,4}, {2,1,4}, {0,1,5}, {1,1,5}, {2,1,5},
//							{0,1,6}, {1,1,6}, {2,1,6} };
//	static vtkIdType pts[12][8] = { {0, 1, 4, 3, 6, 7, 10, 9},
//								 {1, 2, 5, 4, 7, 8, 11, 10},
//								 {6, 10, 9, 12, 0, 0, 0, 0},
//								 {8, 11, 10, 14, 0, 0, 0, 0},
//								 {16, 17, 14, 13, 12, 15, 0, 0},
//								 {18, 15, 19, 16, 20, 17, 0, 0},
//								 {22, 23, 20, 19, 0, 0, 0, 0},
//								 {21, 22, 18, 0, 0, 0, 0, 0},
//								 {22, 19, 18, 0, 0, 0, 0, 0},
//								 {23, 26, 0, 0, 0, 0, 0, 0},
//								 {21, 24, 0, 0, 0, 0, 0, 0},
//								 {25, 0, 0, 0, 0, 0, 0, 0} };
//
//	vtkSmartPointer<vtkPoints> points =
//		vtkSmartPointer<vtkPoints>::New();
//	for (int i = 0; i < 27; i++) points->InsertPoint(i, x[i]);
//
//	vtkSmartPointer<vtkUnstructuredGrid> ugrid =
//		vtkSmartPointer<vtkUnstructuredGrid>::New();
//	ugrid->Allocate(100);
//	ugrid->InsertNextCell(VTK_HEXAHEDRON, 8, pts[0]);
//	ugrid->InsertNextCell(VTK_HEXAHEDRON, 8, pts[1]);
//	ugrid->InsertNextCell(VTK_TETRA, 4, pts[2]);
//	ugrid->InsertNextCell(VTK_TETRA, 4, pts[3]);
//	ugrid->InsertNextCell(VTK_POLYGON, 6, pts[4]);
//	ugrid->InsertNextCell(VTK_TRIANGLE_STRIP, 6, pts[5]);
//	ugrid->InsertNextCell(VTK_QUAD, 4, pts[6]);
//	ugrid->InsertNextCell(VTK_TRIANGLE, 3, pts[7]);
//	ugrid->InsertNextCell(VTK_TRIANGLE, 3, pts[8]);
//	ugrid->InsertNextCell(VTK_LINE, 2, pts[9]);
//	ugrid->InsertNextCell(VTK_LINE, 2, pts[10]);
//	ugrid->InsertNextCell(VTK_VERTEX, 1, pts[11]);
//
//	ugrid->SetPoints(points);
//
//	vtkSmartPointer<vtkDataSetMapper> ugridMapper =
//		vtkSmartPointer<vtkDataSetMapper>::New();
//	ugridMapper->SetInputData(ugrid);
//
//	vtkSmartPointer<vtkActor> ugridActor =
//		vtkSmartPointer<vtkActor>::New();
//	ugridActor->SetMapper(ugridMapper);
//	ugridActor->GetProperty()->SetColor(theInteractorStyle_->GeometryColorRGB.redF(), theInteractorStyle_->GeometryColorRGB.greenF(), theInteractorStyle_->GeometryColorRGB.blueF());
//	ugridActor->GetProperty()->EdgeVisibilityOn();
//
//	theRenderer_->AddActor(ugridActor);
//
//	//for (int i = 0; i < theGeometry_.size(); i++)
//	//{
//	//	theRenderer_->AddActor(theGeometry_.at(i));
//	//	theGeometry_.at(i)->GetProperty()->SetColor
//	//	(
//	//		theInteractorStyle_->GeometryColorRGB.redF(),
//	//		theInteractorStyle_->GeometryColorRGB.greenF(),
//	//		theInteractorStyle_->GeometryColorRGB.blueF()
//	//	);
//	//	//theGeometry_.at(i)->GetProperty()->SetColor(0.2, 0.6314, 0.788);
//	//	//theGeometry_.at(i)->GetProperty()->SetOpacity(0.6);
//	//	//theGeometry_.at(i)->SetBackfaceProperty(bprop);
//	//}
//
//	theRenderWindow_ = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
//
//	theRenderWindow_->AddRenderer(theRenderer_);
//
//	theRenderWindowInteractor_ = vtkSmartPointer<vtkRenderWindowInteractor>::New();
//	theRenderWindowInteractor_->SetRenderWindow(theRenderWindow_);
//
//	theInteractorStyle_ = vtkSmartPointer<FrgBaseInteractorStyle>::New();
//
//	theInteractorStyle_->SetParent(this);
//
//	theInteractorStyle_->SetMouseWheelMotionFactor(0.5);
//
//	theRenderWindowInteractor_->SetInteractorStyle(theInteractorStyle_);
//
//	vtkSmartPointer<vtkTransform> transform =
//		vtkSmartPointer<vtkTransform>::New();
//	transform->Scale(0.25, 0.25, 0.25);
//
//	vtkSmartPointer<vtkAxesActor> axes =
//		vtkSmartPointer<vtkAxesActor>::New();
//
//	axes->PickableOff();
//	/*axes->SetAxisLabels(false);
//	axes->SetUserTransform(transform);
//	theRenderer_->AddActor(axes);*/
//
//	vtkSmartPointer<vtkOrientationMarkerWidget> widget =
//		vtkSmartPointer<vtkOrientationMarkerWidget>::New();
//
//	widget->SetOutlineColor(0.9300, 0.5700, 0.1300);
//	widget->SetOrientationMarker(axes);
//	widget->SetInteractor(theRenderWindowInteractor_);
//	widget->SetViewport(0.0, 0.0, 0.25, 0.25);
//	widget->SetEnabled(1);
//	widget->InteractiveOn();
//
//	// Create a TextActor
//	theLogoActor_ = vtkSmartPointer<vtkTextActor>::New();
//	theLogoActor_->SetInput("Forg++");
//	vtkTextProperty* tprop = theLogoActor_->GetTextProperty();
//	tprop->SetFontFamilyToArial();
//	tprop->ShadowOff();
//
//	tprop->SetLineSpacing(1.0);
//	tprop->SetFontSize(24);
//	tprop->SetFontFamilyToArial();
//	tprop->ShadowOn();
//	tprop->SetColor(0, 0, 0); // (Black) Color
//
//	theLogoActor_->SetDisplayPosition(20, 20);
//	theRenderer_->AddActor2D(theLogoActor_);
//
//	theCamera_ = vtkSmartPointer<vtkCamera>::New();
//	theCamera_->SetPosition(0, 1, 0);
//	theCamera_->SetFocalPoint(0, 0, 0);
//	theCamera_->SetViewUp(0, 0, 1);
//	theCamera_->Azimuth(-180);
//	//theCamera_->Elevation(30);
//
//	theRenderer_->SetActiveCamera(theCamera_);
//	theRenderer_->ResetCamera();
//	theRenderer_->ResetCameraClippingRange();
//
//	this->SetRenderWindow(theRenderWindow_);
//
//	//this->show();
//
//	theRenderWindow_->Render();
//	//theRenderWindowInteractor_->Initialize();
//
//	GetParentMainWindow()->setCentralWidget(this);
//
//	/*if (!GetParentWindow()->GetSceneTabWidget())
//		GetParentWindow()->GetSceneTabWidget() = std::make_shared<TonbSceneTabWidget>(GetParentWindow(), (TonbTWI*)this, this->text(0));
//
//	GetParentWindow()->GetSceneTabWidget()->addTab((QWidget*)this, this->text(0));
//	GetParentWindow()->GetSceneTabWidget()->setCurrentWidget((QWidget*)this);
//
//	GetParentWindow()->GetParentWindow()->setCentralWidget((QWidget*)(GetParentWindow()->GetSceneTabWidget().get()));*/
//
//	theRenderWindowInteractor_->Start();
//
//	//FrgBasePlot2D* thePlot2D_ = FrgNew FrgBasePlot2D;
//}

void ForgBaseLib::FrgBaseSceneTreeItem::StartScene2()
{
	int i;
	static double x[27][3] = { {0,0,0}, {1,0,0}, {2,0,0}, {0,1,0}, {1,1,0}, {2,1,0},
							{0,0,1}, {1,0,1}, {2,0,1}, {0,1,1}, {1,1,1}, {2,1,1},
							{0,1,2}, {1,1,2}, {2,1,2}, {0,1,3}, {1,1,3}, {2,1,3},
							{0,1,4}, {1,1,4}, {2,1,4}, {0,1,5}, {1,1,5}, {2,1,5},
							{0,1,6}, {1,1,6}, {2,1,6} };
	static vtkIdType pts[12][8] = { {0, 1, 4, 3, 6, 7, 10, 9},
								 {1, 2, 5, 4, 7, 8, 11, 10},
								 {6, 10, 9, 12, 0, 0, 0, 0},
								 {8, 11, 10, 14, 0, 0, 0, 0},
								 {16, 17, 14, 13, 12, 15, 0, 0},
								 {18, 15, 19, 16, 20, 17, 0, 0},
								 {22, 23, 20, 19, 0, 0, 0, 0},
								 {21, 22, 18, 0, 0, 0, 0, 0},
								 {22, 19, 18, 0, 0, 0, 0, 0},
								 {23, 26, 0, 0, 0, 0, 0, 0},
								 {21, 24, 0, 0, 0, 0, 0, 0},
								 {25, 0, 0, 0, 0, 0, 0, 0} };


	vtkSmartPointer<vtkNamedColors> colors =
		vtkSmartPointer<vtkNamedColors>::New();

	vtkSmartPointer<vtkRenderer> renderer =
		vtkSmartPointer<vtkRenderer>::New();

	vtkSmartPointer<vtkRenderWindow> renWin =
		vtkSmartPointer<vtkRenderWindow>::New();
	renWin->AddRenderer(renderer);
	vtkSmartPointer<vtkRenderWindowInteractor> iren =
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	iren->SetRenderWindow(renWin);

	vtkSmartPointer<vtkPoints> points =
		vtkSmartPointer<vtkPoints>::New();
	for (i = 0; i < 27; i++) points->InsertPoint(i, x[i]);

	vtkSmartPointer<vtkUnstructuredGrid> ugrid =
		vtkSmartPointer<vtkUnstructuredGrid>::New();
	ugrid->Allocate(100);
	ugrid->InsertNextCell(VTK_HEXAHEDRON, 8, pts[0]);
	ugrid->InsertNextCell(VTK_HEXAHEDRON, 8, pts[1]);
	ugrid->InsertNextCell(VTK_TETRA, 4, pts[2]);
	ugrid->InsertNextCell(VTK_TETRA, 4, pts[3]);
	ugrid->InsertNextCell(VTK_POLYGON, 6, pts[4]);
	ugrid->InsertNextCell(VTK_TRIANGLE_STRIP, 6, pts[5]);
	ugrid->InsertNextCell(VTK_QUAD, 4, pts[6]);
	ugrid->InsertNextCell(VTK_TRIANGLE, 3, pts[7]);
	ugrid->InsertNextCell(VTK_TRIANGLE, 3, pts[8]);
	ugrid->InsertNextCell(VTK_LINE, 2, pts[9]);
	ugrid->InsertNextCell(VTK_LINE, 2, pts[10]);
	ugrid->InsertNextCell(VTK_VERTEX, 1, pts[11]);

	ugrid->SetPoints(points);

	vtkSmartPointer<vtkDataSetMapper> ugridMapper =
		vtkSmartPointer<vtkDataSetMapper>::New();
	ugridMapper->SetInputData(ugrid);

	vtkSmartPointer<vtkActor> ugridActor =
		vtkSmartPointer<vtkActor>::New();
	ugridActor->SetMapper(ugridMapper);
	ugridActor->GetProperty()->SetColor(theInteractorStyle_->GeometryColorRGB.redF(), theInteractorStyle_->GeometryColorRGB.greenF(), theInteractorStyle_->GeometryColorRGB.blueF());
	ugridActor->GetProperty()->EdgeVisibilityOn();

	renderer->AddActor(ugridActor);
	renderer->SetBackground(theInteractorStyle_->GeometryColorRGB.redF(), theInteractorStyle_->GeometryColorRGB.greenF(), theInteractorStyle_->GeometryColorRGB.blueF());

	renderer->ResetCamera();
	renderer->GetActiveCamera()->Elevation(60.0);
	renderer->GetActiveCamera()->Azimuth(30.0);
	renderer->GetActiveCamera()->Dolly(1.2);

	renWin->SetSize(640, 480);

	// interact with data
	renWin->Render();

	iren->Start();

	//GetParentMainWindow()->setCentralWidget(this);
}

void ForgBaseLib::FrgBaseSceneTreeItem::StartSceneNihad()
{
	/*AutLib::Leg_Nihad2_HullPatch patch;

	patch.FwdSection().Tightness0()->SetValue(0.9);
	patch.FwdSection().Tightness1()->SetValue(0.9);

	patch.AftSection().Trim()->SetValue(0.1);
	patch.MidSection().Trim()->SetValue(0.1);
	patch.FwdSection().Trim()->SetValue(0.1);

	patch.Perform();

	patch.FileFormat() = AutLib::Leg_EntityIO_Format::IGES;
	patch.ExportToFile();*/
}