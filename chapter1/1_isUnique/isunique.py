'''
Implement an algorithm to determine if a string has all unique characters. 
What if you cannot use additional data structures?
'''

def allUnique(input):
	if(type(input) != str):
		return False

	freq = dict()
	'''
	if we had a constraint on the types of characters allowed we could check length first
	i.e. if only alphas, check length < 26 * 2 for upper and lower
	'''
	for char in input:
		if(char in freq):
			return False
		else:
			freq[char] = 1
	return True

def allUniqueAlt(input):
	if(type(input) != str):
		return False

	input = sorted(input)
	prev = ''
	for char in input:
		if(prev != '' and char == prev):
			return False
		prev = char
	return True