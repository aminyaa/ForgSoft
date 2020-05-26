#include <FrgVisual_BaseActor.hxx>

#include <vtkObjectFactory.h>
#include <vtkProperty.h>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_BaseActor);

ForgVisualLib::FrgVisual_BaseActor::FrgVisual_BaseActor()
{

}

ForgVisualLib::FrgVisual_BaseActor::~FrgVisual_BaseActor()
{

}

void ForgVisualLib::FrgVisual_BaseActor::SetColor(double red, double green, double blue)
{
	GetProperty()->SetColor(red, green, blue);
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_BaseActor)
{

}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_BaseActor)
{

}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_BaseActor)