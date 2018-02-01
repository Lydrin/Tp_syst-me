#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Argumentation fault !" 
    exit 1
fi

if [ -d $1 ]; then
    k=0
    for i in `ls $1`; do
        k=`expr $k + 1`
    done
    echo "Il y a $k elements dans le dossier"
fi
