#pragma once
#ifndef _FrgVisual_ContoursLUTable_BlackAndWhite_Header
#define _FrgVisual_ContoursLUTable_BlackAndWhite_Header

#include <FrgVisual_Global.hxx>
#include <vtkLookupTable.h>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_ContoursLUTable_BlackAndWhite
	: public vtkLookupTable

{

public:

	static FrgVisual_ContoursLUTable_BlackAndWhite* New();

	vtkTypeMacro(FrgVisual_ContoursLUTable_BlackAndWhite, vtkLookupTable);

protected:

	FrgVisual_ContoursLUTable_BlackAndWhite();
};

EndForgVisualLib

#endif // !_FrgVisual_ContoursLUTable_BlackAndWhite_Header
