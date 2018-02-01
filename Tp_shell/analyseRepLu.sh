#!/bin/bash

if [ $# -ne 0 ]; then
    echo "La commande s'appelle sans arguments"
    exit 1
else
    echo -n "Entrez le nom du dossier : "
    read dossier
    eval "analyseRep.sh $dossier"
    exit 0
fi
