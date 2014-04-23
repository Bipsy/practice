#include <stdio.h>
#include <curl/curl.h>

size_t download(char* ptr, size_t size, size_t nmemb, FILE* stream) {
	return fwrite(ptr, size, nmemb, stream);
}

int main(int argc, char** argv) {
	CURL* curl;
	CURLcode res;

	curl = curl_easy_init();
	if (curl) {
		FILE* fp = fopen("index.html", "w");
		curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, download);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
	
		res = curl_easy_perform(curl);
		if (res != CURLE_OK) {
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
		fclose(fp);
	}
	return 0;
}

