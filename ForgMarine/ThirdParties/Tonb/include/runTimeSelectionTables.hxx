#pragma once
#ifndef _runTimeSelectionTables_Header
#define _runTimeSelectionTables_Header

#include <autoPtr.hxx>
#include <HashTable.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


// external use:
// ~~~~~~~~~~~~~
// declare a run-time selection:
#define declareRunTimeSelectionTable(autoPtr,baseType,argNames,argList,parList) \
                                                                              \
    /* Construct from argList function pointer type */                        \
    typedef autoPtr< baseType > (*argNames##ConstructorPtr)argList;           \
                                                                              \
    /* Construct from argList function table type */                          \
    typedef HashTable< argNames##ConstructorPtr, word, string::hash >         \
        argNames##ConstructorTable;                                           \
                                                                              \
    /* Construct from argList function pointer table pointer */               \
    static argNames##ConstructorTable* argNames##ConstructorTablePtr_;        \
                                                                              \
    /* Class to add constructor from argList to table */                      \
    template< class baseType##Type >                                          \
    class add##argNames##ConstructorToTable                                   \
    {                                                                         \
    public:                                                                   \
                                                                              \
        static autoPtr< baseType > New argList                                \
        {                                                                     \
            return autoPtr< baseType >(new baseType##Type parList);           \
        }                                                                     \
                                                                              \
        add##argNames##ConstructorToTable                                     \
        (                                                                     \
            const word& lookup = baseType##Type::typeName                     \
        )                                                                     \
        {                                                                     \
            construct##argNames##ConstructorTables();                         \
            argNames##ConstructorTablePtr_->insert(lookup, New);              \
        }                                                                     \
                                                                              \
        ~add##argNames##ConstructorToTable()                                  \
        {                                                                     \
            destroy##argNames##ConstructorTables();                           \
        }                                                                     \
    };                                                                        \
                                                                              \
    /* Table constructor called from the table add function */                \
    static void construct##argNames##ConstructorTables();                     \
                                                                              \
    /* Table destructor called from the table add function destructor */      \
    static void destroy##argNames##ConstructorTables()


// external use:
// ~~~~~~~~~~~~~
// declare a run-time selection for derived classes:
#define declareRunTimeNewSelectionTable(autoPtr,baseType,argNames,argList,parList)\
                                                                              \
    /* Construct from argList function pointer type */                        \
    typedef autoPtr< baseType > (*argNames##ConstructorPtr)argList;           \
                                                                              \
    /* Construct from argList function table type */                          \
    typedef HashTable< argNames##ConstructorPtr, word, string::hash >         \
        argNames##ConstructorTable;                                           \
                                                                              \
    /* Construct from argList function pointer table pointer */               \
    static argNames##ConstructorTable* argNames##ConstructorTablePtr_;        \
                                                                              \
    /* Class to add constructor from argList to table */                      \
    template< class baseType##Type >                                          \
    class add##argNames##ConstructorToTable                                   \
    {                                                                         \
    public:                                                                   \
                                                                              \
        static autoPtr< baseType > New##baseType argList                      \
        {                                                                     \
            return autoPtr< baseType >(baseType##Type::New parList.ptr());    \
        }                                                                     \
                                                                              \
        add##argNames##ConstructorToTable                                     \
        (                                                                     \
            const word& lookup = baseType##Type::typeName                     \
        )                                                                     \
        {                                                                     \
            construct##argNames##ConstructorTables();                         \
            argNames##ConstructorTablePtr_->insert                            \
            (                                                                 \
                lookup,                                                       \
                New##baseType                                                 \
            );                                                                \
        }                                                                     \
                                                                              \
        ~add##argNames##ConstructorToTable()                                  \
        {                                                                     \
            destroy##argNames##ConstructorTables();                           \
        }                                                                     \
    };                                                                        \
                                                                              \
    /* Table constructor called from the table add function */                \
    static void construct##argNames##ConstructorTables();                     \
                                                                              \
    /* Table destructor called from the table add function destructor */      \
    static void destroy##argNames##ConstructorTables()


// internal use:
// constructor aid
#define defineRunTimeSelectionTableConstructor(baseType,argNames)             \
                                                                              \
    /* Table constructor called from the table add function */                \
    void baseType::construct##argNames##ConstructorTables()                   \
    {                                                                         \
        static bool constructed = false;                                      \
                                                                              \
        if (!constructed)                                                     \
        {                                                                     \
            baseType::argNames##ConstructorTablePtr_                          \
                = new baseType::argNames##ConstructorTable;                   \
                                                                              \
            constructed = true;                                               \
        }                                                                     \
    }


// internal use:
// destructor aid
#define defineRunTimeSelectionTableDestructor(baseType,argNames)              \
                                                                              \
    /* Table destructor called from the table add function destructor */      \
    void baseType::destroy##argNames##ConstructorTables()                     \
    {                                                                         \
        if (baseType::argNames##ConstructorTablePtr_)                         \
        {                                                                     \
            delete baseType::argNames##ConstructorTablePtr_;                  \
            baseType::argNames##ConstructorTablePtr_ = NULL;                  \
        }                                                                     \
    }


// internal use:
// create pointer to hash-table of functions
#define defineRunTimeSelectionTablePtr(baseType,argNames)                     \
                                                                              \
    /* Define the constructor function table */                               \
    baseType::argNames##ConstructorTable*                                     \
        baseType::argNames##ConstructorTablePtr_ = NULL


// not much in use:
#define defineTemplateRunTimeSelectionTablePtr(baseType,argNames)             \
                                                                              \
    /* Define the constructor function table */                               \
    typename baseType::argNames##ConstructorTable*                            \
        baseType::argNames##ConstructorTablePtr_ = NULL


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


// external use:
// ~~~~~~~~~~~~~
// define run-time selection table
#define defineRunTimeSelectionTable(baseType,argNames)                        \
                                                                              \
    defineRunTimeSelectionTablePtr(baseType,argNames);                        \
    defineRunTimeSelectionTableConstructor(baseType,argNames);                \
    defineRunTimeSelectionTableDestructor(baseType,argNames)


// external use:
// ~~~~~~~~~~~~~
// define run-time selection table for template classes
// use when baseType doesn't need a template argument (eg, is a typedef)
#define defineTemplateRunTimeSelectionTable(baseType,argNames)                \
                                                                              \
    template<>                                                                \
    defineRunTimeSelectionTablePtr(baseType,argNames);                        \
    template<>                                                                \
    defineRunTimeSelectionTableConstructor(baseType,argNames);                \
    template<>                                                                \
    defineRunTimeSelectionTableDestructor(baseType,argNames)


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


// internal use:
// constructor aid
// use when baseType requires the Targ template argument
#define defineTemplatedRunTimeSelectionTableConstructor(baseType,argNames,Targ)\
                                                                              \
    /* Table constructor called from the table add function */                \
    void baseType< Targ >::construct##argNames##ConstructorTables()           \
    {                                                                         \
        static bool constructed = false;                                      \
                                                                              \
        if (!constructed)                                                     \
        {                                                                     \
            baseType< Targ >::argNames##ConstructorTablePtr_                  \
                = new baseType< Targ >::argNames##ConstructorTable;           \
                                                                              \
            constructed = true;                                               \
        }                                                                     \
    }


// internal use:
// destructor aid
// use when baseType requires the Targ template argument
#define defineTemplatedRunTimeSelectionTableDestructor(baseType,argNames,Targ)\
                                                                              \
    /* Table destructor called from the table add function destructor */      \
    void baseType< Targ >::destroy##argNames##ConstructorTables()             \
    {                                                                         \
        if (baseType< Targ >::argNames##ConstructorTablePtr_)                 \
        {                                                                     \
            delete baseType< Targ >::argNames##ConstructorTablePtr_;          \
            baseType< Targ >::argNames##ConstructorTablePtr_ = NULL;          \
        }                                                                     \
    }


// internal use:
// create pointer to hash-table of functions
// use when baseType requires the Targ template argument
#define defineTemplatedRunTimeSelectionTablePtr(baseType,argNames,Targ)       \
                                                                              \
    /* Define the constructor function table */                               \
    baseType< Targ >::argNames##ConstructorTable*                             \
        baseType< Targ >::argNames##ConstructorTablePtr_ = NULL


// external use:
// ~~~~~~~~~~~~~
// define run-time selection table for template classes
// use when baseType requires the Targ template argument
#define defineTemplatedRunTimeSelectionTable(baseType,argNames,Targ)          \
                                                                              \
    template<>                                                                \
    defineTemplatedRunTimeSelectionTablePtr(baseType,argNames,Targ);          \
    template<>                                                                \
    defineTemplatedRunTimeSelectionTableConstructor(baseType,argNames,Targ);  \
    template<>                                                                \
    defineTemplatedRunTimeSelectionTableDestructor(baseType,argNames,Targ)


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_runTimeSelectionTables_Header
