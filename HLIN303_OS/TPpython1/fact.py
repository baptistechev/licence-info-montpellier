import sys

if len(sys.argv)!=2:
    print("Renseignez un seul arguments")
else:
    try:
        i=int(sys.argv[1])
    except:
        print(str(sys.argv[1]) + " n'est pas un nb !!")
        sys.exit()

    if(i<0):
        print(str(i) + " est negatif !!")
        sys.exit()

    fact=1
    for e in range(i):
        fact*=i-e

    print(fact)
        
        
