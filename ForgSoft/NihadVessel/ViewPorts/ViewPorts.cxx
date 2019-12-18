#include <ViewPorts.hxx>
#include <CADScene.hxx>
#include <vtkTextActor.h>
#include <FrgBaseMainWindow.hxx>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidgetAction>
#include <QtWidgets/QLabel>
#include <FrgMenu_View.hxx>
#include <FrgBaseGlobalsICONS.hxx>
#include <FrgBaseCADPart.hxx>

class SliderWithTextWidget : public QWidget
{
private:

	QSlider* theSlider_ = FrgNullPtr;

public:

	SliderWithTextWidget(QWidget* parent, FrgString text, int min, int max, int step, int val)
		: QWidget(parent)
	{
		QHBoxLayout* layout = FrgNew QHBoxLayout(this);

		QLabel* label = FrgNew QLabel(text, parent);
		theSlider_ = FrgNew QSlider(Qt::Orientation::Horizontal, parent);
		theSlider_->setMinimum(min);
		theSlider_->setMaximum(max);
		theSlider_->setSingleStep(step);
		theSlider_->setValue(val);

		layout->addWidget(label);
		layout->addWidget(theSlider_);

		this->setLayout(layout);
	}

	FrgGetMacro(QSlider*, Slider, theSlider_);
};

ForgBaseLib::ViewPorts::ViewPorts(FrgBase_CADScene_TreeItem* parentCADSceneTreeItem, FrgBaseMainWindow* parent)
	: QMainWindow()
	, theParentMainWindow_(parent)
{
	setWindowFlag(Qt::FramelessWindowHint);

	theMdiArea_ = FrgNew QMdiArea(this);
	theToolBar_ = FrgNew QToolBar(this);

	AddScene(FrgNew CADScene(parentCADSceneTreeItem, parent->GetTree()), Qt::FramelessWindowHint);
	SetToolBar();

	this->setCentralWidget(theMdiArea_);

	TileSubWindows();
}

void ForgBaseLib::ViewPorts::SetLogoText(FrgString text)
{
	for (auto scene : theScenes_)
		scene->GetLogoActor()->SetInput(text.toStdString().c_str());
}

void ForgBaseLib::ViewPorts::CreateActor(FrgBaseCADPart_Entity* part)
{
	for (auto scene : theScenes_)
		scene->CreateActor(part);
}

void ForgBaseLib::ViewPorts::ClearScenes()
{
	for (auto scene : theScenes_)
		scene->ClearScene();
}

void ForgBaseLib::ViewPorts::RenderScenes(FrgBool resetCamera)
{
	for (auto scene : theScenes_)
		scene->Render(resetCamera);

	for (int i = 0; i < theMdiArea_->subWindowList().size(); i++)
	{
		theMdiArea_->subWindowActivated(theMdiArea_->subWindowList()[i]);
	}
}

void ForgBaseLib::ViewPorts::AddScene(CADScene * scene, Qt::WindowFlags flags)
{
	theScenes_.push_back(scene);

	theMdiArea_->addSubWindow(scene, flags);
}

void ForgBaseLib::ViewPorts::TileSubWindows()
{
	theMdiArea_->tileSubWindows();
}

#define AddQToolButton(iconAddress, ButtonText, Reciever, Slot)\
theToolButtons_.push_back(FrgNew QToolButton());\
theToolButtons_.last()->setToolButtonStyle(Qt::ToolButtonIconOnly);\
theToolButtons_.last()->setIcon(QPixmap(iconAddress));\
theToolButtons_.last()->setIconSize(QSize(32, 32));\
theToolButtons_.last()->setText(ButtonText);\
theToolBar_->addWidget(theToolButtons_.last());\
connect(theToolButtons_.last(), SIGNAL(clicked(bool)), Reciever, SLOT(Slot));

void ForgBaseLib::ViewPorts::SetToolBar()
{
	/*for (int i = 0; i < theScenes_.size(); i++)
	{
		theToolBar_->addActions(theScenes_[i]->GetContextMenuInScene()->GetItems());
		theToolBar_->addSeparator();
	}*/
	for (int i = 0; i < theScenes_[0]->GetMenus().size(); i++)
	{
		if (theScenes_[0]->GetMenus()[i]->GetItem("Screenshot..."))
			continue;
		if (theScenes_[0]->GetMenus()[i]->GetItem("Export Selected Parts"))
			continue;
		if (theScenes_[0]->GetMenus()[i]->GetItem("Random Colors"))
			continue;
		if (theScenes_[0]->GetMenus()[i]->GetItem("Show Mesh"))
			continue;
		if (theScenes_[0]->GetMenus()[i]->GetItem("Hide"))
			continue;
		if (theScenes_[0]->GetMenus()[i]->GetItem("Show Hidden Parts"))
			continue;

		theToolButtons_.push_back(FrgNew QToolButton(this));
		theToolButtons_.last()->setPopupMode(QToolButton::InstantPopup);
		theToolButtons_.last()->setMenu(theScenes_[0]->GetMenus()[i]);
		if (i == 0)
		{
			theToolButtons_.last()->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
			theToolButtons_.last()->setIcon(QIcon(FrgICON_Menu_View_XYZ));
			theToolButtons_.last()->setIconSize(QSize(32, 32));
		}
		if (i == 1)
		{
			theToolButtons_.last()->setText("Grid Options   ");
			theToolButtons_.last()->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

			SliderWithTextWidget* opacityWidget = FrgNew SliderWithTextWidget(this, "Grid Opacity", 0, 100, 1, 100);
			QWidgetAction* opacityAction = FrgNew QWidgetAction(this);
			opacityAction->setDefaultWidget(opacityWidget);

			connect(opacityWidget->GetSlider(), SIGNAL(valueChanged(int)), theScenes_[0], SLOT(GridOpacityChangedSlot(int)));

			theToolButtons_.last()->menu()->addAction(opacityAction);
		}

		theToolBar_->addWidget(theToolButtons_.last());
		theToolBar_->addSeparator();
	}

	{
		AddQToolButton(FrgICON_Menu_Scene_Cursor, "Select", theScenes_[0], SelectIconSelectedSlot(bool));
		AddQToolButton(FrgICON_Menu_Scene_Move, "Move", theScenes_[0], MoveIconSelectedSlot(bool));
		AddQToolButton(FrgICON_Menu_Scene_RotateX, "Rotate X", theScenes_[0], RotateXIconSelectedSlot(bool));
		AddQToolButton(FrgICON_Menu_Scene_RotateY, "Rotate Y", theScenes_[0], RotateYIconSelectedSlot(bool));
		AddQToolButton(FrgICON_Menu_Scene_RotateZ, "Rotate Z", theScenes_[0], RotateZIconSelectedSlot(bool));
		AddQToolButton(FrgICON_Menu_Scene_RotateXYZ, "Rotate XYZ", theScenes_[0], RotateXYZIconSelectedSlot(bool));
	}

	theToolBar_->setContextMenuPolicy(Qt::PreventContextMenu);

	this->addToolBar(theToolBar_);
}