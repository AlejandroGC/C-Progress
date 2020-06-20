def pi():
    iN = int(input())
    iK = 1
    aprox = 0
    for i in range(0,iN):
        if(iK <= iN*2-1):
            if(iK%4 == 1):
                aprox = aprox + 1/iK
            else:
                aprox = aprox - 1/iK
            iK = iK + 2
        
    print(f'{4*aprox}')
    
def main():
    pi()

main()