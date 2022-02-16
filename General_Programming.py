# sum of the first 100 even fibonacci numbers

def sum_even_fibs(n):
    
    a, b = 0, 1
    s = 0
    c = 0
    while c < n:
        if a % 2 == 0:
            s += a
            c += 1
        a, b = b, a + b
    return s


# Write a function in a language of your choice which, when passed two sorted arrays of integers returns an array of any numbers which appear in both.\
#  No value should appear in the returned array more than once.

def common_elements(arr1, arr2):
    arr3 = []
    for i in arr1:
        if i in arr2:
            arr3.append(i)
    return arr3


# Write a function in a language of your choice which, when passed a positive integer returns true if the decimal representation of that integer contains no odd digits and otherwise returns false.

def no_odd_digits(n):
    if n == 0:
        return True
    else:
        return n % 2 == 0 and no_odd_digits(n // 10)


# Write a function in a language of your choice which, when passed a decimal digit X, returns the value of X+XX+XXX+XXXX. E.g. if the supplied digit is 3 it should return 3702 (3+33+333+3333)

def digit_sum(n):
    sum = n + (n * 10 + n) + (n * 100 +n * 10 + n)+ (n * 1000 + n * 100 + n * 10 + n)
    return sum

if __name__ == '__main__':
    print(sum_even_fibs(100))
    print(common_elements([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]))
    print(no_odd_digits(246))
    print(no_odd_digits(2465))
    print(digit_sum(3))
    print(digit_sum(5))

    


