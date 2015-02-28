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

(define (palindrome? number)
  (palindrome-helper number 1 (len-number number))
)

(define (palindrome-helper number head-digit tail-digit)
  (if (or (= head-digit tail-digit) (> head-digit tail-digit))
      #t
      (and (= (nth-digit number head-digit) (nth-digit number tail-digit)) (palindrome-helper number (+ 1 head-digit) (- tail-digit 1)))))


;(define (is-hack-number? n)
;  (and (palindrome? (to-binary n)) (odd? (to-binary n)))
;)