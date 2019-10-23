#pragma once
#ifndef _Marine_CompoundTable_Header
#define _Marine_CompoundTable_Header

#include <Marine_VesselTable.hxx>
#include <Marine_Table.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	template<class TableType>
	class Marine_CompoundTable
		: public Marine_VesselTable<TableType>
	{

		typedef std::vector<std::shared_ptr<TableType>> tableList;

		/*Private Data*/

		tableList theTables_;

	public:

		Marine_CompoundTable()
		{}

		Marine_CompoundTable
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: Marine_VesselTable<TableType>(theIndex, theName)
		{}


		void Insert(const std::shared_ptr<TableType>& theTable)
		{
			theTables_.push_back(theTable);
		}

		// override functions and operators

		Standard_Boolean IsCompound() const override
		{
			return Standard_True;
		}

		Standard_Integer NbTables() const override
		{
			return (Standard_Integer)theTables_.size();
		}

		const std::shared_ptr<TableType>& Table(const Standard_Integer theIndex) const override;
	};


	namespace marineLib
	{
		typedef Marine_CompoundTable<cmpTableCurve> multiBodyTable;
	}
}

#include <Marine_CompoundTableI.hxx>

#endif // !_Marine_CompoundTable_Header
