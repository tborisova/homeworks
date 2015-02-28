(define (remove-el el l)
  (filter-list (lambda (x) (not (= x el))) l))

(define (filter-list pred? list)
  (cond
    ((null? list) '())
    ((pred? (car list)) (cons (car list) (filter-list pred? (cdr list))))
    (else (filter-list pred? (cdr list)))))

(define (counts l)
  (counts-helper l '()))

(define (occurrences a l)
  (cond
    ((null? l) 0)
    ((= (car l) a) (+ 1 (occurrences a (cdr l))))
    (else (occurrences a (cdr l)))))

(define (counts-helper l l2)
  (cond
    ((null? l) l2)
    (else (cons (cons (car l) (occurrences (car l) l)) (counts-helper (remove-el (car l) l) l2)))))