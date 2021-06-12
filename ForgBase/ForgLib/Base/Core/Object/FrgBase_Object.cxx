#include <FrgBase_Object.hxx>
#include <FrgBase_SerialSpec_QString.hxx>

ForgBaseLib::FrgBase_Object::FrgBase_Object()
	: theIndex_(-1)
	, theName_("")
{

}

ForgBaseLib::FrgBase_Object::~FrgBase_Object()
{

}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_Object)
{
	ar& theName_;
	ar& theIndex_;
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_Object)
{
	ar& theName_;
	ar& theIndex_;
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_Object)