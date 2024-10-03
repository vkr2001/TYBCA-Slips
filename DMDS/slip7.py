import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
import matplotlib.pyplot as plt

# Data
x = np.array([1, 2, 3, 4, 5, 6, 7, 8]).reshape(-1, 1)
y = np.array([7, 14, 15, 18, 19, 21, 26, 23])

# Create a linear regression model
model = LinearRegression()

# Fit the model
model.fit(x, y)

# Get the coefficients
b0 = model.intercept_
b1 = model.coef_[0]

# Predict the values
y_pred = model.predict(x)

# Analyze the performance of the model
mse = mean_squared_error(y, y_pred)
r2 = r2_score(y, y_pred)

# Print the coefficients
print(f"Intercept (b0): {b0}")
print(f"Slope (b1): {b1}")

# Print the performance metrics
print(f"Mean Squared Error: {mse}")
print(f"R-squared: {r2}")

# Plot the data and the regression line
plt.scatter(x, y, color='blue', label='Actual data')
plt.plot(x, y_pred, color='red', linewidth=2, label='Regression line')
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Simple Linear Regression')
plt.legend()
plt.show()
