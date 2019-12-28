#pragma once
#ifndef _FrgBase_Global_Thread_Header
#define _FrgBase_Global_Thread_Header

#include <FrgBase_Global.hxx>
#include <FrgBaseThread.hxx>

#include <QtCore/QEventLoop>
#include <QtCore/QObject>
#include <QtCore/QMutex>

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

#define DefineProcessFunction(functionName, function)\
auto functionName = fnptr<void()>([&]{function;});

#define ExecuteFunctionInMultiProcess(parentMainWindow, N, function, Mutex, lockFunction)\
DefineProcessFunction(MAKE_UNIQUE(func), function); \
DefineProcessFunction(MAKE_UNIQUE(lockFunc), lockFunction); \
StdVector<FrgBaseThread*> MAKE_UNIQUE(thread);\
for(int i = 0; i < N; i++)\
{\
MAKE_UNIQUE(thread).push_back(FrgNew FrgBaseThread(parentMainWindow, MAKE_UNIQUE(func), Mutex, MAKE_UNIQUE(lockFunc)));\
MAKE_UNIQUE(thread).at(i)->start();\
}\
StdVector<QEventLoop*> MAKE_UNIQUE(eventLoop);\
for(int i = 0; i < N; i++)\
{\
MAKE_UNIQUE(eventLoop).push_back(FrgNew QEventLoop());\
QObject::connect(MAKE_UNIQUE(thread).at(i), SIGNAL(finished()), MAKE_UNIQUE(eventLoop).at(i), SLOT(quit())); \
if (!MAKE_UNIQUE(thread).at(i)->isFinished())\
MAKE_UNIQUE(eventLoop).at(i)->exec();\
}

#define ExecuteFunctionInMultiProcessMoveToThread(parentMainWindow, N, function, Mutex, lockFunction, moveTothread)\
DefineProcessFunction(MAKE_UNIQUE(func), function); \
DefineProcessFunction(MAKE_UNIQUE(lockFunc), lockFunction); \
StdVector<FrgBaseThread*> MAKE_UNIQUE(thread);\
for(int i = 0; i < N; i++)\
{\
MAKE_UNIQUE(thread).push_back(FrgNew FrgBaseThread(parentMainWindow, MAKE_UNIQUE(func), Mutex, MAKE_UNIQUE(lockFunc)));\
if(moveTothread)\
moveTothread->moveToThread(MAKE_UNIQUE(thread)[i]);\
MAKE_UNIQUE(thread).at(i)->start();\
}\
FrgVector<QEventLoop*> MAKE_UNIQUE(eventLoop);\
for(int i = 0; i < N; i++)\
{\
MAKE_UNIQUE(eventLoop).push_back(FrgNew QEventLoop());\
QObject::connect(MAKE_UNIQUE(thread).at(i), SIGNAL(finished()), MAKE_UNIQUE(eventLoop).at(i), SLOT(quit())); \
if (!MAKE_UNIQUE(thread).at(i)->isFinished())\
MAKE_UNIQUE(eventLoop).at(i)->exec();\
}

#define ExecuteFunctionInProcess(parentMainWindow, function, Mutex, lockFunction) ExecuteFunctionInMultiProcess(parentMainWindow, 1, function, Mutex, lockFunction)
#define ExecuteFunctionInProcessMoveToThread(parentMainWindow, function, Mutex, lockFunction, moveTothread) ExecuteFunctionInMultiProcess(parentMainWindow, 1, function, Mutex, lockFunction, moveTothread)

#endif // !_FrgBase_Global_Thread_Header
