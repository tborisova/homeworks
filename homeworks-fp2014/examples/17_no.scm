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

(define (product-of-digits n)
  (define (product-of-digits-helper number res)
    (if (= number 0)
      res
      (product-of-digits-helper (quotient number 10) (* (remainder number 10) res))))
  (product-of-digits-helper n 1))

(define (ordinals n)
  (cond
    ((and (<= n 20) (>= n 10)) (string-append (number->string n) "th"))
    ((ends-with? n 1) (string-append (number->string n) "st"))
    ((ends-with? n 2) (string-append (number->string n) "nd"))
    ((ends-with? n 3) (string-append (number->string n) "rd"))
    (else (string-append (number->string n) "th"))))

(define (ends-with? number digit)
  (= digit (nth-digit number (len-number number)))
)

(define (reverse-number n)
  
)