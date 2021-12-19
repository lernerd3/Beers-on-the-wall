
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#define _OPEN_SYS_ITOA_EXT
#include<fcntl.h> 
#include<errno.h> 
#include <sys/stat.h>


// declerations 
int num_beers;
int count;
char c;
FILE *store_txt_f;
char text[20];
char line[256];
pid_t  pid;
int wait_time = 10;
FILE *beer_out;
int current_mode;
struct stat fs;




//get input from command line, if non entered exit 1
int main(int argc, char *argv[]){
   
    //makes sure we have at least one argument 
    if(argc<=1) {
        //print file descriptor, pid and ppid   
        printf("PID = %ld PPID = %ld", (long)getpid(), (long)getppid());
        printf("\n");
        //usaage statement
        printf("Usage:\n ");
        printf("\n");
        printf("No arguments have been passed."); 
        printf("\n");
        printf("Please enter one argument by typing in to the comand line './lab7_1 some_number', replacing some_number with an integer between 1 and 100. Exit(1)" );
        exit(1);
     } 

     //makes sure we have no more than one argmuent 
     if(argc > 2){
       //print file descriptor, pid and ppid   
        printf("PID = %ld PPID = %ld", (long)getpid(), (long)getppid());
       printf("Usage:\n ");
       printf("\n");
        printf("Too many arguments have been passed."); 
        printf("\n");
        printf("Please enter one argument by typing in to the comand line './lab7_1 some_number', replacing some_number with an integer between 1 and 100. Exit(1)" );
       exit(1);
     }

    

     // converts argument  to int 
     int num_beers = atoi(argv[1]);  
     
    
    //checks if input is in range, if not exit 99
     if((num_beers > 100) ||(num_beers < 1)){
       printf(" Sorry, the number is not in the desired range. Exit (Status 99)");
       exit(99);
     }

    

  
    // Open files
    store_txt_f = fopen("bottlesofbeer.txt", "r");
    beer_out = fopen("beer.out", "w");
    
    
    // reads file one line at a time, decrements num_beers
    for(count = 0; count <= num_beers; num_beers --){
      beer_out = fopen("beer.out", "a");
     //when there are no more beers
      if(num_beers == 0){
         //get file descriptor
        int fd = open("bottlesofbeer.txt", O_RDONLY | O_CREAT);
        //print file descriptor, pid, ppid
        // printf(" fd = %d PID = %ld PPID = %ld", fd, (long)getpid(), (long)getppid());
        printf("\n");
        printf(" NO MORE BOTTLES OF BEER ON THE WALL\n");
        fprintf(beer_out, " fd = %d PID = %ld PPID = %ld\n", fd, (long)getpid(), (long)getppid());
        fprintf(beer_out," NO MORE BOTTLES OF BEER ON THE WALL\n");
        

        
        exit(0);
      }
       
      //prints file line by line
      while (fgets(line, sizeof(line), store_txt_f)) {
        // should replace \n with null
        line[strcspn(line, "\n")] = 0;
        
        //get file descriptor
        int fd = open("bottlesofbeer.txt", O_RDONLY | O_CREAT);
        //print file descriptor, pid, ppid
        // printf(" fd = %d PID = %ld PPID = %ld", fd, (long)getpid(), (long)getppid());
        // printf("\n");

        fprintf(beer_out, " fd = %d PID = %ld PPID = %ld\n", fd, (long)getpid(), (long)getppid());
       
      
      
       

        printf(" %d %s",num_beers, line);
        fprintf(beer_out," %d %s\n",num_beers, line);
       
        
       
    }
    
   
          store_txt_f = fopen("bottlesofbeer.txt", "r");
          // beer_out = fopen("beer.out", "w");
          fclose(beer_out);
          printf("\n");
          
          // //new process
          pid = fork();
          
          //instructions for child
          if(pid == 0){
              
              //holder for conversion of int to string
              char num_pass[50];
              //converts int to string
              sprintf(num_pass, "%d", num_beers);
              
              //calls lab7_2 paassing num beers to it 
              char *args[]={"./lab7_2",num_pass,NULL};
              execvp(args[0],args);
              fprintf(stderr, "Failed to execute %s", args[0]);
              exit(EXIT_FAILURE);
      } 
      if(pid > 0){
        wait(&wait_time);
       
        
      }
  }

}
    

   

  
    
    
