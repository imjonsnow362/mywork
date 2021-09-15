import pandas as pd
import os
df = pd.read_csv('emot.csv')
df_st = pd.DataFrame()
file = open("alp.txt","r")
file.seek(0)
emot_val = df['Mnemonic'].tolist()
symbols = []
for i in file:
    data = i.strip()
    str = data.split(" ")
    # print(str)
    if str[0] not in emot_val:
        symbols.append(str[0])

st_values = pd.Series(symbols)
df_st.insert(loc=0, column='Symbol', value = st_values)
df_st.to_csv('ST_NO_LC.csv')
print(df_st)