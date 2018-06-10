#include <stdio.h>
#include <assert.h>

#define VMATH_GLSL_LIKE  1
#define VMATH_SSE_ENABLE 0 
#include "../vmath.h"

void vec2_test(void);
void vec3_test(void);
void vec4_test(void);
void mat2_test(void);
void mat3_test(void);
void mat4_test(void);
void quat_test(void);

void print_vec2(vec2_t v);
void print_vec3(vec2_t v);
void print_vec4(vec2_t v);
void print_mat2(vec2_t v);
void print_mat3(vec2_t v);
void print_mat4(vec2_t v);

int main(int argc, char* argv[])
{
    vec2_test();              
    vec3_test();
    vec4_test();
    mat2_test();
    mat3_test();
    mat4_test();
    quat_test();    
    
#if defined(_MSC_VER)
    fgetc(stdin);
#endif

    return 0;
}

void vec2_test(void)
{
    vec2 a = vec2(1, 2);
    vec2 b = vec2(3, 4);
    vec2 c = add(a, b);
    vec2 d = vec2(4, 6);

    printf("vec2(%lf, %lf)\n", c.x, c.y);
    printf("vec2(%lf, %lf)\n", d.x, d.y);

    assert(c == d);
}

void vec3_test(void)
{
    vec3 a = vec3(1, 2, 3);
    vec3 b = vec3(4, 5, 6);
    vec3 c = add(a, b);
    
    assert(c == vec3(5, 7, 9));
    assert(lengthsquared(c) == 5 * 5 + 7 * 7 + 9 * 9);
    assert(length(c) == vmath_fsqrt(5 * 5 + 7 * 7 + 9 * 9));

    printf("vec3(%f, %f, %f)\n", c.x, c.y, c.z);
}

void vec4_test(void)
{
}

void mat2_test(void)
{
}

void mat3_test(void)
{
}

void mat4_test(void)
{
}

void quat_test(void)
{
}

void print_vec2(vec2_t v)
{
}

void print_vec3(vec2_t v)
{
}

void print_vec4(vec2_t v)
{
}

void print_mat2(vec2_t v)
{
}

void print_mat3(vec2_t v)
{
}

void print_mat4(vec2_t v)
{
}
