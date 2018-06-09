// Learn more about F# at http://fsharp.org

open System
open vmath

[<EntryPoint>]
let main argv =
    printfn "Hello World from F#!"

    let v = neg(vec2(1.0, 2.0))

    printfn "%s" (v.ToString())
    
    0 // return an integer exit code
