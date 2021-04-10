import os, sys

nbFichier=0

def parcours(rep):
    global nbFichier,ext
    liste=os.listdir(rep)
    for fichier in liste:
        if os.path.isdir(rep+'/'+fichier):
            parcours(rep+'/'+fichier)
        else:
            if(fichier.split(".")[-1]=="cp"): 
                print("Decompression de "+fichier)
                os.system('./Decompresseur '+rep+'/'+fichier)
                nbFichier+=1
                os.system('rm '+rep+'/'+fichier)

parcours(sys.argv[1])
print("Nombre de fichiers decompresses : " + str(nbFichier))
