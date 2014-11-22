(define (repeater str)
  (lambda (count glue) (glue-parts-count glue str count)))

(define (glue-parts-count glue str count)
  (cond
    ((or (equal? glue "") (equal? str "")) "")
    ((= 0 (- count 1)) (string-append str ""))
    (else (string-append str glue (glue-parts-count glue str (- count 1))))))