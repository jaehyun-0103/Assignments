#define _CRT_SECURE_NO_WARNINGS
#define WIN32
#pragma comment(lib, "wpcap.lib")
#pragma comment(lib, "ws2_32.lib")

// FTP 貲滄橫 囀萄 薑曖
#define FTP_CMD_PORT 0x01
#define FTP_CMD_PASV 0x02
#define FTP_CMD_RETR 0x03
#define FTP_CMD_STOR 0x04

#include <stdio.h>
#include <pcap\pcap.h>
#include <pcap.h>
#include <string.h>
#include <WinSock2.h>
#include <stdint.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

typedef struct Ethernet_Header {
	u_char des[6];
	u_char src[6];
	short int ptype;
}Ethernet_Header;

typedef struct ipaddress {
	u_char ip1;
	u_char ip2;
	u_char ip3;
	u_char ip4;
}ip;

typedef struct IPHeader {
	u_char HeaderLength : 4;
	u_char Version : 4;
	u_char TypeOfService;
	u_short TotalLength;
	u_short ID;
	u_short FlagOffset;

	u_char TimeToLive;
	u_char Protocol;
	u_short checksum;
	ip SenderAddress;
	ip DestinationAddress;
	u_int Option_Padding;

	unsigned short source_port;
	unsigned short dest_port;
}IPHeader;

typedef struct TCPHeader {
	unsigned short source_port;
	unsigned short dest_port;
	unsigned int sequence;
	unsigned int acknowledge;
	unsigned char ns : 1;
	unsigned char reserved_part1 : 3;
	unsigned char data_offset : 4;
	unsigned char cwr : 1;   // ECN 擬港 Ы楚斜
	unsigned char ece : 1;   // ECN 縑囀 Ы楚斜
	unsigned char urg : 1;
	unsigned char ack : 1;
	unsigned char psh : 1;
	unsigned char rst : 1;
	unsigned char syn : 1;
	unsigned char fin : 1;
	unsigned short window;
	unsigned short tcp_checksum;
	unsigned short urgent_pointer;
}TCPHeader;

typedef struct udp_hdr {
	unsigned short source_port;
	unsigned short dest_port;
	unsigned short udp_length;
	unsigned short udp_checksum;
} UDP_HDR;

typedef struct CheckSummer {
	u_short part1;
	u_short part2;
	u_short part3;
	u_short part4;
	u_short part5;
	u_short checksum;
	u_short part6;
	u_short part7;
	u_short part8;
	u_short part9;
}CheckSummer;

typedef struct DNS {
	u_short identifier_dns;
	u_short flag_dns;
	u_short question_dns;
	u_short answer_dns;
	u_short authority;
	u_short additional;
	u_char domain_name_dns[60];
}domain;

typedef struct DHCP {
	unsigned char op;             // 螃ぷ溯檜暮 囀萄(詭衛雖 籀葬 寞衝)
	unsigned char htype;          // ж萄錚橫 顫殮
	unsigned char hlen;           // ж萄錚橫 輿模 望檜
	unsigned char hops;           // Hops
	unsigned int transactionId;   // お楠燮暮 ID
	unsigned short elapsed;       // DHCP ④渦 頂曖 衛除 薑爾
	unsigned short flags;         // DHCP ④渦 頂曖 睡た Щ煎撮蝶 Ы楚斜
	unsigned char messageType;    // DHCP 詭衛雖 顫殮擊 釭顫頂朝 高
} DHCP;

typedef struct {
	uint8_t op_code;   // FTP 貲滄橫 囀萄
	char data[256];    // FTP 貲滄橫 等檜攪
} FTPCommand;

// pcap_loop 褒ч л熱
void run_pcap_loop(pcap_t* pickedDev, void (*handler)());

// FTP ぬ韃擊 籀葬ж朝 л熱
void packet_handler_ftp(u_char* param, const struct pcap_pkthdr* h, const u_char* data);

