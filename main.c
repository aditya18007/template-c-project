#include <netinet/in.h>
#include <netdb.h>
#include "src/dns.h"

#include "src/utils.h"
int main(){
	init_utils();
	int sockfd;
	char *ip_addr, *reverse_hostname;
	struct sockaddr_in addr_con;
	int addrlen = sizeof(addr_con);
	char net_buf[NI_MAXHOST];

	ip_addr = dns_lookup("www.amazon.com", &addr_con);
	reverse_hostname = reverse_dns_lookup(ip_addr);
}