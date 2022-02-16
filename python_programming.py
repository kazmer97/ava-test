# Define a generator which generates the positive integers up to and including a supplied value \
# which are divisible by another supplied positive integer and use it to calculate the sum of all positive integers less than 102030 which are divisible by 3


def divisible_by(n, m):
    for i in range(n+1):
        if i % m == 0:
            yield i


def sum_divisible_by(n, m):
    sum = 0
    for i in divisible_by(n, m):
        # print(i)
        if i < 102030 and i%3==0:
            # print(sum)
            sum += i
        elif i > 102030:
            break
    return sum


# Write a function which is passed an integer, n, and returns a list of n lists such that:

def list_of_n_lists(n):
    list_of_lists = []
    if n == 0:
        return []
    for i in range(1,n+1):
        list_of_lists.append([])
        for j in range(1,i+1):
            list_of_lists[i-1].append(j)
    return list_of_lists


if __name__ == '__main__':
    print(sum_divisible_by(25, 5))
    print(list_of_n_lists(5))
    print(list_of_n_lists(0))
    print(list_of_n_lists(1))
    print(list_of_n_lists(2))
    print(list_of_n_lists(3))