// FTP 貲滄橫蒂 碟戮ж朝 л熱
FTPCommand analyze_ftp_command(const char* payload);

// FTP 等檜攪蒂 轎溘ж朝 л熱
void print_ftp_data(FTPCommand cmd, const char* payload, int size);

// HTTP ぬ韃擊 籀葬ж朝 л熱
void packet_handler_http(u_char* param, const struct pcap_pkthdr* h, const u_char* data);

// HTTP 蹂羶 ぬ韃, 擬港 ぬ韃 в攪葭
boolean is_http_packet(uint8_t* data);

// DNS ぬ韃擊 籀葬ж朝 л熱
void packet_handler_dns(u_char* param, const struct pcap_pkthdr* h, const u_char* data);

// DHCP ぬ韃擊 籀葬ж朝 л熱
void packet_handler_dhcp(u_char* param, const struct pcap_pkthdr* h, const u_char* data);

// Щ煎饜屬 薑爾蒂 轎溘ж朝 л熱
void print_protocol(IPHeader* IH, CheckSummer* CS);

// ぬ韃曖 16霞熱 等檜攪蒂 轎溘ж朝 л熱
void print_packet_hex_data(u_char* data, int Size);

void main() {
	pcap_if_t* allDevice;
	pcap_if_t* device;
	char errorMSG[256];
	char counter = 0;
	pcap_t* pickedDev;

	if ((pcap_findalldevs(&allDevice, errorMSG)) == -1)
		printf("濰纂 匐儀 螃盟");

	int count = 0;

	// 餌辨 陛棟и 啻お錶觼 濰纂 跡煙 轎溘
	for (device = allDevice; device != NULL; device = device->next) {
		printf("旨  %d 廓 啻お錶觼 蘋萄 收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n", count);
		printf("早 橫湘攪 薑爾 : %s 早\n", device->name);
		printf("早 橫湘攪 撲貲 : %s \n", device->description);
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
		count = count + 1;
	}

	printf("ぬ韃擊 熱餵й 啻お錶觼 蘋萄 摹鷗 >> ");
	device = allDevice;

	int choice;
	scanf_s("%d", &choice);

	for (count = 0; count < choice; count++) {
		device = device->next;
	}

	pickedDev = pcap_open_live(device->name, 65536, 0, 1000, errorMSG);
	pcap_freealldevs(allDevice);

	while (1) {
		int protocol = 0;
		printf("\n碟戮擊 錳ж朝 Щ煎饜屬擊 堅腦衛螃.\n");
		printf("1. FTP(TCP)\n2. HTTP(TCP)\n3. DNS(UDP)\n4. DHCP(UDP)\n5. 謙猿\n");
		printf(" >> ");
		scanf_s("%d", &protocol);

		if (protocol == 5) {
			printf("\nЩ煎斜極擊 謙猿м棲棻.\n");
			break;
		}

		printf("\nぬ韃 碟戮 醞 誇蹺堅 談戲賊 'p', 釭陛堅 談戲賊 'q'蒂 援腦衛螃.\n\n");

		Sleep(3000);

		switch (protocol) {
		case 1:
			run_pcap_loop(pickedDev, packet_handler_ftp);
			break;
		case 2:
			run_pcap_loop(pickedDev, packet_handler_http);
			break;
		case 3:
			run_pcap_loop(pickedDev, packet_handler_dns);
			break;
		case 4:
			run_pcap_loop(pickedDev, packet_handler_dhcp);
			break;
		default:
			printf("澀跤 援腦樟蝗棲棻. 棻衛 殮溘п輿撮蹂.\n");
			break;
		}
	}
}

void run_pcap_loop(pcap_t* pickedDev, void (*handler)()) {
	while (1) {
		if (_kbhit()) {
			char ch = _getch();
			if (ch == 'q' || ch == 'Q') {
				break;
			}
			else if (ch == 'p' || ch == 'P') {
				printf("橾衛薑雖(嬴鼠酈 殮溘衛 棻衛 碟戮 霞ч)\n");
				_getch();
				printf("棻衛 褒ч\n");
			}
		}
		pcap_loop(pickedDev, 1, handler, NULL);
	}
}

