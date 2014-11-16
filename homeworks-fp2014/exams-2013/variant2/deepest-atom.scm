(define (deepest-atom tree)
  (deepest-atom-helper tree 0)
)

(define (deepest-atom-helper tree res)
  (cond
    ((or ((null? tree) (= (length tree) 2))) res)
    ((pair? (cadr tree)) (deepest-atom-helper (cdr tree) (+ 1 res)))
    (else (deepest-atom-helper (cdr tree) res))
  )
)

(define l '(1 (2 (3 4)) 5))
(cadr l)

(deepest-atom '(1 2 3))          ;->  1
(deepest-atom '(1 (2 (3 4)) 5))  ;->  3
(deepest-atom '(1 (2 3 (4 5))))  ;->  3