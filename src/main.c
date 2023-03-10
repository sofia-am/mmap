#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <sys/stat.h>

struct stat st;

struct data
{
    short unsigned int version;
    short unsigned int drxVersion;
    char RESERVED[4];
    double initCW;
    float azimuth;
    float elevation;
    short unsigned int idVolumen;
    short unsigned int idBarrido;
    short unsigned int idConjunto;
    short unsigned int idGrupo;
    short unsigned int idPulso;
    bool iniBarrido;
    bool finBarrido;
    bool inhibido;
    short unsigned int validSamples;
    short unsigned int nroAdquisicion;
    char reserved2[2];
    unsigned int nroSecuencia;
    unsigned long long readTime_high;
    unsigned long long readTime_low;
    char reserved3[64];
};

int main()
{

   // printf("uint %ld\n",sizeof(unsigned long long)); //4
    const char *rawdata = "rawdata/datos";
    int fd = open(rawdata, O_RDONLY);
    if (fd == -1)
    {
        printf("Error al abrir el archivo");
        exit(1);
    }
    printf("Size of struct: %ld\n", sizeof(struct data)); //152

    int stat = fstat(fd, &st);
    if (stat == -1)
    {
        printf("Error al obtener el tamaño del archivo");
        exit(1);
    }
    printf("Size of file: %ld\n", st.st_size); //384

    /*********************** 1. Acceder a datos ***********************/

    struct data *data = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if(data == MAP_FAILED)
    {
        printf("Error al mapear el archivo");
        exit(1);
    }

    int size_of_file = st.st_size;
    int size_of_struct = sizeof(struct data);

    int nro_instances = size_of_file / size_of_struct;

    /*********************** 2. Instancias ***********************/
    printf("La cantidad de muestras contenidas en el archivo es de: %d\n", nro_instances);

    

}
