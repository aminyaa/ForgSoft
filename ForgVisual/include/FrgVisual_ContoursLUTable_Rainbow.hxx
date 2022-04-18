#pragma once
#ifndef _FrgVisual_ContoursLUTable_Rainbow_Header
#define _FrgVisual_ContoursLUTable_Rainbow_Header

#include <FrgViusal_LookUpTable.hxx>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_ContoursLUTable_Rainbow
	: public FrgViusal_LookUpTable

{

public:

	static FrgVisual_ContoursLUTable_Rainbow* New();

	vtkTypeMacro(FrgVisual_ContoursLUTable_Rainbow, FrgViusal_LookUpTable);

	bool IsRainbow() const override { return true; }

protected:

	FrgVisual_ContoursLUTable_Rainbow();
};

EndForgVisualLib

#endif // !_FrgVisual_ContoursLUTable_Rainbow_Header
