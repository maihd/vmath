# vmath - C/C++ vector math libary

## Features
1. Vectors (2, 3, 4), Matrices (2, 3, 4), Quaternion
2. One single header file library
3. C/C++ inline pure functions
4. Plain-old-data types, code and data are separated.
5. SIMD support: SSE , NEON
6. Multi-platforms: Intel, ARM
7. C++ operators/functions overloading
8. GLSL-like API design (C++ only)
9. With some other languages implement (experimental): C#, F#

## Compatibility: platforms and compilers
1. GCC and clang: MacOS tested
2. Cygwin: Windows 7, 10 Desktop testing
3. NDK: Android tested
4. MSVisualC++: 2017 Community - Windows 7, 10 Desktop C/C++ tested

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
vec3_t position  = vec3(100.0f, 200.0f, 10.0f);
quat_t rotation  = quat_euler(0.0f, 0.0f, 0.0f);
vec3_t scalation = VEC3_ONE;
mat4_t model     = mat4_translatev3(position)
                 * mat4_rotateq(rotation)
                 * mat4_scalev3(scalation);
/* OR
mat4_t model    = mul(mul(mat4_translatev3(position), 
                          mat4_rotateq(rotation)), 
                      mat4_scalev3(scale));
 */

/* Perspective matrix with 45 degree fov */
mat4_t proj = mat4_perspective(M_PI * 0.25f, WIDTH / HEIGHT, 0.0f, 100.0f);

/** GLSL-like types version */

vec3 position  = vec3(100.0f, 200.0f, 10.0f);
quat rotation  = quat(0.0f, 0.0f, 0.0f); /* create quat with roll-pitch-yaw */
vec3 scalation = vec3(1.0f);
mat4 model     = translate(position)
               * rotate(rotation)
               * scale(scalation);

/* Perspective matrix with 45 degree fov */
mat4 proj = perspective(M_PI * 0.25f, WIDTH / HEIGHT, 0.0f, 100.0f);

... apply matrix to render ...
```

## Project use vmath
1. MaiHD's OpenGL examples, (https://github.com/maihd/opengl.git)

## Metadata
1. License: NULL
2. Copyright: MaiHD @ ${HOME}, 2017 - 2018
3. Editor: Emacs (used) + VSCode + Visual Studio Community

## FAQ
Q. Why plain-old data?<br/>
A. First, C and C++ are both supported. Second, Data-oriented design. Lastly, design based on GLSL.<br/>
<br/>  
Q. Are GLSL-like types (name without _t postfix), C++ object-oriented type?<br/>
A. Shortly, yes. Long answer, we cannot naming functions with data types' name. The types, are defined separate from default types (name with _t postfix), and has implicit conversion.<br/>