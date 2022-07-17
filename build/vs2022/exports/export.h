
#ifndef LIBCOMMON_EXPORT_H
#define LIBCOMMON_EXPORT_H

#ifdef LIBCOMMON_STATIC_DEFINE
#  define LIBCOMMON_EXPORT
#  define LIBCOMMON_NO_EXPORT
#else
#  ifndef LIBCOMMON_EXPORT
#    ifdef libcommon_EXPORTS
        /* We are building this library */
#      define LIBCOMMON_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define LIBCOMMON_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef LIBCOMMON_NO_EXPORT
#    define LIBCOMMON_NO_EXPORT 
#  endif
#endif

#ifndef LIBCOMMON_DEPRECATED
#  define LIBCOMMON_DEPRECATED __declspec(deprecated)
#endif

#ifndef LIBCOMMON_DEPRECATED_EXPORT
#  define LIBCOMMON_DEPRECATED_EXPORT LIBCOMMON_EXPORT LIBCOMMON_DEPRECATED
#endif

#ifndef LIBCOMMON_DEPRECATED_NO_EXPORT
#  define LIBCOMMON_DEPRECATED_NO_EXPORT LIBCOMMON_NO_EXPORT LIBCOMMON_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef LIBCOMMON_NO_DEPRECATED
#    define LIBCOMMON_NO_DEPRECATED
#  endif
#endif

#endif /* LIBCOMMON_EXPORT_H */