void packet_handler_ftp(u_char* param, const struct pcap_pkthdr* h, const u_char* data) {
	(VOID)(param);

	Ethernet_Header* EH = (Ethernet_Header*)data;
	IPHeader* IH = (struct IPHeader*)(data + 14);
	TCPHeader* TCP = (TCPHeader*)(data + 14 + (IH->HeaderLength) * 4);

	// TCP んお陛 21(FTP)檣 唳辦縑虜 籀葬
	if (ntohs(TCP->source_port) == 21 || ntohs(TCP->dest_port) == 21) {
		FTPCommand cmd = analyze_ftp_command((char*)(data + 14 + (IH->HeaderLength) * 4));

		print_protocol(IH, (CheckSummer*)(data + 14));

		printf("早\t\t*[ TCP ④渦 ]*\t\t\n");
		printf("早\tSCR PORT : %d\n", ntohs(TCP->source_port));
		printf("早\tDEST PORT : %d\n", ntohs(TCP->dest_port));
		printf("早\tSeg : %u\n", ntohl(TCP->sequence));
		printf("早\tAck : %u\n", ntohl(TCP->acknowledge));
		printf("早\tWindow size : %u\n", ntohl(TCP->window));
		printf("早\tChecksum : 0x%04X\n", ntohs(TCP->tcp_checksum)); // 羹觼撰
		printf("早\n");

		if (TCP->syn) {
			printf("早\tTCP 翱唸 撲薑 (SYN)\n");
		}
		else if (TCP->fin) {
			printf("早\tTCP 翱唸 п薯 (FIN)\n");
		}
		else if (TCP->psh) {
			printf("早\tTCP 等檜攪 瞪歎\n");
		}

		printf("早  ---------------flag---------------\n");
		printf("早\turg : %u\n", TCP->urg);
		printf("早\tack : %u\n", TCP->ack);
		printf("早\tpsh : %u\n", TCP->psh);
		printf("早\trst : %u\n", TCP->rst);
		printf("早\tsyn : %u\n", TCP->syn);
		printf("早\tfin : %u\n", TCP->fin);
		printf("早\n");
		printf("早\n");
		char* end_of_headers = strstr((char*)data + 14 + (IH->HeaderLength) * 4, "\r\n\r\n");
		u_char* packet_ = data + 34 + (IH->HeaderLength) * 4;
		printf("早  --------------FTP DATA-------------\n");
		print_ftp_data(cmd, (const char*)packet_, h->len - 34 - (IH->HeaderLength) * 4);
		printf("早\n");
		printf("早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收\n\n");
	}
}

FTPCommand analyze_ftp_command(const char* payload) {
	FTPCommand cmd;

	// FTP 貲滄橫 囀萄 蹺轎
	cmd.op_code = payload[0];

	// FTP 貲滄橫 等檜攪 蹺轎
	strncpy(cmd.data, payload + 2, sizeof(cmd.data) - 1);
	cmd.data[sizeof(cmd.data) - 1] = '\0';  // Null 謙猿

	return cmd;
}

void print_ftp_data(FTPCommand cmd, const char* payload, int size)
{
	printf("早\t貲滄橫 囀萄: 0x%02x\n", cmd.op_code);
	printf("早\t等檜攪 觼晦: %d bytes\n", size);
	printf("早\t等檜攪 頂辨:\n");
	printf("早\t");
	for (int i = 0; i < size; i++) {
		printf("%c", payload[i]);
	}
	printf("\n");
}

