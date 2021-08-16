
def linear_interpolation(x1, x2, y1, y2, x):
    if x < x1 or x > x2:
        raise Exception
    return y1 + (y2-y1)/(x2-x1) * (x-x1)