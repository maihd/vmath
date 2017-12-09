/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */

#ifndef __VMATH_H__
#define __VMATH_H__

#define VMATH_LIBNAME "libvmath"
#define VMATH_VERSION "v1.0.4"

/**
 * Custom modifier
 */
#if !defined(__cplusplus) 
# ifdef __GNUC__ /* GCC with strict-ansi */
#  define __vmath_inline__ __inline__
# else /* Windows MSVC */
#  define __vmath_inline__ __inline
# endif
#else
# define __vmath_inline__ inline
#endif

#ifdef __GNUC__ /* GCC */
# define __vmath_attr__ __attribute__((nothrow, pure, const))
#else /* Windows MSVC */
# define __vmath_attr__ __forceinline __nothrow
#endif
#define __vmath__ __vmath_attr__ static __vmath_inline__


/**
 * Include dependencies
 */
#include <math.h>
#include <float.h>
#include <limits.h>
#include <stdint.h>


/**
 * ARM NEON support checking
 */
#if defined(__ARM_NEON) || defined(__ARM_NEON__)
# include <arm_neon.h>
# ifndef VMATH_NEON_ENABLE
#  define VMATH_NEON_ENABLE 1
# endif
#else
# undef VMATH_NEON_ENABLE
#endif

/**
 * SSE support checking
 */
#if defined(__SSSE3__)
# define VMATH_SSE_SUPPORT
#endif
#if defined(__SSE__) || defined(__SSE2__) || defined(__SSE3__)
# define VMATH_SSE_SUPPORT
#endif
#if defined(__SSE4_1__) || defined(__SSE4_2__) || defined(__SSE_VMATH__)
# define VMATH_SSE_SUPPORT
#endif
#if _MSC_VER && (defined(_M_IX86) || defined(_M_IX64))
# if defined(_M_HYBRID_X86_ARM64)
#  undef VMATH_SSE_SUPPORT
# else
#  define VMATH_SSE_SUPPORT
# endif
#endif

#ifdef VMATH_SSE_SUPPORT
# include <mmintrin.h>
# include <smmintrin.h>
//# include <xmmintrin.h>
//# include <emmintrin.h>
# ifndef VMATH_SSE_ENABLE
#  define VMATH_SSE_ENABLE 1
# endif
#else
# undef VMATH_SSE_ENABLE
#endif


/**
 * Boolean type support
 */
#if !defined(__cplusplus) && !defined(bool)
# define bool unsigned char
#endif
#if !defined(__cplusplus) && !defined(true)
# define true 1
#endif
#if !defined(__cplusplus) && !defined(false)
# define false 0
#endif


/**
 * Include modules
 */

#ifdef __cplusplus
extern "C" {
#endif

#if __GNUC__
# pragma GCC diagnostic ignored "-Wmissing-braces"
#elif __clang__
# pragma clang diagnostic ignored "-Wmissing-braces"
#else
# pragma warning(disable : 4141)
#endif

/********
 * @region: Data types definitions
 ********/
#if VMATH_NEON_ENABLE
typedef float32x2_t float2;
typedef float32x4_t float3;
typedef float32x4_t float4;
#elif VMATH_SSE_ENABLE
typedef __m64       float2;
typedef __m128      float3;
typedef __m128      float4;
static const __m128 VMATH_SIGN_MASK = _mm_set1_epi32(0x80000000);
#else
typedef float       float2[2];
typedef float       float3[3];
typedef float       float4[4];
#endif


/**
 * Vector2D data structure
 */
typedef union __vmath_vec2__
{
    struct
    {
	float x, y;
    };
    float2 data;
} vec2_t;


/**
 * Vector3D data structures definition
 * It's also defined some handler for get Vector2D from its
 * @note: In SIMD enable, sizeof(vec3_t) == 4 * sizeof(float)
 *        instead sizeof(vec3_t) == 3 * sizeof(float)
 */
typedef union __vmath_vec3__
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
    vec2_t xy;
    float3 data;
} vec3_t;


/**
 * Vector4D data structure
 * @note: 'yzw' member is rarely use, 
 *        and it is impossile to provide in SIMD enable
 */
