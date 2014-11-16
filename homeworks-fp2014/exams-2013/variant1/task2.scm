(define (unpack l)
  (unpack-helper l '())
)

(define (unpack-helper l l2)
  (cond
    ((null? l) l2)
    (else (unpack-helper (cdr l) (append l2 (make-list-with (car (car l)) (cadr (car l))))))
 )
)

(define (make-list-with element occurences)
  (make-list-helper element occurences 0 '())
)

(define (make-list-helper element occurences current l)
  (cond
    ((= occurences current) l)
    (else (make-list-helper element occurences (+ 1 current) (append l (list element))))
  )
)

(define l  '((1 2) (5 3) (10 3)))
(unpack l)
