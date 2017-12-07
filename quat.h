/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */


#pragma once


typedef vec4_t quat_t;
static const quat_t QUAT_IDENTITY = { 0, 0, 0, 1 }; 

/**
 * Create quaternion
 * @return: Created quaternion
 */
__vmath__ quat_t quat(float x, float y, float z, float w)
{
    return vec4(x, y, z, w);
}


/**
 * Create a quaternion with euler coordinate
 * @return: result quaternion
 */
__vmath__ quat_t euler(float y, float p, float r)
{
    y *= 0.5f;
    p *= 0.5f;
    r *= 0.5f;

    float c1 = cosf(y);
    float c2 = cosf(p);
    float c3 = cosf(r);
    float s1 = sinf(y);
    float s2 = sinf(p);
    float s3 = sinf(r);
    return quat(s1 * s2 * c3 + c1 * c2 * s3,
		s1 * c2 * c3 + c1 * s2 * s3,
		c1 * s2 * c3 - s1 * c2 * s3,
		c1 * c2 * c3 - s1 * s2 * s3);
}


/**
 * Create a quaternion with euler coordinate
 * @return: result quaternion
 */
__vmath__ quat_t eulerv3(vec3_t e)
{
    return euler(e.x, e.y, e.z);
}


/**
 * Convert to an axis-angle representation.
 * @return: a axis-angle representation store in vec4_t union
 */
__vmath__ vec4_t toaxis(quat_t quat)
{
    quat_t q = quat;
    if (fabsf(q.w) > 0) {
	q = normalize4(quat);
    }
    vec4_t r;
    float den = sqrtf(1.0f - q.w * q.w);
    if (den > 0.0001f) {
	r.xyz = div3(r.xyz, den);
    } else {
	r.xyz = vec3(1, 0, 0);
    }
    r.w = 2.0f * cosf(q.w);
    return r;
}


/**
 * Convert axis-angle representation to quaternion 
 */
__vmath__ quat_t toquat(vec3_t axis, float angle)
{
    if (lensqr3(axis) == 0.0f) {
	return QUAT_IDENTITY;
    }

    quat_t r;
    r.w   = cosf(angle * 0.5f);
    r.xyz = mul3(normalize3(axis), sinf(angle * 0.5f));
    return r;
}


/**
 * Get invert quaternion
 */
__vmath__ quat_t inverseq(quat_t q)
{
    return quat(q.x, q.y, q.z, -q.w);
}


/**
 * Get conjugate quaternion
 */
__vmath__ quat_t conjq(quat_t q)
{
    return quat(-q.x, -q.y, -q.z, q.w);
}


/**
 * Multiplication of two quaternions 
 */
__vmath__ quat_t mulq(quat_t a, quat_t b)
{
    quat_t r;
    r.w   = a.w * b.w - dot3(a.xyz, b.xyz);
    r.xyz = add3(add3(mul3(a.xyz, b.w), mul3(b.xyz, a.w)),
		 cross3(a.xyz, b.xyz));
    return r;
}
