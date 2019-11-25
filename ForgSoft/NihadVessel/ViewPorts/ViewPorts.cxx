#include <ViewPorts.hxx>
#include <CADScene.hxx>
#include <vtkTextActor.h>

ForgBaseLib::ViewPorts::ViewPorts(QWidget* parent)
	: QMdiArea(parent)
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

	for (auto window : subWindowList())
		activateNextSubWindow();
}

void ForgBaseLib::ViewPorts::AddScene(CADScene * scene, Qt::WindowFlags flags)
{
	theScenes_.push_back(scene);

	this->addSubWindow(scene, flags);
}