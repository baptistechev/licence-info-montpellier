class cte n =
object
    val content = n
    method eval = content
    method print = print_int content;
end

class inv (f : inv) =
object
    val content = f
    method eval = - f#eval
    method print = print_string "-"; content#print; print_string ""
end

class add (f1 : add) (f2 : add) =
object
    val f1 = f1
    val f2 = f2
    method eval = f1#eval + f2#eval
    method print = print_string "("; f1#print; print_string " + "; f2#print; print_string ")"
end

class sub (f1 : sub) (f2 : sub) =
object
    val f1 = f1
    val f2 = f2
    method eval = f1#eval - f2#eval
    method print = print_string "("; f1#print; print_string " - "; f2#print; print_string ")"
end

class mul (f1 : mul) (f2 : mul) =
object
    val f1 = f1
    val f2 = f2
    method eval = f1#eval * f2#eval
    method print = print_string "("; f1#print; print_string " x "; f2#print; print_string ")"
end

class div (f1 : div) (f2 : div) =
object
    val f1 = f1
    val f2 = f2
    method eval = f1#eval / f2#eval
    method print = print_string "("; f1#print; print_string " / "; f2#print; print_string ")"
end

let e = new inv (new mul (new add (new cte 1) (new cte 2)) (new inv (new cte 3)));;
e#print;;