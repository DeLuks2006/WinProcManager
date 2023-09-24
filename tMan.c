#include <stdio.h>
#include <windows.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	char help[] = "--help";
	char wait[1];
	int pid = atoi(argv[2]);
	
	if (argc < 2) {
		printf("invalid syntax.\n\n./test.exe <option> <PID>\n./test.exe <option> <handle>\n\n");
		
	} else if (strcmp(argv[1], help) == 0) {
		printf("-- welcome to the CLI task manager clone --\n");
		printf("[1] Get Current from your PID\n[2] Kill Process ");
		
	} else if (strcmp(argv[1], "1") == 0) {
		DWORD MyProcess = GetCurrentProcessId();
		printf("PID = %ld\n", MyProcess);
		gets(wait); // temporary
		
	} else if (strcmp(argv[1], "2") == 0) {
		HANDLE hProcHandle = OpenProcess(
		PROCESS_ALL_ACCESS,
		FALSE,
		pid
		);
		
		TerminateProcess(
		hProcHandle, 
		ERROR_SUCCESS
		);
	}
}
