#!/bin/bash
declare -a arr=("Violet" "Blue" "Green" "Red" "White")
COUNTER=0
PAR=""
for i in "$@" ; do
    echo "${arr[$COUNTER]} -> $i"
    PAR="$PAR --tab -t $i --profile ${arr[$COUNTER]}"
    COUNTER=$((COUNTER + 1))
done
gnome-terminal --maximize $PAR
