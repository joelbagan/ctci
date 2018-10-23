####################
from isunique import allUnique

def test_allUnique1():
    assert allUnique("input1.txt") == False

def test_allUnique2():
    assert allUnique("asdf") == True


def test_allUnique3():
    assert allUnique("aAsSdDfF") == True

def test_allUnique4():
    assert allUnique("((asdf))") == False

def test_allUnique5():
    assert allUnique("qwertyuiop[]asdfghjkl;'zxcvbnm,q") == False

def test_allUnique6():
    assert allUnique("ctci") == False

def test_allUnique7():
    assert allUnique("") == True

def test_allUnique8():
    assert allUnique(1) == False

####################
from isunique import allUniqueAlt

def test_allUniqueAlt1():
    assert allUniqueAlt("input1.txt") == False

def test_allUniqueAlt2():
    assert allUniqueAlt("asdf") == True

def test_allUniqueAlt3():
    assert allUniqueAlt("aAsSdDfF") == True

def test_allUniqueAlt4():
    assert allUniqueAlt("((asdf))") == False

def test_allUniqueAlt5():
    assert allUniqueAlt("qwertyuiop[]asdfghjkl;'zxcvbnm,q") == False

def test_allUniqueAlt6():
    assert allUniqueAlt("ctci") == False

def test_allUniqueAlt7():
    assert allUniqueAlt("") == True

def test_allUniqueAlt8():
    assert allUniqueAlt(1) == False