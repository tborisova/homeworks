(define (nth-element list n)
  (if (= n 0)
      (car list)
      (nth-element (cdr list) (- n 1))))

(define positive-el '(((1 1) (2 2) (3 3)) ((1 2) (2 3) (3 1)) ((1 3) (2 1) (3 2))))
(define negative-el '(((3 1) (2 2) (1 3)) ((3 2) (2 3) (1 1)) ((3 3) (2 1) (1 2))))

(define (determinant matrix)
  (- (sum-of-elements positive-el matrix) (sum-of-elements negative-el matrix))
)

(define (sum-of-elements el-coords matrix)
  (sum-of-elements-helper el-coords matrix 0)
)

(define (sum-of-elements-helper el-coords matrix res)
  (cond
    ((null? el-coords) res)
    (else (sum-of-elements-helper (cdr el-coords) matrix (+ res (proizvedenie (car el-coords) matrix 1))))))

(define (proizvedenie list-of-coords matrix res)
  (cond
    ((null? list-of-coords) res)
    (else (proizvedenie (cdr list-of-coords) matrix (* (el-at-row-col matrix (- (nth-element (car list-of-coords) 0) 1) (- (nth-element (car list-of-coords) 1) 1)) res)))
  )
)

(define (el-at-row-col matrix row col)
  (nth-element (nth-element matrix row) col)
)

