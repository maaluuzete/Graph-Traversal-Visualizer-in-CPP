# Graph Traversal Visualizer in C++

*(Inspired by the exercise  
[Visualizador de Travessia de Grafos em Python](https://neps.academy/br/course/algoritmos-em-grafos/lesson/visualizador-de-travessia-de-grafos-em-c)  
from Neps Academy)*
This project was developed inspired by the **Visualizador de Travessia de Grafos CPP** exercise from **Neps Academy**, part of the Graph Algorithms course.  
It is an interactive desktop application written in **C++ using SDL3** that allows users to visually construct a graph and observe how **Breadth-First Search (BFS)** and **Depth-First Search (DFS)** traverse it step by step.
The main goal of the project is **educational visualization**, helping students understand how graph traversal algorithms explore a graph structure.  
The implementation follows a **competitive programming style**, with short variable names, minimal abstractions, and direct logic.

---

## Features
- Interactive creation of nodes by clicking on the window;
- Nodes are displayed as circles positioned in 2D space;
- Creation of **undirected edges** between nodes by selecting pairs of nodes;
- Multiple interaction modes:
  - Node creation;
  - Edge creation;
  - Start node selection;
- Step-by-step visualization of:
  - **BFS (Breadth-First Search)**;
  - **DFS (Depth-First Search)**;
- Animated traversal with a visible delay between visits;
- Color-based visualization of node states:
  - Default (unvisited);
  - Visited during traversal;
  - Start/selected node;
- Ability to clear the traversal visualization and run again;
- Save the current graph structure to a text file;
- Load a previously saved graph and continue interacting with it.

---

## Controls

| Key | Action |
|----|-------|
| `N` | Node creation mode |
| `E` | Edge creation mode |
| `S` | Select starting node |
| `B` | Run BFS traversal |
| `D` | Run DFS traversal |
| `C` | Clear traversal visualization |
| `W` | Save graph to `saved_graph.txt` |
Nodes and edges are created using **mouse clicks** depending on the current mode.

---

## How to Run

### Requirements
- **MSYS2 (UCRT64 environment)**  
- **SDL3** installed via `pacman`
- **CMake**
- **g++ (C++17 compatible)**

```bash
pacman -S mingw-w64-ucrt-x86_64-sdl3
git clone https://github.com/maaluuzete/Graph-Traversal-Visualizer-in-CPP.git
cd Graph-Traversal-Visualizer-in-CPP
mkdir build
cd build
cmake ..
cmake --build .
./app.exe
```
## Project Structure 
```
graph-traversal-visualizer/
│── CMakeLists.txt
│── main.cpp
│── graph.h
│── graph.cpp
|__ README.md
```