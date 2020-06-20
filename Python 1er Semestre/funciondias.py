def nombreMes(m):
    if m == 1:
        return "Enero"
    elif m == 2:
        return "Febrero"
    elif m == 3:
        return "Marzo"
    elif m == 4:
        return "Abril"
    elif m == 5:
        return "Mayo"
    elif m == 6:
        return "Junio"
    elif m == 7:
        return "Julio"
    elif m == 8:
        return "Agosto"
    elif m == 9:
        return "Septiembre"
    elif m == 10:
        return "Octubre"
    elif m == 11:
        return "Noviembre"
    elif m == 12:
        return "Diciembre"
    else:
        return "Mes Incorrecto"


def diasMes(m):
    
    #If de validacion de dias dependiendo del mes
    if m > 0 and m <= 12:
        if  m == 2:
            return 28
        elif m == 4 or m == 6 or m == 9 or m == 11:
            return 30
        else:
            return 31
    else:
        return 0

def main():
    #Leer el mes
    mes = int(input("Teclea un mes:"))
    
    #Llamar a la funcion diasmes
    dias_mes = diasMes(mes)
    
    #Llamar a la funcion nombremes
    nombre_mes = nombreMes(mes)
    
    #Desplegar la cantidad de dias del mes
    if dias_mes == 0:
        print("El mes es incorrecto")
    else:
        print("El mes de", nombre_mes, "tiene", dias_mes, "dias.")

#Llamar la funcion main
main()