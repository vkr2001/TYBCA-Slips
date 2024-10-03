import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn import metrics

df = pd.read_csv('Datasets/Car_Dataset[Slip12].csv')

# Display the first few rows of the dataset
print(df.head())

# Selecting features (independent variables) and target (dependent variable)
X = df[['Volume', 'Weight']]
y = df['CO2']

# Split the dataset into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Create a linear regression model
model = LinearRegression()

# Train the model on the training set
model.fit(X_train, y_train)

# Make predictions on the test set
y_pred = model.predict(X_test)

# Evaluate the model
print('\nModel Evaluation:')
print('Mean Absolute Error:', metrics.mean_absolute_error(y_test, y_pred))
print('Mean Squared Error:', metrics.mean_squared_error(y_test, y_pred))
print('Root Mean Squared Error:', metrics.mean_squared_error(y_test, y_pred, squared=False))

# Display the coefficients and intercept
print('\nModel Coefficients:')
for feature, coefficient in zip(X.columns, model.coef_):
    print(f'{feature}: {coefficient}')

print('Intercept:', model.intercept_)
