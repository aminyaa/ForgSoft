#include <FrgBase_VectorField_Entity.hxx>
#include <FrgBase_FieldParser.hxx>

ForgBaseLib::FrgBase_VectorField_Entity::FrgBase_VectorField_Entity()
	: FrgBase_Field()
{

}

ForgBaseLib::FrgBase_VectorField_Entity::~FrgBase_VectorField_Entity()
{

}

std::string ForgBaseLib::FrgBase_VectorField_Entity::GetTypeAsString() const
{
	std::string middle =
		GetSize() > 1 ?
		std::to_string(GetSize()) :
		"Dynamic";

	return "Vector[" + middle + "]";
}

void ForgBaseLib::FrgBase_VectorField_Entity::CalcValue
(
	const std::shared_ptr<FrgBase_FieldParser::Calculated>& calculated
)
{
	if (theCalcValueFunction_)
	{
		auto value = theCalcValueFunction_();

		/*if (theValue_.size() != value.size())
			throw std::exception("Mismatch in size of function in " __FUNCSIG__);*/

		if (value.empty())
			theValue_ = { 0.0 };
		else
			theValue_ = value;

		return;
	}

	FrgBase_Field_Entity::CalcValue(calculated);

	theIsCalculating_ = true;

	auto pointer =
		std::dynamic_pointer_cast<FrgBase_VectorField_Entity>(this->shared_from_this());

	auto value =
		FrgBase_FieldParser::CalcValueVector
		(
			pointer,
			calculated
		);

	theValue_ = value;

	theIsCalculating_ = false;
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_VectorField_Entity)
{
	ar& boost::serialization::base_object<FrgBase_Field<std::vector<double>>>(*this);
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_VectorField_Entity)
{
	ar& boost::serialization::base_object<FrgBase_Field<std::vector<double>>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_VectorField_Entity)