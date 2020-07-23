/*
Lab 03 - C Programming in Linux
Class ID : SE1501
Student ID : HE150204
Student Name : Đỗ Sơn Tùng
I declare that this assignment is my own work
in accordance with FPT Policy.
*/
#include <stdio.h>
#include <stdlib.h>

void workingdirect(){
   system("pwd");
}

void cpuinfo(){
   system("cat /proc/cpuinfo");
}

void diskspace(){
   system("df -h");
}

#define CHECKNAME "\
#/bin/bash \n\
echo \"Please enter the directory path: \" \n\
read name \n\
if [ -d $name ] \n\
then \n\
    ls -l $name \n\
else \n\
    echo \"$name is not a directory.\" \n\
fi \n\
exit 0 \n\
"

#define CHECKDIR "\
#/bin/bash \n\
echo \"Please enter file name: \" \n\
read name \n\
if [ -f $name ] \n\
then \n\
    echo \"$name is an ordinary file, with content:\" \n\
    cat $name \n\
elif [ -d $name ] \n\
then \n\
    echo \"$name is a directory.\" \n\
else \n\
    echo \"$name does not exist, or it is neither an ordinary file nor a directory.\" \n\
fi \n\
exit 0 \n\
"

void count(){
    printf("Number of directories in current directory: \n");
    system("ls -d */ | wc -l");
    system("ls -d */ |more");
}    
    

void enter(){
    printf("Hit <Enter> to continue.\n");
    getchar();
}

int main(){
  char c;
  printf("********************************************************************\n");
  printf("Please chooose from the following option; type the option and hit the <Enter> key.\n");
  printf("a or A To display the current directory.\n");
  printf("b or B To list names of the files in a given directory.\n");
  printf("c or C To display whether a file is a simple file or directory.\n");
  printf("d or D To show CPU info.\n");
  printf("e or E To show disk space usage.\n");
  printf("g or G To Count number of directories in the current directory.\n");
  printf("q or Q To exit the program.\n");
  printf("Enter your choice and hit <Enter>:\n");
  while(1){
  scanf("%c",&c);
      switch (c)
      {
      case 'a':
         workingdirect();
         enter();
         break;
         
      case 'b':
          system(CHECKNAME);
          enter();
          break;
          
      case 'c':
          system(CHECKDIR);
          enter();
          break;
          
      case 'd':   
         cpuinfo();
         enter();
         break;
         
      case 'e':
         diskspace();
         enter();
         break;
         
      case 'g':
          count();
          enter();
          break;
          
      case 'q':
          printf("Bye now!\n");
          exit(0);
          break;
          
      default:
          printf("Enter your choice and hit <Enter>:\n");
          break;
      }

  }
  return 0;

}

