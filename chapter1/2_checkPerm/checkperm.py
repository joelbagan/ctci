'''
Given two strings, write a method to decide if one is a permutation of the other
'''

'''
Permutaion conditions:
 * equal length
 * same frequency of each unique char
'''

def checkPerm(string1, string2):
	if(type(string1) != str or type(string2) != str):
		return False

	if(len(string1) != len(string2)):
		return False

	string1_freq = dict()
	string2_freq = dict()

	for i in range(0, len(string1)):
		if(string1[i] in string1_freq):
			string1_freq[string1[i]] += 1
		else:
			string1_freq[string1[i]] = 1

		if(string2[i] in string2_freq):
			string2_freq[string2[i]] += 1
		else:
			string2_freq[string2[i]] = 1

	for key, value in string1_freq.items():
		if(key not in string2_freq or string2_freq[key] != value):
			return False
	return True