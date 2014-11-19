(define (sum-of-prime-divisors n)
  (sum-of-prime-divisors-helper n 2 0)
)

(define (sum-of-prime-divisors-helper number div sum)
  (cond
    ((or (= number 0) (= number 1)) sum)
    ((= number div) sum)
    ((and (is-divisor? number div) (prime? div)) (sum-of-prime-divisors-helper number (+ 1 div) (+ sum div)))
    (else (sum-of-prime-divisors-helper number (+ 1 div) sum))
  )
)

(define (prime? number)
  (prime-helper number 2)
)

(define (is-divisor? number div)
  (= (remainder number div) 0)
)

(define (prime-helper number start)
  (cond
   ((= number start) #t)
   ((and (= (remainder number start) 0) (not (= number start))) #f)
   (else (and (not (= (remainder number start) 0)) (prime-helper number (+ start 1))))
  )
)

(sum-of-prime-divisors 10)