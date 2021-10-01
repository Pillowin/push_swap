# push_swap

## Summary
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

## Fixes

- Handle errors in `sa` `sb` and `ss`

## Todo

- ~~Implement small garbage collector~~
- ~~Implement data structure functions~~
- ~~Implement operations~~
- ~~Handle error cases~~
- ~~Parse arguments~~
- ~~Implement output list~~
- ~~Sort manualy for very small lists~~
- ~~Refactor output list of 5 numbers list~~
- ~~Merge list function~~
- ~~Refactor output list~~
- ~~Change set to only positive numbers with interval of 1~~
- ~~Quick sort~~

- ~~Find pivot intervall in order to know if we need to apply insertion or create new pivots~~

- Create new pivot for big chunks
	- ~~update pivots functions~~
	- ~~copy func to create pivots out of quick_sort.c~~
	- ~~restart same algo to create pivots~~
	=> ~~need to create struct for gc a b out ? in order to pass args~~
	- ~~intervall / 2~~
	- ~~find magic values~~

- ~~Creation de pivot~~
	- ~~push pivot at end of B~~
	- ~~push smaller in B~~
	- ~~push bigger at end of A~~

	- ~~push end of A at the begining of A~~
	- ~~push pivot (end of B) at begining of A~~

	- ~~new pivot in B~~
	- ~~push bigger in A~~
	- ~~push smaller at end of B~~
	- ~~push pivot at end of A~~

	- ~~push pivot at begining of A~~
	- ~~push smaller (in B) at begining of A => or Insertion sort~~

- ~~Insertion sort~~
	- ~~check if value is in A or B~~
		- ~~A~~
		- ~~while not interesting_value PB~~
		- ~~RA~~

		- ~~B~~
		- ~~find optimal RB or RRB~~
		- ~~PA~~
		- ~~RA~~

- Fix pivot calculation while creating new ones in A and B
- Fix find_intervall

- Play with magic number
- Norm all
- Test leaks

- Explicit files in Makefile
- Remove unneeded flags in Makefile
