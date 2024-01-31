#define _CRT_SECURE_NO_WARNINGS
#define WIN32
#pragma comment(lib, "wpcap.lib")
#pragma comment(lib, "ws2_32.lib")

// FTP ��ɾ� �ڵ� ����
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
	unsigned char cwr : 1;   // ECN ���� �÷���
	unsigned char ece : 1;   // ECN ���� �÷���
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
	unsigned char op;             // ���۷��̼� �ڵ�(�޽��� ó�� ���)
	unsigned char htype;          // �ϵ���� Ÿ��
	unsigned char hlen;           // �ϵ���� �ּ� ����
	unsigned char hops;           // Hops
	unsigned int transactionId;   // Ʈ����� ID
	unsigned short elapsed;       // DHCP ��� ���� �ð� ����
	unsigned short flags;         // DHCP ��� ���� ���� ���μ��� �÷���
	unsigned char messageType;    // DHCP �޽��� Ÿ���� ��Ÿ���� ��
} DHCP;

typedef struct {
	uint8_t op_code;   // FTP ��ɾ� �ڵ�
	char data[256];    // FTP ��ɾ� ������
} FTPCommand;

// pcap_loop ���� �Լ�
void run_pcap_loop(pcap_t* pickedDev, void (*handler)());

// FTP ��Ŷ�� ó���ϴ� �Լ�
void packet_handler_ftp(u_char* param, const struct pcap_pkthdr* h, const u_char* data);

// FTP ��ɾ �м��ϴ� �Լ�
FTPCommand analyze_ftp_command(const char* payload);

// FTP �����͸� ����ϴ� �Լ�
void print_ftp_data(FTPCommand cmd, const char* payload, int size);

// HTTP ��Ŷ�� ó���ϴ� �Լ�
void packet_handler_http(u_char* param, const struct pcap_pkthdr* h, const u_char* data);

// HTTP ��û ��Ŷ, ���� ��Ŷ ���͸�
boolean is_http_packet(uint8_t* data);

// DNS ��Ŷ�� ó���ϴ� �Լ�
void packet_handler_dns(u_char* param, const struct pcap_pkthdr* h, const u_char* data);

// DHCP ��Ŷ�� ó���ϴ� �Լ�
void packet_handler_dhcp(u_char* param, const struct pcap_pkthdr* h, const u_char* data);

// �������� ������ ����ϴ� �Լ�
void print_protocol(IPHeader* IH, CheckSummer* CS);

// ��Ŷ�� 16���� �����͸� ����ϴ� �Լ�
void print_packet_hex_data(u_char* data, int Size);

