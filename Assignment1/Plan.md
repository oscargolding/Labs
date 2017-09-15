**Task Breakdown**

First, identify the main components or steps that you think the assignment will involve :

* Implementing the three main c files with their respective functions.
* Solving each of the parts of the assignment individually so as to create a working whole solution.
* Implementing the mandelbrot.c file, which includes creating all of the functions. 
  This should initially start by running tests on logic using ASCII (as recommended in the approach to the problem).
* The steps towards solving the problem should be logically broken up. 
  E.g. it would make sense to solve the escapeSteps function first before starting on the escapeGrid.
* Start working on the server so that an image can actually be delivered.
* The final part will be to work on colouring of the program.

**Task Requirements**

For each of those components or steps above, work out what is involved/required, make an estimate of how long it will take, 
 and decide who is going to do it (or whether you will work on it together):

What needs doing? |	What does it involve?	| How long will it take? | Who's going to do it?
escapeSteps function in mandelbrot.c	| Determines whether a particular set of co-ordinates are in the Mandelbrot set or not. 
 This will return an int, which is the number of steps required to escape the set. The logic should be further broken down into 
 more functions in order to implement this.	| 60min +	| Oscar + Jack
drawMandelBrot function in mandelbrot.c	| Need to use nested while loops in order to print out a Mandelbrot tile. 
 The function escapeSteps will have to be called in order to test this. An int called z is also used as a form of pixel jump. 
 Testing on this function should be done using ASCII symbols. After the completion of escapeGrid , the drawMandelBrot function will call 
 on this directly.	| 120min +	| Jack + Michaela
escapeGrid function in mandelbrot.c | Fills an array that determines the number of steps it took for each pixel to escape the mandelbrot 
 set. This will then be called in the function called drawMandelBrot so that its grid can be printed out.	| 120 min +	| Oscar + Michaela
routeRequest function in server.c |	Use the existing server logic in order to print it out within a browser. 
 The function should act to both take in certain coordinates and zoom levels, and return an image of the location in the Mandelbrot set. 
 Moreover, logic should be installed within the function so that a general image can be produced. Some preliminary testing should be 
 done on the Week6 poetry server to see the image that has been produced. |	180min +	| Oscar + Jack
pixelColor in pixelColor.c	| This adds unique colours to certain parts of the Mandelbrot image using structs and relevant RGB values. 
 Some initial testing on this can be done by moving from black and white towards the different colours.	| 180min+	| Oscar + Michaela
Debugging	| Check for cases that haven't been considered so as to catch unique conditions that might break the code.	
 | 180min +	| Oscar + Jack + Michaela
Attached static functions to the above cases. |	There will need to be supporting functions to the above. This will help to break down the 
 logic and make it more readable.	| 120min +	| Oscar + Jack + Michaela
Individually testing the above functions. |	All the functions will need to be tested for correctness before the next part of the 
 assignment can be done.	| 60 min + |	Oscar + Jack + Michaela
 
 **Learning from experience: Assignment 0**
 
 What did you learn from the process of completing the previous assignment? How could you take that into account during this assignment? 
 What can you do now to prevent any mistakes or problems from happening again?

* Need to more rigorously check the final code for bugs that I haven't detected. This involves actively thinking of cases where the code 
 can fail, and implementing changes that can fix this.
* Have a better initial plan. Need to dedicate more time towards conceptually solving the problems that may arise over the course of 
 the assignment.
* Space out the amount of time that I spend on the assignment, instead of doing it all in one large block. Need to have a regular plan 
 whereby I dedicate a certain amount of time towards the assignment.
* Actively look for ways to simplify the logic in the code. Making more use of functions, along with considering all the syntax I know to 
 create better solutions. The final code shouldn't be inefficient, and instead should be simple and easy to understand.
 
**Identifying potential problems**
What problems might you encounter over the course of the assignment? What could go wrong? What do you need to plan around? 
What could you do to work around or overcome those problems?

* Failing to conceptually understand certain parts of the assignment. This can be resolved by asking someone in my group about how to solve 
  the problem.
* Small bugs within the program that stop it from working properly. To resolve this, there must be careful checking of the code, and a 
 solid conceptual understanding of all the individual functions that are being implemented.
* Time constraints, a certain proportion of each day should be dedicated towards working on the assignment before the deadline.
* Organisation issues, means each member of the group should have a clear understanding of the work that they're supposed to be doing.