void packet_handler_http(u_char* param, const struct pcap_pkthdr* h, const u_char* data) {
	(VOID)(param);
	(VOID)(data);

	Ethernet_Header* EH = (Ethernet_Header*)data;
	IPHeader* IH = (struct IPHeader*)(data + 14);
	CheckSummer* CS = (struct CheckSummer*)(data + 14);
	TCPHeader* TCP = (TCPHeader*)(data + 14 + (IH->HeaderLength) * 4);

	// UDP んお陛 80檜賊憮 Щ煎饜屬檜 TCP檣 唳辦縑虜 籀葬
	if ((ntohs(TCP->source_port) == 80 || ntohs(TCP->dest_port) == 80) && IH->Protocol == IPPROTO_TCP) {

		// 34 == 檜渦喘 ④渦 觼晦(14) + TCP ④渦 觼晦(20)
		// IH->HeaderLength == IP ④萄曖 望檜(32bit 欽嬪) / IH->HeaderLength*4 == IP ④萄曖 望檜(byte 欽嬪)
		// 唸煩 : 34 + (IH->HeaderLength) * 4朝 ん檣攪蒂 檜渦喘婁 IP ④渦蒂 勒傘嗨堅 ぬ韃曖 む檜煎萄 等檜攪 衛濛 睡碟擊 陛葬酈紫煙 撲薑
		// HTTP ぬ韃
		uint8_t* packet = data + 34 + (IH->HeaderLength) * 4;
		if (is_http_packet(packet)) {
			print_protocol(IH, CS);

			printf("早  --------------------------------------------------------------------------  \n");
			printf("早\t\t*[ TCP ④渦 ]*\t\t\n");
			printf("早\tSCR PORT : %d\n", ntohs(TCP->source_port));
			printf("早\tDEST PORT : %d\n", ntohs(TCP->dest_port));
			printf("早\tSeg : %u\n", ntohl(TCP->sequence));
			printf("早\tAck : %u\n", ntohl(TCP->acknowledge));
			printf("早\tWindow size : %u\n", ntohl(TCP->window));
			printf("早\tChecksum : 0x%04X\n", ntohs(TCP->tcp_checksum)); // 羹觼撰
			printf("早\n");
			printf("早  ---------------flag---------------\n");
			printf("早\turg : %u\n", TCP->urg);
			printf("早\tack : %u\n", TCP->ack);
			printf("早\tpsh : %u\n", TCP->psh);
			printf("早\trst : %u\n", TCP->rst);
			printf("早\tsyn : %u\n", TCP->syn);
			printf("早\tfin : %u\n", TCP->fin);
			printf("早\n");
			printf("早  --------------------------------------------------------------------------  \n");
			printf("早\t\t*[ Application ④渦 ]*\t\t\n");
			char* end_of_headers = strstr((char*)packet, "\r\n\r\n");
			if (end_of_headers != NULL) {
				// '\r\n\r\n'檜 嫦唯脹 唳辦, п渡 嬪纂梱雖虜 轎溘
				int header_length = end_of_headers - (char*)packet;
				char* headers = (char*)malloc(header_length + 1); // 寡翮曖 觼晦蒂 滲熱煎 萃 熱 橈晦 陽僥縑 翕瞳 詭賅葬 й渡
				headers[header_length + 1];
				memcpy(headers, packet, header_length);
				headers[header_length] = '\0'; // 僥濠翮 部縑 null 僥濠 蹺陛

				const char* token;
				token = strtok(headers, "\r\n");
				if (token != NULL) {
					printf("早\t%s\n", token);
				}

				// 釭該雖 ④渦 轎溘
				while ((token = strtok(NULL, "\r\n")) != NULL) {
					printf("早\t%s\n", token);
				}
				//printf("%s", headers);
				free(headers); // 翕瞳戲煎 й渡и 詭賅葬 п薯
			}
			else {
				// '\r\n\r\n'檜 嫦唯腎雖 彊擎 唳辦, 瞪羹 ぬ韃 轎溘
				printf("早\t%s", packet);
			}
			printf("早\n");
			printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收\n\n");
		}
	}
}

boolean is_http_packet(uint8_t* data) {
	if (strncmp(data, "HTTP", 4) == 0)
		return 1;

	char* http_methods[] = { "GET", "POST", "PUT", "DELETE", NULL };
	for (int i = 0; http_methods[i] != NULL; i++) {
		if (strncmp(data, http_methods[i], strlen(http_methods[i])) == 0)
			return 1;
	}
	return 0;
}

