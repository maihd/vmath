/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */

#ifndef __VMATH_H__
#define __VMATH_H__

/**
 * Custom modifier
 */
#ifdef __GNUC__ /* GCC */
#ifdef __STRICT_ANSI__
#define inline __inline__
#endif
#else /* Windows MSC */
#define inline _inline
#endif

typedef __m64  float64_t;
typedef __m128 float128_t;

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "quat.h"
#include "rect.h"
#include "mat4.h"

#endif /* __VMATH_H__ */
