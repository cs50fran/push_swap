*This project has been created as part of the 42 curriculum by fdinis-d.*

# 🌀 push_swap

An efficient stack-sorting program using a restricted set of stack operations, crafted for the 42 curriculum.

---

## 📝 Overview

**push_swap** is a project from 42 School that tasks you with sorting a stack of integers using only two stacks (`a` and `b`) and a limited set of moves, aiming to use as few operations as possible.

### Objective
Arrange a randomly ordered stack of integers in ascending order on stack `a` with the minimum number of allowed operations.

### Project Rules
- Start with stack `a` filled with random integers; stack `b` is empty.
- Only 11 specific stack operations are permitted.
- The challenge is to minimize the total number of moves.

### Permitted Operations

| Command | Function |
|---------|----------|
| `sa`    | Swap the top two elements of stack `a` |
| `sb`    | Swap the top two elements of stack `b` |
| `ss`    | Perform `sa` and `sb` simultaneously |
| `pa`    | Move the top element from `b` to `a` |
| `pb`    | Move the top element from `a` to `b` |
| `ra`    | Rotate stack `a` upwards |
| `rb`    | Rotate stack `b` upwards |
| `rr`    | Rotate both stacks upwards |
| `rra`   | Rotate stack `a` downwards |
| `rrb`   | Rotate stack `b` downwards |
| `rrr`   | Rotate both stacks downwards |

### Sorting Strategy

This solution uses a cost-based approach inspired by the "Turk" method:

- **Small stacks (≤5 elements):** Uses direct, optimal solutions.
- **Larger stacks:** 
  - Moves all but three elements to stack `b`, always choosing the least costly move.
  - Sorts the remaining three in stack `a`.
  - Reintegrates elements from `b` to `a` in their correct positions.
  - Final rotation ensures the smallest value is at the top.

### Performance Benchmarks

| Stack Size | Typical Ops | 42 Target |
|------------|-------------|-----------|
| 3          | ≤ 2         | ≤ 3       |
| 5          | ≤ 8         | ≤ 12      |
| 100        | ~560        | < 700     |
| 500        | ~5100       | ≤ 5500    |

---

## ⚙️ Getting Started

### Requirements

- CC
- Make utility
- Unix-like OS (Linux/macOS)

### Build Instructions

```bash
# Clone this repository
git clone <your_repo_url>
cd push_swap

# Compile the program
make

# Remove object files
make clean

# Remove all build files and binary
make fclean

# Rebuild everything
make re

### Running the Program

```bash
# Example usage
./push_swap 3 2 1

# Using a quoted string
./push_swap "5 4 3 2 1"

# Mixed input
./push_swap 5 "4 3" 2 1

# Count the number of operations
./push_swap 3 2 1 | wc -l

# Test with a checker (if available)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
```

### Sample Outputs

```bash
# Sorting 3 numbers
$ ./push_swap 2 1 3
sa

# Sorting 5 numbers
$ ./push_swap 5 4 3 2 1
rra
pb
rra
pb
sa
rra
pa
pa

# Count operations for 100 random numbers
$ ARG=$(shuf -i 1-100 -n 100 | paste -sd' ' -); ./push_swap $ARG | wc -l
     562
```

---

## 🗂️ Directory Layout

```
push_swap/
├── Makefile
├── README.md
├── includes/
│   └── push_swap.h
├── src/
│   ├── main.c
│   ├── operations/
│   ├── sorting/
│   ├── parsing/
│   ├── stack/
│   └── utils/
├── libft/
```

---

## 🔗 Useful Links

- [Push Swap Project Guide](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Turk Algorithm Details](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Oceano Push_swap](https://www.youtube.com/watch?v=OaG81sDEpVk&t=3573s&pp=ygUQb2NlYW5vIHB1c2hfc3dhcA%3D%3D)
- [CS 50 Lecture 5: Data Structures](https://www.youtube.com/watch?v=PmAI76OGE_E&t=4544s&pp=ygUeZGF0YSBzdHJ1Y3R1cmVzIGNzNTAgbGVjdHVyZSA1)

---

## 🤖 AI & Tools Disclosure

AI tools (like GitHub Copilot) were used for:
- Organizing code and files
- Suggesting optimizations for the sorting algorithm
- Spotting edge cases in input handling
- Drafting documentation
- Ensuring code style compliance

All code was written, reviewed, and tested by the author, with a full understanding of the logic and requirements.

---

## ✅ Checklist

- [x] Compiles with `-Wall -Wextra -Werror`
- [x] No memory leaks
- [x] Handles edge cases (empty, single, sorted input)
- [x] Robust error handling (duplicates, invalid input, overflow)
- [x] Norminette compliant
- [x] 100 numbers: < 700 ops
- [x] 500 numbers: ≤ 5500 ops

---

## 📜 License

This project is for educational purposes at 42 School. Please use as inspiration, not for direct copying.

---

*Created with dedication at 42 Lisboa*