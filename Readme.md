# vmath - C/C++ vector math libary

## Features
1. Vectors, matrices, quaternion calculations
2. One single header file library
3. C/C++ inline pure functions
4. SIMD support: SSE, NEON
5. Multi-platforms: Intel, ARM
6. C++ operators overloading

## Examples
C language example:
```C
vec3_t position = vec3(100.0f, 200.0f, 10.0f);
quat_t rotation = quat_euler(0.0f, 0.0f, 0.0f);
vec3_t scale    = VEC3_ONE;
mat4_t model    = mat4_mul(mat4_mul(mat4_translatev3(position),
				    mat4_rotateq(rotation)),
                           mat4_scalev3(scale));

/* Perspective matrix with 45 degree fov */
mat4_t proj = mat4_perspective(M_PI * 0.25f, WIDTH / HEIGHT, 0.0f, 100.0f);

... apply matrix to render ...
```

C++ language example:
```C++
vec3_t position = vec3(100.0f, 200.0f, 10.0f);
quat_t rotation = quat_euler(0.0f, 0.0f, 0.0f);
vec3_t scale    = VEC3_ONE;
mat4_t model    = mat4_translate(position)
                * mat4_rotate(rotation)
		* mat4_scale(scale);

/* Perspective matrix with 45 degree fov */
mat4_t proj = mat4_perspective(M_PI * 0.25f, WIDTH / HEIGHT, 0.0f, 100.0f);

... apply matrix to render ...
```

## Compatibility: platforms and compilers
1. GCC and clang: MacOS tested
2. Cygwin: Windows 7, 10 Desktop testing
3. NDK: Android tested
4. MSVisualC++: Windows 7, 10 Desktop C++ tested

## Metadata
1. License: NULL
2. Copyright: MaiHD @ ${HOME}, 2017
3. Editor: Emacs + Visual Studio Community