import os, sys,re

liste = os.popen('last')

users={}

for l in liste:
    res=re.search("(^[a-z.-]+).+([A-Z][a-z]{2} +\d+).+(\([0-9]{2}:[0-9]{2}\)$)",l)
    if(res and res.group(1) != "reboot"):
        user = res.group(1)
        date = res.group(2)
        tps = res.group(3)
        heureMin = tps.split(":")
        heureMin[0] = re.search("([0-9]{2})",heureMin[0]).group(1)
        heureMin[1] = re.search("([0-9]{2})",heureMin[1]).group(1)
        tps = int(heureMin[1]) + int(heureMin[0])*60
        if user in users:
            if date in users[user]:
                users[user][date].append(tps)
            else:
                users[user][date] = [tps]
        else:
            users[user] = {}
            users[user][date] = [tps]
            
for user in users:
    sys.stdout.write("L'utilisateur " + user + " s'est connecte le ")
    for date in users[user]:
        sys.stdout.write(" | " + date+" " + str(len(users[user][date])) + " fois pour des durees de : ")
        for tps in users[user][date]:
            sys.stdout.write(str(tps) + " min ")
    sys.stdout.write("\n")
