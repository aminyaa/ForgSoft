#pragma once
#ifndef _className_Header
#define _className_Header

#include <word.hxx>
#include <tnbDebug.hxx>
#include <debugSwitch.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// declarations (without debug information)
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//- Add typeName information from argument @a TypeNameString to a class.
//  Without debug information
#define ClassNameNoDebug(TypeNameString)                                      \
    static const char* typeName_() { return TypeNameString; }                 \
    static const ::tnbLib::word typeName

//- Add typeName information from argument @a TypeNameString to a namespace.
//  Without debug information.
#define NamespaceNameNoDebug(TypeNameString)                                  \
    inline const char* typeName_() { return TypeNameString; }                 \
    extern const ::tnbLib::word typeName

//- Add typeName information from argument @a TemplateNameString to a template class.
//  Without debug information.
#define TemplateNameNoDebug(TemplateNameString)                               \
class TemplateNameString##Name                                                \
{                                                                             \
public:                                                                       \
    TemplateNameString##Name() {}                                             \
    ClassNameNoDebug(#TemplateNameString);                                    \
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// declarations (with debug information)
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//- Add typeName information from argument @a TypeNameString to a class.
//  Also declares debug information.
#define ClassName(TypeNameString)                                             \
    ClassNameNoDebug(TypeNameString);                                         \
    static tnbLib::debug::debugSwitch debug;

//- Add typeName information from argument @a TypeNameString to a namespace.
//  Also declares debug information.
#define NamespaceName(TypeNameString)                                         \
    NamespaceNameNoDebug(TypeNameString);                                     \
    extern tnbLib::debug::debugSwitch debug;

//- Add typeName information from argument @a TypeNameString to a template class.
//  Also declares debug information.
#define TemplateName(TemplateNameString)                                      \
class TemplateNameString##Name                                                \
{                                                                             \
public:                                                                       \
    TemplateNameString##Name() {}                                             \
    ClassName(#TemplateNameString);                                           \
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// definitions (without debug information)
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//- Define the typeName, with alternative lookup as @a Name
#define defineTypeNameWithName(Type, Name)                                    \
    const ::tnbLib::word Type::typeName(Name)

//- Define the typeName
#define defineTypeName(Type)                                                  \
    defineTypeNameWithName(Type, Type::typeName_())

#ifdef __INTEL_COMPILER
//- Define the typeName as @a Name for template classes
# define defineTemplateTypeNameWithName(Type, Name)                           \
    defineTypeNameWithName(Type, Name)
#else
//- Define the typeName as @a Name for template classes
# define defineTemplateTypeNameWithName(Type, Name)                           \
    template<>                                                                \
    defineTypeNameWithName(Type, Name)
#endif

//- Define the typeName for template classes, useful with typedefs
#define defineTemplateTypeName(Type)                                          \
    defineTemplateTypeNameWithName(Type, #Type)

//- Define the typeName directly for template classes
#define defineNamedTemplateTypeName(Type)                                     \
    defineTemplateTypeNameWithName(Type, Type::typeName_())



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// definitions (debug information only)
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//- Define the debug information, lookup as @a Name
#define defineDebugSwitchWithName(Type, Name, DebugSwitch, SwitchDescr)       \
    ::tnbLib::debug::debugSwitch                                                \
    Type::debug(std::string(Name), DebugSwitch, SwitchDescr)

//- Define the debug information
#define defineDebugSwitch(Type, DebugSwitch, SwitchDescr)                     \
    defineDebugSwitchWithName(Type, Type::typeName_(), DebugSwitch, SwitchDescr);

#ifdef __INTEL_COMPILER
//- Define the debug information for templates, lookup as @a Name
# define defineTemplateDebugSwitchWithName(Type, Name, DebugSwitch)           \
    defineDebugSwitchWithName(Type, Name, DebugSwitch, "");

#else
//- Define the debug information for templates, lookup as @a Name
# define defineTemplateDebugSwitchWithName(Type, Name, DebugSwitch)           \
    template<>                                                                \
    defineDebugSwitchWithName(Type, Name, DebugSwitch, "");
#endif

//- Define the debug information for templates
//  Useful with typedefs
#define defineTemplateDebugSwitch(Type, DebugSwitch)                          \
    defineTemplateDebugSwitchWithName(Type, #Type, DebugSwitch)

//- Define the debug information directly for templates
#define defineNamedTemplateDebugSwitch(Type, DebugSwitch)                     \
    defineTemplateDebugSwitchWithName(Type, Type::typeName_(), DebugSwitch)



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// definitions (with debug information)
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//- Define the typeName and debug information
#define defineTypeNameAndDebug(Type, DebugSwitch)                             \
    defineTypeName(Type);                                                     \
    defineDebugSwitch(Type, DebugSwitch, "")

//- Define the typeName and debug information + description
#define defineTypeNameAndDebugWithDescription(Type, DebugSwitch, SwitchDescr) \
    defineTypeName(Type);                                                     \
    defineDebugSwitch(Type, DebugSwitch, SwitchDescr)

//- Define the typeName and debug information, lookup as @a Name
#define defineTemplateTypeNameAndDebugWithName(Type, Name, DebugSwitch)       \
    defineTemplateTypeNameWithName(Type, Name);                               \
    defineTemplateDebugSwitchWithName(Type, Name, DebugSwitch)

//- Define the typeName and debug information for templates, useful with typedefs
#define defineTemplateTypeNameAndDebug(Type, DebugSwitch)                     \
    defineTemplateTypeNameAndDebugWithName(Type, #Type, DebugSwitch)

//- Define the typeName and debug information for templates
#define defineNamedTemplateTypeNameAndDebug(Type, DebugSwitch)                \
    defineNamedTemplateTypeName(Type);                                        \
    defineNamedTemplateDebugSwitch(Type, DebugSwitch)


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_className_Header
