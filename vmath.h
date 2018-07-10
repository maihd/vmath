/******************************************************
 * vmath - C/C++ vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017 - 2018
 ******************************************************/

#ifndef __VMATH_H__
#define __VMATH_H__

#define VMATH_LIBNAME "libvmath"
#define VMATH_VERSION "v1.1.2"
#define VMATH_VERCODE 10102 

/**
 * Include dependencies
 */
#include <math.h>
#include <float.h>
#include <limits.h> 

/**
 * Custom modifier
 */
#if !defined(__cplusplus)

# if   defined(__GNUC__) /* GCC with strict-ansi */
#  define __vmath_inline__ __inline__
# elif defined(_MSC_VER) /* Windows MSVC */
#  define __vmath_inline__ __inline
# else
#  define __vmath_inline__
# endif

# define __vmath_nothrow__ 

#else

# define __vmath_inline__ inline

# if   defined(__GNUC__)
#  define __vmath_nothrow__ __attribute((nothrow))
# elif defined(_MSC_VER) /* Windows MSVC */
#  define __vmath_nothrow__ __declspec(nothrow)
# else
#  define __vmath_nothrow__
# endif

#endif

#ifdef __GNUC__ /* GCC */
# define __vmath_attr__     __attribute__((always_inline)) __vmath_nothrow__
#else /* Windows MSVC */
# define __vmath_attr__     __forceinline __vmath_nothrow__
#endif
#define __vmath__ /*{space}*/ __vmath_attr__ static __vmath_inline__ 

#ifndef PI
#define PI 3.14159265358979f
#endif 

/**
 * Building configuration
 */
#ifndef VMATH_CONSTANTS
#define VMATH_CONSTANTS 1
#endif

#ifndef VMATH_BUILD_VEC2
#define VMATH_BUILD_VEC2 1
#endif

#ifndef VMATH_BUILD_VEC3
#define VMATH_BUILD_VEC3 1
#endif

#ifndef VMATH_BUILD_VEC4
#define VMATH_BUILD_VEC4 1
#endif

#ifndef VMATH_BUILD_QUAT
#define VMATH_BUILD_QUAT 1
#endif

#ifndef VMATH_BUILD_MAT2
#define VMATH_BUILD_MAT2 1
#endif

#ifndef VMATH_BUILD_MAT3
#define VMATH_BUILD_MAT3 1
#endif

#ifndef VMATH_BUILD_MAT4
#define VMATH_BUILD_MAT4 1
#endif

#ifndef VMATH_GLSL_LIKE
#define VMATH_GLSL_LIKE 1
#endif

#ifndef VMATH_OPERATOR_OVERLOADING
#define VMATH_OPERATOR_OVERLOADING 1
#endif

#ifndef VMATH_FUNCTION_OVERLOADING
#define VMATH_FUNCTION_OVERLOADING 1
#endif 

#if !VMATH_BUILD_VEC3 
# if VMATH_BUILD_QUAT
#  error "Quaternion module require Vector3D module"
# endif
# if VMATH_BUILD_MAT3     
#  error "Matrix3x3 module require Vector3D module"
# endif
# if VMATH_BUILD_MAT4 
#  error "Matrix4x4 module require Vector3D module"
# endif
#endif

#if !VMATH_BUILD_VEC4 
# if VMATH_BUILD_QUAT
#  error "Quaternion module require Vector4D module"
# endif
# if VMATH_BUILD_MAT4 
#  error "Matrix4x4 module require Vector4D module"
# endif
#endif

/**
 * ARM NEON support checking
 */
#if defined(__ARM_NEON) || defined(__ARM_NEON__)
# include <arm_neon.h>
# ifndef VMATH_NEON_ENABLE
#  define VMATH_NEON_ENABLE 1
# endif
#else
#  define VMATH_NEON_ENABLE 0
#endif

/**
 * SSE support checking
 */
#if defined(__SSSE3__)
# define VMATH_SSE_SUPPORT 1
#endif

#if defined(__SSE__) || defined(__SSE2__) || defined(__SSE3__)
# define VMATH_SSE_SUPPORT 1
#endif

#if defined(__SSE4_1__) || defined(__SSE4_2__) || defined(__SSE_MATH__)
# define VMATH_SSE_SUPPORT 1
#endif

#if defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_IX64))
# if defined(_M_HYBRID_X86_ARM64)
#  define VMATH_SSE_SUPPORT 0
# else
#  define VMATH_SSE_SUPPORT 1
# endif
#endif

#if VMATH_SSE_SUPPORT
# include <mmintrin.h>
# include <smmintrin.h>
//# include <xmmintrin.h>
//# include <emmintrin.h>
# ifndef VMATH_SSE_ENABLE
#  define VMATH_SSE_ENABLE 1
# endif
#else
#  define VMATH_SSE_ENABLE 0
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
 * Static assert support
 */
#include <assert.h>
#if !defined(__cplusplus) && !defined(static_assert)    
#define STATIC_ASSERT_CONCAT_IN(a, b)  a ## b
#define STATIC_ASSERT_CONCAT(a, b)     STATIC_ASSERT_CONCAT_IN(a, b)
#define STATIC_ASSERT_GENSYM()         STATIC_ASSERT_CONCAT(__SA, __LINE__)
#define static_assert(exp, msg) struct STATIC_ASSERT_GENSYM() { char test[(exp) ? 0 : -1]; }
#endif

/**
 * Turn off annoy warning
 */
#if __GNUC__
# pragma GCC   diagnostic ignored "-Wmissing-braces"
#elif __clang__
# pragma clang diagnostic ignored "-Wmissing-braces"
#else
# pragma warning(disable : 4141) /* Shutup announce missing braces warning */
# pragma warning(disable : 4201) /* Shutup announce anonymous union warning */
#endif

/********
 * @region: Data types definitions
 ********/
#if VMATH_NEON_ENABLE
typedef float32x2_t float2_t;
typedef float32x4_t float3_t;
typedef float32x4_t float4_t;
#elif VMATH_SSE_ENABLE
typedef __m64       float2_t;
typedef __m128      float3_t;
typedef __m128      float4_t;
static const __m128 __M128_ZERO = { 0, 0, 0, 0 };
#else
typedef float       float2_t[2];
typedef float       float3_t[3];
typedef float       float4_t[4];
#endif

/**
 * Vector2D data structure
 */
typedef union vmath_vec2
{
    struct
    {
        float x, y;
    };
    
    float    m[2];
    float2_t data;
} vec2_t;

/**
 * Vector3D data structures definition
 * It's also defined some handler for get Vector2D from its
 * @note: In SIMD enable, sizeof(vec3_t) == 4 * sizeof(float)
 *        instead sizeof(vec3_t) == 3 * sizeof(float)
 */                 
typedef union vmath_vec3
{
    struct
    {
        float x, y, z;
    };

    struct
    {
        float  __;
        vec2_t yz;
    };

    vec2_t   xy;
    float    m[3];
    float3_t data;
} vec3_t;

/**
 * Vector4D data structure
 * @note: 'vec3_t yzw' member is rarely use, 
 *        and it is impossile to provide in vec3_t SIMD enable
 */
typedef union vmath_vec4
{
    struct
    {
        float x, y, z, w;
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
        float  __;
        vec2_t yz;
    };

    vec3_t   xyz;
    vec3_t   rgb;
    float    m[4];
    float4_t data;
} vec4_t;

/**
 * Quaternion data structure
 *
 * @hint: to convert to vec4_t, just get the 'vec4' member
 */
typedef union vmath_quat
{
    struct
    {
        float x, y, z, w;
    }; 
    vec4_t   vec4;

    float    m[4];
    float4_t data;
} quat_t;

/**
 * Matrix 2x2 data structure
 */
typedef union vmath_mat2
{
    struct
    {
        float m00, m01;
        float m10, m11;
    };
    vec4_t vec4;
    vec2_t rows[2];
    float  m[2][2];
    float  data[4];
} mat2_t;

/**
 * Matrix3x3 data structure
 */
typedef union vmath_mat3
{
    struct
    {
        float m00, m01, m02;
        float m10, m11, m12;
        float m20, m21, m22;
    };
    float m[3][3];
    float data[9];
} mat3_t;

/**
 * Matrix4x4 data structure
 */
typedef union vmath_mat4
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

static_assert(sizeof(vec2_t) == sizeof(float2_t)  , "Size of vec2_t is not valid");
static_assert(sizeof(vec3_t) == sizeof(float3_t)  , "Size of vec3_t is not valid");
static_assert(sizeof(vec4_t) == sizeof(float4_t)  , "Size of vec3_t is not valid");
static_assert(sizeof(quat_t) == sizeof(float4_t)  , "Size of quat_t is not valid");
static_assert(sizeof(mat2_t) == 4  * sizeof(float), "Size of mat2_t is not valid");
static_assert(sizeof(mat3_t) == 9  * sizeof(float), "Size of mat3_t is not valid");
static_assert(sizeof(mat4_t) == 16 * sizeof(float), "Size of mat4_t is not valid");

#if defined(__cplusplus)
typedef const vec2_t& vec2_arg_t;
typedef const vec2_t& vec2_arg_t;
typedef const vec3_t& vec3_arg_t;
typedef const vec4_t& vec4_arg_t;
typedef const quat_t& quat_arg_t;
typedef const mat2_t& mat2_arg_t;
typedef const mat3_t& mat3_arg_t;
typedef const mat4_t& mat4_arg_t;
#else
typedef vec2_t        vec2_arg_t;
typedef vec3_t        vec3_arg_t;
typedef vec4_t        vec4_arg_t;
typedef quat_t        quat_arg_t;
typedef mat2_t        mat2_arg_t;
typedef mat3_t        mat3_arg_t;
typedef mat4_t        mat4_arg_t;
#endif

/********
 * @endregion: Data types definitions
 ********/


/********************
 * Contants define
 ********************/
#if VMATH_CONSTANTS

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

static const quat_t QUAT_ZERO     = { 0, 0, 0, 0 };
static const quat_t QUAT_IDENTITY = { 0, 0, 0, 1 };

static const mat2_t MAT2_ZERO     = { 1, 0, 0, 1 };
static const mat2_t MAT2_IDENTITY = { 1, 0, 0, 1 };

static const mat3_t MAT3_ZERO     = {
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
};
static const mat3_t MAT3_IDENTITY = {
    1, 0, 0,
    0, 1, 0,
    0, 0, 1,
};

static const mat4_t MAT4_ZERO     = {
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};
static const mat4_t MAT4_IDENTITY = {
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1,
};

/* END OF VMATH_CONSTANTS */
#endif

#ifndef VMATH_FAST_MATH
#define VMATH_FAST_MATH 1
#endif

#if (VMATH_FAST_MATH != 0)
/**
* Fast inverse square root
*/
__vmath__ float vmath_rsqrt(float x)
{
    union
    {
        float x;
        long  i;
    } cvt; /* converter */

    cvt.x = x;
    cvt.i = 0x5F3759DF - (cvt.i >> 1);
    cvt.x = cvt.x * (1.5f - 0.5f * x * cvt.x * cvt.x);
    return cvt.x;
}

/**
* Fast square root
*/
__vmath__ float vmath_fsqrt(float x)
{
    return x == 0.0f ? 0.0f : 1.0f / vmath_rsqrt(x);
}
#else
# ifndef vmath_rsqrt
# define vmath_rsqrt(x) (1.0f / sqrtf(x))
# endif
# ifndef vmath_fsqrt
# define vmath_fsqrt(x) sqrtf(x)
# endif
#endif

/*****************************
 * @region: Constructors
 *****************************/
#if defined(__cplusplus) && VMATH_GLSL_LIKE

#if defined(_MSC_VER)
# define __vmath_ctor__ /*{space}*/ __vmath_attr__ __vmath_inline__ 
# define __vmath_mthd__ /*{space}*/ __vmath_attr__ __vmath_inline__
#else
# define __vmath_ctor__ /*{space}*/ __attribute__((always_inline)) __vmath_nothrow__ __vmath_inline__ 
# define __vmath_mthd__ /*{space}*/ __attribute__((always_inline)) __vmath_nothrow__ __vmath_inline__
#endif

#define __vmath_vec2_property(_1, _2)                       \
    union {                                                 \
    private:                                                \
        struct                                              \
        {                                                   \
            float x;                                        \
            float y;                                        \
        };                                                  \
                                                            \
    public:                                                 \
        __vmath_mthd__ vec2 operator=(const vec2& other)    \
        {                                                   \
            _1 = other.x;                                   \
            _2 = other.y;                                   \
            return vec2(_1, _2);                            \
        }                                                   \
                                                            \
        __vmath_mthd__ operator vec2() const                \
        {                                                   \
            return vec2(_1, _2);                            \
        }                                                   \
    }                                                        
#define __vmath_vec3_property2(_1, _2)                      \
    union {                                                 \
    private:                                                \
        struct { float x; float y; float z; };              \
    public:                                                 \
        __vmath_mthd__ vec2 operator=(const vec2& other)    \
        {                                                   \
            _1 = other.x;                                   \
            _2 = other.y;                                   \
            return vec2(_1, _2);                            \
        }                                                   \
                                                            \
        __vmath_mthd__ operator vec2() const                \
        {                                                   \
            return vec2(_1, _2);                            \
        }                                                   \
    }                         

#define __vmath_vec3_property3(_1, _2, _3)                  \
    union {                                                 \
    private:                                                \
        struct { float x; float y; float z; };              \
    public:                                                 \
        __vmath_mthd__ vec3 operator=(const vec3& other)    \
        {                                                   \
            _1 = other.x;                                   \
            _2 = other.y;                                   \
            _3 = other.z;                                   \
            return vec3(_1, _2, _3);                        \
        }                                                   \
                                                            \
        __vmath_mthd__ operator vec3() const                \
        {                                                   \
            return vec3(_1, _2, _3);                        \
        }                                                   \
    }                                

#define __vmath_vec4_property2(_1, _2)                      \
    union {                                                 \
    private:                                                \
        struct { float x; float y; float z; float w;};      \
    public:                                                 \
        __vmath_mthd__ vec2 operator=(const vec2& other)    \
        {                                                   \
            _1 = other.x;                                   \
            _2 = other.y;                                   \
            return vec2(_1, _2);                            \
        }                                                   \
                                                            \
        __vmath_mthd__ operator vec2() const                \
        {                                                   \
            return vec2(_1, _2);                            \
        }                                                   \
    }

#define __vmath_vec4_property3(_1, _2, _3)                  \
    union  {                                                \
    private:                                                \
        struct { float x; float y; float z; float w;};      \
    public:                                                 \
        __vmath_mthd__ vec3 operator=(const vec3& other)    \
        {                                                   \
            _1 = other.x;                                   \
            _2 = other.y;                                   \
            _3 = other.z;                                   \
            return vec3(_1, _2, _3);                        \
        }                                                   \
                                                            \
        __vmath_mthd__ operator vec3() const                \
        {                                                   \
            return vec3(_1, _2, _3);                        \
        }                                                   \
    }

#define __vmath_vec4_property4(_1, _2, _3, _4)              \
    union  {                                                \
    private:                                                \
        struct { float x; float y; float z; float w;};      \
    public:                                                 \
        __vmath_mthd__ vec4 operator=(const vec4& other)    \
        {                                                   \
            _1 = other.x;                                   \
            _2 = other.y;                                   \
            _3 = other.z;                                   \
            _4 = other.w;                                   \
            return vec4(_1, _2, _3, _4);                    \
        }                                                   \
                                                            \
        __vmath_mthd__ operator vec4() const                \
        {                                                   \
            return vec4(_1, _2, _3, _4);                    \
        }                                                   \
    }


union vec2 
{
public: /* Fields */
    struct { float x, y; };

public: /* Constructor */
    __vmath_ctor__ vec2(void)             : vec2(0, 0) {}
    __vmath_ctor__ vec2(float x, float y) { this->x = x; this->y = y; }

    __vmath_ctor__ vec2(const vec2_t& v) : pure(v) {}
    __vmath_ctor__ operator       vec2_t&()       { return pure; }
    __vmath_ctor__ operator const vec2_t&() const { return pure; }

    __vmath_ctor__ explicit vec2(float s)         : vec2(s, s)       {}
    __vmath_ctor__ explicit vec2(const float* s)  : vec2(s[0], s[1]) {}
    __vmath_ctor__ explicit vec2(const vec3_t& v) : vec2(v.x, v.y)   {}
    __vmath_ctor__ explicit vec2(const vec4_t& v) : vec2(v.x, v.y)   {}
    
public: /* Operator */
    __vmath_mthd__ vec2& operator=(const vec2_t& v)
    {
        pure = v;
        return *this;
    }

    __vmath_mthd__ float& operator[](int index)
    {
        assert(index >= 0 && index < 2);
        return ((float*)this)[index];
    }

    __vmath_mthd__ float operator[](int index) const
    {
        assert(index >= 0 && index < 2);
        return ((float*)this)[index];
    }

public: /* Properties */
    __vmath_vec2_property(y, x) yx;

private:
    vec2_t pure;
};

union vec3 
{
public: /* Fields */
    struct
    {
        float x, y, z;
    };
    struct
    {
        float r, g, b;
    };
    struct
    {
        vec2_t xy;
    };
    struct
    {
        float  __;
        vec2_t yz;
    };

public: /* Constructors */
    __vmath_ctor__ vec3(void)    : vec3(0, 0, 0) {}
    __vmath_ctor__ vec3(float x, float y, float z = 0.0f) : x(x), y(y), z(z) {}

    __vmath_ctor__ explicit vec3(float s)        : vec3(s, s, s)          {}
    __vmath_ctor__ explicit vec3(const float* s) : vec3(s[0], s[1], s[2]) {}

    __vmath_ctor__ explicit vec3(const vec2_t& v, float z = 0.0f) : vec3(v.x, v.y, z)   {}
    __vmath_ctor__ explicit vec3(const vec4_t& v)                 : vec3(v.x, v.y, v.z) {}

