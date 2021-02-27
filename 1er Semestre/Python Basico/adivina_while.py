def adivina(iN):
    a = 8
    r = 0
    c = 0
    while c <= iN:
        a = a + c
        if(c < iN):
            print(f'{a}', end=',')
        c = c + 1

        
    while r != a:
        r = int(input())
        if(r == a):
            print(f'?Felicidades')
    
    
def main():
    iN = int(input())
    adivina(iN)
    
main()