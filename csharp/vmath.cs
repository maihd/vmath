using System;
using System.Diagnostics;
using System.Runtime.CompilerServices;

public static class vmath
{
    [System.Serializable]
    [DebuggerTypeProxy(typeof(vec2.DebuggerProxy))]
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

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public vec2(float x, float y)
        {
            this.x = x;
            this.y = y;
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public vec2(float s)
        {
            x = y = s;
        }

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
    [DebuggerTypeProxy(typeof(vec3.DebuggerProxy))]
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

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public vec3(float x, float y, float z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public vec3(float s)
        {
            x = y = z = s;
        }

        #region ToString
        public override string ToString()
        {
            return string.Format("vec2({0:R}, {1:R}, {2:R})", x, y, z);
        }

        public string ToString(string format, IFormatProvider formatProvider)
        {
            return string.Format(format, x.ToString(format, formatProvider), y.ToString(format, formatProvider), z.ToString(format, formatProvider));
        }
        #endregion
    }

    [System.Serializable]
    [DebuggerTypeProxy(typeof(vec4.DebuggerProxy))]
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

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public vec4(float x, float y, float z, float w)
        {
            this.x = x;
            this.y = y;
            this.z = z;
            this.w = w;
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public vec4(float s)
        {
            x = y = z = w = s;
        }

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
    [DebuggerTypeProxy(typeof(mat2.DebuggerProxy))]
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

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public mat2(float m00, float m01, float m10, float m11)
        {
            this.m00 = m00;
            this.m01 = m01;
            this.m10 = m10;
            this.m11 = m11;
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
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
    [DebuggerTypeProxy(typeof(mat3.DebuggerProxy))]
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
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static vec2 add(vec2 a, vec2 b)
    {
        return new vec2(a.x + b.x, a.y + b.y);
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static vec2 sub(vec2 a, vec2 b)
    {
        return new vec2(a.x - b.x, a.y - b.y);
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static vec2 mul(vec2 a, vec2 b)
    {
        return new vec2(a.x * b.x, a.y * b.y);
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static vec2 div(vec2 a, vec2 b)
    {
        return new vec2(a.x / b.x, a.y / b.y);
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static vec2 add(vec2 v, float s)
    {
        return add(v, new vec2(s));
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static vec2 add(float s, vec2 v)
    {
        return add(v, new vec2(s));
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static vec2 sub(vec2 v, float s)
    {
        return add(v, new vec2(s));
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static vec2 mul(vec2 v, float s)
    {
        return mul(v, new vec2(s));
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static vec2 mul(float s, vec2 v)
    {
        return mul(v, new vec2(s));
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static vec2 div(vec2 v, float s)
    {
        return div(v, new vec2(s));
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static vec2 neg(vec2 v)
    {  
        return new vec2(-v.x, -v.y);
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static bool eql(vec2 a, vec2 b)
    {
        return a.x == b.x && a.y == b.y;
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static float dot(vec2 a, vec2 b)
    {
        return a.x * b.x + a.y * b.y;
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static float lensqr(vec2 v)
    {
        return dot(v, v);
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static float len(vec2 v)
    {
        return (float)Math.Sqrt(lensqr(v));
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static vec2 reflect(vec2 v, vec2 n)
    {
        return sub(v, mul(n, 2.0f * dot(v, n)));
    }
    #endregion vec2 functions
    /* * */

    #region vec3 functions

    #endregion vec3 functions
    /* * */

    #region vec4 functions

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