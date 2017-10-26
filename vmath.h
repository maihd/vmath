/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */

#ifndef __VMATH_H__
#define __VMATH_H__

#define VMATH_LIBNAME "libvmath"
#define VMATH_VERSION "v1.0.3"

/**
 * Custom modifier
 */
#if !defined(__cplusplus) 
# ifdef __GNUC__ /* GCC */
#  define __vmath_inline__ __inline__
# else /* Windows MSVC */
# define __vmath_inline__ __inline
# endif
#else
# define __vmath_inline__ inline
#endif

#ifdef __GNUC__ /* GCC */
# define __vmath_attr__ __attribute__((nothrow, pure, const))
#else /* Windows MSVC */
# define __vmath_attr__ __forceinline __nothrow
#endif
#define __vmath__ __vmath_attr__ static __vmath_inline__


/**
 * Include dependencies
 */
#include <math.h>
#include <float.h>
#include <limits.h>
#include <stdint.h>


/**
 * ARM NEON support checking
 */
#if defined(__ARM_NEON) || defined(__ARM_NEON__)
# include <arm_neon.h>
# ifndef VMATH_NEON_ENABLE
#  define VMATH_NEON_ENABLE 1
# endif
#else
# undef VMATH_NEON_ENABLE
#endif

/**
 * SSE support checking
 */
#if defined(__SSSE3__)
# define VMATH_SSE_SUPPORT
#endif
#if defined(__SSE__) || defined(__SSE2__) || defined(__SSE3__)
# define VMATH_SSE_SUPPORT
#endif
#if defined(__SSE4_1__) || defined(__SSE4_2__) || defined(__SSE_VMATH__)
# define VMATH_SSE_SUPPORT
#endif
#if _MSC_VER && (defined(_M_IX86) || defined(_M_IX64))
# if defined(_M_HYBRID_X86_ARM64)
#  undef VMATH_SSE_SUPPORT
# else
#  define VMATH_SSE_SUPPORT
# endif
#endif

#ifdef VMATH_SSE_SUPPORT
# include <mmintrin.h>
# include <xmmintrin.h>
# include <emmintrin.h>
# ifndef VMATH_SSE_ENABLE
#  define VMATH_SSE_ENABLE 1
# endif
#else
# undef VMATH_SSE_ENABLE
#endif


/**
 * Boolean type support
 */
#if !defined(__cplusplus) && !defined(bool)
typedef unsigned char bool;
#endif
#if !defined(__cplusplus) && !defined(true)
# define true 1
#endif
#if !defined(__cplusplus) && !defined(false)
# define false 0
#endif


/**
 * Include modules
 */

#ifdef __cplusplus
extern "C" {
#endif

#if __GNUC__
# pragma GCC diagnostic ignored "-Wmissing-braces"
#else
# pragma warning(disable : 4141)
#endif

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "quat.h"
#include "mat3.h"
#include "mat4.h"

#include "ray.h"
#include "box3.h"
#include "face.h"
#include "line.h"
#include "rect.h"
#include "plane.h"
#include "frustum.h"

/**
 * Type generic functions
 */
#ifdef __cplusplus
}
# include "operators.h"
#elif __STDC__ == 1 && __STDC_VERSION__ >= 201112L
# include <tgmath.h>
# include "tgvmath.h"
#endif

#endif /* __VMATH_H__ */
