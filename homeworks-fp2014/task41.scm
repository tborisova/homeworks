(define (less-than list1)
  (lambda (number) (less-than-num list1 number))
)

(define (less-than-num list1 num)
  (cond
    ((null? list1) list1)
    ((< (car list1) num) (cons (car list1) (less-than-num (cdr list1) num)))
    (else (less-than-num (cdr list1) num))
  )
)

(define (uniq list1)
  (if (null? list1) list (uniq-helper list1 '()))
)

(define (uniq-helper list1 list2)
  (cond
    ((null? list1) list1)
    ((list-member? (car list1) list2) (uniq-helper (cdr list1) list2))
    (else (cons (car list1) (uniq-helper (cdr list1) list2)))
  )
)

(define (list-member? a list)
  (cond
    ((null? list) #f)
    ((= a (car list)) #t)
    (else (list-member? a (cdr list)))))