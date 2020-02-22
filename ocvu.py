import math
def calculateArea(alpha, radius):
    alpha = 2 * alpha
    return int(round(radius * radius / 2 * (alpha * 3.14 / 180 - math.sin(alpha * 3.145 / 180)) * 100)) / 100