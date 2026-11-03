#pragma once

typedef unsigned long DWORD;

// ==================================================================================================================================== //
bool SetProtRWX(void *addr) {
    unsigned long page_size = sysconf(_SC_PAGESIZE);
    unsigned long size = page_size * sizeof(uintptr_t);
    void *p = (void *) ((uintptr_t) addr - ((uintptr_t) addr % page_size) - page_size);

    return mprotect(p, (size_t) size, PROT_READ | PROT_WRITE | PROT_EXEC) == 0;
}

void HookFunc(void *address, void *replace, void **backup) {
    if (SetProtRWX(address)) {
        Tools::Hook(address, replace, backup);
    }
}

void WriteAddr(void *address, void *buf, size_t size) {
    if (SetProtRWX(address)) {
        memcpy(address, buf, size);
    }
}
// ==================================================================================================================================== //
#define DefineHook(RET, NAME, ARGS) \
    RET (*o ## NAME) ARGS; \
    RET NAME ARGS


uintptr_t OffsetFunc_ShowSelfPlayer_TryUseSkill;

uintptr_t OffsetFunc_CData_Bullet_GetValue_ByID;

