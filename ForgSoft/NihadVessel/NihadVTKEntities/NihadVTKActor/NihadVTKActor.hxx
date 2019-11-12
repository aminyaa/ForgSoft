#pragma once
#ifndef _NihadVTKActor_Header
#define _NihadVTKActor_Header

#include <FrgBaseGlobals.hxx>

#include <vtkActor.h>

namespace AutLib
{
	class TModel_Entity;
}

BeginFrgBaseLib

class NihadVTKActor : public vtkActor
{

public:
	vtkTypeMacro(NihadVTKActor, vtkActor);

	static NihadVTKActor* New();

	FrgGetMacro(FrgSharedPtr<AutLib::TModel_Entity>, TModelEntity, theTModelEntity_);

protected:
	NihadVTKActor();
	//~NihadVTKActor() override;

private:

	FrgSharedPtr<AutLib::TModel_Entity> theTModelEntity_ = FrgNullPtr;

private:
	NihadVTKActor(const NihadVTKActor&) = delete;
	void operator=(const NihadVTKActor&) = delete;
};

EndFrgBaseLib

#endif // !_NihadVTKActor_Header
