import random
import timeit
import sys

# --- Set a high recursion limit for the worst-case deterministic test ---
# We set it higher than the max array size
sys.setrecursionlimit(110000) 

# Deterministic partition (pivot = last element)
def deterministic_partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

# Randomized partition (pivot = random element)
def randomized_partition(arr, low, high):
    pivot_index = random.randint(low, high)
    arr[pivot_index], arr[high] = arr[high], arr[pivot_index]
    return deterministic_partition(arr, low, high)

# General quicksort function
def quick_sort(arr, low, high, partition_fn):
    if low < high:
        pi = partition_fn(arr, low, high)
        quick_sort(arr, low, pi - 1, partition_fn)
        quick_sort(arr, pi + 1, high, partition_fn)

if __name__ == "__main__":
    sizes = [100, 1000, 5000, 10000] # Reduced 100k as it can be very slow

    for size in sizes:
        print(f"\n======== Array size: {size} ========")

        # --- 1. Worst-Case Analysis (Reverse-Sorted Array) ---
        print(f"--- 1. Worst-Case (Reverse-Sorted) ---")
        worst_case_arr = [random.randint(1, 1000) for _ in range(size)]
        worst_case_arr.sort(reverse=True) 

        # Time deterministic quicksort (Worst Case)
        det_time_worst = timeit.timeit(
            stmt="quick_sort(worst_case_arr.copy(), 0, len(worst_case_arr) - 1, deterministic_partition)",
            globals=globals(),
            number=5
        )

        # Time randomized quicksort (Worst Case)
        rand_time_worst = timeit.timeit(
            stmt="quick_sort(worst_case_arr.copy(), 0, len(worst_case_arr) - 1, randomized_partition)",
            globals=globals(),
            number=5
        )

        print(f"Deterministic Quick Sort time: {det_time_worst:.6f} seconds")
        print(f"Randomized Quick Sort time:   {rand_time_worst:.6f} seconds")

        # --- 2. Average-Case Analysis (Random Array) ---
        print(f"\n--- 2. Average-Case (Random) ---")
        avg_case_arr = [random.randint(1, 1000) for _ in range(size)]

        # Time deterministic quicksort (Average Case)
        det_time_avg = timeit.timeit(
            stmt="quick_sort(avg_case_arr.copy(), 0, len(avg_case_arr) - 1, deterministic_partition)",
            globals=globals(),
            number=5
        )

        # Time randomized quicksort (Average Case)
        rand_time_avg = timeit.timeit(
            stmt="quick_sort(avg_case_arr.copy(), 0, len(avg_case_arr) - 1, randomized_partition)",
            globals=globals(),
            number=5
        )

        print(f"Deterministic Quick Sort time: {det_time_avg:.6f} seconds")
        print(f"Randomized Quick Sort time:   {rand_time_avg:.6f} seconds")
        print("-" * 40)