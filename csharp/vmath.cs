#if UNITY_WII || UNITY_ANDROID || UNITY_WEBGL || UNITY_STANDALONE
#define VMATH_UNITY
#endif

#if UNITY_IOS || UNITY_XBOXONE || UNITY_TIZEN || UNITY_TVOS || UNITY_PS4 || UNITY_WSA
#define VMATH_UNITY
#endif

using System;
using System.Diagnostics;
using System.Runtime.CompilerServices;

[System.Serializable]
[DebuggerTypeProxy(typeof(DebuggerProxy))]
public struct vec2 : IFormattable
{
    #region DebuggerProxy
    internal sealed class DebuggerProxy
    {
        public float x;
        public float y;

        public DebuggerProxy(vec2 v)
        {
            x = v.x;
            y = v.y;
        }
    }
    #endregion  

    public float x;
    public float y;

    [MethodImpl(vmath.MethodInlineOptions)]
    public bool Equals(vec2 other)
    {
        return x == other.x && y == other.y;
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public override bool Equals(object obj)
    {
        if (obj == null || GetType() != obj.GetType())
        {
            return false;
        }
        
        return Equals((vec2)obj);
    }
    
    [MethodImpl(vmath.MethodInlineOptions)]
    public override int GetHashCode()
    {
        return (x.GetHashCode()) ^ (y.GetHashCode());
    }

    #region Operators
    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec2 operator+(vec2 a, vec2 b)
    {
        return vmath.add(a, b);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec2 operator-(vec2 a, vec2 b)
    {
        return vmath.sub(a, b);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec2 operator*(vec2 a, vec2 b)
    {
        return vmath.mul(a, b);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec2 operator/(vec2 a, vec2 b)
    {
        return vmath.div(a, b);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec2 operator+(vec2 v, float s)
    {
        return vmath.add(v, s);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec2 operator+(float s, vec2 v)
    {
        return vmath.add(s, v);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec2 operator-(vec2 v, float s)
    {
        return vmath.sub(v, s);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec2 operator-(float s, vec2 v)
    {
        return vmath.sub(s, v);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec2 operator*(vec2 v, float s)
    {
        return vmath.mul(v, s);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec2 operator*(float s, vec2 v)
    {
        return vmath.mul(s, v);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec2 operator/(vec2 v, float s)
    {
        return vmath.div(v, s);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec2 operator/(float s, vec2 v)
    {
        return vmath.div(s, v);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static bool operator==(vec2 a, vec2 b)
    {
        return a.Equals(b);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static bool operator!=(vec2 a, vec2 b)
    {
        return !a.Equals(b);
    }
    #endregion

    #if VMATH_UNITY
    public static implicit operator UnityEngine.Vector2(vec2 v)
    {
        return new UnityEngine.Vector2(v.x, v.y);
    }

    public static implicit operator UnityEngine.Vector3(vec2 v)
    {
        return new UnityEngine.Vector3(v.x, v.y);
    }
    #endif

    #region ToString
    public override string ToString()
    {
        return string.Format("vec2({0:R}, {1:R})", x, y);
    }

    public string ToString(string format, IFormatProvider formatProvider)
    {
        return string.Format("vec2({0:R}, {1:R})", x.ToString(format, formatProvider), y.ToString(format, formatProvider));
    }
    #endregion
}

[System.Serializable]
[DebuggerTypeProxy(typeof(DebuggerProxy))]
public struct vec3 : IFormattable
{
    #region DebuggerProxy
    internal sealed class DebuggerProxy
    {
        public float x;
        public float y;
        public float z;

        public DebuggerProxy(vec3 v)
        {
            x = v.x;
            y = v.y;
            z = v.z;
        }
    }
    #endregion  

    public float x;
    public float y;
    public float z;

    [MethodImpl(vmath.MethodInlineOptions)]
    public bool Equals(vec3 other)
    {
        return x == other.x && y == other.y && z == other.z;
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public override bool Equals(object obj)
    {
        if (obj == null || GetType() != obj.GetType())
        {
            return false;
        }
        
        return Equals((vec3)obj);
    }
    
    [MethodImpl(vmath.MethodInlineOptions)]
    public override int GetHashCode()
    {
        return (x.GetHashCode()) ^ (y.GetHashCode());
    }

    #region Operators
    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec3 operator+(vec3 a, vec3 b)
    {
        return vmath.add(a, b);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec3 operator-(vec3 a, vec3 b)
    {
        return vmath.sub(a, b);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec3 operator*(vec3 a, vec3 b)
    {
        return vmath.mul(a, b);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec3 operator/(vec3 a, vec3 b)
    {
        return vmath.div(a, b);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec3 operator+(vec3 v, float s)
    {
        return vmath.add(v, s);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec3 operator+(float s, vec3 v)
    {
        return vmath.add(s, v);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec3 operator-(vec3 v, float s)
    {
        return vmath.sub(v, s);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec3 operator-(float s, vec3 v)
    {
        return vmath.sub(s, v);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec3 operator*(vec3 v, float s)
    {
        return vmath.mul(v, s);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec3 operator*(float s, vec3 v)
    {
        return vmath.mul(s, v);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec3 operator/(vec3 v, float s)
    {
        return vmath.div(v, s);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec3 operator/(float s, vec3 v)
    {
        return vmath.div(s, v);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static bool operator==(vec3 a, vec3 b)
    {
        return a.Equals(b);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static bool operator!=(vec3 a, vec3 b)
    {
        return !a.Equals(b);
    }
    #endregion

    #if VMATH_UNITY
    public static implicit operator UnityEngine.Vector2(vec3 v)
    {
        return new UnityEngine.Vector2(v.x, v.y);
    }

    public static implicit operator UnityEngine.Vector3(vec3 v)
    {
        return new UnityEngine.Vector3(v.x, v.y, v.z);
    }
    #endif

    #region ToString
    public override string ToString()
    {
        return string.Format("vec3({0:R}, {1:R}, {2:R})", x, y, z);
    }

    public string ToString(string format, IFormatProvider formatProvider)
    {
        return string.Format(format, x.ToString(format, formatProvider), y.ToString(format, formatProvider), z.ToString(format, formatProvider));
    }
    #endregion
}

[System.Serializable]
[DebuggerTypeProxy(typeof(DebuggerProxy))]
public struct vec4 : IFormattable
{
    #region DebuggerProxy
    internal sealed class DebuggerProxy
    {
        public float x;
        public float y;
        public float z;
        public float w;

        public DebuggerProxy(vec4 v)
        {
            x = v.x;
            y = v.y;
            z = v.z;
            w = v.w;
        }
    }
    #endregion  

    public float x;
    public float y;
    public float z;
    public float w;
    
    [MethodImpl(vmath.MethodInlineOptions)]
    public bool Equals(vec4 other)
    {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public override bool Equals(object obj)
    {
        if (obj == null || GetType() != obj.GetType())
        {
            return false;
        }
        
        return Equals((vec2)obj);
    }
    
    [MethodImpl(vmath.MethodInlineOptions)]
    public override int GetHashCode()
    {
        return (x.GetHashCode()) ^ (y.GetHashCode());
    }

    #region Operators
    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec4 operator+(vec4 a, vec4 b)
    {
        return vmath.add(a, b);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec4 operator-(vec4 a, vec4 b)
    {
        return vmath.sub(a, b);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec4 operator*(vec4 a, vec4 b)
    {
        return vmath.mul(a, b);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec4 operator/(vec4 a, vec4 b)
    {
        return vmath.div(a, b);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec4 operator+(vec4 v, float s)
    {
        return vmath.add(v, s);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec4 operator+(float s, vec4 v)
    {
        return vmath.add(s, v);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec4 operator-(vec4 v, float s)
    {
        return vmath.sub(v, s);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec4 operator-(float s, vec4 v)
    {
        return vmath.sub(s, v);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec4 operator*(vec4 v, float s)
    {
        return vmath.mul(v, s);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec4 operator*(float s, vec4 v)
    {
        return vmath.mul(s, v);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec4 operator/(vec4 v, float s)
    {
        return vmath.div(v, s);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec4 operator/(float s, vec4 v)
    {
        return vmath.div(s, v);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static bool operator==(vec4 a, vec4 b)
    {
        return a.Equals(b);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static bool operator!=(vec4 a, vec4 b)
    {
        return !a.Equals(b);
    }
    #endregion

    #if VMATH_UNITY
    public static implicit operator UnityEngine.Vector4(vec4 v)
    {
        return new UnityEngine.Vector4(v.x, v.y, v.z, v.w);
    }
    #endif

    #region ToString
    public override string ToString()
    {
        return string.Format("vec4({0:R}, {1:R}, {2:R}, {3:R})", x, y, z, w);
    }

    public string ToString(string format, IFormatProvider formatProvider)
    {
        return string.Format(format, 
            x.ToString(format, formatProvider),
            y.ToString(format, formatProvider), 
            z.ToString(format, formatProvider), 
            w.ToString(format, formatProvider));
    }
    #endregion
}

[System.Serializable]
[DebuggerTypeProxy(typeof(DebuggerProxy))]
public struct quat : IFormattable
{
    #region DebuggerProxy
    internal sealed class DebuggerProxy
    {
        public float x;
        public float y;
        public float z;
        public float w;

        public DebuggerProxy(quat q)
        {
            x = q.x;
            y = q.y;
            z = q.z;
            w = q.w;
        }
    }
    #endregion

    public float x;
    public float y;
    public float z;
    public float w;

    #region ToString
    public override string ToString()
    {
        return string.Format("quat({0:R}, {1:R}, {2:R}, {3:R})", x, y, z, w);
    }

    public string ToString(string format, IFormatProvider formatProvider)
    {
        return string.Format(format, 
            x.ToString(format, formatProvider),
            y.ToString(format, formatProvider), 
            z.ToString(format, formatProvider), 
            w.ToString(format, formatProvider));
    }
    #endregion
}

[System.Serializable]
[DebuggerTypeProxy(typeof(DebuggerProxy))]
public struct mat2 : IFormattable
{
    #region DebuggerProxy
    internal sealed class DebuggerProxy
    {
        public float m00;
        public float m01;
        public float m10;
        public float m11;

        public DebuggerProxy(mat2 m)
        {
            m00 = m.m00;
            m01 = m.m01;
            m10 = m.m10;
            m11 = m.m11;
        }
    }
    #endregion
    
    public float m00;
    public float m01;
    public float m10;
    public float m11;

    #region ToString
    public override string ToString()
    {
        return string.Format("mat2({0:R}, {1:R}, {2:R}, {3:R})", m00, m01, m10, m11);
    }

    public string ToString(string format, IFormatProvider formatProvider)
    {
        return string.Format(format, 
            m00.ToString(format, formatProvider), 
            m01.ToString(format, formatProvider),
            m10.ToString(format, formatProvider),
            m11.ToString(format, formatProvider));
    }
    #endregion
}

[System.Serializable]
[DebuggerTypeProxy(typeof(DebuggerProxy))]
public struct mat3 : IFormattable
{
    #region DebuggerProxy
    internal sealed class DebuggerProxy
    {
        public float m00;
        public float m01;
        public float m02;
        public float m10;
        public float m11;
        public float m12;
        public float m20;
        public float m21;
        public float m22;

        public DebuggerProxy(mat3 m)
        {
            m00 = m.m00;
            m01 = m.m01;
            m02 = m.m02;
            m10 = m.m10;
            m11 = m.m11;
            m12 = m.m12;
            m20 = m.m20;
            m21 = m.m21;
            m22 = m.m22;
        }
    }
    #endregion

    public float m00;
    public float m01;
    public float m02;
    public float m10;
    public float m11;
    public float m12;
    public float m20;
    public float m21;
    public float m22;

    #region ToString
    public override string ToString()
    {
        return string.Format(@"mat3({0:R}, {1:R}, {2:R},
                                    {3:R}, {4:R}, {5:R},
                                    {6:R}, {7:R}, {8:R})", 
                                    m00, m01, m02,
                                    m10, m11, m12,
                                    m20, m21, m22);
    }

    public string ToString(string format, IFormatProvider formatProvider)
    {
        return string.Format(format,
            m00.ToString(format, formatProvider),
            m01.ToString(format, formatProvider),
            m02.ToString(format, formatProvider),
            m10.ToString(format, formatProvider),
            m11.ToString(format, formatProvider),
            m12.ToString(format, formatProvider),
            m20.ToString(format, formatProvider),
            m21.ToString(format, formatProvider),
            m22.ToString(format, formatProvider));
    }
    #endregion
}

[System.Serializable]
[DebuggerTypeProxy(typeof(DebuggerProxy))]
public struct mat4 : IFormattable
{
    #region DebuggerProxy
    internal sealed class DebuggerProxy
    {
        public float m00;
        public float m01;
        public float m02;
        public float m03;
        public float m10;
        public float m11;
        public float m12;
        public float m13;
        public float m20;
        public float m21;
        public float m22;
        public float m23;
        public float m30;
        public float m31;
        public float m32;
        public float m33;

        public DebuggerProxy(mat4 m)
        {
            m00 = m.m00;
            m01 = m.m01;
            m02 = m.m02;
            m03 = m.m03;
            m10 = m.m10;
            m11 = m.m11;
            m12 = m.m12;
            m13 = m.m13;
            m20 = m.m20;
            m21 = m.m21;
            m22 = m.m22;
            m23 = m.m23;
            m30 = m.m30;
            m31 = m.m31;
            m32 = m.m32;
            m33 = m.m33;
        }
    }
    #endregion


    public float m00;
    public float m01;
    public float m02;
    public float m03;
    public float m10;
    public float m11;
    public float m12;
    public float m13;
    public float m20;
    public float m21;
    public float m22;
    public float m23;
    public float m30;
    public float m31;
    public float m32;
    public float m33;


    #region ToString
    public override string ToString()
    {
        return string.Format(@"mat4({ 0:R}, { 1:R}, { 2:R}, { 3:R}, 
                                    { 4:R}, { 5:R}, { 6:R}, { 7:R}, 
                                    { 8:R}, { 9:R}, {10:R}, {11:R},
                                    {12:R}, {13:R}, {14:R}, {15:R})", 
                                    m00, m01, m02, m03,
                                    m10, m11, m12, m13,
                                    m20, m21, m22, m23,
                                    m30, m31, m32, m33);
    }

    public string ToString(string format, IFormatProvider formatProvider)
    {
        return string.Format(format,
            m00.ToString(format, formatProvider),
            m01.ToString(format, formatProvider),
            m02.ToString(format, formatProvider),
            m03.ToString(format, formatProvider),
            m10.ToString(format, formatProvider),
            m11.ToString(format, formatProvider),
            m12.ToString(format, formatProvider),
            m13.ToString(format, formatProvider),
            m20.ToString(format, formatProvider),
            m21.ToString(format, formatProvider),
            m22.ToString(format, formatProvider),
            m23.ToString(format, formatProvider),
            m30.ToString(format, formatProvider),
            m31.ToString(format, formatProvider),
            m32.ToString(format, formatProvider),
            m33.ToString(format, formatProvider));
    }
    #endregion
}

public static class vmath
{
    public const MethodImplOptions MethodInlineOptions = (MethodImplOptions)0x100;

    #region Constructors
    [MethodImpl(MethodInlineOptions)]
    public static vec2 vec2()
    {
        vec2 result = new vec2();
        return result;
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 vec2(float s)
    {
        vec2 result;
        result.x = s;
        result.y = s;
        return result;
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 vec2(float x, float y)
    {
        vec2 result;
        result.x = x;
        result.y = y;
        return result;
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 vec3()
    {
        vec3 result = new vec3();
        return result;
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 vec3(float s)
    {
        vec3 result;
        result.x = s;
        result.y = s;
        result.z = s;
        return result;
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 vec3(float x, float y, float z = 0.0f)
    {
        vec3 result;
        result.x = x;
        result.y = y;
        result.z = z;
        return result;
    }
    
    [MethodImpl(MethodInlineOptions)]
    public static vec3 vec3(vec2 v, float z = 0.0f)
    {
        vec3 result;
        result.x = v.x;
        result.y = v.y;
        result.z = z;
        return result;
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 vec4()
    {
        vec4 result = new vec4();
        return result;
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 vec4(float s)
    {
        vec4 result;
        result.x = s;
        result.y = s;
        result.z = s;
        result.w = s;
        return result;
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 vec4(float x, float y, float z, float w)
    {
        vec4 result;
        result.x = x;
        result.y = y;
        result.z = z;
        result.w = w;
        return result;
    }
    
    [MethodImpl(MethodInlineOptions)]
    public static vec4 vec4(vec2 v, float z = 0.0f, float w = 0.0f)
    {
        vec4 result;
        result.x = v.x;
        result.y = v.y;
        result.z = z;
        result.w = w;
        return result;
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 vec4(vec3 v, float w = 0.0f)
    {
        vec4 result;
        result.x = v.x;
        result.y = v.y;
        result.z = v.z;
        result.w = w;
        return result;
    }

    [MethodImpl(MethodInlineOptions)]
    public static quat quat()
    {
        quat result = new quat();
        return result;
    }

    [MethodImpl(MethodInlineOptions)]
    public static quat quat(float s)
    {
        quat result;
        result.x = 0;
        result.y = 0;
        result.z = 0;
        result.w = s;
        return result;
    }

    [MethodImpl(MethodInlineOptions)]
    public static quat quat(float x, float y, float z, float w)
    {
        quat result;
        result.x = x;
        result.y = y;
        result.z = z;
        result.w = w;
        return result;
    }

    [MethodImpl(MethodInlineOptions)]
    public static mat4 mat4()
    {
        mat4 result = new mat4();
        return result;
    }

    [MethodImpl(MethodInlineOptions)]
    public static mat4 mat4(float s)
    {
        mat4 result;
        result.m00 = s; result.m01 = 0; result.m02 = 0; result.m03 = 0;
        result.m10 = 0; result.m11 = s; result.m12 = 0; result.m13 = 0;
        result.m20 = 0; result.m21 = 0; result.m22 = s; result.m23 = 0;
        result.m30 = 0; result.m31 = 0; result.m32 = 0; result.m33 = s;
        return result;
    }

    [MethodImpl(MethodInlineOptions)]
    public static mat4 mat4(vec4 row0, vec4 row1, vec4 row2, vec4 row3)
    {
        mat4 result;
        result.m00 = row0.x; result.m01 = row0.y; result.m02 = row0.z; result.m03 = row0.w;
        result.m10 = row1.x; result.m11 = row1.y; result.m12 = row1.z; result.m13 = row1.w;
        result.m20 = row2.x; result.m21 = row2.y; result.m22 = row2.z; result.m23 = row2.w;
        result.m30 = row3.x; result.m31 = row3.y; result.m32 = row3.z; result.m33 = row3.w;
        return result;
    }

    [MethodImpl(MethodInlineOptions)]
    public static mat4 mat4(float m00, float m01, float m02, float m03,
                            float m10, float m11, float m12, float m13,
                            float m20, float m21, float m22, float m23,
                            float m30, float m31, float m32, float m33)
    {
        mat4 result;
        result.m00 = m00; result.m01 = m01; result.m02 = m02; result.m03 = m03;
        result.m10 = m10; result.m11 = m11; result.m12 = m12; result.m13 = m13;
        result.m20 = m20; result.m21 = m21; result.m22 = m22; result.m23 = m23;
        result.m30 = m30; result.m31 = m31; result.m32 = m32; result.m33 = m33;
        return result;
    }
    #endregion Constructors...

    #region vec2 functions
    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec2 add(vec2 a, vec2 b)
    {
        return vec2(a.x + b.x, a.y + b.y);
    }

    [MethodImpl(vmath.MethodInlineOptions)]
    public static vec2 sub(vec2 a, vec2 b)
    {
        return vec2(a.x - b.x, a.y - b.y);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 mul(vec2 a, vec2 b)
    {
        return vec2(a.x * b.x, a.y * b.y);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 div(vec2 a, vec2 b)
    {
        return vec2(a.x / b.x, a.y / b.y);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 add(vec2 v, float s)
    {
        return add(v, vec2(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 add(float s, vec2 v)
    {
        return add(vec2(s), v);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 sub(vec2 v, float s)
    {
        return sub(v, vec2(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 sub(float s, vec2 v)
    {
        return sub(vec2(s), v);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 mul(vec2 v, float s)
    {
        return mul(v, vec2(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 mul(float s, vec2 v)
    {
        return mul(vec2(s), v);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 div(vec2 v, float s)
    {
        return div(v, vec2(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 div(float s, vec2 v)
    {
        return div(vec2(s), v);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 neg(vec2 v)
    {  
        return vec2(-v.x, -v.y);
    }

    [MethodImpl(MethodInlineOptions)]
    public static float dot(vec2 a, vec2 b)
    {
        return a.x * b.x + a.y * b.y;
    }

    [MethodImpl(MethodInlineOptions)]
    public static float lengthsquared(vec2 v)
    {
        return dot(v, v);
    }

    [MethodImpl(MethodInlineOptions)]
    public static float length(vec2 v)
    {
        return (float)Math.Sqrt(lengthsquared(v));
    }

    [MethodImpl(MethodInlineOptions)]
    public static float distance(vec2 a, vec2 b)
    {
        return length(sub(a, b));
    }

    [MethodImpl(MethodInlineOptions)]
    public static float distancesquared(vec2 a, vec2 b)
    {
        return lengthsquared(sub(a, b));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 reflect(vec2 v, vec2 n)
    {
        return sub(v, mul(n, 2.0f * dot(v, n)));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 normalize(vec2 v)
    {
        float lsqr = lengthsquared(v);
        if (lsqr != 1.0f && lsqr > 0.0f)
        {
            float l = 1.0f / (float)Math.Sqrt(lsqr);
            return vec2(v.x * l, v.y * l);
        }
        else
        {
            return v;
        }
    }
    #endregion vec2...
    /* * */

    #region vec3 functions
    [MethodImpl(MethodInlineOptions)]
    public static vec3 add(vec3 a, vec3 b)
    {
        return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 sub(vec3 a, vec3 b)
    {
        return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 mul(vec3 a, vec3 b)
    {
        return vec3(a.x * b.x, a.y * b.y, a.z * b.z);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 div(vec3 a, vec3 b)
    {
        return vec3(a.x / b.x, a.y / b.y, a.z / b.z);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 add(vec3 v, float s)
    {
        return add(v, vec3(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 add(float s, vec3 v)
    {
        return add(vec3(s), v);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 sub(vec3 v, float s)
    {
        return add(v, vec3(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 sub(float s, vec3 v)
    {
        return add(vec3(s), v);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 mul(vec3 v, float s)
    {
        return mul(v, vec3(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 mul(float s, vec3 v)
    {
        return mul(v, vec3(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 div(vec3 v, float s)
    {
        return div(v, vec3(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 div(float s, vec3 v)
    {
        return div(vec3(s), v);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 neg(vec3 v)
    {  
        return vec3(-v.x, -v.y, -v.z);
    }

    [MethodImpl(MethodInlineOptions)]
    public static float dot(vec3 a, vec3 b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    [MethodImpl(MethodInlineOptions)]
    public static float lengthsquared(vec3 v)
    {
        return dot(v, v);
    }

    [MethodImpl(MethodInlineOptions)]
    public static float length(vec3 v)
    {
        return (float)Math.Sqrt(length(v));
    }

    [MethodImpl(MethodInlineOptions)]
    public static float distancesquared(vec3 a, vec3 b)
    {
        return lengthsquared(sub(a, b));
    }

    [MethodImpl(MethodInlineOptions)]
    public static float distance(vec3 a, vec3 b)
    {
        return length(sub(a, b));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 cross(vec3 a, vec3 b)
    {
        return vec3(
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        );
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 reflect(vec3 v, vec3 n)
    {
        return sub(v, mul(n, 2.0f * dot(v, n)));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 normalize(vec3 v)
    {
        float lsqr = lengthsquared(v);
        if (lsqr != 1.0f && lsqr > 0.0f)
        {
            float l = 1.0f / (float)Math.Sqrt(lsqr);
            return vec3(v.x * l, v.y * l, v.z * l);
        }
        else
        {
            return v;
        }
    }
    #endregion vec3...
    /* * */

    #region vec4 functions

    [MethodImpl(MethodInlineOptions)]
    public static vec4 add(vec4 a, vec4 b)
    {
        return vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 sub(vec4 a, vec4 b)
    {
        return vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 mul(vec4 a, vec4 b)
    {
        return vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 div(vec4 a, vec4 b)
    {
        return vec4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 add(vec4 v, float s)
    {
        return add(v, vec4(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 sub(vec4 v, float s)
    {
        return sub(v, vec4(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 mul(vec4 v, float s)
    {
        return mul(v, vec4(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 div(vec4 v, float s)
    {
        return div(v, vec4(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 add(float s, vec4 v)
    {
        return add(vec4(s), v);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 sub(float s, vec4 v)
    {
        return sub(vec4(s), v);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 mul(float s, vec4 v)
    {
        return mul(vec4(s), v);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 div(float s, vec4 v)
    {
        return div(vec4(s), v);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 neg(vec4 v)
    {  
        return vec4(-v.x, -v.y, -v.z, -v.w);
    }

    [MethodImpl(MethodInlineOptions)]
    public static float dot(vec4 a, vec4 b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    [MethodImpl(MethodInlineOptions)]
    public static float lengthsquared(vec4 v)
    {
        return dot(v, v);
    }

    [MethodImpl(MethodInlineOptions)]
    public static float length(vec4 v)
    {
        return (float)Math.Sqrt(lengthsquared(v));
    }

    [MethodImpl(MethodInlineOptions)]
    public static float distancesquared(vec4 a, vec4 b)
    {
        return lengthsquared(sub(a, b));
    }

    [MethodImpl(MethodInlineOptions)]
    public static float distance(vec4 a, vec4 b)
    {
        return length(sub(a, b));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 reflect(vec4 v, vec4 n)
    {
        return sub(v, mul(n, 2.0f * dot(v, n)));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 normalize(vec4 v)
    {
        float lsqr = lengthsquared(v);
        if (lsqr != 1.0f && lsqr > 0.0f)
        {
            float l = 1.0f / (float)Math.Sqrt(lsqr);
            return vec4(v.x * l, v.y * l, v.z * l, v.w * l);
        }
        else
        {
            return v;
        }
    }
    #endregion vec4...
    /* * */

    #region quat functions

    #endregion quat...
    /* * */

    #region mat2 functions

    #endregion mat2...
    /* * */

    #region mat3 functions

    #endregion mat3...
    /* * */

    #region mat4 functions
    [MethodImpl(MethodInlineOptions)]
    public static mat4 add(mat4 a, mat4 b)
    {
        return mat4(
            a.m00 + b.m00, a.m01 + b.m01, a.m02 + b.m02, a.m03 + b.m03, 
            a.m10 + b.m10, a.m11 + b.m11, a.m12 + b.m12, a.m13 + b.m13,
            a.m20 + b.m20, a.m21 + b.m21, a.m22 + b.m22, a.m23 + b.m23,
            a.m30 + b.m30, a.m31 + b.m31, a.m32 + b.m32, a.m33 + b.m33
        );
    }

    [MethodImpl(MethodInlineOptions)]
    public static mat4 sub(mat4 a, mat4 b)
    {
        return mat4(
            a.m00 - b.m00, a.m01 - b.m01, a.m02 - b.m02, a.m03 - b.m03, 
            a.m10 - b.m10, a.m11 - b.m11, a.m12 - b.m12, a.m13 - b.m13,
            a.m20 - b.m20, a.m21 - b.m21, a.m22 - b.m22, a.m23 - b.m23,
            a.m30 - b.m30, a.m31 - b.m31, a.m32 - b.m32, a.m33 - b.m33
        );
    }

    [MethodImpl(MethodInlineOptions)]
    public static mat4 mul(mat4 a, mat4 b)
    {
        return mat4(
            /* Row 1 */
            a.m00 * b.m00 + a.m10 * b.m01 + a.m20 * b.m02 + a.m30 * b.m03, 
            a.m01 * b.m00 + a.m11 * b.m01 + a.m21 * b.m02 + a.m31 * b.m03,
            a.m02 * b.m00 + a.m12 * b.m01 + a.m22 * b.m02 + a.m32 * b.m03,
            a.m03 * b.m00 + a.m13 * b.m01 + a.m23 * b.m02 + a.m33 * b.m03,

            /* Row 2*/
            a.m00 * b.m10 + a.m10 * b.m11 + a.m20 * b.m12 + a.m30 * b.m13, 
            a.m21 * b.m10 + a.m11 * b.m11 + a.m21 * b.m12 + a.m31 * b.m13,
            a.m02 * b.m10 + a.m12 * b.m11 + a.m22 * b.m12 + a.m32 * b.m13,
            a.m03 * b.m10 + a.m13 * b.m11 + a.m23 * b.m12 + a.m33 * b.m13,

            /* Row 3 */
            a.m00 * b.m20 + a.m10 * b.m21 + a.m20 * b.m22 + a.m30 * b.m23, 
            a.m01 * b.m20 + a.m11 * b.m21 + a.m21 * b.m22 + a.m31 * b.m23,
            a.m02 * b.m20 + a.m12 * b.m21 + a.m22 * b.m22 + a.m32 * b.m23,
            a.m03 * b.m20 + a.m13 * b.m21 + a.m23 * b.m22 + a.m33 * b.m23,

            /* Row 4 */
            a.m00 * b.m30 + a.m10 * b.m31 + a.m20 * b.m32 + a.m30 * b.m33, 
            a.m01 * b.m30 + a.m11 * b.m31 + a.m21 * b.m32 + a.m31 * b.m33,
            a.m02 * b.m30 + a.m12 * b.m31 + a.m22 * b.m32 + a.m32 * b.m33,
            a.m03 * b.m30 + a.m13 * b.m31 + a.m23 * b.m32 + a.m33 * b.m33
        );
    }

    [MethodImpl(MethodInlineOptions)]
    public static mat4 mul(mat4 m, float s)
    {
        return mat4(
            /* Row 1 */
            m.m00 * s, 
            m.m01 * s,
            m.m02 * s,
            m.m03 * s,

            /* Row 2*/
            m.m10 * s, 
            m.m11 * s,
            m.m12 * s,
            m.m13 * s,

            /* Row 3 */
            m.m20 * s, 
            m.m21 * s,
            m.m22 * s,
            m.m23 * s,

            /* Row 4 */
            m.m30 * s, 
            m.m31 * s,
            m.m32 * s,
            m.m33 * s
        );
    }

    [MethodImpl(MethodInlineOptions)]
    public static mat4 mul(float s, mat4 m)
    {
        return mat4(
            /* Row 1 */
            m.m00 * s, 
            m.m01 * s,
            m.m02 * s,
            m.m03 * s,

            /* Row 2*/
            m.m10 * s, 
            m.m11 * s,
            m.m12 * s,
            m.m13 * s,

            /* Row 3 */
            m.m20 * s, 
            m.m21 * s,
            m.m22 * s,
            m.m23 * s,

            /* Row 4 */
            m.m30 * s, 
            m.m31 * s,
            m.m32 * s,
            m.m33 * s
        );
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 mul(mat4 m, vec4 v)
    {
        vec4 c0 = vec4(m.m00, m.m10, m.m20, m.m30);
        vec4 c1 = vec4(m.m01, m.m11, m.m21, m.m31);
        vec4 c2 = vec4(m.m02, m.m12, m.m22, m.m32);
        vec4 c3 = vec4(m.m03, m.m13, m.m23, m.m33);

        float x = dot(c0, v);
        float y = dot(c1, v);
        float z = dot(c2, v);
        float w = dot(c3, v);

        return vec4(x, y, z, w);
    }

    [MethodImpl(MethodInlineOptions)]
    public static mat4 translate(float x, float y, float z = 0.0f)
    {
        return mat4(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            x, y, z, 1
        );
    }

    [MethodImpl(MethodInlineOptions)]
    public static mat4 scale(float x, float y, float z = 0.0f)
    {
        return mat4(
            x, 0, 0, 0,
            0, y, 0, 0,
            0, 0, z, 0,
            0, 0, 0, 1
        );
    }
    
    [MethodImpl(MethodInlineOptions)]
    public static mat4 translate(vec2 position)
    {
        return translate(position.x, position.y, 0);
    }

    [MethodImpl(MethodInlineOptions)]
    public static mat4 translate(vec3 position)
    {
        return translate(position.x, position.y, position.z);
    }
    
    [MethodImpl(MethodInlineOptions)]
    public static mat4 scale(vec2 scale)
    {
        return translate(scale.x, scale.y, 0);
    }
    
    [MethodImpl(MethodInlineOptions)]
    public static mat4 scale(vec3 scale)
    {
        return translate(scale.x, scale.y, scale.z);
    }
    
    [MethodImpl(MethodInlineOptions)]
    public static mat4 rotatex(float angle)
    {
        float c = (float)Math.Cos(angle);
        float s = (float)Math.Sin(angle);

        return mat4(
            1,  0, 0, 0,
            0,  c, s, 0,
            0, -s, c, 0,
            0,  0, 0, 1
        );
    }
    
    [MethodImpl(MethodInlineOptions)]
    public static mat4 rotatey(float angle)
    {
        float c = (float)Math.Cos(angle);
        float s = (float)Math.Sin(angle);

        return mat4(
             c, 0, s, 0,
             0, 1, 0, 0,
            -s, 0, c, 0,
             0, 0, 0, 1
        );
    }
    
    [MethodImpl(MethodInlineOptions)]
    public static mat4 rotatez(float angle)
    {
        float c = (float)Math.Cos(angle);
        float s = (float)Math.Sin(angle);

        return mat4(
             c, s, 0, 0,
            -s, c, 0, 0,
             0, 0, 1, 0,
             0, 0, 0, 1
        );
    }

    [MethodImpl(MethodInlineOptions)]
    public static mat4 rotate(float x, float y, float z, float angle)
    {
        float c = (float)Math.Cos(-angle);
        float s = (float)Math.Sin(-angle);
        float t = 1.0f - c;
    
        return mat4(
            /* Row 1 */
            t * x * x + c,
            t * x * y - s * z,
            t * x * z + s * y,
            0.0f,

            /* Row 2 */
            t * x * y + s * z,
            t * y * y + c,
            t * y * z - s * x,
            0.0f,

            /* Row 3 */
            t * x * z - s * y,
            t * y * z + s * x,
            t * z * z + c,
            0.0f,

            /* Row 4 */
            0, 0, 0, 1.0f
        );
    }

    [MethodImpl(MethodInlineOptions)]
    public static mat4 ortho(float l, float r, float b, float t, float n, float f)
    {
        float x = 1.0f / (r - l);
        float y = 1.0f / (t - b);
        float z = 1.0f / (f - n);

        return mat4(
                2.0f * x,            0,            0, 0,
                       0,     2.0f * y,            0, 0,
                       0,            0,     2.0f * z, 0,
            -x * (l + r), -y * (b + t), -z * (n + f), 1
        );
    }

    [MethodImpl(MethodInlineOptions)]
    public static mat4 perspective(float fov, float aspect, float near, float far)
    {
        float a = 1.0f / (float)Math.Tan(fov * 0.5f);
        float b = far / (near - far);

        return mat4(
            a / aspect, 0,        0,  0,
                     0, a,        0,  0,
                     0, 0,        b, -1,
                     0, 0, near * b,  0
        );
    }

    [MethodImpl(MethodInlineOptions)]
    public static mat4 lookat(vec3 eye, vec3 target, vec3 up)
    {
        vec3 z = normalize(sub(eye, target));
        vec3 x = normalize(cross(up, z));
        vec3 y = normalize(cross( z, x));

        return mat4(
            x.x, y.x, z.x, 0,
            x.y, y.y, z.y, 0,
            x.z, y.z, z.z, 0,
            /* row 4 */
            -dot(x, eye), 
            -dot(y, eye), 
            -dot(z, eye), 
            1.0f
        );
    }
    #endregion mat4...
    /* * */
}