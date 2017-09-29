/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */

/**
 * Matrix4x4 data structure
 */
typedef union
{
  struct
  {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;
  };
  vec4_t rows[4];
  float  m[4][4];
  float  data[16];
} mat4_t;


#define MAT4_IDENTITY mat4()

#define mat4() (mat4_t){ { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 } }

#define translatev2(v)       translate3f(v.x, v.y, 0.0)
#define translatev3(v)       translate3f(v.x, v.y, v.z)
#define translate2f(x, y)    translate3f(x, y, 0)
#define translate3f(x, y, z)						\
  (mat4_t){ { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, x, y, z, 1 } }

#define scalev2(v)       scale3f(v.x, v.y, 1.0)
#define scalev3(v)       scale3f(v.x, v.y, v.z)
#define scale1f(s)       scale3f(s, s, s)
#define scale2f(x, y)    scale3f(x, y, 1.0)
#define scale3f(x, y, z)					\
  (mat4_t){ { x, 0, 0, 0, 0, y, 0, 0, 0, 0, z, 0, 0, 0, 0, 1 } }

#define rotatev(v, angle) rotate3f(v.x, v.y, v.z, angle)
#define rotateq(q) rotatev(toaxis(q).axis, toaxis(q).angle)

/**
 * Create mat4 rotate in X-axis matrix
 */
static inline mat4_t rotatex(float angle)
{
  float c = cos(angle);
  float s = sin(angle);
  mat4_t r = (mat4_t){
    {
      1,  0, 0, 0,
      0,  c, s, 0,
      0, -s, c, 0,
      0,  0, 0, 1,
    }
  };
  return r;
}


/**
 * Create mat4 rotate in Y-axis matrix
 */
static inline mat4_t rotatey(float angle)
{
  float c = cos(angle);
  float s = sin(angle);
  mat4_t r = (mat4_t){
    {
       c,  0, s, 0,
       0,  1, 0, 0,
      -s,  0, c, 0,
       0,  0, 0, 1,
    }
  };
  return r;
}


/**
 * Create mat4 rotate in Z-axis matrix
 */
static inline mat4_t rotatez(float angle)
{
  float c = cos(angle);
  float s = sin(angle);
  mat4_t r = (mat4_t){
    {
       c, s, 0, 0,
      -s, c, 0, 0,
       0, 0, 1, 0,
       0, 0, 0, 1,
    }
  };
  return r;
}



/**
 * Create mat4 rotate matrix
 */
static inline mat4_t rotate3f(float x, float y, float z, float angle)
{
  float c = cos(-angle);
  float s = sin(-angle);
  float t = 1.0f - c;
  
  mat4_t r = (mat4_t){
    {
      /* Row 1
       */
      t * x * x + c, t * x * y - s * z,
      t * x * z + s * y, 0.0f,

      /* Row 2
       */
      t * x * y + s * z, t * y * y + c,
      t * y * z - s * x, 0.0f,

      /* Row 3
       */
      t * x * z - s * y, t * y * z + s * x,
      t * z * z + c, 0.0f,

      /* Row 4
       */
      0, 0, 0, 1.0f,
    }
  };
  return r;
}


/**
 * Addidtion of two matrix4x4
 */
static inline mat4_t addm4(mat4_t a, mat4_t b)
{
  mat4_t r = (mat4_t){
    {
      a.m00 + b.m00, a.m01 + b.m01, a.m02 + b.m02, a.m03 + b.m03,
      a.m10 + b.m10, a.m11 + b.m11, a.m12 + b.m12, a.m13 + b.m13,
      a.m20 + b.m20, a.m21 + b.m21, a.m22 + b.m22, a.m23 + b.m23,
      a.m30 + b.m30, a.m31 + b.m31, a.m32 + b.m32, a.m33 + b.m33,
    }
  };
  return r;
}


/**
 * Subtraction of two matrix4x4
 */
static inline mat4_t subm4(mat4_t a, mat4_t b)
{
  mat4_t r = (mat4_t){
    {
      a.m00 - b.m00, a.m01 - b.m01, a.m02 - b.m02, a.m03 - b.m03,
      a.m10 - b.m10, a.m11 - b.m11, a.m12 - b.m12, a.m13 - b.m13,
      a.m20 - b.m20, a.m21 - b.m21, a.m22 - b.m22, a.m23 - b.m23,
      a.m30 - b.m30, a.m31 - b.m31, a.m32 - b.m32, a.m33 - b.m33,
    }
  };
  return r;
}


/**
 * Multiplication of two matrix4x4
 */
