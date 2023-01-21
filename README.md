
## Content 
    
    1. Username and Password
    2. Bus Reservation System (Basic Idea)
    3. Installation and System
    4. Data Types Used for the major and why?
    5. Function prototypes and Working of each Function. how ? why ?
    6. Important Code Snippets for the code Author.
    7. Introduction about the Author.
    8. Thanks
    
    

## Username and Password

for the first time you need to login as admin as i have not defined the username and password except Admin.

```
Username : admin
Password : admin
```
After you login as admin you can register users and register buses as a plus other than user login benefits

# Bus Reservation System
A bus reservation system is a console application made by Mrunal N. Shah to reserve bus tickets.
The system has 3 major concepts :

    1. User Login
    2. Admin Login
    3. Time 

- The User Login :

This part of the sytem ask user to login with username and password provided by the administator.(No user can login if no username and passwords are generated by the administrator).

After login as User :

    1. User can view List of Bus schedules. 
    2. User can book tickets till the registered bus does not depature. 
        (You can book number of tickets at a time)
    3. User can cancel tickets before one day of bus depature
        (Only one ticket can be cancel at a time)
    4. User can see the layout,status of the particular bus.
        (Seats booked with the passenger names are shown here)


- The Admin Login :

After login as administator :

    1. Admin can view list of Bus schedules.
    2. Admin can book tickets till the registered bus does not depature.
        (admin can book number of tickets at a time)
    3. Admin can cancel tickets till the bus does not depature.
        (admin can cancel number of bus tickets).
    4. Admin can see the layout,status of the particular bus.
        (seats booked with the passenger names are shown here)
    5. Admin can register users. Only the registered user can login
        as user otherwise its invalid.
    6. Admin can register Buses. Only the registered buses can be 
        booked by user and admin, if bus is not registered it cannot
        be booked.

- Time :
Date and Time Validation is done with the bus timing(input during admin registering the bus) and current time. 


## Installation

For the first time you have to use :

``` 
Username : admin

password : admin 

```

and create as many username you want and register as many bus
you want.

Windows : 

    1. Download Code::Blocks with mingw compiler.
    2. Open the cbp file attached to the source code provided
    3. Read the code or Compile the code and run the code.
    4. Learn the code and maybe go through my Important 
       Code Snippet Section for the fast grasp of the code. 
       (currently under development)

Windows : 
    
    1. Compile all the source code on terminal as
        gcc sourcecode1.c sourcecode2.c and so on but i would 
        not recommend you the method as Code::Block does that for 
        you easily and is cross-platform available.

Code::Blocks -
    https://www.codeblocks.org/downloads/ 

Linux :
    (under development)
    
    

## Data Types for major code

- For Login

        1. username is string which is char array.
        2. password is string which is char array.

- Bus Number and Bus Name

        1. Bus Number is taken as string which is char array.
           Here integer can be taken but i thought bus number 
           can be 91015A or 9B so...
        2. Bus Name is always a string. 

- Date and Time

        1. day,month and year are taken integer data types.
        2. hour,minute and second are taken integer data types.
        

## Function Protoypes

- admin.c

    ```
    1. void admin();
        ask the user to input digit and based on input 
        the switch cases work.
    2. void register_bus();
        it is for the bus registration or adding bus details 
        to the busdetails.txt so that the bus can be registered 
        otherwise user cannot book for any bus otherthan the 
        admin registered bus
    3. void register_user(); 
        The function helps to register new username and 
        password which can be used to login as the user. 
        any username doesnot work only registered username
        works for valid login.
    ```
- admin_cancellation.c
    ```
    1. void admin_buscancellation();
        it fetch the data of passengers and seat from the filename 
        based on the respective busnumber and stores them in array. 
        ask the user to cancel number of seats and puts in loop to 
        cancel each seat if occupied and store them into array if not 
        occupied then prints EMPTY Already and no changes to the array.
        at last it runs a loop to overwrite and print all the data 
        from array to filename based on busnumber.

    ```
- cancellation.c

    ```
    1. buscancellation();
        it fetch the data of passengers and seat from the 
        filename based on the respective busnumber and stores 
        them in array. ask the user to cancel one seat if 
        occupied and store them into array if not occupied then 
        prints EMPTY Already and no changes to the array. at last
        it runs a loop to overwrite and print all the data from
        array to filename based on busnumber.
    ```
- busavailability.c

    ```
    1. busavailability();
        fetch data from the database file name busdetails.txt 
        and prints the data of the bus schedule as a whole.
    ```
- busbooking.c

    ```
    1. busbooking();
        fetch the data from the respected filename based on 
        busnumber if available else it ask user to input number
        of seats to be booked and ask if the seat is occupied or 
        not if yes than the user is asked again else the system 
        ask to input name and then store all that in an array.
        after the number of seats are booked the loop runs to print 
        all the data in the file while formatting the previous data.
    ```

