#include <stdio.h>
#include <assert.h>

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
    
    return 0;
}

void vec2_test(void)
{
    vec2_t a = vec2(1, 2);
    vec2_t b = vec2(3, 4);
    vec2_t c = add(a, b);
    assert(c == vec2(4, 6));

    printf("vec2(%f, %f)\n", c.x, c.y);
}

void vec3_test(void)
{
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
