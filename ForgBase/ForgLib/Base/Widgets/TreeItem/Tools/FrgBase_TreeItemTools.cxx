#include <FrgBase_TreeItemTools.hxx>
#include <FrgBase_TreeItem.hxx>

ForgBaseLib::FrgBase_TreeItemToolsNamespace::FrgBase_Node::FrgBase_Node
(
	int level,
	const QString& name,
	QIcon icon,
	FrgBase_Node* parentNode
)
	: theLevel_(level)
	, theName_(name)
	, theIcon_(icon)
{

}

ForgBaseLib::FrgBase_TreeItemToolsNamespace::FrgBase_Node::FrgBase_Node
(
	int level,
	FrgBase_TreeItem* pointerToItem,
	FrgBase_Node* parentNode
)
	: theLevel_(level)
	, thePointerToItem_(pointerToItem)
	, theParentNode_(parentNode)
{
	if (thePointerToItem_)
	{
		theName_ = thePointerToItem_->text(0);
		theIcon_ = thePointerToItem_->icon(0);
	}
}

std::vector<std::vector<ForgBaseLib::FrgBase_TreeItemToolsNamespace::FrgBase_Node*>> ForgBaseLib::FrgBase_TreeItemToolsNamespace::GetNodes
(
	const std::vector<FrgBase_TreeItem*>& items,
	bool recursive
)
{
	std::vector<std::vector<FrgBase_Node*>> nodes;

	int maxLevels = -1;
	const auto levels = DetermineLevel(items, maxLevels);

	for (int level = 1; level <= maxLevels; level++)
	{
		std::vector<FrgBase_Node*> innerNodes;
		for (auto item : items)
		{
			innerNodes.push_back(new FrgBase_Node(level, item, std::get<1>(levels[level - 1])));
		}
		nodes.push_back(innerNodes);
	}

	return std::move(nodes);
}

std::vector<std::pair<int, ForgBaseLib::FrgBase_TreeItemToolsNamespace::FrgBase_Node*>> ForgBaseLib::FrgBase_TreeItemToolsNamespace::DetermineLevel
(
	const std::vector<FrgBase_TreeItem*>& items,
	int& maxLevel
)
{
	std::vector<std::pair<int, FrgBase_Node*>> levels;

	// TODO: compute levels and parentNodes

	return std::move(levels);
}