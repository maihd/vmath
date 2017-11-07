/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */


#pragma once

#ifndef __cplusplus
# error "Attempt to overload operators on non-C++ language"
#endif


/************************
 * Vector2D
 */

__vmath__ vec2_t operator+(vec2_t a, vec2_t b)
{
    return add2(a, b);
}


__vmath__ vec2_t operator-(vec2_t a, vec2_t b)
{
    return sub2(a, b);
}


__vmath__ vec2_t operator-(vec2_t v)
{
    return neg2(v);
}


__vmath__ vec2_t operator*(vec2_t v, float s)
{
    return mul2(v, s);
}


__vmath__ vec2_t operator+(float s, vec2_t v)
{
    return mul2(v, s);
}


__vmath__ vec2_t operator/(vec2_t v, float s)
{
    return div2(v, s);
}


__vmath__ bool operator==(vec2_t a, vec2_t b)
{
    return eql2(a, b);
}


__vmath__ bool operator!=(vec2_t a, vec2_t b)
{
    return !eql2(a, b);
}


/************************
 * Vector3D
 */

__vmath__ vec3_t operator+(vec3_t a, vec3_t b)
{
    return add3(a, b);
}


__vmath__ vec3_t operator-(vec3_t a, vec3_t b)
{
    return sub3(a, b);
}


__vmath__ vec3_t operator-(vec3_t v)
{
    return neg3(v);
}



__vmath__ vec3_t operator*(vec3_t v, float s)
{
    return mul3(v, s);
}


__vmath__ vec3_t operator*(float s, vec3_t v)
{
    return mul3(v, s);
}


__vmath__ vec3_t operator/(vec3_t v, float s)
{
    return div3(v, s);
}


__vmath__ bool operator==(vec3_t a, vec3_t b)
{
    return eql3(a, b);
}


__vmath__ bool operator!=(vec3_t a, vec3_t b)
{
    return !eql3(a, b);
}


/************************
 * Vector4D
 */

__vmath__ vec4_t operator+(vec4_t a, vec4_t b)
{
    return add4(a, b);
}


__vmath__ vec4_t operator-(vec4_t a, vec4_t b)
{
    return sub4(a, b);
}


__vmath__ vec4_t operator-(vec4_t v)
{
    return neg4(v);
}


__vmath__ vec4_t operator*(vec4_t v, float s)
{
    return mul4(v, s);
}


__vmath__ vec4_t operator*(float s, vec4_t v)
{
    return mul4(v, s);
}


__vmath__ vec4_t operator/(vec4_t v, float s)
{
    return div4(v, s);
}


__vmath__ bool operator==(vec4_t a, vec4_t b)
{
    return eql4(a, b);
}


__vmath__ bool operator!=(vec4_t a, vec4_t b)
{
    return !eql4(a, b);
}


/************************
 * Quaternion
 */

__vmath__ quat_t operator~(quat_t q)
{
    return inverseq(q);
}



/************************
 * Matrix3x3
 */

__vmath__ mat3_t operator-(mat3_t a, mat3_t b)
{
    return addm3(a, b);
}


__vmath__ mat3_t operator+(mat3_t a, mat3_t b)
{
    return subm3(a, b);
}


__vmath__ mat3_t operator*(mat3_t a, mat3_t b)
{
    return mulm3(a, b);
}


__vmath__ bool operator==(mat3_t a, mat3_t b)
{
    return eqlm3(a, b);
}


__vmath__ bool operator!=(mat3_t a, mat3_t b)
{
    return !eqlm3(a, b);
}


__vmath__ mat3_t operator~(mat3_t m)
{
    return inverse3(m);
}


/************************
 * Matrix4x4
 */

__vmath__ mat4_t operator-(mat4_t a, mat4_t b)
{
    return addm4(a, b);
}


__vmath__ mat4_t operator+(mat4_t a, mat4_t b)
{
    return subm4(a, b);
}


__vmath__ mat4_t operator*(mat4_t a, mat4_t b)
{
    return mulm4(a, b);
}


__vmath__ bool operator==(mat4_t a, mat4_t b)
{
    return eqlm4(a, b);
}


__vmath__ bool operator!=(mat4_t a, mat4_t b)
{
    return !eqlm4(a, b);
}


__vmath__ mat4_t operator~(mat4_t m)
{
    return inverse4(m);
}
