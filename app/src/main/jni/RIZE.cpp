#include "RIZE.h"
#define LOG_TAG "Put"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
bool copyFile(const char *SRC, const char* DEST)
{
    std::ifstream src(SRC, std::ios::binary);
    std::ofstream dest(DEST, std::ios::binary);
    dest << src.rdbuf();
    return src && dest;
}

#define RealLibToLoad "/sdcard/Android/data/com.mobile.legends/files/dragon2017/assets/comlibs/arm64-v8a/libAkSoundEnginerize.so"
#define RealLibToLoad2 "/data/data/com.mobile.legends/app_libs/comlibs/arm64-v8a/libAkSoundEnginerize.so"
#define RealLibToLoad3 "/data/data/com.mobile.legends/app_libs/comlibs/arm64-v8a/libAkSoundEnginerize.so"

void *pLibRealUnity = 0;
typedef jint(JNICALL *CallJNI_OnLoad_t)(JavaVM *vm, void *reserved);
CallJNI_OnLoad_t RealJNIOnLoad = 0;
EGLBoolean (*orig_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
EGLBoolean _eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
	
	eglQuerySurface(dpy, surface, EGL_WIDTH, &s_Width);
	eglQuerySurface(dpy, surface, EGL_HEIGHT, &s_Height);
	
	if (s_Width <= 0 || s_Height <= 0) {
		return eglSwapBuffers(dpy, surface);
	}
	
	if (!initImGui) {
		SetupImgui();
		initImGui = true;
	}
	
	Tick();
	return orig_eglSwapBuffers(dpy, surface);
}

