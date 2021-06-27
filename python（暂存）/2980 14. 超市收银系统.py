chips = 0
chocolate = 0
soap = 0
cupcake = 0
cookie = 0
milk = 0
toothbrush = 0
toothpaste = 0
teapot = 0
tm = 1
while tm != 0:
    if tm == 932071:
        chips = chips + 1
    if tm == 114049:
        chocolate = chocolate + 1
    if tm == 304985:
        soap = soap + 1
    if tm == 955962:
        cupcake = cupcake + 1
    if tm == 313903:
        cookie = cookie + 1
    if tm == 243813:
        milk = milk + 1
    if tm == 961995:
        toothbrush = toothbrush + 1
    if tm == 933328:
        toothpaste = toothpaste + 1
    if tm == 914500:
        teapot = teapot + 1
    tm = int(input())
l1 = 0
l2 = 0
l3 = 0
l4 = 0
l5 = 0
l6 = 0
l7 = 0
l8 = 0
l9 = 0
if chips != 0:
    l1 = 5
if chocolate != 0:
    l2 = 9
if soap != 0:
    l3 = 4
if cupcake != 0:
    l4 = 7
if cookie != 0:
    l5 = 6
if milk != 0:
    l6 = 4
if toothbrush != 0:
    l7 = 10
if toothpaste != 0:
    l8 = 10
if teapot != 0:
    l9 = 6
lang = max(l1, l2, l3, l4, l5, l6, l7, l8, l9) + 1
print("NAME".ljust(lang) + "QUANTITY " + "PRICE SUM")
p1 = chips * 3.5
p2 = 8 * chocolate
p3 = soap * 2.9
p4 = cupcake * 4.9
p5 = cookie * 6.5
p6 = milk * 3.2
p7 = toothbrush * 4.8
p8 = toothpaste * 9.3
p9 = teapot * 29.8
if chips != 0:
    print("chips".ljust(lang) + str(chips).ljust(9) + "3.5".ljust(6) + "%.2f" % p1)
if chocolate != 0:
    print("chocolate".ljust(lang) + str(chocolate).ljust(9) + "8.0".ljust(6) + "%.2f" % p2)
if cookie != 0:
    print("cookie".ljust(lang) + str(cookie).ljust(9) + "6.5".ljust(6) + "%.2f" % p5)
if cupcake != 0:
    print("cupcake".ljust(lang) + str(cupcake).ljust(9) + "4.9".ljust(6) + "%.2f" % p4)
if milk != 0:
    print("milk".ljust(lang) + str(milk).ljust(9) + "3.2".ljust(6) + "%.2f" % p6)
if soap != 0:
    print("soap".ljust(lang) + str(soap).ljust(9) + "2.9".ljust(6) + "%.2f" % p3)
if teapot != 0:
    print("teapot".ljust(lang) + str(teapot).ljust(9) + "29.8".ljust(6) + "%.2f" % p9)
if toothbrush != 0:
    print("toothbrush".ljust(lang) + str(toothbrush).ljust(9) + "4.8".ljust(6) + "%.2f" % p7)
if toothpaste != 0:
    print("toothpaste".ljust(lang) + str(toothpaste).ljust(9) + "9.3".ljust(6) + "%.2f" % p8)
total = p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9
print("total:""%.2f" % total)
