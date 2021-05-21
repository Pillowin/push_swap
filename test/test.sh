#! /bin/bash

for i in `seq 1 5000`
do
    arg=`shuf -i 1-5000 -n 2000 `
    arg=`sed -z 's/\n/ /g' <<<"$arg" `
    ret=`./push_swap $arg`
    if [ "$ret" ]
    then
        error=`echo "$ret" | ./checker $arg 2>&1`
    else
        error=`echo -n "$ret" | ./checker $arg 2>&1`
    fi
    echo $error >>error
    if [[ $error != "OK" ]]
    then 
         echo $arg >>error
    fi
    ret=`echo "$ret" | wc -l`
    #ret2=`./push_swap2 $arg | wc -l`
    if [[ $ret -ge 0 ]]
    then
        echo " solved in $ret tries"
    fi
    #if [[ $ret2 -ge 0 ]]
    #then
    #    echo " solved in $ret2 tries" >> log2
    #fi
done
