### given a string "123456789" put +/- sign in the there to get a target sum
####  _1_2_3_4


def targetSum(numberStr,target):
    results=[]
    backTrackResults(numberStr,target,'',results,0)
    return results

def backTrackResults(originalStr,target,currentStr,results,position):
    if position==len(originalStr):
        sum=0
        base=1
        currentNumner=0
        for i in range(len(currentStr)-1,-1,-1):
            if currentStr[i]=='-':
                sum-=currentNumner
                currentNumner=0
                base=1
            elif currentStr[i]=='+':
                sum+=currentNumner
                currentNumner=0
                base=1
            else:
                currentNumner+=base*int(currentStr[i])
                base*=10
        sum+=currentNumner
        if sum==target:
            results.append(currentStr)
        return
    if position!=0:
        backTrackResults(originalStr,target,currentStr+'+'+originalStr[position],results,position+1)
    backTrackResults(originalStr,target,currentStr+'-'+originalStr[position],results,position+1)
    backTrackResults(originalStr,target,currentStr+originalStr[position],results,position+1)
    

print(targetSum('1011',100))