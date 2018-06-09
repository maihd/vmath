module vmath

type vec2(x : float, y : float) =
    member this.x = x
    member this.y = y

    static member inline neg (v : vec2) : vec2 =
        vec2(-v.x, -v.y)

    static member inline add (a : vec2, b : vec2) : vec2 =
        vec2(a.x + b.x, a.y + b.y)

    static member inline sub (a : vec2, b : vec2) : vec2 = 
        vec2(a.x - b.x, a.y - b.y)

    static member inline mul (a : vec2, b : vec2) : vec2 =
        vec2(a.x * b.x, a.y * b.y)

    static member inline mul (a : vec2, b : float) : vec2 =
        vec2(a.x * b, a.y * b)
        
    static member inline mul (a : float, b : vec2) : vec2 =
        vec2(a * b.x, a * b.y)

    static member inline div (a : vec2, b : vec2) : vec2 = 
        vec2(a.x / b.x, a.y / b.y)

    static member inline dot (a : vec2, b : vec2) : float =
        a.x * b.x + a.y * b.y

    static member inline lensqr (v : vec2) : float =
        vec2.dot(v, v)

    static member inline len (v : vec2) : float =
        sqrt(vec2.lensqr(v))

    static member inline angle (v : vec2) : float =
        atan2(v.y, v.x)

    static member inline reflect (v : vec2, n : vec2) : vec2 =
        vec2.sub(v, vec2.mul(n, 2.0 * vec2.dot(v, n)))

    override this.ToString() : string = 
        "vec2(" + this.x.ToString() + ", " + this.y.ToString() + ")"

type vec3(x : float, y : float, z : float) =
    member this.x = x
    member this.y = y
    member this.z = z

    static member inline neg (v : vec3) : vec3 =
        vec3(-v.x, -v.y)

    override this.ToString() : string = 
        "vec3(" + this.x.ToString() + ", " + this.y.ToString() + ", " this.z.ToString() + ")"

type vec4(x : float, y : float, z : float, w : float) =
    member this.x = x
    member this.y = y
    member this.z = z
    member this.w = w

    static member inline neg (v : vec4) : vec4 = 
        vec4(-v.x, -v.y, -v.z, -v.w)

    override this.ToString() : string = 
        "vec4(" + this.x.ToString() + ", " + this.y.ToString() + ", " this.z.ToString() + ", " + this.w.ToString() + ")"

let inline neg x   = (^Type : (static member neg : ^Type -> ^Type) (x))
let inline add a b = (^Type : (static member add : ^Type -> ^Type -> ^Type) (a, b))