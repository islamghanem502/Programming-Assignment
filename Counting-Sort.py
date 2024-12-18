def counting_sort(arr):
    max_val = max(arr)

    count = [0] * (max_val + 1)

    for num in arr:
        count[num] += 1

    for i in range(1, len(count)):
        count[i] += count[i - 1]

    output = [0] * len(arr)
    for i in range(len(arr) - 1, -1, -1):
        output[count[arr[i]] - 1] = arr[i]
        count[arr[i]] -= 1

    return output


def main():
    n = int(input("Enter the number of elements: "))
    arr = list(map(int, input("Enter the elements: ").split()))


    sorted_arr = counting_sort(arr)

    print("Sorted Array:", sorted_arr)


if __name__ == "__main__":
    main()
