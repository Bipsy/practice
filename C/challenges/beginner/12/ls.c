#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>


int main(int argc, char** argv) {
	int opt;
	char lflag;
	char aflag;
	char Fflag;
	char hflag;
	while ((opt = getopt(argc, argv, "laFh")) != -1) {
		switch (opt) {
			case 'l':	lflag = opt;
						break;
			case 'a': 	aflag = opt;
						break;
			case 'F':	Fflag = opt;
						break;
			case 'h':	hflag = opt;
						break;
			default:	break;
		}
		
	}

	DIR* dir = opendir("./");
	if (dir == NULL) printf("dir is empty\n");
	rewinddir(dir);
	struct dirent* directory_entry;
	while ((directory_entry = readdir(dir)) != NULL) {
		if (aflag) {
			if (directory_entry->d_name[0] != '.') {
				printf("%s\n", directory_entry->d_name);
			}
		} else {
			printf("%s\n", directory_entry->d_name);
		}
	}

	closedir(dir);

	return 0;
}