void packet_handler_dns(u_char* param, const struct pcap_pkthdr* h, const u_char* data) {
	(VOID)(param);
	(VOID)(data);

	Ethernet_Header* EH = (Ethernet_Header*)data;

	IPHeader* IH = (struct IPHeader*)(data + 14);
	CheckSummer* CS = (struct CheckSummer*)(data + 14);
	UDP_HDR* UDP = (struct UDP_HDR*)(data + 34);
	domain* dns = (struct DNS*)(data + 42);

	// UDP んお陛 53檜賊憮 Щ煎饜屬檜 UDP檣 唳辦縑虜 籀葬
	if ((ntohs(UDP->source_port) == 53 || ntohs(UDP->dest_port) == 53) && IH->Protocol == IPPROTO_UDP) {
		print_protocol(IH, CS);

		printf("早  --------------------------------------------------------------------------  \n");
		printf("早\t\t*[ UDP ④渦 ]*\t\t\n");
		printf("早\tSrc Port : %d\n", ntohs(UDP->source_port)); // 轎嫦雖 んお
		printf("早\tDest Port : %d\n", ntohs(UDP->dest_port)); // 跡瞳雖 んお
		printf("早\tLength : %d\n", ntohs(UDP->udp_length)); // 望檜
		printf("早\tChecksum : 0x%04X\n", ntohs(UDP->udp_checksum)); // 羹觼撰
		printf("早\n");

		printf("早  --------------------------------------------------------------------------  \n");
		printf("早\t\t*[ Application ④渦 ]*\t\t\n");
		printf("早\tIdentifier : 0x%04X\n", ntohs(dns->identifier_dns)); // 衝滌濠
		printf("早\tFlag : 0x%04X\n", ntohs(dns->flag_dns)); // Ы楚斜
		printf("早\tQuestion : %d\n", ntohs(dns->question_dns)); // 韓曖
		printf("早\tAnswer : %d\n", ntohs(dns->answer_dns)); // 擬港
		printf("早\tDomain Name : "); // 紫詭檣 檜葷
		for (int i = 0; i < 60; i++) {
			if (dns->domain_name_dns[i] > 40)
				printf("%c", dns->domain_name_dns[i]);
			else if (dns->domain_name_dns[i] == 0x00)
				break;
			else if (dns->domain_name_dns[i - 1] > 60)
				printf(".");
			
		}
		printf("\n");
		printf("早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收\n\n");
	}
}

