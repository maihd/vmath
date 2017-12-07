# vmath - C/C++ vector math libary

## Features
1. Vectors, matrices, quaternion calculations
2. One single header file library, from vmath.h >= v1.0.4
3. C/C++ inline pure functions
4. SIMD support: SSE, NEON
5. Multi-platforms: Intel, ARM
6. C++ operators overloading, in vmath-operators.h
7. Type generic functions C11, in tgvmath.h

## Examples
```C
vec3_t position = vec3(100.0f, 200.0f, 10.0f);
vec4_t eulerRot = euler(0.0f, 0.0f, 0.0f);
vec3_t scale = VEC3_UNIT;
mat4_t model = mulm4(mulm4(translatev3(position), rotatev3(eulerRot.xyz, eulerRot.w)),
                     scalev3(scale));

mat4_t proj = perspective(M_PI * 0.25f, WIDTH / HEIGHT, 0.0f, 100.0f); /* 45 degree fov */

... apply matrix to render ...
```

## Compatibility: platforms and compilers
1. GCC and CLang: MacOS tested
2. Cygwin: Windows 7 Desktop testing
3. NDK: Android tested
4. MSVisualC++: Windows 7 Desktop C++ tested

## Metadata
1. License: NULL
2. Copyright: MaiHD @ ${HOME}, 2017