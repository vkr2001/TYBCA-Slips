import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn import metrics

data = pd.read_csv('Datasets/TV_Shows[Slip15].csv')

# Display the dataset to understand its structure
print("Dataset:")
print(data)

# Map 'Go' column to numeric values (Yes: 1, No: 0)
data['Go'] = data['Go'].map({'Yes': 1, 'No': 0})

# Separate features (X) and target variable (y)
X = data[['Age', 'Experience', 'Rank', 'Nationality']]
y = data['Go']

# Convert 'Nationality' to numerical values using one-hot encoding
X = pd.get_dummies(X, columns=['Nationality'], drop_first=True)

# Split the dataset into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Create a Decision Tree Classifier
dt_classifier = DecisionTreeClassifier()

# Train the classifier
dt_classifier.fit(X_train, y_train)

# Predict class label for a comedian with specific characteristics
comedian_data = {'Age': 40, 'Experience': 10, 'Rank': 7, 'Nationality_USA': 1 }
comedian_df = pd.DataFrame([comedian_data], columns=X_train.columns)

# Make predictions
prediction = dt_classifier.predict(comedian_df)

# Display the prediction
print("\nPrediction:")
if prediction[0] == 1:
    print("The comedian should 'Go'.")
else:
    print("The comedian should not 'Go'.")

# Evaluate the model on the test set
y_pred = dt_classifier.predict(X_test)
accuracy = metrics.accuracy_score(y_test, y_pred)
print("\nModel Accuracy on Test Set:", accuracy)
