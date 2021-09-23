N = input()

croatia_alphabet = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

answer = 0
for c in croatia_alphabet:
    if c in N:
        count = N.count(c)
        N = N.replace(c, ' ')
        answer += count

if len(N.replace(' ', '')) > 0:
    answer += len(N.replace(' ', ''))


print(answer)