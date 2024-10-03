# import pandas as pd
# from sklearn.model_selection import train_test_split
# from sklearn.tree import DecisionTreeClassifier
# from sklearn.preprocessing import LabelEncoder

# # Load the dataset
# data = pd.read_csv('Datasets/TV_Shows[Slip15].csv')

# # Encode categorical variables
# le = LabelEncoder()
# data['Nationality'] = le.fit_transform(data['Nationality'])
# data['Go'] = le.fit_transform(data['Go'])

# # Features and target variable
# X = data[['Age', 'Experience', 'Rank', 'Nationality']]
# y = data['Go']

# # Split the dataset into training and testing sets
# X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# # Build Decision Tree Classifier
# dt_classifier = DecisionTreeClassifier()
# dt_classifier.fit(X_train, y_train)

# # Predict class label for a new data point
# new_data_point = pd.DataFrame({'Age': [40], 'Experience': [10], 'Rank': [7], 'Nationality': [1]})
# predicted_label = dt_classifier.predict(new_data_point)

# # Convert the predicted label back to original class label
# predicted_class = le.inverse_transform(predicted_label)

# print(f"The predicted class label for the new data point is: {predicted_class[0]}")

from ucimlrepo import fetch_ucirepo 
  
# fetch dataset 
iris = fetch_ucirepo(id=53) 
  
# data (as pandas dataframes) 
X = iris.data.features 
y = iris.data.targets 
  
# metadata 
print(iris.metadata) 
  
# variable information 
print(iris.variables) 
