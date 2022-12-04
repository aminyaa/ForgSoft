#include <FrgBase_VectorField.hxx>

ForgBaseLib::FrgBase_VectorField::FrgBase_VectorField::FrgBase_VectorField
(
	const int size
)
{
	if (theValue_.empty())
	{
		theValue_.reserve(size);

		for (int i = 0; i < size; i++)
			theValue_.push_back(0.0);
	}
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_VectorField)
{
	ar& boost::serialization::base_object<FrgBase_VectorField_Entity>(*this);
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_VectorField)
{
	ar& boost::serialization::base_object<FrgBase_VectorField_Entity>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_VectorField)