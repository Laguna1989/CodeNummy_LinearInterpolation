# Overview

This is a Code Kata about linear interpolation.

# Theory

## Linear Interpolation

Linear interpolation is a useful method, e.g. for data analysis. When you have a set of data points, linear
interpolation allows you to get values for any value in between the actual data points.

![ani](https://user-images.githubusercontent.com/2394228/128511764-52235490-5a46-45e9-8e35-43ec5995c87d.gif)

The equation for linear interpolation is

```c++
y = y1 + (y2-y1)/(x2-x1) * (x-x1);
//  ^    [    slope    ]   [    ]
//  |                        ^-how far to the right is x from x0? 
//  y offset
```

Benefits:

- Easy to implement
- Works for functions that return scalar, vector or tensor values.

Drawbacks:

- Derivative is not smooth
- Only works for functions that take a scalar value as an input parameter.

# Exercise

## Implementation

Let's start with implementing the linear interpolation function. The function signature is given
in `src/linear_interpolation`

```
linear_interpolation(x1, x2, y1, y2, x)
```

The tests in `tests/linear_interpolation_input_range_test` and `tests/linear_interpolation_output_values_test`
will help you with the implementation.

### Boundary checks

As a first step, ensure that only values in the range `[x1, x2]` will yield a result. This Kata will not deal with
extrapolation. The expectation is that a value outside the range will result in an exception.

* Implement boundary value checks in the implementation so that the tests
  in `tests/linear_interpolation_input_range_test` pass.
* Also make sure that an exception is raised when `x1` and `x2` are not correctly ordered.

### The simple case: no interpolation needed

As a next corner case, take a look at the tests in `tests/linear_interpolation_output_values_test`.

The first two tests in this file will make sure that for x values already known, the respective y value will be
returned.

### The actual interpolation

The remaining tests in the file will test the actual interpolation for different scenarios.

# Further Reading

* [Explained JoshTheEngineer - Linear Interpolation (youtube video)](https://www.youtube.com/watch?v=Cvc-XalN_kk&ab_channel=JoshTheEngineer)
