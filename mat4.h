/**
 * vmath - C vector math library
 *
 * @author: MaiHD
 * @license: NULL
 * @copyright: MaiHD @ ${HOME}, 2017
 */

#pragma once

/**
 * Matrix4x4 data structure
 */
typedef union __vmath_mat4__
{
    struct
    {
	float m00, m01, m02, m03;
	float m10, m11, m12, m13;
	float m20, m21, m22, m23;
	float m30, m31, m32, m33;
    };
    vec4_t rows[4];
    float  m[4][4];
    float  data[16];
} mat4_t;


/**
 * Constants
 */
static const mat4_t MAT4_IDENTITY = {
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1,
};


/**
 * Create a identity matrix 4x4
 */
__vmath__ mat4_t mat4()
{
    return MAT4_IDENTITY;
}


/**
 *
 */
__vmath__ mat3_t tomat3(mat4_t m)
{
    mat3_t r = {
	m.m00, m.m01, m.m02,
	m.m20, m.m11, m.m12,
	m.m10, m.m21, m.m22,
    };
    return r;
}


/**
 *
 */
__vmath__ mat4_t tomat4(mat3_t m)
{
    mat4_t r = {
	m.m00, m.m01, m.m02, 0,
	m.m20, m.m11, m.m12, 0,
	m.m10, m.m21, m.m22, 0,
        0,     0,     0, 0,
    };
    return r;
}


/**
 * Create translate matrix
 */
__vmath__ mat4_t translate3f(float x, float y, float z)
{				
    mat4_t r = {
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	x, y, z, 1,
    };
    return r;
}


__vmath__ mat4_t translate2f(float x, float y)
{
    return translate3f(x, y, 0);
}


__vmath__ mat4_t translatev2(vec2_t v)
{
    return translate3f(v.x, v.y, 0.0);
}


__vmath__ mat4_t translatev3(vec3_t v)
{
    return translate3f(v.x, v.y, v.z);
}


/**
 * Create scale matrix
 */
__vmath__ mat4_t scale3f(float x, float y, float z)
{
    mat4_t r = {
	x, 0, 0, 0,
	0, y, 0, 0,
	0, 0, z, 0,
	0, 0, 0, 1,
    };
    return r;
}


__vmath__ mat4_t scale1f(float s)
{
    return scale3f(s, s, s);
}


__vmath__ mat4_t scale2f(float x, float y)
{
    return scale3f(x, y, 1.0);
}


__vmath__ mat4_t scalev2(vec2_t v)
{
    return scale3f(v.x, v.y, 1.0);
}


__vmath__ mat4_t scalev3(vec3_t v)
{
    return scale3f(v.x, v.y, v.z);
}

/**
 * Create mat4 rotate in X-axis matrix
 */
__vmath__ mat4_t rotatex(float angle)
{
    const float c = cosf(angle);
    const float s = sinf(angle);
    mat4_t r = {
	1,  0, 0, 0,
	0,  c, s, 0,
	0, -s, c, 0,
	0,  0, 0, 1,
    };
    return r;
}


/**
 * Create mat4 rotate in Y-axis matrix
 */
__vmath__ mat4_t rotatey(float angle)
{
    const float c = cosf(angle);
    const float s = sinf(angle);
    mat4_t r = {
	c,  0, s, 0,
	0,  1, 0, 0,
	-s,  0, c, 0,
	0,  0, 0, 1,
    };
    return r;
}


/**
 * Create mat4 rotate in Z-axis matrix
 */
__vmath__ mat4_t rotatez(float angle)
{
    const float c = cosf(angle);
    const float s = sinf(angle);
    mat4_t r = {
	c, s, 0, 0,
	-s, c, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1,
    };
    return r;
}


/**
 * Create mat4 rotate matrix
 */
__vmath__ mat4_t rotate3f(float x, float y, float z, float angle)
{
    const float c = cosf(-angle);
    const float s = sinf(-angle);
    const float t = 1.0f - c;
  
    mat4_t r = {
	/* Row 1
	 */
	t * x * x + c, t * x * y - s * z,
	t * x * z + s * y, 0.0f,

	/* Row 2
	 */
	t * x * y + s * z, t * y * y + c,
	t * y * z - s * x, 0.0f,

	/* Row 3
	 */
	t * x * z - s * y, t * y * z + s * x,
	t * z * z + c, 0.0f,

	/* Row 4
	 */
	0, 0, 0, 1.0f,
    };
    return r;
}


/**
 * Create rotate matrix with axis and angle
 */
__vmath__ mat4_t rotatev(vec3_t v, float angle)
{
    return rotate3f(v.x, v.y, v.z, angle);
}


/**
 * Create rotation matrix from quaternion
 */
__vmath__ mat4_t rotateq(quat_t q)
{
    const vec4_t aa = toaxis(q); /* axis-angle form of quaternion */
    return rotatev(aa.axis, aa.angle);
}


/**
 * Addidtion of two matrix4x4
 */
