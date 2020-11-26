#pragma once
#ifndef _FrgVisual_ContoursLUTable_Rainbow_Header
#define _FrgVisual_ContoursLUTable_Rainbow_Header

#include <FrgVisual_Global.hxx>
#include <vtkLookupTable.h>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_ContoursLUTable_Rainbow
	: public vtkLookupTable

{

public:

	static FrgVisual_ContoursLUTable_Rainbow* New();

	vtkTypeMacro(FrgVisual_ContoursLUTable_Rainbow, vtkLookupTable);

protected:

	FrgVisual_ContoursLUTable_Rainbow();
};

EndForgVisualLib

#endif // !_FrgVisual_ContoursLUTable_Rainbow_Header
