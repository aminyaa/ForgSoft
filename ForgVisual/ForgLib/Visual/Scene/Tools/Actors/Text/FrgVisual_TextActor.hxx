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
	virtual int GetSize();

	void RemoveActors(vtkRenderer* renderer) override;

	static FrgVisual_TextActor* New();
	vtkTypeMacro(FrgVisual_TextActor, FrgVisual_BaseActor<Dim>);

	void TranslateActor(double dx, double dy) override;
	void TranslateActor(double dx, double dy, double dz) override;

	bool SelectActor(const QColor& color) override;

	void UpdateActor();

	void SetData(const QString& value, std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> position);

	template <typename = std::enable_if_t<Dim == 2>>
	void SetData(const QString& value, double x, double y);
	template <typename = std::enable_if_t<Dim == 3>>
	void SetData(const QString& value, double x, double y, double z);

	/* Properties */

	void SetText(const QString& value);
	void SetDisplayOffset(int offsetX, int offsetY);

	void SetColor(double red, double green, double blue) override;
	void SetBold(bool condition);
	void SetItalic(bool condition);
	void SetOrientation(double degree);

	void SetJustificationToCentered();
	void SetJustificationToLeft();
	void SetJustificationToRight();
	void SetVerticalJustificationToBottom();
	void SetVerticalJustificationToCentered();
	void SetVerticalJustificationToTop();

	ActorType GetActorType() const override;
	std::vector<ActorType> GetActorTypes() const override;
	ActorDimension GetActorDimension() const override;

private:

	DECLARE_SAVE_LOAD_HEADER()

protected:

	QString theValue_;
	vtkSmartPointer<vtkBillboardTextActor3D> theTextActor_ = nullptr;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_TextActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_TextActor<3>)

#endif // !_FrgVisual_TextActor_Header