__vmath__ mat4_t addm4(mat4_t a, mat4_t b)
{
    mat4_t r;
    r.rows[0] = add4(a.rows[0], b.rows[0]);
    r.rows[1] = add4(a.rows[1], b.rows[1]);
    r.rows[2] = add4(a.rows[2], b.rows[2]);
    r.rows[3] = add4(a.rows[3], b.rows[3]);
    return r;
}


/**
 * Subtraction of two matrix4x4
 */
__vmath__ mat4_t subm4(mat4_t a, mat4_t b)
{
    mat4_t r;
    r.rows[0] = sub4(a.rows[0], b.rows[0]);
    r.rows[1] = sub4(a.rows[1], b.rows[1]);
    r.rows[2] = sub4(a.rows[2], b.rows[2]);
    r.rows[3] = sub4(a.rows[3], b.rows[3]);
    return r;
}


/**
 * Multiplication of two matrix4x4
 */
__vmath__ mat4_t mulm4(mat4_t a, mat4_t b)
{
    mat4_t r = {
	b.m00 * a.m00 + b.m01 * a.m10 + b.m02 * a.m20 + b.m03 * a.m30,
	b.m00 * a.m01 + b.m01 * a.m11 + b.m02 * a.m21 + b.m03 * a.m31,
	b.m00 * a.m02 + b.m01 * a.m12 + b.m02 * a.m22 + b.m03 * a.m32,
	b.m00 * a.m03 + b.m01 * a.m13 + b.m02 * a.m23 + b.m03 * a.m33,
    
	b.m10 * a.m00 + b.m11 * a.m10 + b.m12 * a.m20 + b.m13 * a.m30,
	b.m10 * a.m01 + b.m11 * a.m11 + b.m12 * a.m21 + b.m13 * a.m31,
	b.m10 * a.m02 + b.m11 * a.m12 + b.m12 * a.m22 + b.m13 * a.m32,
	b.m10 * a.m03 + b.m11 * a.m13 + b.m12 * a.m23 + b.m13 * a.m33,
     
	b.m20 * a.m00 + b.m21 * a.m10 + b.m22 * a.m20 + b.m23 * a.m30,
	b.m20 * a.m01 + b.m21 * a.m11 + b.m22 * a.m21 + b.m23 * a.m31,
	b.m20 * a.m02 + b.m21 * a.m12 + b.m22 * a.m22 + b.m23 * a.m32,
	b.m20 * a.m03 + b.m21 * a.m13 + b.m22 * a.m23 + b.m23 * a.m33,
	
	b.m30 * a.m00 + b.m31 * a.m10 + b.m32 * a.m20 + b.m33 * a.m30,
	b.m30 * a.m01 + b.m31 * a.m11 + b.m32 * a.m21 + b.m33 * a.m31,
	b.m30 * a.m02 + b.m31 * a.m12 + b.m32 * a.m22 + b.m33 * a.m32,
	b.m30 * a.m03 + b.m31 * a.m13 + b.m32 * a.m23 + b.m33 * a.m33,
    };
    return r;
}


/**
 * Compare if two matrix is equal or not
 * @return: true if equal, false otherwise
 */
__vmath__ bool eqlm4(mat4_t a, mat4_t b)
{
    return
	eql4(a.rows[0], b.rows[0]) &&
	eql4(a.rows[1], b.rows[1]) &&
	eql4(a.rows[2], b.rows[2]) &&
	eql4(a.rows[3], b.rows[3]);
}


/**
 * Transpose matrix4x4
 */
__vmath__ mat4_t transpose4(mat4_t m)
{
    mat4_t r = {
	m.m00, m.m10, m.m20, m.m30,
	m.m01, m.m11, m.m21, m.m31,
	m.m02, m.m12, m.m22, m.m32,
	m.m03, m.m13, m.m23, m.m33,
    };
    return r;
}


/**
 * Create orthographic projection matrix
 */
__vmath__ mat4_t ortho(float l, float r, float b, float t, float n, float f)
{
    mat4_t m = {
	2.0f / (r - l), 0, 0, 0,
	0, 2.0f / (t - b), 0, 0,
	0, 0, 2.0f / (f - n), 0,
	(l + r) / (l - r), (b + t) / (b - t), (n + f) / (n - f), 1,
    };
    return m;
}


/**
 * Create frustum matrix
 */
__vmath__ mat4_t frustum(float l, float r, float b, float t, float n, float f)
{
    mat4_t m = {
	2.0f / (r - l), 0, 0, 0,
	0, 2.0f / (t - b), 0, 0,
	(r + l) / (r - l), (t + b) / (t - b), (f + b) / (f - n), 1,
	0, 0, 2.0f / (f - n), 0,
    };
    return m;
}


/**
 * Create perspective projection matrix
 */
__vmath__ mat4_t perspective(float fov, float aspect, float near, float far)
{
    const float a = 1.0f / tanf(fov * 0.5f);
    const float b = far / (near - far);
    mat4_t r = {
	a / aspect, 0, 0, 0,
	0, a, 0, 0,
	0, 0, b, -1,
	0, 0, near * b, 0,
    };
    return r;
}


/**
 * Create view matrix when focus on the position
 */
