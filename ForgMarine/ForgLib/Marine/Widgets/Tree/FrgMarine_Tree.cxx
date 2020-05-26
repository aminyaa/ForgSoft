#include <FrgMarine_Tree.hxx>
#include <FrgMarine_MainWindow.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgMarine_Geometry_TItem.hxx>
#include <FrgMarine_Analyses_TItem.hxx>
#include <FrgMarine_Plots_TItem.hxx>

#include <boost/serialization/void_cast_fwd.hpp>

//BOOST_CLASS_EXPORT_GUID(ForgMarineLib::FrgMarine_Tree, "ForgMarineLib::FrgMarine_Tree")
//BOOST_CLASS_IMPLEMENTATION(ForgMarineLib::FrgMarine_Tree, boost::serialization::primitive_type)
//BOOST_CLASS_EXPORT_IMPLEMENT(ForgMarineLib::FrgMarine_Tree)

ForgMarineLib::FrgMarine_Tree::FrgMarine_Tree(FrgMarine_MainWindow* parentMainWindow)
	: FrgBase_Tree(parentMainWindow)
{

}

void ForgMarineLib::FrgMarine_Tree::FormTree()
{
	theGeometry_ = new FrgMarine_Geometry_TItem("Geometry", nullptr, this);
	theAnalysis_ = new FrgMarine_Analyses_TItem("Analyses", nullptr, this);
	thePlots_ = new FrgMarine_Plots_TItem("Plots", nullptr, this);
}

ForgMarineLib::FrgMarine_Tree::~FrgMarine_Tree()
{
	FreePointer(theGeometry_);
	FreePointer(theAnalysis_);
	FreePointer(thePlots_);
}

DECLARE_SAVE_IMP(ForgMarineLib::FrgMarine_Tree)
{
	VOID_CAST_REGISTER(ForgMarineLib::FrgMarine_Tree, ForgBaseLib::FrgBase_Tree)

	ar & theGeometry_;
	ar & thePlots_;

	/*std::list<ForgBaseLib::FrgBase_TreeItem*> myItems;

	QTreeWidgetItemIterator it((QTreeWidget*)this);
	while (*it)
	{
		myItems.push_back(dynamic_cast<ForgBaseLib::FrgBase_TreeItem*>(*it));

		++it;
	}

	ar & myItems;*/
}

DECLARE_LOAD_IMP(ForgMarineLib::FrgMarine_Tree)
{
	VOID_CAST_REGISTER(ForgMarineLib::FrgMarine_Tree, ForgBaseLib::FrgBase_Tree)
	
	ar & theGeometry_;
	ar & thePlots_;
	/*std::list<ForgBaseLib::FrgBase_TreeItem*> myItems;

	ar & myItems;*/
}

BOOST_CLASS_EXPORT_CXX(ForgMarineLib::FrgMarine_Tree)