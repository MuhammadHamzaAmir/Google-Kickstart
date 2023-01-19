cases = int(input())
for i in range(cases):
    case = int(input())
    list_ = []
    for j in range(case):
        in_list = list(input())
        list_.append(in_list)

    # main logic
    dots = 0
    blues = 0
    reds = 0
    for k in range(len(list_)):
        for l in range(len(list_[k])):
            if list_[k][l] == ".":
                dots += 1
            elif list_[k][l] == "B":
                blues += 1
            elif list_[k][l] == "R":
                reds += 1
    # print(reds,blues,dots)
    if (case == 1):
        if list_[0][0] == ".":
            print("Case #" + str(i+1) + ": Nobody wins")
        elif list_[0][0] == "B":
            print("Case #" + str(i+1) + ": Blue wins")
        elif list_[0][0] == "R":
            print("Case #" + str(i+1) + ": Red wins")

    if (abs(blues-reds) > 1):
        print("Case #" + str(i+1) + ": Impossible")
    if ((abs(blues-reds) == 1) and (dots == 1)):
        print("Case #" + str(i+1) + ": Impossible")
    if ((abs(blues-reds) <= 1) and (dots > 1)):
        # check for row wise for blues
        blues_rows = 0
        for row in list_:
            check_blue = True
            for col in row:
                if (col == "R"):
                    check_blue = False
                    break
            if (check_blue):
                blues_rows += 1

        if (blues_rows >= 1):
            print("Case #" + str(i+1) + ": Blue wins")
        else:
            red_cols = 0
            for c in range(len(list_)):
                check_red = True
                for r in range(len(list_[c])):
                    if (list_[r][c] == "B"):
                        check_red = False
                        break
                if (check_red):
                    red_cols += 1
            if (red_cols >= 1):
                print("Case #" + str(i+1) + ": Red wins")
            else:
                print("Case #" + str(i+1) + ": Impossible")
