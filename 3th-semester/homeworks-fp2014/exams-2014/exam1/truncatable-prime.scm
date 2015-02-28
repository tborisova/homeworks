(load "functions.scm")

(define (truncatable-prime? x)
  (cond
    ((= x 0) #t)
    ((prime? x) (truncatable-prime? (quotient x 10)))
    (else #f)))

(define (prime? x)
  (prime-helper x 2))

(define (prime-helper x current)
  (cond
    ((= x 1) #f)
    ((or (= x 2) (= x current)) #t)
    ((= (remainder x current) 0) #f)
    ((and #t (prime-helper x (+ 1 current))))))