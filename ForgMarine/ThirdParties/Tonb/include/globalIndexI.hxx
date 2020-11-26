#pragma once
#include <ListOps.hxx>

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

//inline const tnbLib::labelList& tnbLib::globalIndex::offsets() const
//{
//    return offsets_;
//}


inline tnbLib::label tnbLib::globalIndex::offset(const label procI) const
{
	return (procI == 0 ? 0 : offsets_[procI - 1]);
}


inline tnbLib::label tnbLib::globalIndex::localSize(const label procI) const
{
	return
		(
			procI == 0
			? offsets_[procI]
			: offsets_[procI] - offsets_[procI - 1]
			);
}


inline tnbLib::label tnbLib::globalIndex::localSize() const
{
	return localSize(Pstream::myProcNo());
}


inline tnbLib::label tnbLib::globalIndex::size() const
{
	return offsets_[Pstream::nProcs() - 1];
}


inline tnbLib::label tnbLib::globalIndex::toGlobal
(
	const label procI,
	const label i
) const
{
	return(procI == 0 ? i : i + offsets_[procI - 1]);
}


inline tnbLib::label tnbLib::globalIndex::toGlobal(const label i) const
{
	return toGlobal(Pstream::myProcNo(), i);
}


//- Is on local processor
inline bool tnbLib::globalIndex::isLocal(const label procI, const label i) const
{
	return
		(i < offsets_[procI])
		&& (i >= (procI == 0 ? 0 : offsets_[procI - 1]));
}


inline bool tnbLib::globalIndex::isLocal(const label i) const
{
	return isLocal(Pstream::myProcNo(), i);
}


inline tnbLib::label tnbLib::globalIndex::toLocal(const label procI, const label i)
const
{
	label localI = (procI == 0 ? i : i - offsets_[procI - 1]);

	if (localI < 0 || i >= offsets_[procI])
	{
		FatalErrorIn("globalIndex::toLocal(const label, const label)")
			<< "Global " << i << " does not belong on processor "
			<< procI << endl << "Offsets:" << offsets_
			<< abort(FatalError);
	}
	return localI;
}


inline tnbLib::label tnbLib::globalIndex::toLocal(const label i) const
{
	return toLocal(Pstream::myProcNo(), i);
}


inline tnbLib::label tnbLib::globalIndex::whichProcID(const label i) const
{
	label index = findLower(offsets_, i + 1);

	if (index == Pstream::nProcs() - 1)
	{
		FatalErrorIn("globalIndex::whichProcID(const label)")
			<< "Global " << i << " does not belong on any processor."
			<< " Offsets:" << offsets_
			<< abort(FatalError);
	}

	return index + 1;
}


// ************************************************************************* //