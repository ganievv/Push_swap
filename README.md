# Push_swap

## Table of Contents
- [Project Overview](#project-overview)
- [Installation](#installation)
- [Usage](#usage)
- [Example](#example)
- [Mandatory Part Details](#mandatory-part-details)
- [Testing](#testing)

## Project Overview
The Push_swap project is a sorting algorithm challenge where you must sort data on a stack using a limited set of instructions and the smallest possible number of operations. The project emphasizes algorithm complexity and optimization.

## Installation
To build the project, simply clone this repository and run `make`:
```bash
git clone https://github.com/ganievv/Push_swap.git
cd Push_swap
make
```

## Usage
To run the program, provide a list of integers as arguments. Example:
```bash
./push_swap 2 1 3 6 5 8
```
The program will output a sequence of operations to sort the list.

### Error Handling
If there is an error, the program will print `Error` to the standard error output. Errors include:
- Non-integer arguments
- Duplicate numbers
- Arguments larger or smaller than an integer

## Example
```bash
$> ./push_swap 2 1 3 6 5 8
pb
pb
rrb
pb
sa
pa
pa
pa
```

## Mandatory Part Details
- **Stack Operations**:
  - `sa` - Swap the first 2 elements at the top of stack `a`. Do nothing if there is only one or no elements.
  - `sb` -  Swap the first 2 elements at the top of stack `b`. Do nothing if there is only one or no elements.
  - `ss` - `sa` and `sb` at the same time.
  - `pa` - Take the first element at the top of `b` and put it at the top of `a`. Do nothing if `b` is empty.
  - `pb` - Take the first element at the top of `a` and put it at the top of `b`. Do nothing if `a` is empty.
  - `ra` - Rotate `a` (shift all elements up by one). The first element becomes the last one.
  - `rb` - Rotate `b` (shift all elements up by one). The first element becomes the last one.
  - `rr` - `ra` and `rb` at the same time.
  - `rra` - Reverse rotate `a` (shift all elements down by one). The last element becomes the first one.
  - `rrb` - Reverse rotate `b` (shift all elements down by one). The last element becomes the first one.
  - `rrr` - `rra` and `rrb` at the same time.

- **Program Goals**:
  - Display the smallest possible set of instructions to sort the stack.

## Testing
To validate your solution, you can use:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```
This command will check if the output of `push_swap` sorts the provided list.
