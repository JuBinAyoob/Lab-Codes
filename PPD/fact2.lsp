(defun fact(n) 
(if (or (= n 0)(= n 1))
1
(* n (fact(- n 1)))
))

