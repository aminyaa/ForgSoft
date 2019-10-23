#pragma once
namespace AutLib
{

	template<class TableType>
	const std::shared_ptr<TableType>& Marine_SingleTable<TableType>::Table
	(
		const Standard_Integer theIndex
	) const
	{
		if (NOT INSIDE(theIndex, 0, NbTables() - 1))
		{
			FatalErrorIn("std::shared_ptr<TableType> Table(const Standard_Integer theIndex) const")
				<< "the Index exceed the size of the list" << endl
				<< abort(FatalError);
		}

		return theTable_;
	}
}