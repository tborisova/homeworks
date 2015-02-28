(define (is-hack-number? number)
  (and (palindrome? (to-binary number)) (odd? (string-length (to-binary number))))
)

(define (to-binary number)
  (if (or (= number 0) (= number 1))
      (number->string number)
      (string-append (to-binary (quotient number 2)) (number->string (remainder number 2)))))

(define (palindrome? string)
  (= (string->number string) (reverse-number (string->number string)))
)

(define (nth-digit number digit-index)
  (cond
    ((= number 0) -1)
    ((= digit-index (len-number number)) (remainder number 10))
    (else (nth-digit (quotient number 10) digit-index))
  )  
)

(define (len-number number)
  (define (len-number-helper number res)
    (cond
      ((= number 0) res)
      (else (len-number-helper (quotient number 10) (+ 1 res)))
    )
  )
  (len-number-helper number 0)
)

(define (nth-element-str string index)
  (nth-element (string->list string) index)
)

(define (reverse-number number)
  (cond
    ((= number 0) 0)
    (else (+ (* (remainder number 10) (expt 10 (- (len-number number) 1))) (reverse-number (quotient number 10))))
  )
)

(define (nth-element list n)
  (if (= n 0)
      (car list)
      (nth-element (cdr list) (- n 1))))

(define (sum-of-hack a b)
  (cond
    ((and (= a b) (is-hack-number? a)) a)
    ((= a b) 0)
    ((is-hack-number? a) (+ a (sum-of-hack (+ a 1) b)))
    (else (sum-of-hack (+ a 1) b))
  )
)