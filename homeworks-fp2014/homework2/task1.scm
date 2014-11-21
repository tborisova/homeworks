(define (prime? x)
  (prime-helper x 2))

(define (is-divisor? x n)
  (= (remainder x n) 0))

(define (prime-helper x current)
  (cond
    ((= current x) #t)
    ((is-divisor? x current) #f)
    (else (prime-helper x (+ current 1)))))

(define (goldbach-helper current x)
  (cond
    ((and (prime? current) (prime? (- x current))) current)
    ((goldbach-helper (+ current 1) x))
  )
)

(define (goldbach x)
  (goldbach-helper 2 x)
)