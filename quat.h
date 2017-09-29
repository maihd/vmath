/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */

typedef vec4_t quat_t;
#define quat(x, y, z, w) vec4(x, y, z, w)
#define QUAT_IDENTITY    quat(0, 0, 0, 1) 

/**
 * Convert to an axis-angle representation.
 */
static inline vec4_t toaxis(quat_t quat)
{
  quat_t q = quat;
  if (fabsf(q.w) > 0) {
    q = normalize4(quat);
  }
  vec4_t r;
  r.angle = 2.0f * cos(q.w);
  float den = sqrt(1.0 - q.w * q.w);
  if (den > 0.0001f) {
    r.axis = div3(r.axis, den);
  } else {
    r.axis = vec3(1, 0, 0);
  }
  return r;
}
