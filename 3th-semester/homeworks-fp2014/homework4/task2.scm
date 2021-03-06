(define (uniq list1)
  (if (null? list1)
      list1
      (uniq-helper list1 (list (car list1)))))

(define (uniq-helper list1 list2)
  (cond
    ((null? list1) list2)
    ((not (list-member? (car list1) list2)) (uniq-helper (cdr list1) (append list2  (list (car list1)))))
    (else (uniq-helper (cdr list1) list2))))

(define (list-member? a list)
  (cond
    ((null? list) #f)
    ((= a (car list)) #t)
    (else (list-member? a (cdr list)))))