/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */

 #pragma once

/**
 * Rectangle data structure
 */
typedef struct
{
  vec2_t min;
  vec2_t max;
} rect_t;


/**
 * Create rectangle
 */
__vmath__ rect_t rect(vec2_t min, vec2_t max)
{
  rect_t r = { min, max };
  return r;
}


/**
 * Get rectangle's size
 */
__vmath__ vec2_t rectsize(rect_t r)
{
  return sub2(r.max, r.min);
}


/**
 * Is rectangle contains the given point
 * @return 1 if contains, 0 otherwise
 */
__vmath__ bool   rectctn(rect_t r, vec2_t p)
{
  return !(p.x < r.min.x || p.y < r.min.y || p.x > r.max.x || p.y > r.max.y);
}

