/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */

 #pragma once

/**
 * Vector4D data structure
 */
typedef union __vmath_vec4__
{
  struct
  {
    float x, y, z, w;
  };
  struct
  {
    vec2_t pos;
    float  width, height;
  };
  struct
  {
    float r, g, b, a;
  };
  struct
  {
    vec2_t xy;
    vec2_t zw;
  };
  struct
  {
    float  _x;
    vec2_t yz;
    float  _w;
  };
  struct
  {
    vec3_t xyz;
    float  _w_;
  };
  struct
  {
    float  _x_;
    vec3_t yzw;
  };
  /**
   * Quaternion axis angle result
   */
  struct
  {
    vec3_t axis;
    float  angle;
  };
  float  data[4];
  
#if VMATH_NEON_ENABLE
  float32x4_t simd;
#elif VMATH_SSE_ENABLE
  __m128 simd;
#endif
} vec4_t;


/***********
 * Contants
 */
static const vec4_t VEC4_ZERO  = {  0,  0,  0, 0 };
static const vec4_t VEC4_UNIT  = {  1,  1,  1, 1 };
static const vec4_t VEC4_UNITX = {  1,  0,  0, 0 };
static const vec4_t VEC4_UNITY = {  0,  1,  0, 0 };
static const vec4_t VEC4_UNITZ = {  0,  0,  1, 0 };
static const vec4_t VEC4_UNITW = {  0,  0,  0, 1 };
static const vec4_t VEC4_LEFT  = { -1,  0,  0, 0 };
static const vec4_t VEC4_RIGHT = {  1,  0,  0, 0 };
static const vec4_t VEC4_UP    = {  0,  1,  0, 0 };
static const vec4_t VEC4_DOWN  = {  0, -1,  0, 0 };
static const vec4_t VEC4_BACK  = {  0,  0, -1, 0 };
static const vec4_t VEC4_FORE  = {  0,  0,  1, 0 };

/**
 * Create a Vector4D
 */
__vmath__ vec4_t vec4(float x, float y, float z, float w)
{
  vec4_t v = { x, y, z, w };
  return v;
}


/**
 * Addition of two Vector4D
 */
__vmath__ vec4_t add4(vec4_t a, vec4_t b)
{
#if VMATH_NEON_ENABLE
  return (vec4_t){ .simd = vaddq_f32(a.simd, b.simd) };
#elif VMATH_SSE_ENABLE
  vec4_t r;
  r.simd = _mm_add_ps(a.simd, b.simd);
  return r;
#else
  return vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
#endif
}


/**
 * Subtraction of two vector4d
 */
__vmath__ vec4_t sub4(vec4_t a, vec4_t b)
{
#if VMATH_NEON_ENABLE
  return (vec4_t){ .simd = vsubq_f32(a.simd, b.simd) };
#elif VMATH_SSE_ENABLE
  vec4_t r;
  r.simd = _mm_sub_ps(a.simd, b.simd);
  return r;
#else
  return vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
#endif
}


/**
 * Multiplication of a vector4d with a scalar
 */
__vmath__ vec4_t mul4(vec4_t v, float s)
{
#if VMATH_NEON_ENABLE
  return (vec4_t){ .simd = vmulq_n_f32(v.simd, s) };
#else
  return vec4(v.x * s, v.y * s, v.z * s, v.w * s);
#endif
}


/**
 * Division of a vector4d with a scalar
 */
__vmath__ vec4_t div4(vec4_t v, float s)
{
  return mul4(v, 1.0f / s);
}


/**
 * Compare two vector4d is equal or not
 */
__vmath__ bool   eql4(vec4_t a, vec4_t b)
{
#if VMATH_NEON_ENABLE
  /* return sub4(a, b).simd == VEC4_ZERO.simd;
   */
  return eql2(a.xy, b.xy) && eql2(a.zw, b.zw);
#elif VMATH_SSE_ENABLE
  return (_mm_movemask_ps(_mm_cmpeq_ps(a.simd, b.simd)) & 7) == 7;
#else
  return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
#endif
}


/**
 * Negative version of a Vector4D
 */
__vmath__ vec4_t neg4(vec4_t v)
{
#if VMATH_NEON_ENABLE
  return (vec4_t){ .simd = vnegq_f32(v.simd) };
#else
  return vec4(-v.x, -v.y, -v.z, -v.w);
#endif
}


/**
 * Dot product of two vector4d
 */
__vmath__ float  dot4(vec4_t a, vec4_t b)
{
#if VMATH_NEON_ENABLE
  vec4_t v = (vec4_t){ .simd = vmulq_f32(a.simd, b.simd) };
  return v.x + v.y + v.z + v.w;
#elif VMATH_SSE_ENABLE
  vec4_t v;
  v.simd = _mm_mul_ps(a.simd, b.simd);
  return v.x + v.y + v.z + v.w;
#else
  return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
#endif
}


/**
 * Squared length of vector4d
 */
__vmath__ float  lensqr4(vec4_t v)
{
#if VMATH_NEON_ENABLE
  vec4_t r = (vec4_t){ .simd = vmulq_f32(v.simd, v.simd) };
  return r.x + r.y + r.z + r.w;
#elif VMATH_SSE_ENABLE
  vec4_t r;
  r.simd = _mm_mul_ps(v.simd, v.simd);
  return r.x + r.y + r.z + r.w;
#else
  return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
#endif
}


/**
 * Length of vector4d
 */
__vmath__ float  len4(vec4_t v)
{
  return sqrtf(lensqr4(v));
}


/**
 * Distance of two vector4d
 */
__vmath__ float  dist4(vec4_t a, vec4_t b)
{
  return len4(sub4(b, a));
}


/**
 * Squared distance of two vector4d
 */
__vmath__ float  distsqr4(vec4_t a, vec4_t b)
{
  return lensqr4(sub4(b, a));
}


/**
 * Normalize vector4d, force direction only with unit length
 */
__vmath__ vec4_t normalize4(vec4_t v)
{
  const float lsqr = lensqr4(v);
  if (lsqr != 1.0f && lsqr > 0) {
    const float l = sqrtf(lsqr);
    return vec4(v.x / l, v.y / l, v.z / l, v.w / l);
  }
  return v;
}
