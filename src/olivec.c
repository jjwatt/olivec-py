#define OLIVEC_IMPLEMENTATION

#include "olivec.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image_write.h"

#define WIDTH 900
#define HEIGHT 600

int draw_flag_jp(void)
{
  uint32_t pixels[WIDTH*HEIGHT];
  Olivec_Canvas oc = olivec_canvas(pixels, WIDTH, HEIGHT, WIDTH);
  olivec_fill(oc, 0xFFFFFFFF);
  olivec_circle(oc, WIDTH/2, HEIGHT/2, 180, 0xFF2D00BC);

  const char *file_path = "flag_jp.png";
  if (!stbi_write_png(file_path,
		      WIDTH,
		      HEIGHT,
		      4,
		      pixels,
		      sizeof(uint32_t)*WIDTH)) {
    fprintf(stderr, "ERROR: could not write: %s\n", file_path);
    return 1;
  }
  return 0;
}
