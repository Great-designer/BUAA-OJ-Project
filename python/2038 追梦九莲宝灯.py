def dream(card):
    a = 'm'
    if len(card[a]) >= 14 and card[a].count('1') >= 3 and card[a].count('2') >= 1 and card[a].count(
            '3') >= 1 and card[a].count('4') >= 1 and card[a].count('5') >= 1 and card[a].count('6') >= 1 and \
            card[a].count('7') >= 1 and card[a].count('8') >= 1 and card[a].count('9') >= 3:
        return True
    a = 'p'
    if len(card[a]) >= 14 and card[a].count('1') >= 3 and card[a].count('2') >= 1 and card[a].count(
            '3') >= 1 and card[a].count('4') >= 1 and card[a].count('5') >= 1 and card[a].count('6') >= 1 and \
            card[a].count('7') >= 1 and card[a].count('8') >= 1 and card[a].count('9') >= 3:
        return True
    a = 's'
    if len(card[a]) >= 14 and card[a].count('1') >= 3 and card[a].count('2') >= 1 and card[a].count(
            '3') >= 1 and card[a].count('4') >= 1 and card[a].count('5') >= 1 and card[a].count('6') >= 1 and \
            card[a].count('7') >= 1 and card[a].count('8') >= 1 and card[a].count('9') >= 3:
        return True
    a = 'z'
    if len(card[a]) >= 14 and card[a].count('1') >= 3 and card[a].count('2') >= 1 and card[a].count(
            '3') >= 1 and card[a].count('4') >= 1 and card[a].count('5') >= 1 and card[a].count('6') >= 1 and \
            card[a].count('7') >= 1 and card[a].count('8') >= 1 and card[a].count('9') >= 3:
        return True
    return False


init = input()
draw = input()
hand = {'m': [], 'p': [], 's': [], 'z': []}
for i in range(0, 26, 2):
    hand[init[i + 1]].append(init[i])
for i in range(0, 34, 2):
    hand[draw[i + 1]].append(draw[i])
    if dream(hand):
        print(i//2+1)
        break
else:
    print('Stop Your Daydream!')
