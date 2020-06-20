def mayor():
    iV = int(input())
    mayor = 0
    
    if iV == 0:
        return print("npv")
    else:
        while iV != 0:
            iV = int(input())
            if mayor < iV:
                mayor = iV
    if iV == 0:       
        print(f'{mayor}')

def main():
    mayor()
    

main()