void main() {
	pcap_if_t* allDevice;
	pcap_if_t* device;
	char errorMSG[256];
	char counter = 0;
	pcap_t* pickedDev;

	if ((pcap_findalldevs(&allDevice, errorMSG)) == -1)
		printf("��ġ �˻� ����");

	int count = 0;

	// ��� ������ ��Ʈ��ũ ��ġ ��� ���
	for (device = allDevice; device != NULL; device = device->next) {
		printf("��  %d �� ��Ʈ��ũ ī�� ��������������������������������������������������������������������������������������������\n", count);
		printf("�� ����� ���� : %s ��\n", device->name);
		printf("�� ����� ���� : %s \n", device->description);
		printf("����������������������������������������������������������������������������������������������������������������������������������������\n");
		count = count + 1;
	}

	printf("��Ŷ�� ������ ��Ʈ��ũ ī�� ���� >> ");
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
		printf("\n�м��� ���ϴ� ���������� ���ÿ�.\n");
		printf("1. FTP(TCP)\n2. HTTP(TCP)\n3. DNS(UDP)\n4. DHCP(UDP)\n5. ����\n");
		printf(" >> ");
		scanf_s("%d", &protocol);

		if (protocol == 5) {
			printf("\n���α׷��� �����մϴ�.\n");
			break;
		}

		printf("\n��Ŷ �м� �� ���߰� ������ 'p', ������ ������ 'q'�� �����ÿ�.\n\n");

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
			printf("�߸� �����̽��ϴ�. �ٽ� �Է����ּ���.\n");
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
				printf("�Ͻ�����(�ƹ�Ű �Է½� �ٽ� �м� ����)\n");
				_getch();
				printf("�ٽ� ����\n");
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

	// TCP ��Ʈ�� 21(FTP)�� ��쿡�� ó��
	if (ntohs(TCP->source_port) == 21 || ntohs(TCP->dest_port) == 21) {
		FTPCommand cmd = analyze_ftp_command((char*)(data + 14 + (IH->HeaderLength) * 4));

		print_protocol(IH, (CheckSummer*)(data + 14));

		printf("��\t\t*[ TCP ��� ]*\t\t\n");
		printf("��\tSCR PORT : %d\n", ntohs(TCP->source_port));
		printf("��\tDEST PORT : %d\n", ntohs(TCP->dest_port));
		printf("��\tSeg : %u\n", ntohl(TCP->sequence));
		printf("��\tAck : %u\n", ntohl(TCP->acknowledge));
		printf("��\tWindow size : %u\n", ntohl(TCP->window));
		printf("��\tChecksum : 0x%04X\n", ntohs(TCP->tcp_checksum)); // üũ��
		printf("��\n");

		if (TCP->syn) {
			printf("��\tTCP ���� ���� (SYN)\n");
		}
		else if (TCP->fin) {
			printf("��\tTCP ���� ���� (FIN)\n");
		}
		else if (TCP->psh) {
			printf("��\tTCP ������ ����\n");
		}

		printf("��  ---------------flag---------------\n");
		printf("��\turg : %u\n", TCP->urg);
		printf("��\tack : %u\n", TCP->ack);
		printf("��\tpsh : %u\n", TCP->psh);
		printf("��\trst : %u\n", TCP->rst);
		printf("��\tsyn : %u\n", TCP->syn);
		printf("��\tfin : %u\n", TCP->fin);
		printf("��\n");
		printf("��\n");
		char* end_of_headers = strstr((char*)data + 14 + (IH->HeaderLength) * 4, "\r\n\r\n");
		u_char* packet_ = data + 34 + (IH->HeaderLength) * 4;
		printf("��  --------------FTP DATA-------------\n");
		print_ftp_data(cmd, (const char*)packet_, h->len - 34 - (IH->HeaderLength) * 4);
		printf("��\n");
		printf("��\n");
		printf("��������������������������������������������������������������������������������������������������������������������������������������������������������\n\n");
	}
}

FTPCommand analyze_ftp_command(const char* payload) {
	FTPCommand cmd;

	// FTP ��ɾ� �ڵ� ����
	cmd.op_code = payload[0];

	// FTP ��ɾ� ������ ����
	strncpy(cmd.data, payload + 2, sizeof(cmd.data) - 1);
	cmd.data[sizeof(cmd.data) - 1] = '\0';  // Null ����

	return cmd;
}

