(defun small(a l)
(if(null l) nil
(if(< (car l) a) 
(cons(car l)
(small a(cdr l))
)
(small a(cdr l))
)))

(defun large(a l)
(if(null l) nil
(if(> (car l) a)
(cons(car l)
(large a(cdr l))
)
(large a(cdr l))
)))

(defun qsort(l)
(if(null l) nil
(append
(qsort(small(car l)(cdr l)))
(cons(car l)nil)
(qsort(large(car l)(cdr l)))
)))
