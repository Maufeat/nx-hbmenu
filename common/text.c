#include "text.h"

#ifdef SWITCH
static int s_textLang = SetLanguage_ENUS;
#else
static int s_textLang = 1;
#endif

void textInit(void) {
    #ifdef SWITCH
    u64 LanguageCode=0;
    s32 Language=0;
    Result rc = setInitialize();
    s_textLang = SetLanguage_ENUS;
    if (R_SUCCEEDED(rc)) rc = setGetSystemLanguage(&LanguageCode);
    if (R_SUCCEEDED(rc)) rc = setMakeLanguage(LanguageCode, &Language);
    if (R_SUCCEEDED(rc) && Language < 16) s_textLang = Language;
    setExit();
    #else
    s_textLang = 1;
    #endif
}      

int textGetLang(void) {
    return s_textLang;
}

const char* textGetString(StrId id) {
    const char* str = g_strings[id][s_textLang];
    #ifdef SWITCH
    if (!str) str = g_strings[id][SetLanguage_ENUS];
    #else                              
    if (!str) str = g_strings[id][1];
    #endif
    return str;
}
