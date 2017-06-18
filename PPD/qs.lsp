


(defun small(n l)
(if(null l)nil
(if(<(car l)n)
(cons(car l)
(small n(cdr l))
)
(small n(cdr l))
)))

(defun large(n l)
(if(null l)nil
(if(>(car l)n)
(cons(car l)
(large n(cdr l))
)
(large n(cdr l))
)))


(defun qsort(l)
(if(null l)nil
(append
(qsort(small(car l)(cdr l)))
(cons(car l)nil)
(qsort(large(car l)(cdr l)))
)))
