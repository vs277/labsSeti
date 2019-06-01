#include <sys/types.h>    
#include <sys/socket.h>    
#include <netinet/in.h>  
#include <netdb.h>  
#include <memory.h> 
#include <stdio.h>
#include <unistd.h>
#define SRV_PORT 1234  
#define BUF_SIZE 64 
#define TXT_QUEST "Who are you?\n" 

int main () { 
	int s, s_new; 
	socklen_t from_len; 
	char buf[BUF_SIZE]; 
	struct sockaddr_in sin, from_sin; 

	s = socket (AF_INET, SOCK_STREAM, 0); 
	memset ((char *)&sin, '\0', sizeof(sin)); 
	sin.sin_family = AF_INET; 
	sin.sin_addr.s_addr = INADDR_ANY; 
	sin.sin_port = SRV_PORT; 
	bind (s, (struct sockaddr *)&sin, sizeof(sin)); 
	listen (s, 3); 
	while (1) { 
		from_len = sizeof(from_sin); 
		s_new = accept (s,(struct sockaddr *)&from_sin, &from_len); 
		write (s_new, TXT_QUEST, sizeof(TXT_QUEST)); 
		from_len = read (s_new, buf, BUF_SIZE); 
		write (1, buf, from_len); 
		shutdown (s_new, 0); 
		close (s_new);
                break; 
	}; 
	close(s);
	printf("end worked \n");
	return 0;
}
