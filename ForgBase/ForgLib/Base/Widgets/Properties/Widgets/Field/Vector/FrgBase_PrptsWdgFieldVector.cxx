#include <FrgBase_PrptsWdgFieldVector.hxx>

#include <QtWidgets/QLineEdit>

ForgBaseLib::FrgBase_PrptsWdgFieldVector::FrgBase_PrptsWdgFieldVector
(
	QWidget* parent,
	FrgBase_PrptsVrnt* variant
)
	: ForgBaseLib::FrgBase_PrptsWdgField(parent, variant)
{

}

ForgBaseLib::FrgBase_PrptsWdgFieldVector::~FrgBase_PrptsWdgFieldVector()
{

}

void ForgBaseLib::FrgBase_PrptsWdgFieldVector::ValueChangedSlot(const std::vector<double>& values)
{
	QString output;
	for (std::size_t iter = 0; iter < values.size(); iter++)
	{
		if (iter == 0)
			output += ("[" + QString::number(values[iter]) + ", ");
		else if (iter == values.size() - 1)
			output += (QString::number(values[iter]) + "]");
		else
			output += (QString::number(values[iter]) + ", ");
	}

	theLineEdit_->setText(output);
}