#pragma once
#ifndef _Marine_SingleTable_Header
#define _Marine_SingleTable_Header

#include <Marine_VesselTable.hxx>
#include <Marine_Table.hxx>

#include <memory>

namespace AutLib
{

	template<class TableType>
	class Marine_SingleTable
		: public Marine_VesselTable<TableType>
	{

		/*Private Data*/

		std::shared_ptr<TableType> theTable_;

	public:

		enum
		{
			nbTables = 1
		};

		Marine_SingleTable
		(
			const std::shared_ptr<TableType>& theTable
		)
			: theTable_(theTable)
		{}

		Marine_SingleTable
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<TableType>& theTable
		)
			: Marine_VesselTable<TableType>(theIndex, theName)
			, theTable_(theTable)
		{}

		/*const std::shared_ptr<TableType>& Table() const
		{
			return theTable_;
		}*/


		//- override functions and operators

		Standard_Boolean IsSingle() const override
		{
			return Standard_True;
		}

		Standard_Integer NbTables() const override
		{
			return (Standard_Integer)nbTables;
		}

		const std::shared_ptr<TableType>& Table(const Standard_Integer theIndex) const override;
	};


	namespace marineLib
	{
		typedef Marine_SingleTable<cmpTableCurve> singleBodyTable;
	}
}

#include <Marine_SingleTableI.hxx>

#endif // !_Marine_SingleTable_Header
