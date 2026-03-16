*This project has been created as part of the 42 curriculum by smeza-ro.*

# Push_swap

## Description

Push_swap is a 42 School project that implements an algorithm to sort a stack of integers with a limited set of operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`). The goal is to produce a valid sequence of moves with the fewest possible operations, comparing efficiency across test cases.

This repository contains a C implementation using two stacks (`a` and `b`) and a set of helper functions for parsing, indexing, cost calculations, and sorting routines.

## Instructions

### Build

Run:

```
make
```

This creates the executable `push_swap`.

### Usage

```
./push_swap <num1> <num2> ... <numN>
```

Example:

```
./push_swap 3 2 5 1 4
```

The program prints a list of operations (one per line) that sorts the input stack.

### Notes

- Input must be integers. Duplicates and invalid values are not allowed.
- Behavior for out-of-range values depends on the current implementation and is not handled by this version.

## Resources

- 42 Push_swap subject (mandatory project instructions)
- Stack operation definitions and constraints from 42 curriculum
- C standard library references (`stdlib.h`, `unistd.h`, etc.)
- Articles and tutorials on greedy and divide-and-conquer sorting algorithms

### AI usage disclosure

AI (GitHub Copilot, Raptor mini) was used to:
- draft the README contents from user requirements
- summarize the project structure and usage

No production logic code was written by AI; the repository implementation is the student’s own code.

## Additional information

### Project approach

- Parse command-line arguments and build linked list stack nodes (`ft_lst` functions).
- Convert values to indexes for simplified comparison (`ft_index`).
- Compute rotation/push costs (`ft_cost`).
- Use optimized path for small stack sizes (`ft_tiny_sort`) and general sorting (`ft_sorting`).
- Implement operations in `ft_move`/`ft_push`/`ft_rotate`/`ft_rev_rotate`/`ft_swap`.

### Available targets

- `make` : compile
- `make clean` : remove object files
- `make fclean` : remove objects and executable
- `make re` : fclean + make
