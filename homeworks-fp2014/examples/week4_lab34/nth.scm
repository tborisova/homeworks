(define (nth index list)
  (nth-helper index list 0)
)

(define (nth-helper index list current)
 (cond
    ((null? list) -1)
    ((= index current) (car list))
    (else (nth-helper index (cdr list) (+ 1 current)))
  )  
)

(define l '(5 6 7 8 9 10))

(define (join glue parts)
  (if (null? parts)
      ""
      (string-append (car parts) glue (join glue (cdr parts)))))

(join " " (list "Scheme" "is" "an" "akward" "language"))
(join "1!" (list "One" "Two" "Three"))

(define (split delimiter str)
  (split-helper (car (string->list delimiter)) (string->list str) '() '())
)

(define (split-helper delimiter list-of-chars new-list current-list)
  (cond
    ((null? list-of-chars) (append new-list (list (list->string current-list))))
    ((equal? delimiter (car list-of-chars)) (split-helper delimiter (cdr list-of-chars) (append new-list (list (list->string current-list))) '()))
    (else (split-helper delimiter (cdr list-of-chars) new-list (append current-list (list (car list-of-chars)))))
  )
)

(split " " "Scheme is an akward language")











