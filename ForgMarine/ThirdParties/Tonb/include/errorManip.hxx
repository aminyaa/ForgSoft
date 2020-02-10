#pragma once
namespace tnbLib
{

	// Forward declaration of friend functions and operators

	template<class Err> class errorManip;
	template<class Err> Ostream& operator<<(Ostream&, errorManip<Err>);

	template<class Err, class T> class errorManipArg;
	template<class Err, class T>
	Ostream& operator<<(Ostream&, errorManipArg<Err, T>);


	/*---------------------------------------------------------------------------*\
							   Class errorManip Declaration
	\*---------------------------------------------------------------------------*/

	template<class Err>
	class errorManip
	{
		void (Err::*fPtr_)();
		Err& err_;

	public:

		errorManip(void (Err::*fPtr)(), Err& t)
			: fPtr_(fPtr)
			, err_(t)
		{}

		friend Ostream& operator<< <Err>(Ostream& os, errorManip<Err> m);
	};


	template<class Err>
	inline Ostream& operator<<(Ostream& os, errorManip<Err> m)
	{
		(m.err_.*m.fPtr_)();
		return os;
	}


	/*---------------------------------------------------------------------------*\
							   Class errorManipArg Declaration
	\*---------------------------------------------------------------------------*/

	//- errorManipArg
	template<class Err, class T>
	class errorManipArg
	{
		void (Err::*fPtr_)(const T);
		Err& err_;
		T arg_;

	public:

		errorManipArg(void (Err::*fPtr)(const T), Err& t, const T i)
			: fPtr_(fPtr)
			, err_(t)
			, arg_(i)
		{}

		friend Ostream& operator<< <Err, T>(Ostream& os, errorManipArg<Err, T> m);
	};


	template<class Err, class T>
	inline Ostream& operator<<(Ostream& os, errorManipArg<Err, T> m)
	{
		(m.err_.*m.fPtr_)(m.arg_);
		return os;
	}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	inline errorManipArg<error, int> exit(error& err, const int errNo = 1)
	{
		return errorManipArg<error, int>(&error::exit, err, errNo);
	}

	inline errorManip<error> abort(error& err)
	{
		return errorManip<error>(&error::abort, err);
	}


	inline errorManipArg<IOerror, int> exit(IOerror& err, const int errNo = 1)
	{
		return errorManipArg<IOerror, int>(&IOerror::exit, err, errNo);
	}

	inline errorManip<IOerror> abort(IOerror& err)
	{
		return errorManip<IOerror>(&IOerror::abort, err);
	}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}