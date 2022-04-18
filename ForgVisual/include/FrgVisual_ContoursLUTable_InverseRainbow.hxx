#pragma once
#ifndef _FrgVisual_ContoursLUTable_InverseRainbow_Header
#define _FrgVisual_ContoursLUTable_InverseRainbow_Header

#include <FrgViusal_LookUpTable.hxx>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_ContoursLUTable_InverseRainbow
	: public FrgViusal_LookUpTable

{

public:

	static FrgVisual_ContoursLUTable_InverseRainbow* New();

	vtkTypeMacro(FrgVisual_ContoursLUTable_InverseRainbow, FrgViusal_LookUpTable);

	bool IsInverseRainbow() const override { return true; }

protected:

	FrgVisual_ContoursLUTable_InverseRainbow();
};

EndForgVisualLib

#endif // !_FrgVisual_ContoursLUTable_InverseRainbow_Header
