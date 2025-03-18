def print_fir_move(dest, n, crlf):
    print('FIR_MOVE(', end='')
    print(dest, end='')
    print(', ', end='')
    print(n, end='')
    
    if crlf == True:
        print(');')
    else:
        print('); ', end='')

count = 0
for i in range(384, 0, -1):
    if count >= 2:
        print_fir_move('delay', i,True)
        count = 0
    else:
        print_fir_move('delay', i,False)
        count +=1