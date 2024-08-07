#pragma once
#ifndef _FrgVisual_Scene_InterStyle_Header
#define _FrgVisual_Scene_InterStyle_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_Object.hxx>

#include <QtCore/QObject>

#include <vtkSetGet.h>

//#define EliminateUnSelectedActors

// Motion flags

#define VTKIS_Translation             18

BeginForgVisualLib

template<int Dim>
class FrgVisual_Scene;

class FrgVisual_Scene_InterStyle_Base
	: public QObject
	, public ForgBaseLib::FrgBase_Object
{
	Q_OBJECT

public:

	enum class PickingToleranceHelper
	{
		Surface,
		Curve
	};

	FrgVisual_Scene_InterStyle_Base() {}

	// Default is set to picking surface (0.00001)
	double GetPickingTolerance() const { return thePickingTolerance_; }
	void SetPickingTolerance(const double tol) { thePickingTolerance_ = tol; }

	void FORGVISUAL_EXPORT SetPickingToleranceToSurface();
	void FORGVISUAL_EXPORT SetPickingToleranceToCurve();

	static double FORGVISUAL_EXPORT RecommendPickingTolerance(PickingToleranceHelper helper);

public slots:

	virtual void HideActionIsCalledSlot() {}
	virtual void UnHideActionIsCalledSlot() {}

public:

	virtual void FormInterStyle() {}

protected:

	double thePickingTolerance_ = 0.00001;
};

template <int Dim, class T>
class FrgVisual_Scene_InterStyle
	: public FrgVisual_Scene_InterStyle_Base
	, public T
{

public:

	

	static ForgVisualLib::FrgVisual_Scene_InterStyle<Dim, T>* New();

	virtual void StartTranslation();
	virtual void EndTranslation();

	FrgVisual_Scene<Dim>* GetParentScene() const { return theParentScene_; }
	void SetParentScene(FrgVisual_Scene<Dim>* scene) { theParentScene_ = scene; }

protected:

	FrgVisual_Scene_InterStyle();

	FrgVisual_Scene<Dim>* theParentScene_ = nullptr;

protected:
	const char* GetClassNameInternal() const override
	{
		return "FrgVisual_Scene_InterStyle<Dim, T>";
	}
public:
	typedef T Superclass;
	static vtkTypeBool IsTypeOf(const char* type)
	{
		if (!strcmp("FrgVisual_Scene_InterStyle<Dim, T>", type))
		{
			return 1;
		}
		return T::IsTypeOf(type);
	}
	vtkTypeBool IsA(const char* type) override
	{
		return this->FrgVisual_Scene_InterStyle<Dim, T>::IsTypeOf(type);
	}
	static FrgVisual_Scene_InterStyle<Dim, T>* SafeDownCast(vtkObjectBase* o)
	{
		if (o && o->IsA("FrgVisual_Scene_InterStyle<Dim, T>"))
		{
			return static_cast<FrgVisual_Scene_InterStyle<Dim, T>*>(o);
		}
		return nullptr;
	}
	VTK_NEWINSTANCE FrgVisual_Scene_InterStyle<Dim, T>* NewInstance() const
	{
		return FrgVisual_Scene_InterStyle<Dim, T>::SafeDownCast(this->NewInstanceInternal());
	}

protected:
	vtkObjectBase* NewInstanceInternal() const override
	{
		return FrgVisual_Scene_InterStyle<Dim, T>::New();
	}
};

EndForgVisualLib

#include <FrgVisual_Scene_InterStyleI.hxx>

#endif // !_FrgVisual_Scene_InterStyle_Header
