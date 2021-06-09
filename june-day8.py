from typing import List


class Treenode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Treenode:

        if not preorder or not inorder:
            return None

        rootValue = preorder.pop(0)
        root = Treenode(rootValue)
        inorderIndex = inorder.index(rootValue)

        root.left = self.buildTree(preorder, inorder[:inorderIndex])
        root.right = self.buildTree(preorder, inorder[inorderIndex+1:])

        return root


# Inorder Iterative traversal of Btree
def Inorder_iterative(root):
    # Left Node Right

    ans = []
    s = []
    # It returns a list containing inorder traversal of Btree
    node = root
    while(node != None or len(s) > 0):
        if node is not None:
            s.append(node)
            node = node.left
        else:
            node = s.pop()
            ans.append(node.val)
            node = node.right
    return ans


# driver Code
if __name__ == '__main__':
    inorder = [10, 1, 30, 40, 20]
    preorder = [1, 10, 20, 30, 40]
    obj = Solution()
    root = obj.buildTree(preorder, inorder)
    print(Inorder_iterative(root))
