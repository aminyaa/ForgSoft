#pragma once
#ifndef _multiThreader_Header
#define _multiThreader_Header

#include <regIOobject.hxx>
#include <error.hxx>

#include <pthread.h>
#include <errno.h>
#include <sys/types.h>
//#include <unistd.h>

extern "C"
{
	typedef void *(*externThreadFunctionType)(void *);
}

typedef void *(*threadFunctionType)(void *);

#define threadReturnType void *
#define threadReturnValue NULL

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	class Mutex
	{
		// Private data

		mutable pthread_mutex_t lock_;

	public:

		// Debug switch
		static bool debug;

		// Constructor
		Mutex();

		// Destructor
		~Mutex();

		// Lock the mutex
		void lock() const;

		// Try to acquire the mutex.
		// Returns zero if successful
		bool tryLock() const;

		// Unlock the mutex
		void unlock() const;

		// Operator overload
		inline pthread_mutex_t* operator()()
		{
			return &lock_;
		}
	};

	class rwMutex
	{
		// Private data

		mutable pthread_rwlock_t lock_;

	public:

		// Enumerants for lock-types
		enum lockType
		{
			READ_LOCK,
			WRITE_LOCK
		};

		// Debug switch
		static bool debug;

		// Constructor
		rwMutex();

		// Destructor
		~rwMutex();

		// Lock the mutex
		void lock(const lockType lType) const;

		// Try to acquire a lock
		bool tryLock(const lockType lType) const;

		// Unlock the mutex
		void unlock() const;

		// Operator overload
		inline pthread_rwlock_t* operator()()
		{
			return &lock_;
		}
	};

	class Conditional
	{
		// Private data

		mutable pthread_cond_t condition_;

	public:

		// Constructor
		Conditional();

		// Destructor
		~Conditional();

		// Operator overload
		inline pthread_cond_t* operator()()
		{
			return &condition_;
		}
	};

	/*---------------------------------------------------------------------------*\
							   Class multiThreader Declaration
	\*---------------------------------------------------------------------------*/

	class multiThreader
	{
		// Private data

		mutable int numThreads_;

		mutable int maxQueueSize_;

		// Work-queue item: Holds a pointer to the method and its argument
		struct workQueueItem
		{
			void(*function)(void*);
			void *arg;
			workQueueItem *next;
		};

		// Common structure for all threads in the pool.
		mutable struct threadPool
		{
			multiThreader *threader;
			int numThreads;
			int queueSize;
			pthread_t *threads;
			pthread_attr_t attr;
			workQueueItem *head, *tail;

			// Flags
			bool queueClosed;
			bool shutDown;

			// Synchronization
			Mutex queueLock;
			Conditional queueNotEmpty;
			Conditional queueNotFull;
			Conditional queueEmpty;
		} *poolInfo_;

		// Private Member Functions

		void initializeThreadPool();

		static threadReturnType poolThread(void *arg);

		void destroyThreadPool();

		//- Disallow default bitwise copy construct
		multiThreader(const multiThreader&);

		//- Disallow default bitwise assignment
		void operator=(const multiThreader&);

	public:

		// Debug switch

		static bool debug;

		// Constructor

			//- Construct with specified number of threads
		multiThreader(int numThreads);


		// Destructor

		~multiThreader();


		// Member Functions

			//- Return the number of threads
		int getNumThreads() const;

		//- Obtain the thread ID for a given index
		pthread_t getID(int index) const;

		//- Return true if the number of threads is equal to one.
		bool singleThreaded() const;

		//- Return true if the number of threads is more than one.
		bool multiThreaded() const;

		//- Return the maxQueueSize
		int getMaxQueueSize() const;

		//- Set the maxQueueSize
		void setMaxQueueSize(int size) const;

		//- Add a function to the work queue
		void addToWorkQueue(void(*tFunction)(void*), void *arg) const;

		//- Conditional handling
		void waitForCondition(Conditional&, Mutex&) const;
		void broadCast(Conditional&) const;
		void signal(Conditional&) const;
	};

	/*---------------------------------------------------------------------------*\
							 Class IOmultiThreader Declaration
	\*---------------------------------------------------------------------------*/

	class IOmultiThreader
		: public regIOobject
		, public multiThreader
	{

		// Member functions

			//- Disallow default bitwise copy construct
		IOmultiThreader(const IOmultiThreader&);

		//- Disallow default bitwise assignment
		void operator=(const IOmultiThreader&);

	public:

		//- Runtime type information
		TypeName("multiThreader");


		// Constructors

			//- Construct from IOobject and specified number of threads
		IOmultiThreader(const IOobject& io, int numThreads)
			:
			regIOobject(io),
			multiThreader(numThreads)
		{}

		// Destructor

		virtual ~IOmultiThreader() {}

		// Member functions

		bool writeData(Ostream&) const
		{
			return true;
		}
	};

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_multiThreader_Header
