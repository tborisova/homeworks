(define (delete-row matrix i)
  (delete-row-helper matrix (- i 1) 0 '()))

(define (delete-row-helper matrix i current new-matrix)
  (cond
    ((null? matrix) new-matrix)
    ((= i current) (delete-row-helper (cdr matrix) i (+ 1 current) new-matrix))
    (else (delete-row-helper (cdr matrix) i (+ 1 current) (append new-matrix (list (car matrix)))))))


(delete-row '((1 2 3) (4 5 6)) 1)   ; ->  ((4 5 6))
(delete-row '((1 2) (3 4) (5 6)) 2) ; ->  ((1 2) (5 6))