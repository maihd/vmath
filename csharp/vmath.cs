#if UNITY_WII || UNITY_ANDROID || UNITY_WEBGL || UNITY_STANDALONE
#define VMATH_UNITY
#endif

#if UNITY_IOS || UNITY_XBOXONE || UNITY_TIZEN || UNITY_TVOS || UNITY_PS4 || UNITY_WSA
#define VMATH_UNITY
#endif

using System;
using System.Diagnostics;
using System.Runtime.CompilerServices;

public static class vmath
{
    const MethodImplOptions MethodInlineOptions = (MethodImplOptions)0x100;

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

        [MethodImpl(MethodInlineOptions)]
        public vec2(float x, float y)
        {
            this.x = x;
            this.y = y;
        }

        [MethodImpl(MethodInlineOptions)]
        public vec2(float s)
        {
            x = y = s;
        }

        [MethodImpl(MethodInlineOptions)]
        public bool Equals(vec2 other)
        {
            return x == other.x && y == other.y;
        }

        [MethodImpl(MethodInlineOptions)]
        public override bool Equals(object obj)
        {
            if (obj == null || GetType() != obj.GetType())
            {
                return false;
            }
            
            return Equals((vec2)obj);
        }
        
        [MethodImpl(MethodInlineOptions)]
        public override int GetHashCode()
        {
            return (x.GetHashCode()) ^ (y.GetHashCode());
        }

        #region Operators
        [MethodImpl(MethodInlineOptions)]
        public static vec2 operator+(vec2 a, vec2 b)
        {
            return add(a, b);
        }

        [MethodImpl(MethodInlineOptions)]
        public static vec2 operator-(vec2 a, vec2 b)
        {
            return sub(a, b);
        }

        [MethodImpl(MethodInlineOptions)]
        public static vec2 operator*(vec2 a, vec2 b)
        {
            return mul(a, b);
        }

        [MethodImpl(MethodInlineOptions)]
        public static vec2 operator/(vec2 a, vec2 b)
        {
            return div(a, b);
        }

        [MethodImpl(MethodInlineOptions)]
        public static vec2 operator+(vec2 v, float s)
        {
            return add(v, s);
        }

        [MethodImpl(MethodInlineOptions)]
        public static vec2 operator-(vec2 v, float s)
        {
            return sub(v, s);
        }

        [MethodImpl(MethodInlineOptions)]
        public static vec2 operator*(vec2 v, float s)
        {
            return mul(v, s);
        }

        [MethodImpl(MethodInlineOptions)]
        public static vec2 operator/(vec2 v, float s)
        {
            return div(v, s);
        }

        [MethodImpl(MethodInlineOptions)]
        public static bool operator==(vec2 a, vec2 b)
        {
            return a.Equals(b);
        }

        [MethodImpl(MethodInlineOptions)]
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

