(define (fact n)
  (if (= n 0) 1 (* n (fact (- n 1)))))

(define (digit-factorials n)
  (digit-factorials-helper n 1 '()))

(define (digit-factorials-helper n counter l1)
  (cond 
    ((and (<= counter n) (they-are-true counter)) (digit-factorials-helper n (+ 1 counter) (append l1 (list counter))))
    ((and (<= counter n) (not (they-are-true counter))) (digit-factorials-helper n (+ 1 counter) l1))
    (else l1)))

(define (they-are-true n)
  (define sum (they-are-true-helper n 0))
  (= sum n))

(define (they-are-true-helper n counter)
 (cond
   ((= n 0) counter)
   (else (they-are-true-helper (quotient n 10) (+ counter (fact (remainder n 10)))))))

