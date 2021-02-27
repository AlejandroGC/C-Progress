def calculadora(num1, operador, num2):
    if operador == '+':
        res1 = num1 + num2
        print(num1, "+", num2,"=",res1)
    elif operador == '-':
        res2 = num1 - num2
        print(num1, "-", num2,"=",res2)
    elif operador == '*':
        res3 = num1 * num2
        print(num1, "*", num2,"=",res3)
    elif operador == '**':
        res4 = num1 ** num2
        print(num1, "**", num2,"=",res4)
    elif operador == '//' and num2 != 0:
        res5 = num1 // num2
        print(num1, "//", num2,"=",res5)
    elif operador == '%' and num2 != 0:
        res6 = num1 % num2
        print(num1, "%", num2,"=",res6)
    else:
        print("ERROR")
    
def main():
    n1 = float(input())
    op = input()
    n2 = float(input())
    
    calculadora(n1,op,n2)
    
    

main()