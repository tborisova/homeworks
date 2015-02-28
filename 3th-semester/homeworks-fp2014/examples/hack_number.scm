(define (hack-number? number)
  (and (palindrome? (to-binary number)) (string-lenght (odd? (to-binary number))))
)

(define (to-binary number)
  (if (or (= number 0) (= number 1))
      (number->string number)
      (string-append (to-binary (quotient number 2)) (number->string (remainder number 2)))))

(define (palindrome? string)
  (palindrome-helper string 0 (- (string-length string) 1))
)

(define (palindrome-helper string start end)
  (cond
    ((or (= start end) (> start end)) #t)
    (else (and (= (string->number(nth-element-str string start)) (nth-element-str string end)) (palindrome-helper string (+ 1 start) (- end 1))))
  )
)

(define (nth-element-str string index)
  (nth-element (string->list string) index)
)

(define (nth-element list n)
  (if (= n 0)
      (car list)
      (nth-element (cdr list) (- n 1))))