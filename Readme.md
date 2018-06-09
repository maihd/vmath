# vmath - C/C++ vector math libary

## Features
1. Vectors, matrices, quaternion calculations
2. One single header file library
3. C/C++ inline pure functions
4. Plain-old-data types, code and data are separated.
5. SIMD support: SSE , NEON
6. Multi-platforms: Intel, ARM
7. C++ operators/functions overloading
8. GLSL-like API design (C++ only, type name without _t only Visual C++)
9. With some other languages implement (experimental): C#, F#

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
/* OR
mat4_t model    = mul(mul(mat4_translate(position), 
                          mat4_rotate(rotation)), 
                      mat4_scale(scale));
 */

/* Perspective matrix with 45 degree fov */
mat4_t proj = mat4_perspective(M_PI * 0.25f, WIDTH / HEIGHT, 0.0f, 100.0f);

/** GLSL-like types version */

vec3 position = vec3(100.0f, 200.0f, 10.0f);
quat rotation = quat_euler(0.0f, 0.0f, 0.0f);
vec3 scale    = VEC3_ONE;
mat4 model    = mat4_translate(position)
              * mat4_rotate(rotation)
	      * mat4_scale(scale);

/* Perspective matrix with 45 degree fov */
mat4 proj = mat4_perspective(M_PI * 0.25f, WIDTH / HEIGHT, 0.0f, 100.0f);

... apply matrix to render ...
```

## Compatibility: platforms and compilers
1. GCC and clang: MacOS tested
2. Cygwin: Windows 7, 10 Desktop testing
3. NDK: Android tested
4. MSVisualC++: 2017 Community - Windows 7, 10 Desktop C/C++ tested

## Metadata
1. License: NULL
2. Copyright: MaiHD @ ${HOME}, 2017 - 2018
3. Editor: Emacs (used) + VSCode + Visual Studio Community

## FAQ
1. Why plain-old data?
A. First, C and C++ are both supported. Second, Data-oriented design. Lastly, more like GLSL.

2. Are GLSL-like types (name without _t postfix), C++ object-oriented type?
A. Shortly, yes. Long answer, we cannot naming functions with data types' name. The types, are defined separate from default types (name with _t postfix), and has auto conversion. Unfornately, the implement has its own limits.

3. Why GLSL-like types (name without _t postfix) only work with Visual C++?
A. Because the vtable of object, the GLSL-like types (name without _t postfix) do not have the same memory layout with default types (name with _t postfix). Fortunately, Visual C++ has an attribute tell the compiler do not include the vtable (__declspec(novtable)). Unfortunately, other compilers do not have this feature.