#include <FrgVisual_Scene_TItem.hxx>
#include <FrgVisual_Scene.hxx>

#include <FrgVisual_SceneAttributes_TItem.hxx>
#include <FrgVisual_SceneAttBackColor_TItem.hxx>
#include <FrgVisual_SceneAttBackColorSolid_TItem.hxx>
#include <FrgVisual_SceneAttBackColorGradient_TItem.hxx>
#include <FrgVisual_SceneAttAxes_TItem.hxx>

#include <FrgBase_Tree.hxx>
#include <FrgBase_MainWindow.hxx>

#include <vtkRenderer.h>
#include <vtkAxesActor.h>
#include <vtkCaptionActor2D.h>
#include <vtkTextProperty.h>

ForgVisualLib::FrgVisual_Scene_TItem_Entity::FrgVisual_Scene_TItem_Entity
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: ForgBaseLib::FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	this->AddRenameOptionInContextMenu();
	this->AddDeleteOptionInContextMenu();

	SetParentTitleTItem(GetParentTItem());

	connect(this, &FrgVisual_Scene_TItem_Entity::TItemNameChanged, this, &FrgVisual_Scene_TItem_Entity::TItemNameToTabTitleChangedSlot);
}

void ForgVisualLib::FrgVisual_Scene_TItem_Entity::FormTItem()
{
	ForgBaseLib::FrgBase_TreeItem::FormTItem();
}

void ForgVisualLib::FrgVisual_Scene_TItem_Entity::SetParentTitleTItem(ForgBaseLib::FrgBase_TreeItem* pt)
{
	if (theParentTitleTItem_)
	{
		disconnect
		(
			theParentTitleTItem_,
			&ForgBaseLib::FrgBase_TreeItem::TItemNameChanged,
			this,
			&ForgVisualLib::FrgVisual_Scene_TItem_Entity::TItemNameToTabTitleChangedSlot
		);
	}

	theParentTitleTItem_ = pt;

	if (theParentTitleTItem_)
	{
		connect
		(
			theParentTitleTItem_,
			&ForgBaseLib::FrgBase_TreeItem::TItemNameChanged,
			this,
			&ForgVisualLib::FrgVisual_Scene_TItem_Entity::TItemNameToTabTitleChangedSlot
		);
	}
}

void ForgVisualLib::FrgVisual_Scene_TItem_Entity::TItemDoubleClickedSlot()
{
	ShowTabWidget();
}

QString ForgVisualLib::FrgVisual_Scene_TItem_Entity::GetTabText() const
{
	QString prefix = "";
	if (theParentTitleTItem_)
		prefix = theParentTitleTItem_->text(0);

	if (prefix.isEmpty())
		return this->text(0);
	else
		return (prefix + " - " + this->text(0));
}