void packet_handler_dhcp(u_char* param, const struct pcap_pkthdr* h, const u_char* data) {
	(VOID)(param);
	(VOID)(data);

	Ethernet_Header* EH = (Ethernet_Header*)data;

	IPHeader* IH = (struct IPHeader*)(data + 14);
	CheckSummer* CS = (struct CheckSummer*)(data + 14);
	UDP_HDR* UDP = (struct UDP_HDR*)(data + 34);
	DHCP* dhcp = (struct DHCP*)(data + 42);


	const char* dhcpMessageType = "";
	switch (data[284]) {
	case 1:
		dhcpMessageType = "DHCP Discover";
		break;
	case 2:
		dhcpMessageType = "DHCP Offer";
		break;
	case 3:
		dhcpMessageType = "DHCP Request";
		break;
	case 4:
		dhcpMessageType = "DHCP Decline";
		break;
	case 5:
		dhcpMessageType = "DHCP Acknowledge";
		break;
	case 6:
		dhcpMessageType = "DHCP Negative Acknowledge";
		break;
	case 7:
		dhcpMessageType = "DHCP Release";
		break;
	case 8:
		dhcpMessageType = "DHCP Inform";
		break;
	default:
		dhcpMessageType = "Unknown DHCP Message Type";
		break;
	}

	// UDP んお陛 67檜賊憮 Щ煎饜屬檜 DHCP檣 唳辦縑虜 籀葬
	if ((ntohs(UDP->source_port) == 67 || ntohs(UDP->dest_port) == 67) && IH->Protocol == IPPROTO_UDP) {
		print_protocol(IH, CS);

		printf("早  --------------------------------------------------------------------------  \n");
		printf("早\t\t*[ UDP ④渦 ]*\t\t\n");
		printf("早\tSrc Port : %d\n", ntohs(UDP->source_port)); // 轎嫦雖 んお
		printf("早\tDest Port : %d\n", ntohs(UDP->dest_port)); // 跡瞳雖 んお
		printf("早\tLength : %d\n", ntohs(UDP->udp_length)); // 望檜
		printf("早\tChecksum : 0x%04X\n", ntohs(UDP->udp_checksum)); // 羹觼撰
		printf("早\n");

		printf("早  --------------------------------------------------------------------------  \n");
		printf("早\t\t*[ Application ④渦 ]*\t\t\n");
		printf("早\tMessage Type: %s\n", dhcpMessageType); // DHCP 詭衛雖 顫殮
		printf("早\tOperation Code (op): %d\n", dhcp->op);
		printf("早\tHardware Type (htype): 0x%02X\n", dhcp->htype);
		printf("早\tHardware Address Length: %d\n", dhcp->hlen);
		printf("早\tHops: %d\n", dhcp->hops); // Hops
		printf("早\tTransaction ID: 0x%08x\n", ntohl(dhcp->transactionId)); // お楠燮暮 ID
		printf("早\tElapsed: %d\n", ntohs(dhcp->elapsed)); // DHCP ④渦 頂曖 衛除 薑爾
		printf("早\tFlags: 0x%04X\n", ntohs(dhcp->flags)); // 睡た Щ煎撮蝶 Ы楚斜
		printf("早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收\n\n");
	}
}

void print_protocol(IPHeader* IH, CheckSummer* CS) {
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收\n");
	printf("早\t\t*[ IP ④渦 ]*\n");
	printf("早\tChecksum : 0x%04X\n", ntohs(CS->checksum)); // 羹觼撰
	printf("早\tTTL : %d\n", IH->TimeToLive); // TTL
	printf("早\tSrc IP Address : %d.%d.%d.%d\n", IH->SenderAddress.ip1, IH->SenderAddress.ip2, IH->SenderAddress.ip3, IH->SenderAddress.ip4); // 轎嫦雖 IP 輿模
	printf("早\tDest IP Address : %d.%d.%d.%d\n", IH->DestinationAddress.ip1, IH->DestinationAddress.ip2, IH->DestinationAddress.ip3, IH->DestinationAddress.ip4); // 跡瞳雖 IP 輿模
	printf("早\n");

	print_packet_hex_data((u_char*)IH, ntohs(IH->TotalLength));
}

void print_packet_hex_data(u_char* data, int Size) {
	unsigned char a, line[17], c;
	int j;

	printf("早  --------------------------------------------------------------------------  \n");
	printf("早\t\t*[ ぬ韃 頂辨 ]*\n");
	printf("早");
	for (int i = 0; i < Size; i++) {
		c = data[i];
		printf(" %.2x", (unsigned int)c);
		a = (c >= 32 && c <= 128) ? (unsigned char)c : '.';
		line[i % 16] = a;
		if ((i != 0 && (i + 1) % 16 == 0) || i == Size - 1) {
			line[i % 16 + 1] = '\0';
			printf("          ");
			for (j = strlen((const char*)line); j < 16; j++) {
				printf("   ");
			}
			printf("%s \n", line);
			printf("早");
		}

		if (i == Size - 1 && (i + 1) % 16 != 0) {
			for (j = 0; j < (16 - (i + 1) % 16) * 3; j++) {
				printf(" ");
			}
			printf(" ");
			for (j = 0; j <= i % 16; j++) {
				printf("   ");
			}
		}
	}
	printf("\n");
}