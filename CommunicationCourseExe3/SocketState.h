#pragma once
#pragma comment(lib, "Ws2_32.lib")
#include <winsock2.h>
#include "http.h"

struct SocketState
{
	SOCKET id;			// Socket handle
	int	recv;			// Receiving?
	int	send;			// Sending?
	HttpRequest req1;
	HttpRequest req2;
};