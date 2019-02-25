#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define  READ    0 
#define  WRITE   1 

int main ( )
{ 
          int     fd [2],  bytesread ;
          char    message [100] ;
          char    upper [100];
          pipe( fd ) ; 
          if ( fork (  )  ==  0 )    
          { 
                printf(" Input a String: ");
                scanf("%s",&message);
                close( fd [READ] ) ; 
                write( fd [WRITE], message, strlen(message) + 1) ;
                close( fd [WRITE] ) ;                                       /*  close used end  */
          }  
          else                                                              /* parent,  reader*/
          { 
                close( fd [WRITE] ) ; /* close unused end  */
                read(fd [READ], upper, 100) ;
                printf ("Upper Case: %s", toupper(upper) ) ;
                close( fd [READ] ) ;                                        /*  close used end  */
          } 
} 