        [MethodImpl(MethodInlineOptions)]
        public vec3(float x, float y, float z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        [MethodImpl(MethodInlineOptions)]
        public vec3(float s)
        {
            x = y = z = s;
        }

        [MethodImpl(MethodInlineOptions)]
        public bool Equals(vec3 other)
        {
            return x == other.x && y == other.y && z == other.z;
        }

        [MethodImpl(MethodInlineOptions)]
        public override bool Equals(object obj)
        {
            if (obj == null || GetType() != obj.GetType())
            {
                return false;
            }
            
            return Equals((vec3)obj);
        }
        
        [MethodImpl(MethodInlineOptions)]
        public override int GetHashCode()
        {
            return (x.GetHashCode()) ^ (y.GetHashCode());
        }

        #region Operators
        [MethodImpl(MethodInlineOptions)]
        public static vec3 operator+(vec3 a, vec3 b)
        {
            return add(a, b);
        }

        [MethodImpl(MethodInlineOptions)]
        public static vec3 operator-(vec3 a, vec3 b)
        {
            return sub(a, b);
        }

        [MethodImpl(MethodInlineOptions)]
        public static vec3 operator*(vec3 a, vec3 b)
        {
            return mul(a, b);
        }

        [MethodImpl(MethodInlineOptions)]
        public static vec3 operator/(vec3 a, vec3 b)
        {
            return div(a, b);
        }

        [MethodImpl(MethodInlineOptions)]
        public static vec3 operator+(vec3 v, float s)
        {
            return add(v, s);
        }

        [MethodImpl(MethodInlineOptions)]
        public static bool operator==(vec3 a, vec3 b)
        {
            return a.Equals(b);
        }

        [MethodImpl(MethodInlineOptions)]
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

        [MethodImpl(MethodInlineOptions)]
        public vec4(float x, float y, float z, float w)
        {
            this.x = x;
            this.y = y;
            this.z = z;
            this.w = w;
        }

        [MethodImpl(MethodInlineOptions)]
        public vec4(float s)
        {
            x = y = z = w = s;
        }
        
        [MethodImpl(MethodInlineOptions)]
        public bool Equals(vec4 other)
        {
            return x == other.x && y == other.y && z == other.z && w == other.w;
        }

        [MethodImpl(MethodInlineOptions)]
        public override bool Equals(object obj)
        {
            if (obj == null || GetType() != obj.GetType())
            {
                return false;
            }
            
            return Equals((vec2)obj);
        }
        
        [MethodImpl(MethodInlineOptions)]
        public override int GetHashCode()
        {
            return (x.GetHashCode()) ^ (y.GetHashCode());
        }

        #region Operators
        [MethodImpl(MethodInlineOptions)]
        public static vec4 operator+(vec4 a, vec4 b)
        {
            return add(a, b);
        }

        [MethodImpl(MethodInlineOptions)]
        public static vec4 operator-(vec4 a, vec4 b)
        {
            return sub(a, b);
        }

        [MethodImpl(MethodInlineOptions)]
        public static vec4 operator*(vec4 a, vec4 b)
        {
            return mul(a, b);
        }

        [MethodImpl(MethodInlineOptions)]
        public static vec4 operator/(vec4 a, vec4 b)
        {
            return div(a, b);
        }

        [MethodImpl(MethodInlineOptions)]
        public static vec4 operator+(vec4 v, float s)
        {
            return add(v, s);
        }

        [MethodImpl(MethodInlineOptions)]
        public static bool operator==(vec4 a, vec4 b)
        {
            return a.Equals(b);
        }

        [MethodImpl(MethodInlineOptions)]
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

        [MethodImpl(MethodInlineOptions)]
        public mat2(float m00, float m01, float m10, float m11)
        {
            this.m00 = m00;
            this.m01 = m01;
            this.m10 = m10;
            this.m11 = m11;
        }

        [MethodImpl(MethodInlineOptions)]
        public mat2(float s)
        {
            m00 = m01 = m10 = m11 = s;
        }

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

    #region vec2 functions
    [MethodImpl(MethodInlineOptions)]
    public static vec2 add(vec2 a, vec2 b)
    {
        return new vec2(a.x + b.x, a.y + b.y);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 sub(vec2 a, vec2 b)
    {
        return new vec2(a.x - b.x, a.y - b.y);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 mul(vec2 a, vec2 b)
    {
        return new vec2(a.x * b.x, a.y * b.y);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 div(vec2 a, vec2 b)
    {
        return new vec2(a.x / b.x, a.y / b.y);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 add(vec2 v, float s)
    {
        return add(v, new vec2(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 add(float s, vec2 v)
    {
        return add(v, new vec2(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 sub(vec2 v, float s)
    {
        return add(v, new vec2(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 mul(vec2 v, float s)
    {
        return mul(v, new vec2(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 mul(float s, vec2 v)
    {
        return mul(v, new vec2(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 div(vec2 v, float s)
    {
        return div(v, new vec2(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 neg(vec2 v)
    {  
        return new vec2(-v.x, -v.y);
    }

    [MethodImpl(MethodInlineOptions)]
    public static float dot(vec2 a, vec2 b)
    {
        return a.x * b.x + a.y * b.y;
    }

    [MethodImpl(MethodInlineOptions)]
    public static float lensqr(vec2 v)
    {
        return dot(v, v);
    }

    [MethodImpl(MethodInlineOptions)]
    public static float len(vec2 v)
    {
        return (float)Math.Sqrt(lensqr(v));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec2 reflect(vec2 v, vec2 n)
    {
        return sub(v, mul(n, 2.0f * dot(v, n)));
    }
    #endregion vec2 functions
    /* * */

    #region vec3 functions
    [MethodImpl(MethodInlineOptions)]
    public static vec3 add(vec3 a, vec3 b)
    {
        return new vec3(a.x + b.x, a.y + b.y, a.z + b.z);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 sub(vec3 a, vec3 b)
    {
        return new vec3(a.x - b.x, a.y - b.y, a.z - b.z);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 mul(vec3 a, vec3 b)
    {
        return new vec3(a.x * b.x, a.y * b.y, a.z * b.z);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 div(vec3 a, vec3 b)
    {
        return new vec3(a.x / b.x, a.y / b.y, a.z / b.z);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 add(vec3 v, float s)
    {
        return add(v, new vec3(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 add(float s, vec3 v)
    {
        return add(v, new vec3(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 sub(vec3 v, float s)
    {
        return add(v, new vec3(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 mul(vec3 v, float s)
    {
        return mul(v, new vec3(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 mul(float s, vec3 v)
    {
        return mul(v, new vec3(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 div(vec3 v, float s)
    {
        return div(v, new vec3(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 neg(vec3 v)
    {  
        return new vec3(-v.x, -v.y, -v.z);
    }

    [MethodImpl(MethodInlineOptions)]
    public static float dot(vec3 a, vec3 b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    [MethodImpl(MethodInlineOptions)]
    public static float lensqr(vec3 v)
    {
        return dot(v, v);
    }

    [MethodImpl(MethodInlineOptions)]
    public static float len(vec3 v)
    {
        return (float)Math.Sqrt(lensqr(v));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec3 reflect(vec3 v, vec3 n)
    {
        return sub(v, mul(n, 2.0f * dot(v, n)));
    }
    #endregion vec3 functions
    /* * */

    #region vec4 functions

    [MethodImpl(MethodInlineOptions)]
    public static vec4 add(vec4 a, vec4 b)
    {
        return new vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 sub(vec4 a, vec4 b)
    {
        return new vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 mul(vec4 a, vec4 b)
    {
        return new vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 div(vec4 a, vec4 b)
    {
        return new vec4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 add(vec4 v, float s)
    {
        return add(v, new vec4(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 sub(vec4 v, float s)
    {
        return add(v, new vec4(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 mul(vec4 v, float s)
    {
        return mul(v, new vec4(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 div(vec4 v, float s)
    {
        return div(v, new vec4(s));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 neg(vec4 v)
    {  
        return new vec4(-v.x, -v.y, -v.z, -v.w);
    }

    [MethodImpl(MethodInlineOptions)]
    public static float dot(vec4 a, vec4 b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    [MethodImpl(MethodInlineOptions)]
    public static float lensqr(vec4 v)
    {
        return dot(v, v);
    }

    [MethodImpl(MethodInlineOptions)]
    public static float len(vec4 v)
    {
        return (float)Math.Sqrt(lensqr(v));
    }

    [MethodImpl(MethodInlineOptions)]
    public static vec4 reflect(vec4 v, vec4 n)
    {
        return sub(v, mul(n, 2.0f * dot(v, n)));
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