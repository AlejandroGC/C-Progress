def mayor(iN):
    iK = 1
    menor = 1
    
    if iN <= 0:
        print("npv")
    for i in range(iN):
        if iK <= iN:
            iV = int(input())
            if menor > iV:
                menor = iV
                
            iK = iK + 1
            
    if iN > 0:
        print(f'{menor}')

def main():
    iN = int(input())
    
    mayor(iN)
    

main()