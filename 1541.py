from cmath import exp


expression = input()

sub_expression = expression.split('-')
order = []

for i in sub_expression:
    if i == '-':
        continue
    if i.find('+') != -1:
        j = i.split('+')
        sum = 0
        for k in j:
            if k == '+':
                continue
            sum += int(k)
        order.append(sum)
    else:
        order.append(int(i))

result = order[0]
for i in order[1:]:
    result -= i

print(result)