# install this using terminal : pip install statsmodels matplotlib
import pandas as pd
import statsmodels.api as sm
import matplotlib.pyplot as plt

# Create the stock market data frame
Stock_Market = {
    'Year': [2017, 2017, 2017, 2017, 2017, 2017, 2017, 2017, 2017, 2017, 2017, 2017, 2016, 2016, 2016, 2016, 2016, 2016, 2016, 2016, 2016, 2016, 2016, 2016],
    'Month': [12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
    'Interest_Rate': [2.75, 2.5, 2.5, 2.5, 2.5, 2.5, 2.5, 2.25, 2.25, 2.25, 2, 2, 2, 1.75, 1.75, 1.75, 1.75, 1.75, 1.75, 1.75, 1.75, 1.75, 1.75, 1.75],
    'Unemployment_Rate': [5.3, 5.3, 5.3, 5.3, 5.4, 5.6, 5.5, 5.5, 5.5, 5.6, 5.7, 5.9, 6, 5.9, 5.8, 6.1, 6.2, 6.1, 6.1, 6.1, 5.9, 6.2, 6.2, 6.1],
    'Stock_Index_Price': [1464, 1394, 1357, 1293, 1256, 1254, 1234, 1195, 1159, 1167, 1130, 1075, 1047, 965, 943, 958, 971, 949, 884, 866, 876, 822, 704, 719]
}

df = pd.DataFrame(Stock_Market)

# Add a constant term to the independent variables matrix
X = sm.add_constant(df[['Interest_Rate', 'Unemployment_Rate']])

# Fit the regression model
model = sm.OLS(df['Stock_Index_Price'], X).fit()

# Print the regression summary
print(model.summary())

# Plot the graph of Stock Market Price versus Interest Rate
plt.scatter(df['Interest_Rate'], df['Stock_Index_Price'], label='Data Points')
plt.plot(df['Interest_Rate'], model.predict(X), color='red', label='Regression Line')
plt.title('Stock Market Price vs Interest Rate')
plt.xlabel('Interest Rate')
plt.ylabel('Stock Market Price')
plt.legend()
plt.show()
