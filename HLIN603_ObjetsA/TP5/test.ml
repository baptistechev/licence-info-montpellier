class ['a] cell (n : 'a)  =
object
    val mutable content = n
    method get = content
    method set n = content <- n
end

class account b =
object (self)
    val mutable balance = 0.0
    method get = balance
    method deposit x = balance <- balance +. x
    method withdraw x = balance <- balance -. x
    method print = print_float balance; print_newline ()
    initializer self#deposit b
end

class interest_account b =
object
    inherit account b (*as super*)
    method interest = balance <- balance +. 5. *. balance /. 100.
end