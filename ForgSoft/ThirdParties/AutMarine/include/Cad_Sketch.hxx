#pragma once
#ifndef _Cad_Sketch_Header
#define _Cad_Sketch_Header

#include <Standard_TypeDef.hxx>
#include <OFstream.hxx>

namespace AutLib
{

	class Cad_Sketch
	{

		/*Private Data*/

	protected:

		Cad_Sketch()
		{}


	public:

		virtual ~Cad_Sketch()
		{}


		//- virtual functions and operators

		virtual Standard_Boolean IsTwoDim() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsThreeDim() const
		{
			return Standard_False;
		}


		//- Io functions

		virtual void ExportToPlt(OFstream& File) const = 0;
	};
}

#endif // !_Cad_Sketch_Header
