#include "utils.h"

void
print_header(void *packet)
{
    struct custom_packet_header* pkt;
    pkt = (struct custom_packet_header*)packet;
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("|\t%u\t|\t%u\t|\t%u\t|\t%u\t|\n", pkt->next_hop_addr, pkt->dst_addr,\
            pkt->src_addr, pkt->dst_port);
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void
print_ts(uint32_t *ts)
{
    printf("|\t%u\t|\t%u\n",*ts, *(ts+1));
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void
print_drtt_packet(void *packet)
{
    printf(KGRN,"");
    print_header(packet);
    print_ts(packet + CH_LEN);
    printf(RESET);
}

void
print_header_net(void *packet)
{
    struct custom_packet_header* pkt;
    pkt = (struct custom_packet_header*)packet;
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("|\t0X%04X\t|\t0X%04x\t|\t0X%04X\t|\t0X%04X\t|\n",
            htons(pkt->next_hop_addr), htons(pkt->dst_addr),
            htons(pkt->src_addr), htons(pkt->dst_port) );
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void
print_ts_net(uint32_t *ts)
{
    printf("|\t0X%08X\t|\t0X%08X\n",htonl(*ts), htonl(*(ts+1)) );
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void
print_drtt_packet_net(void *packet)
{
    print_header_net(packet);
    print_ts_net(packet + CH_LEN);
}

void
print_timestamp(struct timestamp* ts)
{
    printf("sec:%u\tfsec:%u\n", ts->sec, ts->fsec);
}
