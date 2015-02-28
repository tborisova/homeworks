(define (occurrences a x)
  (cond
    ((= x 0) 0)
    ((= (remainder x 10) a) (+ (occurrences a (quotient x 10)) 1))
    (else (occurrences a (quotient x 10)))))

(define (pandigital-helper digit-from digit-to x)
  (cond
    ((and (= digit-from digit-to) (>= (occurrences digit-to x) 1)))
    ((and (>= (occurrences digit-from x) 1) (pandigital-helper (+ digit-from 1) digit-to x)))
    (else #f)
  )
)

(define (pandigital? x)
  (pandigital-helper 1 (min 9 (digit-count x)) x)
)

(define (digit-count x)
  (if (< x 10)
      1
      (+ 1 (digit-count (quotient x 10)))))
