#This program says hello and asks for your name.

print("Hello World!")
print("What's your name?")
myName = input()
print("It's good to meet you", myName , ".")
print("The length of your name is:")
print(len(myName))
print("What's your age?")
myAge = input()
print("You will be", str(int(myAge) + 1), "in a year.")