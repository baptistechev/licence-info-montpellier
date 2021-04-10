for f in *
do
    if [ -f "$f" ]
    then
	for arg in $*
	do
	    if grep -q $arg "$f" 
	    then
		mv "$f" DUMP/
		break
	    fi
	done
    fi
done
	
    
