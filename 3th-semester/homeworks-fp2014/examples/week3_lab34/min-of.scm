(define (square x)
  (* x x))

(define (inc x)
  (+ x 1))

(define (dec x)
  (- x 1))

; идентитен
(define (id x) x)

(define (min-of f g)
  (lambda (x) (min (f x) (g x)))
)