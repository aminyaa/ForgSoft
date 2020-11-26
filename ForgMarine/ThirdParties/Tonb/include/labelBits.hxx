#pragma once
#ifndef _labelBits_Header
#define _labelBits_Header

#include <label.hxx>
#include <uLabel.hxx>
#include <direction.hxx>
#include <error.hxx>
#include <OSstream.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{


	/*---------------------------------------------------------------------------*\
							 Class labelBits Declaration
	\*---------------------------------------------------------------------------*/

	class labelBits
	{
		// Private data

		label data_;

		inline static label pack(const label val, const direction bits)
		{
#           ifdef FULLDEBUG
			if (bits > 7 || (((val << 3) >> 3) != val))
			{
				FatalErrorIn
				(
					"labelBits::pack(const label, const direction)"
				) << "Direction " << bits << " outside range 0..7"
					<< abort(FatalError);
			}
#           endif

			return (val << 3) | bits;
		}

	public:

		// Constructors

			//- Construct null
		inline labelBits()
		{}

		//- Construct from components
		inline labelBits(const label val, const direction bits)
			:
			data_(pack(val, bits))
		{}

		//- Construct from Istream
		inline labelBits(Istream& is)
		{
			is >> data_;
		}



		// Member Functions

		inline label val() const
		{
			return data_ >> 3;
		}

		inline direction bits() const
		{
			return data_ & 7;
		}

		inline void setVal(const label val)
		{
			data_ = pack(val, bits());
		}

		inline void setBits(const direction bits)
		{
			data_ = pack(val(), bits);
		}


		// Member Operators

		friend inline bool operator==(const labelBits& a, const labelBits& b)
		{
			return a.data_ == b.data_;
		}

		friend inline bool operator!=(const labelBits& a, const labelBits& b)
		{
			return !(a == b);
		}

		// IOstream Operators

		friend inline Istream& operator>>(Istream& is, labelBits& lb)
		{
			return is >> lb.data_;
		}

		friend inline Ostream& operator<<(Ostream& os, const labelBits& lb)
		{
			return os << lb.data_;
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_labelBits_Header
