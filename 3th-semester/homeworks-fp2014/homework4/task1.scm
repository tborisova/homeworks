(define (less-than list1)
  (lambda (number) (filter-list (lambda (el) (< el number)) list1)))

(define (filter-list pred? list)
  (cond
    ((null? list) '())
    ((pred? (car list)) (cons (car list) (filter-list pred? (cdr list))))
    (else (filter-list pred? (cdr list)))))