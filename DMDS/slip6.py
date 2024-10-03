import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import AgglomerativeClustering
from scipy.cluster.hierarchy import dendrogram, linkage

df = pd.read_csv("Datasets/Customer[Slip6].csv")

# Display the first few rows of the dataset to understand its structure
print(df.head())

# Ensure that the column indices are correct
# Adjust these indices based on the actual structure of your dataset
X = df.iloc[:, [2, 3, 4]].values  # Considering 'age', 'annual_income', 'spending_score'

# Hierarchical clustering using Ward's method
linked = linkage(X, 'ward')

# Plotting the dendrogram
plt.figure(figsize=(12, 8))
dendrogram(linked, orientation='top', distance_sort='descending',show_leaf_counts=True)
plt.title('Hierarchical Clustering Dendrogram')
plt.xlabel('Customer Index')
plt.ylabel('Euclidean Distance')
plt.show()

# Performing Agglomerative Clustering
num_clusters = 5  # You can choose the number of clusters based on the dendrogram
hc = AgglomerativeClustering(n_clusters=num_clusters, metric='euclidean', linkage='ward')
y_hc = hc.fit_predict(X)

# Add cluster labels to the original dataset
df['Cluster'] = y_hc

# Display the first few rows of the dataset with cluster labels
print(df.head())