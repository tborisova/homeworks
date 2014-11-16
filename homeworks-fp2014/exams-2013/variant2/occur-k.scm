(define (occur-k items k)
  (define (occur-k-helper l1 k l2)
    (cond
      ((null? l1) l2)
      ((= (occurences items (car l1)) k) (occur-k-helper (cdr l1) k (append l2 (list (car l1)))))
      (else (occur-k-helper (cdr l1) k l2))
    ))
  (occur-k-helper items k '()))

(define (occurences items k)
  (occurences-helper items k 0)
)

(define (occurences-helper items k count)
  (cond
    ((null? items) count)
    ((= (car items) k) (occurences-helper (cdr items) k (+ 1 count)))
    (else  (occurences-helper (cdr items) k count))
  )
)

(occur-k '(1 2 3 5 2 5) 1)  ;->  (1 3)
(occur-k '(1 2 3 5 2 5) 2)  ;->  (2 5 2 5)
(occur-k '(1 2 3 5 2 5) 3)  ;->  ()