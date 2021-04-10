type form =
| Top | Bot
| Var of string
| Not of form
| And of form * form
| Or of form * form
| Imp of form * form
| Eq of form * form
;;

let f1 = Top;;
let f2 = Var "A";;
let f3 = And (Var "A", Var "B");;
let f4 = And (Var "A", Bot);;
let f5 = Or (And (Var "A", Top),(And (Bot, Var "B")));;

let rec print_form = function
| Top -> print_string "T"
| Bot -> print_string "F"
| Var s -> print_string s
| Not f -> print_string "("; print_string "¬"; print_form f; print_string ")"
| And (f1, f2) -> print_string "("; print_form f1; print_string " ^ "; print_form f2; print_string ")"
| Or (f1, f2) -> print_string "("; print_form f1; print_string " v "; print_form f2; print_string ")"
| Imp (f1, f2) -> print_string "("; print_form f1; print_string " => "; print_form f2; print_string ")"
| Eq (f1, f2) -> print_string "("; print_form f1; print_string " <=> "; print_form f2; print_string ")";;

let simplif_and = function
| And (f, Top) | And (Top, f) -> f
| And (f, Bot) | And (Bot, f) -> Bot
| f -> f;;

let simplif_or = function
| Or (f, Top) | Or (Top, f) -> Top
| Or (f, Bot) | Or (Bot, f) -> f
| f -> f;;

let simplif_imp = function
| Imp (f, Top) -> Top
| Imp (f, Bot) -> Not f
| Imp (Top, f) -> f
| Imp (Bot, f) -> Top
| f -> f;;

let simplif_eq = function
| Eq (f, Top) -> f
| Eq (f, Bot) -> Not f
| f -> f;;

let rec simplif_form = function
| And (f1, f2) -> simplif_and (And (simplif_form f1, simplif_form f2))
| Or (f1, f2) -> simplif_or (Or (simplif_form f1, simplif_form f2))
| Imp (f1, f2) -> simplif_imp (Imp (simplif_form f1, simplif_form f2))
| Eq (f1, f2) -> simplif_eq (Eq (simplif_form f1, simplif_form f2))
| Not f -> simplif_form f
| f -> f;;

Sys.command "clear";;