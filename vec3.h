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
  float  data[3];
} vec3_t;


/***********
 * Contants
 */
#define VEC3_ZERO  vec3(0, 0, 0)
#define VEC3_UNIT  vec3(1, 1, 1)
#define VEC3_UNITX vec3(1, 0, 0)
#define VEC3_UNITY vec3(0, 1, 0)
#define VEC3_UNITZ vec3(0, 0, 1)
#define VEC3_LEFT  vec3(-1, 0, 0)
#define VEC3_RIGHT vec3(1, 0, 0)
#define VEC3_UP    vec3(0, 1, 0)
#define VEC3_DOWN  vec3(0, -1, 0)
#define VEC3_BACK  vec3(0, 0, -1)
#define VEC3_FORE  vec3(0, 0, 1)


/**
 * Create vector3d
 */
__vmath__ vec3_t vec3(float x, float y, float z)
{
  return (vec3_t){ .x = x, .y = y, .z = z };
}


/**
 * Compare two vector3d is equal or not
 */
__vmath__ int    eql3(vec3_t a, vec3_t b)
{
  return a.x == b.x && a.y == b.y && a.z == b.z;
}


/**
 * Negative version of a Vector3D
 */
__vmath__ vec3_t neg3(vec3_t v)
{
  return vec3(-v.x, -v.y, -v.z);
}


/**
 * Addition of two vector 3d
 */
__vmath__ vec3_t add3(vec3_t a, vec3_t b)
{
  return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}


/**
 * subtraction of two vector 3d
 */
__vmath__ vec3_t sub3(vec3_t a, vec3_t b)
{
  return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}


/**
 * Multiply of a vector 3d with a scalar, also called as scale
 */
__vmath__ vec3_t mul3(vec3_t v, float s)
{
  return vec3(v.x * s, v.y * s, v.z * s);
}


/**
 * Division of a vector 3d with a scalar, also called as scale down 
 */
__vmath__ vec3_t div3(vec3_t v, float s)
{
  return mul3(v, 1.0f / s);
}


/**
 * Dot product of two vector 3d
 */
__vmath__ float dot3(vec3_t a, vec3_t b)
{
  return a.x * b.x + a.y * b.y + a.z * b.z;
}


/**
 * Cross product of two vector 3d
 */
__vmath__ vec3_t cross3(vec3_t a, vec3_t b)
{
  return vec3(a.y * b.z - a.z * b.y,					
	      a.z * b.x - a.x * b.z,		
	      a.x * b.y - a.y * b.x);
}


/**
 * Squared length of vector 3d
 */
__vmath__ float lensqr3(vec3_t v)
{
  return v.x * v.x + v.y * v.y + v.z * v.z;
}


/**
 * Length of vector 3d
 */
__vmath__ float len3(vec3_t v)
{
  return sqrtf(lensqr3(v));
}


/**
 * Distance of two vector 3d
 */
__vmath__ float dist3(vec3_t a, vec3_t b)
{
  return len3(sub3(b, a));
}


/**
 * Squared distance of two vector 3d
 */
__vmath__ float distsqr3(vec3_t a, vec3_t b)
{
  return lensqr3(sub3(b, a));
}


/**
 * Normalize vector 3d (force to direction only, unit length)
 */
__vmath__ vec3_t normalize3(vec3_t v)
{
  const float lsqr = lensqr3(v);
  if (lsqr != 1.0f && lsqr > 0) {
    const float l = sqrtf(lsqr);
    return vec3(v.x / l, v.y / l, v.z / l);
  }
  return v;
}
