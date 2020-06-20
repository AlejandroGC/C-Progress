def adivina(iN):
    a = 8
    r = 0
    c = 0
    for i in range(0,iN+1):
        if c <= iN:
            a = a + c
            if(c < iN):
                print(f'{a}', end=',')
            c = c + 1

    for j in range(0,iN+1):       
        if r != a:
            r = int(input())
            if(r == a):
                print(f'?Felicidades')
        
    
def main():
    iN = int(input())
    adivina(iN)
    
main()