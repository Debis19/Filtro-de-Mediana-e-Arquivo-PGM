#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 512
#define MAX_HEIGHT 512
#define EMPTY_PIXEL -1  // Define um valor especial para pixels ausentes

// Função para ler a imagem PGM no formato P5
void readPGM(const char *filename, unsigned char image[MAX_HEIGHT][MAX_WIDTH], int *width, int *height, int *maxVal) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    char format[3];
    fscanf(file, "%2s", format);
    if (format[0] != 'P' || format[1] != '5') {
        printf("Formato de arquivo não suportado!\n");
        fclose(file);
        exit(1);
    }

    fscanf(file, "%d %d %d", width, height, maxVal);
    fgetc(file);  // Consome o caractere de nova linha após maxVal

    // Lê a imagem
    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            int pixel = fgetc(file);
            if (pixel == EOF) {
                image[i][j] = EMPTY_PIXEL;  // Se houver erro, marca como pixel ausente
            } else {
                image[i][j] = (unsigned char)pixel;
            }
        }
    }
    
    fclose(file);
}

// Função auxiliar para ordenação (bubble sort)
void sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função para corrigir a imagem usando a mediana dos vizinhos
void fixImage(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Verifica se o pixel é 0 (ou ausente)
            if (image[i][j] == 0) {  
                int neighbors[9];  // Array para armazenar os vizinhos
                int count = 0;

                // Percorre os vizinhos
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < height && nj >= 0 && nj < width && image[ni][nj] != EMPTY_PIXEL && image[ni][nj] != 0) {
                            neighbors[count++] = image[ni][nj];
                        }
                    }
                }

                if (count > 0) {
                    sort(neighbors, count);
                    image[i][j] = neighbors[count / 2]; // Usa a mediana dos vizinhos
                } else {
                    image[i][j] = 0;  // Se não houver vizinhos válidos, mantém como 0
                }
            }
        }
    }
}

// Função para salvar a imagem corrigida
void savePGM(const char *filename, unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height, int maxVal) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Erro ao salvar o arquivo!\n");
        exit(1);
    }

    fprintf(file, "P5\n%d %d\n%d\n", width, height, maxVal);
    
    for (int i = 0; i < height; i++) {
        fwrite(image[i], sizeof(unsigned char), width, file);
    }
    
    fclose(file);
}

// Função para exibir a matriz da imagem no console
void printImage(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    printf("\nImagem corrigida:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%3d ", image[i][j]);
        }
        printf("\n");
    }
}

int main() {
    unsigned char image[MAX_HEIGHT][MAX_WIDTH];
    int width, height, maxVal;

    readPGM("imagem.pgm", image, &width, &height, &maxVal);
    fixImage(image, width, height);
    savePGM("imagem_corrigida.pgm", image, width, height, maxVal);
    
    printf("Imagem corrigida salva como 'imagem_corrigida.pgm'.\n");

    // Exibir a matriz corrigida no console
    printImage(image, width, height);

    return 0;
}
