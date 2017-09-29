/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */

/**
 * Rectangle data structure
 */
typedef vec4_t rect_t;

#define rect(x, y, w, h) vec4(x, y, w, h)

/**
 * Get min position of rectangle
 */
static inline vec2_t rectmin(rect_t rect)
{
  return rect.pos;
}


/**
 * Get max position of rectangle
 */
static inline vec2_t rectmax(rect_t rect)
{
  return add2(rect.pos, rect.zw);
}
