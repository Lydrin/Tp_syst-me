#!/bin/bash
if [ $# -eq 0 ];then
    echo "Argumentation Fault!"
    exit 1
fi


for i in `ls $1`;do
    if [ -d $i ];then
        cd $i
        $0 . 
    else 
        echo $i
    fi
done
