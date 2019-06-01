#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SRV_HOST "delta"
#define SRV_PORT 1234
#define CLNT_PORT 1235
#define BUF_SIZE 64
#define TXT_ANSW "I am your client\n"

int main () {

        int s;
        struct sockaddr_in clnt_sin, srv_sin;
        s = socket (AF_INET, SOCK_DGRAM, 0);
        memset ((char *)&clnt_sin, '\0', sizeof(clnt_sin));
        clnt_sin.sin_family = AF_INET;
        clnt_sin.sin_addr.s_addr = INADDR_ANY;
        clnt_sin.sin_port = CLNT_PORT;
        bind (s, (struct sockaddr *)&clnt_sin, sizeof(clnt_sin));
        memset ((char *)&srv_sin, '\0', sizeof(srv_sin));
        srv_sin.sin_family = AF_INET;
        srv_sin.sin_port = SRV_PORT;
        sendto(s, TXT_ANSW, sizeof(TXT_ANSW), 0, (struct sockaddr*)&srv_sin, sizeof(srv_sin));
	printf("message go out\n");
	 
	close (s);
        exit (0);
}

