(define (number-columns matrix)
  (if (null? matrix)
      0
      (length (row matrix 0))))

(define (number-rows matrix)
  (if (null? matrix)
      0
      (length (column matrix 0))))

(define (row matrix n)
  (if (= n 0)
      (car matrix)
      (row (cdr matrix) (- n 1))))

(define (nth-element list n)
   (if (= n 0)
       (car list)
       (nth-element (cdr list) (- n 1))))

(define (column matrix n)
  (map  (lambda (row) (nth-element row n)) matrix))

(define (transpose matrix)
  (transpose-helper matrix 0))

(define (transpose-helper matrix current)
  (if (= current (matrix-size-2 matrix))
      '()
      (cons (column matrix current) (transpose-helper matrix (+ current 1)))))

(define (swap matrix i j)
  (swap-helper matrix (min i j) (max i j) 0 '() (matrix-size matrix))
)

(define (matrix-size matrix)
  (cond
    ((= (number-columns matrix) (number-rows matrix)) (length matrix))
    (else (- (length matrix) 1))
  )
)

(define (matrix-size-2 matrix)
  (cond
    ((= (number-columns matrix) (number-rows matrix)) (length matrix))
    (else (+ (length matrix) 1))
  )
)

(define (delete-col matrix i)
  (delete-col-helper (transpose matrix) (- i 1) 0 '())
)

(define (delete-col-helper matrix i current new-matrix)
  (cond
    ((null? matrix) (transpose new-matrix))
    ((= i current) (delete-col-helper (cdr matrix) i (+ 1 current) new-matrix))
    (else (delete-col-helper (cdr matrix) i (+ 1 current) (append new-matrix (list (car matrix)))))
))

(delete-col '((1 2 3) (4 5 6)) 1)    ; ->  ((2 3) (5 6))
(delete-col '((1 2) (3 4) (5 6)) 2)   ;->  ((1) (3) (5))