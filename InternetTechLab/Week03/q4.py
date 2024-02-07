words = ['hello', 'akarsh', 'python', 'world', 'zebra', 'ball']
length = len(words)

print("Before sorting: ")
print(words)

for i in range(length - 1) : 
    min = i
    for j in range(i + 1, length) :
        if(words[j] < words[min]) :
            min = j
    (words[i], words[min]) = (words[min], words[i])

print("After sorting: ")
print(words)