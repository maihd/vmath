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
        public float m10;
        public float m11;

        public DebuggerProxy(mat3 m)
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
    #endregion Constructors

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
    #endregion vec2 functions
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
    #endregion vec3 functions
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
    #endregion vec4 functions
    /* * */

    #region mat2 functions

    #endregion mat2 functions
    /* * */

    #region mat3 functions

    #endregion mat3 functions
    /* * */

    #region mat4 functions

    #endregion mat4 functions
    /* * */
}