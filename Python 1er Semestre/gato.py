tablero = [('','','')('','','')('','','')]

j1 = input('''
            1|2|3
            4|5|6
            7|8|9
''')
j2 = input('''
            1|2|3
            4|5|6
            7|8|9
''')

j1 = j1.replace('1','1:1')
j2 = j2.replace('1','1:1')
j1 = j1.replace('2','1:2')
j2 = j2.replace('2','1:2')
j1 = j1.replace('3','1:3')
j2 = j2.replace('3','1:3')
j1 = j1.replace('4','2:1')
j2 = j2.replace('4','2:1')
j1 = j1.replace('5','2:2')
j2 = j2.replace('5','2:2')
j1 = j1.replace('6','2:3')
j2 = j2.replace('6','2:3')
j1 = j1.replace('7','3:1')
j2 = j2.replace('7','3:1')
j1 = j1.replace('8','3:2')
j2 = j2.replace('8','3:2')
j1 = j1.replace('9','3:3')
j2 = j2.replace('9','3:3')

