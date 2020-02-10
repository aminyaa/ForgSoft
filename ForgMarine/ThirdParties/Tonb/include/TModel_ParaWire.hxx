#pragma once
#ifndef _TModel_ParaWire_Header
#define _TModel_ParaWire_Header

#include <TModel_Entity.hxx>
#include <Entity2d_BoxFwd.hxx>

namespace tnbLib
{

	// Forward Declarations
	class TModel_CmpParaCurve;

	class TModel_ParaWire
		: public TModel_Entity
	{

		/*Private Data*/

		std::shared_ptr<TModel_CmpParaCurve> theCurve_;

	public:

		TModel_ParaWire
		(
			const std::shared_ptr<TModel_CmpParaCurve>& theCurve
		);

		TModel_ParaWire
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<TModel_CmpParaCurve>& theCurve
		);

		TModel_ParaWire
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<TModel_CmpParaCurve>& theCurve
		);
	};
}

#endif // !_TModel_ParaWire_Header
