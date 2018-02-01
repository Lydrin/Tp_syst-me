#!/bin/bash

if [ \( $# -ne 1 \) -o \( ! -d "$1" \) ]; then
    echo "Argumentation Fault"
    exit 1
else
    for file in `ls $1`; do
        echo -n "$file : "
        eval "analyseFichierRep.sh $file $1"
        echo "-----------------------"
    done 
    exit 0
fi
