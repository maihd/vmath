/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */


/**
 * Matrix3x3 data structure
 */
typedef union __vmath_mat3__
{
  struct
  {
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
  };
  vec3_t rows[3];
  float  m[3][3];
  float  data[9];
} mat3_t;


/******
 * Constants
 */
static const mat3_t MAT3_IDENTITY = {
  1, 0, 0,
  0, 1, 0,
  0, 0, 1,
};


/**
 * Create a identify matrix 3x3
 */
__vmath__ mat3_t mat3()
{
  return MAT3_IDENTITY;
}


/**
 * Transpose matrix3x3
 */
__vmath__ mat3_t transpose3(mat3_t m)
{
  mat3_t r = {
    m.m00, m.m10, m.m20,
    m.m01, m.m11, m.m21,
    m.m02, m.m12, m.m22,
  };
  return r;
}


/**
 * Addition of two matrix 3x3
 */
__vmath__ mat3_t addm3(mat3_t a, mat3_t b)
{
  mat3_t r;
  r.rows[0] = add3(a.rows[0], b.rows[0]);
  r.rows[1] = add3(a.rows[1], b.rows[1]);
  r.rows[2] = add3(a.rows[2], b.rows[2]);
  return r;
}


/**
 * Subtraction of two matrix 3x3
 */
__vmath__ mat3_t subm3(mat3_t a, mat3_t b)
{
  mat3_t r;
  r.rows[0] = sub3(a.rows[0], b.rows[0]);
  r.rows[1] = sub3(a.rows[1], b.rows[1]);
  r.rows[2] = sub3(a.rows[2], b.rows[2]);
  return r;
}


/**
 * Multiplication of two matrix 3x3
 */
__vmath__ mat3_t mulm3(mat3_t a, mat3_t b)
{
  mat3_t r = {
    a.m00 * b.m00 + a.m10 * b.m01 + a.m20 * b.m02,
    a.m01 * b.m00 + a.m11 * b.m01 + a.m21 * b.m02,
    a.m02 * b.m00 + a.m12 * b.m01 + a.m22 * b.m02,

    a.m00 * b.m10 + a.m10 * b.m11 + a.m20 * b.m12,
    a.m01 * b.m10 + a.m11 * b.m11 + a.m21 * b.m12,
    a.m02 * b.m10 + a.m12 * b.m11 + a.m22 * b.m12,
      
    a.m00 * b.m20 + a.m10 * b.m21 + a.m20 * b.m22,
    a.m01 * b.m20 + a.m11 * b.m21 + a.m21 * b.m22,
    a.m02 * b.m20 + a.m12 * b.m21 + a.m22 * b.m22,
  };
  return r;
}


/**
 * Compare if two matrices is equal or not
 * @return: true is equal, false otherwise
 */
__vmath__ bool eqlm3(mat3_t a, mat3_t b)
{
  return
    eql3(a.rows[0], b.rows[0]) &&
    eql3(a.rows[1], b.rows[1]) &&
    eql3(a.rows[2], b.rows[2]);
}


/**
 * Calculate determinant of a matrix3x3
 */
__vmath__ float determinant3(mat3_t m)
{
  return 
      m.m00 * m.m11 * m.m22 - m.m00 * m.m12 * m.m21
    + m.m01 * m.m10 * m.m22 - m.m01 * m.m12 * m.m20
    + m.m02 * m.m10 * m.m21 - m.m02 * m.m11 * m.m20;
}


/**
 * Get inverted version of a matrix3x3
 */
__vmath__ mat3_t inverse3(mat3_t m)
{
  float d = determinant3(m);
  if (d == 0.0f) {
    return m;
  }
  d = 1.0f / d;
  mat3_t r = {
    d * (m.m11 * m.m22 - m.m12 * m.m21),
    d * (m.m02 * m.m21 - m.m01 * m.m22),
    d * (m.m01 * m.m12 - m.m02 * m.m11),

    d * (m.m12 * m.m20 - m.m10 * m.m22),
    d * (m.m00 * m.m22 - m.m02 * m.m20),
    d * (m.m02 * m.m10 - m.m00 * m.m12),

    d * (m.m10 * m.m21 - m.m11 * m.m20),
    d * (m.m01 * m.m20 - m.m00 * m.m21),
    d * (m.m00 * m.m11 - m.m01 * m.m10), 
  };
  return r;
}
