import sys
from random import *

fichier="capitales.csv"
pays=[]
capitales=[]
fd = open(fichier,"r")
for l in fd.readlines():
    data=l.split(",")
    if len(data)==2:
        d=data[0].split("(")
        pays.append(d[0].rstrip())
        capitales.append(data[1].rstrip())
fd.close()

def game(question,reponse):
    score = 0
    for e in range(int(sys.argv[1])):
        rand = randint(0,len(question)-1)
        rep = input(str(question[rand]) + " : ")
        if(rep.lower() == reponse[rand].lower()):
            print("correct !")
            score +=1
        else:
            print("Faux !! La reponse est " + str(reponse[rand]))
        del question[rand]
        del reponse[rand]
    print("Votre score est : " + str(score))
    print("Votre pourcentage de bonne reponse est : " + str(score*100/int(sys.argv[1])) + "%")


if len(sys.argv)==2:
    print("Trouvez les capitales des pays suivants :")
    game(pays,capitales)
elif len(sys.argv)==3 and sys.argv[2]=="-r":
    print("Trouvez les pays ayant pour capitales les villes suivantes :")
    game(capitales,pays)
else:
    print("Entrez un nombre de questions");
