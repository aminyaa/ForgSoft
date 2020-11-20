#ifndef _FrgMarine_Scene3D_TItem_Header
#define _FrgMarine_Scene3D_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgVisual_Scene3D_TItem.hxx>
#include <FrgBase_PrptsVrntSelectTItems.hxx>

#include <FrgMarine_Serialization_Global.hxx>

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_Scene3D_TItem
	: public ForgVisualLib::FrgVisual_Scene3D_TItem
{
	Q_OBJECT

		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntSelectTItems* SelectTItems READ GetSelectTItems WRITE SetSelectTItems)

public:

	FrgMarine_Scene3D_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	void FormTItem() override;

	ForgBaseLib::FrgBase_PrptsVrntSelectTItems* GetSelectTItems() const { return theSelectTItems_; }
	void SetSelectTItems(ForgBaseLib::FrgBase_PrptsVrntSelectTItems* selectTItems) { theSelectTItems_ = selectTItems; }

	//void ShowTabWidget();

private:

	DECLARE_SAVE_LOAD_HEADER(FORGMARINE_EXPORT)

private:

	ForgBaseLib::FrgBase_PrptsVrntSelectTItems* theSelectTItems_ = nullptr;

//public slots:
//
//	void TItemDoubleClickedSlot() override;
//
//protected slots:
//
//	void TItemNameToTabTitleChangedSlot(const QString&);
};

EndForgMarineLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgMarineLib::FrgMarine_Scene3D_TItem, FORGMARINE_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgMarineLib::FrgMarine_Scene3D_TItem)

#endif // !_FrgMarine_Scene3D_TItem_Header
