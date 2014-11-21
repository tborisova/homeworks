(define (area a b c)
  (define s (/ (+ a b c) 2))
  (sqrt (* s (- s a) (- s b) (- s c)))
)