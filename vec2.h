/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */

#pragma once

/**
 * Vector2D data structure
 */
typedef union __vmath_vec2__
{
    struct
    {
	float x, y;
    };
    struct
    {
	float s, t;
    };
    float data[2];
#if VMATH_NEON_ENABLE
    uint32_t pure; /* Pure data for compare */
    float32x2_t simd;
#elif VMATH_SSE_ENABLE
    __m64 simd;
#endif
} vec2_t;




/***********
 * Contants
 */
static const vec2_t VEC2_ZERO  = {  0,  0 };
static const vec2_t VEC2_UNIT  = {  1,  1 };
static const vec2_t VEC2_UNITX = {  1,  1 };
static const vec2_t VEC2_UNITY = {  0,  1 };
static const vec2_t VEC2_LEFT  = { -1,  0 };
static const vec2_t VEC2_RIGHT = {  1,  0 };
static const vec2_t VEC2_UP    = {  0,  1 };
static const vec2_t VEC2_DOWN  = {  0, -1 };


/**
 * Create vector2d
 */
__vmath__ vec2_t vec2(float x, float y)
{
    vec2_t v = { x, y };
    return v;
}


/**
 * Addition of two vector2d
 */
__vmath__ vec2_t add2(vec2_t a, vec2_t b)
{
#if VMATH_NEON_ENABLE
    return (vec2_t){ .simd = vadd_f32(a.simd, b.simd) };
    //#elif VMATH_SSE_ENABLE
    //return (vec2_t){ _mm_add_si64(a.simd, b.simd) };
#else
    return vec2(a.x + b.x, a.y + b.y);
#endif
}


/**
 * Subtraction of two vector2d
 */
__vmath__ vec2_t sub2(vec2_t a, vec2_t b)
{
#if VMATH_NEON_ENABLE
    return (vec2_t){ .simd = vsub_s32(a.simd, b.simd) };
    //#elif VMATH_SSE_ENABLE
    //return (vec2_t){ _mm_sub_si64(a.simd, b.simd) };
#else
    return vec2(a.x - b.x, a.y - b.y);
#endif
}


/**
 * Multiply of a vector2d with a scalar
 */
__vmath__ vec2_t mul2(vec2_t v, float s)
{
#if VMATH_NEON_ENABLE
    return (vec2_t){ .simd = vmul_n_f32(v.simd, s) };
#else
    return vec2(v.x * s, v.y * s);
#endif
}


/**
 * Division of a vector2d with a scalar
 */
__vmath__ vec2_t div2(vec2_t v, float s)
{
    return mul2(v, 1.0f / s);
}


/**
 * Compare two vector2d is equal or not
 */
__vmath__ bool   eql2(vec2_t a, vec2_t b)
{
#if VMATH_NEON_ENABLE
    return sub2(a, b).pure == VEC2_ZERO.pure;
    //#elif VMATH_SSE_ENABLE
    //return sub2(a, b).pure == VEC2_ZERO.pure;
#else
    return a.x == b.x && a.y == b.y;
#endif
}


/**
 * Create a negative vector
 */
__vmath__ vec2_t neg2(vec2_t v)
{
#if VMATH_NEON_ENABLE
    return (vec2_t){ .simd = vneg_f32(v.simd) };
#else
    return vec2(-v.x, -v.y);
#endif
}


/**
 * Dot product of two vector 2d
 */
__vmath__ float  dot2(vec2_t a, vec2_t b)
{
#if VMATH_NEON_ENABLE
    vec2_t v = (vec2_t){ .simd = vmul_f32(a.simd, b.simd) };
    return v.x + v.y;
    /*
      #elif VMATH_SSE_ENABLE
      vec2_t v = (vec2_t){ _mm_mul_si64(a.simd, b.simd) };
      return v.x + v.y;
    */
#else
    return a.x * b.x + a.y * b.y;
#endif
}


/**
 * Squared length of vector 2d
 */
__vmath__ float  lensqr2(vec2_t v)
{
#if VMATH_NEON_ENABLE
    vec2_t r = (vec2_t){ .simd = vmul_f32(v.simd, v.simd) };
    return r.x + r.y;
    /*
      #elif VMATH_SSE_ENABLE
      v.simd = _mm_mul_si64(v.simd, v.simd);
      return v.x + v.y;
    */
#else
    return v.x * v.x + v.y * v.y;
#endif
}


/**
 * Length of vector 2d
 */
__vmath__ float  len2(vec2_t v)
{
    return sqrtf(lensqr2(v));
}


/**
 * Distance of two vector 2d
 */
__vmath__ float  dist2(vec2_t a, vec2_t b)
{
    return len2(sub2(b, a));
}


/**
 * Squared distance of two vector 2d
 */
__vmath__ float  distsqr2(vec2_t a, vec2_t b)
{
    return lensqr2(sub2(b, a));
}


/**
 * Angle of vector 2d
 */
__vmath__ float  angle2(vec2_t v)
{
    return atan2f(v.y, v.x);
}


/**
 * Normalize vector 2d, force direction only and unit length
 */
__vmath__ vec2_t normalize2(vec2_t v)
{
    const float lsqr = lensqr2(v);
    if (lsqr != 1.0f && lsqr > 0) {
	const float l = sqrtf(lsqr);
	return vec2(v.x / l, v.y / l);
    }
    return v;
}
