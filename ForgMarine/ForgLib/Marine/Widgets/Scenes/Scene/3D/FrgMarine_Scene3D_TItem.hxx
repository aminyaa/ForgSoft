#ifndef _FrgMarine_Scene3D_TItem_Header
#define _FrgMarine_Scene3D_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgVisual_Scene3D_TItem.hxx>
#include <FrgBase_PrptsVrntSelectTItems.hxx>

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

	ForgBaseLib::FrgBase_PrptsVrntSelectTItems* GetSelectTItems() const { return theSelectTItems_; }
	void SetSelectTItems(ForgBaseLib::FrgBase_PrptsVrntSelectTItems* selectTItems) { theSelectTItems_ = selectTItems; }

	void ShowTabWidget();

private:

	ForgBaseLib::FrgBase_PrptsVrntSelectTItems* theSelectTItems_ = nullptr;

public slots:

	void TItemDoubleClickedSlot() override;

protected slots:

	void TItemNameToTabTitleChangedSlot(const QString&);
};

EndForgMarineLib

#endif // !_FrgMarine_Scene3D_TItem_Header
