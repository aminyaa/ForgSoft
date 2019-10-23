#pragma once
#ifndef _Marine_VesselTable_Header
#define _Marine_VesselTable_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>

#include <memory>

namespace AutLib
{

	template<class TableType>
	class Marine_VesselTable
		: public Global_Indexed
		, public Global_Named
	{

		/*Private Data*/

	protected:

		Marine_VesselTable()
		{}

		Marine_VesselTable
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
		{}

	public:

		virtual ~Marine_VesselTable()
		{}


		virtual Standard_Boolean IsSingle() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsCompound() const
		{
			return Standard_False;
		}

		virtual Standard_Integer NbTables() const = 0;

		virtual const std::shared_ptr<TableType>& Table(const Standard_Integer theIndex) const = 0;
	};
}

#endif // !_Marine_VesselTable_Header
