#pragma once
#ifndef _Marine_Section_Header
#define _Marine_Section_Header

#include <Marine_Entity.hxx>
#include <Entity2d_BoxFwd.hxx>
#include <OFstream.hxx>

class gp_Trsf2d;

#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class Pln_Wire;

	class Marine_Section
		: public Marine_Entity
	{

		/*Private Data*/

		std::shared_ptr<Pln_Wire> theWire_;


		static void CheckWire(const Pln_Wire& theWire, const char* theName);

	public:

		Marine_Section
		(
			const std::shared_ptr<Pln_Wire>& theWire
		);

		Marine_Section
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<Pln_Wire>& theWire
		);

		Marine_Section
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<Pln_Wire>& theWire
		);

		const Entity2d_Box& BoundingBox() const;

		const auto& Wire() const
		{
			return theWire_;
		}

		void Transform(const gp_Trsf2d& t);

		void ExportToPlt(OFstream& File) const;

		virtual Standard_Boolean IsDry() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsWet() const
		{
			return Standard_False;
		}

		virtual std::shared_ptr<Marine_Section> Copy() const;

		//- static functions

		static Standard_Real 
			GetXcoord
			(
				const std::shared_ptr<Marine_Section>& theSection
			);
	};
}

#endif // !_Marine_Section_Header
