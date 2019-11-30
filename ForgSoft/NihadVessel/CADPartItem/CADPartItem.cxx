#include <CADPartItem.hxx>
#include <FrgBaseMenu.hxx>
#include <FrgBaseTree.hxx>

#include <Cad3d_TModel.hxx>

ForgBaseLib::CADPartItem::CADPartItem(const FrgString& title, FrgBaseTreeItem* parent, FrgSharedPtr<AutLib::Cad3d_TModel> model)
	: FrgBaseCADPart(title, parent)
	, theModel_(model) 
{
	DoAfterConstruct();
}

ForgBaseLib::CADPartItem::CADPartItem(const FrgString& title, FrgBaseTree* parentTree, FrgSharedPtr<AutLib::Cad3d_TModel> model)
	: FrgBaseCADPart(title, parentTree)
	, theModel_(model)
{
	DoAfterConstruct();
}

void ForgBaseLib::CADPartItem::DoAfterConstruct()
{
	std::vector<std::shared_ptr<AutLib::TModel_EntityManager>> surfaceVector;
	std::vector<std::shared_ptr<AutLib::TModel_EntityManager>> curveVector;
	surfaceVector.push_back(theModel_->Faces());
	curveVector.push_back(theModel_->Segments());
	GetSurfaces() = surfaceVector;
	GetCurves() = curveVector;

	FrgString ExportPartString = "&Export";
	this->GetContextMenu()->AddItem(ExportPartString);
	QObject::connect
	(
		this->GetContextMenu()->GetItem(ExportPartString.remove('&'))
		, SIGNAL(triggered(bool))
		, this->GetParentTree()
		, SLOT(ExportPartSlot(bool))
	);

	FrgBaseCADPart::DoAfterConstruct();

	//const auto& faces = theModel_->Faces();
	//faces->Print();
	//auto block = faces->SelectBlockEntity("Default Block Surface");
	//block->SelectEntity(1);
	//block->SelectEntity(2);
	//block->SelectEntity(3);
	//faces->Split("Block 01");
	//auto block2 = faces->SelectBlockEntity("Default Block Surface");
	//faces->RenameBlock("Block 02");
	////std::cout << "Block name = " << block->Name() << std::endl;
	//faces->Print();
	//block->Print();
	//block2->Print();
}