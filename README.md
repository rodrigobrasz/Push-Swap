*This project has been created as part of the 42 curriculum by rodcaeta*

# DESCRIPTION
The Push Swap project is the first project that introduces the implementation of a sorting algorithm with a minimal number of operations to sort a given set of numbers. I chose the Radix Sort algorithm due to its efficiency in achieving faster results compared to other sorting algorithms.

### How RADIX works?

Radix Sort is a non-comparative sorting algorithm that processes numbers digit by digit (or bit by bit). In this implementation:

- Numbers are sorted by their binary representation
- Processing starts from the least significant bit to the most significant bit
- For each bit position:
  - Numbers with bit `0` → push to stack *b*
  - Numbers with bit `1` → rotate in stack *a*
- After processing each bit, all numbers are moved back to stack *a*

 ## RULES:
 ---
- You have **2 stacks** named `a` and `b`
  - Stack **a** contains a random amount of negative and/or positive numbers
  - Stack **b** is empty
- Sort the numbers in stack **a** in ascending order using the minimum number of operations

---
**Swap**
| Command | Description |
|---------|-------------|
| `sa` | Swap the first 2 elements at the top of stack **a**<br>Do nothing if there is only one or no elements |
| `sb` | Swap the first 2 elements at the top of stack **b**<br>Do nothing if there is only one or no elements |
| `ss` | Execute `sa` and `sb` simultaneously |

**Push**
| Command | Description |
|---------|-------------|
| `pa` | Take the first element from stack **b** and push it to stack **a**<br>Do nothing if **b** is empty |
| `pb` | Take the first element from stack **a** and push it to stack **b**<br>Do nothing if **a** is empty |

**Rotate**
| Command | Description |
|---------|-------------|
| `ra` | Shift all elements of stack **a** up by 1<br>The first element becomes the last |
| `rb` | Shift all elements of stack **b** up by 1<br>The first element becomes the last |
| `rr` | Execute `ra` and `rb` simultaneously |

**Reverse Rotate**
| Command | Description |
|---------|-------------|
| `rra` | Shift all elements of stack **a** down by 1<br>The last element becomes the first |
| `rrb` | Shift all elements of stack **b** down by 1<br>The last element becomes the first |
| `rrr` | Execute `rra` and `rrb` simultaneously |

---
---

# INTRODUCTION

## How to compile

```bash
make (Rreate the executable)
```
```bash
make clean/fclean (Remove the objects files and Remove the executable)
```
```bash
make re (Rebuild the program)
```


## How to use

The program accepts numbers in three different formats:

```bash
./push_swap "9 7 2 4 1 5"
```

```bash
./push_swap "9" "7" "2" "4" "1" "5"
```

```bash
./push_swap 9 7 2 4 1 5
```


# RESOURCES
- 