(define l1 '(1 2 3 4 5 6))
(define l2 '(3 4 5))

(define (sublist-index list1 list2)
  (sublist-helper list1 list2 0))

(define (take n l)
  (define (iter n list result)
    (cond
      ((null? list) result)
      ((= n 0) result)
      (else (iter (- n 1) (cdr list) (cons (car list) result)))))
  (reverse (iter n l (list))))

(define (equal-lists? l1 l2)
  (cond
    ((or (null? l1) (null? l2)) #t)
    ((= (car l1) (car l2)) (equal-lists? (cdr l1) (cdr l2)))
    (else #f)
  )
)

(define (sublist-helper list1 list2 index)
  (cond
    ((or (null? list1) (null? list2)) index)
    ((and (equal? (car list1) (car list2)) (equal? list2 (take (length list2) list1))) index)
    (else (sublist-helper (cdr list1) list2 (+ 1 index)))
  )  
)

;(sublist-index l1 l2)

(define (index-of str1 str2)
  (sublist-index (string->list str2) (string->list str1)))

(define s2 "Hello World")
(define s1 "ello")

(index-of s1 s2)

(define (negate f)
  (lambda (x) (not (f x))))

(define (make-number n)
  (list->number (make-number-helper (number->list n) 0))
)
(define (list->number l)
  (define (iter l result)
    (cond
      ( (null? l)  result )
      (else (iter (cdr l) (glue-ints result (car l))))))
  (iter l 0))

(define (number->list n)
  (define (iter n result)
    (cond ((= n 0) result)
          (else (iter (quotient n 10) (cons (remainder n 10) result)))))
  (iter n (list)))
(define (glue-ints a b)
  (+ (* a 10) b))
(define (nth index list)
  (cond
    ((= index 0) (car list))
    (else (nth (- index 1) (cdr list)))))

(define (make-number-helper n current)
  (cond
    ((null? n) '())
    ((even? (+ 1 current)) (cons (car n) (make-number-helper (cdr n) (+ 1 current))))
    (else (make-number-helper (cdr n) (+ 1 current)))
  )
)

(define (compose f g)
  (lambda (x) (f (g x)))
)

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

(define (add-matrix matrix1 matrix2)
  (cond
    ((and (null? matrix1) (null? matrix2)) '())
    (else (cons (add-row (car matrix1) (car matrix2)) (add-matrix (cdr matrix1) (cdr matrix2))))))

(define (add-row row1 row2)
  (if (and (null? row1) (null? row2))
      '()
      (cons (+ (car row1) (car row2)) (add-row (cdr row1) (cdr row2)))))

(define (scalar-product scalar matrix)
  (if (null? matrix)
      '()
      (cons (scalar-product-row scalar (car matrix)) (scalar-product scalar (cdr matrix)))))

(define (scalar-product-row scalar row)
  (map (lambda (x) (* scalar x)) row))

(define (transpose matrix)
  (transpose-helper matrix 0))

(define (transpose-helper matrix current)
  (if (= current (length (car matrix)))
      '()
      (cons (column matrix current) (transpose-helper matrix (+ current 1)))))

(define (number-columns matrix)
  (if (null? matrix)
      0
      (length (row matrix 0))))

(define (number-rows matrix)
  (if (null? matrix)
      0
      (length (column matrix 0))))
  
(define (dot-product vector1 vector2)
  (if (null? vector1)
      0
      (+ (* (car vector1) (car vector2)) (dot-product (cdr vector1) (cdr vector2)))))

(define (matrix-multiply m1 m2)
  (map (lambda (row)
         (map (lambda (col) (dot-product row col))
              (transpose m2)))
       m1))

(define (matrix-power matrix n)
  (if (= n 1)
      matrix
      (matrix-multiply (matrix-power matrix (- n 1)) matrix)))

(define (delete-row matrix n)
  (delete-row-helper matrix n 0))

(define (delete-row-helper matrix n current)
  (cond
    ((= current (number-rows matrix)) '())
    ((= n current) (delete-row-helper matrix n (+ current 1)))
    (else (cons (row matrix current) (delete-row-helper matrix n (+ current 1))))))

(define (without list index)
  (cond
    ((null? list) '())
    ((= index 0) (without (cdr list) (- index 1)))
    (else (cons (car list) (without (cdr list) (- index 1))))))

(define (delete-column matrix n)
  (map (lambda (row) (without row n)) matrix))

(define (make-matrix m1 m2)
  (transpose (make-matrix-helper (transpose m1) (transpose m2) 0))
)

; start from 0 or 1
(define (make-matrix-helper m1 m2 index)
  (cond
   ((or (null? m1) (null? m2)) '()) 
   ((even? index) (cons (car m1) (make-matrix-helper (cdr m1) (cdr m2) (+ 1 index))))
   (else (cons (car m2) (make-matrix-helper (cdr m1) (cdr m2) (+ 1 index))))
  )
)



(define test-matrix '((1 2 3) (4 5 6) (7 8 9)))

(define test-matrix2 '((11 12 13) (14 15 16) (71 18 19)))

(make-matrix test-matrix test-matrix2)
;(compose f g)
;(define num 1234)
;(make-number num)