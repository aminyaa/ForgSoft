#pragma once
#ifndef _FrgVisual_BaseActor_Entity_Header
#define _FrgVisual_BaseActor_Entity_Header

#include <FrgVisual_Global.hxx>
#include <vtkOpenGLActor.h>

#include <FrgVisual_Serialization_Global.hxx>

#include <QtGui/QColor>
#include <QtCore/QObject>

class vtkRenderer;

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_BaseActor_Entity
	: public QObject
	, public vtkOpenGLActor
{

	Q_OBJECT

public:

	typedef vtkOpenGLActor SuperClass;

public:

	FrgVisual_BaseActor_Entity();

	static FrgVisual_BaseActor_Entity* New();
	vtkTypeMacro(FrgVisual_BaseActor_Entity, vtkOpenGLActor);

	~FrgVisual_BaseActor_Entity();

	virtual bool IsSelectable() const { return theIsSelectable_; }
	virtual void SetSelectable(bool selectable = true);

	virtual bool IsSelected() const { return theIsSelected_; }

	virtual void SetColor(double red, double green, double blue);
	virtual void SetColor(double a[3]);

	virtual double* GetColor();
	virtual void GetColor(double rgb[3]);
	virtual void GetColor(double& r, double& g, double& b);

	virtual bool SelectActor(const QColor& color);
	virtual bool UnSelectActor();

	virtual bool HideActor();
	virtual bool UnHideActor();

	void SetVisibility(vtkTypeBool _arg) override;
	void VisibilityOn() override;
	void VisibilityOff() override;

	virtual void UpdateActor() {}

	vtkRenderer* GetRenderer() const { return theRenderer_; }
	virtual void SetRenderer(vtkRenderer* renderer) { theRenderer_ = renderer; }

	virtual void RemoveActors(vtkRenderer* renderer) {}

	const bool& IsIndependent() const { return theIsIndependent_; }
	void SetIndependent(bool condition) { theIsIndependent_ = condition; }

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)

Q_SIGNALS:

	void DataChangedSignal();
	void SelectionHasChangedSignal();

protected:

	vtkProperty* theCopyProperty_ = nullptr;
	mutable vtkProperty* theProperty_ = nullptr;

	vtkRenderer* theRenderer_ = nullptr;

	bool theIsSelectable_;
	bool theIsSelected_;

	bool theIsIndependent_;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_BaseActor_Entity)

#endif // !_FrgVisual_BaseActor_Entity_Header