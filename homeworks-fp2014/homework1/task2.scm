(define (circle? x y radius)
  (if (<= (+ (expt x 2) (expt y 2)) (expt radius 2)) #t #f)
)