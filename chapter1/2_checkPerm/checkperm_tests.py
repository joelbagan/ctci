from checkperm import checkPerm

def test_checkPerm1():
	assert checkPerm("asdf","fdsa") == True
def test_checkPerm2():
	assert checkPerm("asdfasdfasdfasdfasdfasdfasdfasdf","a") == False
def test_checkPerm3():
	assert checkPerm("1234567890","0987654321") == True
def test_checkPerm4():
	assert checkPerm("ffff","aaaa") == False
def test_checkPerm5():
	assert checkPerm("ffff","fff") == False
def test_checkPerm6():
	assert checkPerm("asdf;lkj","fdsajkl;") == True