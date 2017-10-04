/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */

#ifndef __VMATH_H__
#define __VMATH_H__

#include <math.h>
#include <float.h>
#include <limits.h>
#include <stdint.h>

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

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "quat.h"
#include "rect.h"
#include "mat3.h"
#include "mat4.h"

#ifndef _Generic
#include <tgmath.h>
#include "tgvmath.h"
#endif

#endif /* __VMATH_H__ */
