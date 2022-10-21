#pragma once
#ifndef _FrgVisual_TextActor_Header
#define _FrgVisual_TextActor_Header

#include <FrgVisual_BaseActor.hxx>

class vtkBillboardTextActor3D;

namespace ForgBaseLib
{
	template<int Dim>
	class FrgBase_Pnt;
}

BeginForgVisualLib

template<int Dim>
class FORGVISUAL_EXPORT FrgVisual_TextActor
	: public FrgVisual_BaseActor<Dim>
{
	typedef FrgVisual_BaseActor<Dim> SuperClass;

public:

	FrgVisual_TextActor();

	virtual void SetSize(int size);
	virtual int GetSize() const;

	void RemoveActors(vtkRenderer* renderer) override;

	static FrgVisual_TextActor* New();
	vtkTypeMacro(FrgVisual_TextActor, FrgVisual_BaseActor<Dim>);

	void TranslateActor(double dx, double dy) override;
	void TranslateActor(double dx, double dy, double dz) override;

	bool SelectActor(const QColor& color) override;

	void UpdateActor();

	void SetData(const QString& value, const std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>& position);

	template <typename = std::enable_if_t<Dim == 2>>
	void SetData(const QString& value, double x, double y);
	template <typename = std::enable_if_t<Dim == 3>>
	void SetData(const QString& value, double x, double y, double z);

	void SetRenderer(vtkRenderer* renderer) override;

	/* Properties */

	const std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>& GetPosition() const { return thePosition_; }

	QString GetText() const { return theValue_; }
	void SetText(const QString& value);

	std::tuple<int, int> GetDisplayOffset() const;
	void SetDisplayOffset(int offsetX, int offsetY);

	QColor GetColor() const;
	void SetColor(const QColor& color);

	void GetColor(double* color) const;
	void SetColor(double red, double green, double blue) override;

	bool IsBold() const;
	void SetBold(bool condition);

	bool IsItalic() const;
	void SetItalic(bool condition);

	double GetOrientation() const;
	void SetOrientation(double degree);

	bool IsJustificationToCentered() const;
	void SetJustificationToCentered();

	bool IsJustificationToLeft() const;
	void SetJustificationToLeft();

	bool IsJustificationToRight() const;
	void SetJustificationToRight();

	bool IsVerticalJustificationToBottom() const;
	void SetVerticalJustificationToBottom();

	bool IsVerticalJustificationToCentered() const;
	void SetVerticalJustificationToCentered();

	bool IsVerticalJustificationToTop() const;
	void SetVerticalJustificationToTop();

	ActorType GetActorType() const override;
	std::vector<ActorType> GetActorTypes() const override;
	ActorDimension GetActorDimension() const override;

private:

	DECLARE_SAVE_LOAD_HEADER()

protected:

	QString theValue_;
	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> thePosition_;

	mutable vtkSmartPointer<vtkBillboardTextActor3D> theTextActor_ = nullptr;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_TextActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_TextActor<3>)

#endif // !_FrgVisual_TextActor_Header
