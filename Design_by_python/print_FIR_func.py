def print_fir_func(dest, n, h, crlf):
    print('FIR_MAD(', end='')
    print(dest, end='')
    print(', ', end='')
    print(n, end='')
    print(', ', end='')
    print(h, end='')
    
    if crlf == True:
        print(');')
    else:
        print('); ', end='')

count = 0
for i in range(384):
    if count >= 2:
        print_fir_func('temporary', i, 'h',True)
        count = 0
    else:
        print_fir_func('temporary', i, 'h',False)
        count +=1