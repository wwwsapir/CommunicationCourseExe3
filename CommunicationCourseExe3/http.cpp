#include "http.h"
#include <iostream>
using namespace std;

int parseHttpRequest(char *msg, int len, HttpRequest *reqPtr)
{
	if (len == 0)
	{
		return INVALID_HTTP_MSG;
	}
	cout << "parseHttpRequest Not Implemented!";
	return INVALID_HTTP_MSG;
}

int httpResponseToString(HttpResponse response, char buffer[])
{
	cout << "httpResponseToString Not Implemented!";
	return 0;
}

HttpResponse handleGetRequest(HttpRequest req)
{
	cout << "handleGetRequest Not Implemented!";
	return HttpResponse();
}

HttpResponse handlePostRequest(HttpRequest req)
{
	cout << "handlePostRequest Not Implemented!";
	return HttpResponse();
}

HttpResponse handlePutRequest(HttpRequest req)
{
	cout << "handlePutRequest Not Implemented!";
	return HttpResponse();
}

HttpResponse handleTraceRequest(HttpRequest req)
{
	cout << "handleTraceRequest Not Implemented!";
	return HttpResponse();
}

HttpResponse handleOptionsRequest(HttpRequest req)
{
	cout << "handleOptionsRequest Not Implemented!";
	return HttpResponse();
}

HttpResponse handleHeadRequest(HttpRequest req)
{
	cout << "handleHeadRequest Not Implemented!";
	return HttpResponse();
}

HttpResponse handleDeleteRequest(HttpRequest req)
{
	cout << "handleDeleteRequest Not Implemented!";
	return HttpResponse();
}
