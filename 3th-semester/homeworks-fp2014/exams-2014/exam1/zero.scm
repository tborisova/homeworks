(load "functions.scm")

(define (zero matrix) 
 (define (zero-helper matrix)
   (cond
    ((null? matrix) '())
    ((row-contains-zero? (car matrix)) (cons (make-zero-row (length (car matrix))) (zero-helper (cdr matrix))))
    (else (cons (car matrix) (zero-helper (cdr matrix))))))
  (transpose (zero-helper (transpose matrix))))

(define (row-contains-zero? row)
  (any? (lambda (x) (= x 0)) row))

(define (make-zero-row len)
  (if (= len 0)
      '()
      (cons 0 (make-zero-row (- len 1)))))

(define (row matrix n)
  (if (= n 0)
      (car matrix)
      (row (cdr matrix) (- n 1))))

(define (transpose matrix)
  (transpose-helper matrix 0))

(define (transpose-helper matrix current)
  (if (= current (length (car matrix)))
      '()
      (cons (column matrix current) (transpose-helper matrix (+ current 1)))))

(define (nth-element list n)
  (if (= n 0)
      (car list)
      (nth-element (cdr list) (- n 1))))

(define (column matrix n)
  (map  (lambda (row) (nth-element row n)) matrix))