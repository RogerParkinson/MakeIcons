/*
 * Icon.h
 *
 *  Created on: Oct 24, 2017
 *      Author: roger
 */

#ifndef ICON_H_
#define ICON_H_

unsigned long char_to_bin10(char ch) {
  unsigned char uch = ch;
  unsigned long sum = 0;
  unsigned long power = 1;
  while (uch) {
    if (uch & 1) {
      sum += power;
      }
   power *= 10;
   uch /= 2;
  }
  return sum;
}

unsigned long long_to_bin10(long ch) {
  unsigned char uch = ch;
  unsigned long sum = 0;
  unsigned long power = 1;
  while (uch) {
    if (uch & 1) {
      sum += power;
      }
   power *= 10;
   uch /= 2;
  }
  return sum;
}

unsigned long int_to_bin10(int ch) {
  unsigned int uch = ch;
  unsigned long sum = 0;
  unsigned long power = 1;
  while (uch) {
    if (uch & 1) {
      sum += power;
      }
   power *= 10;
   uch /= 2;
  }
  return sum;
}

class Icon {
public:
	unsigned int size;
	const char *bitmap;
	Icon(const unsigned int s, const char *data) {
		size = s;
		bitmap = data;
	};
	virtual ~Icon() {
	};
	const void draw(const int x, const int y) {
		const char *pImg = bitmap;

		char pRGB[3];
		printf("static uint16_t myicon[] PROGMEM = {");
		for (unsigned int j = 0; j < size; j++) {

			printf("\n\t");

			for (unsigned int i = 0; i < size; i++) {
				pRGB[0] = ((pImg[3] - 33)) | (((pImg[2] - 33)& 0x3)<<6);
				pRGB[1] = ((((pImg[2] - 33) >> 2) & 0xF) | ((pImg[1] - 33) &0xF)<<4);
				pRGB[2] = (((pImg[1] - 33) >> 4) & 0x3 ) | ((pImg[0] - 33)<<2);
				unsigned int colour = ((pRGB[0]) & 0x0000FF)
						| ((((unsigned int) pRGB[1]) << 8) & 0x00FF00)
						| ((((unsigned int) pRGB[2]) << 16) & 0xFF0000);
				unsigned int colour16 = ((colour & 0x0000F8) >> 3)
				         | ((colour & 0x00F800) >> 5)
				         | ((colour & 0xF80000) >> 8);
					printf("0x%04x,",colour16);
				pImg += 4;
			}
		}
		printf("0x0};\n");

	}

};


#endif /* ICON_H_ */
