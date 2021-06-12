#include <FrgVisual_PlaneActor.hxx>
#include <FrgBase_Pnt.hxx>

#include <vtkPlaneSource.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>

#include <vtkObjectFactory.h>

template<int Dim>
vtkStandardNewMacro(ForgVisualLib::FrgVisual_PlaneActor<Dim>);

template<int Dim>
ForgVisualLib::FrgVisual_PlaneActor<Dim>::FrgVisual_PlaneActor()
{

}

template<int Dim>
void ForgVisualLib::FrgVisual_PlaneActor<Dim>::SetData
(
	const ForgBaseLib::FrgBase_Pnt<Dim>& center,
	const ForgBaseLib::FrgBase_Pnt<Dim>& normal
)
{
	if (thePlaneSource_)
	{
		if constexpr (Dim == 2)
		{
			thePlaneSource_->SetCenter(center.X(), center.Y(), 0.0);
			thePlaneSource_->SetNormal(normal.X(), normal.Y(), 0.0);
		}
		else if constexpr (Dim == 3)
		{
			thePlaneSource_->SetCenter(center.X(), center.Y(), center.Z());
			thePlaneSource_->SetNormal(normal.X(), normal.Y(), normal.Z());
		}
		thePlaneSource_->Update();
		theMapper_->Update();

		return;
	}

	// Create a plane
	thePlaneSource_ = vtkSmartPointer<vtkPlaneSource>::New();

	if constexpr (Dim == 2)
	{
		thePlaneSource_->SetCenter(center.X(), center.Y(), 0.0);
		thePlaneSource_->SetNormal(normal.X(), normal.Y(), 0.0);
	}
	else if constexpr (Dim == 3)
	{
		thePlaneSource_->SetCenter(center.X(), center.Y(), center.Z());
		thePlaneSource_->SetNormal(normal.X(), normal.Y(), normal.Z());
	}

	thePlaneSource_ ->Update();

	vtkSmartPointer<vtkPolyData> plane = thePlaneSource_->GetOutput();

	// Create a mapper and actor
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputData(plane);

	SetMapper(mapper);
}

template<int Dim>
void ForgVisualLib::FrgVisual_PlaneActor<Dim>::SetData
(
	const ForgBaseLib::FrgBase_Pnt<Dim>& origin,
	const ForgBaseLib::FrgBase_Pnt<Dim>& P1,
	const ForgBaseLib::FrgBase_Pnt<Dim>& P2
)
{
	if (thePlaneSource_)
	{
		if constexpr (Dim == 2)
		{
			thePlaneSource_->SetOrigin(origin.X(), origin.Y(), 0.0);
			thePlaneSource_->SetPoint1(P1.X(), P1.Y(), 0.0);
			thePlaneSource_->SetPoint2(P2.X(), P2.Y(), 0.0);
		}
		else if constexpr (Dim == 3)
		{
			thePlaneSource_->SetOrigin(origin.X(), origin.Y(), origin.Z());
			thePlaneSource_->SetPoint1(P1.X(), P1.Y(), P1.Z());
			thePlaneSource_->SetPoint2(P2.X(), P2.Y(), P2.Z());
		}
		thePlaneSource_->Update();
		theMapper_->Update();

		return;
	}

	// Create a plane
	thePlaneSource_ = vtkSmartPointer<vtkPlaneSource>::New();

	if constexpr (Dim == 2)
	{
		thePlaneSource_->SetOrigin(origin.X(), origin.Y(), 0.0);
		thePlaneSource_->SetPoint1(P1.X(), P1.Y(), 0.0);
		thePlaneSource_->SetPoint2(P2.X(), P2.Y(), 0.0);
	}
	else if constexpr (Dim == 3)
	{
		thePlaneSource_->SetOrigin(origin.X(), origin.Y(), origin.Z());
		thePlaneSource_->SetPoint1(P1.X(), P1.Y(), P1.Z());
		thePlaneSource_->SetPoint2(P2.X(), P2.Y(), P2.Z());
	}

	thePlaneSource_->Update();

	vtkSmartPointer<vtkPolyData> plane = thePlaneSource_->GetOutput();

	// Create a mapper and actor
	theMapper_ = vtkSmartPointer<vtkPolyDataMapper>::New();
	theMapper_->SetInputData(plane);

	SetMapper(theMapper_);
}

