#include <FrgVisual_TextActor.hxx>

#include <FrgBase_Pnt.hxx>
#include <FrgBase_SerialSpec_QString.hxx>
#include <FrgBase_SerialSpec_QColor.hxx>
#include <FrgBase_SerialSpec_Tuple.hxx>

#include <vtkRenderer.h>
#include <vtkBillboardTextActor3D.h>
#include <vtkTextProperty.h>

#include <vtkObjectFactory.h>

template<int Dim>
vtkStandardNewMacro(ForgVisualLib::FrgVisual_TextActor<Dim>);

template<int Dim>
ForgVisualLib::FrgVisual_TextActor<Dim>::FrgVisual_TextActor()
{
	theValue_ = "";
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetSize(int size)
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetFontSize(size);
}

template<int Dim>
int ForgVisualLib::FrgVisual_TextActor<Dim>::GetSize() const
{
	if (!theTextActor_)
		return 0;

	return theTextActor_->GetTextProperty()->GetFontSize();
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::RemoveActors(vtkRenderer* renderer)
{
	if (renderer)
		renderer->RemoveActor(theTextActor_);
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::TranslateActor(double dx, double dy)
{
	FrgVisual_BaseActor<Dim>::TranslateActor(dx, dy);
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::TranslateActor(double dx, double dy, double dz)
{
	FrgVisual_BaseActor<Dim>::TranslateActor(dx, dy, dz);
}

template<int Dim>
bool ForgVisualLib::FrgVisual_TextActor<Dim>::SelectActor(const QColor& color)
{
	if (!FrgVisual_BaseActor<Dim>::SelectActor(color))
		return false;

	return true;
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::UpdateActor()
{

}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetData
(
	const QString& value,
	const std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>& position
)
{
	thePosition_ = position;

	theValue_ = value;

	// Setup the text and add it to the renderer
	theTextActor_ = vtkSmartPointer<vtkBillboardTextActor3D>::New();
	theTextActor_->SetInput(value.toStdString().c_str());
	theTextActor_->GetTextProperty()->SetFontSize(12);
	theTextActor_->GetTextProperty()->SetColor(0.0, 0.0, 0.0);
	theTextActor_->GetTextProperty()->SetJustificationToLeft();

	if constexpr (Dim == 2)
		theTextActor_->SetPosition(position->X(), position->Y(), 0.0);
	else if constexpr (Dim == 3)
		theTextActor_->SetPosition(position->X(), position->Y(), position->Z());

	if (theRenderer_)
		theRenderer_->AddActor(theTextActor_);
}

template<>
template<>
void ForgVisualLib::FrgVisual_TextActor<2>::SetData(const QString& value, double x, double y)
{
	SetData(value, std::make_shared<ForgBaseLib::FrgBase_Pnt<2>>(x, y));
}

template<>
template<>
void ForgVisualLib::FrgVisual_TextActor<3>::SetData(const QString& value, double x, double y, double z)
{
	SetData(value, std::make_shared<ForgBaseLib::FrgBase_Pnt<3>>(x, y, z));
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetRenderer(vtkRenderer* renderer)
{
	theRenderer_ = renderer;

	if (theRenderer_)
		theRenderer_->AddActor(theTextActor_);
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetText(const QString& value)
{
	if (theTextActor_)
		theTextActor_->SetInput(value.toStdString().c_str());
}

template<int Dim>
std::tuple<int, int> ForgVisualLib::FrgVisual_TextActor<Dim>::GetDisplayOffset() const
{
	if (theTextActor_)
	{
		int offsetX;
		int offsetY;

		theTextActor_->GetDisplayOffset(offsetX, offsetY);

		return { offsetX , offsetY };
	}

	return { 0, 0 };
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetDisplayOffset(int offsetX, int offsetY)
{
	if (theTextActor_)
		theTextActor_->SetDisplayOffset(offsetX, offsetY);
}

template<int Dim>
QColor ForgVisualLib::FrgVisual_TextActor<Dim>::GetColor() const
{
	if (theTextActor_)
	{
		QColor c;
		double co[3];
		theTextActor_->GetTextProperty()->GetColor(co);

		c.setRedF(co[0]);
		c.setGreenF(co[1]);
		c.setBlueF(co[2]);

		return std::move(c);
	}

	return QColor();
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetColor(const QColor& color)
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::GetColor(double* color) const
{
	auto qColor = GetColor();

	color[0] = qColor.redF();
	color[1] = qColor.greenF();
	color[2] = qColor.blueF();
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetColor(double red, double green, double blue)
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetColor(red, green, blue);
}

template<int Dim>
bool ForgVisualLib::FrgVisual_TextActor<Dim>::IsBold() const
{
	if (theTextActor_)
		return theTextActor_->GetTextProperty()->GetBold();

	return false;
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetBold(bool condition)
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetBold(condition);
}

template<int Dim>
bool ForgVisualLib::FrgVisual_TextActor<Dim>::IsItalic() const
{
	if (theTextActor_)
		return theTextActor_->GetTextProperty()->GetItalic();

	return false;
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetItalic(bool condition)
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetItalic(condition);
}

template<int Dim>
double ForgVisualLib::FrgVisual_TextActor<Dim>::GetOrientation() const
{
	if (theTextActor_)
		return theTextActor_->GetTextProperty()->GetOrientation();

	return 0.0;
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetOrientation(double degree)
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetOrientation(degree);
}

template<int Dim>
bool ForgVisualLib::FrgVisual_TextActor<Dim>::IsJustificationToCentered() const
{
	if (theTextActor_)
		return (theTextActor_->GetTextProperty()->GetJustification() == VTK_TEXT_CENTERED);

	return false;
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetJustificationToCentered()
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetJustificationToCentered();
}

template<int Dim>
bool ForgVisualLib::FrgVisual_TextActor<Dim>::IsJustificationToLeft() const
{
	if (theTextActor_)
		return (theTextActor_->GetTextProperty()->GetJustification() == VTK_TEXT_LEFT);

	return false;
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetJustificationToLeft()
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetJustificationToLeft();
}

template<int Dim>
bool ForgVisualLib::FrgVisual_TextActor<Dim>::IsJustificationToRight() const
{
	if (theTextActor_)
		return (theTextActor_->GetTextProperty()->GetJustification() == VTK_TEXT_RIGHT);

	return false;
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetJustificationToRight()
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetJustificationToRight();
}

template<int Dim>
bool ForgVisualLib::FrgVisual_TextActor<Dim>::IsVerticalJustificationToBottom() const
{
	if (theTextActor_)
		return (theTextActor_->GetTextProperty()->GetVerticalJustification() == VTK_TEXT_BOTTOM);

	return false;
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetVerticalJustificationToBottom()
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetVerticalJustificationToBottom();
}

template<int Dim>
bool ForgVisualLib::FrgVisual_TextActor<Dim>::IsVerticalJustificationToCentered() const
{
	if (theTextActor_)
		return (theTextActor_->GetTextProperty()->GetVerticalJustification() == VTK_TEXT_CENTERED);

	return false;
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetVerticalJustificationToCentered()
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetVerticalJustificationToCentered();
}

template<int Dim>
bool ForgVisualLib::FrgVisual_TextActor<Dim>::IsVerticalJustificationToTop() const
{
	if (theTextActor_)
		return (theTextActor_->GetTextProperty()->GetVerticalJustification() == VTK_TEXT_TOP);

	return false;
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetVerticalJustificationToTop()
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetVerticalJustificationToTop();
}

template<int Dim>
ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType ForgVisualLib::FrgVisual_TextActor<Dim>::GetActorType() const
{
	return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Text;
}

template<int Dim>
std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType> ForgVisualLib::FrgVisual_TextActor<Dim>::GetActorTypes() const
{
	std::vector<ActorType> types;

	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Text);

	return types;
}

template<int Dim>
ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension ForgVisualLib::FrgVisual_TextActor<Dim>::GetActorDimension() const
{
	if constexpr (Dim == 2)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::TwoDim;
	if constexpr (Dim == 3)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::ThreeDim;
}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_TextActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);

	int size = GetSize();
	auto displayOffset = GetDisplayOffset();
	auto color = GetColor();
	bool isBold = IsBold();
	bool isItalic = IsItalic();
	double orientation = GetOrientation();
	bool isJustificationToCentered = IsJustificationToCentered();
	bool isJustificationToLeft = IsJustificationToLeft();
	bool isJustificationToRight = IsJustificationToRight();
	bool isVerticalJustificationToBottom = IsVerticalJustificationToBottom();
	bool isVerticalJustificationToCentered = IsVerticalJustificationToCentered();
	bool isVerticalJustificationToTop = IsVerticalJustificationToTop();

	ar& thePosition_;
	ar& theValue_;
	ar& size;
	ar& displayOffset;
	ar& color;
	ar& isBold;
	ar& isItalic;
	ar& orientation;
	ar& isJustificationToCentered;
	ar& isJustificationToLeft;
	ar& isJustificationToRight;
	ar& isVerticalJustificationToBottom;
	ar& isVerticalJustificationToCentered;
	ar& isVerticalJustificationToTop;
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_TextActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);

	int size;
	std::tuple<int, int> displayOffset;
	QColor color;
	bool isBold;
	bool isItalic;
	double orientation;
	bool isJustificationToCentered;
	bool isJustificationToLeft;
	bool isJustificationToRight;
	bool isVerticalJustificationToBottom;
	bool isVerticalJustificationToCentered;
	bool isVerticalJustificationToTop;

	ar& thePosition_;
	ar& theValue_;
	ar& size;
	ar& displayOffset;
	ar& color;
	ar& isBold;
	ar& isItalic;
	ar& orientation;
	ar& isJustificationToCentered;
	ar& isJustificationToLeft;
	ar& isJustificationToRight;
	ar& isVerticalJustificationToBottom;
	ar& isVerticalJustificationToCentered;
	ar& isVerticalJustificationToTop;

	SetData(theValue_, thePosition_);

	SetSize(size);
	SetDisplayOffset(std::get<0>(displayOffset), std::get<1>(displayOffset));
	SetColor(color);
	SetBold(isBold);
	SetItalic(isItalic);
	SetOrientation(orientation);

	if (isJustificationToCentered)
		SetJustificationToCentered();
	if (isJustificationToLeft)
		SetJustificationToLeft();
	if (isJustificationToRight)
		SetJustificationToRight();
	if (isVerticalJustificationToBottom)
		SetVerticalJustificationToBottom();
	if (isVerticalJustificationToCentered)
		SetVerticalJustificationToCentered();
	if (isVerticalJustificationToTop)
		SetVerticalJustificationToTop();
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_TextActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_TextActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_TextActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_TextActor<3>;