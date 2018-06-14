#if UNITY_WII || UNITY_ANDROID || UNITY_WEBGL || UNITY_STANDALONE
#define VMATH_UNITY
#endif

#if UNITY_IOS || UNITY_XBOXONE || UNITY_TIZEN || UNITY_TVOS || UNITY_PS4 || UNITY_WSA
#define VMATH_UNITY
#endif

module vmath

open Microsoft.FSharp.Core;

type vec2 =
    struct
        val x : float32
        val y : float32
        
        new (s : float32) =
            vec2(s, s)

        new (x : float32, y : float32) = { x = x; y = y }
    end

    static member inline neg (v : vec2) : vec2 =
        vec2(-v.x, -v.y)

    static member inline add (a : vec2, b : vec2) : vec2 =
        vec2(a.x + b.x, a.y + b.y)

    static member inline add (a : vec2, b) : vec2 =
        vec2(a.x + b, a.y + b)

    static member inline add (a, b : vec2) : vec2 =
        vec2(a + b.x, a + b.y)

    static member inline sub (a : vec2, b : vec2) : vec2 = 
        vec2(a.x - b.x, a.y - b.y)

    static member inline sub (a : vec2, b) : vec2 = 
        vec2(a.x - b, a.y - b)

    static member inline sub (a, b : vec2) : vec2 = 
        vec2(a - b.x, a - b.y)

    static member inline mul (a : vec2, b : vec2) : vec2 =
        vec2(a.x * b.x, a.y * b.y)

    static member inline mul (a : vec2, b) : vec2 =
        vec2(a.x * b, a.y * b)
        
    static member inline mul (a, b : vec2) : vec2 =
        vec2(a * b.x, a * b.y)

    static member inline div (a : vec2, b : vec2) : vec2 = 
        vec2(a.x / b.x, a.y / b.y)

    static member inline div (a : vec2, b) : vec2 = 
        vec2(a.x / b, a.y / b)

    static member inline div (a, b : vec2) : vec2 = 
        vec2(a / b.x, a / b.y)

    static member inline dot (a : vec2, b : vec2) =
        a.x * b.x + a.y * b.y

    static member inline lengthsquared (v : vec2) =
        vec2.dot(v, v)

    static member inline length (v : vec2) =
        sqrt(vec2.lengthsquared(v))

    static member inline distance (a : vec2, b : vec2) =
        vec2.length(vec2.sub(a, b))

    static member inline distancesquared (a : vec2, b : vec2) =
        vec2.lengthsquared(vec2.sub(a, b))

    static member inline reflect (v : vec2, n : vec2) : vec2 =
        vec2.sub(v, vec2.mul(n, 2.0f * vec2.dot(v, n)))

    static member inline normalize (v : vec2) : vec2 =
        let lsqr = vec2.lengthsquared(v)
        match lsqr with
        | 0.0f | 1.0f -> v
        | _           ->
            let l = 1.0f / sqrt(lsqr)
            vec2(v.x * l, v.y * l)
       
    override this.ToString() : string = 
        "vec2(" + this.x.ToString() + ", " + this.y.ToString() + ")"

