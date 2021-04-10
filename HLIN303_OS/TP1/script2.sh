#find -name "*.test" -exec mv {} DUMP/ \;
chemin=$1
extension=$2
find $chemin -name "*.$extension" -exec mv {} /home/e20180011339/Documents/TP1/DUMP \;
