#include <FrgVisual_3DLineActor.hxx>

#include <FrgBase_Pnt3d.hxx>

#include <vtkObjectFactory.h>
#include <vtkLineSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_3DLineActor);

ForgVisualLib::FrgVisual_3DLineActor::FrgVisual_3DLineActor()
{
	GetProperty()->SetRepresentationToWireframe();
}

ForgVisualLib::FrgVisual_3DLineActor::~FrgVisual_3DLineActor()
{

}

void ForgVisualLib::FrgVisual_3DLineActor::SetLineWidth(float width)
{
	GetProperty()->SetLineWidth(width);
}

void ForgVisualLib::FrgVisual_3DLineActor::SetRenderLinesAsTubes(bool condition)
{
	GetProperty()->SetRenderLinesAsTubes(condition);
}

void ForgVisualLib::FrgVisual_3DLineActor::SetData(std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> P0, std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> P1)
{
	if (P0 == nullptr || P1 == nullptr)
		return;

	theP0_ = P0;
	theP1_ = P1;

	vtkSmartPointer<vtkLineSource> lineSource =
		vtkSmartPointer<vtkLineSource>::New();
	lineSource->SetPoint1(P0->X(), P0->Y(), P0->Z());
	lineSource->SetPoint2(P1->X(), P1->Y(), P1->Z());

	vtkSmartPointer<vtkPolyDataMapper> mapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputConnection(lineSource->GetOutputPort());

	this->SetMapper(mapper);
}

void ForgVisualLib::FrgVisual_3DLineActor::SetData(double P0_X, double P0_Y, double P0_Z, double P1_X, double P1_Y, double P1_Z)
{
	SetData(std::make_shared<ForgBaseLib::FrgBase_Pnt3d>(P0_X, P0_Y, P0_Z), std::make_shared<ForgBaseLib::FrgBase_Pnt3d>(P1_X, P1_Y, P1_Z));
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_3DLineActor)
{
	VOID_CAST_REGISTER(ForgVisualLib::FrgVisual_3DLineActor, ForgVisualLib::FrgVisual_3DBaseActor);

	ar & theP0_;
	ar & theP1_;
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_3DLineActor)
{
	VOID_CAST_REGISTER(ForgVisualLib::FrgVisual_3DLineActor, ForgVisualLib::FrgVisual_3DBaseActor);

	ar & theP0_;
	ar & theP1_;

	SetData(theP0_, theP1_);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_3DLineActor)