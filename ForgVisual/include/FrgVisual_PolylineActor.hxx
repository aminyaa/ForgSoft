#pragma once
#ifndef _FrgVisual_PolylineActor_Header
#define _FrgVisual_PolylineActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_CurveActor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

#include <vtkSmartPointer.h>

class vtkPolyDataMapper;
class vtkPolyData;

namespace ForgBaseLib
{
	template<int Dim>
	class FrgBase_Pnt;
}

namespace opencascade
{
	template <class T>
	class handle;
}

BeginForgVisualLib

template<int Dim>
class FrgVisual_PointActor;

template<int Dim>
class FrgVisual_BSPLineActor;

template<int Dim>
class FORGVISUAL_EXPORT FrgVisual_PolylineActor
	: public FrgVisual_CurveActor<Dim>
{
	typedef FrgVisual_CurveActor<Dim> SuperClass;

public:

	FrgVisual_PolylineActor();

	static FrgVisual_PolylineActor* New();
	vtkTypeMacro(FrgVisual_PolylineActor, FrgVisual_CurveActor<Dim>);

	//void SetData(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> pts);
	void SetData(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> pts);
	virtual void AddNextPoint(ForgBaseLib::FrgBase_Pnt<Dim> pt);
	virtual void SetLastPoint(ForgBaseLib::FrgBase_Pnt<Dim> pt);

	template <typename = typename std::enable_if_t<Dim == 2>>
	void AddNextPoint(double x, double y);
	template <typename = typename std::enable_if_t<Dim == 2>>
	void SetLastPoint(double x, double y);

	template <typename = typename std::enable_if_t<Dim == 3>>
	void AddNextPoint(double x, double y, double z);
	template <typename = typename std::enable_if_t<Dim == 3>>
	void SetLastPoint(double x, double y, double z);

	virtual void RemoveLastPoint();

	long long GetNumberOfPoints();
	std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> GetPoints() const;

	ForgBaseLib::FrgBase_Pnt<Dim> GetPoint(long long i);
	void SetPoint(long long i, ForgBaseLib::FrgBase_Pnt<Dim> pt);

	template <typename = typename std::enable_if_t<Dim == 2>>
	void SetPoint(long long i, double x, double y);
	template <typename = typename std::enable_if_t<Dim == 3>>
	void SetPoint(long long i, double x, double y, double z);

	bool SelectActor(const QColor& color) override;
	bool UnSelectActor() override;

	virtual void ShowPoints(bool condition = true);

	//void SetData(std::vector<FrgVisual_PointActor<Dim>*> ptsActors);

	//std::vector<FrgVisual_PointActor<Dim>*> GetPts() const { return thePts_; }

	//void TranslateActor(double dx, double dy) override;
	//void TranslateActor(double dx, double dy, double dz) override;

	void UpdateActor() override;

	void SetRenderer(vtkRenderer* renderer) override;

	//FrgVisual_BSPLineActor<Dim>* GetParentBSPLineActor() const { return theParentBSPLineActor_; }
	//void SetParentBSPLineActor(FrgVisual_BSPLineActor<Dim>* parentBSPLineActor);

	//void SetSelectable(bool selectable = true) override;

	void RemoveActors(vtkRenderer* renderer) override;

	ActorType GetActorType() const override;
	std::vector<ActorType> GetActorTypes() const override;
	ActorDimension GetActorDimension() const override;

	std::vector<opencascade::handle<Standard_Transient>> GetCurves();

	//void UpdateActor() override;

	//const auto& GetCurve() const { return theCurve_; }

private:

	DECLARE_SAVE_LOAD_HEADER( )

protected:

	void AddNextIdIntoCell(vtkPolyData* polyData);
	void UpdateIdListUsingPoints(vtkPolyData* polyData);

protected:

	std::vector<FrgVisual_PointActor<Dim>*> thePts_;

	mutable vtkSmartPointer<vtkPolyDataMapper> theMapper_ = nullptr;
	//opencascade::handle<Standard_Transient> theCurve_ = nullptr;

	//FrgVisual_BSPLineActor<Dim>* theParentBSPLineActor_ = nullptr;

};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_PolylineActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_PolylineActor<3>)

#include <FrgVisual_PolylineActorI.hxx>

#endif // !_FrgVisual_PolylineActor_Header
