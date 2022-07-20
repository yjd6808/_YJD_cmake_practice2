
#ifndef LIBMATH_EXPORT_H
#define LIBMATH_EXPORT_H

#ifdef LIBMATH_STATIC_DEFINE
#  define LIBMATH_EXPORT
#  define LIBMATH_NO_EXPORT
#else
#  ifndef LIBMATH_EXPORT
#    ifdef libmath_EXPORTS
        /* We are building this library */
#      define LIBMATH_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define LIBMATH_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef LIBMATH_NO_EXPORT
#    define LIBMATH_NO_EXPORT 
#  endif
#endif

#ifndef LIBMATH_DEPRECATED
#  define LIBMATH_DEPRECATED __declspec(deprecated)
#endif

#ifndef LIBMATH_DEPRECATED_EXPORT
#  define LIBMATH_DEPRECATED_EXPORT LIBMATH_EXPORT LIBMATH_DEPRECATED
#endif

#ifndef LIBMATH_DEPRECATED_NO_EXPORT
#  define LIBMATH_DEPRECATED_NO_EXPORT LIBMATH_NO_EXPORT LIBMATH_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef LIBMATH_NO_DEPRECATED
#    define LIBMATH_NO_DEPRECATED
#  endif
#endif

#endif /* LIBMATH_EXPORT_H */
