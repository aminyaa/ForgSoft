#include <FrgBase_ToolsParameter_TItem.hxx>
#include <FrgBase_ToolsParameters_TItem.hxx>

#include <exprtk.hpp>

ForgBaseLib::FrgBase_ToolsParameter_TItem::FrgBase_ToolsParameter_TItem
(
	const QString& itemTitle,
	FrgBase_TreeItem* parentItem,
	FrgBase_Tree* parentTree
)
	: ForgBaseLib::FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	AddRenameOptionInContextMenu();
	AddDeleteOptionInContextMenu();

	theVariableName_ = this->text(0).replace(' ', '_');

	connect(this, &FrgBase_TreeItem::TItemIsGoingToBeDeleted, [this]()
		{
			if (theParentToolsParametersTItem_)
			{
				const auto& parameters = theParentToolsParametersTItem_->GetAllChildrenToTheRoot();
				for (const auto& x : parameters)
				{
					const auto& parameter = dynamic_cast<FrgBase_ToolsParameter_TItem*>(x);
					if (parameter)
					{
						std::cout << " ===== > " << parameter->GetDependentParameters().size() << std::endl;
						if (parameter->GetDependentParameters().contains(this))
						{
							std::exception myException("You cannot delete this parameter due to dependency to another parameter.");
							throw myException;
						}
					}
				}
			}

			/*auto scalarParameter = dynamic_cast<FrgBase_ToolsParameterScalar_TItem*>(this);
			auto vectorParameter = dynamic_cast<FrgBase_ToolsParameterVector_TItem*>(this);

			double value;
			std::vector<double> values;

			if (scalarParameter)
			{
				value = scalarParameter->GetValue();
				theSymbolTableT_->remove_variable(theVariableName_.toStdString());
			}
			else if (vectorParameter)
			{
				values = vectorParameter->GetValues();
				theSymbolTableT_->remove_vector(theVariableName_.toStdString());
			}

			try
			{
				if (theParentToolsParametersTItem_)
					theParentToolsParametersTItem_->UpdateAllParameters();
			}
			catch (const std::exception& exc)
			{
				if (scalarParameter)
				{
					theSymbolTableT_->add_variable(theVariableName_.toStdString(), scalarParameter->GetValueRef());
				}
				else if (vectorParameter)
				{
					theSymbolTableT_->add_vector(theVariableName_.toStdString(), vectorParameter->GetValuesRef());
				}

				std::exception myException("You cannot delete this parameter due to dependency to another parameter.");
				throw myException;
			}*/
		}
	);
}

ForgBaseLib::FrgBase_ToolsParameter_TItem::~FrgBase_ToolsParameter_TItem()
{
	RemoveAllDependentParameters();
}

void ForgBaseLib::FrgBase_ToolsParameter_TItem::FormTItem()
{
	ForgBaseLib::FrgBase_TreeItem::FormTItem();
}

QString ForgBaseLib::FrgBase_ToolsParameter_TItem::GetCorrectedVariableName(const QString& s) const
{
	QString newName = s.simplified();
	QString editedName = newName;
	QString prefix("P_");

	int i = 0;
	for (auto c : newName)
	{
		if (!c.isLetterOrNumber())
		{
			if (c == " ")
				editedName = editedName.replace(i, 1, "_");
			else
			{
				editedName = editedName.replace(i, 1, "");
				i--;
			}
		}

		i++;
	}

	newName = prefix + editedName;

	return newName;
}

void ForgBaseLib::FrgBase_ToolsParameter_TItem::Update()
{
	for (const auto& dependentParameter : theDependentParameters_)
		dependentParameter->Update();
}

void ForgBaseLib::FrgBase_ToolsParameter_TItem::AddDependentParameter(FrgBase_ToolsParameter_TItem* dependentParameter)
{
	if (!theDependentParameters_.contains(dependentParameter))
		theDependentParameters_.push_back(dependentParameter);
}

void ForgBaseLib::FrgBase_ToolsParameter_TItem::RemoveDependentParameter(FrgBase_ToolsParameter_TItem* dependentParameter)
{
	theDependentParameters_.removeOne(dependentParameter);
}

void ForgBaseLib::FrgBase_ToolsParameter_TItem::RemoveAllDependentParameters()
{
	theDependentParameters_.clear();
}

bool ForgBaseLib::FrgBase_ToolsParameter_TItem::IsDeletable() const
{
	if (!FrgBase_TreeItem::IsDeletable())
		return false;

	if (theParentToolsParametersTItem_)
	{
		const auto& myChildren = theParentToolsParametersTItem_->GetAllChildrenToTheRoot();
		for (const auto& myChild : myChildren)
		{
			const auto& paramaterTItem = dynamic_cast<FrgBase_ToolsParameter_TItem*>(myChild);
			if (paramaterTItem)
			{
				if (paramaterTItem == this)
					continue;

				if (!paramaterTItem->IsInDependent())
				{
					if (paramaterTItem->GetDependentParameters().contains(const_cast<FrgBase_ToolsParameter_TItem*>(this)))
					{
						return false;
					}
				}
			}
		}
	}

	return true;
}