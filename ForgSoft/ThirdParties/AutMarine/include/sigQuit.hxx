#pragma once
#ifndef _sigQuit_Header
#define _sigQuit_Header

typedef	void(*__p_sig_fn_t)(int);

namespace AutLib
{

	class sigQuit
	{
		// Private data

		//- Saved old signal trapping setting
		static __p_sig_fn_t oldAction_;


		// Private Member Functions

		static void sigQuitHandler(int);


	public:

		// Constructors

		sigQuit();


		// Destructor

		~sigQuit();


		// Member functions

		void set(const bool verbose);
	};
}

#endif // !_sigQuit_Header
