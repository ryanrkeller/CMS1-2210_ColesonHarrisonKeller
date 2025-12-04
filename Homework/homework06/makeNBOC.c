// resources used: https://keasigmadelta.com/blog/how-to-convert-endianness-in-c-c-in-4-different-ways/
                // https://stackoverflow.com/questions/32786493/reversing-byte-order-in-c
                // https://stackoverflow.com/questions/15863775/ntohl-vs-htonl-in-little-endian

#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>   

int is_little_endian(void)
{
    uint16_t value = 0x0001;
    unsigned char *byte_ptr = (unsigned char *)&value;

    return (*byte_ptr == 0x01);
}

uint32_t make_network_byte_order(uint32_t host_value)
{
    return htonl(host_value);
}

uint32_t make_host_byte_order(uint32_t network_value)
{
    return ntohl(network_value);
}

int main(void)
{
    uint32_t host_value       = 0xBEEFCAFE;
    uint32_t network_value    = 0;
    uint32_t roundtrip_value  = 0;

    if (is_little_endian()) {
        printf("Detected byte order: Little Endian\n\n");
    } else {
        printf("Detected byte order: Big Endian\n\n");
    }

    printf("Original host value: 0x%08X\n", host_value);

    network_value = make_network_byte_order(host_value);
    printf("Value in Network Byte Order: 0x%08X\n", network_value);

    roundtrip_value = make_host_byte_order(network_value);
    printf("Back to host byte order (roundtrip): 0x%08X\n\n", roundtrip_value);

    if (is_little_endian()) {
        printf("This machine is little endian, bytes have been swapped.\n");
    } else {
        printf("This machine is big endian, no need to swap bytes\n");
    }

    return 0;
}

