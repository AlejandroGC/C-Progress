#lang racket


;Act 2.1

;Act 1
(define (ftc f)
  (/ (* 5 (- f 32)) 9))

;Act 2
(define (bmi m a)
  (define indice (/ m (* a a)))
  (cond
    [(< indice 20) (display "underweight")]
    [(and (<= 20 indice) (< indice 25)) (display "normal")]
    [(and (<= 25 indice) (< indice 30)) (display "obese1")]
    [(and (<= 30 indice) (< indice 40)) (display "obese2")]
    [(<= 40 indice) (display "obese3")]
    ))

;Act 3
(define (mayor-0 n)
  (> n 0))

(define (positives lst)
  (filter mayor-0 lst))

;opcion 2

(define (positive-2 lst)
  (if (empty? lst)
      '()
      (if (> (car lst) 0)
          (cons (car lst) (positive-2 (cdr lst)))
          (positive-2 (cdr lst)))))

;Act 4
(define (swapper a b lst)
  (if (empty? lst)
      '()
      (if (equal? (car lst) a)
          (cons b (swapper a b (cdr lst)))
          (if (equal? (car lst) b)
              (cons a (swapper a b (cdr lst)))
              (cons (car lst) (swapper a b (cdr lst)))))))
