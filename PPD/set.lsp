( defun mem(a l)
(cond
	((null l)nil)
	((eq a (car l))t)
	(t (mem a (cdr l)))
))

( defun my_union(l1 l2)
(cond
        ((null l1)l2)
	((null l2)l1)
        ((mem (car l1) l2) (my_union (cdr l1) l2))
	(t 
))

