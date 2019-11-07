class Solution(object):
    def mergeKLists(self, lists):
        finalList=ListNode(-10000)
        current=finalList
        while True:
            minList=None
            index=0
            for i in range(len(lists)):
                lst=lists[i]
                if lst==None:
                    continue
                if minList==None:
                    minList=lst
                    index=i
                elif lst.val<minList.val:
                    minList=lst
                    index=i
            if minList==None:
                break
            current.next=minList
            current=current.next
            lists[index]=minList.next
        return finalList.next

def stringToListNode(input):
    # Generate list from the input
    numbers = json.loads(input)

    # Now convert that list into linked list
    dummyRoot = ListNode(0)
    ptr = dummyRoot
    for number in numbers:
        ptr.next = ListNode(number)
        ptr = ptr.next

    ptr = dummyRoot.next
    return ptr

def stringToListNodeArray(input):
    listNodeArrays = json.loads(input)
    nodes = []
    for listNodeArray in listNodeArrays:
        nodes.append(stringToListNode(json.dumps(listNodeArray)))
    return nodes

def listNodeToString(node):
    if not node:
        return "[]"

    result = ""
    while node:
        result += str(node.val) + ", "
        node = node.next
    return "[" + result[:-2] + "]"

def main():
    import sys
    def readlines():
        for line in sys.stdin:
            yield line.strip('\n')
    lines = readlines()
    while True:
        try:
            line = lines.next()
            lists = stringToListNodeArray(line)
            
            ret = Solution().mergeKLists(lists)

            out = listNodeToString(ret)
            print out
        except StopIteration:
            break

if __name__ == '__main__':
    main()