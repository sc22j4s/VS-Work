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
            # remove '\n' from last element
            self.header[len(self.header)-1] = self.header[len(self.header)-1].strip()

            # check for empty file
            if(self.header[0] == None):
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

        stats = {}
        dict_list = []

        """
            1. make entire stats dict to write smaller dicts to 
            2. number of smaller dicts (columns) unknown, setup iterative struct per column

            --iterating data top to down allgood--

            read value and check if it is number.
                **one-time check** if string, iterate to next column
                if 'NA', '-', or '', ignore, (valdation bool )
            3. define static count mean min max dicts within
            4. define sum, count, min, max vars
        """

        # iterate for number of columns

        # iterate through each column
        for i in range(len(self.header)):

            is_valid_column = True
            # check if column contains integer values
            # must also check if the item is not redundant

            # todo: cast as int!!!
            if not self.data[0][i].isdigit() and self.data[0][i] != 'NA' and self.data[0][i] != '' and self.data[0][i] != '-':
                is_valid_column = False
                print("{0} is not integer. skipping {1}".format(self.data[0][i], self.header[i]))


            if is_valid_column:
               # iterate through column
                dict_title = self.header[i]
                dict_contents = {}
                sum = 0
                # assign min/max variables to data items
                min = int(self.data[0][i])
                max = int(self.data[0][i])
                count = 0
                

                for k in range(len(self.data)):
                    is_integer = True
                    # skip missing data item
                    if self.data[k][i] == 'NA' or self.data[k][i] == '' or self.data[k][i] == '-':
                        is_integer = False
                    
                    if is_integer:
                        # cast string as int for processing
                        item = int(self.data[k][i])
                        # process variables
                        count = count + 1
                        sum = sum + item

                        if item < min:
                            min = item
                        if item > max: 
                            max = item
                
                # calculate average, rounded 2 d.p
                if count > 0:                    
                    mean = round(sum / count, 2)

                # assign dictionary key/value pairs

                dict_contents = {
                    'count': count,
                    'mean': mean,   
                    'min': min,
                    'max': max
                }
                # print("appending {0} to stats from column {1}".format(dict_contents, dict_title))
                stats[dict_title] = dict_contents

        return stats
            

        # number of entries in header 
        

    def html_stats(self, stats: dict, filepath: str) -> None:


        with open("filepath.html","w") as html:
            html.write("<html>\n")
            html.write("<head>\n")
            html.write("<meta charset=\"UTF-8\">\n")
            html.write("<style>\n")
            html.write("table, th, td {\n")
            html.write("border: 1px solid black;\n")
            html.write("border-collapse: collapse;\n")
            html.write("}\n")
            html.write("</style>\n")
            html.write("<title>Student grades</title>\n")
            html.write("</head>\n")
            html.write("<body>\n")
            html.write("<h2>Test scores</h2>\n")
            html.write("<table>\n")

            for i in stats: 
                for k in i: 
                    x=1
                    




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
    # print(test.get_data())
    stats = test.stats()
    print(stats)
    test.html_stats(stats, "diabetes.html")
    print()

    # test fide2021.csv
    
    test2 = Leopard("fide2021.csv")
    print(test2.get_header())
    # print(test.get_data())
    stats2 = test2.stats()
    print(stats2)
    test2.html_stats(stats2, "fide2021.html")
    print()
    
    

    # test student.csv
    
    test3 = Leopard("student.csv")
    print(test3.get_header())
    # print(test.get_data())
    stats3 = test3.stats()
    print(stats3)
    test3.html_stats(stats3, "student.html")
    
    