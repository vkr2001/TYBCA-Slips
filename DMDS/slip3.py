import numpy as np

x = np.array([0,1,2,3,4,5,6,7,8,9,11,13])
y = np.array([1, 3, 2, 5, 7, 8, 8, 9, 10, 12,16, 18])

# calculate mean of x and y
mean_x = np.mean(x)
mean_y = np.mean(y)

# calculate covariance of x and y
cov_xy = np.sum((x - mean_x) * (y - mean_y)) / (len(x) - 1)

# calculate variance of x
var_x = np.sum((x - mean_x)**2) / (len(x) - 1)

# calculate slope (b1)
b1 = cov_xy / var_x

# calculate intercept (b0)
b0 = mean_y - b1 * mean_x

# print estimated coefficients
print("Estimated coefficients:")
print("B0:", b0)
print("B1:", b1)