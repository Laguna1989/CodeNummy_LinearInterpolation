# Overview

This is a Code Kata about linear interpolation.

# Theory

## Linear Interpolation

TODO Create picture in inkscape


The equation for linear interpolation is
```c++
y = y0 + (y1-y0)/(x1-x0) * (x-x0);
//  ^    [ slope       ]   [    ]
//  |                       ^- how far is x in between x0 and x1? 
//  y offset
```

# Exercise

## Implementation

Let's start with implementing the linear interpolation function. The function signature is given
in `src/linear_interpolation.hpp`

```
template <typename T>
T linear_interpolation(T const x0, T const x1, T const y0, T const y1, T const x)
```

The tests in (TODO) will help you with the implementation.

### Boundary checks

As a first step, it shall be ensured that only values in the range `[x0, x1]` will yield results. This Kata will not
deal with extrapolation. The expectation is that a value outside the range will result in an invalid_argument exception.

* Implement boundary value checks in the implementation so that the tests in (TODO) pass.
* Also make sure that an exception is raised when `x0` and `x1` are not correctly ordered.

### The simple case: no interpolation needed

As a next corner case, take a look at the tests in (TODO).

The first two tests in this file will make sure that for x values already known, the respective y value will be
returned.

### The actual interpolation

# Further Reading

* [Explained JoshTheEngineer - Linear Interpolation (youtube video)](https://www.youtube.com/watch?v=Cvc-XalN_kk&ab_channel=JoshTheEngineer)
