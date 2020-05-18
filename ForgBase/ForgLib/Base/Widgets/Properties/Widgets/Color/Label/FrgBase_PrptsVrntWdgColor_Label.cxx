#include <FrgBase_PrptsVrntWdgColor_Label.hxx>
#include <FrgBase_PrptsWdgColor.hxx>

ForgBaseLib::FrgBase_PrptsVrntWdgColor_Label::FrgBase_PrptsVrntWdgColor_Label
(
	const QString& title,
	FrgBase_PrptsWdgColor* parent
)
	: QLabel(title, parent)
{

}

void ForgBaseLib::FrgBase_PrptsVrntWdgColor_Label::mousePressEvent(QMouseEvent * ev)
{
	dynamic_cast<FrgBase_PrptsWdgColor*>(parentWidget())->OnColorButtonClickedSlot();
}