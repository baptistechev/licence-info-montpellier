let rec size l =
match l with
| [] -> 0
| e :: tl -> 1 + (size tl);;

let rec inv l =
match l with
| [] -> []
| t :: r -> (inv r) @ [t];;

let rec occ x l =
match l with
| [] -> 0
| e :: tl ->  (if e=x then 1 else 0) + (occ x tl);;

let rec estTriee = function
| [] | [_] -> true
| e1 :: e2 :: tl -> (e1 <= e2) && (estTriee (e2 :: tl));;

let rec insertionTriee x = function
| [] -> [x]
| e :: tl -> if e>=x then x :: e :: tl else e :: (insertionTriee x tl);;

let rec trier = function
| [] -> []
| e :: tl -> insertionTriee e (trier tl);;

let liste = [4; 1; 3; 2; 5];;
size liste;;
inv liste;;
occ 1 liste;;
estTriee liste;;
insertionTriee 2 liste;;
trier liste;;



Sys.command "clear";;