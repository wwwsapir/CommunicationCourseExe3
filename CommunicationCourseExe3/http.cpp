#define _CRT_SECURE_NO_WARNINGS
#include "http.h"
#include <iostream>
#include <string>
using namespace std;


int parseHttpRequest(char *msg, int len, HttpRequest *reqPtr)
{
	if (len == 0)
	{
		return INVALID_HTTP_MSG;
	}
	msg[len] = '\0';
	cout << msg;
	char* rest = msg;

	char* line = strtok_s(msg, "\n", &rest);
	int lineID = 0;
	while (line != NULL && lineID >= 0) {
		cout << line << "\n";
		if (lineID == 0) //method url version
		{
			char* part = strtok(line, " "); //method
			reqPtr->method = -1;
			for (int i = 0; i < NUMBER_OF_OPTIONS; i++)
			{
				if (!strcmp(httpMethods[i], part))
				{
					reqPtr->method = i;
				}
			}
			if (reqPtr->method == -1) //error validation
			{
				return INVALID_HTTP_MSG;
			};
			part = strtok(NULL, " "); //url
			strcpy(reqPtr->url, part);
			//cout << part << "\n";
			part = strtok(NULL, "\r"); //version
			//cout << part << "\n";
			strcpy(reqPtr->httpVersion, part);
		}
		else //headers 
		{
			char* key = strtok(line, ":");
			char* value = strtok(NULL, "\r") + 1; //+1 skip space
			
			if (!strcmp("Connection", key))
			{
				strcpy(reqPtr->connectionHeader, value);
			}
			if (!strcmp("Content-Type", key))
			{
				strcpy(reqPtr->contentTypeHeader, value);
			}
			if (!strcmp("Content-Length", key))
			{
				reqPtr->contentLengthHeader = atoi(value);
			}
			if (!strcmp("\r", key)) //empty row before data
			{
				reqPtr->content =(char *)malloc(reqPtr->contentLengthHeader);
				strcpy(reqPtr->content, rest);
				//reqPtr->content = rest; //msg + len - reqPtr->contentLengthHeader; //todo : bug of data - only first row remains
			}
		}
		

		line = strtok_s(NULL, "\n", &rest); //strtok(NULL, "\n");
		lineID++;
	}
	reqPtr->isEmpty = NOT_EMPTY_REQ;
	return VALID_HTTP_MSG;
}

int httpResponseToString(HttpResponse response, char buffer[])
{
	cout << "httpResponseToString Not Implemented!";
	return 0;
}

HttpResponse handleGetRequest(HttpRequest req)
{
	cout << "handleGetRequest Not Implemented!"; //malloc
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
