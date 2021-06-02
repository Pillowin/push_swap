#! /bin/bash

read -p "Please entre the number of lists: " nb_lists
if ! [[ "$nb_lists" =~ ^[0-9]+$ ]]
then
	echo "Sorry positive integers only"
	exit 1
fi

read -p "Please entre the minimal number: " min
if ! [[ "$nb_lists" =~ ^[0-9]+$ ]]
then
	echo "Sorry positive integers only"
	exit 1
fi

read -p "Please entre the maximal number: " max
if ! [[ "$nb_lists" =~ ^[0-9]+$ ]]
then
	echo "Sorry positive integers only"
	exit 1
fi

if [ $min -ge $max ]
then
	echo "Max needs to be greater than min"
	exit 1
fi

for i in `seq 1 $nb_lists`
do
	arg=`shuf -i $min-$max`
	arg=`echo $arg | tr '\n' ' '`
	echo -n $arg
	ret=`./push_swap $arg`
	if [ "$ret" ]
	then
		error=`echo "$ret" | ./checker $arg 2>&1`
	else
		error=`echo -n "$ret" | ./checker $arg 2>&1`
	fi
	ret=`echo "$ret" | wc -l | tr -d '[:space:]'`
	echo " solved in $ret tries"
done
