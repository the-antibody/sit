#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>
#include <sys/stat.h>

#include "get.h"

/**
 * C EXCEPTIONS LIBRARY
 * By Yochran
 */
#include "exceptions.h"

/**
 * FORMAT:
 * sit
 */

/**
 * @brief Main function
 * 
 * @param argc - argument count
 * @param argv - argument array
 * @return int 
 */
int main(int argc, char *argv[])
{
    // get euid
    uid_t uid = getuid(), euid = geteuid();

    // check if running as root
    if (uid != euid || uid != 0)
    {
        // create exception
        exception _exception = {
            "You must be running as a super-user to use sit.",
            NO_PERMISSION
        };

        // throw exception
        _throw(&_exception);
        exit(0);
    }

    // check argument length
    if (argc != 1)
    {
        // create exception
        exception _exception = {
            "Correct usage: sit",
            INCORRECT_ARGUMENTS
        };

        // throw exception
        _throw(&_exception);
        exit(0);
    }

    // create system structure
    char os[100], version[100], cpu[100], gpu[100], motherboard[100], memory[100], cpu_temp[100];

    // apply to variables
    get_os(os);
    get_version(version);
    get_cpu(cpu);
    get_gpu(gpu);
    get_motherboard(motherboard);
    get_memory(memory);
    get_cpu_temp(cpu_temp);

    // create message variable
    char *message = (char*) malloc(512);
    sprintf(message, "\n--- SYSTEM INFORMATION: ---\n\nOS: %s\nOS Release: %s\nCPU: %s\nGPU: %s\nMotherboard: %s\nMemory: %s\nCPU Temperature: %s\n\n", os, version, cpu, gpu, motherboard, memory, cpu_temp);

    // print
    printf(message);

    // free memory
    free(message);

    return 0;
}