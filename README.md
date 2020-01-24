# __Mapper-Reducer__
This Readme gives a brief overview of the problem, the files included and instructions to run the program
* Author : Prudhvee Narasimha Sadha
* Email  : prudhvee.sadha@ufl.edu
* UFID   : 4689 9656
--------------------
### __II. Files Included__
* __mapper.c__ - The mapper program processes these tuples to generate a weighted profile based on the set of rules defined in the problem statement.
* __reducer.c__ - Reads the mapped tuples one by one and converts them to the format (userID,topic, total) (for each of the topics) and prints them to the standard output.
* __combiner.c__ - Uses various system calls like fork,exec,pipe and dup2 to call the Mapper and Reducer.
* __input.txt__ - List of tuples that are input to the Mapper.
--------------------
### __III. How to run the Combiner__
* Open the folder in the terminal.
* run 'make' - to compile all the files and generate the executables.
* To execute the Mapper run __'./mapper.out <path_to_input_file>'__
* To execute the Reducer run __'./reducer.out'__. Reduce takes tuples one by one from STDIN and also detects EOF signal to stop processing the tuples.
* To execute the Combiner run __'./combiner.out <path_to_input_file>'__. 
--------------------
### __IV. Outputs:__
The Reduced tuples are displayed on the standard output.
