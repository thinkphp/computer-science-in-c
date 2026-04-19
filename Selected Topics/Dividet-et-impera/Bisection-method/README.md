# Bisection Method — Theory & Implementation

## Overview

The bisection method is a numerical analysis technique for finding roots of continuous functions. It belongs to the **divide and conquer** family of algorithms (alongside binary search, merge sort, etc.) and is the first method taught in numerical analysis courses due to its simplicity and guaranteed convergence.

---

## The Problem

Given an equation **f(x) = 0**, find the value of x that satisfies it.

### Example used throughout

```
f(x) = x³ + x - 1 = 0
```

This equation has one real root at approximately **x ≈ 0.6823278...**

---

## Bolzano's Theorem (Intermediate Value Theorem)

The entire bisection method rests on this theorem:

> If **f** is continuous on **[a, b]** and **f(a) · f(b) < 0**, then there exists at least one **c ∈ (a, b)** such that **f(c) = 0**.

In plain terms: if the function is negative at one end and positive at the other, it must cross zero somewhere in between.

**Note:** Bernard Bolzano (1781–1848) was a Czech mathematician and philosopher. Not to be confused with Ludwig Boltzmann (the physicist known for thermodynamics).

---

## Prerequisites for Bisection

You must start from a **valid interval [a, b]** where:

```
f(a) · f(b) < 0
```

This is **your responsibility** — the algorithm assumes the interval is already valid.

### Example validation for f(x) = x³ + x - 1

```
f(0) = -1  < 0
f(1) = +1  > 0

f(0) · f(1) = -1 < 0  ✅  valid interval
```

---

## When Does Bisection Fail?

