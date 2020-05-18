#pragma once
#include <FrgBase_PrptsWdgSelectTItem_Dlg.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_MainWindow.hxx>

#include <QtWidgets/QLabel>

template<typename Type>
inline ForgBaseLib::FrgBase_PrptsWdgSelectTItem<Type>::FrgBase_PrptsWdgSelectTItem(QWidget * parent, FrgBase_PrptsVrnt * variant)
	: FrgBase_PrptsWdgSelectTItem_Base(parent, variant)
{

}

template<typename Type>
inline ForgBaseLib::FrgBase_PrptsWdgSelectTItem<Type>::~FrgBase_PrptsWdgSelectTItem()
{

}

template<typename Type>
inline void ForgBaseLib::FrgBase_PrptsWdgSelectTItem<Type>::OnButtonClicked()
{
	auto myVariant = dynamic_cast<FrgBase_PrptsVrntSelectTItem<Type>*>(theVariant_);

	auto propertiesPanel = dynamic_cast<FrgBase_PropertiesPanel*>(theParent_);
	auto myMainWindow = dynamic_cast<FrgBase_MainWindow*>(propertiesPanel->GetParentWidget());
	std::shared_ptr<FrgBase_PrptsWdgSelectTItem_Dlg<Type>> selectTItemDlg = std::make_shared<FrgBase_PrptsWdgSelectTItem_Dlg<Type>>
		(
			"Select Item",
			myMainWindow,
			myVariant->GetValue()
			);

	if (selectTItemDlg->exec() == QDialog::Accepted)
	{
		myVariant->SetValue(dynamic_cast<FrgBase_TreeItem*>(selectTItemDlg->GetSelectedTItem()));
		theSelectedTItemLabel_->setText(selectTItemDlg->GetSelectedTItem()->text(0));
	}
}