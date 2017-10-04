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

/**
 * Create a identity matrix 4x4
 */
static inline mat4_t mat4()
{
  return (mat4_t){
    .data = {
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0,
      0, 0, 0, 1,
    }
  };
}


/**
 *
 */
static inline mat3_t tomat3(mat4_t m)
{
  return (mat3_t){
    .data = {
      m.m00, m.m01, m.m02,
      m.m20, m.m11, m.m12,
      m.m10, m.m21, m.m22,
    }
  };
}


/**
 *
 */
static inline mat4_t tomat4(mat3_t m)
{
  return (mat4_t){
    .data = {
      m.m00, m.m01, m.m02, 0,
      m.m20, m.m11, m.m12, 0,
      m.m10, m.m21, m.m22, 0,
          0,     0,     0, 0,
    }
  };
}


/**
 * Create translate matrix
 */
static inline mat4_t translate3f(float x, float y, float z)
{									
  return (mat4_t){
    .data = {
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0,
      x, y, z, 1,
    }
  };
}


static inline mat4_t translatev2(vec2_t v)
{
  return translate3f(v.x, v.y, 0.0);
}


static inline mat4_t translatev3(vec3_t v)
{
  return translate3f(v.x, v.y, v.z);
}


static inline mat4_t translate2f(float x, float y)
{
  return translate3f(x, y, 0);
}


/**
 * Create scale matrix
 */
static inline mat4_t scale3f(float x, float y, float z)
{
  return (mat4_t){
    .data = {
      x, 0, 0, 0,
      0, y, 0, 0,
      0, 0, z, 0,
      0, 0, 0, 1,
    }
  };
}


static inline mat4_t scale1f(float s) 
{
  return scale3f(s, s, s);
}


static inline mat4_t scale2f(float x, float y)
{
  return scale3f(x, y, 1.0);
}


static inline mat4_t scalev2(vec2_t v)
{
  return scale3f(v.x, v.y, 1.0);
}


static inline mat4_t scalev3(vec3_t v)
{
  return scale3f(v.x, v.y, v.z);
}

/**
 * Create mat4 rotate in X-axis matrix
 */
static inline mat4_t rotatex(float angle)
{
  float c = cosf(angle);
  float s = sinf(angle);
  return (mat4_t){
    .data = {
      1,  0, 0, 0,
      0,  c, s, 0,
      0, -s, c, 0,
      0,  0, 0, 1,
    }
  };
}


/**
 * Create mat4 rotate in Y-axis matrix
 */
static inline mat4_t rotatey(float angle)
{
  float c = cosf(angle);
  float s = sinf(angle);
  return (mat4_t){
    .data = {
       c,  0, s, 0,
       0,  1, 0, 0,
      -s,  0, c, 0,
       0,  0, 0, 1,
    }
  };
}


/**
 * Create mat4 rotate in Z-axis matrix
 */
static inline mat4_t rotatez(float angle)
{
  float c = cosf(angle);
  float s = sinf(angle);
  return (mat4_t){
    .data = {
       c, s, 0, 0,
      -s, c, 0, 0,
       0, 0, 1, 0,
       0, 0, 0, 1,
    }
  };
}



/**
 * Create mat4 rotate matrix
 */
