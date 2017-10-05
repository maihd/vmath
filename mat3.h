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
typedef struct
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
#define MAT3_IDENTITY mat3()


/**
 * Create a identify matrix 3x3
 */
__vmath__ mat3_t mat3()
{
  return (mat3_t){
    .data = {
      1, 0, 0,
      0, 1, 0,
      0, 0, 1,
    }
  };
}


/**
 * Transpose matrix3x3
 */
__vmath__ mat3_t transpose3(mat3_t m)
{
  return (mat3_t){
    .data = {
      m.m00, m.m10, m.m20,
      m.m01, m.m11, m.m21,
      m.m02, m.m12, m.m22,
    }
  };
}


/**
 * Addition of two matrix 3x3
 */
__vmath__ mat3_t addm3(mat3_t a, mat3_t b)
{
  return (mat3_t){
    .rows = {
      add3(a.rows[0], b.rows[0]),
      add3(a.rows[1], b.rows[1]),
      add3(a.rows[2], b.rows[2]),
    }
  };
}


/**
 * Subtraction of two matrix 3x3
 */
__vmath__ mat3_t subm3(mat3_t a, mat3_t b)
{
  return (mat3_t){
    .rows = {
      sub3(a.rows[0], b.rows[0]),
      sub3(a.rows[1], b.rows[1]),
      sub3(a.rows[2], b.rows[2]),
    }
  };
}


/**
 * Multiplication of two matrix 3x3
 */
__vmath__ mat3_t mulm3(mat3_t a, mat3_t b)
{
  return (mat3_t){
    .data = {
      a.m00 * b.m00 + a.m10 * b.m01 + a.m20 * b.m02,
      a.m01 * b.m00 + a.m11 * b.m01 + a.m21 * b.m02,
      a.m02 * b.m00 + a.m12 * b.m01 + a.m22 * b.m02,

      a.m00 * b.m10 + a.m10 * b.m11 + a.m20 * b.m12,
      a.m01 * b.m10 + a.m11 * b.m11 + a.m21 * b.m12,
      a.m02 * b.m10 + a.m12 * b.m11 + a.m22 * b.m12,
      
      a.m00 * b.m20 + a.m10 * b.m21 + a.m20 * b.m22,
      a.m01 * b.m20 + a.m11 * b.m21 + a.m21 * b.m22,
      a.m02 * b.m20 + a.m12 * b.m21 + a.m22 * b.m22,
    }
  };
}
