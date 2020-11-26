#pragma once
#ifndef _FrgVisual_ContoursLUTable_InverseRainbow_Header
#define _FrgVisual_ContoursLUTable_InverseRainbow_Header

#include <FrgVisual_Global.hxx>
#include <vtkLookupTable.h>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_ContoursLUTable_InverseRainbow
	: public vtkLookupTable

{

public:

	static FrgVisual_ContoursLUTable_InverseRainbow* New();

	vtkTypeMacro(FrgVisual_ContoursLUTable_InverseRainbow, vtkLookupTable);

protected:

	FrgVisual_ContoursLUTable_InverseRainbow();
};

EndForgVisualLib

#endif // !_FrgVisual_ContoursLUTable_InverseRainbow_Header