void *Init_Thread(void *) {
	copyFile(RealLibToLoad,RealLibToLoad2);
	while (!il2cppMap) {
		il2cppMap = Tools::GetBaseAddress(targetLib);
		sleep(1);
	}
	
	while (!m_EGL) {
        m_EGL = dlopen_ex("libEGL.so", RTLD_NOW);
        sleep(1);
    }

	Il2CppAttach(targetLib);
    sleep(5);
	
	//Hook EGL
	bInitDone = true;
	
	Tools::Hook((void *) dlsym_ex(m_EGL, OBFUSCATE("eglSwapBuffers")), (void *) _eglSwapBuffers, (void **) &orig_eglSwapBuffers);
	Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), "", OBFUSCATE("System/Net"), OBFUSCATE("GetHostByName_internal"), 4), (void *) oDns_GetHostByName_internal, (void **) &Dns_GetHostByName_internal);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), "", OBFUSCATE("System/Net"), OBFUSCATE("GetHostByAddr_internal"), 4), (void *) oDns_GetHostByAddr_internal, (void **) &Dns_GetHostByAddr_internal);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), "", OBFUSCATE("System/Net"), OBFUSCATE("hostent_to_IPHostEntry"), 3), (void *) oDns_hostent_to_IPHostEntry, (void **) &Dns_hostent_to_IPHostEntry);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), "", OBFUSCATE("System/Net"), OBFUSCATE("GetHostByAddressFromString"), 2), (void *) oDns_GetHostByAddressFromString, (void **) &Dns_GetHostByAddressFromString);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), "", OBFUSCATE("System/Net"), OBFUSCATE("GetHostEntry"), 1), (void *) oDns_GetHostEntry, (void **) &Dns_GetHostEntry);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), "", OBFUSCATE("System/Net"), OBFUSCATE("GetHostEntry"), 1), (void *) oDns_GetHostEntry, (void **) &Dns_GetHostEntry);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), "", OBFUSCATE("System/Net"), OBFUSCATE("GetHostAddresses"), 1), (void *) oDns_GetHostAddresses, (void **) &Dns_GetHostAddresses);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), "", OBFUSCATE("System/Net"), OBFUSCATE("GetHostByName"), 1), (void *) oDns_GetHostByName, (void **) &Dns_GetHostByName);
    Tools::Hook((void *) BattleManager_Update, (void *) UpdateMapHack, (void **) &oUpdateMapHack);

    Tools::Hook((void *) ShowUnitAIComp_TryUseSkill, (void *) TryUseSkill, (void **) &orig_TryUseSkill);
    Tools::Hook((void *) ShowUnitAIComp_Update, (void *) UpdateRetribution, (void **) &orig_UpdateRetribution);
    
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), "", OBFUSCATE("GameMain"), OBFUSCATE("PlugInTesting"), 0), (void *) PlugInTesting, (void **) &oPlugInTesting);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), "", OBFUSCATE("GameReceiveMessage"), OBFUSCATE("SendGameReport"), 0), (void *) SendGameReport, (void **) &oSendGameReport);
    OffsetFunc_ReportMd5 = (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("LogicBattleManager") , OBFUSCATE("ReportMd5"), 1);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), "", OBFUSCATE("APKSignature"), OBFUSCATE("IsSignatureSame"), 1), (void *) IsSignatureSame, (void **) &oIsSignatureSame);
    
    Tools::Hook((void *) (uintptr_t)Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("SystemData") , OBFUSCATE("BUseEsportsEmblem"), 0), (void *) s_Emblem, (void **) &s_Emblem2);
    Tools::Hook((void *) (uintptr_t)Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("ChooseHeroMgr") , OBFUSCATE("BCustomRoomFreeSkill"), 0), (void *) s_Spell, (void **) &s_Spell2);
    Tools::Hook((void *) SystemData_GetHeroSkin, (void *) GetHeroSkin, (void **) &oGetHeroSkin);
    Tools::Hook((void *) SystemData_GetMCLimitSkin, (void *) GetMCLimitSkin, (void **) &oGetMCLimitSkin);
    Tools::Hook((void *) SystemData_GetHeroHolyStatue, (void *) GetHeroHolyStatue, (void **) &oGetHeroHolyStatue);
    Tools::Hook((void *) SystemData_IsCanUseSkin, (void *) IsCanUseSkin, (void **) &oIsCanUseSkin);
    Tools::Hook((void *) SystemData_IsHaveSkin, (void *) IsHaveSkin, (void **) &oIsHaveSkin);
    Tools::Hook((void *) SystemData_IsHaveSkinForever, (void *) IsHaveSkinForever, (void **) &oIsHaveSkinForever);
    Tools::Hook((void *) SystemData_IsHaveStatue, (void *) IsHaveStatue, (void **) &oIsHaveStatue);
    Tools::Hook((void *) SystemData_IsHaveStatueForever, (void *) IsHaveStatueForever, (void **) &oIsHaveStatueForever);
    Tools::Hook((void *) SystemData_IsForbidStatue, (void *) IsForbidStatue, (void **) &oIsForbidStatue);
    Tools::Hook((void *) SystemData_IsForbidSkin, (void *) IsForbidSkin, (void **) &oIsForbidSkin);
    Tools::Hook((void *) SystemData_IsForbidARSkin, (void *) IsForbidARSkin, (void **) &oIsForbidARSkin);

    Tools::Hook((void *) UIChooseHero_SendSelectSkin, (void *) SendSelectSkin, (void **) &oSendSelectSkin);
    
    Tools::Hook((void *) UIChooseHero_SendSelectSkin2, (void *) SendSelectSkin2, (void **) &oSendSelectSkin2);
    
    Tools::Hook((void *) UIChooseHero_ShowSkinExpiryDate, (void *) ShowSkinExpiryDate, (void **) &oShowSkinExpiryDate);

    Tools::Hook((void *) UIRankHero_BatttleSelectSkin, (void *) BatttleSelectSkin, (void **) &oBatttleSelectSkin);
    
    Tools::Hook((void *) UIRankHero_BatttleSelectSkin2, (void *) BatttleSelectSkin2, (void **) &oBatttleSelectSkin2);

    Tools::Hook((void *) UIRankHero_ChangeShow_SendUseSkin, (void *) SendUseSkin, (void **) &oSendUseSkin);

    Tools::Hook((void *) BattleReceiveMessage_SetPlayerData, (void *) SetPlayerData, (void **) &oSetPlayerData);
  // Tools::Hook((void *) BattleReceiveMessage_SetPlayerData_, (void *) SetPlayerData_, (void **) &oSetPlayerData_);
  //Tools::Hook((void *) BattleReceiveMessage_AddPlayerInfo, (void *) AddPlayerInfo, (void **) &oAddPlayerInfo);
  //Tools::Hook((void *) BattleReceiveMessage_AddPlayerInfo_, (void *) AddPlayerInfo_, (void **) &oAddPlayerInfo_);

    Tools::Hook((void *) GameServerConfig_SendRawData, (void *) SendRawData, (void **) &oSendRawData);
	
	//OffsetFunc_ShowSelfPlayer_TryUseSkill = (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("ShowSelfPlayer"), OBFUSCATE("TryUseSkill"), 7);
   // DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("ShowSelfPlayer"), OBFUSCATE("OnUpdate")), (void *) ShowSelfPlayer_OnUpdate2, (void **) &oShowSelfPlayer_OnUpdate2)

//Tools::Hook((void *) (uintptr_t)Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Application") , OBFUSCATE("get_targetFrameRate")), (void *) Frame_Rate, (void **) &old_FrameRate);
	
    Auto_Skill();
    
	return nullptr;
}


JNIEXPORT jint JNICALL CallJNIOL(
        JavaVM *vm, void *reserved) {
    LOGI("Exec %s", RealLibToLoad);
	
    pthread_t myThread;
	pthread_create(&myThread, NULL, Init_Thread, NULL);
	
	sleep(5);
	
    if (!pLibRealUnity)
        pLibRealUnity = dlopen(RealLibToLoad, RTLD_NOW);
		pLibRealUnity = dlopen(RealLibToLoad3, RTLD_NOW);
    if (!RealJNIOnLoad)
        RealJNIOnLoad = reinterpret_cast<CallJNI_OnLoad_t>(dlsym(pLibRealUnity, "JNI_OnLoad"));
    return RealJNIOnLoad(vm, reserved);
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    jvm = vm;
JNIEnv *env;
vm->GetEnv((void **) &env, JNI_VERSION_1_6);
    LOGI("Initialize JNI");
    return CallJNIOL(vm, reserved);
}


