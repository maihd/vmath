/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */


/**
 * Vector4D data structure
 */
typedef struct
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
  float      data[4];
  float128_t simd;
} vec4_t, color4f_t;

#define vec4(x, y, z, w)    (vec4_t){ { x, y, z, w } }
#define color4f(r, g, b, a) (vec4_t){ { r, g, b, a } }

/**
 * Addition of two vector4d
 */
static inline vec4_t add4(vec4_t a, vec4_t b)
{
  return vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}


/**
 * Subtraction of two vector4d
 */
static inline vec4_t sub4(vec4_t a, vec4_t b)
{
  return vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}


/**
 * Multiplication of a vector4d with a scalar
 */
static inline vec4_t mul4(vec4_t v, float s)
{
  return vec4(v.x * s, v.y * s, v.z * s, v.w * s);
}


/**
 * Division of a vector4d with a scalar
 */
static inline vec4_t div4(vec4_t v, float s)
{
  return vec4(v.x / s, v.y / s, v.z / s, v.w / s);
}


/**
 * Dot product of two vector4d
 */
static inline float  dot4(vec4_t a, vec4_t b)
{
  return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}


/**
 * Squared length of vector4d
 */
static inline float  lensqr4(vec4_t v)
{
  return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}


/**
 * Length of vector4d
 */
static inline float  len4(vec4_t v)
{
  return sqrt(lensqr4(v));
}


/**
 * Distance of two vector4d
 */
static inline float  dist4(vec4_t a, vec4_t b)
{
  return len4(sub4(b, a));
}


/**
 * Squared distance of two vector4d
 */
static inline float  distsqr4(vec4_t a, vec4_t b)
{
  return lensqr4(sub4(b, a));
}


/**
 * Normalize vector4d, force direction only with unit length
 */
static inline vec4_t normalize4(vec4_t v)
{
  float length = lensqr4(v);
  if (length != 1.0f && (length = sqrt(length)) > 0) {
    vec4_t r;
    r.x = v.x / length;
    r.y = v.y / length;
    r.z = v.z / length;
    r.w = v.w / length;
    return r;
  }
  return v;
}
