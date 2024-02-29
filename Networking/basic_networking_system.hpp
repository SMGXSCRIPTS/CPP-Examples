#ifndef __NETWORKING_SYSTEM_H
#define __NETWORKING_SYSTEM_H

#ifndef __CUSTOM_STDINT_H
#define __CUSTOM_STDINT_H

typedef signed char SINT8_T;
typedef unsigned char UINT8_T;
typedef short SINT16_T;
typedef unsigned short UINT16_T;
typedef int SINT32_T;
typedef unsigned int UINT32_T;
typedef long long int SINT64_T;
typedef unsigned long long int UINT64_T;

#endif // __CUSTOM_STDINT_H

#ifndef __SYS_SOCKET_H
#define __SYS_SOCKET_H

#define AF_INET 1
#define AF_INET6 2

#define SOCK_STREAM 1
#define SOCK_DGRAM 2

#define SO_REUSEADDR 1
#define SO_REUSEPORT 2

#ifndef __SOCKLEN_T
#define __SOCKLEN_T
typedef unsigned int NWK_SOCKLEN_T;
#endif // __SOCKLEN_T

int NWK_SOCKET(int N_DOMAIN,int N_TYPE,int N_PROTOCOL);
int NWK_BIND(int SOCKET_FD,const struct SOCKADDR *ADDR,NWK_SOCKLEN_T ADDRLEN);
int NWK_LISTEN(int SOCKET_FD,int BACKLOG);
int NWK_ACCEPT(int SOCKET_FD,struct SOCKADDR *ADDR,NWK_SOCKLEN_T *ADDRLEN);
int NWK_CONNECT(int SOCKET_FD,struct SOCKADDR *ADDR,NWK_SOCKLEN_T *ADDRLEN);
int NWK_SETSOCKOPT(int SOCKET_FD,int LEVEL,int OPTNAME,const void *OPTVAL,NWK_SOCKLEN_T OPTLEN);

UINT16_T htons(UINT16_T HOST_SHORT)
{
    union {
        UINT16_T VALUE;
        UINT8_T BYTES[2];
    } TEST = {0x0102};
    if (TEST.BYTES[0] == 0x01 && TEST.BYTES[1] == 0x02)
    {
        return HOST_SHORT;
    }
    else
    {
        return ((HOST_SHORT & 0xFF00) >> 8) | ((HOST_SHORT & 0x00FF) << 8)
    }
}

#endif // __SYS_SOCKET_H

#ifndef __NETWORKING_INET_H
#define __NETWORKING_INET_H

typedef unsigned short IN_PORT_T;
typedef unsigned short SA_FAMILY_T;
typedef unsigned long SIZE_T;
typedef long SSIZE_T;

struct IN4_ADDR
{
    UINT32_T S4_ADDR;
};

struct IN6_ADDR
{
    UINT8_T S6_ADDR[16];
};

struct SOCKADDR_IN4
{
    UINT8_T SIN4_LEN;
    SA_FAMILY_T SIN4_FAMILY;
    IN_PORT_T SIN4_PORT;
    struct IN4_ADDR SIN4_ADDR;
};

struct SOCKADDR_IN6
{
    UINT8_T SIN6_LEN;
    SA_FAMILY_T SIN6_FAMILY;
    IN_PORT_T SIN6_PORT;
    UINT32_T SIN6_FLOWINFO;
    struct IN6_ADDR SIN6_ADDR;
    UINT32_T SIN6_SCOPE_ID;
};

#endif // __NETWORKING_INET_H

#ifndef __CUSTOM_UNISTD_H
#define __CUSTOM_UNISTD_H

int N_CLOSE(int FILE_DESCRIPTOR);
SSIZE_T N_READ(int FILE_DESCRIPTOR,void *BUFFER,SIZE_T COUNTER);
SSIZE_T N_WRITE(int FILE_DESCRIPTOR,const void *BUFFER,SIZE_T COUNTER);

#endif // __CUSTOM_UNISTD_H
#endif // __NETWORKING_SYSTEM_H
