# Conway's Game of Life Simulation with Qt C++!
## Inspired by
[YouTube Video](https://www.youtube.com/watch?v=FWSR_7kZuYg&t=664s)

## Some Information about Conway's Game of Life
This game belongs to the category of cellular automata: in simple terms, it consists of a 2D grid of cells, each of which can have multiple states and a set of neighboring cells. The game has a few rules, and the differences in states, neighbors, and rules make the game interesting and diverse.

Conway's Game of Life has the following rules:
- Consider a 2D grid.
- Each cell has 2 states: Alive or Dead.
- Each cell has 8 neighbors (forming a 3x3 square around it). Cells on the edges of the grid have fewer neighbors due to the boundary of the grid.
- The rules are:
  - If a cell is alive and has fewer than 2 live neighbors, it dies (underpopulation).
  - If a cell is alive and has exactly 2 or 3 live neighbors, it remains alive (stable population).
  - If a cell is alive and has more than 3 live neighbors, it dies (overpopulation).
  - If a cell is dead and has exactly 3 live neighbors, it becomes alive (reproduction).
- With these simple rules, the game simulation can create fascinating patterns.

## Here is a video of the game with a pre-made seed
https://drive.google.com/file/d/1iaSUtV8i7cFnIjQpXJ8jJOmKepFL2Q5S/view?usp=sharing

## What This Game Represents
This game uses rules that mirror the survival and reproduction of populations. This means that if we have a good set of rules, we can simulate the development of a species or a population. Additionally, it looks quite interesting ฅ(^•ﻌ•^ฅ).

# Technical Information
- Framework: Qt 6.7.2
- IDE: Qt Creator 13.0.2 (Community)
