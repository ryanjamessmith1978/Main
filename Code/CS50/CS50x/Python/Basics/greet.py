from sys import argv

## sys is like module or library

for i in range(len(argv)):
    print(f"hello, {argv[i]}")

#for arg in argv[1:]: # slicing the list starting at index 1.
 #   print(arg)