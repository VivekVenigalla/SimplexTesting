# SimplexTesting

A small C++20 engine for topological data analysis (TDA), built as part of a UGA Directed Reading Program on applying TDA to financial markets. The goal is to turn a cloud of points in R^n into a simplicial complex and compute its boundary operators, ending with a check of the theorem that applying the boundary twice gives zero (∂∘∂ = 0).

## Status

| Component | State |
|---|---|
| `Point` (vector in R^n) | Done |
| `PointCloud` | Done |
| `Simplex` | Done |
| `SimplicialComplex` | Done, except Vietoris-Rips construction (`buildRips`) |
| Boundary operator and ∂∘∂ = 0 check | Planned |

## Components

**Point** ([point.hpp](include/point.hpp)): a point in R^n backed by a `std::vector<double>`. Supports `+`, `-`, scalar `*`, Euclidean distance (`getDist`) and printing. Mismatched dimensions throw `std::invalid_argument`.

**PointCloud** ([pointCloud.hpp](include/pointCloud.hpp)): a collection of `Point`s of one dimension. `hFunc(pt)` returns the distance from `pt` to the nearest point in the cloud and throws on an empty cloud.

**Simplex** ([simplex.hpp](include/simplex.hpp)): a k-simplex stored as a sorted list of k+1 distinct vertex indices into a point cloud, so `{2,0,1}` and `{0,1,2}` are the same simplex. It is purely combinatorial and holds no coordinates.
- `getDim()`: number of vertices minus 1
- `getFaces()`: the k+1 faces, where face i drops vertex i. This ordering is what gives the boundary its sign (-1)^i.
- `operator==` and `operator<` so simplices work in `std::set` and `std::map`

**SimplicialComplex** ([simplicialComplex.hpp](include/simplicialComplex.hpp)): a `std::set<Simplex>` that is always closed under taking faces. `addSimplex` inserts a simplex and, recursively, all of its faces. Also provides `contains`, `getDim`, `getSimplices(d)`, `countSimplices(d)`, `size` and `printComplex`.

## Explorations so far

- **Simplices and faces.** A triangle `{0,1,2}` has faces `[1,2]`, `[0,2]`, `[0,1]`. A tetrahedron `{0,1,2,3}` has 4 triangles, each with 3 edges.
- **Complexes are subsets of the power set.** Adding only the tetrahedron produces all 2^4 - 1 = 15 nonempty subsets of 4 points. Real complexes keep only the subsets that meet some condition, such as pairwise distance at most epsilon.
- **Closure.** Adding a face that already exists changes nothing. Adding a simplex pulls in all of its faces.
- **Holes.** A triangle built from only its three edges is a loop (dimension 1, 6 simplices). Adding the triangle fills it (dimension 2, 7 simplices). This is the kind of feature homology detects.

## Planned work

- **Chains and the boundary operator:** a `Chain` class mapping simplices to integer coefficients, with ∂σ = Σ (-1)^i · face_i extended linearly, and a check that ∂∘∂ = 0 on every simplex of dimension 2 or more in a complex.
- **Later:** boundary matrices, Betti numbers and persistent homology.

## Build and run

Requires CMake 3.20 or newer and a C++17 compiler.

```bash
cmake -S . -B build
cmake --build build
./build/runny
```

`src/main.cpp` is the test driver. It prints simplices and faces for a triangle and a tetrahedron, builds complexes from them, and exercises `Point` and `PointCloud`.

## Layout

```
include/   headers (point, pointCloud, simplex, simplicialComplex)
src/       implementations and main.cpp
CMakeLists.txt
```
