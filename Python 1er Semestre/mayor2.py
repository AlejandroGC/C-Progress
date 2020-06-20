def mayor(iN):
    iK = 1
    mayor = 0
    
    if iN <= 0:
        print("npv")
    for i in range(iN):
        if iK <= iN:
            iV = int(input())
            if mayor < iV:
                mayor = iV
                
            iK = iK + 1
            
    if iK <= (iN + 1):
        print(f'{mayor}')

def main():
    iN = int(input())
    
    mayor(iN)
    

main()