#lang racket
; Alejandro Daniel Gonzalez Carrillo
; A01570396

;Act 1
(define (insert n lst)
  (if (empty? lst)
      (list n)
      (if (< n (car lst))
          (cons n lst)
          (cons (car lst) (insert n (cdr lst))))))

;Act 2
(define (rotate-left n lst)
  (define (m n lst)
    (modulo n length(lst)))
  (cond
    [(or (= n 0) (empty? lst)) lst]
    [(< n 0) (rotate-left (+ n 1) (cons (last lst) (drop-right lst 1)))]
    [else (rotate-left (- n 1) (append (cdr lst)(list (car lst))))]))

;Act 3

(define (decode n lst)
  (if (= (length lst) 1)
      (list (cons n (list (car lst))))
      (if (equal? (car lst) (cadr lst))
          (decode(+ n 1) (cdr lst))
          (append (list (cons n (list (car lst)))) (decode 1 (cdr lst))))))

(define (encode lst)
  (if (empty? lst)
      '()
      (decode 1 lst)))


;Act 4
(define (deep-reverse lst)
  (if (empty? lst)
      '()
      (if (list? (car lst))
          (append (deep-reverse (cdr lst)) (list (deep-reverse (car lst))))
          (append (deep-reverse (cdr lst)) (list (car lst))))))