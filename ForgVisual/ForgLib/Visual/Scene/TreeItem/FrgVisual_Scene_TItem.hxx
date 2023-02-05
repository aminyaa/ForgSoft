#pragma once
#ifndef _FrgVisual_Scene_TItem_Header
#define _FrgVisual_Scene_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>

#include <FrgVisual_Serialization_Global.hxx>

namespace ForgBaseLib
{
	class FrgBase_MainWindow;
}

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_Scene_TItem_Entity
	: public ForgBaseLib::FrgBase_TreeItem
{

	Q_OBJECT

public:

	FrgVisual_Scene_TItem_Entity
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	void FormTItem() override;

	virtual bool Is2D() const { return false; }
	virtual bool Is3D() const { return false; }

	ForgBaseLib::FrgBase_TreeItem* GetParentTitleTItem() const { return theParentTitleTItem_; }
	virtual void SetParentTitleTItem(ForgBaseLib::FrgBase_TreeItem* pt);

private:

	DECLARE_SAVE_LOAD_HEADER( )

public slots:

	virtual void BackgroundGradientModeChangedSlot(const QString& mode) {}
	virtual void BackgroundGradientColor1ChangedSlot(const QColor& color1) {}
	virtual void BackgroundGradientColor2ChangedSlot(const QColor& color2) {}
	virtual void BackgroundSolidColorChangedSlot(const QColor& color) {}

	virtual void AxesTextColorChangedSlot(const QColor& color) {}
	virtual void AxesVisibleChangedSlot(const bool& visible) {}
	virtual void AxesXLabelChangedSlot(const QString& xLabel) {}
	virtual void AxesYLabelChangedSlot(const QString& yLabel) {}
	virtual void AxesZLabelChangedSlot(const QString& zLabel) {}

	virtual void ShowTabWidget() {}

	virtual QString GetTabText() const;

protected slots:

	void TItemDoubleClickedSlot() override;
	virtual void TItemNameToTabTitleChangedSlot(const QString&) {}

protected:

	ForgBaseLib::FrgBase_TreeItem* theParentTitleTItem_ = nullptr;
};

template<int Dim>
class FrgVisual_Scene;

template <int Dim>
class FrgVisual_SceneAttributes_TItem;

template<int Dim>
class FORGVISUAL_EXPORT FrgVisual_Scene_TItem
	: public FrgVisual_Scene_TItem_Entity
{

public:

	FrgVisual_Scene_TItem
	(
		const QString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	~FrgVisual_Scene_TItem();

	void FormTItem() override;


	void SetThemeDark(const bool isDark = false) override;

	FrgVisual_Scene<Dim>* GetScene() const { return theScene_; }

	void SetParentMainWindow(ForgBaseLib::FrgBase_MainWindow* parentMainWindow) override;

	FrgVisual_SceneAttributes_TItem<Dim>* GetAttributes() const { return theAttributes_; }

private:

	DECLARE_SAVE_LOAD_HEADER( )

public:

	void BackgroundGradientModeChangedSlot(const QString& mode) override;
	void BackgroundGradientColor1ChangedSlot(const QColor& color1) override;
	void BackgroundGradientColor2ChangedSlot(const QColor& color2) override;
	void BackgroundSolidColorChangedSlot(const QColor& color) override;

	void AxesTextColorChangedSlot(const QColor& color) override;
	void AxesVisibleChangedSlot(const bool& visible) override;
	void AxesXLabelChangedSlot(const QString& xLabel) override;
	void AxesYLabelChangedSlot(const QString& yLabel) override;
	void AxesZLabelChangedSlot(const QString& zLabel) override;

	void ShowTabWidget() override;
	void TItemNameToTabTitleChangedSlot(const QString&) override;

protected:

	FrgVisual_Scene<Dim>* theScene_ = NullPtr;

	FrgVisual_SceneAttributes_TItem<Dim>* theAttributes_ = nullptr;
};

EndForgVisualLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgVisualLib::FrgVisual_Scene_TItem_Entity, FORGVISUAL_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Scene_TItem_Entity)

namespace boost
{
	namespace serialization
	{
		template<class Archive, int Dim>
		void save_construct_data(Archive& ar, const ForgVisualLib::FrgVisual_Scene_TItem<Dim>* m, const unsigned int version);
		template<class Archive, int Dim>
		void load_construct_data(Archive& ar, ForgVisualLib::FrgVisual_Scene_TItem<Dim>* m, const unsigned int version);
	}
}

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Scene_TItem<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Scene_TItem<3>)

#endif // !_FrgVisual_Scene_TItem_Header
