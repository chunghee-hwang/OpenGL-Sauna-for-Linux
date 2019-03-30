#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "bitmaploader.h"
typedef struct MY_BITMAP_INFO mybitmapinfo;
float g_fSpinX = 0.0f;
float g_fSpinY = 0.0f;

GLuint texture[TEXTURE_NUM]; //texture ID
char texture_name[TEXTURE_NUM][20] = { "desk.bmp", "bright_wood.bmp", "lock.bmp", "glass.bmp", "wall.bmp","mirror.bmp","chair.bmp","saunaWall.bmp","darkWood.bmp","mackbanseock.bmp",
"stainless.bmp","showerHeadHole.bmp", "marble.bmp","water.bmp", "temp20.bmp", "temp39.bmp", "temp42.bmp", "temp59.bmp", "saunaWall2.bmp", "background.bmp","grass.bmp", "forest.bmp"
};

void getBitmapInfo(char* imagepath, mybitmapinfo* bitinfo)
{
	// Data read from the header of the BMP file
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char * data;

	// Open the file
	FILE * file = fopen(imagepath,"rb");
	
	if (!file){printf("Image could not be opened\n"); return;}
	if (fread(header, 1, 54, file)!=54 )
	{ 
		// If not 54 bytes read : problem
    		printf("Not a correct BMP file\n");
    		return;
	}
	if ( header[0]!='B' || header[1]!='M' ){
	    	printf("Not a correct BMP file\n");
	    	return;
	}

	dataPos    = *(int*)&(header[0x0A]);
	imageSize  = *(int*)&(header[0x22]);
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header[0x16]);
	// 몇몇 BMP 파일들은 포맷이 잘못되었습니다. 정보가 누락됬는지 확인해봅니다. 
	// Some BMP files are misformatted, guess missing information
	if (imageSize==0)    imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos==0)      dataPos=54; // The BMP header is done that way
	
	// 버퍼 생성
	//data = new unsigned char [imageSize];
	data = (unsigned char*)malloc(sizeof(unsigned char) * imageSize);
	// 파일에서 버퍼로 실제 데이터 넣기. 
	fread(data,1,imageSize,file);
	bitinfo->data = data;
	bitinfo->width = width;
	bitinfo->height = height;
	//이제 모두 메모리 안에 있으니까, 파일을 닫습니다. 
	//Everything is in memory now, the file can be closed
	fclose(file);
	printf("image name: %s\n", imagepath);
	printf("Image width : %d \n", width);
	printf("Image height: %d \n", height);

}

void LoadGLTextures()
{
	int i;
	mybitmapinfo bitmapinfo;
	
	for (i = 0; i < TEXTURE_NUM; i++) 
	{
		getBitmapInfo(texture_name[i], &bitmapinfo);
		
		if (bitmapinfo.width != -1) {
			glGenTextures(1, &texture[i]);
			glBindTexture(GL_TEXTURE_2D, texture[i]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
			glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			//glTexImage2D(GL_TEXTURE_2D, 0, 3, bitmapinfo.width,
				//bitmapinfo.height, 0,
				//GL_RGB, GL_UNSIGNED_BYTE, bitmapinfo.data);
			glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, bitmapinfo.width, bitmapinfo.height, 0, GL_BGR, GL_UNSIGNED_BYTE,  bitmapinfo.data);
			printf("\n\n");
			
		}
		else {
			puts("Image file has a error !");
		}
	}
	
}
