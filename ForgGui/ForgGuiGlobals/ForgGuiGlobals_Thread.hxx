#pragma once
#ifndef _ForgGuiGlobals_Thread_Header
#define _ForgGuiGlobals_Thread_Header

#include <ForgGuiGlobals.hxx>
#include <ForgGuiThread.hxx>

#include <QtCore/QObject>
#include <QtCore/QEventLoop>

#include <type_traits>
#include <utility>

template<typename Callable>
union storage
{
	storage() {}
	std::decay_t<Callable> callable;
};

template<int, typename Callable, typename Ret, typename... Args>
auto fnptr_(Callable&& c, Ret(*)(Args...))
{
	static bool used = false;
	static storage<Callable> s;
	using type = decltype(s.callable);

	if (used)
		s.callable.~type();
	new (&s.callable) type(std::forward<Callable>(c));
	used = true;

	return [](Args... args) -> Ret {
		return Ret(s.callable(std::forward<Args>(args)...));
	};
}

template<typename Fn, int N = 0, typename Callable>
Fn* fnptr(Callable&& c)
{
	return fnptr_<N>(std::forward<Callable>(c), (Fn*)nullptr);
}

// boiler-plate
#define CONCATENATE_DETAIL(x, y) x##y
#define CONCATENATE(x, y) CONCATENATE_DETAIL(x, y)
#define MAKE_UNIQUE(x) CONCATENATE(x, __LINE__)

#define ForgDefineProcessFunction(functionName, function)\
auto functionName = fnptr<void()>([&]{function;});

#define ForgExecuteFunctionInMultiProcess(parentMainWindow, N, function)\
ForgDefineProcessFunction(MAKE_UNIQUE(func), function); \
ForgVector<ForgSharedPtr<ForgGuiThread>> MAKE_UNIQUE(thread);\
for(int i = 0; i < N; i++)\
{\
MAKE_UNIQUE(thread).push_back(ForgMakeSharedPtr(ForgGuiThread)(parentMainWindow, MAKE_UNIQUE(func)));\
MAKE_UNIQUE(thread).at(i)->start();\
}\
ForgVector<ForgSharedPtr<QEventLoop>> MAKE_UNIQUE(eventLoop);\
for(int i = 0; i < N; i++)\
{\
MAKE_UNIQUE(eventLoop).push_back(ForgMakeSharedPtr(QEventLoop)());\
QObject::connect(MAKE_UNIQUE(thread).at(i).get(), SIGNAL(finished()), MAKE_UNIQUE(eventLoop).at(i).get(), SLOT(quit())); \
if (!MAKE_UNIQUE(thread).at(i)->isFinished())\
MAKE_UNIQUE(eventLoop).at(i)->exec();\
}

#define ForgExecuteFunctionInProcess(parentMainWindow, function) ForgExecuteFunctionInMultiProcess(parentMainWindow, 1, function)

#endif // !_ForgGuiGlobals_Thread_Header
