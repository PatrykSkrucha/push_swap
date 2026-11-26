# push_swap

> Sort a list of integers using **two stacks and a tiny instruction set**, in as few moves as possible.

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![Algorithms](https://img.shields.io/badge/topic-sorting_algorithms-555555?style=flat)

## About

Numbers start on stack **a**, stack **b** is empty. `push_swap` prints the shortest sequence of
operations it can find that leaves stack **a** sorted. The bonus `checker` program reads those
operations and checks that they really sort the input.

| Operation | Effect |
|---|---|
| `sa` `sb` `ss` | swap the top two elements |
| `pa` `pb` | push the top element to the other stack |
| `ra` `rb` `rr` | rotate up (first element becomes last) |
| `rra` `rrb` `rrr` | rotate down (last element becomes first) |

## Algorithm

- **2–3 numbers**: a hard-coded optimal sort
- **more numbers**: a cost-based (greedy) approach
  1. elements are pushed from **a** to **b**, each time choosing the one that is cheapest to move into its sorted place
  2. once only three remain in **a**, they are sorted directly
  3. elements are pushed back from **b** to **a**, again picking the cheapest combination of rotations each time, and using `rr`/`rrr` to rotate both stacks at once
  4. stack **a** is finally rotated with `ra` or `rra` (whichever is shorter) so the smallest number is on top

Input is validated: non-numbers, duplicates and values outside the `int` range print `Error`.

## Build & run

```bash
make            # builds push_swap
make bonus      # builds checker

./push_swap 3 2 5 1 4
ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG   # OK
./push_swap $ARG | wc -l                                                          # number of moves
```

---

<sub>Part of the <a href="https://www.codam.nl/">Codam</a> (42 network) curriculum.</sub>
