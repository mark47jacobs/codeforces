def check(g):
    for x in g:
        if x < 0:
            return True
    else:
        return False
    
def applyall(d):
    k = []
    global v
    for x in d:
        y = x-v
        k.append(y)
    return k
    

[n,v] = [int(x) for x in input().split(" ")]
l = []

for i in range(n):
    temp = [int(x) for x in input().split(" ")]
    l.append(temp)
    
counter = 0
dealers = []

for i in range(len(l)):
    temp = applyall(l[i][1:])
    if check(temp):
        dealers.append(i+1)
    
print(len(dealers))
for x in dealers:
    print(x,end=" ")

    
        
    
