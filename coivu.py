def censorText(s1, s2):
    s = ""
    for c2 in s2.split():
        ok = 0
        for c1 in s1.split():
            if (c1.lower() in c2.lower()):
                ok1 = 0
                for c in c2:
                    if (c.isalpha() and not ok1):
                        ok1 = 1
                        s += c
                    elif (not c.isalpha()):
                        s += c
                    else:
                        s += "*"
                ok = 1
                break
        if not ok:
            s += c2
        s += " "
    return s
print (censorText("fucking shit hell asshole dick", "I do not fucking want to work with you asshole, go and keep sucking my dick, go to the hell to eat shit"))