| Cause | Example |
|---|---|
| f > 0 or f < 0 everywhere (no real roots) | x² + x + 1 = 0 |
| Root of even order (touches zero, doesn't cross) | x² = 0 |
| Even number of roots in interval (same sign at endpoints) | (x−1)(x−2) on [0, 3] |
| Discontinuity inside the interval | 1/x on [−1, 1] |
| Complex roots only | x² + 1 = 0 |

### Special case: x² + x + 1 = 0

This equation has **no real roots** (discriminant Δ = 1 − 4 = −3 < 0). Its roots are complex:

```
x = (−1 ± i√3) / 2
```

For equations with only complex roots, bisection cannot be applied. Alternatives include:
- **Newton-Raphson in the complex domain**
- **Companion matrix + QR eigenvalue method**

---

## The Algorithm

### Core logic

At each step:

1. Compute the midpoint: `m = (a + b) / 2`
2. Evaluate `f(m)`
3. If `f(a) · f(m) < 0` → root is in **[a, m]**, set `b = m`
4. If `f(a) · f(m) > 0` → root is in **[m, b]**, set `a = m`
5. Repeat until error is small enough

### Why does the sign determine which half to keep?

```
Case: f(m) < 0

f(a) < 0    f(m) < 0    f(b) > 0
  |------------|------------|
  a            m            b

Sign change is between m and b → root is in [m, b]
```

```
Case: f(m) > 0

f(a) < 0    f(m) > 0    f(b) > 0
  |------------|------------|
  a            m            b

Sign change is between a and m → root is in [a, m]
```

The subinterval where **signs are opposite** is always kept — Bolzano guarantees the root is there.

---

## Stopping Condition

The algorithm stops when the error becomes smaller than a chosen tolerance **ε**:

```
(b - a) / 2 < ε
```

The error `(b - a) / 2` represents the **maximum distance** the true root can be from the midpoint `m`.

### Choosing ε

| ε | Correct decimal places | Use case |
|---|---|---|
| 1e-3 | 3 | quick estimate |
| 1e-6 | 6 | standard (most common) |
| 1e-9 | 9 | high precision |
| 1e-12 | 12 | near limit of `double` |

### Number of iterations needed

```
n ≥ log₂((b − a) / ε)
```

For interval [0, 1] and ε = 1e-6:
```
n ≥ log₂(1 / 0.000001) = log₂(1,000,000) ≈ 20 iterations
```

---

## Error Formula

After n iterations:

```
eₙ ≤ (b − a) / 2ⁿ
```

The error is **halved at every step** — this is why bisection converges slowly compared to Newton-Raphson (which converges quadratically), but it **always converges** if the starting interval is valid.

---

## Bisection as Divide and Conquer

Bisection follows the divide and conquer paradigm:

1. **Divide** — split [a, b] into [a, m] and [m, b]
2. **Conquer** — select only the relevant subinterval and recurse
3. **Combine** — the result of the subproblem is directly the final result (trivial)

The key distinction from algorithms like merge sort is that bisection **discards one half** at every step instead of solving both. This makes the recursion tree degenerate into a straight line.

```
Merge sort (both halves):       Bisection (one half):

        [...]                        [a, b]
        /   \                        /
    [...]  [...]                  [a, m]
    /  \   /  \                   /
   ..  .. ..  ..               [a, m']
                                /
                              ...
```

Binary search follows the same principle and is also classified as divide and conquer.

---

## Iterations for f(x) = x³ + x - 1 on [0, 1]

| n | a | b | m | f(m) | error |
|---|---|---|---|---|---|
| 1 | 0.000000 | 1.000000 | 0.500000 | −0.375000 | 0.500000 |
| 2 | 0.500000 | 1.000000 | 0.750000 | +0.171875 | 0.250000 |
| 3 | 0.500000 | 0.750000 | 0.625000 | −0.130859 | 0.125000 |
| 4 | 0.625000 | 0.750000 | 0.687500 | +0.013092 | 0.062500 |
| 5 | 0.625000 | 0.687500 | 0.656250 | −0.060974 | 0.031250 |
| 10 | ... | ... | 0.682373 | ... | 0.000976 |
| 20 | ... | ... | 0.682328 | ... | 0.000001 |

---

## C++ Implementation

```cpp
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return x*x*x + x - 1;
}

double bisectie(double a, double b, double eps = 1e-6) {
    if (f(a) * f(b) >= 0) {
        cout << "Error: f(a) and f(b) must have opposite signs!" << endl;
        return -1;
    }

    double m;
    while ((b - a) / 2.0 > eps) {
        m = (a + b) / 2.0;
        if (f(a) * f(m) < 0)
            b = m;
        else
            a = m;
    }
    return (a + b) / 2.0;
}

int main() {
    double root = bisectie(0.0, 1.0, 1e-6);
    cout << fixed << setprecision(8);
    cout << "Root: x = " << root << endl;
    cout << "Verification: f(" << root << ") = " << f(root) << endl;
    return 0;
}
```

### Key notes on `setw` (from `<iomanip>`)

- `setw(n)` sets the **minimum field width** for the next output only — it does not persist
- Default alignment is **right**; use `left` to align left
- Use `setfill(c)` to change the padding character (default is space)

```cpp
cout << left << setw(10) << "text" << "|";   // "text      |"
cout << right << setw(10) << "text" << "|";  // "      text|"
```

---

## Stopping Condition Variants

```cpp
// Variant 1 — interval width
while ((b - a) / 2.0 > eps)

// Variant 2 — function value close to zero
while (fabs(f(m)) > eps)

// Variant 3 — both conditions (safest)
while ((b - a) / 2.0 > eps && fabs(f(m)) > eps)
```

---

## Comparison with Other Methods

| Method | Convergence | Always converges? | Requires |
|---|---|---|---|
| Bisection | Linear (slow) | ✅ Yes | Valid interval [a,b] |
| Newton-Raphson | Quadratic (fast) | ❌ Not always | Good starting point x₀, f'(x) |
| Secant | Superlinear | ❌ Not always | Two starting points |
| Fixed-point | Linear | ❌ Not always | Contraction condition |

Bisection is preferred when **reliability matters more than speed**.

---

## Summary

```
1. Find [a, b] with f(a) · f(b) < 0     ← your job
2. Apply bisection                        ← the algorithm
3. Stop when (b - a) / 2 < ε            ← your precision
```

The bisection method will always find the root — provided you start from a valid interval.


### References 

- https://web.mit.edu/10.001/Web/Course_Notes/NLAE/node2.html
- https://www.geeksforgeeks.org/dsa/program-for-bisection-method/
- https://en.wikipedia.org/wiki/Bisection_method
- https://pythonnumericalmethods.studentorg.berkeley.edu/notebooks/chapter19.03-Bisection-Method.html
- https://ece.uwaterloo.ca/~dwharder/NumericalAnalysis/10RootFinding/bisection/complete.html
- https://people.clas.ufl.edu/kees/files/Bisection.pdf
