#pragma once
#ifndef _sigInt_Header
#define _sigInt_Header

typedef	void(*__p_sig_fn_t)(int);

namespace AutLib
{

	class sigInt
	{
		// Private data

		//- Saved old signal trapping setting
		static __p_sig_fn_t oldAction_;


		// Private Member Functions

		static void sigIntHandler(int);


	public:

		// Constructors

		sigInt();


		// Destructor

		~sigInt();


		// Member functions

		void set(const bool verbose);
	};
}

#endif // !_sigInt_Header
