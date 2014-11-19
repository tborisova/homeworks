(define (nth-digit number digit-index)
  (cond
    ((= number 0) -1)
    ((= digit-index (len-number number)) (remainder number 10))
    (else (nth-digit (quotient number 10) digit-index))
  )  
)

(define (len-number number)
  (if (= number 0)
      0
      (+ 1 (len-number (quotient number 10)))))

(define (reverse-number number)
  (if (= number 0)
      0
    (+ (* (remainder number 10) (expt 10 (- (len-number number) 1))) (reverse-number (quotient number 10)))))

(define (palindrome? number)
  (palindrome-helper number 1 (len-number number))
)

(define (palindrome-helper number head-digit tail-digit)
  (if (or (= head-digit tail-digit) (> head-digit tail-digit))
      #t
      (and (= (nth-digit number head-digit) (nth-digit number tail-digit)) (palindrome-helper number (+ 1 head-digit) (- tail-digit 1)))))


; not working??: to slow
(define (non-lychrel-sum a b)
  (cond
    ((and (= a b) (palindrome? (+ a (reverse-number a)))) a)
    ((= a b) 0)
    ((palindrome? (+ a (reverse-number a))) (+ a (non-lychrel-sum (+ 1 a) b)))
    (else (non-lychrel-sum (+ 1 a) b))
  )
)

(non-lychrel-sum 10 30)