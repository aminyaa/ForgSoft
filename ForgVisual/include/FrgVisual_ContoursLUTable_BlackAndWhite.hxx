#pragma once
#ifndef _FrgVisual_ContoursLUTable_BlackAndWhite_Header
#define _FrgVisual_ContoursLUTable_BlackAndWhite_Header

#include <FrgViusal_LookUpTable.hxx>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_ContoursLUTable_BlackAndWhite
	: public FrgViusal_LookUpTable

{

public:

	static FrgVisual_ContoursLUTable_BlackAndWhite* New();

	vtkTypeMacro(FrgVisual_ContoursLUTable_BlackAndWhite, FrgViusal_LookUpTable);

	bool IsBlackAndWhite() const override { return true; }

protected:

	FrgVisual_ContoursLUTable_BlackAndWhite();
};

EndForgVisualLib

#endif // !_FrgVisual_ContoursLUTable_BlackAndWhite_Header
