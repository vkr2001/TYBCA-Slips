import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import AgglomerativeClustering
from sklearn.preprocessing import StandardScaler
from scipy.cluster.hierarchy import dendrogram, linkage

data = pd.read_csv("Datasets/Wholesale_Customers[Slip11].csv")

# Select relevant fields for clustering
fields = ['Fresh', 'Milk', 'Grocery', 'Frozen', 'Detergents_Paper', 'Delicassen']
data_numeric = data[fields]

# Standardize the data
scaler = StandardScaler()
data_scaled = scaler.fit_transform(data_numeric)

# Hierarchical clustering using AgglomerativeClustering
num_clusters = 3  # You can adjust the number of clusters as needed
model = AgglomerativeClustering(n_clusters=num_clusters, linkage='ward')
clusters = model.fit_predict(data_scaled)

# Add the cluster labels to the original dataset
data['Cluster'] = clusters

# Print the count of points in each cluster
print("Number of points in each cluster:")
print(data['Cluster'].value_counts())

# Plot the dendrogram
plt.figure(figsize=(12, 6))
dendrogram(linkage(data_scaled, method='ward'))
plt.title('Dendrogram')
plt.xlabel('Data points')
plt.ylabel('Euclidean distance')
plt.show()