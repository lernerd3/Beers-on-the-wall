# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include<fcntl.h> 
#include<errno.h> 

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


//gets args
int main(int argc, char **argv){
  
//opens file
store_txt_f = fopen("happenstofall.txt", "r");
beer_out = fopen("beer.out", "a");
    
 
      // reads file one line at a time,   
      while (fgets(line, sizeof(line), store_txt_f)) {
        //get file descriptor
        int fd = open("bottlesofbeer.txt", O_RDONLY | O_CREAT);
        //print file descriptor, pid, ppid
        printf(" fd = %d PID = %ld PPID = %ld", fd, (long)getpid(), (long)getppid());

         //write to beer.out
        fprintf(beer_out, " fd = %d PID = %ld PPID = %ld\n", fd, (long)getpid(), (long)getppid());
        

      
        printf("\n");
            printf(" %s", line);
            fprintf(beer_out, " %s\n", line);
            
            
        }
        
            
      printf("\n");
            
            
        
      store_txt_f = fopen("happenstofall.txt", "r");
      // beer_out = fopen("beer.out", "w");
        
      fclose(beer_out);
      
      //new process
            
      pid = fork();
      if(pid == 0){
        //calls lab_3 passing num beers
          char *args[]={"./lab7_3",argv[1],NULL};
          execvp(args[0],args);
          
         
          } 

          if(pid > 0){
            wait(&wait_time);
            //close file
            fclose(store_txt_f);
            //terminate
            exit(0);
          }
        
        
        printf("\n");
        

    

}
