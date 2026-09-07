/*
    Solving this problem employs the same algorithm
    as the one I've demonstrated in numbers_9.c.

    Instead of iterating over two sets, in this case
    we will iterate over one set using a front index
    and a rear index.

    (a): sort the set in ascending order. set i = 0,
    j = n - 1.

    while i < j:
        if set[i] + set[j] < x: i += 1
        else if set[i] + set[j] > x: j -= 1
        else: return true
    return false
    Time: O(nlogn)

    (b): follow the same algorithm shown in (a), skipping
    sorting.
    Time: O(n)
 */
