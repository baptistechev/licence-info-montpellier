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

class secure_account b =
object
    inherit account b as super
    method withdraw x = if (balance -. x) >= 0. 
                        then super#withdraw x
                        else failwith "Not enough money !"
end 

class bank =
object
    val mutable account_list = []
    method add (a : account) = account_list <- a :: account_list
    method balance = List.fold_left (fun acc a -> acc +. a#get) 0. account_list
    method print = List.iter (fun a -> a#print) account_list
    method fees = List.iter (fun a -> a#withdraw (5. *. a#get /. 100.)) account_list
end

class ['a] collection = 
object
    val mutable content = []
    method add (i : 'a) = content <- i :: content
end

class bank =
object
    inherit [account] collection
    method balance = List.fold_left (fun acc a -> acc +. a#get) 0. content
    method print = List.iter (fun a -> a#print) content
    method fees = List.iter (fun a -> a#withdraw (0.05 *. a#get /. 100.)) content
end