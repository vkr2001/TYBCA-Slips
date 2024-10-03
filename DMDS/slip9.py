# Import necessary libraries
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score, precision_score, recall_score

# Load the Breast Cancer Wisconsin dataset
cancer_data = datasets.load_breast_cancer()

# Split the dataset into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(
    cancer_data.data, cancer_data.target, test_size=0.2, random_state=42
)

# Initialize the Support Vector Machine model
svm_model = SVC(kernel='linear', C=1)
print("Features: ", cancer_data.feature_names) 
print("Labels: ", cancer_data.target_names)
cancer_data.data.shape 
11
print(cancer_data.data[0:5]) 
print(cancer_data.target)
# Train the model
svm_model.fit(X_train, y_train)

# Make predictions on the test set
y_pred = svm_model.predict(X_test)

# Evaluate the model
accuracy = accuracy_score(y_test, y_pred)
precision = precision_score(y_test, y_pred)
recall = recall_score(y_test, y_pred)

# Print the results
print(f"Accuracy: {accuracy:.2f}")
print(f"Precision: {precision:.2f}")
print(f"Recall: {recall:.2f}")