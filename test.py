import duck

t = 10
y = 5
h = 15
a = -43.5
max_a = -a

x = duck.grab("test.obj")

duck.eat()
duck.winter(500)
while a < max_a:
    duck.eat()
    duck.quaks(x, a)
    duck.winter(5)
    a += 0.5
