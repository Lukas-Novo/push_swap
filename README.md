*This project has been created as part of the 42 curriculum by lnovotny*

# Description
The **Push_swap** project is a highly effective algorithm project that focuses on sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions.

The goal is to explore, adapt, and implement various sorting algorithms to find the most optimized solution. The program receives a list of integers and outputs a sequence of instructions that, when executed, results in a sorted stack.

### Error Handling
If an invalid input is detected, the program will display **"Error"** on the standard error output. This includes:
*   Non-numeric parameters.
*   Numbers that exceed integer limits (Overflow/Underflow).
*   Duplicate numbers in the input.
*   Memory allocation failures.

### Allowed Instructions

At the beginning, all numbers are added to **Stack A** in their original order, while **Stack B** starts empty. The goal is to have all numbers sorted in ascending order in Stack A at the end of the process, while **Stack B** ends empty. During the sorting process, numbers are moved between the stacks A and B.

| Instruction | Name | Description |
| :--- | :--- | :--- |
| **sa** | Swap A | Swaps the first 2 elements at the top of stack A. |
| **sb** | Swap B | Swaps the first 2 elements at the top of stack B. |
| **ss** | Swap Both | Executes `sa` and `sb` simultaneously. **Not used in this project** |
| **pa** | Push A | Takes the first element at the top of B and puts it at the top of A. |
| **pb** | Push B | Takes the first element at the top of A and puts it at the top of B. |
| **ra** | Rotate A | Shifts up all elements of stack A by 1 (First becomes last). |
| **rb** | Rotate B | Shifts up all elements of stack B by 1 (First becomes last). |
| **rr** | Rotate Both | Executes `ra` and `rb` simultaneously. **Not used in this project** |
| **rra** | Reverse Rotate A | Shifts down all elements of stack A by 1 (Last becomes first). |
| **rrb** | Reverse Rotate B | Shifts down all elements of stack B by 1 (Last becomes first). |
| **rrr** | Reverse Rotate Both | Executes `rra` and `rrb` simultaneously. **Not used in this project** |

# Instructions
You can manage the project using the provided **Makefile**:

*   `make` – Compiles the `push_swap` program and creates object files.
*   `make clean` – Deletes all object files.
*   `make fclean` – Deletes all object files and the `push_swap` executable.
*   `make re` – Performs a full re-compilation (`fclean` followed by `make`).

The program accepts integers as arguments. These can be provided as individual arguments, as a single quoted string of numbers, or a combination of both.

```bash
# Example 1: Individual arguments
./push_swap 2 1 3 6 5 8

# Example 2: Single string argument
./push_swap "2 1 3 6 5 8"

# Example 3: Mixed arguments
./push_swap 2 1 "3 6 5" 8
```

To run the program with numbers in the input file and pass the output to the checker, the following command can be used:

`./push_swap $(cat input) | ./checker_linux $(cat input)`

# Resources

AI was used mainly for educational purposes (explaining the concepts of sorting algorithms) and code debugging

https://www.geeksforgeeks.org/dsa/introduction-to-sorting-algorithm/  
https://en.wikipedia.org/wiki/Sorting_algorithm  
https://codepen.io/ahkoh/full/bGWxmVz
