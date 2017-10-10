/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */


/**
 * Vector2D data structure
 */
typedef union
{
  struct
  {
    float x, y;
  };
  struct
  {
    float width, height;
  };
  struct
  {
    float s, t;
  };
  float data[2];
#if VMATH_NEON_ENABLE
  float32x2_t simd;
#endif
} vec2_t;


/***********
 * Contants
 */
#define VEC2_ZERO  vec2(0, 0)
#define VEC2_UNIT  vec2(1, 1)
#define VEC2_UNITX vec2(1, 0)
#define VEC2_UNITY vec2(0, 1)
#define VEC2_LEFT  vec2(-1, 0)
#define VEC2_RIGHT vec2(1, 0)
#define VEC2_UP    vec2(0, 1)
#define VEC2_DOWN  vec2(0, -1)


/**
 * Create vector2d
 */
__vmath__ vec2_t vec2(float x, float y)
{
  return (vec2_t){ .x = x, .y = y };
}


/**
 * Compare two vector2d is equal or not
 */
__vmath__ int    eql2(vec2_t a, vec2_t b)
{
  return a.x == b.x && a.y == b.y;
}


/**
 * Create a negative vector
 */
__vmath__ vec2_t neg2(vec2_t v)
{
  return vec2(-v.x, -v.y);
}


/**
 * Addition of two vector2d
 */
__vmath__ vec2_t add2(vec2_t a, vec2_t b)
{
#if VMATH_NEON_ENABLE
  return (vec2_t){ .simd = vadd_f32(a.simd, b.simd) };
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
#else
  return vec2(a.x - b.x, a.y - b.y);
#endif
}


/**
 * Multiply of a vector2d with a scalar
 */
__vmath__ vec2_t mul2(vec2_t v, float s)
{
  return vec2(v.x * s, v.y * s);
}


/**
 * Division of a vector2d with a scalar
 */
__vmath__ vec2_t div2(vec2_t v, float s)
{
  return vec2(v.x / s, v.y / s);
}


/**
 * Dot product of two vector 2d
 */
__vmath__ float  dot2(vec2_t a, vec2_t b)
{
  return a.x * b.x + a.y * b.y;
}


/**
 * Squared length of vector 2d
 */
__vmath__ float  lensqr2(vec2_t v)
{
  return v.x * v.x + v.y * v.y;
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
