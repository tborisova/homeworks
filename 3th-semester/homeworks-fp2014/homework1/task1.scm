(define (quadrant x y)
  (cond 
    ((and (= x 0) (= y 0)) 0)
    ((and (positive? x) (positive? y)) 1)
    ((and (negative? x) (positive? y)) 2)
    ((and (negative? x) (negative? y)) 3)
    ((and (positive? x) (negative? y)) 4)
  )
)