- choice.c
    ```
    1. choice();
        ask user to input a digit and based on digit the 
        switch cases are implemented.
    ```

- design.c

    ```
    1. void start_screen();
        designs used in different modules.
    2. void end_screen();
        designs used in different modules.
    3. void creator_details();
        designs used in different modules.
    4. void returnpage();
        designs used in different modules.
    5. void user_welcome();
        designs used in different modules.
    6. void admin_welcome();
        designs used in different modules.
    7. void makedir();
        has a system function to create a folder named "database"
        where all our files are stored.
    ```
- login.c

    ```
    1. int login(); 
        contains both input function and validate function
        and returns value as per the returns
    2. void input_login();
        takes input for username and password and store it in 
        global variable
    3. int validate_login();
        takes the value of global variable and validates it
        with other first admin then fetch username, password data
        from the file name "userdetails.txt" and validate and returns
        0 for invalid input, 1 for user validation and 
        2 for admin validation.
    ```

- main.c

    ```
       main();
        contains all the defined functions in other .c files
    ```

- status.c

    ```
    1. void busstatus();
        it checks it filename for the respective busnumber 
        if available if yes than it calls the bus_layout 
        function.
    2. void bus_layout(char busnumber[]);
        it takes the input of busnumber and prints all the 
        fetched data for the bus. if there is no file created 
        for it then it prints EMPTY for all seats and 
        totalseats = 20.
    ```

- time_validation.c

    ```
    1. int date_validation(int day,int month,int year);
        it takes parameter of the day,month and year you want to 
        compare with the current date
    2. int time_validation(int hour,int minute,int second);
        it takes the input of hour,minute and second you want to 
        compare with the current time.
    ```

## Important Code Snippet

1.
```
while(fscanf(fptr,"%format_specifer1,%format_specifer2,...,%format_specifern",&val1,&val2,val3,...valn) == n){
    //do something
}
```
THE ABOVE CODE FETCH DATA FROM THE FILE AS A SEQUENCE OF n DATATYPES AS A WHOLE.The code takes n datas at a time and stores in the variables mentioned. if the data are less than n or more than n then the program will run as follows:
    
    1. less than n never runs
    2. more than n runs and save n Datatypes in the respective variables and then check if another n data-types are there, if not then the loop ends and if yes than it          stores the data-types of n Sequence to the variable and the loop continues till less than n sequence. 
    
    see the example below.

Example : 

    FILE CONTAINS : 
    1 Mrunal 
    2 Shah
    3 Albion
```

while(scanf(fptr,"%d %s",&num,string) == 2){
    int_variable[num] = num; 
    // on index of num int_variable stores num.
    strcpy(char_variable[num],string); 
    // on index of num char_variable stores string.
}
/*
If the file has like
1 Mrunal
2 

the program stores only 1 on index 1 and Mrunal on index 1.
as 2 is only number without string, it doesnot satisfy 
(== 2) in Code.

This code can be used to fetch data from file accurately and
store them in array and do changes in array and overwrite the
file with "fprintf".
*/
```

2.

```

```



## 🚀 About Me
I am Mrunal Nirajkumar Shah.
An AI and Machine Learning student, I am constantly seeking to expand my knowledge and skills in the field of technology. However, I do not limit myself to one specific domain or technology. I am passionate about mathematics and love applying it to solve complex problems. I also enjoy competitive programming as it allows me to test my skills and knowledge against others in the field. My love for coding and logical thinking is matched by my love for reading books, which I believe helps me to think critically and creatively.

I am a person who is always eager to learn and explore new possibilities. My dedication to my studies is evident in my love for spending hours on my laptop each day. I am not only passionate about AI and ML, but also about technology in general. I am always interested in the latest developments and advancements in this field. This makes me a well-rounded individual who is always looking to learn something new.

I am a person who is not afraid to take on new challenges and is always willing to put in the hard work to achieve my goals. I believe that the ability to continuously learn and adapt is essential in today's world, and I am always working towards becoming a better version of myself.

In my free time, I enjoy playing games and doing creative work. I also love listening to music and reading books, which helps me to relax and recharge. I am a person who is constantly looking to improve myself and explore new opportunities. I am confident that my passion for technology, mathematics, and continuous learning will help me to make a positive impact in the field of AI and Machine Learning.



## Thank you

"Thank you so much for taking the time to view my project. Your interest and support mean a great deal to me. I hope you found the project informative and thought-provoking. Your feedback and suggestions are highly valued, and I look forward to continue to improve and develop my work with your guidance. Thank you once again for your time and consideration. Your support is truly appreciated."

Contact me from the links on :

https://github.com/mrunalnshah
