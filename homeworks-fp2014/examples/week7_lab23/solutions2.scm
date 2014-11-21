(define (filter-map-all pr maps items)
  (filter (lambda (x) (all-values-are-true? pr (get-array-of-one-value-and-maps maps x))) items)
)

(define (all-values-are-true? pr l)
  (filter (lambda (x) ()) l)
)

(define (get-array-of-one-value-and-maps maps value)
  (map (lambda (map-i) (map-i value)) maps))

(filter-map-all predicates maps items)