template<int Dim>
const ForgBaseLib::FrgBase_Pnt<Dim>& ForgVisualLib::FrgVisual_PlaneActor<Dim>::GetOrigin() const
{
	ForgBaseLib::FrgBase_Pnt<Dim> pt;

	if (thePlaneSource_)
	{
		double o[3];
		thePlaneSource_->GetOrigin(o);

		if constexpr (Dim == 2)
		{
			pt.X() = o[0];
			pt.Y() = o[1];
		}
		else if constexpr (Dim == 3)
		{
			pt.X() = o[0];
			pt.Y() = o[1];
			pt.Z() = o[2];
		}
	}

	return std::move(pt);
}

template<int Dim>
const ForgBaseLib::FrgBase_Pnt<Dim>& ForgVisualLib::FrgVisual_PlaneActor<Dim>::GetCenter() const
{
	ForgBaseLib::FrgBase_Pnt<Dim> pt;

	if (thePlaneSource_)
	{
		double c[3];
		thePlaneSource_->GetCenter(c);

		if constexpr (Dim == 2)
		{
			pt.X() = c[0];
			pt.Y() = c[1];
		}
		else if constexpr (Dim == 3)
		{
			pt.X() = c[0];
			pt.Y() = c[1];
			pt.Z() = c[2];
		}
	}

	return std::move(pt);
}

template<int Dim>
const ForgBaseLib::FrgBase_Pnt<Dim>& ForgVisualLib::FrgVisual_PlaneActor<Dim>::GetNormal() const
{
	ForgBaseLib::FrgBase_Pnt<Dim> pt;

	if (thePlaneSource_)
	{
		double n[3];
		thePlaneSource_->GetNormal(n);

		if constexpr (Dim == 2)
		{
			pt.X() = n[0];
			pt.Y() = n[1];
		}
		else if constexpr (Dim == 3)
		{
			pt.X() = n[0];
			pt.Y() = n[1];
			pt.Z() = n[2];
		}
	}

	return std::move(pt);
}

template<int Dim>
const ForgBaseLib::FrgBase_Pnt<Dim>& ForgVisualLib::FrgVisual_PlaneActor<Dim>::GetPoint1() const
{
	ForgBaseLib::FrgBase_Pnt<Dim> pt;

	if (thePlaneSource_)
	{
		double p1[3];
		thePlaneSource_->GetOrigin(p1);

		if constexpr (Dim == 2)
		{
			pt.X() = p1[0];
			pt.Y() = p1[1];
		}
		else if constexpr (Dim == 3)
		{
			pt.X() = p1[0];
			pt.Y() = p1[1];
			pt.Z() = p1[2];
		}
	}

	return std::move(pt);
}

template<int Dim>
const ForgBaseLib::FrgBase_Pnt<Dim>& ForgVisualLib::FrgVisual_PlaneActor<Dim>::GetPoint2() const
{
	ForgBaseLib::FrgBase_Pnt<Dim> pt;

	if (thePlaneSource_)
	{
		double p2[3];
		thePlaneSource_->GetOrigin(p2);

		if constexpr (Dim == 2)
		{
			pt.X() = p2[0];
			pt.Y() = p2[1];
		}
		else if constexpr (Dim == 3)
		{
			pt.X() = p2[0];
			pt.Y() = p2[1];
			pt.Z() = p2[2];
		}
	}

	return std::move(pt);
}

