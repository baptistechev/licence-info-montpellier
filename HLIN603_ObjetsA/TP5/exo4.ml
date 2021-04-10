class virtual ['a] abr =
object
    method virtual insert : 'a -> 'a abr
    method virtual find : 'a -> bool
end

class ['a] node n (l : 'a abr) (r : 'a abr) =
object (self)
  inherit ['a] abr
  val value = n
  val mutable left = l
  val mutable right = r
  method insert (n : 'a) =
    (if n < value then left <- left#insert n
     else if n > value then right <- right#insert n);
    (self :> 'a abr)
  method find (n : 'a) =
    if n == value then true
    else if n < value then left#find n
    else right#find n
end

class ['a] empty =
object
  inherit ['a] abr
  method insert n = new node n (new empty) (new empty)
  method find n = false
end