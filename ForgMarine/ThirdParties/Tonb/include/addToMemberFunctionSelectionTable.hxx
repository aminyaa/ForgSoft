#pragma once
#ifndef _addToMemberFunctionSelectionTable_Header
#define _addToMemberFunctionSelectionTable_Header

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


// add to hash-table of functions with typename as the key
#define addToMemberFunctionSelectionTable\
(baseType,thisType,memberFunction,argNames)                                   \
                                                                              \
    /* Add the thisType memberFunction to the table */                        \
    baseType::add##memberFunction##argNames##MemberFunctionToTable<thisType>  \
    add##thisType##memberFunction##argNames##MemberFunctionTo##baseType##Table_



// add to hash-table of functions with 'lookup' as the key
#define addNamedToMemberFunctionSelectionTable\
(baseType,thisType,memberFunction,argNames,lookup)                            \
                                                                              \
    /* Add the thisType memberFunction to the table, find by lookup name */   \
    baseType::add##memberFunction##argNames##MemberFunctionToTable<thisType>  \
    add_##lookup##_##thisType##memberFunction##argNames##MemberFunctionTo##baseType##Table_(#lookup)


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


// add to hash-table of functions with typename as the key
// use when baseType doesn't need a template argument (eg, is a typedef)
#define addTemplateToMemberFunctionSelectionTable\
(baseType,thisType,Targ,memberFunction,argNames)                              \
                                                                              \
    /* Add the thisType memberFunction to the table */                        \
    baseType::add##memberFunction##argNames##MemberFunctionToTable<thisType<Targ>> \
    add##thisType##Targ##memberFunction##argNames##MemberFunctionTo##baseType##Table_


// add to hash-table of functions with 'lookup' as the key
// use when baseType doesn't need a template argument (eg, is a typedef)
#define addNamedTemplateToMemberFunctionSelectionTable\
(baseType,thisType,Targ,memberFunction,argNames,lookup)                       \
                                                                              \
    /* Add the thisType memberFunction to the table, find by lookup name */   \
    baseType::add##memberFunction##argNames##MemberFunctionToTable<thisType<Targ>> \
    add_##lookup##_##thisType##Targ##memberFunction##argNames##MemberFunctionTo##baseType##Table_(#lookup)

// use when baseType requires the Targ template argument as well
#define addTemplatedToMemberFunctionSelectionTable\
(baseType,thisType,Targ,memberFunction,argNames)                              \
                                                                              \
    /* Add the thisType memberFunction to the table */                        \
    baseType<Targ>::add##memberFunction##argNames##MemberFunctionToTable<thisType<Targ>> \
    add##thisType##Targ##memberFunction##argNames##MemberFunctionTo##baseType##Targ##Table_

// use when baseType requires the Targ template argument as well
#define addNamedTemplatedToMemberFunctionSelectionTable\
(baseType,thisType,Targ,memberFunction,argNames,lookup)                       \
                                                                              \
    /* Add the thisType memberFunction to the table, find by lookup name */   \
    baseType<Targ>::add##memberFunction##argNames##MemberFunctionToTable<thisType<Targ>> \
    add_##lookup##_##thisType##Targ##memberFunction##argNames##MemberFunctionTo##baseType##Targ##Table_(#lookup)


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


// add to hash-table of functions with typename as the key
// use when baseType requires the Targ template argument as well
#define addTemplatedToMemberFunctionSelectionTable\
(baseType,thisType,Targ,memberFunction,argNames)                              \
                                                                              \
    /* Add the thisType memberFunction to the table */                        \
    baseType<Targ>::add##memberFunction##argNames##MemberFunctionToTable<thisType<Targ>> \
    add##thisType##Targ##memberFunction##argNames##MemberFunctionTo##baseType##Targ##Table_


// add to hash-table of functions with 'lookup' as the key
// use when baseType requires the Targ template argument as well
#define addNamedTemplatedToMemberFunctionSelectionTable\
(baseType,thisType,Targ,memberFunction,argNames,lookup)                       \
                                                                              \
    /* Add the thisType memberFunction to the table, find by lookup name */   \
    baseType<Targ>::add##memberFunction##argNames##MemberFunctionToTable<thisType<Targ>> \
    add_##lookup##_##thisType##Targ##memberFunction##argNames##MemberFunctionTo##baseType##Targ##Table_(#lookup)


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_addToMemberFunctionSelectionTable_Header
