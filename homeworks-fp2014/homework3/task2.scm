(define (fact x)
  (accumulate * 1 (lambda(x) x) 1 (lambda(x) (+ 1 x)) x)
)

(define (accumulate op initial-value f a next b)
  (if (> a b)
      initial-value
      (op (f a) (accumulate op initial-value f (next a) next b))))
