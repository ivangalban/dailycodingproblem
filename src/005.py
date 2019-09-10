def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair


def car(f):
    def g(a, b):
        return a
    return f(g)


def cdr(f):
    def g(a, b):
        return b
    return f(g)


print(car(cons(3, 4)))  # 3
print(cdr(cons(3, 4)))  # 4
