/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */

#pragma once

#ifndef __cplusplus
# error "Attempt to overload functions on non-C++ language"
#endif


namespace vmath
{
    /*****************************
     * Constructors
     *****************************/

    __vmath__ vec2_t vec2(float x = 0.0f, float y = 0.0f)
    {
	return ::vec2(x, y);
    }


    __vmath__ vec3_t vec3(float x = 0.0f, float y = 0.0f, float z = 0.0f)
    {
	return ::vec3(x, y);
    }


    __vmath__ vec3_t vec3(vec2_t v, float z = 0.0f)
    {
	return ::vec3(v.x, v.y, z);
    }


    __vmath__ vec4_t vec4(float x = 0.0f, float y = 0.0f,
			  float z = 0.0f, float w = 0.0f)
    {
	return ::vec4(x, y, z, w);
    }


    __vmath__ vec4_t vec4(vec2_t v, float z = 0.0f, float w = 0.0f)
    {
	return ::vec4(v.x, v.y, z, w);
    }


    __vmath__ vec4_t vec4(vec3_t v, float w = 0.0f)
    {
	return ::vec4(v.x, v.y, v.z, w);
    }


    __vmath__ mat3_t mat3(float m = 1.0f)
    {
        mat3_t r = {
	    m, 0, 0,
	    0, m, 0,
	    0, 0, m,
	};
	return r;
    }


    __vmath__ mat4_t mat4(float m = 1.0f)
    {
	mat4_t r = {
	    m, 0, 0, 0,
	    0, m, 0, 0,
	    0, 0, m, 0,
	    0, 0, 0, m,
	};
	return r;
    }
    

    __vmath__ quat_t quat(float x = 0.0f, float y = 0.0f,
			  float z = 0.0f, float w = 0.0f)
    { 
	return ::quat(x, y, z, w);
    }


    __vmath__ rect_t rect(float x, float y, float w, float h)
    {
	return ::rect(::vec2(x, y), ::vec2(x + w, y + h));
    }


    __vmath__ rect_t rect(vec2_t min, vec2_t max)
    {
	return ::rect(min, max);
    }
    
    
    /*****************************
     * Normalization
     *****************************/
    
    __vmath__ vec2_t normalize(vec2_t v)
    {
	return normalize2(v);
    }


    __vmath__ vec3_t normalize(vec3_t v)
    {
	return normalize3(v);
    }


    __vmath__ vec4_t normalize(vec4_t v)
    {
	return normalize4(v);
    }

    
    /*****************************
     * Length yielding
     *****************************/

    __vmath__ float length(vec2_t v)
    {
	return len2(v);
    }


    __vmath__ float length(vec3_t v)
    {
	return len3(v);
    }


    __vmath__ float length(vec4_t v)
    {
	return len4(v);
    }


    __vmath__ float lensqr(vec2_t v)
    {
	return lensqr2(v);
    }

    
    __vmath__ float lensqr(vec3_t v)
    {
	return lensqr3(v);
    }

    
    __vmath__ float lensqr(vec4_t v)
    {
	return lensqr4(v);
    }


    /*****************************
     * Addition
     *****************************/
    
    __vmath__ vec2_t add(vec2_t a, vec2_t b)
    {
	return add2(a, b);
    }


    __vmath__ vec3_t add(vec3_t a, vec3_t b)
    {
	return add3(a, b);
    }


    __vmath__ vec4_t add(vec4_t a, vec4_t b)
    {
	return add4(a, b);
    }


    __vmath__ mat3_t add(mat3_t a, mat3_t b)
    {
	return addm3(a, b);
    }


    __vmath__ mat4_t add(mat4_t a, mat4_t b)
    {
	return addm4(a, b);
    }


    /*****************************
     * Subtraction
     *****************************/

    __vmath__ vec2_t sub(vec2_t a, vec2_t b)
    {
	return sub2(a, b);
    }

   
    __vmath__ vec3_t sub(vec3_t a, vec3_t b)
    {
	return sub3(a, b);
    }


    __vmath__ vec4_t sub(vec4_t a, vec4_t b)
    {
	return sub4(a, b);
    }

    
    __vmath__ mat3_t sub(mat3_t a, mat3_t b)
    {
	return subm3(a, b);
    }

    
    __vmath__ mat4_t sub(mat4_t a, mat4_t b)
    {
	return subm4(a, b);
    }


    /*****************************
     * Multiplication
     *****************************/

    __vmath__ vec2_t mul(vec2_t v, float s)
    {
	return mul2(v, s);
    }
    

    __vmath__ vec2_t mul(float s, vec2_t v)
    {
	return mul2(v, s);
    }

    
    __vmath__ vec3_t mul(vec3_t v, float s)
    {
	return mul3(v, s);
    }

    
    __vmath__ vec3_t mul(float s, vec3_t v)
    {
	return mul3(v, s);
    }

    
    __vmath__ vec4_t mul(vec4_t v, float s)
    {
	return mul4(v, s);
    }
    

