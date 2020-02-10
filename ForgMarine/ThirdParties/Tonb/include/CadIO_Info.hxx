#pragma once
#ifndef _CadIO_Info_Header
#define _CadIO_Info_Header

#include <Standard_TypeDef.hxx>
#include <fileName.hxx>

namespace tnbLib
{

	class CadIO_Info
	{

		/*Private Data*/

		Standard_Integer theNbFaces_;

		fileName theFileName_;

	protected:

		CadIO_Info()
			: theNbFaces_(0)
		{}

		void SetNbFaces(const Standard_Integer theValue)
		{
			theNbFaces_ = theValue;
		}

		void SetFileName(const fileName& theName)
		{
			theFileName_ = theName;
		}

	public:

		auto NbFaces() const
		{
			return theNbFaces_;
		}

		const auto& FileName() const
		{
			return theFileName_;
		}
	};
}

#endif // !_CadIO_Info_Header
