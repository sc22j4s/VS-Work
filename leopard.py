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

        # begin reading from csv filehju
        with open(filepath, 'r') as file:
            reader = csv.reader(file)
            # read first line into header list
            line = file.readline()
            # split line into list and append 
            self.header = line.split(',').copy()
 



            # check for empty file
            if(self.header[0] == ""):
                print("empty file.")
                return
            
            # read remaining rows into data list
            for row in reader:
                #line = row.split(',')
                self.data.append(row)




        

    def get_header(self) -> list:
        print("\nHEADER\n")
        if len(self.header) > 0: 
            return self.header
        else:
            return

    def get_data(self) -> list:
        print("\nDATA\n")
        if len(self.data) > 0:
            return self.data
        else:
            return

    def stats(self) -> dict:
        print("\nSTATS\n")

        dict_stats = {}

        """
            1. make entire stats dict to write smaller dicts to 
            2. number of smaller dicts (columns) unknown, setup iterative struct per column

            --iterating data top to down allgood--
            
            read value and check if it is number.S 
                **one-time check** if string, iterate to next column 
                if 'NA', '-', or '', ignore, (valdation bool )
            3. define static count mean min max dicts within 
            4. define sum, count, min, max vars 
            
            
        """
        dict_list = []

        # iterate for number of columns

        # iterate through each column
        for i in range(len(self.header)):

            is_valid = True
            # check if data item is an integer
            print(self.data[0][i])
            if (not isinstance(self.data[0][i], int)) and self.data[0][i] != 'NA' and self.data[0][i] != '' and self.data[0][i] != '-':

                is_valid = False
                print("{0} is not integer. skipping", self.header[i])
            
            if is_integer:
                is_valid = True

                if self.data[0][i] == 'NA' and self.data[0][i] == '' and self.data[0][i] == '-':
                    is_valid = False
                
                if is_valid:
                    for k in range(len(self.data)):
                        print(self.data[k][i])
                # ignore data entry 
                

                

                
                
        return dict_stats
            

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
    