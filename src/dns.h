//
// Created by aditya on 16/12/21.
//

#ifndef DISPERSION_TOOL_DNS_H
#define DISPERSION_TOOL_DNS_H
char* reverse_dns_lookup(char *ip_addr);
char *dns_lookup(char *addr_host, struct sockaddr_in *addr_con);
#endif //DISPERSION_TOOL_DNS_H
