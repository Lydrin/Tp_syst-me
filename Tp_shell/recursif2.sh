#!/bin/bash

recurse(){
    for i in `ls $1`;do
        if [ -d $i ];then
            echo "dir: $i"
            recurse $i
        elif [ -f $i ];then
            echo "file: $i"
        fi
    done
}

recurse .
