#s the largest integer H such that the
#researcher has H papers with at
#least H citations each.

def h_index(arr):
    index = []
    int_ind = 1
    for i in range(len(arr)):
        # H papers
        papers = 0
        if (int_ind <= (i+1)):
            # look for citations
            cit = 0
            # only for that element & maybe previous
            for j in range(i, 0, -1):
                if arr[i] >= (j):
                    witness = 1
                    if (arr[i] > int_ind):
                        # previous element
                        for k in range(i, 0, -1):
                            if (arr[k-1] >= j):
                                witness += 1
                            if (witness == j):
                                cit += 1
                                break
                        else:
                            continue
                        break

            papers = papers + cit
            int_ind = int_ind + papers
            index.append(int_ind)
        else:
            index.append(int_ind)
    return index


def print_output(case, arr):
    stm = "Case #"+str(case)+":"
    for i in arr:
        stm = stm + " " + str(i)
    return stm


def take_input():

    cases = int(input())

    for i in range(cases):
        n = int(input())
        arr_s = input()
        arr_xs = arr_s.split(' ')
        for j in range(len(arr_xs)):
            arr_xs[j] = int(arr_xs[j])

        h_ind = h_index(arr_xs)
        stm = print_output(i+1, h_ind)
        print(stm)


take_input()
