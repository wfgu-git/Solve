/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const ld eps = 1e-10;

int cont[2][10];
map<string, int> mep[2];
string raw;
vector<int> fac = {2, 3, 5, 7};
void work() {
  int T;
  cin >> T;
  while (T--) {
    memset(cont, 0, sizeof(cont));
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 3; ++j) {
        cin >> raw;
        for (int k = 0; k < 2; ++k) {
          if (mep[k][raw] == 4) {
            cont[k][2] += 2;
            continue;
          }
          if (mep[k][raw] == 6) {
            cont[k][2]++;
            cont[k][3]++;
            continue;
          }
          cont[k][mep[k][raw]]++;
        }
      }
    }
    ld ex1 = 0, ex2 = 0;
    for (int x : fac) {
      ex1 += (ld)(cont[0][x]) * ((ld)log(x) / (ld)log(2.0));
      ex2 += (ld)(cont[1][x]) * ((ld)log(x) / (ld)log(2.0));
    }
    if (abs(ex1 - ex2) < eps) {
      cout << 'E' << '\n';
      continue;
    }
    if (ex1 > ex2) {
      cout << 'A' << '\n';
      continue;
    }
    if (ex1 < ex2) {
      cout << 'B' << '\n';
      continue;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  mep[0]["UFS2.0"] = 2;
  mep[0]["UFS2.1"] = 3;
  mep[0]["eMMC5.1"] = 5;
  mep[0]["LPDDR3"] = 4;
  mep[0]["LPDDR4"] = 6;
  mep[0]["Sparse"] = 7;
  mep[0]["Normal"] = 3;

  mep[1]["UFS2.0"] = 3;
  mep[1]["UFS2.1"] = 5;
  mep[1]["eMMC5.1"] = 2;
  mep[1]["LPDDR3"] = 7;
  mep[1]["LPDDR4"] = 3;
  mep[1]["Sparse"] = 4;
  mep[1]["Normal"] = 6;

  work();
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netpacket/packet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <linux/if_ether.h>
#include <linux/in.h>
#include <linux/if.h>

typedef int int32;
typedef unsigned int u_int32;
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned long u_long;

#define buffer_size 2048
#define AND_LOGIC (0xff)

/*
#define IPPROTO_IP 0   // dummy for IP
#define IPPROTO_ICMP 1 // control message protocol
#define IPPROTO_IGMP 2 // internet group management protocol
#define IPPROTO_GGP 3 // gateway^2 (deprecated)
#define IPPROTO_TCP 6 // tcp
#define IPPROTO_PUP 12 // pup
#define IPPROTO_UDP 17 // user datagram protocol
#define IPPROTO_IDP 22 // xns idp
#define IPPROTO_ND 77 // UNOFFICIAL net disk proto
#define IPPROTO_RAW 255 // raw IP packet
#define IPPROTO_MAX 256
*/

typedef struct mac_frm_header {
  u_char dest_addr[6];
  u_char src_addr[6];
  // u_char type[2];
  u_short type;
} __attribute__((packed)) MAC_FRM_HDR; //__attribute__((packed))取消编译器自动优化对齐结构体，也是为了保证属性长度和帧中相应区域的长度相同。

typedef struct arp_header {
  u_short arp_hdr; // hardware address
  u_short arp_pro; // protocol address
  u_char arp_hln; // length of hardware address
  u_char arp_pln; // length of protocol address
  u_short arp_opt; // ARP/RARP operation

  u_char arp_sha[6]; // sender hardware address
  u_long arp_spa; // sender protocol address
  u_char arp_tha[6]; // target ..
  u_long arp_tpa; // target ..
} __attribute__((packed)) ARP_HDR;

typedef struct ip_address {
    u_char byte1;
    u_char byte2;
    u_char byte3;
    u_char byte4;
} ip_addr;
typedef struct ip_header {
    u_char ip_len_ver;

    u_char ip_tos;
    u_short ip_total_len; // length
    u_short ip_id; // id
    u_short ip_flags; // 分片使用
    u_char ip_ttl; // 存活时间
    u_char ip_protocol;
    u_short ip_chksum;
    ip_addr ip_src;
    ip_addr ip_dest;
} __attribute__((packed)) IP_HDR;

typedef struct udp_header {
  u_short src_port; // 16bit
  u_short dest_port; // 16bit
  u_short pack_size; // 16bit
  u_short udp_chksum; // 16bit
} __attribute__((packed)) UDP_HDR;

typedef struct tcp_header {
  u_short src_port; // 16bit
  u_short dest_port; // 16bit
  u_int32 seq_num; // 32bit
  u_int32 ack_num; // 32bit
  u_short tcp_length_flag; // 4bit tcp length, 6bit xxxxxx, 6bit flag
  u_short window_size; // 16bit
  u_short tcp_chksum; // 16bit
  u_short tcp_pointer; // 16bit
} __attribute__((packed)) TCP_HDR;

typedef struct tcp_options {
  u_char kind;
  u_char length;
  u_char context[32];
} __attribute__((packed)) TCP_OPT;

int get_ifindex(int socket_src, char* interface) {
  struct ifreq ifr;
  memset(&ifr, 0, sizeof(ifr));
  strcpy(ifr.ifr_name, interface);
  if ((ioctl(socket_src, SIOCGIFINDEX, &ifr))) {
    printf("ioctl error\n");
    return -1;
  }
  return ifr.ifr_ifindex;
}
int main(int argc, char * argv[]) {
  int socket_src;
  char buffer[buffer_size] = {0};
  int n_rd;


  char* temp_src;
  char* temp_dest;

  if ((socket_src = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_IP))) < 0) {
    fprintf(stderr, "failed to create socket, try 'sudo'\n");
    exit(0);
  }

  struct sockaddr_ll sll;
  sll.sll_family = PF_PACKET;
  sll.sll_ifindex = get_ifindex(socket_src, "wlp4s0");
  printf("sll_ifindex = %d\n", sll.sll_ifindex);
  sll.sll_protocol = htons(ETH_P_IP);
  if((bind(socket_src, (struct sockaddr *)&sll, sizeof(sll))) < 0) {
    printf("Bind error!\n");
    exit(0);
  }

  for (int i = 0; ; ++i) {
    printf("%i ...\n", i);
    printf("====================================================\n");
    memset(buffer, 0x0, sizeof(buffer));
    n_rd = recvfrom(socket_src, buffer, buffer_size, 0, NULL, NULL);
    if (n_rd < 42) {
      perror("error: recvfrom()\n");
      printf("error code %d\n", errno);
      close(socket_src);
      exit(0);
    }
    printf("package length %d\n", n_rd);


    // work
    MAC_FRM_HDR* mac_header; // ethernet frame header
    mac_header = (MAC_FRM_HDR*)buffer;

    temp_src= mac_header->src_addr;
    temp_dest = mac_header->dest_addr;
    printf("MAC: %.2x:%.2x:%.2x:%.2x:%.2x:%.2x ---> %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n",
      temp_src[0] & AND_LOGIC,
      temp_src[1] & AND_LOGIC,
      temp_src[2] & AND_LOGIC,
      temp_src[3] & AND_LOGIC,
      temp_src[4] & AND_LOGIC,
      temp_src[5] & AND_LOGIC,

      temp_dest[0] & AND_LOGIC,
      temp_dest[1] & AND_LOGIC,
      temp_dest[2] & AND_LOGIC,
      temp_dest[3] & AND_LOGIC,
      temp_dest[4] & AND_LOGIC,
      temp_dest[5] & AND_LOGIC
    );

    // printf("ethernet header type: %2x\n", mac_header->type);

    // if (mac_header->type[0] == 0x08 && mac_header->type[1] == 0x00) { // ip
      IP_HDR* ip_header; // ip header
      ip_header = (struct IP_HDR*)&buffer[14];
      printf("src-ip: %d.%d.%d.%d\n",
        ip_header->ip_src.byte1, ip_header->ip_src.byte2,
        ip_header->ip_src.byte3, ip_header->ip_src.byte4);
      printf("dest-ip: %d.%d.%d.%d\n",
        ip_header->ip_dest.byte1, ip_header->ip_dest.byte2,
        ip_header->ip_dest.byte3, ip_header->ip_dest.byte4);


      /*
      temp_src = (char*)&ip_header->ip_src;
      temp_dest = (char*)&ip_header->ip_dest;
      printf("IP: %d.%d.%d.%d ---> %d.%d.%d.%d\n",
        temp_src[0] & AND_LOGIC,
        temp_src[1] & AND_LOGIC,
        temp_src[2] & AND_LOGIC,
        temp_src[3] & AND_LOGIC,

        temp_dest[0] & AND_LOGIC,
        temp_dest[1] & AND_LOGIC,
        temp_dest[2] & AND_LOGIC,
        temp_dest[3] & AND_LOGIC
    );
    */

      TCP_HDR* tcp_header;
      TCP_OPT* tcp_options;
      UDP_HDR* udp_header;
      udp_header = (UDP_HDR*)buffer + sizeof(MAC_FRM_HDR) + sizeof(IP_HDR);
      tcp_header = (TCP_HDR*)buffer + sizeof(MAC_FRM_HDR) + sizeof(IP_HDR) + sizeof(UDP_HDR);

      printf("Protocol code is %d\n", ip_header->ip_protocol);
      switch ((int)ip_header->ip_protocol) {
        case IPPROTO_ICMP: printf("ICMP\n"); break;
        case IPPROTO_IGMP: printf("IGMP\n"); break;
        case IPPROTO_IPIP: printf("IPIP\n"); break;
        case IPPROTO_TCP:
        case IPPROTO_UDP:
          printf("Protocol: %s ", ip_header->ip_protocol == IPPROTO_TCP ? "TCP" : "UDP");
          printf("Source port: %u, Destination port: %u\n", udp_header->src_port, udp_header->dest_port);
          break;
        case IPPROTO_RAW: printf("RAW\n"); break;
        default: printf("something wrong!!!\n");
      }
    // }


    printf("====================================================\n");
    printf("\n");
  }
  close(socket_src);
  return 0;
}
