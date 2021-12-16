//
// Created by aditya on 16/12/21.
//
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>
#include <log.h>
#include "utils/memory.h"


char* reverse_dns_lookup(char *ip_addr) {
	struct sockaddr_in temp_addr;
	socklen_t len;
	char buf[NI_MAXHOST], *ret_buf;
	log_debug("Performing Reverse DNS Lookup");
	temp_addr.sin_family = AF_INET;
	temp_addr.sin_addr.s_addr = inet_addr(ip_addr);
	len = sizeof(struct sockaddr_in);
	int got_info = getnameinfo((struct sockaddr *) &temp_addr, len, buf,sizeof(buf), NULL, 0, NI_NAMEREQD);
	if (!got_info) {
		log_error("Could not resolve reverse lookup of hostname");
		return NULL;
	}
	ret_buf = (char*)my_malloc((strlen(buf) +1)*sizeof(char) );
	strcpy(ret_buf, buf);
	log_debug("IP = %s | Reverse DNS = %s", ip_addr, ret_buf);
	return ret_buf;
}

char *dns_lookup(char *addr_host, struct sockaddr_in *addr_con)
{
	log_debug("Performing DNS Lookup\n");
	struct hostent *host_entity;
	char *ip=(char*)my_malloc(NI_MAXHOST*sizeof(char));
	int i;
	
	if ((host_entity = gethostbyname(addr_host)) == NULL)
	{
		// No ip found for hostname
		log_error("No IP found for hostname = %s\n", addr_host);
		return NULL;
	}
	
	//filling up address structure
	strcpy(ip, inet_ntoa(*(struct in_addr *)
			host_entity->h_addr));
	
	(*addr_con).sin_family = host_entity->h_addrtype;
	(*addr_con).sin_port = htons (0);
	(*addr_con).sin_addr.s_addr  = *(long*)host_entity->h_addr;
	log_debug("Hostname = %s | IP = %s", addr_host, ip);
	return ip;
}