import sys

input_text = sys.stdin.read()
expressions = input_text.splitlines()

for expr in expressions:
    expr = expr.strip() 
    if expr == '': 
        continue
    result = eval(expr)  
    if result.is_integer():
        print(f'{int(result)} 1')
    else:
        for i in range(1, 4001):
            if (result * i).is_integer():
                print(f"{int(result * i)} {i}")
                break
