#pragma once
#ifndef _FrgViusal_LookUpTable_Header
#define _FrgViusal_LookUpTable_Header

#include <FrgVisual_Global.hxx>
#include <vtkLookupTable.h>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgViusal_LookUpTable
	: public vtkLookupTable

{

public:

	static FrgViusal_LookUpTable* New();

	vtkTypeMacro(FrgViusal_LookUpTable, vtkLookupTable);

	virtual bool IsBlackAndWhite() const { return false; }
	virtual bool IsRainbow() const { return false; }
	virtual bool IsInverseRainbow() const { return false; }

	static unsigned char* MapScalarToColor(double value, FrgViusal_LookUpTable* lut);

	unsigned char* MapScalarToColor(double value);

protected:

	FrgViusal_LookUpTable();
};

EndForgVisualLib

#endif // !_FrgViusal_LookUpTable_Header
