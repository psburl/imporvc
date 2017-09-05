#include "../network/network.h"
#include "../collections/collections.h"
#include <stdio.h>

int main(){

	ip_t* ip = ip_from_string("255.255.255.0 ");
	ip_print(ip);

    return 0;
}