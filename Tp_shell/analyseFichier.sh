#!/bin/bash
if [ $# -ne 1 ]
    then
    echo "Et l'argument tu le mets ou ?"
    exit 1
fi
if [ -f "$1" ]; then 
    echo "Ceci est un fichier"
else 
    if [ -d "$1" ]; then 
        echo "Ceci est un dossier"
    else
        echo "Ceci n'est ni un fichier ni un dossier"
        exit 1
    fi
fi
exit 0
