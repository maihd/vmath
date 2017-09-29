/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */


/**
 * Vector3D data structures definition
 * It's also defined some handler for get Vector2D from its
 */
typedef union
{
  struct
  {
    float x, y, z;
  };
  struct
  {
    float  _x;
    vec2_t yz;
  };
  struct
  {
    vec2_t xy;
    float  _z;
  };
  struct
  {
    float r, g, b;
  };
  float data[3];
} vec3_t;


#define vec3(x, y, z)      (vec3_t){ { x, y, z } }

/**
 * Addition of two vector 3d
 */
static inline vec3_t add3(vec3_t a, vec3_t b)
{
  return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}


/**
 * subtraction of two vector 3d
 */
static inline vec3_t sub3(vec3_t a, vec3_t b)
{
  return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}


/**
 * Multiply of a vector 3d with a scalar, also called as scale
 */
static inline vec3_t mul3(vec3_t v, float s)
{
  return vec3(v.x * s, v.y * s, v.z * s);
}


/**
 * Division of a vector 3d with a scalar, also called as scale down 
 */
static inline vec3_t div3(vec3_t v, float s)
{
  return mul3(v, 1.0f / s);
}


/**
 * Dot product of two vector 3d
 */
static inline float dot3(vec3_t a, vec3_t b)
{
  return a.x * b.x + a.y * b.y + a.z * b.z;
}


/**
 * Cross product of two vector 3d
 */
static inline vec3_t cross3(vec3_t a, vec3_t b)
{
  return vec3(a.y * b.z - a.z * b.y,					
	      a.z * b.x - a.x * b.z,		
	      a.x * b.y - a.y * b.x);
}


/**
 * Squared length of vector 3d
 */
static inline float lensqr3(vec3_t v)
{
  return v.x * v.x + v.y * v.y + v.z * v.z;
}


/**
 * Length of vector 3d
 */
static inline float len3(vec3_t v)
{
  return sqrt(lensqr3(v));
}


/**
 * Distance of two vector 3d
 */
static inline float dist3(vec3_t a, vec3_t b)
{
  return len3(sub3(b, a));
}


/**
 * Squared distance of two vector 3d
 */
static inline float distsqr3(vec3_t a, vec3_t b)
{
  return lensqr3(sub3(b, a));
}


/**
 * Normalize vector 3d (force to direction only, unit length)
 */
static inline vec3_t normalize3(vec3_t v)
{
  vec3_t r = v;
  float length = lensqr3(r);
  if (length != 1.0f && (length = sqrt(length)) > 0) {
    r.x /= length;
    r.y /= length;
    r.z /= length;
  }
  return r;
}
