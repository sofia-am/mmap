#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <sys/stat.h>

struct stat st;

struct data
{
    unsigned int version;
    unsigned int drxVersion;
    char RESERVED[4];
    double initCW;
    float azimuth;
    float elevation;
    unsigned int idVolumen;
    unsigned int idBarrido;
    unsigned int idConjunto;
    unsigned int idGrupo;
    unsigned int idPulso;
    bool iniBarrido;
    bool finBarrido;
    bool inhibido;
    unsigned int validSamples;
    unsigned int nroAdquisicion;
    char reserved2[2];
    unsigned int nroSecuencia;
    unsigned long long readTime_high;
    unsigned long long readTime_low;
    char reserved3[64];
};

int main()
{

    const char *rawdata = "rawdata/datos";
    int fd = open(rawdata, O_RDONLY);
    if (fd == -1)
    {
        printf("Error al abrir el archivo");
        exit(1);
    }
    printf("Size of struct: %ld\n", sizeof(struct data));

    int stat = fstat(fd, &st);
    if (stat == -1)
    {
        printf("Error al obtener el tamaño del archivo");
        exit(1);
    }
    printf("Size of file: %ld\n", st.st_size);
}
