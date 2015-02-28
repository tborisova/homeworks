(define (magic-square? M)
  (cond
    ((null? M) #f)
    ((and (all-rows-have-sum (diagonal-sum M) M) (all-cols-have-sum (diagonal-sum M) M) (secondary-diagonal-sum (diagonal-sum M) M)) #t)
    (else #f)))

(define (all-rows-have-sum sum M)
  (cond
    ((null? M) #t)
    ((= (sum-list (car M)) sum) (all-rows-have-sum sum (cdr M)))
    (else #f)))

(define (all-cols-have-sum sum M)
  (all-rows-have-sum sum (transpose M)))

(define (secondary-diagonal-sum sum M)
  (sum-list (secondary-diagonal M))
)

(define (diagonal-sum M)
  (sum-list (diagonal M)))

(define (sum-list l)
  (cond
    ((null? l) 0)
    ((+ (car l) (sum-list (cdr l))))))

(define (transpose matrix)
  (transpose-helper matrix 0))

(define (transpose-helper matrix current)
  (if (= current (length (car matrix)))
      '()
      (cons (column matrix current) (transpose-helper matrix (+ current 1)))))

(define (secondary-diagonal matrix)
  (secondary-diagonal-helper matrix (- (length (car matrix)) 1)))

(define (secondary-diagonal-helper matrix current)
  (if (< current 0)
      '()
      (cons (get-at current (car matrix)) (secondary-diagonal-helper (cdr matrix) (- current 1)))))

(define (get-at position list)
  (if (= position 0)
      (car list)
      (get-at (- position 1) (cdr list))))

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

(define (diagonal matrix)
  (define (diagonal-helper matrix current)
    (if (= current (length matrix))
        '()
        (cons (nth-element (row matrix current) current) (diagonal-helper matrix (+ current 1)))))
  (diagonal-helper matrix 0))