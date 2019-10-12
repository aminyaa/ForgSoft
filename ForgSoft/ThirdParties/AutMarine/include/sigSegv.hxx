#pragma once
#ifndef _sigSegv_Header
#define _sigSegv_Header

typedef	void(*__p_sig_fn_t)(int);

namespace AutLib
{

	class sigSegv
	{
		// Private data

		//- Saved old signal trapping setting
		static __p_sig_fn_t oldAction_;


		// Private Member Functions

		static void sigSegvHandler(int);


	public:

		// Constructors

		sigSegv();


		// Destructor

		~sigSegv();


		// Member functions

		void set(const bool verbose);
	};
}

#endif // !_sigSegv_Header
