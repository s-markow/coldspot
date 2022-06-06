#ifndef __RFRONTEND_H
#define __RFRONTEND_H

void RF_Init();
void RF_Clean();

void RF_RenderFrame();

// gfx/textures.h (texture_t)
void RF_InitTexture( /* texture_t *tex*/ );
void RF_CleanTexture( /* texture_t *tex*/ );


#endif