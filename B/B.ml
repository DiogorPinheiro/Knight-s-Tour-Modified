open Printf
open Scanf
open Array

let n = scanf " %d" (fun n -> n)
let x_init,y_init = scanf " %d %d" (fun x_init y_init -> x_init, y_init)
let peoes = scanf " %d" (fun peoes -> peoes)

let saltos = ref 2
let xp = [|-2; -2; -1; -1;  1; 1;  2; 2 |]
let yp = [|-1;  1; -2;  2; -2; 2; -1; 1 |]
let possivel = (n * n) - peoes
let matriz = Array.make_matrix n n 0 
let () = matriz.(x_init).(y_init) <- 1 
let () =
    if peoes <> 0 then
    for i = 0 to peoes do
        let x,y = scanf " %d %d" (fun x y -> x, y) in
        let () = matriz.(x).(y) <- -1 in ()
    done
 

let validarSalto x y n matriz =
    if (x >= 0) && (x < n) && (y >= 0) && (y < n) && (matriz.(x).(y) = 0) then true else false

let validarPosicao x y n matriz =
    if (x >= 0) && (x < n) && (y >= 0) && (y < n) then true else false
(*
let saltosPossiveis  x y n matriz xp yp =
    let cont = ref 0 in
    let () = for j = 0 to 8 do
                let next_x = x + xp.(j) in 
                let next_y = y + yp.(j) in
                if (validarSalto next_x next_y n matriz) then (cont := (!cont +1)) else (cont := (!cont +0)) 
           
             done in
    !cont
*)

let rec resultado x y n saltos matriz possivel xp yp =


    let rec newFor cont x y n saltos matrix possivel xp yp =    
        if(cont < 8) then 
            
            let next_x = x + xp.(cont) in
            let next_y = y + yp.(cont) in

            if ( validarSalto next_x next_y n matriz) then 
                let () = matriz.(next_x).(next_y) <- saltos in
                if ( resultado next_x next_y n (saltos+1) matriz possivel xp yp ) then
                    true
                else
                    let () = matriz.(next_x).(next_y) <- 0 in
                    newFor (cont+1) x y n saltos matriz possivel xp yp

            else newFor (cont+1) x y n saltos matriz possivel xp yp

        else false
        

    in

    if ( validarPosicao x y n matriz ) then

        if (saltos = possivel) then 
            
            true 

        else

            newFor 0 x y n saltos matriz possivel xp yp

    else false

let () =         
        if ( resultado x_init y_init n !saltos matriz possivel xp yp ) = true then
            let () = Printf.printf "YES" in ()
        else
            let () = Printf.printf "NO" in () 