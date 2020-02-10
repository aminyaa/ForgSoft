#pragma once
#ifndef _Marine_Section_Header
#define _Marine_Section_Header

#include <Marine_Entity.hxx>

#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class Pln_Wire;

	class Marine_Section
		: public Marine_Entity
	{

		typedef std::shared_ptr<Pln_Wire> outer;
		typedef std::shared_ptr<std::vector<std::shared_ptr<Pln_Wire>>> inner;

		/*Private Data*/

		outer theOuter_;
		inner theInner_;

	public:

		Marine_Section
		(
			const outer& theOuter,
			const inner& theInner = nullptr
		);

		Marine_Section
		(
			const Standard_Integer theIndex,
			const outer& theOuter,
			const inner& theInner = nullptr
		);

		Marine_Section
		(
			const Standard_Integer theIndex,
			const word& theName,
			const outer& theOuter,
			const inner& theInner = nullptr
		);


		Standard_Boolean HasHole() const;

		Standard_Integer NbHoles() const;

		const outer& Outer() const
		{
			return theOuter_;
		}

		const inner& Inner() const
		{
			return theInner_;
		}

	};
}

#endif // !_Marine_Section_Header
