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
#define VMATH_VERSION "v1.0.2"

/**
 * Custom modifier
 */
#ifdef __GNUC__ /* GCC */
#ifdef __STRICT_ANSI__
#define inline __inline__
#endif
#define __attr__ __attribute__((nothrow, pure, const))
#else /* Windows MSVC */
#define inline _inline
#define __attr__ __declspec(const)
#endif
#define __vmath__ static inline __attr__


/**
 * Include dependencies
 */
#include <math.h>
#include <float.h>
#include <limits.h>
#include <stdint.h>

#if defined(__ARM_NEON) || defined(__ARM_NEON__)
#include <arm_neon.h>
#ifndef VMATH_NEON_ENABLE
#define VMATH_NEON_ENABLE 1
#endif
#else
#undef VMATH_NEON_ENABLE
#endif

#if defined(__SSSE3__)
#define SSE_SUPPORT
#endif
#if defined(__SSE__) || defined(__SSE2__) || defined(__SSE3__)
#define SSE_SUPPORT
#endif
#if defined(__SSE4_1__) || defined(__SSE4_2__) || defined(__SSE_VMATH__)
#define SSE_SUPPORT
#endif
#ifdef SSE_SUPPORT
#include <mmintrin.h>
#include <xmmintrin.h>
#include <emmintrin.h>
#ifndef VMATH_SSE_ENABLE
#define VMATH_SSE_ENABLE 1
#endif
#else
#undef VMATH_SSE_ENABLE
#endif

/**
 * Include modules
 */

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
#if __STDC__ == 1 && __STDC_VERSION__ >= 201112L
#include <tgmath.h>
#include "tgvmath.h"
#endif

#endif /* __VMATH_H__ */
