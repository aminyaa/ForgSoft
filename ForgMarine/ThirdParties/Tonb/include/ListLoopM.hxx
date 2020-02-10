#pragma once
#ifndef _ListLoopM_Header
#define _ListLoopM_Header

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef vectorMachine

// Element access looping using [] for vector machines

#define List_FOR_ALL(f, i)                      \
        register const label _n##i = (f).size();\
        for (register label i=0; i<_n##i; i++)  \
        {

#define List_END_FOR_ALL  }

#define List_ELEM(f, fp, i)  (fp[i])

#define List_ACCESS(type, f, fp) \
    type* const __restrict fp = (f).begin()

#define List_CONST_ACCESS(type, f, fp) \
    const type* const __restrict fp = (f).begin()

#else

// Pointer looping for scalar machines

#define List_FOR_ALL(f, i)                      \
        register label i = (f).size();          \
        while (i--)                             \
        {                                       \

#define List_END_FOR_ALL  }

#define List_ELEM(f, fp, i)  (*fp++)

#define List_ACCESS(type, f, fp) \
    register type* __restrict fp = (f).begin()

#define List_CONST_ACCESS(type, f, fp) \
    register const type* __restrict fp = (f).begin()

#endif


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_ListLoopM_Header
