#pragma once

#include <FrgBase_PrptsWdgSelectTItemFromTItem_Dlg.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgBase_Tree.hxx>

#include <QtWidgets/QLabel>

template<typename Type>
inline ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem<Type>::FrgBase_PrptsWdgSelectTItemFromTItem(QWidget* parent, FrgBase_PrptsVrnt* variant)
	: FrgBase_PrptsWdgSelectTItemFromTItem_Base(parent, variant)
{

}

template<typename Type>
inline ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem<Type>::~FrgBase_PrptsWdgSelectTItemFromTItem()
{

}

template<typename Type>
inline void ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem<Type>::OnButtonClicked()
{
	auto myVariant = dynamic_cast<FrgBase_PrptsVrntSelectTItemFromTItem<Type>*>(theVariant_);

	auto propertiesPanel = dynamic_cast<FrgBase_PropertiesPanel*>(theParent_);
	auto myMainWindow = dynamic_cast<FrgBase_MainWindow*>(propertiesPanel->GetParentWidget());
	std::shared_ptr<FrgBase_PrptsWdgSelectTItemFromTItem_Dlg<Type>> selectTItemDlg = std::make_shared<FrgBase_PrptsWdgSelectTItemFromTItem_Dlg<Type>>
		(
			"Select Item",
			myMainWindow,
			myVariant
			);

	if (selectTItemDlg->exec() == QDialog::Accepted)
	{
		myVariant->SetValue(dynamic_cast<FrgBase_TreeItem*>(selectTItemDlg->GetSelectedTItem()));
		theSelectedTItemLabel_->setText(selectTItemDlg->GetSelectedTItem()->text(0));
	}

	FrgBase_PropertiesPanel* myPanel = dynamic_cast<FrgBase_PropertiesPanel*>(theParent_);
	if (myPanel)
	{
		QTreeWidgetItem* myTItem = dynamic_cast<QTreeWidgetItem*>(myPanel->GetParentObject());
		if (myTItem)
			emit myMainWindow->GetTree()->itemClicked(myTItem, 0);
	}
}