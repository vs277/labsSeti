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
        int s;
        socklen_t from_len;
        char buf[BUF_SIZE];
        struct sockaddr_in sin;

        s = socket (AF_INET, SOCK_DGRAM, 0);
        memset ((char *)&sin, '\0', sizeof(sin));
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = INADDR_ANY;
        sin.sin_port = SRV_PORT;
        bind (s, (struct sockaddr *)&sin, sizeof(sin));
       
        while (1) {
                from_len = recvfrom(s, buf, BUF_SIZE, 0, NULL, NULL);
		if (from_len > 0)
		{
			
			printf("%s\n", buf);
			break;//comment this = server not die
		}
	}
        close(s);
        printf("end worked \n");
        return 0;
}

