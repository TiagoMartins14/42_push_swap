# 42_push_swap
Project developed during the Common Core @ 42 Porto

## Push_swap
Because Swap_push isn’t as natural

### Summary:
This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting.

## The rules

- You have 2 stacks: `a` and `b`.
- Initially:
  - `a` contains a random set of unique integers (positive and/or negative).
  - `b` is empty.
- Goal: Sort `a` in ascending order using a limited set of operations:
  sa : Swap top two elements of a (does nothing if < 2).
  sb : Swap top two elements of b.
  ss : sa and sb simultaneously.
  pa : Push top element from b to a.
  pb : Push top element from a to b.
  ra : Rotate a upwards (top becomes bottom).
  rb : Rotate b upwards.
  rr : ra and rb simultaneously.
  rra : Reverse rotate a (bottom becomes top).
  rrb : Reverse rotate b.
  rrr : rra and rrb simultaneously.

## 🛠️ Usage

### Requirements

The project is written in C language and needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the project**

To compile the project, go to its path and run:

For all mandatory functions:

```shell
$> make
```

For bonus functions:

```shell
$> make bonus
```

**2. Using it in your terminal**

It should be executed in this way:

```shell
$> ./push_swap <LIST_OF_INTEGERS>
```
