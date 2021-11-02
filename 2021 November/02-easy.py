n = int(input())
zodiacs = ["Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"]
cowyears = {"Bessie":0}
cowzodiac = {"Bessie":"Ox"}
for _ in range(n):
    statement = input().split(" ")
    cow1 = statement[0]
    nextorprev = statement[3]
    zodiac = statement[4]
    cow2 = statement[-1]

    cowzodiac[cow1] = zodiac

    zodiac1 = zodiacs.index(zodiac)
    zodiac2 = zodiacs.index(cowzodiac[cow2])
    diff = abs(zodiac1 - zodiac2)

    if nextorprev == "next":
        if zodiac1 > zodiac2:
            cowyears[cow1] = cowyears[cow2] + diff
        else:
            cowyears[cow1] = cowyears[cow2] + (12-diff)
    else:
        if zodiac1 < zodiac2:
            cowyears[cow1] = cowyears[cow2] - diff
        else:
            cowyears[cow1] = cowyears[cow2] - (12-diff)

print(abs(cowyears["Elsie"] - cowyears["Bessie"]))




