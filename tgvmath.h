/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */


/********
 * Type generic version of vmath functions
 */


#define add(a, b)				\
  _Generic((a, b),				\
	   vec2_t: add2,			\
	   vec3_t: add3,			\
	   vec4_t: add4,			\
	   mat3_t: addm3,			\
	   mat4_t: addm4			\
	   )(a, b)


#define sub(a, b)				\
  _Generic((a, b),				\
	   vec2_t: sub2,			\
	   vec3_t: sub3,			\
	   vec4_t: sub4,			\
	   mat3_t: subm3,			\
	   mat4_t: subm4			\
	   )(a, b)


#define mul(a, b)				\
  _Generic((a),					\
	   vec2_t: mul2,			\
	   vec3_t: mul3,			\
	   vec4_t: mul4,			\
	   mat3_t: mulm3,			\
	   mat4_t: mulm4			\
	   )(a, b)
    /*
      default:					\
      _Generic((b),				\
	       vec2_t: mul2,			\
	       vec3_t: mul3,			\
	       vec4_t: mul4,			\
	       )(b, a)				\
    */


/*#define div(a, b)				\
  _Generic((a, b),				\
	   vec2_t: div2,			\
	   vec3_t: div3,			\
	   vec4_t: div4,			\
	   default: div				\
	   )(a, b)*/


#define dot(a, b)				\
  _Generic((a, b),				\
	   vec2_t: dot2,			\
	   vec3_t: dot3,			\
	   vec4_t: dot4				\
	   )(a, b)


#define cross(a, b)				\
  _Generic((a, b),				\
	   vec3_t: cross3			\
	   )(a, b)


#define len(v)					\
  _Generic((v),					\
	   vec2_t: len2,			\
	   vec3_t: len3,			\
	   vec4_t: len4			\
	   )(v)


#define lensqr(v)					\
  _Generic((v),						\
	   vec2_t: lensqr2,				\
	   vec3_t: lensqr3,				\
	   vec4_t: lensqr4				\
	   )(v)


#define normalize(v)					\
  _Generic((v),						\
	   vec2_t: normalize2,				\
	   vec3_t: normalize3,				\
	   vec4_t: normalize4				\
	   )(v)


#define transpose(m)				\
  _Generic((m),					\
	   mat3_t: transpose3,			\
	   mat4_t: transpose4			\
	   )(m)


#define translate(...)				\
  _Generic((__VA_ARGS__),			\
	   vec2_t: translatev2,			\
	   vec3_t: translatev3,			\
	   default: translate3f			\
	   )(__VA_ARGS__)


#define scale(...)				\
  _Generic((__VA_ARGS__),			\
	   vec2_t: scalev2,			\
	   vec3_t: scalev3,			\
	   default: scale3f			\
	   )(__VA_ARGS__)


#define rotate(...)				\
  _Generic((__VA_ARGS__),			\
	   quat_t: rotateq,			\
	   default: rotate3f			\
	   )(__VA_ARGS__)


#define inverse(m)				\
  _Generic((m),					\
	   quat_t: inverseq,			\
	   mat3_t: inverse3,			\
	   mat4_t: inverse4			\
	   )(m)
