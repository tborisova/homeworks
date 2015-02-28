(define (sublist l1 l2)
  (sublist-helper l1 l2 #t)
)

(define (sublist-helper l1 l2 current)
  (cond
    ((or (null? l1) (null? l2)) current)
    ((and (= (car l1) (car l2)) (check-equal l1 (take-elements l2 (length l1)))) (sublist-helper '() l2 #t))
    (else (sublist-helper l1 (cdr l2) #f))
  )
)

(define (take-elements l2 number-to-take)
  (take-elements-helper l2 number-to-take 0 '())
)

(define  (take-elements-helper l2 number-to-take current l)
  (cond
    ((= number-to-take current) l)
    (else (take-elements-helper (cdr l2) number-to-take (+ 1 current) (append l (list (car l2)))))
  )
)

(define (check-equal l1 l2)
  (check-eq-hel l1 l2 #t)
)

(define (check-eq-hel l1 l2 res)
  (cond
    ((null? l1) res)
    ((and (= (car l1) (car l2)) (check-eq-hel (cdr l1) (cdr l2) res)))
    (else (check-eq-hel '() '() #f))
  )
)

(sublist '(1 2 3) '(1 2 3 4 5))
(sublist '(3 4 5) '(1 2 3 4 5)) 
(sublist '(2 3 4) '(1 2 3 4 5)) 
(sublist '(1 2 4) '(1 2 3 4 5)) 