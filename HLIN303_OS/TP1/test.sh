#!/bin/bash
for i in $*
do
    if [ -e $i ]
    then
	echo $i
    fi
done
