#! /bin/bash

NC='\033[0m'	# No Color
RED='\033[0;31m'
GREEN='\033[0;32m'

read -p "Please enter the number of lists: " nb_lists 2>&1
if ! [[ "$nb_lists" =~ ^[0-9]+$ ]]
then
	echo "Sorry positive integers only"
	exit 1
fi

read -p "Please enter the minimal number: " min 2>&1
if ! [[ "$nb_lists" =~ ^[0-9]+$ ]]
then
	echo "Sorry positive integers only"
	exit 1
fi

read -p "Please enter the maximal number: " max 2>&1
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

av=0
ok=0
min_op=999999
max_op=0
for i in `seq 1 $nb_lists`
do
	arg=`shuf -i $min-$max`
	arg=`echo $arg | tr '\n' ' '`
	echo -n $arg
	ret=`./push_swap $arg`
	if [ "$ret" ]
	then
		error=`echo "$ret" | ./test/checker_linux $arg 2>&1`
	else
		error=`echo -n "$ret" | ./test/checker_linux $arg 2>&1`
	fi
	if [ "$error" = "KO" ]
	then
		echo -e "\t${RED}[KO]${NC}"
	else
		ret=`echo "$ret" | wc -l | tr -d '[:space:]'`
		echo -e "\t${GREEN}[OK]${NC} in $ret operations"
		av=$(($av + $ret))
		ok=$(($ok + 1))
		if [ "$ret" -lt "$min_op" ]
		then
			min_op=$ret
		fi
		if [ "$ret" -gt "$max_op" ]
		then
			max_op=$ret
		fi
	fi
done

if [ "$ok" -gt "0" ]
then
	echo "Average: $(($av/$ok)) operations"
fi
echo "Min: $min_op operations"
echo "Max: $max_op operations"
