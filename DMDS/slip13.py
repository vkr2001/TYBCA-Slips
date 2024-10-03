import pandas as pd

# Read the CSV file
df = pd.read_csv('Datasets/Student_Performance[Slip13].csv')

# Display the shape of the dataset
print("Shape of the dataset:", df.shape)

# Display the top rows of the dataset with their columns
print("\nTop rows of the dataset:")
print(df.head(10))