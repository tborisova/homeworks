(define (sum-generic f a b)
  (if (> a b)
      0
      (+ (f a) (sum-generic f (+ a 1) b))))

(define (reverse-int n)
  (define (iter n result)
    (cond
      ((= n 0) result)
      (else (iter (quotient n 10) (+ (remainder n 10) (* result 10))))))
    (iter n 0))

(define (non-lychrel-sum a b)
  (sum-generic returns-zero-if-lychrel-else-the-number a b)
)

(define (returns-zero-if-lychrel-else-the-number number)
  (if (is-not-lynchrel number) number 0)
)

(define (is-not-lynchrel number)
  (int-palindrom? (+ number (reverse-int number)))
)

(define (int-palindrom? n)
 (= n (reverse-int n)))
