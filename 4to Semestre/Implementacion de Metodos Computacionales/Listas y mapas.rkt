#lang racket

(define (suma a b)
  (+ a b))

(define x 100)
(define y 200)

(define (area alt base)
  (* alt base))
(define (calc-area lalt lbase)
  (map area lalt lbase))

(define (cal-area-2 lalt lbase)
  (map (lambda (alt base) (* alt base)) lalt lbase))

(define lista1 (list 1 2 3 4 5 6 7 8))
(define lista2 (list 100 200 300 400 500))
(define lista3 (list 1 2 (list 3 4 5) 6 7 8 9 (list 10 (list 11 12 13 14 15)) 16))
(define lista4 (list 1 2 (list 3 4) 5))

;Cuenta los elem que tiene una lista
(define (cuenta-elem lst)
 (if (empty? lst)
     0
     (+ 1 (cuenta-elem (cdr lst)))))

;Genera una lista con n ceros n=4 '(0 0 0 0)
(define (genera-zero n)
  (if (= n 0)
      '()
      (cons 0 (genera-zero (- n 1)))))

;reversa de una lista
(define (reverse lst)
  (if (empty? lst)
      '()
      (append (reverse (cdr lst) ) (list (car lst)))))

(reverse lista4)

; contar todos los atomos que estan en una lista
(define (cuenta-atomos lst)
  (if (empty? lst)
      0
      (if (list? (car lst))
                 (+ (cuenta-atomos (car lst)) (cuenta-atomos (cdr lst)))
                 (+ 1 (cuenta-atomos (cdr lst))))))

(cuenta-atomos lista4)