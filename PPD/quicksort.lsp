(defun qsort (L)
   (cond
   ((null L) nil)
   (t(append
      (qsort (small (car L) (cdr L)))
      (cons (car L) nil)
      (qsort (large (car L) (cdr L)))))))

(defun small (n l)
    (cond
    (( or(null n)(null l) nil))
    (( < n (car l)) (small n (cdr l)))
    (t(cons (car l) (small n (cdr l))))))

(defun large (n l)
    (cond
    (( or( null n)(null l) nil))
    (( >= n (car l)) (large n (cdr l)))
    (t(cons (car l) (large n (cdr l))))))   
