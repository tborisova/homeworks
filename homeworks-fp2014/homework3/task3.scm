(define (cosh-series x n) 
  (define (calculate-ugly-number exp)
    (/ (expt x exp) (fact exp))
  )
  
  (accumulate + 0 calculate-ugly-number 0 (lambda (x) (+ 2 x)) n)
)

(define (accumulate op initial-value f a next b)
  (if (> a b)
      initial-value
      (op (f a) (accumulate op initial-value f (next a) next b))))

(define (fact x)
  (accumulate * 1 (lambda(x) x) 1 (lambda(x) (+ 1 x)) x)
)

(define pi 3.14159265)

