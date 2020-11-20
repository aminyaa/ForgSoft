#include <FrgVisual_TextActor.hxx>

#include <FrgBase_Pnt.hxx>
#include <FrgBase_SerialSpec_QString.hxx>

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
	if(theTextActor_)
		theTextActor_->GetTextProperty()->SetFontSize(size);
}

template<int Dim>
int ForgVisualLib::FrgVisual_TextActor<Dim>::GetSize()
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
	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> position
)
{
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
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetText(const QString& value)
{
	if (theTextActor_)
		theTextActor_->SetInput(value.toStdString().c_str());
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetDisplayOffset(int offsetX, int offsetY)
{
	if (theTextActor_)
		theTextActor_->SetDisplayOffset(offsetX, offsetY);
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetColor(double red, double green, double blue)
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetColor(red, green, blue);
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetBold(bool condition)
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetBold(condition);
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetItalic(bool condition)
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetItalic(condition);
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetOrientation(double degree)
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetOrientation(degree);
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetJustificationToCentered()
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetJustificationToCentered();
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetJustificationToLeft()
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetJustificationToLeft();
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetJustificationToRight()
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetJustificationToRight();
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetVerticalJustificationToBottom()
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetVerticalJustificationToBottom();
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetVerticalJustificationToCentered()
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetVerticalJustificationToCentered();
}

template<int Dim>
void ForgVisualLib::FrgVisual_TextActor<Dim>::SetVerticalJustificationToTop()
{
	if (theTextActor_)
		theTextActor_->GetTextProperty()->SetVerticalJustificationToTop();
}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_TextActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);

	double data[3];
	theTextActor_->GetPosition(data);

	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> pt;

	if constexpr (Dim == 2)
		std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(data[0], data[1]);
	else if constexpr (Dim == 3)
		std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(data[0], data[1], data[2]);

	ar& pt;
	ar& theValue_;
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_TextActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);

	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> pt;

	ar& pt;
	ar& theValue_;

	SetData(theValue_, pt);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_TextActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_TextActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_TextActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_TextActor<3>;