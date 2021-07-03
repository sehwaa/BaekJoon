word = input()

word = word.upper()
from collections import Counter
c = dict(Counter(word).most_common())
if len(list(filter(lambda x: x == max(c.values()), c.values()))) > 1:
    print("?")
else:
    print(list(c)[0])