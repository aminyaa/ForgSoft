#pragma once
#ifndef _FrgBase_TreeItemI_Header
#define _FrgBase_TreeItemI_Header

//#include <QTreeWidgetItemIterator>

template<class T>
inline std::vector<T*> ForgBaseLib::FrgBase_TreeItem::GetChildrenByType() const
{
	std::vector<T*> listOfItems;
	int nbIems = this->childCount();

	for (int iItem = 0; iItem < nbIems; iItem++)
	{
		auto castedTItem = dynamic_cast<T*>(this->child(iItem));
		if(castedTItem)
			listOfItems.push_back(castedTItem);
	}

	return listOfItems;
}

template <class T>
inline std::vector<T*> ForgBaseLib::FrgBase_TreeItem::GetAllChildrenToTheRootByType() const
{
	std::vector<T*> results;
	int i = 0;
	QTreeWidgetItemIterator it((QTreeWidgetItem*)(this));
	while (*it)
	{
		bool founded = false;
		QTreeWidgetItem* itParent = (*it)->parent();
		while (itParent)
		{
			if (itParent == this)
			{
				founded = true;
				break;
			}

			itParent = itParent->parent();
		}

		if (!founded && i == 0)
		{
			++it;
			continue;
		}

		if (!founded)
			break;

		auto myTItem = dynamic_cast<T*>(*it);
		if (myTItem)
			results.push_back(myTItem);

		++it;
		i++;
	}

	return results;
}

#endif // !_FrgBase_TreeItemI_Header
