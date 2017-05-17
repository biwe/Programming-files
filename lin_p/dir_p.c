/* this is a programme which prints the name 
 * of dirctory and subdirectory.
 *
 * optional: print files in each directory.
 * depth: the distance of indent
 *
 * this just copys from <<Beginning Linux Programming>>
 * 									biwei
 * */

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printdir(char *dir, int depth){
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;

	if((dp=opendir(dir))==NULL){
		fprintf(stderr,"cannot open directory: %s\n", dir);
		return;
	}
	chdir(dir);
	while((entry=readdir(dp)) != NULL){
		lstat(entry->d_name, &statbuf);
		if(S_ISDIR(statbuf.st_mode)){
			/* Found a directory, but ignore . and .. */
			if(strcmp(".", entry->d_name)==0 ||
					strcmp("..",entry->d_name)==0)
				continue;
			printf("%*s%s/\n",depth," ",entry->d_name);
			/* Recurse at a new indent level */
			printdir(entry->d_name,depth+4);
		}
	/* optional: print files. */
	//	else printf("%*s%s\n",depth,"",entry->d_name);
	}
	chdir("..");
	closedir(dp);
}

int main(){
	printf("Directory scan of /home/bv_user/Documents:\n");
	printdir("/home/bv_user/Documents",0);
	printf("done.\n");

	exit(0);
}

