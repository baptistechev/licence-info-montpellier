import os, sys

nbFichier=0

def parcours(rep):
    global nbFichier,ext
    liste=os.listdir(rep)
    for fichier in liste:
        if os.path.isdir(rep+'/'+fichier):
            parcours(rep+'/'+fichier)
        else:
            if(fichier!="Huffman" and fichier!="archiveur.py"):
                print("Compression de "+fichier)
                os.system('./Huffman '+rep+'/'+fichier)
                nbFichier+=1
                os.system('rm '+rep+'/'+fichier)

parcours(sys.argv[1])
print("Nombre de fichiers compresses : " + str(nbFichier))
