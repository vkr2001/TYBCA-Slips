import pandas as pd
from mlxtend.preprocessing import TransactionEncoder
from mlxtend.frequent_patterns import apriori, association_rules

df = pd.read_csv('Datasets/MarketBasket[Slip10].csv', header=None)

# Display the first few rows of the dataset to understand its structure
print("Dataset structure:")
print(df.head())

# Preprocess the data for Apriori algorithm
transactions = df.apply(lambda row: row.dropna().tolist(), axis=1).values.tolist()

# Use TransactionEncoder to one-hot encode the transaction data
te = TransactionEncoder()
te_ary = te.fit(transactions).transform(transactions)
df_encoded = pd.DataFrame(te_ary, columns=te.columns_)

# Apply Apriori algorithm to find frequent itemsets
min_support = 0.01  # You can adjust this parameter based on your dataset
frequent_itemsets = apriori(df_encoded, min_support=min_support, use_colnames=True)

# Display frequent itemsets with support
print("\nFrequent Itemsets:")
print(frequent_itemsets)

# Generate association rules
rules = association_rules(frequent_itemsets, metric="confidence", min_threshold=0.5)

# Display association rules with support, confidence, and lift
print("\nAssociation Rules:")
print(rules[['antecedents', 'consequents', 'support', 'confidence', 'lift']])
