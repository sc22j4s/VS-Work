"""
Please write your name
@author: James Schwar

"""

# Reminder: You are only allowed to import the csv module (done it for you).
# OTHER MODULES ARE NOT ALLOWED (NO OTHER IMPORT!!!).

import csv


class Leopard:
    def __init__(self, filepath: str) -> None:
        self.filepath = filepath
        

        print(filepath)
        # check if file is locatable
        try:
            file = open(filepath, 'rb')
        except FileNotFoundError:
            print("file not found.")

        

        # check if file is empty
        """
        try:
            test_reader = csv.reader(file)

        except:
            print("asd")
        """
        
        self.header = []
        self.data = []

        # begin reading from csv file
        with open(filepath, 'r') as file:
            reader = csv.reader(file)
            # read first line into header list
            header.append(file.readline())
            # read remaining rows into data list
            for row in reader:
                data.append(row)




        

    def get_header(self) -> list:
        if len(self.header) > 0: 
            return self.header
        else:
            return

    def get_data(self) -> list:
        if len(self.data) > 0:
            return self.data
        else:
            return

    def stats(self) -> dict:
        cols = [] 
        for x in cols:
            cols.append(x)
        stats = {}

        """
            1. make entire stats dict to write smaller dicts to 
            2. number of smaller dicts unknown, setup iterative struct for **column**
            
            read value and check if it is number. 
                if string, iterate to next column 
                if 'NA', '-', or '', ignore, (valdation bool )
            3. define static count mean min max dicts within 
            4. define sum, count, min, max vars 
            
            
        """
        dict_list = []
        isNumber = True
        for enumerate i, x in enumerate(self.data):
            #setup structure for reading in 
            dict_title = self.header[i]
            # var = sum(int(i) for i in line)


            try:
                mean = 0
                sum = 0 
                min = 0
                max = 0
            except ValueError:
                #skip

            if 1 > 2: 

                

            

        # number of entries in header 
        

    def html_stats(self, stats: dict, filepath: str) -> None:
        # delete pass and this comment to write your code
        pass

    def count_instances(self, criteria) -> int:
        """
        Write your docstring to explain how to use this method.
        You are to decide what data type format is criteria or how many
        arguments to this method.
        Delete above and this comment to write your docstring.
        """
        # delete pass and this comment to write your code
        pass


if __name__ == "__main__":
    # DO NOT COMMENT ALL WHEN SUBMIT YOUR FILE, cannot have an if statement
    # with nothing afterwards.

    # test diabetes_data.csv
    test = Leopard("diabetes_data.csv")
    print(test.get_header())
    print(test.get_data())
    stats = test.stats()
    print(stats)
    test.html_stats(stats, "diabetes.html")
    print()

    # test fide2021.csv
    """
    test2 = Leopard("fide2021.csv")
    print(test2.get_header())
    print(test.get_data())
    stats2 = test2.stats()
    print(stats2)
    test2.html_stats(stats2, "fide2021.html")
    print()
    """
    

    # test student.csv
    """
    test3 = Leopard("student.csv")
    print(test3.get_header())
    print(test.get_data())
    stats3 = test3.stats()
    print(stats3)
    test3.html_stats(stats3, "student.html")
    """
    
