f1 = open(input("Enter file to read: "), 'r')
f2 = open(input("Enter file to write: "), 'w')
text = f1.read()
text_w = text[::-1]
f2.write(text_w)