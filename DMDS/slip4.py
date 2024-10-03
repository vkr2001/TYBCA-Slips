# Given dataset
weather = ['Sunny', 'Sunny', 'Overcast', 'Rainy', 'Rainy', 'Rainy', 'Overcast', 'Sunny', 'Sunny', 'Rainy', 'Sunny', 'Overcast', 'Overcast', 'Rainy']
temp = ['Hot', 'Hot', 'Hot', 'Mild', 'Cool', 'Cool', 'Cool', 'Mild', 'Cool', 'Mild', 'Mild', 'Mild', 'Hot', 'Mild']
play = ['No', 'No', 'Yes', 'Yes', 'Yes', 'No', 'Yes', 'No', 'Yes', 'Yes', 'Yes', 'Yes', 'Yes', 'No']

# Tuple to predict
new_data = [('Overcast', 'Mild')]

# Count occurrences of each class
play_count = {'Yes': play.count('Yes'), 'No': play.count('No')}

# Calculate P(Outlook | Play) and P(Temperature | Play)
outlook_given_play = {}
temp_given_play = {}

for outlook, temp, p in zip(weather, temp, play):
    if p not in outlook_given_play:
        outlook_given_play[p] = {}
        temp_given_play[p] = {}
        
    if outlook not in outlook_given_play[p]:
        outlook_given_play[p][outlook] = 0
    if temp not in temp_given_play[p]:
        temp_given_play[p][temp] = 0
    
    outlook_given_play[p][outlook] += 1
    temp_given_play[p][temp] += 1

# Calculate probabilities for the new tuple
new_outlook, new_temp = new_data[0]
p_play_yes = (outlook_given_play['Yes'].get(new_outlook, 0) / play_count['Yes']) * (temp_given_play['Yes'].get(new_temp, 0) / play_count['Yes']) * (play_count['Yes'] / len(play))
p_play_no = (outlook_given_play['No'].get(new_outlook, 0) / play_count['No']) * (temp_given_play['No'].get(new_temp, 0) / play_count['No']) * (play_count['No'] / len(play))

# Print the probabilities
print("P(Play=Yes | Outlook={}, Temperature={}) = {:.4f}".format(new_outlook, new_temp, p_play_yes))
print("P(Play=No | Outlook={}, Temperature={}) = {:.4f}".format(new_outlook, new_temp, p_play_no))

# Predict the class
predicted_class = 'Yes' if p_play_yes > p_play_no else 'No'
print("Predicted class: {}".format(predicted_class))