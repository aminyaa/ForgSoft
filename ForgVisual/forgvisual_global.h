#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(FORGVISUAL_LIB)
#  define FORGVISUAL_EXPORT Q_DECL_EXPORT
# else
#  define FORGVISUAL_EXPORT Q_DECL_IMPORT
# endif
#else
# define FORGVISUAL_EXPORT
#endif
