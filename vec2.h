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
  float64_t simd; 
} vec2_t;

#define vec2(x, y) (vec2_t){ { x, y } }


/**
 * Addition of two vector2d
 */
static inline vec2_t add2(vec2_t a, vec2_t b)
{
  return vec2(a.x + b.x, a.y + b.y);
}


/**
 * Subtraction of two vector2d
 */
static inline vec2_t sub2(vec2_t a, vec2_t b)
{
  return vec2(a.x - b.x, a.y - b.y);
}


/**
 * Multiply of a vector2d with a scalar
 */
static inline vec2_t mul2(vec2_t v, float s)
{
  return vec2(v.x * s, v.y * s);
}


/**
 * Division of a vector2d with a scalar
 */
static inline vec2_t div2(vec2_t v, float s)
{
  return vec2(v.x / s, v.y / s);
}


/**
 * Dot product of two vector 2d
 */
static inline float  dot2(vec2_t a, vec2_t b)
{
  return a.x * b.x + a.y * b.y;
}


/**
 * Squared length of vector 2d
 */
static inline float  lensqr2(vec2_t v)
{
  return v.x * v.x + v.y * v.y;
}


/**
 * Length of vector 2d
 */
static inline float  len2(vec2_t v)
{
  return sqrt(lensqr2(v));
}


/**
 * Distance of two vector 2d
 */
static inline float  dist2(vec2_t a, vec2_t b)
{
  return len2(sub2(b, a));
}


/**
 * Squared distance of two vector 2d
 */
static inline float  distsqr2(vec2_t a, vec2_t b)
{
  return lensqr2(sub2(b, a));
}


/**
 * Angle of vector 2d
 */
static inline float  angle2(vec2_t v)
{
  return atan2(v.y, v.x);
}


/**
 * Normalize vector 2d, force direction only and unit length
 */
static inline vec2_t normalize2(vec2_t v)
{
  float length = lensqr2(v);
  if (length != 1.0f && (length = sqrt(length)) > 0) {
    vec2_t r;
    r.x = v.x / length;
    r.y = v.y / length;
    return r;
  }
  return v;
}
