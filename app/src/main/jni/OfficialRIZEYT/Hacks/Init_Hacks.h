#pragma once

#define targetLib OBFUSCATE("libil2cpp.so")

uintptr_t il2cppMap;
void *m_EGL = nullptr;

bool initImGui;

int s_Width = 0;
int s_Height = 0;
