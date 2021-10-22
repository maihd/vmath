#pragma once

#include <math.h>
#include <float.h>
#include <stdbool.h>

// Remove stupid stuffs
#undef min      // When Windows.h was included, `min` is an macro
#undef max      // When Windows.h was included, `max` is an macro
#undef far      // When Windows.h was included, `far` is an macro
#undef near     // When Windows.h was included, `near` is an macro

// -------------------------------------------------------------
// Compiler settings
// -------------------------------------------------------------

#if defined(__GNUC__)
#   define __vectorcall  /* NO VECTORCALL SUPPORTED */
#   define __forceinline static __attribute__((always_inline))
#endif

// constexpr is helpful
#if !defined(__cplusplus) && !defined(constexpr)
#   define constexpr static const
#endif

// -------------------------------------------------------------
// Constants
// -------------------------------------------------------------

constexpr float PI                   = 3.141592653589f;
constexpr float TWO_PI               = 3.141592653589f * 2.0f;
constexpr float HALF_PI              = 3.141592653589f * 0.5f;
constexpr float THREE_HALF_PI        = 3.141592653589f * 1.5f;

constexpr float INV_PI               = 1.0f / (3.141592653589f * 1.0f);
constexpr float INV_TWO_PI           = 1.0f / (3.141592653589f * 2.0f);
constexpr float INV_HALF_PI          = 1.0f / (3.141592653589f * 0.5f);
constexpr float INV_THREE_HALF_PI    = 1.0f / (3.141592653589f * 1.5f);

// -------------------------------------------------------------
// Functions
// -------------------------------------------------------------

/// Convert degrees to radians
__forceinline float radians(float degrees)
{
    return degrees * PI / 180.0f;
}

/// Convert radians to degrees
__forceinline float degrees(float radians)
{
    return radians * 180.0f / PI;
}

/// Compute the sign of 'x'
__forceinline int sign(int x)
{
    return x >> 31;
}

/// Get the smaller value
__forceinline int min(int x, int y)
{
    return x < y ? x : y;
}

/// Get the larger value
__forceinline int max(int x, int y)
{
    return x > y ? x : y;
}

/// Clamps the 'x' to the [min, max]
__forceinline int clamp(int x, int min, int max)
{
    return x < min ? min : (x > max ? max : x);
}

/// Computes sign of 'x'
__forceinline int signf(float x)
{
    union
    {
        float f;
        int   i;
    } cvt;
    cvt.f = x;
    return sign(cvt.i);
}

/// Get the fractal part of floating point
__forceinline float fracf(float x)
{
    float y;
    return modff(x, &y);
}

// Android polyfill for log2 and log2f
#if defined(__ANDROID__)
__forceinline float log2f(float x)
{
    return (logf(x) / 0.693147180559945f);
}

__forceinline double log2(double x)
{
    return (log(x) / 0.693147180559945);
}
#endif

/// Get the smaller value
__forceinline float minf(float x, float y)
{
    return x < y ? x : y;
}

/// Get the larger value
__forceinline float maxf(float x, float y)
{
    return x > y ? x : y;
}

/// Clamps the 'x' value to the [min, max].
__forceinline float clampf(float x, float min, float max)
{
    return x < min ? min : (x > max ? max : x);
}

/// Clamps the specified value within the range of 0 to 1
__forceinline float saturatef(float x)
{
    return clampf(x, 0.0f, 1.0f);
}

/// Compares two values, returning 0 or 1 based on which value is greater.
__forceinline float stepf(float y, float x)
{
    return (float)(x >= y);
}

/// Performs a linear interpolation.
__forceinline float lerpf(float x, float y, float s)
{
    return x + (y - x) * s;
}

/// Computes inverse square root of 'x'.
__forceinline float rsqrtf(float x)
{
    return 1.0f / sqrtf(x);
}

/// Compute a smooth Hermite interpolation
/// @return: 0 if x <= min
///          1 if x >= max
///          (0, 1) otherwise
__forceinline float smoothstepf(float min, float max, float x)
{
    return (clampf(x, min, max) - min) / (max - min);
}

/// Test is two values are closely equal
__forceinline bool isclosef(float a, float b)
{
    return fabsf(a - b) <= FLT_EPSILON;
}