__vmath__ mat4_t lookat(vec3_t eye, vec3_t target, vec3_t up)
{
    const vec3_t z = normalize3(sub3(eye, target));
    const vec3_t x = normalize3(cross3(up, z));
    const vec3_t y = normalize3(cross3(z, x));
    mat4_t r = {
	x.x, y.x, z.x, 0,
	x.y, y.y, z.y, 0,
	x.z, y.z, z.z, 0,
	-dot3(x, eye), -dot3(y, eye), -dot3(z, eye), 1.0f,
    };
    return r;
}


/**
 * Calculate deternimant value
 */
__vmath__ float determinant4(mat4_t m)
{
    float s1 = m.m00 * m.m11 - m.m10 * m.m01;
    float s2 = m.m00 * m.m12 - m.m10 * m.m02;
    float s3 = m.m00 * m.m13 - m.m10 * m.m03;
    float s4 = m.m01 * m.m12 - m.m11 * m.m02;
    float s5 = m.m01 * m.m13 - m.m11 * m.m03;
    float s6 = m.m02 * m.m13 - m.m12 * m.m03;
  
    float c1 = m.m20 * m.m31 - m.m30 * m.m21;
    float c2 = m.m20 * m.m32 - m.m30 * m.m22;
    float c3 = m.m20 * m.m33 - m.m30 * m.m23;
    float c4 = m.m21 * m.m32 - m.m31 * m.m22;
    float c5 = m.m21 * m.m32 - m.m31 * m.m23;
    float c6 = m.m22 * m.m33 - m.m32 * m.m23;

    return s1 * c6 - s2 * c5 + s3 * c4 + s4 * c3 - s5 * c2 + s6 * c1;
}


/**
 * Get inverse version of matrix4x4
 */
__vmath__ mat4_t inverse4(mat4_t m)
{
    float s1 = m.m00 * m.m11 - m.m10 * m.m01;
    float s2 = m.m00 * m.m12 - m.m10 * m.m02;
    float s3 = m.m00 * m.m13 - m.m10 * m.m03;
    float s4 = m.m01 * m.m12 - m.m11 * m.m02;
    float s5 = m.m01 * m.m13 - m.m11 * m.m03;
    float s6 = m.m02 * m.m13 - m.m12 * m.m03;
  
    float c1 = m.m20 * m.m31 - m.m30 * m.m21;
    float c2 = m.m20 * m.m32 - m.m30 * m.m22;
    float c3 = m.m20 * m.m33 - m.m30 * m.m23;
    float c4 = m.m21 * m.m32 - m.m31 * m.m22;
    float c5 = m.m21 * m.m32 - m.m31 * m.m23;
    float c6 = m.m22 * m.m33 - m.m32 * m.m23;
  
    float d = s1 * c6 - s2 * c5 + s3 * c4 + s4 * c3 - s5 * c2 + s6 * c1;
    if (d == 0.0f) {
	return m;
    }
    d = 1.0f / d;
  
    mat4_t r = {
	d *  (m.m11 * c6 - m.m12 * c5 + m.m13 * c4),
	d * -(m.m01 * c6 - m.m02 * c5 + m.m03 * c4),
	d *  (m.m31 * s6 - m.m32 * s5 + m.m33 * s4),
	d * -(m.m21 * s6 - m.m22 * s5 + m.m23 * s4),
      
	d * -(m.m10 * c6 - m.m12 * c3 + m.m13 * c2),
	d *  (m.m00 * c6 - m.m02 * c3 + m.m03 * c2),
	d * -(m.m30 * s6 - m.m32 * s3 + m.m33 * s2),
	d *  (m.m20 * s6 - m.m22 * s3 + m.m23 * s2),
      
	d *  (m.m10 * c5 - m.m11 * c3 + m.m13 * c1),
	d * -(m.m00 * c5 - m.m01 * c3 + m.m03 * c1),
	d *  (m.m30 * s5 - m.m31 * s3 + m.m33 * s1),
	d * -(m.m20 * s5 - m.m21 * s3 + m.m23 * s1),

	d * -(m.m10 * c4 - m.m11 * c2 + m.m12 * c1),
	d *  (m.m00 * c4 - m.m01 * c2 + m.m02 * c1),
	d * -(m.m30 * s4 - m.m31 * s2 + m.m32 * s1),
	d *  (m.m20 * s4 - m.m21 * s2 + m.m22 * s1),
    };
    return r;
}


/**
 * Apply transform (Matrix4x4) for Vector4D
 */
__vmath__ vec4_t transform4(mat4_t m, vec4_t v)
{
    const vec4_t c0 = vec4(m.m00, m.m10, m.m20, m.m30);
    const vec4_t c1 = vec4(m.m01, m.m11, m.m21, m.m31);
    const vec4_t c2 = vec4(m.m02, m.m12, m.m22, m.m32);
    const vec4_t c3 = vec4(m.m03, m.m13, m.m23, m.m33);

    const float x = dot4(c0, v);
    const float y = dot4(c1, v);
    const float z = dot4(c2, v);
    const float w = dot4(c3, v);
    return vec4(x, y, z, w);
}
