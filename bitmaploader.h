#ifndef bitmaploader_h
#define bitmaploader_h
#define TEXTURE_NUM 22 //image °³Œö
typedef struct MY_BITMAP_INFO mybitmapinfo;
struct MY_BITMAP_INFO
{
	int width;
	int height;
	unsigned char *data;
};

extern float g_fSpinX;
extern float g_fSpinY;
extern GLuint texture [TEXTURE_NUM]; //texture ID
extern char texture_name[TEXTURE_NUM][20];
void LoadGLTextures();
void getBitmapInfo(char* filename, mybitmapinfo* bitinfo);
#endif