template<int Dim>
ForgVisualLib::FrgVisual_Scene_TItem<Dim>::FrgVisual_Scene_TItem
(
	const QString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgVisual_Scene_TItem_Entity(itemTitle, parentItem, parentTree)
{

}

template<int Dim>
ForgVisualLib::FrgVisual_Scene_TItem<Dim>::~FrgVisual_Scene_TItem()
{
	if (GetParentMainWindow())
		GetParentMainWindow()->RemoveTabWidget(theScene_);

	theScene_->deleteLater();
	//FreePointer(theScene_);
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene_TItem<Dim>::FormTItem()
{
	FrgVisual_Scene_TItem_Entity::FormTItem();

	ShowTabWidget();

	theAttributes_ = new FrgVisual_SceneAttributes_TItem<Dim>("Attributes", dynamic_cast<FrgVisual_Scene_TItem*>(this), GetParentTree());
	theAttributes_->FormTItem();

	theAttributes_->setHidden(true);

	auto myBackgroundColor = theAttributes_->GetBackgroundColor();
	connect(myBackgroundColor, SIGNAL(GradientModeChangedSignal(const QString&)), this, SLOT(BackgroundGradientModeChangedSlot(const QString&)));
	connect(myBackgroundColor, SIGNAL(GradientColor1ChangedSignal(const QColor&)), this, SLOT(BackgroundGradientColor1ChangedSlot(const QColor&)));
	connect(myBackgroundColor, SIGNAL(GradientColor2ChangedSignal(const QColor&)), this, SLOT(BackgroundGradientColor2ChangedSlot(const QColor&)));
	connect(myBackgroundColor, SIGNAL(SolidColorChangedSignal(const QColor&)), this, SLOT(BackgroundSolidColorChangedSlot(const QColor&)));

	auto myAxes = theAttributes_->GetAxes();
	connect(myAxes, SIGNAL(TextColorChangedSignal(const QColor&)), this, SLOT(AxesTextColorChangedSlot(const QColor&)));
	connect(myAxes, SIGNAL(VisibleChangedSignal(const bool&)), this, SLOT(AxesVisibleChangedSlot(const bool&)));
	connect(myAxes, SIGNAL(XLabelChangedSignal(const QString&)), this, SLOT(AxesXLabelChangedSlot(const QString&)));
	connect(myAxes, SIGNAL(YLabelChangedSignal(const QString&)), this, SLOT(AxesYLabelChangedSlot(const QString&)));
	connect(myAxes, SIGNAL(ZLabelChangedSignal(const QString&)), this, SLOT(AxesZLabelChangedSlot(const QString&)));
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene_TItem<Dim>::SetThemeDark
(
	const bool isDark
)
{
	if (theScene_)
		theScene_->SetThemeDark(isDark);
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene_TItem<Dim>::ShowTabWidget()
{
	if (GetParentMainWindow())
		GetParentMainWindow()->ShowTabWidget(theScene_, GetTabText());
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene_TItem<Dim>::TItemNameToTabTitleChangedSlot(const QString& title)
{
	GetParentMainWindow()->SetTabText(theScene_, GetTabText());

	/*auto myMainWindow = dynamic_cast<ForgBaseLib::FrgBase_MainWindow*>(GetParentMainWindow());
	if (myMainWindow)
		myMainWindow->SetTabText(theScene_, title + " - " + this->text(0));*/
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene_TItem<Dim>::SetParentMainWindow(ForgBaseLib::FrgBase_MainWindow* parentMainWindow)
{
	ForgBaseLib::FrgBase_TreeItem::SetParentMainWindow(parentMainWindow);

	if (theScene_)
		theScene_->SetParentMainWindow(parentMainWindow);
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene_TItem<Dim>::BackgroundGradientModeChangedSlot(const QString& mode)
{
	if (theScene_)
	{
		auto myRenderer = theScene_->GetRenderer();
		if (myRenderer)
		{
			auto myBackgroundColor = theAttributes_->GetBackgroundColor();
			auto myGradientBackground = myBackgroundColor->GetGradientBackground();

			if (mode == "Top-Bottom")
			{
				BackgroundGradientColor1ChangedSlot(myGradientBackground->GetColor1());
				BackgroundGradientColor2ChangedSlot(myGradientBackground->GetColor2());
			}
			else if (mode == "Bottom-Top")
			{
				BackgroundGradientColor1ChangedSlot(myGradientBackground->GetColor2());
				BackgroundGradientColor2ChangedSlot(myGradientBackground->GetColor1());
			}
			else if (mode == "Left-Right")
			{

			}
			else if (mode == "Right-Left")
			{

			}
			else if (mode == "Radial")
			{

			}
		}
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene_TItem<Dim>::BackgroundGradientColor1ChangedSlot(const QColor& color1)
{
	if (theScene_)
	{
		auto myRenderer = theScene_->GetRenderer();
		if (myRenderer)
		{
			myRenderer->SetBackground(color1.redF(), color1.greenF(), color1.blueF());

			theScene_->RenderScene(false);
		}
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene_TItem<Dim>::BackgroundGradientColor2ChangedSlot(const QColor& color2)
{
	if (theScene_)
	{
		auto myRenderer = theScene_->GetRenderer();
		if (myRenderer)
		{
			myRenderer->SetBackground2(color2.redF(), color2.greenF(), color2.blueF());

			theScene_->RenderScene(false);
		}
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene_TItem<Dim>::BackgroundSolidColorChangedSlot(const QColor& color)
{
	if (theScene_)
	{
		auto myRenderer = theScene_->GetRenderer();
		if (myRenderer)
		{
			myRenderer->SetBackground(color.redF(), color.greenF(), color.blueF());
			myRenderer->SetBackground2(color.redF(), color.greenF(), color.blueF());

			theScene_->RenderScene(false);
		}
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene_TItem<Dim>::AxesTextColorChangedSlot(const QColor& color)
{
	if (theScene_)
	{
		theScene_->GetAxesActor()->GetXAxisCaptionActor2D()->GetCaptionTextProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
		theScene_->GetAxesActor()->GetYAxisCaptionActor2D()->GetCaptionTextProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
		theScene_->GetAxesActor()->GetZAxisCaptionActor2D()->GetCaptionTextProperty()->SetColor(color.redF(), color.greenF(), color.blueF());

		theScene_->RenderScene(false);
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene_TItem<Dim>::AxesVisibleChangedSlot(const bool& visible)
{
	if (theScene_)
	{
		theScene_->GetAxesActor()->SetVisibility(visible);

		theScene_->RenderScene(false);
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene_TItem<Dim>::AxesXLabelChangedSlot(const QString& xLabel)
{
	if (theScene_)
	{
		theScene_->GetAxesActor()->SetXAxisLabelText(xLabel.toStdString().c_str());

		theScene_->RenderScene(false);
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene_TItem<Dim>::AxesYLabelChangedSlot(const QString& yLabel)
{
	if (theScene_)
	{
		theScene_->GetAxesActor()->SetYAxisLabelText(yLabel.toStdString().c_str());

		theScene_->RenderScene(false);
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene_TItem<Dim>::AxesZLabelChangedSlot(const QString& zLabel)
{
	if (theScene_)
	{
		theScene_->GetAxesActor()->SetZAxisLabelText(zLabel.toStdString().c_str());

		theScene_->RenderScene(false);
	}
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Scene_TItem_Entity)
{

}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Scene_TItem_Entity)
{

}

DECLARE_SAVE_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Scene_TItem_Entity)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Scene_TItem_Entity);
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Scene_TItem_Entity)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Scene_TItem_Entity);
}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Scene_TItem<Dim>)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);

	ar& theScene_;
	//ar& theAttributes_;
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Scene_TItem<Dim>)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);

	ar& theScene_;
	//ar& theAttributes_;

	/*auto myBackgroundColor = theAttributes_->GetBackgroundColor();
	connect(myBackgroundColor, SIGNAL(GradientModeChangedSignal(const QString&)), this, SLOT(BackgroundGradientModeChangedSlot(const QString&)));
	connect(myBackgroundColor, SIGNAL(GradientColor1ChangedSignal(const QColor&)), this, SLOT(BackgroundGradientColor1ChangedSlot(const QColor&)));
	connect(myBackgroundColor, SIGNAL(GradientColor2ChangedSignal(const QColor&)), this, SLOT(BackgroundGradientColor2ChangedSlot(const QColor&)));
	connect(myBackgroundColor, SIGNAL(SolidColorChangedSignal(const QColor&)), this, SLOT(BackgroundSolidColorChangedSlot(const QColor&)));

	auto myAxes = theAttributes_->GetAxes();
	connect(myAxes, SIGNAL(TextColorChangedSignal(const QColor&)), this, SLOT(AxesTextColorChangedSlot(const QColor&)));
	connect(myAxes, SIGNAL(VisibleChangedSignal(const bool&)), this, SLOT(AxesVisibleChangedSlot(const bool&)));
	connect(myAxes, SIGNAL(XLabelChangedSignal(const QString&)), this, SLOT(AxesXLabelChangedSlot(const QString&)));
	connect(myAxes, SIGNAL(YLabelChangedSignal(const QString&)), this, SLOT(AxesYLabelChangedSlot(const QString&)));
	connect(myAxes, SIGNAL(ZLabelChangedSignal(const QString&)), this, SLOT(AxesZLabelChangedSlot(const QString&)));*/
}

template<class Archive, int Dim>
void boost::serialization::save_construct_data
(
	Archive& ar,
	const ForgVisualLib::FrgVisual_Scene_TItem<Dim>* t,
	const unsigned int version
)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Scene_TItem<Dim>);
}

template<class Archive, int Dim>
void boost::serialization::load_construct_data
(
	Archive& ar,
	ForgVisualLib::FrgVisual_Scene_TItem<Dim>* t,
	const unsigned int version
)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Scene_TItem<Dim>);
}

BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_Scene_TItem_Entity)

BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_Scene_TItem<2>)
BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_Scene_TItem<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_Scene_TItem<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_Scene_TItem<3>;