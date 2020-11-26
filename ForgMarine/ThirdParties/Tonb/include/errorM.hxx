#pragma once
#include <Global_Macros.hxx>
#define FunctionSIG __FUNCSIG__

#define FULLDEBUG
#ifdef FULLDEBUG
#define Debug(theStatements)  \
    {theStatements}
#else
#define Debug(theStatements) ((void)0)
#endif // FULLDEBUG

#ifdef FULLDEBUG
#define Debug_If_Condition(theCondition)  \
  Debug(if(theCondition) {FatalErrorIn(FunctionSIG) << " The Condition Is not Satisfied" <<tnbLib::abort(FatalError);})
#else
#define Debug_If_Condition(theCondition)  ((void)0)
#endif // FULLDEBUG

#ifdef FULLDEBUG
#define Debug_If_Condition_Message(theCondition, theMessage)  \
  Debug(if(theCondition) {FatalErrorIn(FunctionSIG) << theMessage << tnbLib::abort(FatalError);})
#else
#define Debug_If_Condition_Message(theCondition, theMessage)  ((void)0)
#endif // FULLDEBUG

#ifdef FULLDEBUG
#define Debug_Bad_Index(INDEX, MinIndex, MaxIndex)  \
  Debug(IF_NOT_INSIDE(INDEX, MinIndex, MaxIndex) {FatalErrorIn(__FUNCSIG__) << " Bad Subscript" <<tnbLib::abort(FatalError);})
#else
#define Debug_Bad_Index(INDEX, MinIndex, MaxIndex)  ((void)0)
#endif // FULLDEBUG

#ifdef FULLDEBUG
#define Debug_Null_Pointer(Pointer) \
  Debug(if(!Pointer){FatalErrorIn(FunctionSIG) << "NULL Pointer has been detected" << abort(FatalError);})
#else
#define Debug_Null_Pointer(Pointer) ((void)0)
#endif // FULLDEBUG