type vec3 =
    struct
        val x : float32
        val y : float32
        val z : float32

        new (s : float32) =
            vec3(s, s, s)

        new (x : float32, y : float32, ?z : float32) = { x = x; y = y; z = defaultArg z 0.0f;}

        new (xy : vec2, ?z : float32) = { x = xy.x; y = xy.y; z = defaultArg z 0.0f };
    end

    static member inline neg (v : vec3) : vec3 =
        vec3(-v.x, -v.y, -v.z)
        
    static member inline add (a : vec3, b : vec3) : vec3 =
        vec3(a.x + b.x, a.y + b.y, a.z + b.z)

    static member inline add (a : vec3, b) : vec3 =
        vec3(a.x + b, a.y + b, a.z + b)

    static member inline add (a, b : vec3) : vec3 =
        vec3(a + b.x, a + b.y, a + b.z)

    static member inline sub (a : vec3, b : vec3) : vec3 = 
        vec3(a.x - b.x, a.y - b.y, a.z - b.z)

    static member inline sub (a : vec3, b) : vec3 = 
        vec3(a.x - b, a.y - b, a.z - b)

    static member inline sub (a, b : vec3) : vec3 = 
        vec3(a - b.x, a - b.y, a - b.z)

    static member inline mul (a : vec3, b : vec3) : vec3 =
        vec3(a.x * b.x, a.y * b.y, a.z * b.z)

    static member inline mul (a : vec3, b) : vec3 =
        vec3(a.x * b, a.y * b, a.z * b)
        
    static member inline mul (a, b : vec3) : vec3 =
        vec3(a * b.x, a * b.y, a * b.z)

    static member inline div (a : vec3, b : vec3) : vec3 = 
        vec3(a.x / b.x, a.y / b.y, a.z / b.z)

    static member inline div (a : vec3, b) : vec3 = 
        vec3(a.x / b, a.y / b, a.z / b)

    static member inline div (a, b : vec3) : vec3 = 
        vec3(a / b.x, a / b.y, a / b.z)

    static member inline dot (a : vec3, b : vec3) =
        a.x * b.x + a.y * b.y + a.z * b.z

    static member inline lengthsquared (v : vec3) =
        vec3.dot(v, v)

    static member inline length (v : vec3) =
        sqrt(vec3.lengthsquared(v))

    static member inline distance (a : vec3, b : vec3) =
        vec3.length(vec3.sub(a, b))

    static member inline distancesquared (a : vec3, b : vec3) =
        vec3.lengthsquared(vec3.sub(a, b))

    static member inline reflect (v : vec3, n : vec3) : vec3 =
        vec3.sub(v, vec3.mul(n, 2.0f * vec3.dot(v, n)))

    static member inline normalize (v : vec3) : vec3 =
        let lsqr = vec3.lengthsquared(v)
        match lsqr with
        | 0.0f | 1.0f -> v
        | _           ->
            let l = 1.0f / sqrt(lsqr)
            vec3(v.x * l, v.y * l, v.z * l)

    static member inline cross (a : vec3, b : vec3) : vec3 =
        vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x) 

    override this.ToString() : string = 
        "vec3(" + this.x.ToString() + ", " + this.y.ToString() + ", " + this.z.ToString() + ")"

type vec4 =
    struct
        val x : float32
        val y : float32
        val z : float32
        val w : float32

        new (s : float32) =
            vec4(s, s, s, s)

        new (x : float32, y : float32, z : float32, w : float32) =
            { x = x; y = y; z = z; w = w; }

        new (xy : vec2, zw : vec2) =
            { x = xy.x; y = xy.y; z = zw.x; w = zw.y; }

        new (xy : vec2, ?z : float32, ?w : float32) =
            { x = xy.x; y = xy.y; z = defaultArg z 0.0f; w = defaultArg w 0.0f; }

        new (xyz : vec3, ?w : float32) =
            vec4 (xyz.x, xyz.y, xyz.z, defaultArg w 0.0f)
    end

    static member inline neg (v : vec4) : vec4 = 
        vec4(-v.x, -v.y, -v.z, -v.w)
        
    static member inline add (a : vec4, b : vec4) : vec4 =
        vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w)

    static member inline add (a : vec4, b) : vec4 =
        vec4(a.x + b, a.y + b, a.y + b, a.w + b)

    static member inline add (a, b : vec4) : vec4 =
        vec4(a + b.x, a + b.y, a + b.z, a + b.w)

    static member inline sub (a : vec4, b : vec4) : vec4 = 
        vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w)

    static member inline sub (a : vec4, b) : vec4 = 
        vec4(a.x - b, a.y - b, a.z - b, a.w - b)

    static member inline sub (a, b : vec4) : vec4 = 
        vec4(a - b.x, a - b.y, a - b.z, a - b.w)

    static member inline mul (a : vec4, b : vec4) : vec4 =
        vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w)

    static member inline mul (a : vec4, b) : vec4 =
        vec4(a.x * b, a.y * b, a.z * b, a.w * b)
        
    static member inline mul (a, b : vec4) : vec4 =
        vec4(a * b.x, a * b.y, a * b.z, a * b.w)

    static member inline div (a : vec4, b : vec4) : vec4 = 
        vec4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w)

    static member inline div (a : vec4, b) : vec4 = 
        vec4(a.x / b, a.y / b, a.z / b, a.w / b)

    static member inline div (a, b : vec4) : vec4 = 
        vec4(a / b.x, a / b.y, a / b.z, a / b.w)

    static member inline dot (a : vec4, b : vec4) =
        a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w

    static member inline lengthsquared (v : vec4) =
        vec4.dot(v, v)

    static member inline length (v : vec4) =
        sqrt(vec4.lengthsquared(v))

    static member inline distance (a : vec4, b : vec4) =
        vec4.length(vec4.sub(a, b))

    static member inline distancesquared (a : vec4, b : vec4) =
        vec4.lengthsquared(vec4.sub(a, b))

    static member inline reflect (v : vec4, n : vec4) : vec4 =
        vec4.sub(v, vec4.mul(n, 2.0f * vec4.dot(v, n)))

    static member inline normalize (v : vec4) : vec4 =
        let lsqr = vec4.lengthsquared(v)
        match lsqr with
        | 0.0f | 1.0f -> v
        | _           ->
            let l = 1.0f / sqrt(lsqr)
            vec4(v.x * l, v.y * l, v.z * l, v.w * l)

    override this.ToString() : string = 
        "vec4(" + this.x.ToString() + ", " + this.y.ToString() + ", " + this.z.ToString() + ", " + this.w.ToString() + ")"