typedef union __vmath_vec4__
{
    struct
    {
	float x, y, z, w;
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
    vec3_t xyz;
    float3 data;
} vec4_t, quat_t;


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
    float  m[3][3];
    float  data[9];
} mat3_t;


/**
 * Matrix4x4 data structure
 */
typedef union __vmath_mat4__
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
/********
 * @endregion: Data types definitions
 ********/


/********
 * @region: Contants define
 ********/
static const vec2_t VEC2_ZERO  = {  0,  0 };
static const vec2_t VEC2_UNIT  = {  1,  1 };
static const vec2_t VEC2_UNITX = {  1,  1 };
static const vec2_t VEC2_UNITY = {  0,  1 };
static const vec2_t VEC2_LEFT  = { -1,  0 };
static const vec2_t VEC2_RIGHT = {  1,  0 };
static const vec2_t VEC2_UP    = {  0,  1 };
static const vec2_t VEC2_DOWN  = {  0, -1 };

static const vec3_t VEC3_ZERO  = {  0,  0,  0 };
static const vec3_t VEC3_UNIT  = {  1,  1,  1 };
static const vec3_t VEC3_UNITX = {  1,  0,  0 };
static const vec3_t VEC3_UNITY = {  0,  1,  0 };
static const vec3_t VEC3_UNITZ = {  0,  0,  1 };
static const vec3_t VEC3_LEFT  = { -1,  0,  0 };
static const vec3_t VEC3_RIGHT = {  1,  0,  0 };
static const vec3_t VEC3_UP    = {  0,  1,  0 };
static const vec3_t VEC3_DOWN  = {  0, -1,  0 };
static const vec3_t VEC3_BACK  = {  0,  0, -1 };
static const vec3_t VEC3_FORE  = {  0,  0,  1 };

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

static const mat3_t MAT3_IDENTITY = {
    1, 0, 0,
    0, 1, 0,
    0, 0, 1,
};

static const mat4_t MAT4_IDENTITY = {
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1,
};

static const quat_t QUAT_IDENTITY = { 0, 0, 0, 1 }; 
/********
 * @endregion: Contants define
 ********/   


/********
 * @region: Functions define
 ********/

/**
 * Create vector2d
 */
__vmath__ vec2_t vec2(float x, float y)
{
    vec2_t v = { x, y };
    return v;
}


/**
 * Addition of two vector2d
 */
__vmath__ vec2_t add2(vec2_t a, vec2_t b)
{
#if VMATH_NEON_ENABLE
    return (vec2_t){ .data = vadd_f32(a.data, b.data) };
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
    return (vec2_t){ .data = vsub_s32(a.data, b.data) };
#else
    return vec2(a.x - b.x, a.y - b.y);
#endif
}


/**
 * Multiply of a vector2d with a scalar
 */
__vmath__ vec2_t mul2(vec2_t v, float s)
{
#if VMATH_NEON_ENABLE
    return (vec2_t){ .data = vmul_n_f32(v.data, s) };
#else
    return vec2(v.x * s, v.y * s);
#endif
}


/**
 * Division of a vector2d with a scalar
 */
__vmath__ vec2_t div2(vec2_t v, float s)
{
    return mul2(v, 1.0f / s);
}


/**
 * Compare two vector2d is equal or not
 */
__vmath__ bool   eql2(vec2_t a, vec2_t b)
{
#if 0 && VMATH_NEON_ENABLE
    return sub2(a, b).pure == VEC2_ZERO.pure;
#elif 0 && VMATH_SSE_ENABLE
    return sub2(a, b).pure == VEC2_ZERO.pure;
#else
    return a.x == b.x && a.y == b.y;
#endif
}


/**
 * Create a negative vector
 */
__vmath__ vec2_t neg2(vec2_t v)
{
#if VMATH_NEON_ENABLE
    return (vec2_t){ .data = vneg_f32(v.data) };
#else
    return vec2(-v.x, -v.y);
#endif
}


/**
 * Dot product of two vector 2d
 */
__vmath__ float  dot2(vec2_t a, vec2_t b)
{
#if VMATH_NEON_ENABLE
    vec2_t v = (vec2_t){ .data = vmul_f32(a.data, b.data) };
    return v.x + v.y;
#else
    return a.x * b.x + a.y * b.y;
#endif
}


