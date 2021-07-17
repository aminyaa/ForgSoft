#pragma once
#ifndef _FrgVisual_BaseActor_Entity_Header
#define _FrgVisual_BaseActor_Entity_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_Object.hxx>
#include <vtkOpenGLActor.h>

#include <FrgVisual_Serialization_Global.hxx>

#include <QtGui/QColor>
#include <QtCore/QObject>

class vtkRenderer;

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_BaseActor_Entity
	: public QObject
	, public vtkOpenGLActor
	, public ForgBaseLib::FrgBase_Object
{

	Q_OBJECT

public:

	typedef vtkOpenGLActor SuperClass;

	enum class ActorType
	{
		Point,
		CtrlPoint,
		PickingPoint,
		Line,
		PolyLine,
		BSPLine,
		Curve,
		Solid,
		Conic,
		Circle,
		Rectangle,
		Box,
		Mesh,
		Grid,
		Text,
		Surface,
		Plane,
		Other
	};


	enum class ActorDimension
	{
		TwoDim,
		ThreeDim
	};

public:

	FrgVisual_BaseActor_Entity();

	//static FrgVisual_BaseActor_Entity* New();
	vtkTypeMacro(FrgVisual_BaseActor_Entity, vtkOpenGLActor);

	~FrgVisual_BaseActor_Entity();

	virtual bool IsSelectable() const { return theIsSelectable_; }
	virtual void SetSelectable(bool selectable = true);

	virtual bool IsSelected() const { return theIsSelected_; }

	virtual void SetColor(double red, double green, double blue);
	virtual void SetColor(double a[3]);
	virtual void SetColor(const QColor& color);

	virtual void SetSelectingColor(const QColor& color) { theSelectingColor_ = color; }
	virtual QColor GetSelectingColor() const { return theSelectingColor_; }

	virtual double* GetColor();
	virtual void GetColor(double rgb[3]);
	virtual void GetColor(double& r, double& g, double& b);

	virtual bool SelectActor(const QColor& color);
	virtual bool SelectActor();
	virtual bool UnSelectActor();

	virtual bool HideActor();
	virtual bool UnHideActor();

	void SetVisibility(vtkTypeBool _arg) override;
	void VisibilityOn() override;
	void VisibilityOff() override;

	virtual double GetOpacity();
	virtual void SetOpacity(double opacity);

	virtual void UpdateActor() {}

	vtkRenderer* GetRenderer() const { return theRenderer_; }
	virtual void SetRenderer(vtkRenderer* renderer) { theRenderer_ = renderer; }

	vtkProperty* GetCopyProperty() const { return theCopyProperty_; }

	virtual void RemoveActors(vtkRenderer* renderer) {}

	const bool& IsIndependent() const { return theIsIndependent_; }
	void SetIndependent(bool condition) { theIsIndependent_ = condition; }

	virtual ActorType GetActorType() const = 0;
	virtual std::vector<ActorType> GetActorTypes() const = 0;
	virtual ActorDimension GetActorDimension() const = 0;

	std::vector<QString> GetActorTypesAsString() const;
	QString GetActorTypeAsString(ActorType actorType) const;
	QString GetActorTypeAsString() const;

	bool IsPoint() const;
	bool IsCtrlPoint() const;
	bool IsPickingPoint() const;
	bool IsLine() const;
	bool IsPolyLine() const;
	bool IsBSPLine() const;
	bool IsCurve() const;
	bool IsSolid() const;
	bool IsConic() const;
	bool IsCircle() const;
	bool IsRectangle() const;
	bool IsBox() const;
	bool IsMesh() const;
	bool IsGrid() const;
	bool IsText() const;
	bool IsSurface() const;
	bool IsPlane() const;

	bool IsTwoDimension() const;
	bool IsThreeDimension() const;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)

Q_SIGNALS:

	void DataChangedSignal();
	void SelectionHasChangedSignal();

protected:

	mutable vtkProperty* theCopyProperty_ = nullptr;
	mutable vtkProperty* theProperty_ = nullptr;

	vtkRenderer* theRenderer_ = nullptr;

	bool theIsSelectable_;
	bool theIsSelected_;

	bool theIsIndependent_;

	QColor theSelectingColor_;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_BaseActor_Entity)

#endif // !_FrgVisual_BaseActor_Entity_Header