    __vmath__ vec4_t mul(float s, vec4_t v)
    {
	return mul4(v, s);
    }

    
    __vmath__ quat_t mul(quat_t a, quat_t b)
    {
	return mulq(a, b);
    }

    
    __vmath__ mat3_t mul(mat3_t a, mat3_t b)
    {
	return mulm3(a, b);
    }

    
    __vmath__ mat4_t mul(mat4_t a, mat4_t b)
    {
	return mulm4(a, b);
    }

    
    /*****************************
     * Divisation
     *****************************/

    __vmath__ vec2_t div(vec2_t v, float s)
    {
	return div2(v, s);
    }

    
    __vmath__ vec3_t div(vec3_t v, float s)
    {
	return div3(v, s);
    }


    __vmath__ vec4_t div(vec4_t v, float s)
    {
	return div4(v, s);
    }
    

    /*****************************
     * Negation
     *****************************/
    
    __vmath__ vec2_t neg(vec2_t v)
    {
	return neg2(v);
    }


    __vmath__ vec3_t neg(vec3_t v)
    {
	return neg3(v);
    }

    
    __vmath__ vec4_t neg(vec4_t v)
    {
	return neg4(v);
    }


    /*****************************
     * Negation
     *****************************/

    __vmath__ bool eql(vec2_t a, vec2_t b)
    {
	return eql2(a, b);
    }

    
    __vmath__ bool eql(vec3_t a, vec3_t b)
    {
	return eql3(a, b);
    }

    
    __vmath__ bool eql(vec4_t a, vec4_t b)
    {
	return eql4(a, b);
    }

    
    /*****************************
     * Transpose
     *****************************/
    
    __vmath__ mat3_t transpose(mat3_t x)
    {
	return transpose3(x);
    }

    
    __vmath__ mat4_t transpose(mat4_t x)
    {
	return transpose4(x);
    }

    
    /*****************************
     * Inverse
     *****************************/
    
    __vmath__ mat3_t inverse(mat3_t x)
    {
	return inverse3(x);
    }

    
    __vmath__ mat4_t inverse(mat4_t x)
    {
	return inverse4(x);
    }

    
    __vmath__ quat_t inverse(quat_t x)
    {
	return inverseq(x);
    }

    /*****************************
     * Determinant
     *****************************/

    __vmath__ float determinant(mat3_t x)
    {
	return determinant3(x);
    }

    
    __vmath__ float determinant(mat4_t x)
    {
	return determinant4(x);
    }

    
    /*****************************
     * Translation
     *****************************/

    __vmath__ mat4_t translate(float x, float y)
    {
	return ::translate2f(x, y);
    }
    

    __vmath__ mat4_t translate(float x, float y, float z)
    {
	return ::translate3f(x, y, z);
    }

    
    __vmath__ mat4_t translate(vec2_t v)
    {
	return ::translatev2(v);
    }

    
    __vmath__ mat4_t translate(vec3_t v)
    {
	return ::translatev3(v);
    }


    /*****************************
     * Scaling
     *****************************/

    __vmath__ mat4_t scale(float x, float y)
    {
	return ::scale2f(x, y);
    }
    

    __vmath__ mat4_t scale(float x, float y, float z)
    {
	return ::scale3f(x, y, z);
    }

    
    __vmath__ mat4_t scale(vec2_t v)
    {
	return ::scalev2(v);
    }

    
    __vmath__ mat4_t scale(vec3_t v)
    {
	return ::scalev3(v);
    }
    
    
    /*****************************
     * Rotation
     *****************************/

    __vmath__ mat4_t rotatex(float angle)
    {
	return ::rotatex(angle);
    }

    
    __vmath__ mat4_t rotatey(float angle)
    {
	return ::rotatey(angle);
    }

    
    __vmath__ mat4_t rotatez(float angle)
    {
	return ::rotatez(angle);
    }


    __vmath__ mat4_t rotate(float x, float y, float z, float angle)
    {
	return ::rotate3f(x, y, z, angle);
    }


    __vmath__ mat4_t rotate(vec3_t v, float angle)
    {
	return ::rotatev(v, angle);
    }


    __vmath__ mat4_t rotate(quat_t q)
    {
	return ::rotateq(q);
    }

    
    /*****************************
     * Space transform matrix
     *****************************/

    __vmath__ mat4_t ortho(float l, float r,
			   float b, float t,
			   float n, float f)
    {
	return ::ortho(l, r, b, t, n, f);
    }


    __vmath__ mat4_t frustum(float l, float r,
			     float b, float t,
			     float n, float f)
    {
	return ::frustum(l, r, b, t, n, f);
    }


    __vmath__ mat4_t perspective(float fov, float a, float n, float f)
    {
	return ::perspective(fov, a, n, f);
    }


    __vmath__ mat4_t lookat(vec3_t e, vec3_t t, vec3_t u)
    {
	return ::lookat(e, t, u);
    }
}
