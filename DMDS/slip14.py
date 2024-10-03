import pandas as pd
from mlxtend.frequent_patterns import apriori, association_rules

df = pd.read_csv('Datasets/Groceries[Slip14].csv')

# Display the first few rows of the dataset
print("First few rows of the dataset:")
print(df.head())

# Data preprocessing
basket = df.groupby(['Member_number', 'itemDescription'])['itemDescription'].count().unstack().reset_index().fillna(0).set_index('Member_number')

# Convert the count values to binary (1 or 0)
basket_sets = basket.map(lambda x: 1 if x > 0 else 0).astype(bool)

# Apply Apriori algorithm
frequent_itemsets = apriori(basket_sets, min_support=0.01, use_colnames=True)

# Generate association rules
rules = association_rules(frequent_itemsets, metric="confidence", min_threshold=0.2)

# Display support and confidence for each rule
print("\nAssociation Rules:")
print(rules[['antecedents', 'consequents', 'support', 'confidence']])