(define (without list index)
  (cond
    ((null? list) '())
    ((= index 0) (without (cdr list) (- index 1)))
    (else (cons (car list) (without (cdr list) (- index 1))))))

(define (duplicate matrix)
  (cond
    ((null? matrix) '())
    ((cons (append (car matrix) (without (car matrix) (- (length (car matrix)) 1))) (duplicate (cdr matrix))))))