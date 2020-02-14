#include <FrgVisual_Scene.hxx>
#include <FrgBase_MainWindow.hxx>

#include <vtkActor.h>
#include <vtkTextActor.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkTextProperty.h>
#include <vtkCollection.h>

#include <vtkAutoInit.h>

VTK_MODULE_INIT(vtkRenderingContextOpenGL2)
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)
VTK_MODULE_INIT(vtkRenderingFreeType)

ForgVisualLib::FrgVisual_Scene::FrgVisual_Scene(ForgBaseLib::FrgBase_MainWindow * parentMainWindow)
	: QVTKOpenGLNativeWidget(parentMainWindow)
{

}

void ForgVisualLib::FrgVisual_Scene::RemoveAllActors()
{
	if (theRenderer_)
	{
		vtkActorCollection* ac = theRenderer_->GetActors();
		vtkCollectionSimpleIterator ait;
		vtkActor* anActor, *aPart;
		vtkAssemblyPath* path;
		for (ac->InitTraversal(ait); (anActor = ac->GetNextActor(ait)); )
		{
			theRenderer_->RemoveActor(anActor);
		}
	}
}

void ForgVisualLib::FrgVisual_Scene::SetLogoText(const char * logoText)
{
	if (theLogoActor_)
	{
		theLogoActor_->SetInput(logoText);
		RenderScene(false);
	}
}