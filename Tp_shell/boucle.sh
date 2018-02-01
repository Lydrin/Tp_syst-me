#!/bin/bash
i=0
while ((1));do
    echo $i
    sleep 1
    i=`expr $i + 1`
done
