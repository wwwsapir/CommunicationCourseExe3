#define INVALID_HTTP_MSG -1
#define VALID_HTTP_MSG 1
#define EMPTY_REQ 0
#define NOT_EMPTY_REQ 1

struct HttpRequest
{
	char isEmpty = EMPTY_REQ;
	int method;
	char url[1024];
	char httpVersion[9];

	char connectionHeader[255];
	char contentTypeHeader[255];
	int contentLengthHeader;

	char* content;
};

struct HttpResponse
{
	char httpVersion[9] = "HTTP/1.1";
	int responseCode;
	char statusPhrase[16];

	char connectionHeader[255];
	char contentTypeHeader[255];
	char dateHeader[255];
	char lastModifiedHeader[255];
	char serverHeader[255];
	int contentLengthHeader;

	char* content;
};

int parseHttpRequest(char *msg, int len, HttpRequest *reqPtr);
int httpResponseToString(HttpResponse response, char buffer[]);
HttpResponse handleGetRequest(HttpRequest req);
HttpResponse handlePostRequest(HttpRequest req);
HttpResponse handlePutRequest(HttpRequest req);
HttpResponse handleTraceRequest(HttpRequest req);
HttpResponse handleOptionsRequest(HttpRequest req);
HttpResponse handleHeadRequest(HttpRequest req);
HttpResponse handleDeleteRequest(HttpRequest req);