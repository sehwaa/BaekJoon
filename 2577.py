su = 1

for _ in range(3):
    n = int(input())
    su *= n

import re

for idx in range(10):
    p = re.compile(str(idx))
    result = p.findall(str(su))
    print(len(result))