static inline mat4_t mulm4(mat4_t a, mat4_t b)
{
  mat4_t r = (mat4_t){
    /*{
      b.m00 * a.m00 + b.m01 * a.m10 + b.m02 * a.m20 + b.m03 * a.m30,
      b.m00 * a.m01 + b.m01 * a.m11 + b.m02 * a.m21 + b.m03 * a.m31,
      b.m00 * a.m02 + b.m01 * a.m12 + b.m02 * a.m22 + b.m03 * a.m32,
      b.m00 * a.m03 + b.m01 * a.m13 + b.m02 * a.m23 + b.m03 * a.m33,
    
      b.m10 * a.m00 + b.m11 * a.m10 + b.m12 * a.m20 + b.m13 * a.m30,
      b.m10 * a.m01 + b.m11 * a.m11 + b.m12 * a.m21 + b.m13 * a.m31,
      b.m10 * a.m02 + b.m11 * a.m12 + b.m12 * a.m22 + b.m13 * a.m32,
      b.m10 * a.m03 + b.m11 * a.m13 + b.m12 * a.m23 + b.m13 * a.m33,
      
      b.m20 * a.m00 + b.m21 * a.m10 + b.m22 * a.m20 + b.m23 * a.m30,
      b.m20 * a.m01 + b.m21 * a.m11 + b.m22 * a.m21 + b.m23 * a.m31,
      b.m20 * a.m02 + b.m21 * a.m12 + b.m22 * a.m22 + b.m23 * a.m32,
      b.m20 * a.m03 + b.m21 * a.m13 + b.m22 * a.m23 + b.m23 * a.m33,
	
      b.m30 * a.m00 + b.m31 * a.m10 + b.m32 * a.m20 + b.m33 * a.m30,
      b.m30 * a.m01 + b.m31 * a.m11 + b.m32 * a.m21 + b.m33 * a.m31,
      b.m30 * a.m02 + b.m31 * a.m12 + b.m32 * a.m22 + b.m33 * a.m32,
      b.m30 * a.m03 + b.m31 * a.m13 + b.m32 * a.m23 + b.m33 * a.m33,
      }*/
    {
      a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20 + a.m03 * b.m30,
      a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21 + a.m03 * b.m31,
      a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22 + a.m03 * b.m32,
      a.m00 * b.m03 + a.m01 * b.m13 + a.m02 * b.m23 + a.m03 * b.m33,
    
      a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20 + a.m13 * b.m30,
      a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31,
      a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32,
      a.m10 * b.m03 + a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33,
     
      a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20 + a.m23 * b.m30,
      a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31,
      a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32,
      a.m20 * b.m03 + a.m21 * b.m13 + a.m22 * b.m23 + a.m23 * b.m33,
	
      a.m30 * b.m00 + a.m31 * b.m10 + a.m32 * b.m20 + a.m33 * b.m30,
      a.m30 * b.m01 + a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31,
      a.m30 * b.m02 + a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32,
      a.m30 * b.m03 + a.m31 * b.m13 + a.m32 * b.m23 + a.m33 * b.m33,
    }
  };
  return r;
}


/**
 * Transpose matrix4x4
 */
static inline mat4_t transpose(mat4_t m)
{
  mat4_t r = (mat4_t){
    {
      m.m00, m.m10, m.m20, m.m30,
      m.m01, m.m11, m.m21, m.m31,
      m.m02, m.m12, m.m22, m.m32,
      m.m03, m.m13, m.m23, m.m33,
    }
  };
  return r;
}


/**
 * Create orthographic projection matrix
 */
static inline mat4_t ortho(float l, float r, float b, float t, float n, float f)
{
  mat4_t m = (mat4_t){
    {
      2.0f / (r - l), 0, 0, 0,
      0, 2.0f / (t - b), 0, 0,
      0, 0, 2.0f / (f - n), 0,
      (l + r) / (l - r), (b + t) / (b - t), (n + f) / (n - f), 1,
    }
  };
  return m;
}


/**
 * Create frustum matrix
 */
static inline mat4_t frustum(float l, float r, float b, float t, float n, float f)
{
  mat4_t m = (mat4_t){
    {
      2.0f / (r - l), 0, 0, 0,
      0, 2.0f / (t - b), 0, 0,
      (r + l) / (r - l), (t + b) / (t - b), (f + b) / (f - n), 1,
      0, 0, 2.0f / (f - n), 0,
    }
  };
  return m;
}


/**
 * Create perspective projection matrix
 */
static inline mat4_t perspective(float fov, float aspect, float near, float far)
{
  const float a = 1.0f / tan(fov * 0.5f);
  const float b = far / (near - far);
  mat4_t r = (mat4_t){
    {
      a / aspect, 0, 0, 0,
      0, a, 0, 0,
      0, 0, b, -1,
      0, 0, near * b, 0,
    }
  };
  return r;
}


/**
 * Create view matrix when focus on the position
 */
static inline mat4_t lookat(vec3_t eye, vec3_t target, vec3_t up)
{
  vec3_t z = normalize3(sub3(eye, target));
  vec3_t x = normalize3(cross3(up, z));
  vec3_t y = normalize3(cross3(z, x));
  mat4_t r = (mat4_t){
    {
      x.x, y.x, z.x, 0,
      x.y, y.y, z.y, 0,
      x.z, y.z, z.z, 0,
      -dot3(x, eye),
      -dot3(y, eye),
      -dot3(z, eye),
      //0, 0, 0,
      1.0f,
    }
  };
  //return mulm4(translate3f(-eye.x, -eye.y, -eye.z), r);
  return r;
}