void print_ftp_data(FTPCommand cmd, const char* payload, int size)
{
	printf("��\t��ɾ� �ڵ�: 0x%02x\n", cmd.op_code);
	printf("��\t������ ũ��: %d bytes\n", size);
	printf("��\t������ ����:\n");
	printf("��\t");
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

	// UDP ��Ʈ�� 80�̸鼭 ���������� TCP�� ��쿡�� ó��
	if ((ntohs(TCP->source_port) == 80 || ntohs(TCP->dest_port) == 80) && IH->Protocol == IPPROTO_TCP) {

		// 34 == �̴��� ��� ũ��(14) + TCP ��� ũ��(20)
		// IH->HeaderLength == IP ����� ����(32bit ����) / IH->HeaderLength*4 == IP ����� ����(byte ����)
		// ��� : 34 + (IH->HeaderLength) * 4�� �����͸� �̴��ݰ� IP ����� �ǳʶٰ� ��Ŷ�� ���̷ε� ������ ���� �κ��� ����Ű���� ����
		// HTTP ��Ŷ
		uint8_t* packet = data + 34 + (IH->HeaderLength) * 4;
		if (is_http_packet(packet)) {
			print_protocol(IH, CS);

			printf("��  --------------------------------------------------------------------------  \n");
			printf("��\t\t*[ TCP ��� ]*\t\t\n");
			printf("��\tSCR PORT : %d\n", ntohs(TCP->source_port));
			printf("��\tDEST PORT : %d\n", ntohs(TCP->dest_port));
			printf("��\tSeg : %u\n", ntohl(TCP->sequence));
			printf("��\tAck : %u\n", ntohl(TCP->acknowledge));
			printf("��\tWindow size : %u\n", ntohl(TCP->window));
			printf("��\tChecksum : 0x%04X\n", ntohs(TCP->tcp_checksum)); // üũ��
			printf("��\n");
			printf("��  ---------------flag---------------\n");
			printf("��\turg : %u\n", TCP->urg);
			printf("��\tack : %u\n", TCP->ack);
			printf("��\tpsh : %u\n", TCP->psh);
			printf("��\trst : %u\n", TCP->rst);
			printf("��\tsyn : %u\n", TCP->syn);
			printf("��\tfin : %u\n", TCP->fin);
			printf("��\n");
			printf("��  --------------------------------------------------------------------------  \n");
			printf("��\t\t*[ Application ��� ]*\t\t\n");
			char* end_of_headers = strstr((char*)packet, "\r\n\r\n");
			if (end_of_headers != NULL) {
				// '\r\n\r\n'�� �߰ߵ� ���, �ش� ��ġ������ ���
				int header_length = end_of_headers - (char*)packet;
				char* headers = (char*)malloc(header_length + 1); // �迭�� ũ�⸦ ������ �� �� ���� ������ ���� �޸� �Ҵ�
				headers[header_length + 1];
				memcpy(headers, packet, header_length);
				headers[header_length] = '\0'; // ���ڿ� ���� null ���� �߰�

				const char* token;
				token = strtok(headers, "\r\n");
				if (token != NULL) {
					printf("��\t%s\n", token);
				}

				// ������ ��� ���
				while ((token = strtok(NULL, "\r\n")) != NULL) {
					printf("��\t%s\n", token);
				}
				//printf("%s", headers);
				free(headers); // �������� �Ҵ��� �޸� ����
			}
			else {
				// '\r\n\r\n'�� �߰ߵ��� ���� ���, ��ü ��Ŷ ���
				printf("��\t%s", packet);
			}
			printf("��\n");
			printf("��������������������������������������������������������������������������������������������������������������������������������������������������������\n\n");
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

	// UDP ��Ʈ�� 53�̸鼭 ���������� UDP�� ��쿡�� ó��
	if ((ntohs(UDP->source_port) == 53 || ntohs(UDP->dest_port) == 53) && IH->Protocol == IPPROTO_UDP) {
		print_protocol(IH, CS);

		printf("��  --------------------------------------------------------------------------  \n");
		printf("��\t\t*[ UDP ��� ]*\t\t\n");
		printf("��\tSrc Port : %d\n", ntohs(UDP->source_port)); // ����� ��Ʈ
		printf("��\tDest Port : %d\n", ntohs(UDP->dest_port)); // ������ ��Ʈ
		printf("��\tLength : %d\n", ntohs(UDP->udp_length)); // ����
		printf("��\tChecksum : 0x%04X\n", ntohs(UDP->udp_checksum)); // üũ��
		printf("��\n");

		printf("��  --------------------------------------------------------------------------  \n");
		printf("��\t\t*[ Application ��� ]*\t\t\n");
		printf("��\tIdentifier : 0x%04X\n", ntohs(dns->identifier_dns)); // �ĺ���
		printf("��\tFlag : 0x%04X\n", ntohs(dns->flag_dns)); // �÷���
		printf("��\tQuestion : %d\n", ntohs(dns->question_dns)); // ����
		printf("��\tAnswer : %d\n", ntohs(dns->answer_dns)); // ����
		printf("��\tDomain Name : "); // ������ �̸�
		for (int i = 0; i < 60; i++) {
			if (dns->domain_name_dns[i] > 40)
				printf("%c", dns->domain_name_dns[i]);
			else if (dns->domain_name_dns[i] == 0x00)
				break;
			else if (dns->domain_name_dns[i - 1] > 60)
				printf(".");
			
		}
		printf("\n");
		printf("��\n");
		printf("��������������������������������������������������������������������������������������������������������������������������������������������������������\n\n");
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

	// UDP ��Ʈ�� 67�̸鼭 ���������� DHCP�� ��쿡�� ó��
	if ((ntohs(UDP->source_port) == 67 || ntohs(UDP->dest_port) == 67) && IH->Protocol == IPPROTO_UDP) {
		print_protocol(IH, CS);

		printf("��  --------------------------------------------------------------------------  \n");
		printf("��\t\t*[ UDP ��� ]*\t\t\n");
		printf("��\tSrc Port : %d\n", ntohs(UDP->source_port)); // ����� ��Ʈ
		printf("��\tDest Port : %d\n", ntohs(UDP->dest_port)); // ������ ��Ʈ
		printf("��\tLength : %d\n", ntohs(UDP->udp_length)); // ����
		printf("��\tChecksum : 0x%04X\n", ntohs(UDP->udp_checksum)); // üũ��
		printf("��\n");

		printf("��  --------------------------------------------------------------------------  \n");
		printf("��\t\t*[ Application ��� ]*\t\t\n");
		printf("��\tMessage Type: %s\n", dhcpMessageType); // DHCP �޽��� Ÿ��
		printf("��\tOperation Code (op): %d\n", dhcp->op);
		printf("��\tHardware Type (htype): 0x%02X\n", dhcp->htype);
		printf("��\tHardware Address Length: %d\n", dhcp->hlen);
		printf("��\tHops: %d\n", dhcp->hops); // Hops
		printf("��\tTransaction ID: 0x%08x\n", ntohl(dhcp->transactionId)); // Ʈ����� ID
		printf("��\tElapsed: %d\n", ntohs(dhcp->elapsed)); // DHCP ��� ���� �ð� ����
		printf("��\tFlags: 0x%04X\n", ntohs(dhcp->flags)); // ���� ���μ��� �÷���
		printf("��\n");
		printf("��������������������������������������������������������������������������������������������������������������������������������������������������������\n\n");
	}
}

void print_protocol(IPHeader* IH, CheckSummer* CS) {
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��\t\t*[ IP ��� ]*\n");
	printf("��\tChecksum : 0x%04X\n", ntohs(CS->checksum)); // üũ��
	printf("��\tTTL : %d\n", IH->TimeToLive); // TTL
	printf("��\tSrc IP Address : %d.%d.%d.%d\n", IH->SenderAddress.ip1, IH->SenderAddress.ip2, IH->SenderAddress.ip3, IH->SenderAddress.ip4); // ����� IP �ּ�
	printf("��\tDest IP Address : %d.%d.%d.%d\n", IH->DestinationAddress.ip1, IH->DestinationAddress.ip2, IH->DestinationAddress.ip3, IH->DestinationAddress.ip4); // ������ IP �ּ�
	printf("��\n");

	print_packet_hex_data((u_char*)IH, ntohs(IH->TotalLength));
}

void print_packet_hex_data(u_char* data, int Size) {
	unsigned char a, line[17], c;
	int j;

	printf("��  --------------------------------------------------------------------------  \n");
	printf("��\t\t*[ ��Ŷ ���� ]*\n");
	printf("��");
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
			printf("��");
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