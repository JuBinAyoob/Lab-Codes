(defun cou(a l)
	(if (null l)0
	(if(eq a(car l))(1+(cou a (cdr l)))
	(cou a (cdr l))
	))
)
