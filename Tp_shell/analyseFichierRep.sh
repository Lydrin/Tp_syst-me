#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Argumentation Fault"
    exit 1
else
    eval "analyseFichier.sh $2/$1"
    exit 0
fi