/**
 * Squared length of vector 2d
 */
__vmath__ float  lensqr2(vec2_t v)
{
#if VMATH_NEON_ENABLE
    vec2_t r = (vec2_t){ .data = vmul_f32(v.data, v.data) };
    return r.x + r.y;
#else
    return v.x * v.x + v.y * v.y;
#endif
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
 * Get normalized Vector2D, force direction only and unit length
 */
__vmath__ vec2_t normal2(vec2_t v)
{
    const float lsqr = lensqr2(v);
    if (lsqr != 1.0f && lsqr > 0) {
	const float l = 1.0f / sqrtf(lsqr);
	return vec2(v.x * l, v.y * l);
    }
    return v;
}


/**
 * Create a Vector3D
 */
__vmath__ vec3_t vec3(float x, float y, float z)
{
    vec3_t v = { x, y, z };
    return v;
}


/**
 * Addition of two vector 3d
 */
__vmath__ vec3_t add3(vec3_t a, vec3_t b)
{
#if VMATH_NEON_ENABLE
    return (vec3_t){ .data = vaddq_f32(a.data, b.data) };
#elif VMATH_SSE_ENABLE
    vec3_t r;
    r.data = _mm_add_ps(a.data, b.data);
    return r;
#else
    return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
#endif
}


/**
 * subtraction of two vector 3d
 */
__vmath__ vec3_t sub3(vec3_t a, vec3_t b)
{
#if VMATH_NEON_ENABLE
    return (vec3_t){ .data = vsubq_f32(a.data, b.data) };
#elif VMATH_SSE_ENABLE
    vec3_t r;
    r.data = _mm_sub_ps(a.data, b.data);
    return r;
#else
    return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
#endif
}


/**
 * Multiply of a vector 3d with a scalar, also called as scale
 */
__vmath__ vec3_t mul3(vec3_t v, float s)
{
#if VMATH_NEON_ENABLE
    return (vec3_t){ .data = vmulq_n_f32(v.data, s) };
#elif VMATH_SSE_ENABLE
    vec3_t r;
    r.data = _mm_mul_ps(v.data, _mm_set1_ps(s));
    return r;
#else
    return vec3(v.x * s, v.y * s, v.z * s);
#endif
}


/**
 * Division of a vector 3d with a scalar, also called as scale down 
 */
__vmath__ vec3_t div3(vec3_t v, float s)
{
    return mul3(v, 1.0f / s);
}


/**
 * Compare two vector3d is equal or not
 */
__vmath__ bool   eql3(vec3_t a, vec3_t b)
{
#if VMATH_SSE_ENABLE
    return ((_mm_movemask_ps(_mm_cmpeq_ps(a.data, b.data))) & 0x7) == 0x7;
#else
    return eql2(a.xy, b.xy) && a.z == b.z;
#endif
}


/**
 * Negative version of a Vector3D
 */
__vmath__ vec3_t neg3(vec3_t v)
{
#if VMATH_NEON_ENABLE
    return (vec3_t){ .data = vnegq_f32(v.data) };
#elif VMATH_SSE_ENABLE
    vec3_t r;
    r.data = _mm_xor_ps(v.data, VMATH_SIGN_MASK);
    return r;
#else
    return vec3(-v.x, -v.y, -v.z);
#endif
}


/**
 * Dot product of two vector 3d
 */
__vmath__ float dot3(vec3_t a, vec3_t b)
{
#if VMATH_SSE_ENABLE
    return _mm_cvtss_f32(_mm_sqrt_ss(_mm_dp_ps(a.data, b.data, 0x71)));
#else
    return a.x * b.x + a.y * b.y + a.z * b.z;
#endif
}


/**
 * Cross product of two vector 3d
 */
__vmath__ vec3_t cross3(vec3_t a, vec3_t b)
{
#if VMATH_SSE_ENABLE
    vec3_t r;
    r.data = _mm_sub_ps(
	_mm_mul_ps(_mm_shuffle_ps(a.data, a.data, _MM_SHUFFLE(3, 0, 2, 1)),
		   _mm_shuffle_ps(b.data, b.data, _MM_SHUFFLE(3, 1, 0, 2))),
	_mm_mul_ps(_mm_shuffle_ps(a.data, a.data, _MM_SHUFFLE(3, 1, 0, 2)),
		   _mm_shuffle_ps(b.data, b.data, _MM_SHUFFLE(3, 0, 2, 1)))
	);
    return r;
#else
    return vec3(a.y * b.z - a.z * b.y,					
		a.z * b.x - a.x * b.z,		
		a.x * b.y - a.y * b.x);
#endif
}


/**
 * Squared length of vector 3d
 */
__vmath__ float lensqr3(vec3_t v)
{
#if VMATH_SSE_ENABLE
    return _mm_cvtss_f32(_mm_dp_ps(v.data, v.data, 0x71));
#else
    return lensqr2(v.xy) + v.z * v.z;
#endif
}


/**
 * Length of vector 3d
 */
__vmath__ float len3(vec3_t v)
{
#if VMATH_SSE_ENABLE
    return _mm_cvtss_f32(_mm_sqrt_ss(_mm_dp_ps(v.data, v.data, 0x71)));
#else
    return sqrtf(lensqr3(v));
#endif
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
 * Get normalized vector3D (force to direction only, unit length)
 */
__vmath__ vec3_t normal3(vec3_t v)
{
#if VMATH_SSE_ENABLE
    vec3_t r;
    r.data = _mm_div_ps(v.data,
			_mm_sqrt_ps(_mm_dp_ps(v.data, v.data, 0xff)));
    return r;
#else
    const float lsqr = lensqr3(v);
    if (lsqr != 1.0f && lsqr > 0) {
	const float l = 1.0f / sqrtf(lsqr);
	return vec3(v.x * l, v.y * l, v.z * l);
    }
    return v;
#endif
}


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
    return (vec4_t){ .data = vaddq_f32(a.data, b.data) };
#elif VMATH_SSE_ENABLE
    vec4_t r;
    r.data = _mm_add_ps(a.data, b.data);
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
    return (vec4_t){ .data = vsubq_f32(a.data, b.data) };
#elif VMATH_SSE_ENABLE
    vec4_t r;
    r.data = _mm_sub_ps(a.data, b.data);
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
    return (vec4_t){ .data = vmulq_n_f32(v.data, s) };
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
    return eql2(a.xy, b.xy) && eql2(a.zw, b.zw);
#elif VMATH_SSE_ENABLE
    return (_mm_movemask_ps(_mm_cmpeq_ps(a.data, b.data)) & 7) == 7;
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
    return (vec4_t){ .data = vnegq_f32(v.data) };
#elif VMATH_SSE_ENABLE
    vec4_t r;
    r.data = _mm_xor_ps(v.data, VMATH_SIGN_MASK);
    return r;
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
    vec4_t v = (vec4_t){ .data = vmulq_f32(a.data, b.data) };
    return v.x + v.y + v.z + v.w;
#elif VMATH_SSE_ENABLE
    vec4_t v;
    v.data = _mm_mul_ps(a.data, b.data);
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
    vec4_t r = (vec4_t){ .data = vmulq_f32(v.data, v.data) };
    return r.x + r.y + r.z + r.w;
#elif VMATH_SSE_ENABLE
    vec4_t r;
    r.data = _mm_mul_ps(v.data, v.data);
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
 * Get normalized Vector4D, force direction only with unit length
 */
__vmath__ vec4_t normal4(vec4_t v)
{
    const float lsqr = lensqr4(v);
    if (lsqr != 1.0f && lsqr > 0) {
	const float l = 1.0f / sqrtf(lsqr);
	return vec4(v.x * l, v.y * l, v.z * l, v.w * l);
    }
    return v;
}


/**
 * Create quaternion
 * @return: Created quaternion
 */
__vmath__ quat_t quat(float x, float y, float z, float w)
{
    return vec4(x, y, z, w);
}


/**
 * Create a quaternion with euler coordinate
 * @return: result quaternion
 */
__vmath__ quat_t euler(float y, float p, float r)
{
    y *= 0.5f;
    p *= 0.5f;
    r *= 0.5f;

    float c1 = cosf(y);
    float c2 = cosf(p);
    float c3 = cosf(r);
    float s1 = sinf(y);
    float s2 = sinf(p);
    float s3 = sinf(r);
    return quat(s1 * s2 * c3 + c1 * c2 * s3,
		s1 * c2 * c3 + c1 * s2 * s3,
		c1 * s2 * c3 - s1 * c2 * s3,
		c1 * c2 * c3 - s1 * s2 * s3);
}


/**
 * Create a quaternion with euler coordinate
 * @return: result quaternion
 */
__vmath__ quat_t eulerv3(vec3_t e)
{
    return euler(e.x, e.y, e.z);
}


/**
 * Convert to an axis-angle representation.
 * @return: a axis-angle representation store in vec4_t union
 */
__vmath__ vec4_t toaxis(quat_t quat)
{
    quat_t q = quat;
    if (fabsf(q.w) > 0) {
	q = normal4(quat);
    }
    vec4_t r;
    float den = sqrtf(1.0f - q.w * q.w);
    if (den > 0.0001f) {
	r.xyz = div3(r.xyz, den);
    } else {
	r.xyz = vec3(1, 0, 0);
    }
    r.w = 2.0f * cosf(q.w);
    return r;
}


/**
 * Convert axis-angle representation to quaternion 
 */
__vmath__ quat_t toquat(vec3_t axis, float angle)
{
    if (lensqr3(axis) == 0.0f) {
	return QUAT_IDENTITY;
    }

    quat_t r;
    r.xyz = mul3(normal3(axis), sinf(angle * 0.5f));
    r.w   = cosf(angle * 0.5f);
    return r;
}


/**
 * Get invert quaternion
 */
__vmath__ quat_t inverseq(quat_t q)
{
    return quat(q.x, q.y, q.z, -q.w);
}


/**
 * Get conjugate quaternion
 */
__vmath__ quat_t conjq(quat_t q)
{
    return quat(-q.x, -q.y, -q.z, q.w);
}


/**
 * Multiplication of two quaternions 
 */
__vmath__ quat_t mulq(quat_t a, quat_t b)
{
    quat_t r;
    r.xyz = add3(add3(mul3(a.xyz, b.w), mul3(b.xyz, a.w)),
		 cross3(a.xyz, b.xyz));
    r.w   = a.w * b.w - dot3(a.xyz, b.xyz);
    return r;
}


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
    mat3_t r = {
	a.m00 + b.m00, a.m10 + b.m10, a.m20 + b.m20,
	a.m01 + b.m01, a.m11 + b.m11, a.m21 + b.m21,
	a.m02 + b.m02, a.m12 + b.m12, a.m22 + b.m22,
    };
    return r;
}


/**
 * Subtraction of two matrix 3x3
 */
__vmath__ mat3_t subm3(mat3_t a, mat3_t b)
{
    mat3_t r = {
	a.m00 - b.m00, a.m10 - b.m10, a.m20 - b.m20,
	a.m01 - b.m01, a.m11 - b.m11, a.m21 - b.m21,
	a.m02 - b.m02, a.m12 - b.m12, a.m22 - b.m22,
    };
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
        a.m00 == b.m00 && a.m01 == b.m01 && a.m02 == b.m02 &&
	a.m10 == b.m10 && a.m11 == b.m11 && a.m12 == b.m12 &&
	a.m20 == b.m20 && a.m21 == b.m21 && a.m22 == b.m22;
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


/**
 * Apply transform (Matrix3x3) for Vector3D
 */
__vmath__ vec3_t transform3(mat3_t m, vec3_t v)
{
    const vec3_t c0 = vec3(m.m00, m.m10, m.m20);
    const vec3_t c1 = vec3(m.m01, m.m11, m.m21);
    const vec3_t c2 = vec3(m.m02, m.m12, m.m22);

    const float x = dot3(c0, v);
    const float y = dot3(c1, v);
    const float z = dot3(c2, v);
    return vec3(x, y, z);
}


/**
 * Create a identity matrix 4x4
 */
__vmath__ mat4_t mat4()
{
    return MAT4_IDENTITY;
}


/**
 *
 */
__vmath__ mat3_t tomat3(mat4_t m)
{
    mat3_t r = {
	m.m00, m.m01, m.m02,
	m.m20, m.m11, m.m12,
	m.m10, m.m21, m.m22,
    };
    return r;
}


/**
 *
 */
__vmath__ mat4_t tomat4(mat3_t m)
{
    mat4_t r = {
	m.m00, m.m01, m.m02, 0,
	m.m20, m.m11, m.m12, 0,
	m.m10, m.m21, m.m22, 0,
        0,     0,     0, 0,
    };
    return r;
}


/**
 * Create translate matrix
 */
__vmath__ mat4_t translate3f(float x, float y, float z)
{				
    mat4_t r = {
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	x, y, z, 1,
    };
    return r;
}


__vmath__ mat4_t translate2f(float x, float y)
{
    return translate3f(x, y, 0);
}


__vmath__ mat4_t translatev2(vec2_t v)
{
    return translate3f(v.x, v.y, 0.0);
}


__vmath__ mat4_t translatev3(vec3_t v)
{
    return translate3f(v.x, v.y, v.z);
}


/**
 * Create scale matrix
 */
__vmath__ mat4_t scale3f(float x, float y, float z)
{
    mat4_t r = {
	x, 0, 0, 0,
	0, y, 0, 0,
	0, 0, z, 0,
	0, 0, 0, 1,
    };
    return r;
}


__vmath__ mat4_t scale1f(float s)
{
    return scale3f(s, s, s);
}


__vmath__ mat4_t scale2f(float x, float y)
{
    return scale3f(x, y, 1.0);
}


__vmath__ mat4_t scalev2(vec2_t v)
{
    return scale3f(v.x, v.y, 1.0);
}


__vmath__ mat4_t scalev3(vec3_t v)
{
    return scale3f(v.x, v.y, v.z);
}

/**
 * Create mat4 rotate in X-axis matrix
 */
__vmath__ mat4_t rotatex(float angle)
{
    const float c = cosf(angle);
    const float s = sinf(angle);
    mat4_t r = {
	1,  0, 0, 0,
	0,  c, s, 0,
	0, -s, c, 0,
	0,  0, 0, 1,
    };
    return r;
}


/**
 * Create mat4 rotate in Y-axis matrix
 */
__vmath__ mat4_t rotatey(float angle)
{
    const float c = cosf(angle);
    const float s = sinf(angle);
    mat4_t r = {
	 c, 0, s, 0,
	 0, 1, 0, 0,
	-s, 0, c, 0,
	 0, 0, 0, 1,
    };
    return r;
}


/**
 * Create mat4 rotate in Z-axis matrix
 */
__vmath__ mat4_t rotatez(float angle)
{
    const float c = cosf(angle);
    const float s = sinf(angle);
    mat4_t r = {
	 c, s, 0, 0,
	-s, c, 0, 0,
	 0, 0, 1, 0,
	 0, 0, 0, 1,
    };
    return r;
}


/**
 * Create mat4 rotate matrix
 */
__vmath__ mat4_t rotate3f(float x, float y, float z, float angle)
{
    const float c = cosf(-angle);
    const float s = sinf(-angle);
    const float t = 1.0f - c;
  
    mat4_t r = {
	/* Row 1
	 */
	t * x * x + c,
	t * x * y - s * z,
	t * x * z + s * y,
	0.0f,

	/* Row 2
	 */
	t * x * y + s * z,
	t * y * y + c,
	t * y * z - s * x,
	0.0f,

	/* Row 3
	 */
	t * x * z - s * y,
	t * y * z + s * x,
	t * z * z + c,
	0.0f,

	/* Row 4
	 */
	0, 0, 0, 1.0f,
    };
    return r;
}


/**
 * Create rotate matrix with axis and angle
 */
__vmath__ mat4_t rotatev3(vec3_t v, float angle)
{
    return rotate3f(v.x, v.y, v.z, angle);
}


/**
 * Create rotation matrix from quaternion
 */
__vmath__ mat4_t rotateq(quat_t q)
{
    const vec4_t aa = toaxis(q); /* axis-angle form of quaternion */
    return rotatev3(aa.xyz, aa.w);
}


/**
 * Addidtion of two matrix4x4
 */
__vmath__ mat4_t addm4(mat4_t a, mat4_t b)
{
    mat4_t r;
    r.rows[0] = add4(a.rows[0], b.rows[0]);
    r.rows[1] = add4(a.rows[1], b.rows[1]);
    r.rows[2] = add4(a.rows[2], b.rows[2]);
    r.rows[3] = add4(a.rows[3], b.rows[3]);
    return r;
}


/**
 * Subtraction of two matrix4x4
 */
__vmath__ mat4_t subm4(mat4_t a, mat4_t b)
{
    mat4_t r;
    r.rows[0] = sub4(a.rows[0], b.rows[0]);
    r.rows[1] = sub4(a.rows[1], b.rows[1]);
    r.rows[2] = sub4(a.rows[2], b.rows[2]);
    r.rows[3] = sub4(a.rows[3], b.rows[3]);
    return r;
}


/**
 * Multiplication of two matrix4x4
 */
__vmath__ mat4_t mulm4(mat4_t a, mat4_t b)
{
    mat4_t r = {
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
    };
    return r;
}


/**
 * Compare if two matrix is equal or not
 * @return: true if equal, false otherwise
 */
__vmath__ bool eqlm4(mat4_t a, mat4_t b)
{
    return
	eql4(a.rows[0], b.rows[0]) &&
	eql4(a.rows[1], b.rows[1]) &&
	eql4(a.rows[2], b.rows[2]) &&
	eql4(a.rows[3], b.rows[3]);
}


/**
 * Transpose matrix4x4
 */
__vmath__ mat4_t transpose4(mat4_t m)
{
    mat4_t r = {
	m.m00, m.m10, m.m20, m.m30,
	m.m01, m.m11, m.m21, m.m31,
	m.m02, m.m12, m.m22, m.m32,
	m.m03, m.m13, m.m23, m.m33,
    };
    return r;
}


/**
 * Create orthographic projection matrix
 */
__vmath__ mat4_t ortho(float l, float r, float b, float t, float n, float f)
{
    mat4_t m = {
	2.0f / (r - l), 0, 0, 0,
	0, 2.0f / (t - b), 0, 0,
	0, 0, 2.0f / (f - n), 0,

	/* Row 4 */
	(l + r) / (l - r),
	(b + t) / (b - t),
	(n + f) / (n - f),
	1.0f,
    };
    return m;
}


/**
 * Create frustum matrix
 */
__vmath__ mat4_t frustum(float l, float r, float b, float t, float n, float f)
{
    mat4_t m = {
	/* Row 1 */
	2.0f / (r - l), 0, 0, 0,
	/* Row 2 */
	0, 2.0f / (t - b), 0, 0,
	/* Row 3 */
	(r + l) / (r - l),
	(t + b) / (t - b),
	(f + b) / (f - n), 1.0f,
	/* Row 4 */
	0, 0, 2.0f / (f - n), 0,
    };
    return m;
}


/**
 * Create perspective projection matrix
 */
__vmath__ mat4_t perspective(float fov, float aspect, float near, float far)
{
    const float a = 1.0f / tanf(fov * 0.5f);
    const float b = far / (near - far);
    mat4_t r = {
	a / aspect, 0, 0, 0,
	0, a, 0, 0,
	0, 0, b, -1,
	0, 0, near * b, 0,
    };
    return r;
}


/**
 * Create view matrix when focus on the position
 */
__vmath__ mat4_t lookat(vec3_t eye, vec3_t target, vec3_t up)
{
    const vec3_t z = normal3(sub3(eye, target));
    const vec3_t x = normal3(cross3(up, z));
    const vec3_t y = normal3(cross3(z, x));
    mat4_t r = {
	x.x, y.x, z.x, 0,
	x.y, y.y, z.y, 0,
	x.z, y.z, z.z, 0,
	-dot3(x, eye), -dot3(y, eye), -dot3(z, eye), 1.0f,
    };
    return r;
}


/**
 * Calculate deternimant value
 */
__vmath__ float determinant4(mat4_t m)
{
    const float s1 = m.m00 * m.m11 - m.m10 * m.m01;
    const float s2 = m.m00 * m.m12 - m.m10 * m.m02;
    const float s3 = m.m00 * m.m13 - m.m10 * m.m03;
    const float s4 = m.m01 * m.m12 - m.m11 * m.m02;
    const float s5 = m.m01 * m.m13 - m.m11 * m.m03;
    const float s6 = m.m02 * m.m13 - m.m12 * m.m03;
  
    const float c1 = m.m20 * m.m31 - m.m30 * m.m21;
    const float c2 = m.m20 * m.m32 - m.m30 * m.m22;
    const float c3 = m.m20 * m.m33 - m.m30 * m.m23;
    const float c4 = m.m21 * m.m32 - m.m31 * m.m22;
    const float c5 = m.m21 * m.m32 - m.m31 * m.m23;
    const float c6 = m.m22 * m.m33 - m.m32 * m.m23;

    return s1 * c6 - s2 * c5 + s3 * c4 + s4 * c3 - s5 * c2 + s6 * c1;
}


/**
 * Get inverse version of matrix4x4
 */
__vmath__ mat4_t inverse4(mat4_t m)
{
    const float s1 = m.m00 * m.m11 - m.m10 * m.m01;
    const float s2 = m.m00 * m.m12 - m.m10 * m.m02;
    const float s3 = m.m00 * m.m13 - m.m10 * m.m03;
    const float s4 = m.m01 * m.m12 - m.m11 * m.m02;
    const float s5 = m.m01 * m.m13 - m.m11 * m.m03;
    const float s6 = m.m02 * m.m13 - m.m12 * m.m03;
  
    const float c1 = m.m20 * m.m31 - m.m30 * m.m21;
    const float c2 = m.m20 * m.m32 - m.m30 * m.m22;
    const float c3 = m.m20 * m.m33 - m.m30 * m.m23;
    const float c4 = m.m21 * m.m32 - m.m31 * m.m22;
    const float c5 = m.m21 * m.m32 - m.m31 * m.m23;
    const float c6 = m.m22 * m.m33 - m.m32 * m.m23;
  
    float d = s1 * c6 - s2 * c5 + s3 * c4 + s4 * c3 - s5 * c2 + s6 * c1;
    if (d == 0.0f) {
	return m;
    }
    d = 1.0f / d;
  
    mat4_t r = {
	d *  (m.m11 * c6 - m.m12 * c5 + m.m13 * c4),
	d * -(m.m01 * c6 - m.m02 * c5 + m.m03 * c4),
	d *  (m.m31 * s6 - m.m32 * s5 + m.m33 * s4),
	d * -(m.m21 * s6 - m.m22 * s5 + m.m23 * s4),
      
	d * -(m.m10 * c6 - m.m12 * c3 + m.m13 * c2),
	d *  (m.m00 * c6 - m.m02 * c3 + m.m03 * c2),
	d * -(m.m30 * s6 - m.m32 * s3 + m.m33 * s2),
	d *  (m.m20 * s6 - m.m22 * s3 + m.m23 * s2),
      
	d *  (m.m10 * c5 - m.m11 * c3 + m.m13 * c1),
	d * -(m.m00 * c5 - m.m01 * c3 + m.m03 * c1),
	d *  (m.m30 * s5 - m.m31 * s3 + m.m33 * s1),
	d * -(m.m20 * s5 - m.m21 * s3 + m.m23 * s1),

	d * -(m.m10 * c4 - m.m11 * c2 + m.m12 * c1),
	d *  (m.m00 * c4 - m.m01 * c2 + m.m02 * c1),
	d * -(m.m30 * s4 - m.m31 * s2 + m.m32 * s1),
	d *  (m.m20 * s4 - m.m21 * s2 + m.m22 * s1),
    };
    return r;
}


/**
 * Apply transform (Matrix4x4) for Vector4D
 */
__vmath__ vec4_t transform4(mat4_t m, vec4_t v)
{
    const vec4_t c0 = vec4(m.m00, m.m10, m.m20, m.m30);
    const vec4_t c1 = vec4(m.m01, m.m11, m.m21, m.m31);
    const vec4_t c2 = vec4(m.m02, m.m12, m.m22, m.m32);
    const vec4_t c3 = vec4(m.m03, m.m13, m.m23, m.m33);

    const float x = dot4(c0, v);
    const float y = dot4(c1, v);
    const float z = dot4(c2, v);
    const float w = dot4(c3, v);
    return vec4(x, y, z, w);
}
/********
 * @endregion: Functions define
 ********/    

#ifdef __cplusplus
}
#endif

#endif /* __VMATH_H__ */
