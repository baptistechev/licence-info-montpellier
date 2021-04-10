class min (xi : int) = 
object (self)
    val mutable x = xi
    method get = x
    method set n = x <- n
    method min y = if self#get < y then self#get else y
end

class min_zero xi =
object
    inherit min xi
    method get = 0
end



