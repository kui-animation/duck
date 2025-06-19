import duck

t = 11
y = 3

x = [

        8, y,-3,
        16,y,0,
        0,y,0,

        8,y,t+3,
        0,y,t,
        16,y,t
    ]

while y < 15:
    duck.eat()
    print("\x1B[07;00fduck")

    duck.quaks(x)
    duck.winter(500)
    for i in range(1,18,3):
        x[i] = y
    y += 1    
