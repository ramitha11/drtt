#include "populate_header.h"

int
populate_header(uint16_t next_hop_addr, uint16_t dst_addr, uint16_t src_addr,\
             uint16_t dst_port, void **packet)
{
    struct custom_packet_header* hdr;
    hdr = (struct custom_packet_header*)*packet;
    hdr->next_hop_addr = next_hop_addr;
    hdr->dst_addr = dst_addr;
    hdr->src_addr = src_addr;
    hdr->dst_port = dst_port;
    
}
