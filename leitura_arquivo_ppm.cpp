#include <iostream>

struct Pixel {

  int r, g, b;

}

class Imagem {

  private:
    struct Pixel **pixels;
    int width, height;
    char tipo[2];

    void setPixels(FILE *arq) {

      struct Pixel **pixel;

      fscanf(arq, "%s %d %d\n\n", &this->tipo, this->width, this->height);

      pixel = (struct Pixel **) malloc (sizeof(struct Pixel *) * (this->height));

      for (int i = 0; i < this->width; i++) {

        pixel[i] = (struct Pixel *) malloc (sizeof(struct Pixel) * (this->width));

      }

      for (int y = 0; y < this->height; y++) {
        for (int x = 0; x < this->width; x++) {
          fscanf(arq, "%d %d %d ", &pixel[y][x].r, &pixel[y][g].g);
        }
      }
    }

}
