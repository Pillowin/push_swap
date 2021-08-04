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

- Find pivot intervall in order to know if we need to apply insertion or create new pivots

- Create new pivot for big chunks
	- move func to create pivots out of quick_sort.c
	- intervall / 2
	- restart same algo to create pivots
	- need to : update pivots functions and find magic values

- Insertion sort
	- check if value is in A or B
	- find best logic to retrieve value

- Norm all
- Test leaks

- Explicit files in Makefile
- Remove unneeded flags in Makefile
