def getString(s):

    stri = []

    for i in range(len(s)):
        stri.append(s[i])


    for i in range(len(stri)):
        for j in range(i+1,len(stri)):
            if (stri[i] < stri[j]):
                x = stri[j]
                stri[i] = stri[j]
                stri[j] = x
            

    return "".join(stri)

