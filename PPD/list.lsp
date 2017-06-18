

(defun my_member(a l)
(cond((null l) nil)
((eq a (car l))t)
(t (my_member a(cdr l)))))

(defun my_union(l1 l2)
(cond ((null l1)l2)
((null l2)l1)
((my_member(car l1)l2)(my_union (cdr l1)l2))
(t(cons(car l1)(my_union(cdr l1)l2)))))

(defun inter(l1 l2)
(cond ((null l1)nil)
((null l2)nil)
((my_member(car l1)l2)
(cons(car l1) (inter(cdr l1)l2)))
(t (inter(cdr l1)l2))))

(defun dif(l1 l2)
(cond((null l1)nil)
((Null l2)nil)
((my_member(car l1)l2)(dif(cdr l1)l2))
(t(cons(car l1)(dif(cdr l1)l2)))))


