"""
Please write your name
@author: James Schwar
"""

# Reminder: You are only allowed to import the csv module (done it for you).
# OTHER MODULES ARE NOT ALLOWED (NO OTHER IMPORT!!!).

import csv


class Leopard:

  def __init__(self, filepath: str) -> None:
    # self.filepath = filepath
    # check if file is locatable
    try:
      file = open(filepath, 'rb')
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
        self.header[len(self.header) - 1] = self.header[len(self.header) -
                                                        1].strip()

        # check for empty file
        if (self.header[0] == None):
          print("empty file.")
          return

        # read remaining rows into data list
        for row in reader:
          #line = row.split(',')
          self.data.append(row)
    except FileNotFoundError:
      print("file not found.")




    

  def get_header(self) -> list:
    # returns 'None' if empty
    if self.header != None:
      return self.header
    else:
      return None

  def get_data(self) -> list:
    # returns 'None' if empty
    if self.data != None:
      return self.data
    else:
      return None

  def stats(self) -> dict:

    stats = {}
    dict_list = []

    # iterate for number of columns

    # iterate through each column
    for i in range(len(self.header)):

      is_valid_column = True
      # check if column contains integer values
      # must also check if the item is not redundant

      if not self.data[0][i].isdigit() and self.data[0][
          i] != 'NA' and self.data[0][i] != '' and self.data[0][i] != '-':
        is_valid_column = False

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
          if self.data[k][i] == 'NA' or self.data[k][i] == '' or self.data[k][
              i] == '-':
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

        dict_contents = {'count': count, 'mean': mean, 'min': min, 'max': max}
        stats[dict_title] = dict_contents

    return stats

  def html_stats(self, stats: dict, filepath: str) -> None:

    # create new html file
    with open("filepath.html", "w") as html:

      # write boiler plate
      html.write("<html>\n")
      html.write("<head>\n")
      html.write("<meta charset=\"UTF-8\">\n")

      # css styling
      html.write("<style>\n")

      html.write("table {\n")
      html.write("border: 5px solid black;\n")
      html.write("border-collapse: collapse;\n")
      html.write("width: 500;\n")
      html.write("background-color: grey;\n")
      html.write("}\n")

      html.write("</style>\n")
      html.write("<title>html_stats</title>\n")
      html.write("</head>\n")

      html.write("<body>\n")
      html.write("<table>")

      # write headers to table
      # (count, mean, min, max)
      # styling background color for the header
      html.write("<tr bgcolor={0}>\n".format("lightblue"))

      html.write("<th> Category </th>\n")
      for key in list(stats.values())[0].keys():
        html.write("<th>{0}</th>\n".format(key))

      header_list = []
      for keys in stats:
        header_list.append(keys)

      # write data to table via nested iteration
      # enumeration allows for access of keys in list
      for i, stats_dicts in enumerate(stats.values()):
        # append next header element
        html.write("<tr><th>{0}</th>\n".format(header_list[i]))

        for value in stats_dicts.values():
          html.write("<th>{0}</th>\n".format(value))
        html.write("<tr>\n")

      html.write("</body>\n")
      html.write("</html>\n")

  def count_instances(self, criteria: dict) -> int:
    """

        In this method, 'criteria' is accepted as a dictionary data type as it can store a list of parameters in pairs, 
        the header name and the desired value in that header as key value pairs, which is passed down as the main argument.
        The keys and values must be passed down as strings.

        The method returns an integer value denoting the number of elements in the csv with the matching parameters.

    """
    # initialized variable to be incremented
    instances = 0

    # split dict into separate iterable lists
    args = list(criteria.keys())
    values = list(criteria.values())    
     
    # iterate through data list
    for row in self.data:
      
      # count variable showing how many dict conditions met
      criteria_met = 0 

      for i, x in enumerate(args):
        # check if key is valid
        if x in self.header:
          dictvalue = values[i]
          data = row[self.header.index(x)]
          
          if dictvalue == data:
            criteria_met = criteria_met + 1

      # iterated through all criteria with match:
      if criteria_met == len(args):
        # row is a match
        instances = instances + 1

    return instances


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

  test2 = Leopard("fide2021.csv")
  print(test2.get_header())
  print(test.get_data())
  stats2 = test2.stats()
  print(stats2)
  test2.html_stats(stats2, "fide2021.html")
  print()

  # test student.csv

  test3 = Leopard("student.csv")
  print(test3.get_header())
  print(test.get_data())
  stats3 = test3.stats()
  print(stats3)
  test3.html_stats(stats3, "student.html")
