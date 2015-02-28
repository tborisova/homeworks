(define (both-in f g start end)
  (lambda (x) (and (and (>= (f x) start) (<= (f x) end))) (and (>= (g x) start) (<= (g x) end)))
)

(both-in (lambda (x) (* x 2)) (lambda (x) (* x 3)) -10 10)        ;->  #<procedure:........>
( (both-in (lambda (x) (* x 2)) (lambda (x) (* x 3)) -10 10) 1)   ;->  #t
( (both-in (lambda (x) (* x 2)) (lambda (x) (* x 3)) -10 10) 2)   ;->  #t
( (both-in (lambda (x) (* x 2)) (lambda (x) (* x 3)) -10 10) 3)   ;->  #t
( (both-in (lambda (x) (* x 2)) (lambda (x) (* x 3)) -10 10) 4)   ;->  #f