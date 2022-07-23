#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <string.h>
#include <unistd.h>

#include "utils.h"

/**
 * @brief Get the os name
 * 
 * @param var the variable to apply to
 */
void get_os(char *var)
{
    // create os data buffer
    struct utsname buffer;

    // check if buffer is null
    if (uname(&buffer) != 0)
        return;

    // pipe the os data to a txt file
    system("cat /etc/os-release | grep 'PRETTY' >> os_data.txt");

    // pull from the file
    FILE *file = fopen("os_data.txt", "rb"); 
    char *os_name = (char*) malloc(100);
    fgets(os_name, 100, file); 
    fclose(file);

    // delete the file
    system("rm os_data.txt");

    // cut the string
    os_name += 13;
    rmsubstr(os_name, "\n");
    rmsubstr(os_name, "\"");

    // merge the string
    char *os = (char*) malloc(100);
    sprintf(os, "%s %s", os_name, buffer.machine);

    // export
    memcpy(var, os, strlen(os));

    // free memory
    free(os_name -= 13);
    free(os);
}

/**
 * @brief Get the version
 * 
 * @param var the variable to apply to
 */
void get_version(char *var)
{
    // create os data buffer
    struct utsname buffer;

    // check if buffer is null
    if (uname(&buffer) != 0)
        return;

    // export string
    memcpy(var, buffer.release, strlen(buffer.release));
}

/**
 * @brief Get the cpu
 * 
 * @param var the variable to apply to
 */
void get_cpu(char* var)
{
    // pipe the cpu data to a txt file
    system("cat /proc/cpuinfo | grep 'model name' -m 1 >> cpu_data.txt");

    // pull from the file
    FILE *file = fopen("cpu_data.txt", "rb"); 
    char *cpu = (char*) malloc(100);
    fgets(cpu, 100, file); 
    fclose(file);

    // delete the file
    system("rm cpu_data.txt");

    // cut the string
    cpu += 13;
    rmsubstr(cpu, "\n");

    // export
    memcpy(var, cpu, strlen(cpu - 3));

    // free memory
    free(cpu -= 13);
}

/**
 * @brief Get the gpu
 * 
 * @param var the variable to apply to
 */
void get_gpu(char* var)
{
    // pipe the gpu data to a txt file
    system("lspci | grep ' VGA ' >> gpu.txt");

    // pull from the file
    FILE *file = fopen("gpu.txt", "rb"); 
    char *gpu = (char*) malloc(200);
    fgets(gpu, 200, file); 
    fclose(file);

    // delete the file
    system("rm gpu.txt");

    // cut the string
    int index = 0;
    for (int i = 0; i < strlen(gpu); i++)
    {
        if (gpu[i] == '[')
        {
            index = ++i;
            gpu += index;
            break;
        }
    }

    rmsubstr(gpu, "\n");
    rmsubstr(gpu, "] (rev a1)");

    // export
    memcpy(var, gpu, strlen(gpu - 1));

    // free memory
    free(gpu -= index);
}

/**
 * @brief Get the motherboard
 * 
 * @param var the variable to apply to
 */
void get_motherboard(char *var)
{
    // pipe the motherboard data to a txt file
    system("sudo dmidecode -t 2 | grep 'Product' >> motherboard.txt");

    // pull from the file
    FILE *file = fopen("motherboard.txt", "rb"); 
    char *motherboard = (char*) malloc(100);
    fgets(motherboard, 100, file); 
    fclose(file);

    // delete the file
    system("rm motherboard.txt");

    // cut the string
    motherboard += 15;
    rmsubstr(motherboard, "\n");

    // export
    memcpy(var, motherboard, strlen(motherboard));

    // free memory
    free(motherboard -= 15);
}

/**
 * @brief Get the memory
 * 
 * @param var the variable to apply to
 */
void get_memory(char *var)
{
    // pipe the memory data to a txt file
    system("free -h | grep 'Mem' >> memory.txt");

    // pull from the file
    FILE *file = fopen("memory.txt", "rb"); 
    char *memory = (char*) malloc(200);
    fgets(memory, 200, file); 
    fclose(file);

    // delete the file
    system("rm memory.txt");

    // cut the string
    memory += 16;
    for (int i = 3; i < strlen(memory); i++)
        memory[i] = '\0';

    rmsubstr(memory, "\n");

    // create final string
    char *fnl = (char*) malloc(50);
    sprintf(fnl, "%sB", memory);

    // export
    memcpy(var, fnl, strlen(fnl));

    // free memory
    free(memory -= 16);
    free(fnl);
}

/**
 * @brief Get the cpu temperature
 * 
 * @param var the variable to apply to
 */
void get_cpu_temp(char *var)
{
    // pipe the sensor data to a txt file
    system("sensors | grep 'Package id' >> cpu_temp.txt");

    // pull from the file
    FILE *file = fopen("cpu_temp.txt", "rb"); 
    char *temp = (char*) malloc(100);
    fgets(temp, 100, file); 
    fclose(file);

    // give time to record
    sleep(0.5);

    // delete file
    system("rm cpu_temp.txt");

    // cut the string
    temp += 16;
    for (int i = 6; i < strlen(temp); i++)
        temp[i] = '\0';

    rmsubstr(temp, "\n");

    // export
    memcpy(var, temp, strlen(temp));

    // free memory
    free(temp -= 16);
}