static inline mat4_t rotate3f(float x, float y, float z, float angle)
{
  float c = cosf(-angle);
  float s = sinf(-angle);
  float t = 1.0f - c;
  
  return (mat4_t){
    .data = {
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
}


/**
 * Create rotate matrix with axis and angle
 */
static inline mat4_t rotatev(vec3_t v, float angle)
{
  return rotate3f(v.x, v.y, v.z, angle);
}


/**
 * Create rotation matrix from quaternion
 */
static inline mat4_t rotateq(quat_t q)
{
  vec4_t aa = toaxis(q); /* axis-angle form of quaternion */
  return rotatev(aa.axis, aa.angle);
}


/**
 * Addidtion of two matrix4x4
 */
static inline mat4_t addm4(mat4_t a, mat4_t b)
{
#ifdef VMATH_SIMD_ENABLE
  return (mat4_t){
    .rows = {
      add4(a.rows[0], b.rows[0]),
      add4(a.rows[1], b.rows[1]),
      add4(a.rows[2], b.rows[2]),
      add4(a.rows[3], b.rows[3]),
    }
  };
#else
  return (mat4_t){
    .data = {
      a.m00 + b.m00, a.m01 + b.m01, a.m02 + b.m02, a.m03 + b.m03,
      a.m10 + b.m10, a.m11 + b.m11, a.m12 + b.m12, a.m13 + b.m13,
      a.m20 + b.m20, a.m21 + b.m21, a.m22 + b.m22, a.m23 + b.m23,
      a.m30 + b.m30, a.m31 + b.m31, a.m32 + b.m32, a.m33 + b.m33,
    }
  };
#endif
}


/**
 * Subtraction of two matrix4x4
 */
static inline mat4_t subm4(mat4_t a, mat4_t b)
{
#ifdef VMATH_SIMD_ENABLE
  return (mat4_t){
    .rows = {
      sub4(a.rows[0], b.rows[0]),
      sub4(a.rows[1], b.rows[1]),
      sub4(a.rows[2], b.rows[2]),
      sub4(a.rows[3], b.rows[3]),
    }
  };
#else
  return (mat4_t){
    .data = {
      a.m00 - b.m00, a.m01 - b.m01, a.m02 - b.m02, a.m03 - b.m03,
      a.m10 - b.m10, a.m11 - b.m11, a.m12 - b.m12, a.m13 - b.m13,
      a.m20 - b.m20, a.m21 - b.m21, a.m22 - b.m22, a.m23 - b.m23,
      a.m30 - b.m30, a.m31 - b.m31, a.m32 - b.m32, a.m33 - b.m33,
    }
  };
#endif
}


/**
 * Multiplication of two matrix4x4
 */
static inline mat4_t mulm4(mat4_t a, mat4_t b)
{
  return (mat4_t){
    .data = {
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
}


/**
 * Transpose matrix4x4
 */
static inline mat4_t transpose4(mat4_t m)
{
  return (mat4_t){
    .data = {
      m.m00, m.m10, m.m20, m.m30,
      m.m01, m.m11, m.m21, m.m31,
      m.m02, m.m12, m.m22, m.m32,
      m.m03, m.m13, m.m23, m.m33,
    }
  };
}


/**
 * Create orthographic projection matrix
 */
static inline mat4_t ortho(float l, float r, float b, float t, float n, float f)
{
  return (mat4_t){
    .data = {
      2.0f / (r - l), 0, 0, 0,
      0, 2.0f / (t - b), 0, 0,
      0, 0, 2.0f / (f - n), 0,
      (l + r) / (l - r), (b + t) / (b - t), (n + f) / (n - f), 1,
    }
  };
}


/**
 * Create frustum matrix
 */
static inline mat4_t frustum(float l, float r, float b, float t, float n, float f)
{
  return (mat4_t){
    .data = {
      2.0f / (r - l), 0, 0, 0,
      0, 2.0f / (t - b), 0, 0,
      (r + l) / (r - l), (t + b) / (t - b), (f + b) / (f - n), 1,
      0, 0, 2.0f / (f - n), 0,
    }
  };
}


/**
 * Create perspective projection matrix
 */
static inline mat4_t perspective(float fov, float aspect, float near, float far)
{
  const float a = 1.0f / tanf(fov * 0.5f);
  const float b = far / (near - far);
  return (mat4_t){
    .data = {
      a / aspect, 0, 0, 0,
      0, a, 0, 0,
      0, 0, b, -1,
      0, 0, near * b, 0,
    }
  };
}


/**
 * Create view matrix when focus on the position
 */
static inline mat4_t lookat(vec3_t eye, vec3_t target, vec3_t up)
{
  vec3_t z = normalize3(sub3(eye, target));
  vec3_t x = normalize3(cross3(up, z));
  vec3_t y = normalize3(cross3(z, x));
  return (mat4_t){
    .data = {
      x.x, y.x, z.x, 0,
      x.y, y.y, z.y, 0,
      x.z, y.z, z.z, 0,
      -dot3(x, eye), -dot3(y, eye), -dot3(z, eye), 1.0f,
    }
  };
}
