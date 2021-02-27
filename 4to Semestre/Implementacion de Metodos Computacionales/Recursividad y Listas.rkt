#lang racket

; (n * (n+1)) / 2
(define (suma-1 n)
  (/ (* n (+ n 1)) 2))

; not-tail recursive
(define (suma-2 n)
  (if (= n 0)
      0
      (+ n (suma-2 (- n 1)))))

;tail-recursive
(define (suma-tail n a)
  (if (= n 0)
      a
      (suma-tail (- n 1) (+ a n)))
  )

(define (suma-3 n)
  (suma-tail n 0))

;Lista: '(1 2 '(80 90) 100)
; (car lista1) = 1
; (cdr lista1) = 2 3 4 5


(define lista1 '(1 2 3 4 5 6))
(define lista2 '(100 200 300))

;Find the amount of numbers inside an array.
(define (cuantos lst)
  (if (empty? lst)
     0
     (+ 1 (cuantos (cdr lst))))
  )

;Cantidad de valores n en una lista
(define (cantidad n lista)
  (if (empty? lista)
      0
      (if (= n (car lista))
          (+ 1 (cantidad n (cdr lista)))
          (cantidad n (cdr lista)))))

;Append apendiza 2 o mas listas
(define (sumale-1 lst)
  (if (empty? lst)
      '()
      (append (list (+ 1 (car lst))) (sumale-1 (cdr lst))))
  )

;cons apendiza un valor a una lista
(define (sumale-1-b lst)
  (if (empty? lst)
      '()
      (cons (+ 1 (car lst)) (sumale-1-b (cdr lst)))))

;map coleccion, add1 agrega un 1 a todos los datos 
(map add1 lista1)

;intercambia las coincidencias de a por a*2
;intercambia 3 lista 1
; '(1 2 6 4 5 6 6 6 6 6)

(define (intercambia a lst)
  (if (empty? lst)
      '()
      (if (= a (car lst))
          (cons (* 2 a) (cdr lst))
          (cons a (cdr lst)))
      ))

(define (es-a a n)
  (if (= a n)
      (* a 2)
      n))

(define (igual-3 n)
  (= n 3))

(define (may-3 n)
  (> n 3))

; filter(may-3 lista1) = (4 5 6)