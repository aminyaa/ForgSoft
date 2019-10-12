#pragma once
#ifndef _Exceptions_Header
#define _Exceptions_Header

#define HAS_EXCEPTIONS

#ifdef HAS_EXCEPTIONS

#define TRY_BEGIN	try {
#define CATCH(x)	} catch (x) {
#define CATCH_ALL	} catch (...) {
#define CATCH_END	}

#define RAISE(x) throw x
#define RERAISE	throw

#else

#define TRY_BEGIN	{ if (1) {
#define CATCH(x)	} else if (0) {
#define CATCH_ALL	} else if (0) {
#define CATCH_END	} }

#define RERAISE
#define THROW(x)	x.Raise()

#endif

#endif // !_Exceptions_Header
