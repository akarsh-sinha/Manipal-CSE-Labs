class My_solution:
    def __init__(self):
        self.input_string = ""

    def get_String(self):
        self.input_string = input("Enter a string: ")

    def print_String(self):
        print("String in uppercase:", self.input_string.upper())

obj = My_solution()
obj.get_String()
obj.print_String()
