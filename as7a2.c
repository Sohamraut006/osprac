#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

 int main()
 {
  
   int fd,fd1;
   
   char *myfifo="myfifo";
   char *myfifo1="myfifo1";
   char buf[512],ch[512];
   int words=0,lines=1,i=0;
   FILE *fp;
   mkfifo(myfifo,0777);
   mkfifo(myfifo1,0777);
   fd=open(myfifo,O_RDONLY);
   read (fd,buf,1024);
   printf("message received by the reader in FIFO1:\n");
   sleep(2);
   while (buf[i]!='\0')
   {
   
    if(buf[i]==' ')
     words++;
    if(buf[i]=='\n')
     lines++;
     i++;
   }
      fp=fopen("text.txt","w");
      fprintf(fp,"Total words=%d\n",words);
      fprintf(fp,"Total lines=%d\n",lines);
      fprintf(fp,"Total characters=%d\n",i);
      fclose(fp);
      printf("Analysis is wrote in file test.txt...\n");
      sleep(2);
      i=0;
      fp=fopen("text.txt","r");
      while (!feof(fp))
      {
       ch[i]=fgetc(fp);
       i++;
      }
        fclose(fp);
        close(fd);
        unlink(myfifo);
        fd1=open(myfifo1,O_WRONLY);
        write (fd1,ch,sizeof(ch));
        printf("mesage wrote in FIFO2 by reader ...\n");
        sleep(2);
        close(fd1);
        unlink(myfifo1);
        return 0;
        
        }
      
