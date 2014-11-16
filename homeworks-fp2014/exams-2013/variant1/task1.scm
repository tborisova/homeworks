(define (sum-of-evenly a b)
  (sum-of-evenly-helper a b a 0)
)

(define (sum-of-evenly-helper a b counter res)
  (cond
    ((< b counter) res)
    ((= (remainder (sum-of-evenly-dels counter) 2) 0) (sum-of-evenly-helper a b (+ 1 counter) (+ res counter)))
    (else (sum-of-evenly-helper a b (+ 1 counter) res))
  )
)

(define (sum-of-evenly-dels num)
  (sum-of-evenly-dels-helper num 1 0)
)

(define (sum-of-evenly-dels-helper num delitel sum)
  (cond
    ((< num delitel) sum)
    ((= (remainder num delitel) 0) (sum-of-evenly-dels-helper num (+ delitel 1) (+ 1 sum)))
    (else (sum-of-evenly-dels-helper num (+ delitel 1) sum))
    )
)

(sum-of-evenly 1 10) 
(sum-of-evenly 100 200)
(sum-of-evenly 1 42)