template<int Dim>
void ForgVisualLib::FrgVisual_PlaneActor<Dim>::SetOrigin(const ForgBaseLib::FrgBase_Pnt<Dim>& origin)
{
	if (thePlaneSource_)
	{
		if constexpr (Dim == 2)
			thePlaneSource_->SetOrigin(origin.X(), origin.Y(), 0.0);
		else if constexpr (Dim == 3)
			thePlaneSource_->SetOrigin(origin.X(), origin.Y(), origin.Z());

		thePlaneSource_->Update();
		theMapper_->Update();
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_PlaneActor<Dim>::SetCenter(const ForgBaseLib::FrgBase_Pnt<Dim>& center)
{
	if (thePlaneSource_)
	{
		if constexpr (Dim == 2)
			thePlaneSource_->SetCenter(center.X(), center.Y(), 0.0);
		else if constexpr (Dim == 3)
			thePlaneSource_->SetCenter(center.X(), center.Y(), center.Z());

		thePlaneSource_->Update();
		theMapper_->Update();
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_PlaneActor<Dim>::SetNormal(const ForgBaseLib::FrgBase_Pnt<Dim>& normal)
{
	if (thePlaneSource_)
	{
		if constexpr (Dim == 2)
			thePlaneSource_->SetNormal(normal.X(), normal.Y(), 0.0);
		else if constexpr (Dim == 3)
			thePlaneSource_->SetNormal(normal.X(), normal.Y(), normal.Z());

		thePlaneSource_->Update();
		theMapper_->Update();
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_PlaneActor<Dim>::SetPoint1(const ForgBaseLib::FrgBase_Pnt<Dim>& p1)
{
	if (thePlaneSource_)
	{
		if constexpr (Dim == 2)
			thePlaneSource_->SetPoint1(p1.X(), p1.Y(), 0.0);
		else if constexpr (Dim == 3)
			thePlaneSource_->SetPoint1(p1.X(), p1.Y(), p1.Z());

		thePlaneSource_->Update();
		theMapper_->Update();
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_PlaneActor<Dim>::SetPoint2(const ForgBaseLib::FrgBase_Pnt<Dim>& p2)
{
	if (thePlaneSource_)
	{
		if constexpr (Dim == 2)
			thePlaneSource_->SetPoint1(p2.X(), p2.Y(), 0.0);
		else if constexpr (Dim == 3)
			thePlaneSource_->SetPoint1(p2.X(), p2.Y(), p2.Z());

		thePlaneSource_->Update();
		theMapper_->Update();
	}
}

template<int Dim>
ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType ForgVisualLib::FrgVisual_PlaneActor<Dim>::GetActorType() const
{
	return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Plane;
}

template<int Dim>
std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType> ForgVisualLib::FrgVisual_PlaneActor<Dim>::GetActorTypes() const
{
	std::vector<ActorType> types;

	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Plane);
	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Surface);

	return types;
}

template<int Dim>
ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension ForgVisualLib::FrgVisual_PlaneActor<Dim>::GetActorDimension() const
{
	if constexpr (Dim == 2)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::TwoDim;
	if constexpr (Dim == 3)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::ThreeDim;
}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_PlaneActor<Dim>)
{
	ar& boost::serialization::base_object<FrgVisual_SurfaceActor<Dim>>(*this);

	auto o = GetOrigin();
	auto p1 = GetPoint1();
	auto p2 = GetPoint2();

	ar& o;
	ar& p1;
	ar& p2;
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_PlaneActor<Dim>)
{
	ar& boost::serialization::base_object<FrgVisual_SurfaceActor<Dim>>(*this);

	ForgBaseLib::FrgBase_Pnt<Dim> o;
	ForgBaseLib::FrgBase_Pnt<Dim> p1;
	ForgBaseLib::FrgBase_Pnt<Dim> p2;

	ar& o;
	ar& p1;
	ar& p2;

	SetData(o, p1, p2);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_PlaneActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_PlaneActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_PlaneActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_PlaneActor<3>;