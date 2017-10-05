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
#ifndef _Generic
#include <tgmath.h>
#include "tgvmath.h"
#endif

#endif /* __VMATH_H__ */
