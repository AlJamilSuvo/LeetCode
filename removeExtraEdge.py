class TreeNode:
    def __init__(self,value):
        self.value=value
        self.left=None
        self.right=None

root=TreeNode(1)
tw=TreeNode(2)
th=TreeNode(3)
root.left=tw
root.right=th
fr=TreeNode(4)
fv=TreeNode(5)
tw.left=fr
tw.right=fv
th.left=fv
print(root)