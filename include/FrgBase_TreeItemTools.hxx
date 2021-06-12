#pragma once
#ifndef _FrgBase_TreeItemTools_Header
#define _FrgBase_TreeItemTools_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Global_Icons.hxx>

#include <QtGui/QIcon>

BeginForgBaseLib

class FrgBase_TreeItem;

namespace FrgBase_TreeItemToolsNamespace
{

	struct FORGBASE_EXPORT FrgBase_Node
	{
		FrgBase_Node
		(
			int level,
			const QString& name,
			QIcon icon = QIcon(ICON_Menu_File_Load),
			FrgBase_Node* parentNode = nullptr
		);

		FrgBase_Node
		(
			int level,
			FrgBase_TreeItem* pointerToItem,
			FrgBase_Node* parentNode = nullptr
		);

		FrgBase_Node* theParentNode_ = nullptr;
		FrgBase_TreeItem* theItem_ = nullptr;
		FrgBase_TreeItem* thePointerToItem_ = nullptr;

		QString theName_;
		QIcon theIcon_;

		// The level must be >= 1
		int theLevel_;
	};

	std::vector<std::vector<FrgBase_Node*>> FORGBASE_EXPORT GetNodes
	(
		const std::vector<FrgBase_TreeItem*>& items,
		bool recursive = true
	);

	std::vector<std::pair<int, FrgBase_Node*>> DetermineLevel(const std::vector<FrgBase_TreeItem*>& items, int& maxLevel);

}

EndForgBaseLib

#endif // !_FrgBase_TreeItemTools_Header
