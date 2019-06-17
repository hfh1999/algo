#!/bin/bash
function count
{
    for file in $(ls)
    do
        if [ -d $file ]  # get the lines of this dir file 
        then
            cd $file
            count
        else
            if echo $file|grep -Eq ".c$|.h$"
            then
                echo $file
                count=$(wc -l $file|awk '{print $1}')
                sum=$(( $count + $sum ))           # count the lines
            fi
        fi
    done
    cd ..
    return
}

sum=0
count
echo "there are $sum lines C  in this directory"
