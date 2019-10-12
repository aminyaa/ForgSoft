#pragma once
#ifndef _TimeState_Header
#define _TimeState_Header

#include <dimensionedScalar.hxx>

namespace AutLib
{

	class TimeState
		: public dimensionedScalar
	{

	protected:

		label timeIndex_;
		scalar deltaT_;
		scalar deltaTSave_;
		scalar deltaT0_;
		bool deltaTchanged_;

		label outputTimeIndex_;
		bool  outputTime_;

	public:

		// Constructors

		TimeState();


		// Destructor

		//- Virtual destructor
		virtual ~TimeState();


		// Member functions

		// Access

		//- Convert the user-time (e.g. CA deg) to real-time (s).
		virtual scalar userTimeToTime(const scalar theta) const;

		//- Convert the real-time (s) into user-time (e.g. CA deg)
		virtual scalar timeToUserTime(const scalar t) const;

		//- Return current time value
		virtual scalar timeOutputValue() const;

		//- Return current time index
		virtual label timeIndex() const;

		//- Return time step value
		scalar deltaTValue() const
		{
			return deltaT_;
		}

		//- Return old time step value
		scalar deltaT0Value() const
		{
			return deltaT0_;
		}

		//- Return time step
		virtual dimensionedScalar deltaT() const;

		//- Return old time step
		virtual dimensionedScalar deltaT0() const;


		// Check

		//- Return true if this is an output time
		virtual bool outputTime() const;
	};
}

#endif // !_TimeState_Header
