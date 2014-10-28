(define (difference list1 list2)
 (filter-list (lambda (num) (and (list-member? num list1) (not (list-member? num list2)))) (append list1 list2)))

(define (list-member? a list)
  (cond
    ((null? list) #f)
    ((= a (car list)) #t)
    (else (list-member? a (cdr list)))))

(define (filter-list pred? list)
  (cond
    ((null? list) '())
    ((pred? (car list)) (cons (car list) (filter-list pred? (cdr list))))
    (else (filter-list pred? (cdr list)))))