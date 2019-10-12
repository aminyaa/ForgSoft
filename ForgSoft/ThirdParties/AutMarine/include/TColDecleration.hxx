#pragma once
#ifndef _TColDecleration_Header
#define _TColDecleration_Header

#define TCol_ADT_DeclarationH(NameSpace, TypeName, Container, SuffixName)      \
  typedef ADT_##Container<Global_Handle(TypeName)> TCol##NameSpace##_H##Container##Of##SuffixName

#define TCol_ADT_DeclarationD(NameSpace, TypeName, Container, SuffixName)      \
  typedef ADT_##Container<Global_Dangle(TypeName)> TCol##NameSpace##_D##Container##Of##SuffixName

#define TCol_ADT_DeclarationConstH(NameSpace, TypeName, Container, SuffixName)      \
  typedef ADT_##Container<Global_Handle(TypeName)> TCol##NameSpace##_ConstH##Container##Of##SuffixName

#define TCol_ADT_DeclarationConstD(NameSpace, TypeName, Container, SuffixName)      \
  typedef ADT_##Container<Global_Dangle(TypeName)> TCol##NameSpace##_ConstD##Container##Of##SuffixName

#define TCol_ADT_Declarations(NameSpace, TypeName, Container, SuffixName) \
  TCol_ADT_DeclarationH(NameSpace, TypeName, Container, SuffixName);      \
  TCol_ADT_DeclarationD(NameSpace, TypeName, Container, SuffixName);/*;      \
  TCol_ADT_DeclarationConstH(NameSpace, TypeName, Container, SuffixName); \
  TCol_ADT_DeclarationConstD(NameSpace, TypeName, Container, SuffixName)*/
  

#endif // !_TColDecleration_Header
