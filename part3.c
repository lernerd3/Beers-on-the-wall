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



//gets arguments 
int main(int argc, char **argv){
  

  
  //converts argument to int
  int num_beers = atoi(argv[1]);
  //decriments nnum beers
  num_beers--; 
  if(num_beers == 0){
    
    sleep(1);
  
    //close file
    fclose(store_txt_f);
    //terminates
    exit(0);

  }
  // printf(" %d", num_beers); 
  
  
  store_txt_f = fopen("remaining.txt", "r");
  beer_out = fopen("beer.out", "a");
    
    
  // reads file one line at a time, decrements num_beers
  while (fgets(line, sizeof(line), store_txt_f)) {
         //get file descriptor
        int fd = open("bottlesofbeer.txt", O_RDONLY | O_CREAT);
        //print file descriptor, pid, ppid
        // printf(" fd = %d PID = %ld PPID = %ld", fd, (long)getpid(), (long)getppid());
        printf("\n");
        fprintf(beer_out," fd = %d PID = %ld PPID = %ld\n", fd, (long)getpid(), (long)getppid());
        printf(" %d %s",num_beers, line);
        fprintf(beer_out, " %d %s\n",num_beers, line );
        
    }
    
    
  printf("\n");
  printf("\n");
  printf("\n");
      
    
     
  
    
  store_txt_f = fopen("remaining.txt", "r");
  //causes 1 second pause between iterations
  sleep(1);
  
    //close file
    fclose(store_txt_f);
    fclose(beer_out);
    //terminates
    exit(0);
    
  

}
