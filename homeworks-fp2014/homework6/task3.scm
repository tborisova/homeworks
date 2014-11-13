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

(define (swap-helper matrix i j current-row new-matrix m-length)
  (cond
    ((= m-length current-row) (transpose new-matrix))
    ((= current-row i) (swap-helper matrix i j (+ 1 current-row) (append new-matrix (list (column matrix j))) m-length))
    ((= current-row j) (swap-helper matrix i j (+ 1 current-row) (append new-matrix (list (column matrix i))) m-length))
    (else (swap-helper matrix i j (+ 1 current-row) (append new-matrix (list (column matrix current-row))) m-length))
  )
)
