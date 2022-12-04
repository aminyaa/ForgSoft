#include <FrgBase_ScalarField.hxx>

ForgBaseLib::FrgBase_ScalarField::FrgBase_ScalarField()
	: FrgBase_Field<double>()
{
	theValue_ = 0.0;
}

void ForgBaseLib::FrgBase_ScalarField::CalcValue
(
	const std::shared_ptr<FrgBase_FieldParser::Calculated>& calculated
)
{
	if (theCalcValueFunction_)
	{
		theValue_ = theCalcValueFunction_();

		return;
	}

	FrgBase_Field_Entity::CalcValue(calculated);

	theIsCalculating_ = true;

	auto pointer =
		std::dynamic_pointer_cast<FrgBase_ScalarField>(this->shared_from_this());

	auto value =
		FrgBase_FieldParser::CalcValueScalar
		(
			pointer,
			calculated
		);

	theValue_ = value;

	theIsCalculating_ = false;
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_ScalarField)
{
	ar& boost::serialization::base_object<FrgBase_Field<double>>(*this);
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_ScalarField)
{
	ar& boost::serialization::base_object<FrgBase_Field<double>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_ScalarField)