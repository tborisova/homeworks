(load "functions.scm")

(define (where list-elements list-predicates)
  (filter (lambda (x) (all-is-true list-predicates x)) list-elements))

(define (all-is-true list-predicates x)
  (= 0 (length (filter (lambda (pred) (not (pred x))) list-predicates))))
