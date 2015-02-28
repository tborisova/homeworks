(define (last-index-of elem list)
  (define (last-index-of-helper l counter pos)
    (cond
     ((null? l) pos)
     ((= elem (car l)) (last-index-of-helper (cdr l) (+ 1 counter) (+ pos counter)))
     (else (last-index-of-helper (cdr l) (+ 1 counter) pos))))
  
  (if (list-member? elem list) (last-index-of-helper list 0 0) -1))

(define (list-member? a list)
  (cond
    ((null? list) #f)
    ((= a (car list)) #t)
    (else (list-member? a (cdr list)))))