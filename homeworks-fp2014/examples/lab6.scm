(define test-matrix '((1 2 3) (4 5 6) (7 8 9)))

(define (row matrix n)
  (if (= n 0)
    (car matrix)
    (row (cdr matrix) (- n 1))
  )
)

(define (col matrix n)
  (if (= n 0)
    (car matrix)
    (row (cdr matrix) (- n 1))
  )
)

(row test-matrix 1)