    __vmath_ctor__ vec3(const vec3_t& v) : pure(v) {}
    __vmath_ctor__ operator       vec3_t&()       { return pure; }
    __vmath_ctor__ operator const vec3_t&() const { return pure; }

public: /* Operator */
    __vmath_mthd__ float& operator[](int index)
    {
        assert(index >= 0 && index < 3);
        return pure.m[index];
    }

    __vmath_mthd__ float operator[](int index) const
    {
        assert(index >= 0 && index < 3);
        return pure.m[index];
    }

public: /* Properties */           
    __vmath_vec3_property2(x, z)    xz;
    __vmath_vec3_property2(y, x)    yx;
    __vmath_vec3_property2(z, x)    zx;
    __vmath_vec3_property2(z, y)    zy;
    __vmath_vec3_property3(x, z, y) xzy;
    __vmath_vec3_property3(y, x, z) yxz;
    __vmath_vec3_property3(y, z, x) yzx;
    __vmath_vec3_property3(z, x, y) zxy;
    __vmath_vec3_property3(z, y, x) zyx;

private:
    vec3_t pure;
};

union vec4 
{
public: /* Fields */
    struct
    {
        float x, y, z, w;
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
        float  __;
        vec2_t yz;
    };
    vec3_t   xyz;
    vec3_t   rgb;

public: /* Constructors */
    __vmath_ctor__ vec4(void) : vec4(0, 0, 0, 0) {}
    
    __vmath_ctor__ vec4(float x, float y, float z, float w) 
        #if VMATH_SSE_ENABLE != 0
        { pure.data = _mm_set_ps(w, z, y, x); }
        #else
        : x(x), y(y), z(z), w(w) {}
        #endif
    
    __vmath_ctor__ explicit vec4(float s)         : vec4(s, s, s, s)             {}
    __vmath_ctor__ explicit vec4(const float* s)  : vec4(s[0], s[1], s[2], s[3]) {}

    __vmath_ctor__ vec4(const vec2_t& v, float z = 0.0f, float w = 0.0f) : vec4(v.x, v.y,   z, w) {}
    __vmath_ctor__ vec4(const vec3_t& v, float w = 0.0f)                 : vec4(v.x, v.y, v.z, w) {}

    __vmath_ctor__ vec4(const vec4_t& v) : pure(v) {}
    __vmath_ctor__ operator       vec4_t&()       { return pure; }
    __vmath_ctor__ operator const vec4_t&() const { return pure; }

public: /* Operator */
    __vmath_mthd__ float& operator[](int index)
    {
        assert(index >= 0 && index < 4);
        return pure.m[index];
    }

    __vmath_mthd__ float operator[](int index) const
    {
        assert(index >= 0 && index < 4);
        return pure.m[index];
    }

public: /* Properties */

private:
    vec4_t pure;
};

/**
 * Quaternion data structure
 */
union quat
{
public: /* Fields */
    union
    {
        struct
        {
            float x, y, z, w;
        };
    };

public: /* Constructors */
    __vmath_ctor__ quat(void) : quat(0, 0, 0, 0) {}
    __vmath_ctor__ quat(float x, float y, float z, float w) : vec4(::vec4(x, y, z, w)) {}

    __vmath_ctor__ explicit quat(const vec3_t& euler) : quat(euler.x, euler.y, euler.z) {}
    __vmath_ctor__ quat(float x, float y, float z)
    {
        float r;
        float p;

        r = z * 0.5f;
        p = x * 0.5f;
        y = y * 0.5f; // Now y min yaw

        const float c1 = cosf(y);
        const float c2 = cosf(p);
        const float c3 = cosf(r);
        const float s1 = sinf(y);
        const float s2 = sinf(p);
        const float s3 = sinf(r);

        this->x = s1 * s2 * c3 + c1 * c2 * s3;
        this->y = s1 * c2 * c3 + c1 * s2 * s3;
        this->z = c1 * s2 * c3 - s1 * c2 * s3;
        this->w = c1 * c2 * c3 - s1 * s2 * s3;
    }

    __vmath_ctor__ operator vec3() const
    {
        float s = 2.0f * (w * x + y * z);
        float c = 1.0f - 2.0f * (x * x + y * y);
        const float r = atan2f(s, c);

        s = 2.0f * (w * y - z * x);
        const float p = fabsf(s >= 1.0f) >= 1.0f ? copysignf(PI * 0.5f, s) : s;

        s = 2.0f * (w * z + y * x);
        c = 1.0f - 2.0f * (y * y + z * z);
        const float y = atan2f(s, c);
        return vec3(r, p, y);
    }


    __vmath_ctor__ quat(const vec3_t& axis, float angle)
    {
        const float lsqr = axis.x * axis.x + axis.y * axis.y + axis.z * axis.z;
        if (lsqr == 0.0f)
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
            w = 1.0f;
        }
        else
        {
            const float s = sinf(angle * 0.5f) / vmath_fsqrt(lsqr);
            const float c = cosf(angle * 0.5f);

            x = axis.x * s;
            y = axis.y * s;
            z = axis.z * s;
            w = c;
        }
    }

    __vmath_ctor__ explicit quat(float s) : quat(0, 0, 0, s) {}
    __vmath_ctor__ explicit quat(const float* s) : quat(s[0], s[1], s[2], s[3]) {}

    __vmath_ctor__ explicit quat(const vec4_t& v) : quat(v.xyz, v.w) {}
    __vmath_ctor__ operator vec4() const 
    { 
        quat_t c = *this;
        if (c.w != 0.0f)
        {
            const float f = 1.0f / vmath_fsqrt(x * x + y * y + z * z + w * w);
            c.x *= f;
            c.y *= f;
            c.z *= f;
            c.w *= f;
        }

        vec4_t r;
        const float den = vmath_rsqrt(1.0f - c.w * c.w);
        if (den > 0.0001f)
        {
            r.x = c.x * den;
            r.y = c.y * den;
            r.z = c.z * den;
        }
        else
        {
            r.x = 1;
            r.y = 1;
            r.z = 1;
        }
        r.w = 2.0f * cosf(c.w);
        return r;
    }

    __vmath_ctor__ quat(const quat_t& v) : pure(v) {}
    __vmath_ctor__ operator       quat_t&()       { return pure; }
    __vmath_ctor__ operator const quat_t&() const { return pure; }

public: /* Operator */
    __vmath_mthd__ float& operator[](int index)
    {
        assert(index >= 0 && index < 4);
        return pure.m[index];
    }

    __vmath_mthd__ float operator[](int index) const
    {
        assert(index >= 0 && index < 4);
        return pure.m[index];
    }

private:
    vec4_t vec4;
    quat_t pure;
};

/**
 * Matrix 2x2 data structure
 */
union mat2
{
public: /* Fields */
    struct
    {
        float m00, m01;
        float m10, m11;
    };

public: /* Constructors */
    __vmath_ctor__ mat2(const mat2_t& v) : pure(v) {}
    __vmath_ctor__ operator       mat2_t&()       { return pure; }
    __vmath_ctor__ operator const mat2_t&() const { return pure; }

    __vmath_ctor__ explicit mat2(const mat3_t& m)
        : mat2(m.m00, m.m01,
               m.m10, m.m11) {}
    __vmath_ctor__ explicit mat2(const mat4_t& m)
        : mat2(m.m00, m.m01,
               m.m10, m.m11) {}

    __vmath_ctor__ mat2(void) : mat2(0.0f) {}
    __vmath_ctor__ explicit mat2(float s)
        : mat2(s, 0, 
               0, s) {}

    __vmath_ctor__ mat2(float m00, float m01, float m10, float m11)
        : m00(m00), m01(m01)
        , m10(m10), m11(m11) {}

    __vmath_ctor__ mat2(const vec2& row0, const vec2& row1)
        : mat2(row0.x, row0.y, 
               row1.x, row1.y) {}

    __vmath_ctor__ operator       float*()       { return pure.data; }
    __vmath_ctor__ operator const float*() const { return pure.data; }

public: /* Operator */
    __vmath_mthd__ vec2& operator[](int index)
    {
        assert(index >= 0 && index < 2);
        return *(vec2*)(pure.m + index);
    }

    __vmath_mthd__ const vec2& operator[](int index) const
    {
        assert(index >= 0 && index < 2);
        return *(const vec2*)(pure.m + index);
    }

private:
    mat2_t pure;
};

/**
 * Matrix3x3 data structure
 */
union mat3
{
public: /* Fields */
    struct
    {
        float m00, m01, m02;
        float m10, m11, m12;
        float m20, m21, m22;
    };
    
public: /* Constructors */
    __vmath_ctor__ mat3(const mat3_t& v) : pure(v) {}
    __vmath_ctor__ operator       mat3_t&()       { return pure; }
    __vmath_ctor__ operator const mat3_t&() const { return pure; }

    __vmath_ctor__ explicit mat3(const mat2_t& m)
        : mat3(m.m00, m.m01, 0,
               m.m10, m.m11, 0,
                   0,     0, 0) {}

    __vmath_ctor__ explicit mat3(const mat4_t& m)
        : mat3(m.m00, m.m01, m.m02,
               m.m10, m.m11, m.m12,
               m.m20, m.m21, m.m22) {}

    __vmath_ctor__ mat3(void) : mat3(0.0f) {}
    __vmath_ctor__ explicit mat3(float s)
        : mat3(s, 0, 0, 
               0, s, 0,
               0, 0, s) {}

    __vmath_ctor__ mat3(float m00, float m01, float m02, 
                        float m10, float m11, float m12,
                        float m20, float m21, float m22)
        : m00(m00), m01(m01), m02(m02)
        , m10(m10), m11(m11), m12(m12)
        , m20(m20), m21(m21), m22(m22) {}

    __vmath_ctor__ mat3(const vec3& row0, const vec3& row1, const vec3& row2)
        : mat3(row0.x, row0.y, row0.z, 
               row1.x, row1.y, row1.z,
               row2.x, row2.y, row2.z) {}

    __vmath_ctor__ operator       float*()       { return pure.data; }
    __vmath_ctor__ operator const float*() const { return pure.data; }

public: /* Operators */
    __vmath_mthd__ float& operator[](int index)
    {
        assert(index >= 0 || index < 3);
        return pure.data[index];
    }

    __vmath_mthd__ float operator[](int index) const
    {
        assert(index >= 0 || index < 3);
        return pure.data[index];
    }

private:
    mat3_t pure;
};

/**
 * Matrix4x4 data structure
 */
union mat4
{
public: /* Fields */
    struct
    {
        float m00, m01, m02, m03;
        float m10, m11, m12, m13;
        float m20, m21, m22, m23;
        float m30, m31, m32, m33;
    };

public: /* Constructors */
    __vmath_ctor__ mat4(const mat4_t& v) : pure(v) {}
    __vmath_ctor__ operator       mat4_t&()       { return pure; }
    __vmath_ctor__ operator const mat4_t&() const { return pure; }

    __vmath_ctor__ operator       float*()       { return pure.data; }
    __vmath_ctor__ operator const float*() const { return pure.data; }

    __vmath_ctor__ mat4(void) : mat4(0.0f) {}
    __vmath_ctor__ explicit mat4(float s)
        : mat4(s, 0, 0, 0,
               0, s, 0, 0,
               0, 0, s, 0,
               0, 0, 0, s) {}

    __vmath_ctor__ mat4(float m00, float m01, float m02, float m03, 
                        float m10, float m11, float m12, float m13,
                        float m20, float m21, float m22, float m23,
                        float m30, float m31, float m32, float m33)
        #if VMATH_SSE_ENABLE != 0
        {
            pure.rows[0] = vec4(m00, m01, m02, m03);
            pure.rows[1] = vec4(m10, m11, m12, m13);
            pure.rows[2] = vec4(m20, m21, m22, m23);
            pure.rows[3] = vec4(m30, m31, m32, m33);
        }
        #else
        : m00(m00), m01(m01), m02(m02), m03(m03)
        , m10(m10), m11(m11), m12(m12), m13(m13)
        , m20(m20), m21(m21), m22(m22), m23(m23)
        , m30(m30), m31(m31), m32(m32), m33(m33) {}
        #endif

    __vmath_ctor__ mat4(const vec4& row0, const vec4& row1, const vec4& row2, const vec4& row3)
        : mat4(row0.x, row0.y, row0.z, row0.w,
               row1.x, row1.y, row1.z, row1.w,
               row2.x, row2.y, row2.z, row2.w,
               row3.x, row3.y, row3.z, row3.w) {}

    __vmath_ctor__ explicit mat4(const mat2_t& m)
        : mat4(m.m00, m.m01, 0, 0,
               m.m10, m.m11, 0, 0,
                   0,     0, 0, 0,
                   0,     0, 0, 0) {}            

    __vmath_ctor__ explicit mat4(const mat3_t& m)
        : mat4(m.m00, m.m01, m.m02, 0,
               m.m10, m.m11, m.m12, 0,
               m.m20, m.m21, m.m22, 0,
                   0,     0,     0, 0) {}        

    __vmath_ctor__ mat4(const mat2_t& m0, const mat2_t& m1, const mat2_t& m2, const mat2_t& m3)
        : mat4(m0.m00, m0.m01, m1.m00, m1.m01,
               m0.m10, m0.m11, m1.m10, m1.m11,
               m2.m00, m2.m01, m3.m00, m3.m01,
               m2.m10, m2.m11, m3.m10, m3.m11) {}

public: /* Operators */
    __vmath_mthd__ vec4& operator[](int index)
    {
        assert(index >= 0 && index < 4);
        return *(vec4*)(pure.rows + index);
    }

    __vmath_mthd__ const vec4& operator[](int index) const
    {
        assert(index >= 0 && index < 4);
        return *(const vec4*)(pure.m + index);
    }

private: /* Operator */

private:
    mat4_t pure;
};

static_assert(sizeof(vec2) == sizeof(vec2_t), "Size of vec2 is not equal vec2_t");
static_assert(sizeof(vec3) == sizeof(vec3_t), "Size of vec3 is not equal vec3_t");
static_assert(sizeof(vec4) == sizeof(vec4_t), "Size of vec4 is not equal vec4_t");
static_assert(sizeof(quat) == sizeof(quat_t), "Size of quat is not equal quat_t");
static_assert(sizeof(mat2) == sizeof(mat2_t), "Size of mat2 is not equal mat2_t");
static_assert(sizeof(mat3) == sizeof(mat3_t), "Size of mat3 is not equal mat3_t");
static_assert(sizeof(mat4) == sizeof(mat4_t), "Size of mat4 is not equal mat4_t");

#else

/**
 * Create Vector2D
 */
__vmath__ vec2_t vec2(float x, float y)
{
    vec2_t v;
    v.x = x;
    v.y = y;
    return v;
}

/**
 * Create a Vector3D
 */
__vmath__ vec3_t vec3(float x, float y, float z)
{
    vec3_t v;
#if VMATH_SSE_ENABLE
    v.data = _mm_set_ps(0, z, y, x);
#else
    v.x = x;
    v.y = y;
    v.z = z;
#endif         
    return v;
}

/**
 * Create a Vector4D
 */
__vmath__ vec4_t vec4(float x, float y, float z, float w)
{
    vec4_t v;
    
#if (VMATH_SSE_ENABLE != 0)
    v.data = _mm_set_ps(w, z, y, x);
#else
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
#endif
    
    return v;
}

/**
 * Create Quaternion
 * @return: Created quaternion
 */
__vmath__ quat_t quat(float x, float y, float z, float w)
{           
    quat_t r;
    r.vec4 = vec4(x, y, z, w);
    return r;
}

/**
 * Create a matrix 2x2 with 4 components of its
 *
 * @param m00 component at [0, 0]
 * @param m01 component at [0, 1]
 * @param m10 component at [1, 0]
 * @param m11 component at [1, 1]
 * @return result matrix
 */
__vmath__ mat2_t mat2(float m00, float m01, float m10, float m11)
{
    mat2_t r;
    r.vec4 = vec4(m00, m01, m10, m11);
    return r;
}

/**
 * Create a identify matrix 3x3
 */
__vmath__ mat3_t mat3(float s)
{
    mat3_t r = {
        s, 0, 0,
        0, s, 0,
        0, 0, s,
    };
    return r;
}

/**
 * Create a identity matrix 4x4
 */
__vmath__ mat4_t mat4(float s)
{
    mat4_t r;
    r.rows[0] = vec4(s, 0, 0, 0);
    r.rows[1] = vec4(0, s, 0, 0);
    r.rows[2] = vec4(0, 0, s, 0);
    r.rows[3] = vec4(0, 0, 0, s);
    return r;
}

#if defined(__cplusplus) && VMATH_FUNCTION_OVERLOADING != 0
/* BEGIN OF VMATH_FUNCTION_OVERLOADING */

#if VMATH_BUILD_VEC2
__vmath__ vec2_t vec2(void)
{
    return vec2(0, 0);
}

__vmath__ vec2_t vec2(float s)
{
    return vec2(s, s);
}

__vmath__ vec2_t vec2(const float* data)
{
    return vec2(data[0], data[1]);
}

__vmath__ vec2_t vec2(vec3_t v)
{
    return vec2(v.x, v.y);
}

__vmath__ vec2_t vec2(vec4_t v)
{
    return vec2(v.x, v.y);
}
#endif /* VMATH_BUILD_VEC2 */

#if VMATH_BUILD_VEC3
__vmath__ vec3_t vec3(void)
{
    return vec3(0, 0, 0);
}

__vmath__ vec3_t vec3(float s)
{
#if VMATH_SSE_ENABLE
    vec3_t r;
    r.data = _mm_set_ps1(s);
    return r;
#else
    return vec3(s, s, s);
#endif
} 

__vmath__ vec3_t vec3(const float* data)
{
    return vec3(data[0], data[1], data[2]);
}

__vmath__ vec3_t vec3(vec2_t v, float z = 0.0f)
{
    return vec3(v.x, v.y, z);
}

__vmath__ vec3_t vec3(vec4_t v)
{
    return vec3(v.x, v.y, v.z);
}
#endif /* VMATH_BUILD_VEC3 */

#if VMATH_BUILD_VEC4
__vmath__ vec4_t vec4(void)
{
    return vec4(0, 0, 0, 0);
}

