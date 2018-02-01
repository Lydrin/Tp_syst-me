#!/bin/bash

if [ $# -eq 0 ]; then
   exit 1
fi

for i in $@; do
    echo $i
done
exit 0
