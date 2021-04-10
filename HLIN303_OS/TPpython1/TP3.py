import os, sys

ext={}
nbFichier=0

def parcours(rep):
    global nbFichier,ext
    liste=os.listdir(rep)
    for fichier in liste:
        if os.path.isdir(rep+'/'+fichier):
            parcours(rep+'/'+fichier)
        else:
            nbFichier+=1
            ex=fichier.split(".")[-1]
            if(ex==fichier):
                ex="Sans extension"
            if(ex in ext):
                ext[ex]+=1
            else:
                ext[ex]=1


parcours(sys.argv[1])
for e in ext:
    print(e + " : " + str(ext.get(e)))
print("TOTAL : " + str(nbFichier))
