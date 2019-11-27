#include <ViewPorts.hxx>
#include <CADScene.hxx>
#include <vtkTextActor.h>
#include <FrgBaseMainWindow.hxx>

ForgBaseLib::ViewPorts::ViewPorts(FrgBaseMainWindow* parent)
	: QMdiArea(parent)
	, theParentMainWindow_(parent)
{

}

void ForgBaseLib::ViewPorts::SetLogoText(FrgString text)
{
	for (auto scene : theScenes_)
		scene->GetLogoActor()->SetInput(text.toStdString().c_str());
}

void ForgBaseLib::ViewPorts::CreateActor(NihadVesselPartTreeItem * part)
{
	for (auto scene : theScenes_)
		scene->CreateActor(part);
}

void ForgBaseLib::ViewPorts::ClearScenes()
{
	for (auto scene : theScenes_)
		scene->ClearScene();
}

void ForgBaseLib::ViewPorts::RenderScenes()
{
	for (auto scene : theScenes_)
		scene->Render();

	for (int i = 0; i < subWindowList().size(); i++)
	{
		this->subWindowActivated(subWindowList()[i]);

		theParentMainWindow_->ParseErrorToConsole("Activated!");
	}
}

void ForgBaseLib::ViewPorts::AddScene(CADScene * scene, Qt::WindowFlags flags)
{
	theScenes_.push_back(scene);

	this->addSubWindow(scene, flags);
}