__vmath__ vec4_t vec4(float s)
{
#if VMATH_SSE_ENABLE
    vec4_t r;
    r.data = _mm_set_ps1(s);
    return r;
#else
    return vec4(s, s, s, s);
#endif
}

__vmath__ vec4_t vec4(const float* data)
{
#if VMATH_SSE_ENABLE
    vec4_t r;
    r.data = _mm_load_ps(data);
    return r;
#else
    return vec4(data[0], data[1], data[2], data[3]);
#endif
}

__vmath__ vec4_t vec4(vec2_t v)
{
    return vec4(v.x, v.y, 0, 0);
}

__vmath__ vec4_t vec4(vec2_t xy, vec2_t zw)
{
    return vec4(xy.x, xy.y, zw.x, zw.y);
}

__vmath__ vec4_t vec4(vec3_t v, float w = 0.0f)
{
#if VMATH_SSE_ENABLE || VMATH_NEON_ENABLE
    vec4_t r;
    r.data = v.data;
    r.w    = w;
    return r;
#else
    return vec4(v.x, v.y, v.z, w);
#endif
}        
#endif /* VMATH_BUILD_VEC4 */


#if VMATH_BUILD_QUAT
__vmath__ quat_t quat(float s)
{
    return quat(s, s, s, s);
}
#endif /* VMATH_BUILD_QUAT */

#if VMATH_BUILD_MAT2
__vmath__ mat2_t mat2(float s)
{
    return mat2(s, 0, 0, s);
}

__vmath__ mat2_t mat2(vec2_t row0, vec2_t row1)
{
    return mat2(row0.x, row0.y, row1.x, row1.y);
}

__vmath__ mat2_t mat2(const float* data)
{
    return mat2(data[0], data[1], data[2], data[3]);   
}
#endif /* VMATH_BUILD_MAT2 */


#if VMATH_BUILD_MAT3
__vmath__ mat3_t mat3(vec3_t row0, vec3_t row1, vec3_t row2)
{
    mat3_t r = {
        row0.x, row0.y, row0.z,
        row1.x, row1.y, row1.z,
        row2.z, row2.y, row2.z,
    };
    return r;
}

__vmath__ mat3_t mat3(float m00, float m01, float m02,
                      float m10, float m11, float m12,
                      float m20, float m21, float m22)
{
    mat3_t r = {
        m00, m01, m02,
        m10, m11, m12,
        m20, m21, m22,
    };
    return r;
}

__vmath__ mat3_t mat3(const float* data)
{
    mat3_t r = {
        data[0], data[1], data[2],
        data[3], data[4], data[5],
        data[6], data[7], data[8]
    };
    return r;
}
#endif /* VMATH_BUILD_MAT3 */

#if VMATH_BUILD_MAT4
__vmath__ mat4_t mat4(vec4_t row0, vec4_t row1, vec4_t row2, vec4_t row3)
{
    mat4_t r;
    r.rows[0] = row0;
    r.rows[1] = row1;
    r.rows[2] = row2;
    r.rows[3] = row3;
    return r;
}

__vmath__ mat4_t mat4(float m00, float m01, float m02, float m03,
                      float m10, float m11, float m12, float m13,
                      float m20, float m21, float m22, float m23,
                      float m30, float m31, float m32, float m33)
{
    mat4_t r;
    r.rows[0] = vec4(m00, m01, m02, m03);
    r.rows[1] = vec4(m10, m11, m12, m13);
    r.rows[2] = vec4(m20, m21, m22, m23);
    r.rows[3] = vec4(m30, m31, m32, m33);
    return r;
}

__vmath__ mat4_t mat4(const float* data)
{
    mat4_t r;
    r.rows[0] = vec4(data +  0);
    r.rows[1] = vec4(data +  4);
    r.rows[2] = vec4(data +  8);
    r.rows[3] = vec4(data + 12);
    return r;
}
#endif /* VMATH_BUILD_MAT4 */

/* END OF VMATH_FUNCTION_OVERLOADING */
#endif /* VMATH_FUNCTION_OVERLOADING */

#endif /* VMATH_GLSL_LIKE */


/*******************************
 * @region: Functions define
 *******************************/
__vmath__ float radians(float d)
{
    const float f = PI / 180.0f;
    return d * f;
}

__vmath__ float degrees(float r)
{
    const float f = 180.0f / PI;
    return r * f;
}

__vmath__ float minf(float a, float b)
{
    return a < b ? a : b;
}

__vmath__ float maxf(float a, float b)
{
    return a > b ? a : b;
}

__vmath__ float clampf(float v, float min, float max)
{
    return v < min ? min : (v > max ? max : v);
}

__vmath__ float stepf(float a, float b, float t)
{
    return (a + (b - a) * t);
}

__vmath__ float smoothstepf(float a, float b, float t)
{
    t = clampf((t - a) / (b - a), 0.0f, 1.0f);
    return t * t * t * ((t * 6 - 15) + 10);
}

__vmath__ float mixf(float a, float b, float t)
{
    return a * (1.0f - t) + b * t;
}

__vmath__ float dotf(float a, float b)
{
    return a * b;
}

__vmath__ float rsqrtf(float x)
{
    return vmath_rsqrt(x);
}

__vmath__ float lengthf(float x)
{
    return fabsf(x);
}

__vmath__ float distancef(float a, float b)
{
    return fabsf(a - b);
}

__vmath__ float normalizef(float x)
{
    return 1.0f;
}

__vmath__ float reflectf(float v, float n)
{
    /* equation: ref = v - 2 * n * dot(v, n) */
    return v - 2 * n * dotf(v, n);
}

__vmath__ float faceforwardf(float n, float i, float nref)
{
    return dotf(i, nref) < 0.0f ? n : -n;
}

__vmath__ float refractf(float v, float n, float eta)
{
    float k = 1.0f - eta * eta * (1.0f - dotf(n, v) * dotf(n, v));
    return k < 0.0f 
        ? 0.0f 
        : eta * v - (eta * dotf(n, v) + vmath_fsqrt(k)) * v;
}

/**************************
 * Vector2D
 **************************/
#if VMATH_BUILD_VEC2
/**
 * Addition of two vector2d
 */
__vmath__ vec2_t vec2_add(vec2_arg_t a, vec2_arg_t b)
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
__vmath__ vec2_t vec2_sub(vec2_arg_t a, vec2_arg_t b)
{
#if VMATH_NEON_ENABLE
    return (vec2_t){ .data = vsub_s32(a.data, b.data) };
#else
    return vec2(a.x - b.x, a.y - b.y);
#endif
}

/**
* Multiplication of two vector2d
*/
__vmath__ vec2_t vec2_mul(vec2_arg_t a, vec2_arg_t b)
{
#if VMATH_NEON_ENABLE
    return (vec2_t){ .data = vmul_f32(a.data, b.data) };
#else
    return vec2(a.x * b.x, a.y * b.y);
#endif
}

/**
 * Division of two vector2d
 */
__vmath__ vec2_t vec2_div(vec2_arg_t a, vec2_arg_t b)
{
#if VMATH_NEON_ENABLE
    return (vec2_t){ .data = vdiv_s32(a.data, b.data) };
#else
    return vec2(a.x / b.x, a.y / b.y);
#endif
}

/**
 * Add of a vector2d with a scalar
 */
__vmath__ vec2_t vec2_addf(vec2_arg_t v, float s)
{
#if VMATH_NEON_ENABLE
    return (vec2_t){ .data = vadd_n_f32(v.data, s) };
#else
    return vec2(v.x + s, v.y + s);
#endif
}

/**
* Subtract of a vector2d with a scalar
*/
__vmath__ vec2_t vec2_subf(vec2_arg_t v, float s)
{
#if VMATH_NEON_ENABLE
    return (vec2_t){ .data = vsub_n_f32(v.data, s) };
#else
    return vec2(v.x - s, v.y - s);
#endif
}

/**
 * Multiply of a vector2d with a scalar
 */
__vmath__ vec2_t vec2_mulf(vec2_arg_t v, float s)
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
__vmath__ vec2_t vec2_divf(vec2_arg_t v, float s)
{
    return vec2_mulf(v, 1.0f / s);
}

/**
 * Compare two vector2d is equal or not
 */
__vmath__ bool vec2_equal(vec2_arg_t a, vec2_arg_t b)
{
    return a.x == b.x && a.y == b.y;
}

/**
 * Create a negative vector
 */
__vmath__ vec2_t vec2_neg(vec2_arg_t v)
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
__vmath__ float vec2_dot(vec2_arg_t a, vec2_arg_t b)
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
__vmath__ float vec2_lengthsquared(vec2_arg_t v)
{
    return vec2_dot(v, v);
}

/**
 * Length of vector 2d
 */
__vmath__ float vec2_length(vec2_arg_t v)
{
    return vmath_fsqrt(vec2_lengthsquared(v));
}

/**
 * Distance of two vector 2d
 */
__vmath__ float vec2_distance(vec2_arg_t a, vec2_arg_t b)
{
    return vec2_length(vec2_sub(b, a));
}

/**
 * Squared distance of two vector 2d
 */
__vmath__ float vec2_distancesquared(vec2_arg_t a, vec2_arg_t b)
{
    return vec2_lengthsquared(vec2_sub(b, a));
}

/**
 * Angle of vector 2d
 */
__vmath__ float vec2_angle(vec2_arg_t v)
{
    return atan2f(v.y, v.x);
}

/**
 * Get normalized Vector2D, force direction only and unit length
 */
__vmath__ vec2_t vec2_normalize(vec2_arg_t v)
{
    const float lsqr = vec2_lengthsquared(v);
    if (lsqr != 1.0f && lsqr > 0)
    {
        const float l = vmath_rsqrt(lsqr);
        return vec2(v.x * l, v.y * l);
    }
    return v;
}

/**
 * Calculate reflection vector
 */ 
__vmath__ vec2_t vec2_reflect(vec2_arg_t v, vec2_arg_t n)
{
    /* equation: ref = v - 2 * n * dot(v, n) */
    return vec2_sub(v, vec2_mulf(n, 2 * vec2_dot(n, v)));
}

/**
 *
 */
__vmath__ vec2_t vec2_min(vec2_arg_t a, vec2_arg_t b)
{
    return vec2(
        minf(a.x, b.x),
        minf(a.y, b.y)
    );
}

/**
 *
 */
__vmath__ vec2_t vec2_max(vec2_arg_t a, vec2_arg_t b)
{
    return vec2(
        maxf(a.x, b.x),
        maxf(a.y, b.y)
    );
}

/**
 *
 */
__vmath__ vec2_t vec2_clamp(vec2_arg_t v, vec2_arg_t min, vec2_arg_t max)
{
    return vec2(
        clampf(v.x, min.x, max.x),
        clampf(v.y, min.y, max.y)
    );
}

/**
 *
 */
__vmath__ vec2_t vec2_clamplength(vec2_arg_t v, float min, float max)
{
    const float oldlen = vec2_length(v);
    const float newlen = clampf(oldlen, min, max);
    const float factor = newlen / oldlen;

    return vec2(v.x * factor, v.y * factor);
}

__vmath__ vec2_t vec2_minf(vec2_arg_t a, float b)
{
    return vec2(
        minf(a.x, b),
        minf(a.y, b)
    );
}

__vmath__ vec2_t vec2_maxf(vec2_arg_t a, float b)
{
    return vec2(
        maxf(a.x, b),
        maxf(a.y, b)
    );
}

__vmath__ vec2_t vec2_clampf(vec2_arg_t v, float min, float max)
{
    return vec2(
        clampf(v.x, min, max),
        clampf(v.y, min, max)
    );
}

__vmath__ vec2_t vec2_step(vec2_arg_t a, vec2_arg_t b, vec2_arg_t t)
{
    return vec2(
        stepf(a.x, b.x, t.x),
        stepf(a.y, b.y, t.y)  
    );
}

__vmath__ vec2_t vec2_smoothstep(vec2_arg_t a, vec2_arg_t b, vec2_arg_t t)
{
    return vec2(
        smoothstepf(a.x, b.x, t.x),
        smoothstepf(a.y, b.y, t.y)  
    );
}

__vmath__ vec2_t vec2_stepf(vec2_arg_t a, vec2_arg_t b, float t)
{
    return vec2(
        stepf(a.x, b.x, t),
        stepf(a.y, b.y, t)  
    );
}

__vmath__ vec2_t vec2_smoothstepf(vec2_arg_t a, vec2_arg_t b, float t)
{
    return vec2(
        smoothstepf(a.x, b.x, t),
        smoothstepf(a.y, b.y, t)  
    );
}

__vmath__ vec2_t vec2_mix(vec2_arg_t a, vec2_arg_t b, vec2_arg_t t)
{
    return vec2(
        mixf(a.x, b.x, t.x),
        mixf(a.y, b.y, t.y)
    );
}

__vmath__ vec2_t vec2_mixf(vec2_arg_t a, vec2_arg_t b, float t)
{
    return vec2(
        mixf(a.x, b.x, t),
        mixf(a.y, b.y, t)
    );
}

__vmath__ vec2_t vec2_faceforward(vec2_arg_t n, vec2_arg_t i, vec2_arg_t nref)
{
    return vec2_dot(i, nref) < 0.0f ? n : vec2_neg(n);
}

__vmath__ vec2_t vec2_refract(vec2_arg_t v, vec2_arg_t n, float eta)
{
    float k = 1.0f - eta * eta * (1.0f - vec2_dot(n, v) * vec2_dot(n, v));
    if (k < 0.0f)
        return vec2(0.0f, 0.0f);
    else
        return vec2_sub(vec2_mulf(v, eta), vec2_mulf(v, (eta * vec2_dot(n, v) + vmath_fsqrt(k))));
}

/* END OF VMATH_BUILD_VEC2 */
#endif

/**************************
* Vector3D
**************************/
#if VMATH_BUILD_VEC3
/**
 * Addition of two vector 3d
 */
