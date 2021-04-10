import sys

np = [2]
n = 3
while n<=int(sys.argv[1]):
    prem = True
    for e in np:
        if n%e == 0:
            prem = False
            break
    if prem:
        np.append(n)
    n+=1
print(np)
