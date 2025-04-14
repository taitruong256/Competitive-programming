def xoa(s):
    return ''.join([x for x in s.lower() if x not in '-_;'])
a=xoa(input())
b=xoa(input())
c=xoa(input())
tohop=[a+b+c, a+c+b, b+a+c, b+c+a, c+a+b, c+b+a]
for _ in range(int(input())):
    print('ACC' if xoa(input()) in tohop else 'WA')