type quat =
    struct
        val x : float32
        val y : float32
        val z : float32
        val w : float32

        new (v : vec4) =
            quat(v.x, v.y, v.z, v.w)

        new (s : float32) =
            quat(s, s, s, s)

        new (x : float32, y : float32, z : float32, w : float32) =
            { x = x; y = y; z = z; w = w; }
    end

    static member inline neg (v : quat) : quat = 
        quat(-v.x, -v.y, -v.z, -v.w)
        
    static member inline add (a : quat, b : quat) : quat =
        quat(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w)

    static member inline add (a : quat, b) : quat =
        quat(a.x + b, a.y + b, a.y + b, a.w + b)

    static member inline add (a, b : quat) : quat =
        quat(a + b.x, a + b.y, a + b.z, a + b.w)

    static member inline sub (a : quat, b : quat) : quat = 
        quat(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w)

    static member inline sub (a : quat, b) : quat = 
        quat(a.x - b, a.y - b, a.z - b, a.w - b)

    static member inline sub (a, b : quat) : quat = 
        quat(a - b.x, a - b.y, a - b.z, a - b.w)

    static member inline mul (a : quat, b) : quat =
        quat(a.x * b, a.y * b, a.z * b, a.w * b)
        
    static member inline mul (a, b : quat) : quat =
        quat(a * b.x, a * b.y, a * b.z, a * b.w)

    static member inline div (a : quat, b) : quat = 
        quat(a.x / b, a.y / b, a.z / b, a.w / b)

    static member inline div (a, b : quat) : quat = 
        quat(a / b.x, a / b.y, a / b.z, a / b.w)

    static member inline mul (a : quat, b : quat) : quat =
        quat(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w)

    static member inline normalize (v : quat) : quat =
        let lsqr = v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w
        match lsqr with
        | 0.0f | 1.0f -> v
        | _           ->
            let l = 1.0f / sqrt(lsqr)
            quat(v.x * l, v.y * l, v.z * l, v.w * l)

    override this.ToString() : string = 
        "quat(" + this.x.ToString() + ", " + this.y.ToString() + ", " + this.z.ToString() + ", " + this.w.ToString() + ")"

let inline neg x            = (^T : (static member neg : ^T -> ^T) (x))
let inline add a b          = (^T : (static member add : ^T -> ^U -> ^V) (a, b))
let inline sub a b          = (^T : (static member sub : ^T -> ^U -> ^V) (a, b))
let inline mul a b          = (^T : (static member mul : ^T -> ^U -> ^V) (a, b))
let inline div a b          = (^T : (static member div : ^T -> ^U -> ^V) (a, b))
let inline dot a b          = (^T : (static member dot : ^T -> ^U -> float32) (a, b))
let inline length v         = (^T : (static member length          : ^T -> float32) (v))
let inline lengthsquared v  = (^T : (static member lengthsquared   : ^T -> float32) (v))
let inline distance v       = (^T : (static member distance        : ^T -> float32) (v))
let inline distancesquare v = (^T : (static member distancesquared : ^T -> float32) (v))

let inline reflect v n      = (^T : (static member reflect         : ^T -> ^T -> ^T) (v, n))
let inline normalize v      = (^T : (static member normalize       : ^T -> ^T) (v))

let inline cross (a : vec3, b : vec3) = vec3.cross(a, b)

let inline (~-) a   = (^T : (static member neg : ^T -> ^U) (a))
let inline (+)  a b = (^T : (static member add : ^T -> ^U -> ^V) (a, b))
let inline (-)  a b = (^T : (static member sub : ^T -> ^U -> ^V) (a, b))
let inline (*)  a b = (^T : (static member mul : ^T -> ^U -> ^V) (a, b))
let inline (/)  a b = (^T : (static member div : ^T -> ^U -> ^V) (a, b))