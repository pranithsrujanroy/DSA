x = input()
a = [0,0,0,0,0,0,0,0,0,0]
for i in x:
    k = int(i)
    a[k] = a[k]+1
for i in list(range(10)):
    print(str(i)+' '+str(a[i]))