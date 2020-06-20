
    name = name.replace('á','a')
    name = name.replace('é','e')
    name = name.replace('í','i')
    name = name.replace('ó','o')
    name = name.replace('ú','u')
    
    print(contar())
    pos1 = name.find(" ")
    pos2 = name.find(" ", pos1 + 1)

    nombre = name[:pos1]
    paterno = name[pos1+1:pos2]
    materno = name[pos2:]

    print(f'nombre = {nombre}')
    print(f'paterno = {paterno}')
    print(f'materno = {materno}')
