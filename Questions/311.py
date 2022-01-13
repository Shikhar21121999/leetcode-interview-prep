class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        preorder = preorder.split(',')
        degree = -1
        for s in preorder:
            degree += 1
            if (degree > 0):
                return False
            if (not (s == '#')):
                degree -= 2
        return degree == 0
