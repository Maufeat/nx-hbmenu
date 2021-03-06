#pragma once

#include "common.h"

typedef struct
{
    color_t textColor;
    color_t frontWaveColor;
    color_t middleWaveColor;
    color_t backWaveColor;
    color_t backgroundColor;
    color_t highlightColor;
    bool enableWaveBlending;
    const uint8_t *buttonAImage;      
    const uint8_t *buttonBImage;
    const uint8_t *hbmenuLogoImage;
} theme_t;

typedef enum
{
    THEME_PRESET_LIGHT,
    THEME_PRESET_DARK,
} ThemePreset;

void themeStartup(ThemePreset preset);

theme_t themeCurrent;