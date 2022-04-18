#include <FrgViusal_LookUpTable.hxx>

#include <vtkObjectFactory.h>

vtkStandardNewMacro(ForgVisualLib::FrgViusal_LookUpTable);

ForgVisualLib::FrgViusal_LookUpTable::FrgViusal_LookUpTable()
{
	
}

unsigned char* ForgVisualLib::FrgViusal_LookUpTable::MapScalarToColor(double value, FrgViusal_LookUpTable* lut)
{
	double dcolor[3];
	lut->GetColor(value, dcolor);

	unsigned char* color = new unsigned char[3];

	for (unsigned int j = 0; j < 3; j++)
		color[j] = static_cast<unsigned char>(255.0 * dcolor[j]);

	return color;
}

unsigned char* ForgVisualLib::FrgViusal_LookUpTable::MapScalarToColor(double value)
{
	return MapScalarToColor(value, this);
}
