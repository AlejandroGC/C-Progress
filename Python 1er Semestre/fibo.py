def fibo(iN):
    v1 = 0
    v2 = 1
    temp = 1
    for i in range(0,iN):
        if temp <= iN:
            if temp == iN:
                print(f'{v1}')
                temp = temp + 1
            else:
                print(f'{v1}', end=',')
                v3 = v1 + v2
                v1 = v2
                v2 = v3
                temp = temp + 1

        
def main():
    iN = int(input())
    fibo(iN)

main()