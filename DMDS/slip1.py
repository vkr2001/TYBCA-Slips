import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_absolute_error, mean_squared_error, r2_score

# Load the student data set
student_data = np.loadtxt(r"Datasets/Student_Dataset[Slip1].csv", delimiter=",")

# Split the data into features and target
X_train = student_data[:, :-1]
y_train = student_data[:, -1]

# Create a linear regression model
model = LinearRegression()

# Fit the model to the training data
model.fit(X_train, y_train)

# Make predictions on the training data
y_pred = model.predict(X_train)

# Calculate the mean absolute error, mean squared error, and root mean squared error
mae = mean_absolute_error(y_train, y_pred)
mse = mean_squared_error(y_train, y_pred)
rmse = np.sqrt(mse)

# Print the results
print("Mean Absolute Error:", mae)
print("Mean Squared Error:", mse)
print("Root Mean Squared Error:", rmse)