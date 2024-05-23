from collections import defaultdict

def readNumberOfTestCases():
    return int(input())

def readArrayFromInput():
    return list(map(int, input().split()))

def main():
    numberOfTestCases = readNumberOfTestCases()
    
    while numberOfTestCases > 0:
        numberOfTestCases -= 1
        arraySize =readNumberOfTestCases()
        numbers = readArrayFromInput()
        
        abCount = defaultdict(int)
        bcCount = defaultdict(int)
        acCount = defaultdict(int)
        ab3Count = defaultdict(int)
        bc3Count = defaultdict(int)
        ac3Count = defaultdict(int)
        
        result = 0
        
        for i in range(arraySize - 2):
            current = numbers[i]
            nextNumber = numbers[i + 1]
            afterNext = numbers[i + 2]
            
            abCount[(current, nextNumber)] += 1
            bcCount[(nextNumber, afterNext)] += 1
            acCount[(current, afterNext)] += 1
            
            triple = [current, nextNumber, afterNext]
            ab3Count[tuple(triple)]+=1;
            bc3Count[tuple(triple)]+=1;
            ac3Count[tuple(triple)]+=1;
            
            result += abCount[(current, nextNumber)]-ab3Count[tuple(triple)]
            result += bcCount[(nextNumber, afterNext)]-bc3Count[tuple(triple)]
            result += acCount[(current, afterNext)]-ac3Count[tuple(triple)]
        
        print(result)

if __name__ == "__main__":
    main()
