#include <FrgBase_ToolsParameter_TItem.hxx>
#include <FrgBase_ToolsParameters_TItem.hxx>
#include <FrgBase_SerialSpec_QString.hxx>
#include <FrgBase_Tree.hxx>

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

	//connect(this, &FrgBase_TreeItem::TItemIsGoingToBeDeleted, [this]()
	//	{
	//		if (theParentToolsParametersTItem_)
	//		{
	//			const auto& parameters = theParentToolsParametersTItem_->GetAllChildrenToTheRoot();
	//			for (const auto& x : parameters)
	//			{
	//				const auto& parameter = dynamic_cast<FrgBase_ToolsParameter_TItem*>(x);
	//				if (parameter)
	//				{
	//					//std::cout << " ===== > " << parameter->GetDependentParameters().size() << std::endl;
	//					if (parameter->GetDependentParameters().contains(this))
	//					{
	//						std::exception myException("You cannot delete this parameter due to dependency to another parameter.");
	//						throw myException;
	//					}
	//				}
	//			}
	//		}

	//		/*auto scalarParameter = dynamic_cast<FrgBase_ToolsParameterScalar_TItem*>(this);
	//		auto vectorParameter = dynamic_cast<FrgBase_ToolsParameterVector_TItem*>(this);

	//		double value;
	//		std::vector<double> values;

	//		if (scalarParameter)
	//		{
	//			value = scalarParameter->GetValue();
	//			theSymbolTableT_->remove_variable(theVariableName_.toStdString());
	//		}
	//		else if (vectorParameter)
	//		{
	//			values = vectorParameter->GetValues();
	//			theSymbolTableT_->remove_vector(theVariableName_.toStdString());
	//		}

	//		try
	//		{
	//			if (theParentToolsParametersTItem_)
	//				theParentToolsParametersTItem_->UpdateAllParameters();
	//		}
	//		catch (const std::exception& exc)
	//		{
	//			if (scalarParameter)
	//			{
	//				theSymbolTableT_->add_variable(theVariableName_.toStdString(), scalarParameter->GetValueRef());
	//			}
	//			else if (vectorParameter)
	//			{
	//				theSymbolTableT_->add_vector(theVariableName_.toStdString(), vectorParameter->GetValuesRef());
	//			}

	//			std::exception myException("You cannot delete this parameter due to dependency to another parameter.");
	//			throw myException;
	//		}*/
	//	}
	//);
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
	QString prefix("");

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
	if (!dependentParameter)
		return;

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
		const auto& myChildren = theParentToolsParametersTItem_->GetAllChildrenToTheRootByType<FrgBase_ToolsParameter_TItem>();
		for (const auto& myChild : myChildren)
		{
			if (myChild->GetDependentParameters().contains((FrgBase_ToolsParameter_TItem*)this))
				return false;
		}
	}

	return true;
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_ToolsParameter_TItem)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);
	auto dv = theDependentParameters_.toStdList();

	ar& theVariableName_;
	ar& dv;
	ar& theParentToolsParametersTItem_;
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_ToolsParameter_TItem)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);
	std::list<FrgBase_ToolsParameter_TItem*> dv;

	ar& theVariableName_;
	ar& dv;
	ar& theParentToolsParametersTItem_;

	theDependentParameters_ = QList<FrgBase_ToolsParameter_TItem*>::fromStdList(dv);

	if (theParentToolsParametersTItem_)
		theSymbolTableT_ = theParentToolsParametersTItem_->GetSymbolTableT();
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgBaseLib::FrgBase_ToolsParameter_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgBaseLib::FrgBase_ToolsParameter_TItem);
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgBaseLib::FrgBase_ToolsParameter_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgBaseLib::FrgBase_ToolsParameter_TItem);
}

BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgBaseLib::FrgBase_ToolsParameter_TItem)