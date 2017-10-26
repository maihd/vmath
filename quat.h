/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */

typedef vec4_t quat_t;

static const quat_t QUAT_IDENTITY = { 0, 0, 0, 1 }; 

/**
 * Create quaternion
 */
__vmath__ quat_t quat(float x, float y, float z, float w)
{
  return vec4(x, y, z, w);
}


/**
 * Create euler quaternion
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
 * Create euler quaternion
 */
__vmath__ quat_t eulerv3(vec3_t e)
{
  return euler(e.x, e.y, e.z);
}


/**
 * Convert to an axis-angle representation.
 */
__vmath__ vec4_t toaxis(quat_t quat)
{
  quat_t q = quat;
  if (fabsf(q.w) > 0) {
    q = normalize4(quat);
  }
  vec4_t r;
  r.angle = 2.0f * cosf(q.w);
  float den = sqrtf(1.0f - q.w * q.w);
  if (den > 0.0001f) {
    r.axis = div3(r.axis, den);
  } else {
    r.axis = vec3(1, 0, 0);
  }
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
  quat_t q;
  q.xyz = mul3(normalize3(axis), sinf(angle * 0.5f));
  q._w_ = cosf(angle * 0.5f);
  return q;
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
  quat_t q;
  q.xyz = add3(add3(mul3(a.xyz, b.w), mul3(b.xyz, a.w)),
               cross3(a.xyz, b.xyz));
  q._w_ = a.w * b.w - dot3(a.xyz, b.xyz);
  return q;
}
