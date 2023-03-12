#pragma once

#include <FrgBase_PrptsWdgSelectTItemFromTItem_Dlg.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgBase_Tree.hxx>

#include <QtWidgets/QLabel>

template<typename Type>
inline ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem<Type>::FrgBase_PrptsWdgSelectTItemFromTItem
(
	QWidget* parent,
	FrgBase_PrptsVrnt* variant
)
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
	auto myVariant =
		dynamic_cast<FrgBase_PrptsVrntSelectTItemFromTItem<Type>*>(theVariant_);

	if (!myVariant)
		throw std::exception("Variant is null in " __FUNCSIG__);

	const auto& selectFunction =
		myVariant->GetSelectTItemFunction();

	FrgBase_TreeItem* result = nullptr;

	if (selectFunction)
	{
		result = selectFunction();
	}
	else
	{
		auto propertiesPanel =
			dynamic_cast<FrgBase_PropertiesPanel*>(theParent_);

		auto myMainWindow =
			dynamic_cast<FrgBase_MainWindow*>(propertiesPanel->GetParentWidget());

		auto selectTItemDlg =
			std::make_shared<FrgBase_PrptsWdgSelectTItemFromTItem_Dlg<Type>>
			(
				"Select Item",
				myMainWindow,
				myVariant
				);

		if (selectTItemDlg->exec() == QDialog::Accepted)
			result = dynamic_cast<FrgBase_TreeItem*>(selectTItemDlg->GetSelectedTItem());

		if (propertiesPanel)
		{
			auto myTItem =
				dynamic_cast<QTreeWidgetItem*>(propertiesPanel->GetParentObject());

			if (myTItem)
				emit myMainWindow->GetTree()->itemClicked(myTItem, 0);
		}
	}

	if (result)
	{
		myVariant->SetValue(result);
		theSelectedTItemLabel_->setText(result->text(0));
	}
}