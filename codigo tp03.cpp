#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


typedef struct {
    float X;
    float Y;
} Ponto;

float calcularArea(Ponto vertices[], int n) {
    float area = 0.0;
    int j;

    for (int i = 0; i < n; i++) {
        j = (i + 1) % n;
        area += (vertices[i].X * vertices[j].Y - vertices[j].X * vertices[i].Y);
    }

    return 0.5 * fabs(area);
}

int main() {
    FILE *file;
    int n;
setlocale(LC_ALL, "Portuguese");
    file = fopen("poligonos.txt", "r");

    if (file == NULL) {
        printf("Erro.");
        return 1;
    }

    fscanf(file, "%d", &n);

    Ponto *vertices = (Ponto *)malloc(sizeof(Ponto) * n);

    if (vertices == NULL) {
        printf("Erro.");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%f %f", &vertices[i].X, &vertices[i].Y);
    }

    fclose(file);

    float area = calcularArea(vertices, n);

    printf("A área do polígono é %.2f\n", area);


    free(vertices);

    return 0;
}