__vmath__ vec3_t vec3_add(vec3_arg_t a, vec3_arg_t b)
{
#if VMATH_NEON_ENABLE
    vec3_t r;
    r.data = vaddq_f32(a.data, b.data);
    return r;
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
__vmath__ vec3_t vec3_sub(vec3_arg_t a, vec3_arg_t b)
{
#if VMATH_NEON_ENABLE
    vec3_t r;
    r.data = vsubq_f32(a.data, b.data);
    return r;
#elif VMATH_SSE_ENABLE
    vec3_t r;
    r.data = _mm_sub_ps(a.data, b.data);
    return r;
#else
    return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
#endif
}

/**
 * Multiplication of two vector 3d
 */
__vmath__ vec3_t vec3_mul(vec3_arg_t a, vec3_arg_t b)
{
#if VMATH_NEON_ENABLE
    vec3_t r;
    r.data = vmulq_f32(a.data, b.data);
    return r;
#elif VMATH_SSE_ENABLE
    vec3_t r;
    r.data = _mm_mul_ps(a.data, b.data);
    return r;
#else
    return vec3(a.x * b.x, a.y * b.y, a.z * b.z);
#endif
}

/**
 * Division of two vector 3d
 */
__vmath__ vec3_t vec3_div(vec3_arg_t a, vec3_arg_t b)
{
#if VMATH_NEON_ENABLE
    vec3_t r;
    r.data = vdivq_f32(a.data, b.data);
    return r;
#elif VMATH_SSE_ENABLE
    vec3_t r;
    r.data = _mm_div_ps(a.data, b.data);
    return r;
#else
    return vec3(a.x / b.x, a.y / b.y, a.z / b.z);
#endif
}

/**
 * Addition of a vector 3d with a scalar, also called as scale
 */
__vmath__ vec3_t vec3_addf(vec3_arg_t v, float s)
{
#if VMATH_NEON_ENABLE
    vec3_t r;
    r.data = vaddq_n_f32(v.data, s);
    return r;
#elif VMATH_SSE_ENABLE
    vec3_t r;
    r.data = _mm_add_ps(v.data, _mm_set_ps1(s));
    return r;
#else
    return vec3(v.x + s, v.y + s, v.z + s);
#endif
}

/**
 * Subtraction of a vector 3d with a scalar, also called as scale down 
 */
__vmath__ vec3_t vec3_subf(vec3_arg_t v, float s)
{
#if VMATH_NEON_ENABLE
    vec3_t r;
    r.data = vsubq_n_f32(v.data, s);
    return r;
#elif VMATH_SSE_ENABLE
    vec3_t r;
    r.data = _mm_sub_ps(v.data, _mm_set_ps1(s));
    return r;
#else
    return vec3(v.x - s, v.y - s, v.z - s);
#endif
}

/**
 * Multiply of a vector 3d with a scalar, also called as scale
 */
__vmath__ vec3_t vec3_mulf(vec3_arg_t v, float s)
{
#if VMATH_NEON_ENABLE
    vec3_t r;
    r.data = vmulq_n_f32(v.data, s);
    return r;
#elif VMATH_SSE_ENABLE
    vec3_t r;
    r.data = _mm_mul_ps(v.data, _mm_set_ps1(s));
    return r;
#else
    return vec3(v.x * s, v.y * s, v.z * s);
#endif
}

/**
 * Division of a vector 3d with a scalar, also called as scale down 
 */
__vmath__ vec3_t vec3_divf(vec3_arg_t v, float s)
{
    return vec3_mulf(v, 1.0f / s);
}

/**
 * Compare two vector3d is equal or not
 */
__vmath__ bool vec3_equal(vec3_arg_t a, vec3_arg_t b)
{
#if VMATH_SSE_ENABLE
    return (_mm_movemask_ps(_mm_cmpeq_ps(a.data, b.data)) & 0x7) == 0x7;
#else
    return a.x == b.x && a.y == b.y && a.z == b.z;
#endif
}

/**
 * Negative version of a Vector3D
 */
__vmath__ vec3_t vec3_neg(vec3_arg_t v)
{
#if VMATH_NEON_ENABLE
    vec3_t r;
    r.data = vnegq_f32(v.data);
    return r;
#elif VMATH_SSE_ENABLE
    vec3_t r;
    r.data = _mm_sub_ps(__M128_ZERO, v.data);
    return r;
#else
    return vec3(-v.x, -v.y, -v.z);
#endif
}

/**
 * Dot product of two vector 3d
 */
__vmath__ float vec3_dot(vec3_arg_t a, vec3_arg_t b)
{
#if VMATH_SSE_ENABLE
# if defined(__SSE4_1__)
    return _mm_cvtss_f32(_mm_dp_ps(a.data, b.data, 0x71));
# else
    const vec3_t tmp = vec3_mul(a, b);
    return tmp.x + tmp.y + tmp.z; 
# endif
#else
    return a.x * b.x + a.y * b.y + a.z * b.z;
#endif
}

/**
 * Cross product of two vector 3d
 */
__vmath__ vec3_t vec3_cross(vec3_arg_t a, vec3_arg_t b)
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
__vmath__ float vec3_lengthsquared(vec3_arg_t v)
{
    return vec3_dot(v, v);
}

/**
 * Length of vector 3d
 */
__vmath__ float vec3_length(vec3_arg_t v)
{
#if VMATH_SSE_ENABLE && defined(__SSE4_1__)
    return _mm_cvtss_f32(_mm_sqrt_ss(_mm_dp_ps(v.data, v.data, 0x71)));
#else
    return vmath_fsqrt(vec3_lengthsquared(v));
#endif
}

/**
 * Distance of two vector 3d
 */
__vmath__ float vec3_distance(vec3_arg_t a, vec3_arg_t b)
{
    return vec3_length(vec3_sub(b, a));
}

/**
 * Squared distance of two vector 3d
 */
__vmath__ float vec3_distancesquared(vec3_arg_t a, vec3_arg_t b)
{
    return vec3_lengthsquared(vec3_sub(b, a));
}

/**
 * Get normalized vector3D (force to direction only, unit length)
 */
__vmath__ vec3_t vec3_normalize(vec3_arg_t v)
{
#if VMATH_SSE_ENABLE && defined(__SSE4_1__)
    vec3_t r;
    r.data = _mm_mul_ps(v.data, _mm_rsqrt_ps(_mm_dp_ps(v.data, v.data, 0x77)));
    return r;
#else
    const float lsqr = vec3_lengthsquared(v);
    if (lsqr != 1.0f && lsqr > 0) 
    {
        const float inv = vmath_rsqrt(lsqr);
        return vec3(v.x * inv, v.y * inv, v.z * inv);
    }
    return v;
#endif
}

/**
 * Calculate reflection vector
 */ 
__vmath__ vec3_t vec3_reflect(vec3_arg_t v, vec3_arg_t n)
{
    /* equation: ref = v - 2 * n * dot(v, n) */
    return vec3_sub(v, vec3_mulf(n, 2 * vec3_dot(n, v)));
}

/**
*
*/
__vmath__ vec3_t vec3_min(vec3_arg_t a, vec3_arg_t b)
{
    return vec3(
        minf(a.x, b.x),
        minf(a.y, b.y),
        minf(a.z, b.z)
    );
}

/**
*
*/
__vmath__ vec3_t vec3_max(vec3_arg_t a, vec3_arg_t b)
{
    return vec3(
        maxf(a.x, b.x),
        maxf(a.y, b.y),
        maxf(a.z, b.z)
    );
}

/**
*
*/
__vmath__ vec3_t vec3_clamp(vec3_arg_t v, vec3_arg_t min, vec3_arg_t max)
{
    return vec3(
        clampf(v.x, min.x, max.x),
        clampf(v.y, min.y, max.y),
        clampf(v.z, min.z, max.z)
    );
}

/**
*
*/
__vmath__ vec3_t vec3_clamplength(vec3_arg_t v, float min, float max)
{
    const float oldlen = vec3_length(v);
    const float newlen = clampf(oldlen, min, max);
    const float factor = newlen / oldlen;

    return vec3(v.x * factor, v.y * factor, v.z * factor);
}

__vmath__ vec3_t vec3_minf(vec3_arg_t a, float b)
{
    return vec3(
        minf(a.x, b),
        minf(a.y, b),
        minf(a.z, b)
    );
}

__vmath__ vec3_t vec3_maxf(vec3_arg_t a, float b)
{
    return vec3(
        maxf(a.x, b),
        maxf(a.y, b),
        maxf(a.z, b)
    );
}

__vmath__ vec3_t vec3_clampf(vec3_arg_t v, float min, float max)
{
    return vec3(
        clampf(v.x, min, max),
        clampf(v.y, min, max),
        clampf(v.z, min, max)
    );
}

__vmath__ vec3_t vec3_step(vec3_arg_t a, vec3_arg_t b, vec3_arg_t t)
{
    return vec3(
        stepf(a.x, b.x, t.x),
        stepf(a.y, b.y, t.y),
        stepf(a.z, b.z, t.z)  
    );
}

__vmath__ vec3_t vec3_smoothstep(vec3_arg_t a, vec3_arg_t b, vec3_arg_t t)
{
    return vec3(
        smoothstepf(a.x, b.x, t.x),
        smoothstepf(a.y, b.y, t.y),
        smoothstepf(a.z, b.z, t.z)  
    );
}

__vmath__ vec3_t vec3_stepf(vec3_arg_t a, vec3_arg_t b, float t)
{
    return vec3(
        stepf(a.x, b.x, t),
        stepf(a.y, b.y, t),
        stepf(a.z, b.z, t)  
    );
}

__vmath__ vec3_t vec3_smoothstepf(vec3_arg_t a, vec3_arg_t b, float t)
{
    return vec3(
        smoothstepf(a.x, b.x, t),
        smoothstepf(a.y, b.y, t), 
        smoothstepf(a.z, b.z, t)  
    );
}

__vmath__ vec3_t vec3_mix(vec3_arg_t a, vec3_arg_t b, vec3_arg_t t)
{
    return vec3(
        mixf(a.x, b.x, t.x),
        mixf(a.y, b.y, t.y),
        mixf(a.z, b.z, t.z)
    );
}

__vmath__ vec3_t vec3_mixf(vec3_arg_t a, vec3_arg_t b, float t)
{
    return vec3(
        mixf(a.x, b.x, t),
        mixf(a.y, b.y, t),
        mixf(a.z, b.z, t)
    );
}

__vmath__ vec3_t vec3_faceforward(vec3_arg_t n, vec3_arg_t i, vec3_arg_t nref)
{
    return vec3_dot(i, nref) < 0.0f ? n : vec3_neg(n);
}

__vmath__ vec3_t vec3_refract(vec3_arg_t v, vec3_arg_t n, float eta)
{
    float k = 1.0f - eta * eta * (1.0f - vec3_dot(n, v) * vec3_dot(n, v));
    if (k < 0.0f)
        return vec3(0.0f, 0.0f, 0.0f);
    else
        return vec3_sub(vec3_mulf(v, eta), vec3_mulf(v, (eta * vec3_dot(n, v) + vmath_fsqrt(k))));
}

/* END OF VMATH_BUILD_VEC3 */
#endif

/**************************
* Vector4D
**************************/
#if VMATH_BUILD_VEC4
/**
 * Addition of two Vector4D
 */
__vmath__ vec4_t vec4_add(vec4_arg_t a, vec4_arg_t b)
{
#if VMATH_NEON_ENABLE
    vec4_t r;
    r.data = vaddq_f32(a.data, b.data);
    return r;
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
__vmath__ vec4_t vec4_sub(vec4_arg_t a, vec4_arg_t b)
{
#if VMATH_NEON_ENABLE
    vec4_t r;
    r.data = vsubq_f32(a.data, b.data);
    return r;
#elif VMATH_SSE_ENABLE
    vec4_t r;
    r.data = _mm_sub_ps(a.data, b.data);
    return r;
#else
    return vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
#endif
}

/**
 * Mutiplication of two Vector4D
 */
__vmath__ vec4_t vec4_mul(vec4_arg_t a, vec4_arg_t b)
{
#if VMATH_NEON_ENABLE
    vec4_t r;
    r.data = vmulq_f32(a.data, b.data);
    return r;
#elif VMATH_SSE_ENABLE
    vec4_t r;
    r.data = _mm_mul_ps(a.data, b.data);
    return r;
#else
    return vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
#endif
}

/**
 * Division of two vector4d
 */
__vmath__ vec4_t vec4_div(vec4_arg_t a, vec4_arg_t b)
{
#if VMATH_NEON_ENABLE
    vec4_t r;
    r.data = vdivq_f32(a.data, b.data);
    return r;
#elif VMATH_SSE_ENABLE
    vec4_t r;
    r.data = _mm_div_ps(a.data, b.data);
    return r;
#else
    return vec4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
#endif
}

/**
 * Addition of a vector4d with a scalar
 */
__vmath__ vec4_t vec4_addf(vec4_arg_t v, float s)
{
#if VMATH_NEON_ENABLE
    vec4_t r;
    r.data = vmulq_n_f32(v.data, s);
    return r;
#elif VMATH_SSE_ENABLE
    vec4_t r;
    r.data = _mm_mul_ps(v.data, _mm_set_ps1(s));
    return r;
#else
    return vec4(v.x + s, v.y + s, v.z + s, v.w + s);
#endif
}

/**
 * Subtraction of a vector4d with a scalar
 */
__vmath__ vec4_t vec4_subf(vec4_arg_t v, float s)
{
#if VMATH_NEON_ENABLE
    vec4_t r;
    r.data = vsubq_n_f32(v.data, s);
    return r;
#elif VMATH_SSE_ENABLE
    vec4_t r;
    r.data = _mm_sub_ps(v.data, _mm_set_ps1(s));
    return r;
#else
    return vec4(v.x - s, v.y - s, v.z - s, v.w - s);
#endif
}

/**
 * Multiplication of a vector4d with a scalar
 */
__vmath__ vec4_t vec4_mulf(vec4_arg_t v, float s)
{
#if VMATH_NEON_ENABLE
    vec4_t r;
    r.data = vmulq_n_f32(v.data, s);
    return r;
#elif VMATH_SSE_ENABLE
    vec4_t r;
    r.data = _mm_mul_ps(v.data, _mm_set_ps1(s));
    return r;
#else
    return vec4(v.x * s, v.y * s, v.z * s, v.w * s);
#endif
}

/**
 * Division of a vector4d with a scalar
 */
__vmath__ vec4_t vec4_divf(vec4_arg_t v, float s)
{
    return vec4_mulf(v, 1.0f / s);
}

/**
 * Compare two vector4d is equal or not
 */
__vmath__ bool vec4_equal(vec4_arg_t a, vec4_arg_t b)
{
#if VMATH_NEON_ENABLE
    return vec2_equal(a.xy, b.xy) && vec2_equal(a.zw, b.zw);
#elif VMATH_SSE_ENABLE
    return _mm_movemask_ps(_mm_cmpeq_ps(a.data, b.data)) == 0xf;
#else
    return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
#endif
}

/**
 * Negative version of a Vector4D
 */
__vmath__ vec4_t vec4_neg(vec4_arg_t v)
{
#if VMATH_NEON_ENABLE
    vec4_t r;
    r.data = vnegq_f32(v.data);
    return r;
#elif VMATH_SSE_ENABLE
    vec4_t r;
    r.data = _mm_sub_ps(__M128_ZERO, v.data);
    return r;
#else
    return vec4(-v.x, -v.y, -v.z, -v.w);
#endif
}

/**
 * Dot product of two vector4d
 */
__vmath__ float vec4_dot(vec4_arg_t a, vec4_arg_t b)
{
#if VMATH_NEON_ENABLE
    vec4_t v;
    v.data = vmulq_f32(a.data, b.data);
    return v.x + v.y + v.z + v.w;
#elif VMATH_SSE_ENABLE
    return _mm_cvtss_f32(_mm_dp_ps(a.data, b.data, 0xf1));
#else
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
#endif
}

/**
 * Squared length of vector4d
 */
__vmath__ float vec4_lengthsquared(vec4_arg_t v)
{
    return vec4_dot(v, v);
}

/**
 * Length of vector4d
 */
__vmath__ float vec4_length(vec4_arg_t v)
{
    return vmath_fsqrt(vec4_lengthsquared(v));
}

/**
 * Distance of two vector4d
 */
__vmath__ float vec4_distance(vec4_arg_t a, vec4_arg_t b)
{
    return vec4_length(vec4_sub(b, a));
}

/**
 * Squared distance of two vector4d
 */
__vmath__ float vec4_distancesquared(vec4_arg_t a, vec4_arg_t b)
{
    return vec4_lengthsquared(vec4_sub(b, a));
}

/**
 * Get normalized Vector4D, force direction only with unit length
 */
__vmath__ vec4_t vec4_normalize(vec4_arg_t v)
{
#if VMATH_SSE_ENABLE
    vec4_t r;
    r.data = _mm_mul_ps(v.data, _mm_rsqrt_ps(_mm_dp_ps(v.data, v.data, 0xff)));
    return r;
#else
    const float lsqr = vec4_lengthsquared(v);
    if (lsqr != 1.0f && lsqr > 0)
    {
        const float inv = vmath_rsqrt(lsqr);
        return vec4(v.x * inv, v.y * inv, v.z * inv, v.w * inv);
    }
    return v;
#endif
}

/**
 * Calculate reflection vector
 */ 
__vmath__ vec4_t vec4_reflect(vec4_arg_t v, vec4_arg_t n)
{
    /* equation: ref = v - 2 * n * dot(v, n) */
    return vec4_sub(v, vec4_mulf(n, 2 * vec4_dot(n, v)));
}

/**
*
*/
__vmath__ vec4_t vec4_min(vec4_arg_t a, vec4_arg_t b)
{
    return vec4(
        minf(a.x, b.x),
        minf(a.y, b.y),
        minf(a.z, b.z),
        minf(a.w, b.w)
    );
}

/**
*
*/
__vmath__ vec4_t vec4_max(vec4_arg_t a, vec4_arg_t b)
{
    return vec4(
        maxf(a.x, b.x),
        maxf(a.y, b.y),
        maxf(a.z, b.z),
        maxf(a.w, b.w)
    );
}

/**
*
*/
__vmath__ vec4_t vec4_clamp(vec4_arg_t v, vec4_arg_t min, vec4_arg_t max)
{
    return vec4(
        clampf(v.x, min.x, max.x),
        clampf(v.y, min.y, max.y),
        clampf(v.z, min.z, max.z),
        clampf(v.w, min.w, max.w)
    );
}

/**
*
*/
__vmath__ vec4_t vec4_clamplength(vec4_arg_t v, float min, float max)
{
    const float oldlen = vec4_length(v);
    const float newlen = clampf(oldlen, min, max);
    const float factor = newlen / oldlen;

    return vec4(v.x * factor, v.y * factor, v.z * factor, v.w * factor);
}

__vmath__ vec4_t vec4_minf(vec4_arg_t a, float b)
{
    return vec4(
        minf(a.x, b),
        minf(a.y, b),
        minf(a.z, b),
        minf(a.w, b)
    );
}

__vmath__ vec4_t vec4_maxf(vec4_arg_t a, float b)
{
    return vec4(
        maxf(a.x, b),
        maxf(a.y, b),
        maxf(a.z, b),
        maxf(a.w, b)
    );
}

__vmath__ vec4_t vec4_clampf(vec4_arg_t v, float min, float max)
{
    return vec4(
        clampf(v.x, min, max),
        clampf(v.y, min, max),
        clampf(v.z, min, max),
        clampf(v.w, min, max)
    );
}

__vmath__ vec4_t vec4_step(vec4_arg_t a, vec4_arg_t b, vec4_arg_t t)
{
    return vec4(
        stepf(a.x, b.x, t.x),
        stepf(a.y, b.y, t.y),
        stepf(a.z, b.z, t.z),
        stepf(a.w, b.w, t.w)
    );
}

__vmath__ vec4_t vec4_smoothstep(vec4_arg_t a, vec4_arg_t b, vec4_arg_t t)
{
    return vec4(
        smoothstepf(a.x, b.x, t.x),
        smoothstepf(a.y, b.y, t.y),
        smoothstepf(a.z, b.z, t.z),
        smoothstepf(a.w, b.w, t.w)  
    );
}

__vmath__ vec4_t vec4_stepf(vec4_arg_t a, vec4_arg_t b, float t)
{
    return vec4(
        stepf(a.x, b.x, t),
        stepf(a.y, b.y, t),
        stepf(a.z, b.z, t),
        stepf(a.w, b.w, t)  
    );
}

__vmath__ vec4_t vec4_smoothstepf(vec4_arg_t a, vec4_arg_t b, float t)
{
    return vec4(
        smoothstepf(a.x, b.x, t),
        smoothstepf(a.y, b.y, t), 
        smoothstepf(a.z, b.z, t),
        smoothstepf(a.w, b.w, t)
    );
}

__vmath__ vec4_t vec4_mix(vec4_arg_t a, vec4_arg_t b, vec4_arg_t t)
{
    return vec4(
        mixf(a.x, b.x, t.x),
        mixf(a.y, b.y, t.y),
        mixf(a.z, b.z, t.z),
        mixf(a.w, b.w, t.w)
    );
}

__vmath__ vec4_t vec4_mixf(vec4_arg_t a, vec4_arg_t b, float t)
{
    return vec4(
        mixf(a.x, b.x, t),
        mixf(a.y, b.y, t),
        mixf(a.z, b.z, t),
        mixf(a.w, b.w, t)
    );
}

__vmath__ vec4_t vec4_faceforward(vec4_arg_t n, vec4_arg_t i, vec4_arg_t nref)
{
    return vec4_dot(i, nref) < 0.0f ? n : vec4_neg(n);
}

__vmath__ vec4_t vec4_refract(vec4_arg_t v, vec4_arg_t n, float eta)
{
    float k = 1.0f - eta * eta * (1.0f - vec4_dot(n, v) * vec4_dot(n, v));
    if (k < 0.0f)
        return vec4(0.0f, 0.0f, 0.0f, 0.0f);
    else
        return vec4_sub(vec4_mulf(v, eta), vec4_mulf(v, (eta * vec4_dot(n, v) + vmath_fsqrt(k))));
}

/* END OF VMATH_BUILD_VEC4 */
#endif

/**************************
* Quaternion
**************************/
#if VMATH_BUILD_QUAT
/**
 * Addition of two quaternions
 */
__vmath__ quat_t quat_add(quat_arg_t a, quat_arg_t b)
{
    quat_t r;
    r.vec4 = vec4_add(a.vec4, b.vec4);
    return r;
}

/**
 * Subtraction of two quaternions
 */
__vmath__ quat_t quat_sub(quat_arg_t a, quat_arg_t b)
{
    quat_t r;
    r.vec4 = vec4_sub(a.vec4, b.vec4);
    return r;
}

/**
 * Addition of a quaternion with a scalar
 */
__vmath__ quat_t quat_addf(quat_arg_t q, float s)
{
    quat_t r;
    r.vec4 = vec4_addf(q.vec4, s);
    return r;
}

/**
 * Subtraction of a quaternion with a scalar
 */
__vmath__ quat_t quat_subf(quat_arg_t q, float s)
{
    quat_t r;
    r.vec4 = vec4_subf(q.vec4, s);
    return r;
}

/**
 * Multiplication of a quaternion with a scalar (scale quaternion up)
 */
__vmath__ quat_t quat_mulf(quat_arg_t q, float s)
{
    quat_t r;
    r.vec4 = vec4_mulf(q.vec4, s);
    return r;
}

/**
 * Division of a quaternion with a scalar (scale quaternion down)
 */
__vmath__ quat_t quat_divf(quat_arg_t q, float s)
{
    quat_t r;
    r.vec4 = vec4_divf(q.vec4, s);
    return r;
}

/**
 * Get negative version of given quaternion
 */
__vmath__ quat_t quat_neg(quat_arg_t q)
{
    quat_t r;
    r.vec4 = vec4_neg(q.vec4);
    return r;
}

/**
 * Test if two quaternions is equal
 */
__vmath__ bool quat_equal(quat_arg_t a, quat_arg_t b)
{
    return vec4_equal(a.vec4, b.vec4);
}

/**
 * Normalize the quaternion (force length equal 1)
 */
__vmath__ quat_t quat_normalize(quat_arg_t q)
{
    quat_t r;
    r.vec4 = vec4_normalize(q.vec4);
    return r;
}

/**
 * Create a quaternion with euler coordinate
 * @return: result quaternion
 */
__vmath__ quat_t quat_euler(float x, float y, float z)
{
    float r;
    float p;

    r = z * 0.5f;
    p = x * 0.5f;
    y = y * 0.5f; // Now y min yaw

    const float c1 = cosf(y);
    const float c2 = cosf(p);
    const float c3 = cosf(r);
    const float s1 = sinf(y);
    const float s2 = sinf(p);
    const float s3 = sinf(r);

    return quat(
        s1 * s2 * c3 + c1 * c2 * s3,
	    s1 * c2 * c3 + c1 * s2 * s3,
	    c1 * s2 * c3 - s1 * c2 * s3,
	    c1 * c2 * c3 - s1 * s2 * s3
    );
}

/**
 * Create a quaternion with euler coordinate
 * @return: result quaternion
 */
__vmath__ quat_t quat_eulerv3(vec3_arg_t e)
{
    return quat_euler(e.x, e.y, e.z);
}

/**
 * Convert to an axis-angle representation.
 * @return: a axis-angle representation store in vec4_t union
 */
__vmath__ vec4_t quat_toaxis(quat_arg_t q)
{
    quat_t c = q;
    if (c.w != 0.0f)
    {
        c = quat_normalize(q);
    }

    vec4_t r;
    const float den = sqrtf(1.0f - c.w * c.w);
    if (den > 0.0001f)
    {
        r.xyz = vec3_divf(c.vec4.xyz, den);
    } 
    else
    {
        r.xyz = vec3(1, 0, 0);
    }
    r.w = 2.0f * cosf(c.w);
    return r;
}

/**
 * Convert axis-angle representation to quaternion 
 */
__vmath__ quat_t quat_fromaxis(vec3_arg_t axis, float angle)
{
    if (vec3_lengthsquared(axis) == 0.0f)
    {
        return QUAT_IDENTITY;
    }

    quat_t r;
    r.vec4.xyz = vec3_mulf(vec3_normalize(axis), sinf(angle * 0.5f));
    r.vec4.w   = cosf(angle * 0.5f);
    return r;
}

/**
 * Get invert quaternion
 */
__vmath__ quat_t quat_inverse(quat_arg_t q)
{
    return quat(q.x, q.y, q.z, -q.w);
}

/**
 * Get conjugate quaternion
 */
__vmath__ quat_t quat_conjugate(quat_arg_t q)
{
    return quat(-q.x, -q.y, -q.z, q.w);
}

/**
 * Multiplication of two quaternions 
 */
__vmath__ quat_t quat_mul(quat_arg_t a, quat_arg_t b)
{
#if VMATH_QUAT_MUL_SIMPLE   
    return quat(
        a.x * b.x - a.y * b.y - a.z * b.z - a.w * b.w,
        a.y * b.x + a.x * b.y - a.w * b.z + a.z * b.w,
        a.z * b.x + a.w * b.y + a.x * b.z - a.y * b.w,
        a.w * b.x - a.z * b.y + a.y * b.z + a.x * b.w,
    );
#else
    quat_t r;
    r.vec4.xyz = vec3_add(
        vec3_add(vec3_mulf(a.vec4.xyz, b.w), vec3_mulf(b.vec4.xyz, a.w)),
        vec3_cross(a.vec4.xyz, b.vec4.xyz)
    );
    r.vec4.w   = a.w * b.w - vec3_dot(a.vec4.xyz, b.vec4.xyz);
    return r;
#endif
}


/**
 * Get euler values present in Vector3D   
 */
__vmath__ vec3_t quat_toeuler(quat_arg_t q)
{
    float s = 2.0f * (q.w * q.x + q.y * q.z);
    float c = 1.0f - 2.0f * (q.x * q.x + q.y * q.y);
    const float r = atan2f(s, c);

    s = 2.0f * (q.w * q.y - q.z * q.x);
    const float p = fabsf(s >= 1.0f) >= 1.0f ? copysignf(PI * 0.5f, s) : s;

    s = 2.0f * (q.w * q.z + q.y * q.x);
    c = 1.0f - 2.0f * (q.y * q.y + q.z * q.z);
    const float y = atan2f(s, c);
    return vec3(r, p, y);
}

/* END OF VMATH_BUILD_QUAT */
#endif

/**************************
* Matrix 2x2
**************************/
#if VMATH_BUILD_MAT2
/**
 *
 */
__vmath__ mat2_t mat2_neg(mat2_arg_t m)
{
    mat2_t r;
    r.vec4 = vec4_neg(m.vec4);
    return r;
}

/**
 * Addition of 2 matrix 2x2
 */
__vmath__ mat2_t mat2_add(mat2_arg_t a, mat2_arg_t b)
{
    mat2_t r;
    r.vec4 = vec4_add(a.vec4, b.vec4);
    return r;
}

/**
 * Subtraction of 2 matrix 2x2
 */
__vmath__ mat2_t mat2_sub(mat2_arg_t a, mat2_arg_t b)
{
    mat2_t r;
    r.vec4 = vec4_sub(a.vec4, b.vec4);
    return r;
}

/**
 * Multiplication of 2 matrix 2x2
 */
__vmath__ mat2_t mat2_mul(mat2_arg_t a, mat2_arg_t b)
{
#if VMATH_SSE_ENABLE
    mat2_t r;

    const __m128 tmp  = _mm_shuffle_ps(
        a.vec4.data, a.vec4.data, _MM_SHUFFLE(3, 1, 2, 0));
    
    r.vec4.data = _mm_hadd_ps(
        _mm_mul_ps(
            tmp, 
            _mm_shuffle_ps(
                b.vec4.data, b.vec4.data, _MM_SHUFFLE(1, 0, 1, 0))),
        _mm_mul_ps(
            tmp, 
            _mm_shuffle_ps(
                b.vec4.data, b.vec4.data, _MM_SHUFFLE(3, 2, 3, 2))));
    return r;
#else
    return mat2(
        a.m00 * b.m00 + a.m10 * b.m01, 
        a.m01 * b.m00 + a.m11 * b.m01, 
        a.m00 * b.m10 + a.m10 * b.m11, 
        a.m01 * b.m10 + a.m11 * b.m11
    );
#endif
}

/**
 * Multiplication of a matrix 2x2 with a scalar (scaling the components)
 */
__vmath__ mat2_t mat2_mulf(mat2_arg_t m, float s)
{
    mat2_t r;
    r.vec4 = vec4_mulf(m.vec4, s);
    return r;
}

/**
 * Division of a matrix 2x2 with a scalar (invert scaling the components)
 */
__vmath__ mat2_t mat2_divf(mat2_arg_t m, float s)
{
    mat2_t r;
    r.vec4 = vec4_divf(m.vec4, s);
    return r;
}

/**
 * Test if 2 matrix 2x2 is equal
 */                             
__vmath__ bool   mat2_equal(mat2_arg_t a, mat2_arg_t b)
{
    return vec4_equal(a.vec4, b.vec4);
}

/**
 * Get the transpose version of the given matrix 2x2 (rotate left the matrix)
 */
__vmath__ mat2_t mat2_transpose(mat2_arg_t m)
{
#if VMATH_SSE_ENABLE
    mat2_t r;
    r.vec4.data = _mm_shuffle_ps(m.vec4.data, m.vec4.data, _MM_SHUFFLE(3, 1, 2, 0));
    return r;
#else
    return mat2(m.m00, m.m10, m.m01, m.m11);
#endif
}

/**
 *
 */
__vmath__ float mat2_det(mat2_arg_t m)
{
    (void)m;
    return 0.0f;
}

/**
 *
 */
__vmath__ mat2_t mat2_inverse(mat2_arg_t m)
{
    (void)m;
    return MAT2_IDENTITY;
}

/**
 *
 */
__vmath__ vec2_t mat2_mulv2(mat2_arg_t m, vec2_arg_t v)
{
    return vec2(
        vec2_dot(vec2(m.m00, m.m01), v),
        vec2_dot(vec2(m.m10, m.m11), v)
    );
}

/* END OF VMATH_BUILD_MAT2 */
#endif

/**************************
* Matrix 3x3
**************************/
#if VMATH_BUILD_MAT3
/**
 *
 */
__vmath__ mat2_t mat3_tomat2(mat3_arg_t m)
{
    mat2_t r;
    r.m00 = m.m00;
    r.m01 = m.m01;
    r.m10 = m.m10;
    r.m11 = m.m11;
    return r;
}

/**
 *
 */
__vmath__ mat4_t mat3_tomat4(mat3_arg_t m)
{
    mat4_t r;
    r.rows[0] = vec4(m.m00, m.m01, m.m02, 0);
    r.rows[1] = vec4(m.m10, m.m11, m.m12, 0);
    r.rows[2] = vec4(m.m20, m.m21, m.m22, 0);
    r.rows[3] = vec4(    0,     0,     0, 0);
    return r;
}

/**
 * Transpose matrix3x3
 */
__vmath__ mat3_t mat3_transpose(mat3_arg_t m)
{
    mat3_t r;
    r.m00 = m.m00; r.m01 = m.m10; r.m02 = m.m20;
    r.m10 = m.m01; r.m11 = m.m11; r.m12 = m.m21;
    r.m20 = m.m02; r.m12 = m.m12; r.m22 = m.m22;
    return r;
}

/**
 * Addition of two matrix 3x3
 */
__vmath__ mat3_t mat3_add(mat3_arg_t a, mat3_arg_t b)
{
    mat3_t r;
    r.m00 = a.m00 + b.m00; r.m01 = a.m01 + b.m01; r.m02 = a.m02 + b.m02;
    r.m10 = a.m10 + b.m10; r.m11 = a.m11 + b.m11; r.m12 = a.m12 + b.m12;
    r.m20 = a.m20 + b.m20; r.m21 = a.m21 + b.m21; r.m22 = a.m22 + b.m22;
    return r;
}

/**
 * Subtraction of two matrix 3x3
 */
__vmath__ mat3_t mat3_sub(mat3_arg_t a, mat3_arg_t b)
{
    mat3_t r;
    r.m00 = a.m00 - b.m00; r.m01 = a.m01 - b.m01; r.m02 = a.m02 - b.m02;
    r.m10 = a.m10 - b.m10; r.m11 = a.m11 - b.m11; r.m12 = a.m12 - b.m12;
    r.m20 = a.m20 - b.m20; r.m21 = a.m21 - b.m21; r.m22 = a.m22 - b.m22;
    return r;
}

/**
 * Multiplication of two matrix 3x3
 */
__vmath__ mat3_t mat3_mul(mat3_arg_t a, mat3_arg_t b)
{
    mat3_t r;
    r.m00 = a.m00 * b.m00 + a.m10 * b.m01 + a.m20 * b.m02;
    r.m01 = a.m01 * b.m00 + a.m11 * b.m01 + a.m21 * b.m02;
    r.m02 = a.m02 * b.m00 + a.m12 * b.m01 + a.m22 * b.m02;

    r.m10 = a.m00 * b.m10 + a.m10 * b.m11 + a.m20 * b.m12;
    r.m11 = a.m01 * b.m10 + a.m11 * b.m11 + a.m21 * b.m12;
    r.m12 = a.m02 * b.m10 + a.m12 * b.m11 + a.m22 * b.m12;
      
    r.m20 = a.m00 * b.m20 + a.m10 * b.m21 + a.m20 * b.m22;
    r.m21 = a.m01 * b.m20 + a.m11 * b.m21 + a.m21 * b.m22;
    r.m22 = a.m02 * b.m20 + a.m12 * b.m21 + a.m22 * b.m22;
    return r;
}

/**
 *
 */
__vmath__ mat3_t mat3_mulf(mat3_arg_t m, float s)
{
    mat3_t r;
    r.m00 = m.m00 * s; r.m01 = m.m01 * s; r.m02 = m.m02 * s;
    r.m10 = m.m10 * s; r.m11 = m.m11 * s; r.m12 = m.m12 * s;
    r.m20 = m.m20 * s; r.m21 = m.m21 * s; r.m22 = m.m22 * s;
    return r;
}

/**
 *
 */
__vmath__ mat3_t mat3_divf(mat3_arg_t m, float s)
{
    return mat3_mulf(m, 1.0f / s);
}

/**
 * Compare if two matrices is equal or not
 * @return: true is equal, false otherwise
 */
__vmath__ bool mat3_equal(mat3_arg_t a, mat3_arg_t b)
{
    return
        a.m00 == b.m00 && a.m01 == b.m01 && a.m02 == b.m02 &&
        a.m10 == b.m10 && a.m11 == b.m11 && a.m12 == b.m12 &&
        a.m20 == b.m20 && a.m21 == b.m21 && a.m22 == b.m22;
}

/**
 *
 */
__vmath__ mat3_t mat3_neg(mat3_arg_t m)
{
    mat3_t r;
    r.m00 = -m.m00; r.m01 = -m.m01; r.m02 = -m.m02;
    r.m10 = -m.m10; r.m11 = -m.m11; r.m12 = -m.m12;
    r.m20 = -m.m20; r.m21 = -m.m21; r.m22 = -m.m22;
    return r;
}

/**
 * Calculate determinant of a matrix3x3
 */
__vmath__ float mat3_det(mat3_arg_t m)
{
    return 
          m.m00 * m.m11 * m.m22 - m.m00 * m.m12 * m.m21
        + m.m01 * m.m10 * m.m22 - m.m01 * m.m12 * m.m20
        + m.m02 * m.m10 * m.m21 - m.m02 * m.m11 * m.m20;
}

/**
 * Get inverted version of a matrix3x3
 */
__vmath__ mat3_t mat3_inverse(mat3_arg_t m)
{
    float d = mat3_det(m);
    if (d == 0.0f)
    {
        return m;
    }

    d = 1.0f / d;

    mat3_t r;
    r.m00 = d * (m.m11 * m.m22 - m.m12 * m.m21);
    r.m01 = d * (m.m02 * m.m21 - m.m01 * m.m22);
    r.m02 = d * (m.m01 * m.m12 - m.m02 * m.m11);

    r.m10 = d * (m.m12 * m.m20 - m.m10 * m.m22);
    r.m11 = d * (m.m00 * m.m22 - m.m02 * m.m20);
    r.m12 = d * (m.m02 * m.m10 - m.m00 * m.m12);

    r.m20 = d * (m.m10 * m.m21 - m.m11 * m.m20);
    r.m21 = d * (m.m01 * m.m20 - m.m00 * m.m21);
    r.m22 = d * (m.m00 * m.m11 - m.m01 * m.m10); 
    return r;
}

/**
 * Multiplication between Matrix3x3 and Vector3D
 */
__vmath__ vec3_t mat3_mulv3(mat3_arg_t m, vec3_arg_t v)
{
    const vec3_t c0 = vec3(m.m00, m.m10, m.m20);
    const vec3_t c1 = vec3(m.m01, m.m11, m.m21);
    const vec3_t c2 = vec3(m.m02, m.m12, m.m22);

    const float x = vec3_dot(c0, v);
    const float y = vec3_dot(c1, v);
    const float z = vec3_dot(c2, v);
    return vec3(x, y, z);
}

/* END OF VMATH_BUILD_MAT3 */
#endif

/**************************
* Matrix 4x4
**************************/
#if VMATH_BUILD_MAT4
/**
 * Convert matrix 4x4 to matrix 2x2
 */
__vmath__ mat2_t mat4_tomat2(mat4_arg_t m)
{
    mat2_t r;
    r.rows[0] = vec2(m.m00, m.m01);
    r.rows[1] = vec2(m.m10, m.m11);
    return r;
}

/**
 * Convert matrix 4x4 to matrix 3x3
 */
__vmath__ mat3_t mat4_tomat3(mat4_arg_t m)
{
    mat3_t r;
    r.m00 = m.m00; r.m01 = m.m01, r.m02 = m.m02;
    r.m10 = m.m10; r.m11 = m.m11, r.m12 = m.m12;
    r.m20 = m.m20; r.m21 = m.m21, r.m22 = m.m22;
    return r;
}

/**
 * Create translate matrix
 */
__vmath__ mat4_t mat4_translate3f(float x, float y, float z)
{				
    mat4_t r;
    r.rows[0] = vec4(1, 0, 0, 0);
    r.rows[1] = vec4(0, 1, 0, 0);
    r.rows[2] = vec4(0, 0, 1, 0);
    r.rows[3] = vec4(x, y, z, 1);
    return r;
}

/**
 *
 */
__vmath__ mat4_t mat4_translate2f(float x, float y)
{
    return mat4_translate3f(x, y, 0);
}

/**
 *
 */
__vmath__ mat4_t mat4_translatev2(vec2_arg_t v)
{
    return mat4_translate3f(v.x, v.y, 0.0);
}

/**
 *
 */
__vmath__ mat4_t mat4_translatev3(vec3_arg_t v)
{
    return mat4_translate3f(v.x, v.y, v.z);
}

/**
 * Create scale matrix
 */
__vmath__ mat4_t mat4_scale3f(float x, float y, float z)
{
    mat4_t r;
    r.rows[0] = vec4(x, 0, 0, 0);
    r.rows[1] = vec4(0, y, 0, 0);
    r.rows[2] = vec4(0, 0, z, 0);
    r.rows[3] = vec4(0, 0, 0, 1);
    return r;
}

/**
 *
 */
__vmath__ mat4_t mat4_scale1f(float s)
{
    return mat4_scale3f(s, s, s);
}

/**
 *
 */
__vmath__ mat4_t mat4_scale2f(float x, float y)
{
    return mat4_scale3f(x, y, 1.0);
}

/**
 *
 */
__vmath__ mat4_t mat4_scalev2(vec2_arg_t v)
{
    return mat4_scale3f(v.x, v.y, 1.0);
}

/**
 *
 */
__vmath__ mat4_t mat4_scalev3(vec3_arg_t v)
{
    return mat4_scale3f(v.x, v.y, v.z);
}

/**
 * Create mat4 rotate in X-axis matrix
 */
__vmath__ mat4_t mat4_rotatex(float angle)
{
    const float c = cosf(angle);
    const float s = sinf(angle);

    mat4_t r;
    r.rows[0] = vec4(1,  0, 0, 0);
    r.rows[1] = vec4(0,  c, s, 0);
    r.rows[2] = vec4(0, -s, c, 0);
    r.rows[3] = vec4(0,  0, 0, 1);
    return r;
}

/**
 * Create mat4 rotate in Y-axis matrix
 */
__vmath__ mat4_t mat4_rotatey(float angle)
{
    const float c = cosf(angle);
    const float s = sinf(angle);

    mat4_t r;
    r.rows[0] = vec4( c, 0, s, 0);
    r.rows[1] = vec4( 0, 1, 0, 0);
    r.rows[2] = vec4(-s, 0, c, 0);
    r.rows[3] = vec4( 0, 0, 0, 1);
    return r;
}

/**
 * Create mat4 rotate in Z-axis matrix
 */
__vmath__ mat4_t mat4_rotatez(float angle)
{
    const float c = cosf(angle);
    const float s = sinf(angle);

    mat4_t r;
    r.rows[0] = vec4( c, s, 0, 0);
    r.rows[1] = vec4(-s, c, 0, 0);
    r.rows[2] = vec4( 0, 0, 1, 0);
    r.rows[3] = vec4( 0, 0, 0, 1);
    return r;
}

/**
 * Create mat4 rotate matrix
 */
__vmath__ mat4_t mat4_rotate3f(float x, float y, float z, float angle)
{
    const float c = cosf(-angle);
    const float s = sinf(-angle);
    const float t = 1.0f - c;
  
    mat4_t r;
    /* Row 1 */
    r.rows[0] = vec4(t * x * x + c,
                     t * x * y - s * z,
                     t * x * z + s * y,
		     0.0f);

    /* Row 2 */
    r.rows[1] = vec4(t * x * y + s * z,
		     t * y * y + c,
		     t * y * z - s * x,
		     0.0f);

    /* Row 3 */
    r.rows[2] = vec4(t * x * z - s * y,
		     t * y * z + s * x,
		     t * z * z + c,
		     0.0f);

    /* Row 4 */
    r.rows[3] = vec4(0, 0, 0, 1.0f);
    return r;
}

/**
 * Create rotate matrix with axis and angle
 */
__vmath__ mat4_t mat4_rotatev3(vec3_arg_t v, float angle)
{
    return mat4_rotate3f(v.x, v.y, v.z, angle);
}

/**
 * Create rotation matrix from quaternion
 */
__vmath__ mat4_t mat4_rotateq(quat_arg_t q)
{
    const vec4_t aa = quat_toaxis(q); /* axis-angle form of quaternion */
    return mat4_rotatev3(aa.xyz, aa.w);
}

/**
 * Multiplication between Matrix4x4 and Vector4D
 */
__vmath__ vec4_t mat4_mulv4(mat4_arg_t m, vec4_arg_t v)
{
    const vec4_t c0 = vec4(m.m00, m.m10, m.m20, m.m30);
    const vec4_t c1 = vec4(m.m01, m.m11, m.m21, m.m31);
    const vec4_t c2 = vec4(m.m02, m.m12, m.m22, m.m32);
    const vec4_t c3 = vec4(m.m03, m.m13, m.m23, m.m33);

    const float x = vec4_dot(c0, v);
    const float y = vec4_dot(c1, v);
    const float z = vec4_dot(c2, v);
    const float w = vec4_dot(c3, v);

    return vec4(x, y, z, w);
}

/**
 * Multiplication between Matrix4x4 and Vector3D
 */
__vmath__ vec3_t mat4_mulv3(mat4_arg_t m, vec3_arg_t v)
{
    vec4_t v4 = mat4_mulv4(m, vec4(v.x, v.y, v.z, 1.0f));
    return vec3(v4.x / v4.w, v4.y / v4.w, v4.z / v4.w);
}

/**
 * Addidtion of two matrix4x4
 */
__vmath__ mat4_t mat4_add(mat4_arg_t a, mat4_arg_t b)
{
    mat4_t r;
    r.rows[0] = vec4_add(a.rows[0], b.rows[0]);
    r.rows[1] = vec4_add(a.rows[1], b.rows[1]);
    r.rows[2] = vec4_add(a.rows[2], b.rows[2]);
    r.rows[3] = vec4_add(a.rows[3], b.rows[3]);
    return r;
}

/**
 * Subtraction of two matrix4x4
 */
__vmath__ mat4_t mat4_sub(mat4_arg_t a, mat4_arg_t b)
{
    mat4_t r;
    r.rows[0] = vec4_sub(a.rows[0], b.rows[0]);
    r.rows[1] = vec4_sub(a.rows[1], b.rows[1]);
    r.rows[2] = vec4_sub(a.rows[2], b.rows[2]);
    r.rows[3] = vec4_sub(a.rows[3], b.rows[3]);
    return r;
}

/**
 * Multiplication of two matrix4x4
 */
__vmath__ mat4_t mat4_mul(mat4_arg_t a, mat4_arg_t b)
{
    mat4_t r;
    r.rows[0] = mat4_mulv4(a, b.rows[0]);
    r.rows[1] = mat4_mulv4(a, b.rows[1]);
    r.rows[2] = mat4_mulv4(a, b.rows[2]);
    r.rows[3] = mat4_mulv4(a, b.rows[3]);
    return r;
}

/**
 * Multiplication of a matrix 4x4 with a scalar
 */
__vmath__ mat4_t mat4_mulf(mat4_arg_t m, float s)
{
    mat4_t r;
    r.rows[0] = vec4_mulf(m.rows[0], s);
    r.rows[1] = vec4_mulf(m.rows[1], s);
    r.rows[2] = vec4_mulf(m.rows[2], s);
    r.rows[3] = vec4_mulf(m.rows[3], s);
    return r;
}         

/**
 * Multiplication of a matrix 4x4 with a scalar
 */
__vmath__ mat4_t mat4_divf(mat4_arg_t m, float s)
{
    return mat4_mulf(m, 1.0f / s);
}

/**
 * Compare if two matrix is equal or not
 * @return: true if equal, false otherwise
 */
__vmath__ bool mat4_equal(mat4_arg_t a, mat4_arg_t b)
{
    return
        vec4_equal(a.rows[0], b.rows[0]) &&
        vec4_equal(a.rows[1], b.rows[1]) &&
        vec4_equal(a.rows[2], b.rows[2]) &&
        vec4_equal(a.rows[3], b.rows[3]);
}

/**
 *
 */
__vmath__ mat4_t mat4_neg(mat4_arg_t m)
{
    mat4_t r;
    r.rows[0] = vec4_neg(m.rows[0]);
    r.rows[1] = vec4_neg(m.rows[1]);
    r.rows[2] = vec4_neg(m.rows[2]);
    r.rows[3] = vec4_neg(m.rows[3]);
    return r;
}

/**
 * Transpose matrix4x4
 */
__vmath__ mat4_t mat4_transpose(mat4_arg_t m)
{
    mat4_t r;
    r.rows[0] = vec4(m.m00, m.m10, m.m20, m.m30);
    r.rows[1] = vec4(m.m01, m.m11, m.m21, m.m31);
    r.rows[2] = vec4(m.m02, m.m12, m.m22, m.m32);
    r.rows[3] = vec4(m.m03, m.m13, m.m23, m.m33);
    return r;
}

/**
 * Create orthographic projection matrix
 */
__vmath__ mat4_t mat4_ortho(float l, float r,
			                float b, float t,
			                float n, float f)
{
    const float x = 1.0f / (r - l);
    const float y = 1.0f / (t - b);
    const float z = 1.0f / (f - n);
    
    mat4_t m;
    m.rows[0] = vec4(    2.0f * x,            0,            0,    0);
    m.rows[1] = vec4(           0,     2.0f * y,            0,    0);
    m.rows[2] = vec4(           0,            0,    -2.0f * z,    0);
    m.rows[3] = vec4(-x * (l + r), -y * (b + t), -z * (n + f), 1.0f);
    return m;
}

/**
 * Create frustum matrix
 */
__vmath__ mat4_t mat4_frustum(float l, float r,
			                  float b, float t,
			                  float n, float f)
{
    mat4_t m;
    /* Row 1 */
    m.rows[0] = vec4(2.0f / (r - l), 0, 0, 0);
    /* Row 2 */
    m.rows[1] = vec4(0, 2.0f / (t - b), 0, 0);
    /* Row 3 */
    m.rows[2] = vec4((r + l) / (r - l),
		             (t + b) / (t - b),
		             (f + b) / (f - n), 
                     1.0f);
    /* Row 4 */
    m.rows[3] = vec4(0, 0, 2.0f / (f - n), 0);
    return m;
}

/**
 * Create perspective projection matrix
 */
__vmath__ mat4_t mat4_perspective(float fov, float aspect,
				                  float znear, float zfar)
{
    const float a = 1.0f / tanf(fov * 0.5f);
    const float b = zfar / (znear - zfar);
    
    mat4_t r;
    r.rows[0] = vec4(a / aspect,   0,         0,   0);
    r.rows[1] = vec4(         0,   a,         0,   0);
    r.rows[2] = vec4(         0,   0,         b,  -1);
    r.rows[3] = vec4(         0,   0, znear * b,   0);
    return r;
}

/**
 * Create view matrix when focus on the position
 */
__vmath__ mat4_t mat4_lookat(vec3_arg_t eye, vec3_arg_t target, vec3_arg_t up)
{
    const vec3_t z = vec3_normalize(vec3_sub(eye, target));
    const vec3_t x = vec3_normalize(vec3_cross(up, z));
    const vec3_t y = vec3_normalize(vec3_cross( z, x));

    mat4_t r;
    r.rows[0] = vec4(x.x, y.x, z.x, 0);
    r.rows[1] = vec4(x.y, y.y, z.y, 0);
    r.rows[2] = vec4(x.z, y.z, z.z, 0);

    /* Row 4 */
    r.rows[3] = vec4(-vec3_dot(x, eye), 
                     -vec3_dot(y, eye), 
                     -vec3_dot(z, eye), 
                     1.0f);
    return r;
}

/**
 * Calculate deternimant value
 */
__vmath__ float mat4_det(mat4_arg_t m)
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
__vmath__ mat4_t mat4_inverse(mat4_arg_t m)
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
    if (d == 0.0f)
    {
        return m;
    }
    d = 1.0f / d;
  
    mat4_t r;
    r.m00 = d *  (m.m11 * c6 - m.m12 * c5 + m.m13 * c4);
    r.m01 = d * -(m.m01 * c6 - m.m02 * c5 + m.m03 * c4);
    r.m02 = d *  (m.m31 * s6 - m.m32 * s5 + m.m33 * s4);
    r.m03 = d * -(m.m21 * s6 - m.m22 * s5 + m.m23 * s4);
      
    r.m10 = d * -(m.m10 * c6 - m.m12 * c3 + m.m13 * c2);
    r.m11 = d *  (m.m00 * c6 - m.m02 * c3 + m.m03 * c2);
    r.m12 = d * -(m.m30 * s6 - m.m32 * s3 + m.m33 * s2);
    r.m13 = d *  (m.m20 * s6 - m.m22 * s3 + m.m23 * s2);
      
    r.m20 = d *  (m.m10 * c5 - m.m11 * c3 + m.m13 * c1);
    r.m21 = d * -(m.m00 * c5 - m.m01 * c3 + m.m03 * c1);
    r.m22 = d *  (m.m30 * s5 - m.m31 * s3 + m.m33 * s1);
    r.m23 = d * -(m.m20 * s5 - m.m21 * s3 + m.m23 * s1);

    r.m30 = d * -(m.m10 * c4 - m.m11 * c2 + m.m12 * c1);
    r.m31 = d *  (m.m00 * c4 - m.m01 * c2 + m.m02 * c1);
    r.m32 = d * -(m.m30 * s4 - m.m31 * s2 + m.m32 * s1);
    r.m33 = d *  (m.m20 * s4 - m.m21 * s2 + m.m22 * s1);
    return r;
}

/* END OF VMATH_BUILD_MAT4 */
#endif

/********
 * @endregion: Functions define
 ********/

/**************************
* @region: Functions overloading
**************************/
#if defined(__cplusplus) && VMATH_FUNCTION_OVERLOADING != 0

#undef min
#undef max

/**************************
 * Float functions
 **************************/
__vmath__ float dot(float a, float b)
{
    return dotf(a, b);
}

__vmath__ float length(float x)
{
    return lengthf(x);
}

__vmath__ float distance(float a, float b)
{
    return distancef(a, b);
}

__vmath__ float normalize(float x)
{
    return 1.0f;
}

__vmath__ float min(float a, float b)
{
    return minf(a, b);
}

__vmath__ float max(float a, float b)
{
    return maxf(a, b);
}

__vmath__ float mix(float a, float b, float t)
{
    return mixf(a, b, t);
}

__vmath__ float step(float a, float b, float t)
{
    return stepf(a, b, t);
}

__vmath__ float smoothstep(float a, float b, float t)
{
    return smoothstepf(a, b, t);
}

__vmath__ float clamp(float v, float min, float max)
{
    return clampf(v, min, max);
}

__vmath__ float reflect(float i, float n)
{
    return reflectf(i, n);
}

__vmath__ float refract(float i, float n, float eta)
{
    return refractf(i, n, eta);
}

__vmath__ float faceforward(float n, float i, float nref)
{
    return faceforwardf(n, i, nref);
}

/**************************
 * Vector2D functions
 **************************/
#if VMATH_BUILD_VEC2
__vmath__ vec2_t add(const vec2_t& a, const vec2_t& b)
{
    return vec2_add(a, b);
}

__vmath__ vec2_t sub(const vec2_t& a, const vec2_t& b)
{
    return vec2_sub(a, b);
}

__vmath__ vec2_t mul(const vec2_t& a, const vec2_t& b)
{
    return vec2_mul(a, b);
}

__vmath__ vec2_t div(const vec2_t& a, const vec2_t& b)
{
    return vec2_div(a, b);
}

__vmath__ vec2_t add(const vec2_t& v, float s)
{
    return vec2_addf(v, s);
}

__vmath__ vec2_t sub(const vec2_t& v, float s)
{
    return vec2_subf(v, s);
}

__vmath__ vec2_t mul(const vec2_t& v, float s)
{
    return vec2_mulf(v, s);
}

__vmath__ vec2_t div(const vec2_t& v, float s)
{
    return vec2_divf(v, s);
}

__vmath__ vec2_t add(float s, const vec2_t& v)
{
    return vec2_addf(v, s);
}

__vmath__ vec2_t sub(float s, const vec2_t& v)
{
    return vec2_sub(vec2(s), v);
}

__vmath__ vec2_t mul(float s, const vec2_t& v)
{
    return vec2_mulf(v, s);
}

__vmath__ vec2_t div(float s, const vec2_t& v)
{
    return vec2_div(vec2(s), v);
}

__vmath__ vec2_t neg(const vec2_t& v)
{
    return vec2_neg(v);
}

__vmath__ float dot(const vec2_t& a, const vec2_t& b)
{
    return vec2_dot(a, b);
}

__vmath__ float length(const vec2_t& v)
{
    return vec2_length(v);
}

__vmath__ float lengthsquared(const vec2_t& v)
{
    return vec2_lengthsquared(v);
}

__vmath__ float distance(const vec2_t& a, const vec2_t& b)
{
    return vec2_distance(a, b);
}

__vmath__ float distancesquared(const vec2_t& a, const vec2_t& b)
{
    return vec2_distancesquared(a, b);
}

__vmath__ vec2_t reflect(const vec2_t& v, const vec2_t& n)
{
    return vec2_reflect(v, n);
}

__vmath__ vec2_t normalize(const vec2_t& v)
{
    return vec2_normalize(v);
}

__vmath__ vec2_t min(const vec2_t& a, const vec2_t& b)
{
    return vec2_min(a, b);
}

__vmath__ vec2_t max(const vec2_t& a, const vec2_t& b)
{
    return vec2_max(a, b);
}

__vmath__ vec2_t clamp(const vec2_t& v, const vec2_t& min, const vec2_t& max)
{
    return vec2_clamp(v, min, max);
}

__vmath__ vec2_t clamplength(const vec2_t& v, float min, float max)
{
    return vec2_clamplength(v, min, max);
}

__vmath__ vec2_t min(const vec2_t& a, float b)
{
    return vec2_minf(a, b);
}                 

__vmath__ vec2_t max(const vec2_t& a, float b)
{
    return vec2_maxf(a, b);
}

__vmath__ vec2_t min(float a, const vec2_t& b)
{
    return vec2_minf(b, a);
}

__vmath__ vec2_t max(float a, const vec2_t& b)
{
    return vec2_maxf(b, a);
}

__vmath__ vec2_t clamp(const vec2_t& v, float min, float max)
{
    return vec2_clampf(v, min, max);
}

__vmath__ vec2_t step(const vec2_t& a, const vec2_t& b, const vec2_t& t)
{
    return vec2_step(a, b, t);
}

__vmath__ vec2_t step(const vec2_t& a, const vec2_t& b, float t)
{
    return vec2_stepf(a, b, t);
}

__vmath__ vec2_t smoothstep(const vec2_t& a, const vec2_t& b, const vec2_t& t)
{
    return vec2_smoothstep(a, b, t);
}

__vmath__ vec2_t smoothstep(const vec2_t& a, const vec2_t& b, float t)
{
    return vec2_smoothstepf(a, b, t);
}

__vmath__ vec2_t mix(const vec2_t& a, const vec2_t& b, const vec2_t& t)
{
    return vec2_mix(a, b, t);
}

__vmath__ vec2_t mix(const vec2_t& a, const vec2_t& b, float t)
{
    return vec2_mixf(a, b, t);
}

__vmath__ vec2_t refract(const vec2_t& i, const vec2_t& n, float eta)
{
    return vec2_refract(i, n, eta);
}

__vmath__ vec2_t faceforward(const vec2_t& n, const vec2_t& i, const vec2_t& nref)
{
    return vec2_faceforward(n, i, nref);
}

/* END OF VMATH_BUILD_VEC2 */
#endif

/**************************
 * Vector3D functions
 **************************/ 
#if VMATH_BUILD_VEC3
__vmath__ vec3_t add(const vec3_t& a, const vec3_t& b)
{
    return vec3_add(a, b);
}

__vmath__ vec3_t sub(const vec3_t& a, const vec3_t& b)
{
    return vec3_sub(a, b);
}

__vmath__ vec3_t mul(const vec3_t& a, const vec3_t& b)
{
    return vec3_mul(a, b);
}

__vmath__ vec3_t div(const vec3_t& a, const vec3_t& b)
{
    return vec3_div(a, b);
}

__vmath__ vec3_t add(const vec3_t& v, float s)
{
    return vec3_addf(v, s);
}

__vmath__ vec3_t sub(const vec3_t& v, float s)
{
    return vec3_subf(v, s);
}

__vmath__ vec3_t mul(const vec3_t& v, float s)
{
    return vec3_mulf(v, s);
}

__vmath__ vec3_t div(const vec3_t& v, float s)
{
    return vec3_divf(v, s);
}

__vmath__ vec3_t add(float s, const vec3_t& v)
{
    return vec3_addf(v, s);
}

__vmath__ vec3_t sub(float s, const vec3_t& v)
{
    return vec3_sub(vec3(s), v);
}

__vmath__ vec3_t mul(float s, const vec3_t& v)
{
    return vec3_mulf(v, s);
}

__vmath__ vec3_t div(float s, const vec3_t& v)
{
    return vec3_div(vec3(s), v);
}

__vmath__ vec3_t neg(const vec3_t& v)
{
    return vec3_neg(v);
}

__vmath__ float dot(const vec3_t& a, const vec3_t& b)
{
    return vec3_dot(a, b);
}

__vmath__ float length(const vec3_t& v)
{
    return vec3_length(v);
}

__vmath__ float lengthsquared(const vec3_t& v)
{
    return vec3_lengthsquared(v);
}

__vmath__ float distance(const vec3_t& a, const vec3_t& b)
{
    return vec3_distance(a, b);
}

__vmath__ float distancesquared(const vec3_t& a, const vec3_t& b)
{
    return vec3_distancesquared(a, b);
}

__vmath__ vec3_t cross(const vec3_t& a, const vec3_t& b)
{
    return vec3_cross(a, b);
}

__vmath__ vec3_t reflect(const vec3_t& v, const vec3_t& n)
{
    return vec3_reflect(v, n);
}

__vmath__ vec3_t normalize(const vec3_t& v)
{
    return vec3_normalize(v);
}

__vmath__ vec3_t min(const vec3_t& a, const vec3_t& b)
{
    return vec3_min(a, b);
}

__vmath__ vec3_t max(const vec3_t& a, const vec3_t& b)
{
    return vec3_max(a, b);
}

__vmath__ vec3_t clamp(const vec3_t& v, const vec3_t& min, const vec3_t& max)
{
    return vec3_clamp(v, min, max);
}

__vmath__ vec3_t clamplength(const vec3_t& v, float min, float max)
{
    return vec3_clamplength(v, min, max);
}

__vmath__ vec3_t min(const vec3_t& a, float b)
{
    return vec3_minf(a, b);
}

__vmath__ vec3_t max(const vec3_t& a, float b)
{
    return vec3_maxf(a, b);
}

__vmath__ vec3_t min(float a, const vec3_t& b)
{
    return vec3_minf(b, a);
}

__vmath__ vec3_t max(float a, const vec3_t& b)
{
    return vec3_maxf(b, a);
}

__vmath__ vec3_t clamp(const vec3_t& v, float min, float max)
{
    return vec3_clampf(v, min, max);
}

__vmath__ vec3_t step(const vec3_t& a, const vec3_t& b, const vec3_t& t)
{
    return vec3_step(a, b, t);
}

__vmath__ vec3_t step(const vec3_t& a, const vec3_t& b, float t)
{
    return vec3_stepf(a, b, t);
}

__vmath__ vec3_t smoothstep(const vec3_t& a, const vec3_t& b, const vec3_t& t)
{
    return vec3_smoothstep(a, b, t);
}

__vmath__ vec3_t smoothstep(const vec3_t& a, const vec3_t& b, float t)
{
    return vec3_smoothstepf(a, b, t);
}

__vmath__ vec3_t mix(const vec3_t& a, const vec3_t& b, const vec3_t& t)
{
    return vec3_mix(a, b, t);
}

__vmath__ vec3_t mix(const vec3_t& a, const vec3_t& b, float t)
{
    return vec3_mixf(a, b, t);
}

__vmath__ vec3_t refract(const vec3_t& i, const vec3_t& n, float eta)
{
    return vec3_refract(i, n, eta);
}

__vmath__ vec3_t faceforward(const vec3_t& n, const vec3_t& i, const vec3_t& nref)
{
    return vec3_faceforward(n, i, nref);
}

/* END OF VMATH_BUILD_VEC3 */
#endif

/**************************
 * Vector4D functions
 **************************/
#if VMATH_BUILD_VEC4
__vmath__ vec4_t add(const vec4_t& a, const vec4_t& b)
{
    return vec4_add(a, b);
}

__vmath__ vec4_t sub(const vec4_t& a, const vec4_t& b)
{
    return vec4_sub(a, b);
}

__vmath__ vec4_t mul(const vec4_t& a, const vec4_t& b)
{
    return vec4_mul(a, b);
}

__vmath__ vec4_t div(const vec4_t& a, const vec4_t& b)
{
    return vec4_div(a, b);
}

__vmath__ vec4_t add(const vec4_t& v, float s)
{
    return vec4_addf(v, s);
}

__vmath__ vec4_t sub(const vec4_t& v, float s)
{
    return vec4_subf(v, s);
}

__vmath__ vec4_t mul(const vec4_t& v, float s)
{
    return vec4_mulf(v, s);
}

__vmath__ vec4_t div(const vec4_t& v, float s)
{
    return vec4_divf(v, s);
}

__vmath__ vec4_t add(float s, const vec4_t& v)
{
    return vec4_addf(v, s);
}

__vmath__ vec4_t sub(float s, const vec4_t& v)
{
    return vec4_sub(vec4(s), v);
}

__vmath__ vec4_t mul(float s, const vec4_t& v)
{
    return vec4_mulf(v, s);
}

__vmath__ vec4_t div(float s, const vec4_t& v)
{
    return vec4_div(vec4(s), v);
}

__vmath__ vec4_t neg(const vec4_t& v)
{
    return vec4_neg(v);
}

__vmath__ float dot(const vec4_t& a, const vec4_t& b)
{
    return vec4_dot(a, b);
}

__vmath__ float length(const vec4_t& v)
{
    return vec4_length(v);
}

__vmath__ float lengthsquared(const vec4_t& v)
{
    return vec4_lengthsquared(v);
}

__vmath__ float distance(const vec4_t& a, const vec4_t& b)
{
    return vec4_distance(a, b);
}

__vmath__ float distancesquared(const vec4_t& a, const vec4_t& b)
{
    return vec4_distancesquared(a, b);
}

__vmath__ vec4_t reflect(const vec4_t& v, const vec4_t& n)
{
    return vec4_reflect(v, n);
}

__vmath__ vec4_t normalize(const vec4_t& v)
{
    return vec4_normalize(v);
}

__vmath__ vec4_t min(const vec4_t& a, const vec4_t& b)
{
    return vec4_min(a, b);
}

__vmath__ vec4_t max(const vec4_t& a, const vec4_t& b)
{
    return vec4_max(a, b);
}

__vmath__ vec4_t clamp(const vec4_t& v, const vec4_t& min, const vec4_t& max)
{
    return vec4_clamp(v, min, max);
}

__vmath__ vec4_t clamplength(const vec4_t& v, float min, float max)
{
    return vec4_clamplength(v, min, max);
}

__vmath__ vec4_t min(const vec4_t& a, float b)
{
    return vec4_minf(a, b);
}

__vmath__ vec4_t max(const vec4_t& a, float b)
{
    return vec4_maxf(a, b);
}

__vmath__ vec4_t min(float a, const vec4_t& b)
{
    return vec4_minf(b, a);
}

__vmath__ vec4_t max(float a, const vec4_t& b)
{
    return vec4_maxf(b, a);
}

__vmath__ vec4_t clamp(const vec4_t& v, float min, float max)
{
    return vec4_clampf(v, min, max);
}

__vmath__ vec4_t step(const vec4_t& a, const vec4_t& b, const vec4_t& t)
{
    return vec4_step(a, b, t);
}

__vmath__ vec4_t step(const vec4_t& a, const vec4_t& b, float t)
{
    return vec4_stepf(a, b, t);
}

__vmath__ vec4_t smoothstep(const vec4_t& a, const vec4_t& b, const vec4_t& t)
{
    return vec4_smoothstep(a, b, t);
}

__vmath__ vec4_t smoothstep(const vec4_t& a, const vec4_t& b, float t)
{
    return vec4_smoothstepf(a, b, t);
}

__vmath__ vec4_t mix(const vec4_t& a, const vec4_t& b, const vec4_t& t)
{
    return vec4_mix(a, b, t);
}

__vmath__ vec4_t mix(const vec4_t& a, const vec4_t& b, float t)
{
    return vec4_mixf(a, b, t);
}

__vmath__ vec4_t refract(const vec4_t& i, const vec4_t& n, float eta)
{
    return vec4_refract(i, n, eta);
}

__vmath__ vec4_t faceforward(const vec4_t& n, const vec4_t& i, const vec4_t& nref)
{
    return vec4_faceforward(n, i, nref);
}

/* END OF VMATH_BUILD_VEC4 */
#endif

/**************************
 * Quaternion functions
 **************************/
#if VMATH_BUILD_QUAT
__vmath__ quat_t add(const quat_t& a, const quat_t& b)
{
    return quat_add(a, b);
}

__vmath__ quat_t sub(const quat_t& a, const quat_t& b)
{
    return quat_sub(a, b);
}

__vmath__ quat_t mul(const quat_t& a, const quat_t& b)
{
    return quat_mul(a, b);
}

__vmath__ quat_t mul(float s, const quat_t& q)
{
    return quat_mulf(q, s);
}

__vmath__ quat_t mul(const quat_t& q, float s)
{
    return quat_mulf(q, s);
}

__vmath__ quat_t neg(const quat_t& q)
{
    return quat_neg(q);
}

__vmath__ quat_t inverse(const quat_t& q)
{
    return quat_inverse(q);
}

/**
 * Make euler angle, present in quaternion
 */
__vmath__ quat_t euler(float x, float y, float z)
{
    return quat_euler(x, y, z);
}

/**
 * Make euler angle, present in quaternion
 */
__vmath__ quat_t euler(const vec3_t& v)
{
    return quat_eulerv3(v);
}

__vmath__ vec3_t toeuler(const quat_t& q)
{
    return quat_toeuler(q);
}

/**
 * Convert quaternion to axis-angle presentation
 */
__vmath__ vec4_t toaxis(const quat_t& q)
{
    return quat_toaxis(q);
}
#endif

/**************************
 * Matrix 2x2 functions
 **************************/
#if VMATH_BUILD_MAT2
__vmath__ mat2_t neg(const mat2_t& m)
{
    return mat2_neg(m);
}

__vmath__ mat2_t add(const mat2_t& a, const mat2_t& b)
{
    return mat2_add(a, b);
}

__vmath__ mat2_t sub(const mat2_t& a, const mat2_t& b)
{
    return mat2_sub(a, b);
}

__vmath__ mat2_t mul(const mat2_t& a, const mat2_t& b)
{
    return mat2_mul(a, b);
}

__vmath__ mat2_t mul(const mat2_t& m, float s)
{
    return mat2_mulf(m, s);
}

__vmath__ mat2_t mul(float s, const mat2_t& m)
{
    return mat2_mulf(m, s);
}

__vmath__ vec2_t mul(const mat2_t& m, const vec2_t& v)
{
    return mat2_mulv2(m, v);
}

__vmath__ mat2_t inverse(const mat2_t& m)
{
    return mat2_inverse(m);
}

__vmath__ mat2_t transpose(const mat2_t& m)
{
    return mat2_transpose(m);
}

/* END OF VMATH_BUILD_MAT2 */
#endif

/**************************
 * Matrix 3x3 functions
 **************************/
#if VMATH_BUILD_MAT3
__vmath__ mat3_t neg(const mat3_t& m)
{
    return mat3_neg(m);
}

__vmath__ mat3_t add(const mat3_t& a, const mat3_t& b)
{
    return mat3_add(a, b);
}

__vmath__ mat3_t sub(const mat3_t& a, const mat3_t& b)
{
    return mat3_sub(a, b);
}

__vmath__ mat3_t mul(const mat3_t& a, const mat3_t& b)
{
    return mat3_mul(a, b);
}

__vmath__ mat3_t mul(const mat3_t& m, float s)
{
    return mat3_mulf(m, s);
}

__vmath__ mat3_t mul(float s, const mat3_t& m)
{
    return mat3_mulf(m, s);
}

__vmath__ vec3_t mul(const mat3_t& m, const vec3_t& v)
{
    return mat3_mulv3(m, v);
}

__vmath__ mat3_t inverse(const mat3_t& m)
{
    return mat3_inverse(m);
}

__vmath__ mat3_t transpose(const mat3_t& m)
{
    return mat3_transpose(m);
}

/* END OF VMATH_BUILD_MAT3 */
#endif  

/**************************
 * Matrix 4x4 functions overloading
 **************************/
#if VMATH_BUILD_MAT4
__vmath__ mat4_t neg(const mat4_t& m)
{
    return mat4_neg(m);
}

__vmath__ mat4_t add(const mat4_t& a, const mat4_t& b)
{
    return mat4_add(a, b);
}

__vmath__ mat4_t sub(const mat4_t& a, const mat4_t& b)
{
    return mat4_sub(a, b);
}

__vmath__ mat4_t mul(const mat4_t& a, const mat4_t& b)
{
    return mat4_mul(a, b);
}

__vmath__ mat4_t mul(const mat4_t& m, float s)
{
    return mat4_mulf(m, s);
}

__vmath__ mat4_t mul(float s, const mat4_t& m)
{
    return mat4_mulf(m, s);
}

__vmath__ vec3_t mul(const mat4_t& m, const vec3_t& v)
{
    return mat4_mulv3(m, v);
}

__vmath__ vec4_t mul(const mat4_t& m, const vec4_t& v)
{
    return mat4_mulv4(m, v);
}

__vmath__ mat4_t inverse(const mat4_t& m)
{
    return mat4_inverse(m);
}

__vmath__ mat4_t transpose(const mat4_t& m)
{
    return mat4_transpose(m);
}

__vmath__ mat4_t ortho(float l, float r, float b, float t, float n, float f)
{
    return mat4_ortho(l, r, b, t, n, f);
}

__vmath__ mat4_t frustum(float l, float r, float b, float t, float n, float f)
{
    return mat4_frustum(l, r, b, t, n, f);
}

__vmath__ mat4_t perspective(float fov, float aspect, float znear, float zfar)
{
    return mat4_perspective(fov, aspect, znear, zfar);
}

__vmath__ mat4_t scale(float s)
{
    return mat4_scale1f(s);
}

__vmath__ mat4_t scale(float x, float y)
{
    return mat4_scale2f(x, y);
}

__vmath__ mat4_t scale(float x, float y, float z)
{
    return mat4_scale3f(x, y, z);
}

__vmath__ mat4_t scale(const vec2_t& v)
{
    return mat4_scalev2(v);
}

__vmath__ mat4_t scale(const vec3_t& v)
{
    return mat4_scalev3(v);
}

__vmath__ mat4_t rotate(const quat_t& q)
{
    return mat4_rotateq(q);
}

__vmath__ mat4_t rotate(const vec3_t& axis, float angle)
{
    return mat4_rotatev3(axis, angle);
}

__vmath__ mat4_t rotate(float x, float y, float z, float angle)
{
    return mat4_rotate3f(x, y, z, angle);
}

__vmath__ mat4_t translate(const vec2_t& v)
{
    return mat4_translatev2(v);
}

__vmath__ mat4_t translate(const vec3_t& v)
{
    return mat4_translatev3(v);
}

__vmath__ mat4_t translate(float x, float y)
{
    return mat4_translate2f(x, y);
}

__vmath__ mat4_t translate(float x, float y, float z)
{
    return mat4_translate3f(x, y, z);
}

/* END OF VMATH_BUILD_MAT4 */
#endif

/* END OF VMATH_FUNCTION_OVERLOADING */
#endif

/***********************************
 * @region: Operators overloading
 ***********************************/
#if defined(__cplusplus) && VMATH_OPERATOR_OVERLOADING != 0

/************************
 * Vector2D
 ************************/
#if VMATH_BUILD_VEC2
__vmath__ vec2_t operator-(const vec2_t& v)
{
    return vec2_neg(v);
}

__vmath__ vec2_t operator+(const vec2_t& a, const vec2_t& b)
{
    return vec2_add(a, b);
}

__vmath__ vec2_t operator+(const vec2_t& a, float b)
{
    return vec2_addf(a, b);
}

__vmath__ vec2_t operator+(float a, const vec2_t& b)
{
    return vec2_addf(b, a);
}

__vmath__ vec2_t operator-(const vec2_t& a, const vec2_t& b)
{
    return vec2_sub(a, b);
}

__vmath__ vec2_t operator-(const vec2_t& a, float b)
{
    return vec2_subf(a, b);
}

__vmath__ vec2_t operator-(float a, const vec2_t& b)
{
    return vec2_sub(vec2(a), b);
}

__vmath__ vec2_t operator*(const vec2_t& a, const vec2_t& b)
{
    return vec2_mul(a, b);
}

__vmath__ vec2_t operator*(const vec2_t& v, float s)
{
    return vec2_mulf(v, s);
}

__vmath__ vec2_t operator*(float s, const vec2_t& v)
{
    return vec2_mulf(v, s);
}

__vmath__ vec2_t operator/(const vec2_t& a, const vec2_t& b)
{
    return vec2_div(a, b);
}

__vmath__ vec2_t operator/(const vec2_t& v, float s)
{
    return vec2_divf(v, s);
}

__vmath__ vec2_t operator/(float a, const vec2_t& b)
{
    return vec2_div(vec2(a), b);
}

__vmath__ bool operator==(const vec2_t& a, const vec2_t& b)
{
    return vec2_equal(a, b);
}

__vmath__ bool operator!=(const vec2_t& a, const vec2_t& b)
{
    return !vec2_equal(a, b);
}

__vmath__ vec2_t operator+=(vec2_t& a, const vec2_t& b)
{
    return (a = a + b);
}

__vmath__ vec2_t operator+=(vec2_t& a, float b)
{
    return (a = a + b);
}

__vmath__ vec2_t operator-=(vec2_t& a, const vec2_t& b)
{
    return (a = a - b);
}

__vmath__ vec2_t operator-=(vec2_t& a, float b)
{
    return (a = a - b);
}

__vmath__ vec2_t operator*=(vec2_t& a, const vec2_t& b)
{
    return (a = a + b);
}

__vmath__ vec2_t operator*=(vec2_t& v, float s)
{
    return (v = v * s);
}

__vmath__ vec2_t operator/=(vec2_t& a, const vec2_t& b)
{
    return (a = a / b);
}

__vmath__ vec2_t operator/=(vec2_t& v, float s)
{
    return (v = v / s);
}

/* END OF VMATH_BUILD_MAT4 */
#endif

/************************
* Vector3D
************************/
#if VMATH_BUILD_VEC3

__vmath__ vec3_t operator-(const vec3_t& v)
{
    return vec3_neg(v);
}

__vmath__ vec3_t operator+(const vec3_t& a, const vec3_t& b)
{
    return vec3_add(a, b);
}

__vmath__ vec3_t operator+(const vec3_t& a, float b)
{
    return vec3_addf(a, b);
}

__vmath__ vec3_t operator+(float a, const vec3_t& b)
{
    return vec3_addf(b, a);
}

__vmath__ vec3_t operator-(const vec3_t& a, const vec3_t& b)
{
    return vec3_sub(a, b);
}

__vmath__ vec3_t operator-(const vec3_t& a, float b)
{
    return vec3_subf(a, b);
}

__vmath__ vec3_t operator-(float a, const vec3_t& b)
{
    return vec3_sub(vec3(a), b);
}

__vmath__ vec3_t operator*(const vec3_t& a, const vec3_t& b)
{
    return vec3_mul(a, b);
}

__vmath__ vec3_t operator*(const vec3_t& v, float s)
{
    return vec3_mulf(v, s);
}

__vmath__ vec3_t operator*(float s, const vec3_t& v)
{
    return vec3_mulf(v, s);
}

__vmath__ vec3_t operator/(const vec3_t& a, const vec3_t& b)
{
    return vec3_div(a, b);
}

__vmath__ vec3_t operator/(const vec3_t& v, float s)
{
    return vec3_divf(v, s);
}

__vmath__ vec3_t operator/(float a, const vec3_t& b)
{
    return vec3_div(vec3(a), b);
}

__vmath__ bool operator==(const vec3_t& a, const vec3_t& b)
{
    return vec3_equal(a, b);
}

__vmath__ bool operator!=(const vec3_t& a, const vec3_t& b)
{
    return !vec3_equal(a, b);
}

__vmath__ vec3_t operator+=(vec3_t& a, const vec3_t& b)
{
    return (a = a + b);
}

__vmath__ vec3_t operator+=(vec3_t& a, float b)
{
    return (a = a + b);
}

__vmath__ vec3_t operator-=(vec3_t& a, const vec3_t& b)
{
    return (a = a - b);
}

__vmath__ vec3_t operator-=(vec3_t& a, float b)
{
    return (a = a - b);
}

__vmath__ vec3_t operator*=(vec3_t& a, const vec3_t& b)
{
    return (a = a + b);
}

__vmath__ vec3_t operator*=(vec3_t& v, float s)
{
    return (v = v * s);
}

__vmath__ vec3_t operator/=(vec3_t& a, const vec3_t& b)
{
    return (a = a / b);
}

__vmath__ vec3_t operator/=(vec3_t& v, float s)
{
    return (v = v / s);
}    

/* END OF VMATH_BUILD_VEC4 */
#endif

/************************
* Vector4D
************************/    
#if VMATH_BUILD_VEC4
__vmath__ vec4_t operator-(const vec4_t& v)
{
    return vec4_neg(v);
}

__vmath__ vec4_t operator+(const vec4_t& a, const vec4_t& b)
{
    return vec4_add(a, b);
}

__vmath__ vec4_t operator+(const vec4_t& a, float b)
{
    return vec4_addf(a, b);
}

__vmath__ vec4_t operator+(float a, const vec4_t& b)
{
    return vec4_addf(b, a);
}

__vmath__ vec4_t operator-(const vec4_t& a, const vec4_t& b)
{
    return vec4_sub(a, b);
}

__vmath__ vec4_t operator-(const vec4_t& a, float b)
{
    return vec4_subf(a, b);
}

__vmath__ vec4_t operator-(float a, const vec4_t& b)
{
    return vec4_sub(vec4(a), b);
}

__vmath__ vec4_t operator*(const vec4_t& a, const vec4_t& b)
{
    return vec4_mul(a, b);
}

__vmath__ vec4_t operator*(const vec4_t& v, float s)
{
    return vec4_mulf(v, s);
}

__vmath__ vec4_t operator*(float s, const vec4_t& v)
{
    return vec4_mulf(v, s);
}

__vmath__ vec4_t operator/(const vec4_t& a, const vec4_t& b)
{
    return vec4_div(a, b);
}

__vmath__ vec4_t operator/(const vec4_t& v, float s)
{
    return vec4_divf(v, s);
}

__vmath__ vec4_t operator/(float a, const vec4_t& b)
{
    return vec4_div(vec4(a), b);
}

__vmath__ bool operator==(const vec4_t& a, const vec4_t& b)
{
    return vec4_equal(a, b);
}

__vmath__ bool operator!=(const vec4_t& a, const vec4_t& b)
{
    return !vec4_equal(a, b);
}

__vmath__ vec4_t operator+=(vec4_t& a, const vec4_t& b)
{
    return (a = a + b);
}

__vmath__ vec4_t operator+=(vec4_t& a, float b)
{
    return (a = a + b);
}

__vmath__ vec4_t operator-=(vec4_t& a, const vec4_t& b)
{
    return (a = a - b);
}

__vmath__ vec4_t operator-=(vec4_t& a, float b)
{
    return (a = a - b);
}

__vmath__ vec4_t operator*=(vec4_t& a, const vec4_t& b)
{
    return (a = a + b);
}

__vmath__ vec4_t operator*=(vec4_t& v, float s)
{
    return (v = v * s);
}

__vmath__ vec4_t operator/=(vec4_t& a, const vec4_t& b)
{
    return (a = a / b);
}

__vmath__ vec4_t operator/=(vec4_t& v, float s)
{
    return (v = v / s);
}    
/* END OF VMATH_BUILD_MAT4 */
#endif

/************************
* Quaternion
************************/
#if VMATH_BUILD_QUAT

__vmath__ quat_t operator-(const quat_t& q)
{
    return quat_neg(q);
}


__vmath__ quat_t operator~(const quat_t& q)
{
    return quat_inverse(q);
}


__vmath__ quat_t operator-(const quat_t& a, const quat_t& b)
{
    return quat_add(a, b);
}


__vmath__ quat_t operator+(const quat_t& a, const quat_t& b)
{
    return quat_sub(a, b);
}


__vmath__ quat_t operator*(const quat_t& a, const quat_t& b)
{
    return quat_mul(a, b);
}


__vmath__ quat_t operator*(const quat_t& a, float b)
{
    return quat_mulf(a, b);
}     


__vmath__ quat_t operator*(float b, const quat_t& a)
{
    return quat_mulf(a, b);
}


__vmath__ quat_t operator/(const quat_t& a, const float b)
{
    return quat_divf(a, b);
}


__vmath__ bool operator==(const quat_t& a, const quat_t& b)
{
    return quat_equal(a, b);
}


__vmath__ bool operator!=(const quat_t& a, const quat_t& b)
{
    return !quat_equal(a, b);
}


__vmath__ quat_t& operator+=(quat_t& a, const quat_t& b)
{
    return (a = a + b);
}


__vmath__ quat_t& operator-=(quat_t& a, const quat_t& b)
{
    return (a = a - b);
}


__vmath__ quat_t& operator*=(quat_t& a, const quat_t& b)
{
    return (a = a * b);
}


__vmath__ quat_t& operator*=(quat_t& a, float b)
{
    return (a = a * b);
}      


__vmath__ quat_t& operator/=(quat_t& a, float b)
{
    return (a = a * b);
}

/* END OF VMATH_BUILD_QUAT */
#endif                 

/************************
* Matrix2x2
************************/
#if VMATH_BUILD_MAT2    

__vmath__ mat2_t operator-(const mat2_t& m)
{
    return mat2_neg(m);
}      

__vmath__ mat2_t operator~(const mat2_t& m)
{
    return mat2_inverse(m);
}


__vmath__ mat2_t operator-(const mat2_t& a, const mat2_t& b)
{
    return mat2_add(a, b);
}


__vmath__ mat2_t operator+(const mat2_t& a, const mat2_t& b)
{
    return mat2_sub(a, b);
}


__vmath__ mat2_t operator*(const mat2_t& a, const mat2_t& b)
{
    return mat2_mul(a, b);
}


__vmath__ mat2_t operator*(const mat2_t& m, float s)
{
    return mat2_mulf(m, s);
}                 


__vmath__ mat2_t operator*(float s, const mat2_t& m)
{
    return mat2_mulf(m, s);
}


__vmath__ mat2_t operator/(const mat2_t& m, float s)
{
    return mat2_divf(m, s);
}                 


__vmath__ mat2_t operator/(float s, const mat2_t& m)
{
    return mat2_divf(m, s);
}


__vmath__ bool operator==(const mat2_t& a, const mat2_t& b)
{
    return mat2_equal(a, b);
}


__vmath__ bool operator!=(const mat2_t& a, const mat2_t& b)
{
    return !mat2_equal(a, b);
}


__vmath__ mat2_t& operator+=(mat2_t& a, const mat2_t& b)
{
    return (a = a + b);
}


__vmath__ mat2_t& operator-=(mat2_t& a, const mat2_t& b)
{
    return (a = a - b);
}


__vmath__ mat2_t& operator*=(mat2_t& a, const mat2_t& b)
{
    return (a = a * b);
}


__vmath__ mat2_t& operator*=(mat2_t& a, float b)
{
    return (a = a * b);
}               


__vmath__ mat2_t& operator/=(mat2_t& a, float b)
{
    return (a = a / b);
}


__vmath__ vec2_t operator*(const mat2_t& a, const vec2_t& b)
{
    return mat2_mulv2(a, b);
}

/* END OF VMATH_BUILD_MAT3 */
#endif


/************************
* Matrix3x3
************************/
#if VMATH_BUILD_MAT3

__vmath__ mat3_t operator-(const mat3_t& m)
{
    return mat3_neg(m);
}  


__vmath__ mat3_t operator~(const mat3_t& m)
{
    return mat3_inverse(m);
}


__vmath__ mat3_t operator-(const mat3_t& a, const mat3_t& b)
{
    return mat3_add(a, b);
}


__vmath__ mat3_t operator+(const mat3_t& a, const mat3_t& b)
{
    return mat3_sub(a, b);
}


__vmath__ mat3_t operator*(const mat3_t& a, const mat3_t& b)
{
    return mat3_mul(a, b);
}                        


__vmath__ mat3_t operator*(const mat3_t& m, float s)
{
    return mat3_mulf(m, s);
}                 


__vmath__ mat3_t operator*(float s, const mat3_t& m)
{
    return mat3_mulf(m, s);
}


__vmath__ mat3_t operator/(const mat3_t& m, float s)
{
    return mat3_divf(m, s);
}                 


__vmath__ bool operator==(const mat3_t& a, const mat3_t& b)
{
    return mat3_equal(a, b);
}


__vmath__ bool operator!=(const mat3_t& a, const mat3_t& b)
{
    return !mat3_equal(a, b);
}


__vmath__ mat3_t& operator+=(mat3_t& a, const mat3_t& b)
{
    return (a = a + b);
}


__vmath__ mat3_t& operator-=(mat3_t& a, const mat3_t& b)
{
    return (a = a - b);
}


__vmath__ mat3_t& operator*=(mat3_t& a, const mat3_t& b)
{
    return (a = a * b);
}


__vmath__ mat3_t& operator*=(mat3_t& a, float b)
{
    return (a = a * b);
}           


__vmath__ mat3_t& operator/=(mat3_t& a, float b)
{
    return (a = a / b);
}


__vmath__ vec3_t operator*(const mat3_t& a, const vec3_t& b)
{
    return mat3_mulv3(a, b);
}

/* END OF VMATH_BUILD_MAT3 */
#endif

/************************
 * Matrix4x4
 ************************/
#if VMATH_BUILD_MAT4

__vmath__ mat4_t operator-(const mat4_t& m)
{
    return mat4_neg(m);
}  

__vmath__ mat4_t operator~(const mat4_t& m)
{
    return mat4_inverse(m);
}

__vmath__ mat4_t operator-(const mat4_t& a, const mat4_t& b)
{
    return mat4_add(a, b);
}

__vmath__ mat4_t operator+(const mat4_t& a, const mat4_t& b)
{
    return mat4_sub(a, b);
}

__vmath__ mat4_t operator*(const mat4_t& a, const mat4_t& b)
{
    return mat4_mul(a, b);
}

__vmath__ mat4_t operator*(const mat4_t& a, float b)
{
    return mat4_mulf(a, b);
}                

__vmath__ mat4_t operator*(float a, const mat4_t& b)
{
    return mat4_mulf(b, a);
}                      

__vmath__ mat4_t operator/(const mat4_t& a, float b)
{
    return mat4_divf(a, b);
}                

__vmath__ bool operator==(const mat4_t& a, const mat4_t& b)
{
    return mat4_equal(a, b);
}

__vmath__ bool operator!=(const mat4_t& a, const mat4_t& b)
{
    return !mat4_equal(a, b);
}

__vmath__ mat4_t& operator+=(mat4_t& a, const mat4_t& b)
{
    return (a = a + b);
}

__vmath__ mat4_t& operator-=(mat4_t& a, const mat4_t& b)
{
    return (a = a - b);
}

__vmath__ mat4_t& operator*=(mat4_t& a, const mat4_t& b)
{
    return (a = a * b);
}

__vmath__ mat4_t operator*=(mat4_t& a, float b)
{
    return (a = a * b);
}                                 

__vmath__ mat4_t operator/=(mat4_t& a, float b)
{
    return (a = a / b);
}

__vmath__ vec3_t operator*(const mat4_t& a, const vec3_t& b)
{
    return mat4_mulv3(a, b);
}

__vmath__ vec4_t operator*(const mat4_t& a, const vec4_t& b)
{
    return mat4_mulv4(a, b);
}

/* END OF VMATH_BUILD_MAT4 */
#endif

/* END OF VMATH_OPERATOR_OVERLOADING */
#endif

/**
 * Turn on annoy warning
 */
#if __GNUC__
#  pragma GCC   diagnostic warning "-Wmissing-braces"
#elif __clang__
#  pragma clang diagnostic warning "-Wmissing-braces"
#elif defined(_MSC_VER)
#  pragma warning(default : 4141) /* Shutup announce missing braces warning */
#  pragma warning(default : 4201) /* Shutup announce anonymous union warning */
#endif

#endif /* __VMATH_H__ */

