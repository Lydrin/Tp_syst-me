#!/bin/bash

if [ $# -eq 0 ];then
    echo "Argumentation Fault"
    exit 1
fi

if [ -d $1 ];then
    for i in `ls $1`;do
        if [ -d $1/$i ];then
            $0 $1/$i
        else
            echo $i
        fi
    done
fi
exit 0
