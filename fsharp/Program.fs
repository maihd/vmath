// Learn more about F# at http://fsharp.org

open System
open vmath

let print a = 
    printfn "%s" (a.ToString())

module test =
    let vec2 =
        let a = vec2(1.0f, 2.0f)
        let v = a + 1.0f

        let f = a |> add


        print v

        ()

    let vec3 = 
        ()
    
    let vec4 =
        ()

    let quat =
        ()

    let all =
        vec2
        vec3
        vec4
        quat

[<EntryPoint>]
let main argv =
    printfn "Hello World from F#!"
    
    test.all

    0 // return an integer exit code
