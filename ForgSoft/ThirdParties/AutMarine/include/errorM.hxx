#pragma once
#include <Global_Macros.hxx>
#define FunctionSIG __FUNCSIG__

#define Exception_Handle_Exit(ExceptionObject) \
FatalError(FunctionSIG, __FILE__, __LINE__) \
<<AutLib::abort(FatalError);

#define THROW_STANDARD_EXCEPTION(fn)         \
AutLib::ThrowException.throwExceptions();    \
ThrowException(fn, __FILE__, __LINE__)

#define Try_Exception_Handle_ReThrow(Expression)  \
    try {Expression;} catch(AutLib::error) {throw;} catch(std::exception&) {throw;}

#define Try_Exception_Handle_Exit(Expression)  \
    try {Expression;} catch(AutLib::error& x) {Exception_Handle_Exit(x);}

#define FULLDEBUG
#ifdef FULLDEBUG
#define Debug(theStatements)  \
    {theStatements}
#else
#define Debug(theStatements) ((void)0)
#endif // FULLDEBUG

#ifdef FULLDEBUG
#define Debug_If_Condition(theCondition)  \
  Debug(if(theCondition) {FatalErrorIn(FunctionSIG) << " The Condition Is not Satisfied" <<AutLib::abort(FatalError);})
#else
#define Debug_If_Condition(theCondition)  ((void)0)
#endif // FULLDEBUG

#ifdef FULLDEBUG
#define Debug_If_Condition_Message(theCondition, theMessage)  \
  Debug(if(theCondition) {FatalErrorIn(FunctionSIG) << theMessage << AutLib::abort(FatalError);})
#else
#define Debug_If_Condition_Message(theCondition, theMessage)  ((void)0)
#endif // FULLDEBUG

#ifdef FULLDEBUG
#define Debug_Bad_Index(INDEX, MinIndex, MaxIndex)  \
  Debug(IF_NOT_INSIDE(INDEX, MinIndex, MaxIndex) {FatalErrorIn(__FUNCSIG__) << " Bad Subscript" <<AutLib::abort(FatalError);})
#else
#define Debug_Bad_Index(INDEX, MinIndex, MaxIndex)  ((void)0)
#endif // FULLDEBUG

#ifdef FULLDEBUG
#define Debug_Null_Pointer(Pointer) \
  Debug(if(!Pointer){FatalErrorIn(FunctionSIG) << "NULL Pointer has been detected" << abort(FatalError);})
#else
#define Debug_Null_Pointer(Pointer) ((void)0)
#endif // FULLDEBUG