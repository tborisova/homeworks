(define (sum-of-oddly a b)
  (sum-of-oddly-helper a b 0)
)

(define (sum-of-oddly-helper a b sum)
  (cond
    ((> a b) sum)
    ((odd? (sum-divisors a)) (sum-of-oddly-helper (+ 1 a) b (+ sum a)))
    (else (sum-of-oddly-helper (+ 1 a) b sum))
  )
)

(define (sum-divisors a)
  (sum-divisors-helper a 1 0))

(define (sum-divisors-helper a current res)
  (cond
    ((< a current) res)
    ((= (remainder a current) 0) (sum-divisors-helper a (+ 1 current) (+ 1 res)))
    (else (sum-divisors-helper a (+ 1 current) res))
  )
)

(sum-of-oddly 1 10)     ;->   14   (1 + 4 + 9)
(sum-of-oddly 100 200)  ;->   730
(sum-of-oddly 1 42)     ;->   91