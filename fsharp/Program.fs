// Learn more about F# at http://fsharp.org

open System
open vmath

[<EntryPoint>]
let main argv =
    printfn "Hello World from F#!"

    let a = vec2(1.0f, 2.0f)
    let v = a + 1.0f

    printfn "%s" (v.ToString())
    
    0 // return an integer exit code
