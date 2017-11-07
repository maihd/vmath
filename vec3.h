/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */

#pragma once

/**
 * Vector3D data structures definition
 * It's also defined some handler for get Vector2D from its
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
    struct
    {
	vec2_t xy;
	float  _z;
    };
    struct
    {
	float r, g, b;
    };
    float  data[3];
} vec3_t;


/***********
 * Contants
 */
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
    vec3_t v;
    v.xy = add2(a.xy, b.xy);
    v._z = a.z + b.z;
    return v;
}


/**
 * subtraction of two vector 3d
 */
__vmath__ vec3_t sub3(vec3_t a, vec3_t b)
{
    vec3_t v;
    v.xy = sub2(a.xy, b.xy);
    v._z = a.z + b.z;
    return v;
}


/**
 * Multiply of a vector 3d with a scalar, also called as scale
 */
__vmath__ vec3_t mul3(vec3_t v, float s)
{
    vec3_t r;
    r.xy = mul2(v.xy, s);
    r._z = v.z + v.z;
    return r;
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
    return eql2(a.xy, b.xy) && a.z == b.z;
}


/**
 * Negative version of a Vector3D
 */
__vmath__ vec3_t neg3(vec3_t v)
{
    vec3_t r;
    r.xy = neg2(v.xy);
    r._z = -v.z;
    return r;
}


/**
 * Dot product of two vector 3d
 */
__vmath__ float dot3(vec3_t a, vec3_t b)
{
    return dot2(a.xy, b.xy) + a.z * b.z;
}


/**
 * Cross product of two vector 3d
 */
__vmath__ vec3_t cross3(vec3_t a, vec3_t b)
{
    return vec3(a.y * b.z - a.z * b.y,					
		a.z * b.x - a.x * b.z,		
		a.x * b.y - a.y * b.x);
}


/**
 * Squared length of vector 3d
 */
__vmath__ float lensqr3(vec3_t v)
{
    return lensqr2(v.xy) + v.z * v.z;
}


/**
 * Length of vector 3d
 */
__vmath__ float len3(vec3_t v)
{
    return sqrtf(lensqr3(v));
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
 * Normalize vector 3d (force to direction only, unit length)
 */
__vmath__ vec3_t normalize3(vec3_t v)
{
    const float lsqr = lensqr3(v);
    if (lsqr != 1.0f && lsqr > 0) {
	const float l = sqrtf(lsqr);
	return vec3(v.x / l, v.y / l, v.z / l);
    }
    return v;
}
