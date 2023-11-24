import random
# import numpy as np


# def quicksort_a(stack_a, stack_b, len):

# 	if (len(stack_a) <= 3):
# 		stack_a = sorted(stack_a)
# 		return (stack_a)
# 	# median = int(np.median(stack_a[0:len]))
# 	for number in stack_a:
# 		if number < median:
# 			stack_b.insert(0, number)
# 			del stack_a[0]






# def quicksort_b(stack_a, stack_b, len):
# 	pass



def test_sort():
	stack_a = random.sample(range(1, 100), 20)
	stack_b = []
	print(f"\nSTACK A UNSORTED: {stack_a}\n")
	return

	stack_a = quicksort_a(stack_a, stack_b, len(stack_a))
	print(f"STACK A   SORTED: {stack_a}\n")

test_sort()
