#원래 생각한 클래스 구현하는 방식 그래도 딕셔너리를 쓰긴함
class TreeNode():
    def __init__(self, left, right, item):
        self.left = left
        self.right = right
        self.item = item

def preorder(node):
    print(node.item, end='')
    if node.left != '.':
        preorder(tree[node.left])
    if node.right != '.':
        preorder(tree[node.right])

def inorder(node):
    if node.left != '.':
        inorder(tree[node.left])
    print(node.item, end='')
    if node.right != '.':
        inorder(tree[node.right])

def postorder(node):
    if node.left != '.':
        postorder(tree[node.left])
    if node.right != '.':
        postorder(tree[node.right])
    print(node.item, end='')


tree = {}
N = int(input())
strList = []
for i in range(N):
    strList.append(input())

for i in range(N):
    li = strList[i].split(' ')
    tree[li[0]] = TreeNode(li[1], li[2], li[0])

preorder(tree['A'])
print('')
inorder(tree['A'])
print('')
postorder(tree['A'])
# 참고해서, 딕셔너리만 이용하는 방식
'''
def preorder(item):
    if item != '.':
        print(item, end='')
        preorder(tree[item][0])
        preorder(tree[item][1])

def inorder(item):
    if item != '.':
        inorder(tree[item][0])
        print(item, end='')
        inorder(tree[item][1])

def postorder(item):
    if item != '.':
        postorder(tree[item][0])
        postorder(tree[item][1])
        print(item, end='')

tree = {}
N = int(input())
strList = []
for i in range(N):
    strList.append(input())

for i in range(N):
    li = strList[i].split(' ')
    tree[li[0]] = [li[1], li[2]]

preorder('A')
print('')
inorder('A')
print('')
postorder('A')
'''