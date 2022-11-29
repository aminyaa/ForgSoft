#include <FrgBase_VectorField_Entity.hxx>
#include <FrgBase_FieldParser.hxx>

ForgBaseLib::FrgBase_VectorField_Entity::FrgBase_VectorField_Entity()
	: FrgBase_Field()
{

}

ForgBaseLib::FrgBase_VectorField_Entity::~FrgBase_VectorField_Entity()
{

}

void ForgBaseLib::FrgBase_VectorField_Entity::CalcValue
(
	const std::shared_ptr<FrgBase_FieldParser::Calculated>& calculated
)
{
	FrgBase_Field_Entity::CalcValue(calculated);

	theIsCalculating_ = true;

	auto value =
		FrgBase_FieldParser::CalcValueVector
		(
			this,
			calculated
		);

	theValue_ = value;

	theIsCalculating_ = false;
}