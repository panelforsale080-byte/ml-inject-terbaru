#pragma once
template <typename T>
struct monoArray
{
    void* klass;
    void* monitor;
    void* bounds;
    int   max_length;
    void* vector [1];
    int getLength()
    {
        return max_length;
    }
    T getPointer()
    {
        return (T)vector;
    }
};

template <typename T>
struct monoList {
    void *unk0;
    void *unk1;
    monoArray<T> *items;
    int size;
    int version;

    T getItems(){
        return items->getPointer();
    }

    int getSize(){
        return size;
    }

    int getVersion(){
        return version;
    }
};

template <typename K, typename V>
struct monoDictionary {
    void *unk0;
    void *unk1;
    monoArray<int **> *table;
    monoArray<void **> *linkSlots;
    monoArray<K> *keys;
    monoArray<V> *values;
    int touchedSlots;
    int emptySlot;
    int size;

    K getKeys(){
        return keys->getPointer();
    }

    V getValues(){
        return values->getPointer();
    }

    int getNumKeys(){
        return keys->getLength();
    }

    int getNumValues(){
        return values->getLength();
    }

    int getSize(){
        return size;
    }
};
union intfloat {
	int i;
	float f;
};

typedef struct _monoString
{
    void* klass;
    void* monitor;
    int length;    
    char chars[1];   
    int getLength()
    {
      return length;
    }
    char* getChars()
    {
        return chars;
    }
}monoString;

struct sConfig {
    struct sESP {
        struct sPlayer {
            bool Line;
            bool Box;
            bool Health;
            bool Name;
            bool Distance;
            bool Hero;
            bool CoolDown;
            bool Alert;
			bool ID;
            bool Visible;
			bool Radar;
			bool Color;
			
        };
        sPlayer Player{0};

        struct sMonster {
            bool Box;
            bool Health;
            bool Name;
            bool Alert;
        };
        sMonster Monster{0};
    };
    sESP ESP{0};

    struct sVisual {
        bool UnlockSkin;
		bool Eudora;
		bool AutoSteallB;
		bool AutoSteallA;
		bool AutoSteallP;
		bool Chou2;
		bool BeatrixSniper;
		bool Argus2;
		bool Esmeralda;
		bool Esmeralda2;
		bool Yve;
		bool Franco;
		bool Eudora22;
		bool Sprint;
		bool Edith2;
		bool Granger3;
		bool Helcurt;
		bool Harley;
		bool YinUlti2;
		bool YinUlti3;
		bool YinUlti4;
		bool YinUlti5;
		bool YinUlti6;
		bool Edith;
		bool Flameshot;
        bool MaphackIcon;
		bool HealthBar;
		bool Xavier;
		bool Speed;
		bool Hayabusa;
		bool AutoOn;
		bool AutoOff;
		bool AutoCombo;
		bool AutoSpell;
		bool ComboSkill;
		bool Pharsa;
		bool Moskov;
		bool Moskov2;
		bool Balmond2;
		bool Lylia2;
		bool Chou;
		bool Lylia;
		bool Granger;
		bool ComboSkill1;
		bool ComboSkill2;
		bool ComboSkill3;
		bool Retri;
		bool ComboSkill4;
		bool ComboXavierAutomatic;
		bool ComboXavierAutomatic2;
		bool ComboSkill21;
		bool ComboSkill32;
		bool Kagura2;
		bool HanzoBlue;
		bool Freedrin;
		bool Freedrin2;
		bool Dyrroth2;
		bool Dyrroth;
		bool Hilda;
		bool Hilda2;
		bool HanzoRed;
		bool Hanzo;
		bool ComboSkill31;
		bool ComboSkill321;
		bool Fliker;
		bool UltiFlicker;
		bool Skill1Flicker;
		bool GrangerLord;
		bool LaylaLord;
		bool XavierLord;
		bool MoskovLord;
		bool BalmondLord;
		bool BeatrixLord;
		bool PharsaLord;
		bool GusionLord;
		bool Xevana2;
		bool Xevana;
		bool PapuquitoLord;
		bool YveLord;
		bool GrangerTriggerLord;
		bool LaylaTriggerLord;
		bool XavierTriggerLord;
		bool MoskovTriggerLord;
		bool BalmondTriggerLord;
		bool BeatrixTriggerLord;
		bool PharsaTriggerLord;
		bool GusionTriggerLord;
		bool PapuquitoTriggerLord;
		bool YveTriggerLord;
		bool GrangerTurtle;
		bool LaylaTriggerTurtle;
		bool XavierTriggerTurtle;
		bool BalmondTurtle;
		bool BeatrixTurtle;
		bool PharsaTurtle;
		bool GusionTurtle;
		bool PapuquitoTurtle;
		bool YveTurtle;
		bool GrangerTriggerTurtle;
		bool LaylaTurtle;
		bool XavierTurtle;
		bool MoskovTurtle;
		//bool LaylaTriggerTurtle;
	//.bool XavierTriggerTurtle;
		bool MoskovTriggerTurtle;
		bool BalmondTriggerTurtle;
		bool BeatrixTriggerTurtle;
		bool PharsaTriggerTurtle;
		bool GusionTriggerTurtle;
		bool PapuquitoTriggerTurtle;
		bool YveTriggerTurtle;
		//bool MoskovTriggerTurtle;
		bool Skill2Flicker;
		bool Skill4Flicker;		
		bool Gusion223;
		bool Balmond;
		bool Beatrix2;
		bool Martis;
		bool Kagura;
		bool Gusion2;
		bool XavierRed;
		bool XavierBlue;
		bool Ruby;
		bool Dragons;
		
		bool Vale;
		bool Gusion3;
		bool GrangerTrigger;
		bool LaylaTrigger;
		bool XavierTrigger;
		bool MoskovTrigger;
		bool ComboXavier221;
		bool BeatrixTrigger;
		bool BalmondTrigger;
		bool Granger2;
		bool Vale2;
		bool Layla2;
		bool YinUlti;
		bool Argus;
		bool Beatrix;
		bool Beatrix3;
		bool UnlockEmblem;
		bool UnlockSpell;
		bool ComboGS;
		bool Moskov22;
		bool Xavier22;
		bool Balmond222;
		bool Gusion33;
		bool Papuquito33;
		bool Papuquito3;
		bool AutoSteall;
		bool AutoSteallTrigger;
		bool Yve3;
		bool Yve33;
		bool Yve2233;
		bool Martis222;
		bool Pharsa3;
		bool PharsaTrigger;
		bool Selena;
		bool Selena2;
		bool Xavier223;
		bool Freya;
		bool Freya2;
		bool ComboXavier21;
		bool ComboXavier12;
		bool ComboXavier122;
		bool BeatrixUlti;
		
    };
    sVisual Visual{0};
};
sConfig Config{0};

bool Player;
bool showjungle;
//static float DistCombo = 5.0f;	
int FrameRate = 0;
static float Speed = 10.0f;
static int RedLine = 255;
static int GreenLine = 255;
static int BlueLine = 255;
bool OnAllEsp;
static float AutoStealBuff = 0;
//static float AutoStealTurtle= 2002;
//static float AutoStealLord= 2003;
static float DistCombo = 5.0f;


void DrawCircleHealth(ImVec2 position, int health, int max_health, float radius) {
    float a_max = ((3.14159265359f * 2.0f));
    ImU32 healthColor = IM_COL32(45, 180, 45, 255);
    if (health <= (max_health * 0.6)) {
        healthColor = IM_COL32(180, 180, 45, 255);
    }
    if (health < (max_health * 0.3)) {
        healthColor = IM_COL32(180, 45, 45, 255);
    }
    ImGui::GetForegroundDrawList()->PathArcTo(position, radius, (-(a_max / 4.0f)) + (a_max / max_health) * (max_health - health), a_max - (a_max / 4.0f));
    ImGui::GetForegroundDrawList()->PathStroke(healthColor, ImDrawFlags_None, 4);
}

static float SetFieldOfView = 0, GetFieldOfView = 0;

void DroneView() {
    if (GetFieldOfView == 0) {
        GetFieldOfView = get_fieldOfView();
    }
    if (SetFieldOfView > 0 && GetFieldOfView != 0) {
        set_fieldOfView((float)GetFieldOfView + SetFieldOfView);
    }
    if (SetFieldOfView == 0 && GetFieldOfView != 0) {
        set_fieldOfView((float)GetFieldOfView);
    }
}

void (*s_Jungle2)(void *instance, int Jungle);
void s_Jungle(void *instance, int Jungle) {
    if (instance != nullptr) {
        if (showjungle) {
			return;
		}
    }
     s_Jungle2(instance, Jungle);
}

bool (*s_Emblem2)(void* _this);
bool s_Emblem(void* _this) {
    if (Config.Visual.UnlockEmblem) {
        return true;
    }
    return s_Emblem2(_this);
}

void (*s_Spell2)(void *instance, int Spelll);
void s_Spell(void *instance, int Spelll) {
    if (instance != nullptr) {
        if (Config.Visual.UnlockSpell) {
			return;
		}
    }
     s_Spell2(instance, Spelll);
}

int (*old_FrameRate)(void *instance);
int Frame_Rate(void *instance) {
 if (instance != NULL && FrameRate > 1) {
     return (int) FrameRate;
   } 
  return old_FrameRate(instance);
}

//MapHack With Hook Update (No FC/Lag) -> Fix Blink By Razor
#define DefineHook(RET, NAME, ARGS) \
    RET (*o ## NAME) ARGS; \
    RET NAME ARGS


DefineHook(void, UpdateMapHack, (void * pThis)) {
    oUpdateMapHack(pThis);
    
    if (pThis != NULL && Config.Visual.MaphackIcon || pThis != NULL && Config.Visual.HealthBar) {
        void *BattleBridge_Instance, *BattleManager_Instance;
        Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleData", "m_BattleBridge", &BattleBridge_Instance);
        
        if (BattleBridge_Instance) {
            Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &BattleManager_Instance);
            if (BattleManager_Instance) {
                monoList<void **> *m_ShowPlayers = *(monoList<void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_ShowPlayers);
                if (m_ShowPlayers) {
                    for (int i = 0; i < m_ShowPlayers->getSize(); i++) {
                        auto Pawn = m_ShowPlayers->getItems()[i];               
                        if (!Pawn) continue;
                        auto m_bSameCampType = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bSameCampType);
                        if (m_bSameCampType) continue;
                        auto m_bDeath = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bDeath);
                        auto m_IsDeathProgress = *(bool *) ((uintptr_t)Pawn + EntityBase_m_IsDeathProgress);                        
                        if (m_bDeath || m_IsDeathProgress) continue;
                        auto canSight = *(bool *) ((uintptr_t)Pawn + EntityBase_canSight);
                        if (canSight) continue;
                        auto m_uGuid = *(int *) ((uintptr_t)Pawn + EntityBase_m_uGuid);
                        auto _Position = *(Vector3 *) ((uintptr_t)Pawn + ShowEntity__Position);
						if (Config.Visual.MaphackIcon) {
                            auto SetMapEntityIconPos = (void (*)(void *, Vector3, int, bool)) (BattleBridge_SetMapEntityIconPos);
                            auto SetMapInvisibility = (void (*)(void *, int, bool, bool)) (BattleBridge_SetMapInvisibility);                            
                            auto ShowEntity_UpdateEyeLayer = (void (*)(void *, bool, bool)) (ShowEntityUpdateEyeLayer);        
                            SetMapInvisibility(BattleBridge_Instance, m_uGuid, true, m_bDeath);
                            SetMapEntityIconPos(BattleBridge_Instance, _Position, m_uGuid, true);
                            //ShowEntity_UpdateEyeLayer(BattleBridge_Instance, true, false);
							//isPlayer(BattleManager, m_uGuid, true, m_bDeath);
						}
						if (Config.Visual.HealthBar) {
							auto SetBloodInvisibility = (void (*)(void *, int, bool, bool, bool)) (BattleBridge_SetBloodInvisibility);
                            auto SynBloodAttr = (void (*)(void *, void *, bool)) (BattleBridge_SynBloodAttr);
                            auto UpdateBloodPos = (void (*)(void *, void *, bool)) (BattleBridge_UpdateBloodPos);
                            
							SetBloodInvisibility(BattleBridge_Instance, m_uGuid, true, m_bDeath, true);
                            SynBloodAttr(BattleBridge_Instance, Pawn, true);
                            UpdateBloodPos(BattleBridge_Instance, Pawn, true);
						}
                    }
                }
            }
        }
    }
   // @Razor Ganteng
}


//Draw ESP
void drawESP__Player(ImDrawList *draw) {
    void *BattleBridge_Instance, *BattleManager_Instance, *LogicBattleManager_Instance;
    Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleData", "m_BattleBridge", &BattleBridge_Instance);
    if (BattleBridge_Instance) {
        auto _bStartBattle = *(bool *) ((uintptr_t)BattleBridge_Instance + BattleBridge_bStartBattle);
        if (_bStartBattle) {
            DroneView();
            Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &BattleManager_Instance);
            if (BattleManager_Instance) {
                auto m_LocalPlayerShow = *(uintptr_t *) ((uintptr_t)BattleManager_Instance + BattleManager_m_LocalPlayerShow);
                if (m_LocalPlayerShow) {
                    auto selfPos = *(Vector3 *) ((uintptr_t)m_LocalPlayerShow + ShowEntity__Position);
                    if (selfPos != Vector3::zero()) {
                        auto SelfPosW2S = WorldToScreen(selfPos);
                        auto SelfPosVec2 = ImVec2(s_Width - SelfPosW2S.x, SelfPosW2S.y);
                        if (SelfPosW2S.z > 0) {
                            SelfPosVec2 = ImVec2(SelfPosW2S.x, s_Height - SelfPosW2S.y);
                        }
                        monoList<void **> *m_ShowPlayers = *(monoList<void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_ShowPlayers);
                        if (m_ShowPlayers) {
                            for (int i = 0; i < m_ShowPlayers->getSize(); i++) {
                                auto Pawn = m_ShowPlayers->getItems()[i];
                                if (!Pawn) continue;
                                auto m_bSameCampType = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bSameCampType);
                                if (m_bSameCampType) continue;
                                auto m_bDeath = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bDeath);
                                if (m_bDeath) continue;
                                auto canSight = *(bool *) ((uintptr_t)Pawn + EntityBase_canSight);
                                auto CurHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_Hp);
                                auto MaxHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_HpMax);
                                auto _Position = *(Vector3 *) ((uintptr_t)Pawn + ShowEntity__Position);

                                auto *m_RoleName = *(MonoString **) ((uintptr_t)Pawn + ShowEntity_m_RoleName);
                                auto *m_HeroName = *(MonoString **) ((uintptr_t)Pawn + ShowPlayer_m_HeroName);

                                auto HeroID = *(int *) ((uintptr_t)Pawn + EntityBase_m_ID);

                                int Distance = (int) Vector3::Distance(selfPos, _Position);
                                auto RootPosW2S = WorldToScreen(_Position);
                                auto RootPosVec2 = Vector2(s_Width - RootPosW2S.x, RootPosW2S.y);
                                if (RootPosW2S.z > 0) {
                                    RootPosVec2 = Vector2(RootPosW2S.x, s_Height - RootPosW2S.y);
                                }
                                auto HeadPosVec2 = Vector2(RootPosVec2.x, RootPosVec2.y - (s_Height / 10.35));

                                if (Config.ESP.Player.Visible) {
                                    if (canSight && !isOutsideScreen(ImVec2(RootPosVec2.x, RootPosVec2.y), ImVec2(s_Width, s_Height)))
                                        continue;
                                }
                                if (Config.ESP.Player.Line || OnAllEsp) {
                                    draw->AddLine(SelfPosVec2, ImVec2(RootPosVec2.x, RootPosVec2.y), IM_COL32(RedLine, GreenLine, BlueLine, 255), 1.7f);
									draw->AddCircleFilled(ImVec2(SelfPosVec2.x, SelfPosVec2.y), 5, IM_COL32(255, 0, 0, 255), 0);
                    	            draw->AddCircleFilled(ImVec2(RootPosVec2.x, RootPosVec2.y), 7, IM_COL32(255, 0, 0, 255), 0);                                                        
                                }
								if  (/*@sjwmod*/Config.ESP.Player.Radar) {
									
                                bool out = false;
                                struct Vector3 Pos;
                                Pos.x = s_Width / 4.395;
                                Pos.y = s_Height / 200;
                                struct Vector3 Size;
                                Size.x = 200; //Width of Radar Box.
                                Size.y = 210; //Height of Radar Box.
                                float RadarCenterX = Pos.x +  (/*@sjwmod*/Size.x / 2 /*@sjwmod*/);
                                float RadarCenterY = Pos.y +  (/*@sjwmod*/Size.y / 2 /*@sjwmod*/);
                                ImColor CircleColor = ImColor (/*@sjwmod*/0, 0, 0, 20 /*@sjwmod*/);
                                ImColor PointColor = ImColor (/*@sjwmod*/255, 0, 0, 25 /*@sjwmod*/);
                                draw ->/*join @sjwmod*/AddLine (/*@sjwmod*/ImVec2 (/*@sjwmod*/RadarCenterX, RadarCenterY /*@sjwmod*/),
                                              ImVec2 (/*@sjwmod*/SelfPosVec2.x, Pos.y /*@sjwmod*/),
                                              ImColor (/*@sjwmod*/Config.ESP.Player.Box /*@sjwmod*/), 1.f /*@sjwmod*/);
                                draw ->/*join @sjwmod*/AddLine (/*@sjwmod*/ImVec2 (/*@sjwmod*/RadarCenterX, RadarCenterY /*@sjwmod*/),
                                              ImVec2 (/*@sjwmod*/SelfPosVec2.x, RootPosVec2.y /*@sjwmod*/),
                                              ImColor (/*@sjwmod*/Config.ESP.Player.Box /*@sjwmod*/), 1.f /*@sjwmod*/);
                                draw ->/*join @sjwmod*/AddLine (/*@sjwmod*/ImVec2 (/*@sjwmod*/Pos.x, RadarCenterY /*@sjwmod*/),
                                              ImVec2 (/*@sjwmod*/Pos.x + Size.x, RootPosVec2.y /*@sjwmod*/),
                                              ImColor (/*@sjwmod*/Config.ESP.Player.Box /*@sjwmod*/), 1.f /*@sjwmod*/);
                                draw ->/*join @sjwmod*/AddLine (/*@sjwmod*/ImVec2 (/*@sjwmod*/RootPosVec2.x, SelfPosVec2.y /*@sjwmod*/),
                                              ImVec2 (/*@sjwmod*/Pos.x + Size.x, RootPosVec2.y /*@sjwmod*/),
                                              ImColor (/*@sjwmod*/Config.ESP.Player.Box /*@sjwmod*/), 1.f /*@sjwmod*/);

                                draw ->/*join @sjwmod*/AddCircleFilled (/*@sjwmod*/ImVec2 (/*@sjwmod*/RadarCenterX, RadarCenterY /*@sjwmod*/), 100.f,
                                                      CircleColor, 1000 /*@sjwmod*/); //Background
                                draw ->/*join @sjwmod*/AddCircle (/*@sjwmod*/ImVec2 (/*@sjwmod*/RadarCenterX, RadarCenterY /*@sjwmod*/), 100.f,
                                                PointColor, 1000 /*@sjwmod*/); // Circle Around Background
                                draw ->/*join @sjwmod*/AddCircleFilled (/*@sjwmod*/
                                        ImVec2 (/*@sjwmod*/RadarCenterX + 0.5f, RadarCenterY + 0.5f /*@sjwmod*/), 3.f,
                                        PointColor, 1000 /*@sjwmod*/); // Center of Cross Ci

                            }
                                if (Config.ESP.Player.Box || OnAllEsp) {
                                    float boxHeight = abs(HeadPosVec2.y - RootPosVec2.y);
                                    float boxWidth = boxHeight * 0.75f;
                                    ImVec2 vStart = {HeadPosVec2.x - (boxWidth / 2), HeadPosVec2.y};
                                    ImVec2 vEnd = {vStart.x + boxWidth, vStart.y + boxHeight};
                                    draw->AddRect(vStart, vEnd, IM_COL32(RedLine, GreenLine, BlueLine, 255), 0, 140, 1.7f);
                                }
                                if (Config.ESP.Player.Health || OnAllEsp) {
                                    float boxHeight = abs(HeadPosVec2.y - RootPosVec2.y);
                                    float boxWidth = boxHeight * 0.75f;
                                    float PercentHP = ((float)CurHP * boxHeight) / (float)MaxHP;
                                    draw->AddRectFilled(ImVec2(RootPosVec2.x + (boxWidth / 2) + 5, RootPosVec2.y), ImVec2(RootPosVec2.x + (boxWidth / 2) + 25, RootPosVec2.y - PercentHP), IM_COL32(255, 100, 0, 255));
                                    draw->AddRect(ImVec2(RootPosVec2.x + (boxWidth / 2) + 5, RootPosVec2.y), ImVec2(RootPosVec2.x + (boxWidth / 2) + 25, HeadPosVec2.y), IM_COL32(255, 255, 255, 255), 0, 240, 0.5);
                                }
                                if (Config.ESP.Player.Name || Config.ESP.Player.Hero || OnAllEsp) {
                                    if (Config.ESP.Player.Name || OnAllEsp && Config.ESP.Player.Hero || OnAllEsp) {
                                        if (m_RoleName && m_HeroName) {
                                            std::string strName = "[" + m_HeroName->toString() + "] " + m_RoleName->toString();
                                            auto textSize = ImGui::CalcTextSize2(strName.c_str(), 0, ((float) s_Height / 39.0f));
                                            draw->AddText(NULL, ((float) s_Height / 39.0f), {RootPosVec2.x - (textSize.x / 2), RootPosVec2.y + 25}, IM_COL32(255, 255, 255, 255), strName.c_str());
                                        }
										
                                    } else if (Config.ESP.Player.Name || OnAllEsp) {
                                        if (m_RoleName) {
                                            std::string strName = m_RoleName->toString();
                                            auto textSize = ImGui::CalcTextSize2(strName.c_str(), 0, ((float) s_Height / 39.0f));
                                            draw->AddText(NULL, ((float) s_Height / 39.0f), {RootPosVec2.x - (textSize.x / 2), RootPosVec2.y + 25}, IM_COL32(255, 255, 255, 255), strName.c_str());
                                        }
                                    } else if (Config.ESP.Player.Hero || OnAllEsp) {
                                        if (m_HeroName) {
                                            std::string strName = "[" + m_HeroName->toString() + "]";
                                            auto textSize = ImGui::CalcTextSize2(strName.c_str(), 0, ((float) s_Height / 39.0f));
                                            draw->AddText(NULL, ((float) s_Height / 39.0f), {RootPosVec2.x - (textSize.x / 2), RootPosVec2.y + 25}, IM_COL32(255, 255, 255, 255), strName.c_str());
                                        }
                                    }
                                }
                                if (Config.ESP.Player.Distance || OnAllEsp) {
                                    std::string strDistance = to_string(Distance) + " M";
                                    auto textSize = ImGui::CalcTextSize2(strDistance.c_str(), 0, ((float) s_Height / 39.0f));
                                    draw->AddText(NULL, ((float) s_Height / 39.0f), {RootPosVec2.x - (textSize.x / 2), RootPosVec2.y + 5}, IM_COL32(255, 2550, 255, 255), strDistance.c_str());
                                }
                                if (Config.ESP.Player.CoolDown) {				                                													   
						        uint32_t cd[8] {0};
								void *Instance;
		                        Il2CppGetStaticFieldValue(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("LogicBattleManager"), OBFUSCATE("Instance"), &Instance);
		                        if (Instance != nullptr) {
                                auto m_dicPlayerLogic = *(Dictionary<uint32_t, void *> **)((uintptr_t)Instance + LogicBattleManager_m_dicPlayerLogic);
                                if (m_dicPlayerLogic == NULL) return;          
                                int playerCount = m_dicPlayerLogic->getSize();                                                       
                                auto Values = m_dicPlayerLogic->getValues();
                                for (int u = 0; u < std::min(10, playerCount); u++) {
                                auto Pawn2 = Values[u];								                            						                                                                      
                                        auto m_SkillComp = *(uintptr_t *) ((uintptr_t)Pawn2 + LogicFighter_m_SkillComp);
                                        if (m_SkillComp) {
                                            auto m_CoolDownComp = *(uintptr_t *) ((uintptr_t)m_SkillComp + LogicSkillComp_m_CoolDownComp);
                                            if (m_CoolDownComp) {
                                                Dictionary<int, uintptr_t> *m_DicCoolInfo = *(Dictionary<int, uintptr_t> **) ((uintptr_t)m_CoolDownComp + CoolDownComp_m_DicCoolInfo);
                                                if (m_DicCoolInfo) {
                                                    for (int j = 0; j < m_DicCoolInfo->getNumKeys(); j++) {
                                                        auto keys = m_DicCoolInfo->getKeys()[j];
                                                        auto values = m_DicCoolInfo->getValues()[j];
                                                        if (keys && values) {													                                                      
                                                            int skillIdx = -1;
                                                            //Spell
                                                            if (SpellIdExist(keys == HeroID)) {
                                                                skillIdx = 4;
                                                            }                                                         
                                                            //Skill 1
                                                            else if (keys == 100 * HeroID + 10 || keys == 2010510) {
                                                                skillIdx = 0;
                                                            }
                                                            //Skill 2
                                                            else if (keys == 100 * HeroID + 20 || keys == 2010520) {
                                                                skillIdx = 1;
                                                            }
                                                            //Skill 3
                                                            else if (keys == 100 * HeroID + 30 || keys == 2010530) {
                                                                skillIdx = 2;
                                                            }
                                                            //Skill 4
                                                            else if (keys == 100 * HeroID + 40) {
                                                                skillIdx = 3;
                                                            }
                                                            if (skillIdx != -1) {
                                                                uint32_t uiCoolTime = ((uint32_t (*)(uintptr_t)) (CoolDownData_GetCoolTime))(values);
                                                                if (uiCoolTime > 0) {
                                                                    cd[skillIdx] = uiCoolTime / 1000;
                                                                } else {
                                                                    cd[skillIdx] = 0;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                         }
                                      	}}		  
									  if (cd[0] || cd[1] || cd[2] || cd[3] || cd[4]) {
                                        std::string strCooldown;
                                        if (cd[0]) {
                                            strCooldown += "Skill (1): " + to_string(cd[0]);
                                        }
                                        if (cd[1]) {
                                            if (!cd[0]) {
                                                strCooldown += "Skill (2): " + to_string(cd[1]);
                                            } else {
                                                strCooldown += " | Skill (2): " + to_string(cd[1]);
                                            }
                                        }
                                        if (cd[2]) {
                                            if (!cd[0] && !cd[1]) {
                                                strCooldown += "Skill (3): " + to_string(cd[2]);
                                            } else {
                                                strCooldown += " | Skill (3): " + to_string(cd[2]);
                                            }
                                        }
                                        if (cd[3]) {
                                            if (!cd[0] && !cd[1] && !cd[2]) {
                                                strCooldown += "Skill (4): " + to_string(cd[3]);
                                            } else {
                                                strCooldown += " | Skill (4): " + to_string(cd[3]);
                                            }
                                        }
                                        if (cd[4]) {
                                            if (!cd[0] && !cd[1] && !cd[2] && !cd[3]) {
                                                strCooldown += "Spell: " + to_string(cd[4]);
                                            } else {
                                                strCooldown += " | Spell: " + to_string(cd[4]);
                                            }
                                        }
                                        auto textSize = ImGui::CalcTextSize2(strCooldown.c_str(), 0, ((float) s_Height / 39.0f));
                                        draw->AddText(NULL, ((float) s_Height / 39.0f), {RootPosVec2.x - (textSize.x / 2), RootPosVec2.y + 60}, IM_COL32(255, 255, 255, 255), strCooldown.c_str());
                                    }
								 }	
										
                                if (Config.ESP.Player.Alert || OnAllEsp && isOutsideScreen(ImVec2(RootPosVec2.x, RootPosVec2.y), ImVec2(s_Width, s_Height))) {
                                    ImVec2 hintDotRenderPos = pushToScreenBorder(ImVec2(RootPosVec2.x, RootPosVec2.y), ImVec2(s_Width, s_Height), - 50);
                                    ImVec2 hintTextRenderPos = pushToScreenBorder(ImVec2(RootPosVec2.x, RootPosVec2.y), ImVec2(s_Width, s_Height), - 50);
                                    draw->AddCircleFilled(hintDotRenderPos, 25, IM_COL32(255, 100, 100, 110));
                                    DrawCircleHealth(hintDotRenderPos, CurHP, MaxHP, 25);
                                    std::string strDistance = to_string(Distance) + " M";
                                    auto textSize = ImGui::CalcTextSize2(strDistance.c_str(), 0, ((float) s_Height / 45.0f));
                                    draw->AddText(NULL, ((float) s_Height / 45.0f), {hintTextRenderPos.x - (textSize.x / 2), hintTextRenderPos.y - 7}, IM_COL32(255, 255, 255, 255), strDistance.c_str());
                                    if (m_HeroName) {
                                        std::string strName = m_HeroName->toString();
                                        auto textSize = ImGui::CalcTextSize2(strName.c_str(), 0, ((float) s_Height / 39.0f));
                                        draw->AddText(NULL, ((float) s_Height / 39.0f), {hintTextRenderPos.x - (textSize.x / 2), hintTextRenderPos.y + 30}, IM_COL32(255, 255, 100, 255), strName.c_str());
                                    }
                                }
                            }
                        }
                    }

                    monoList<void **> *m_ShowMonsters = *(monoList<void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_ShowMonsters);
                    if (m_ShowMonsters) {
                        for (int i = 0; i < m_ShowMonsters->getSize(); i++) {
                            auto Pawn = m_ShowMonsters->getItems()[i];
                            if (!Pawn) continue;
                            auto m_ID = *(int *) ((uintptr_t)Pawn + EntityBase_m_ID);
                            if (MonsterToString(m_ID) == "") continue;
                            auto m_bSameCampType = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bSameCampType);
                            if (m_bSameCampType) continue;
                            auto m_bDeath = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bDeath);
                            if (m_bDeath) continue;
                            auto CurHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_Hp);
                            auto MaxHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_HpMax);
                            auto _Position = *(Vector3 *) ((uintptr_t)Pawn + ShowEntity__Position);
                            auto RootPosW2S = WorldToScreen(_Position);
                            auto RootPosVec2 = Vector2(s_Width - RootPosW2S.x, RootPosW2S.y);
                            if (RootPosW2S.z > 0) {
                                RootPosVec2 = Vector2(RootPosW2S.x, s_Height - RootPosW2S.y);
                            }
                            auto HeadPosVec2 = Vector2(RootPosVec2.x, RootPosVec2.y - (s_Height / 10.35));
                            if (Config.ESP.Monster.Box || OnAllEsp) {
                                float boxHeight = abs(HeadPosVec2.y - RootPosVec2.y);
                                float boxWidth = boxHeight * 0.75f;
                                ImVec2 vStart = {HeadPosVec2.x - (boxWidth / 2), HeadPosVec2.y};
                                ImVec2 vEnd = {vStart.x + boxWidth, vStart.y + boxHeight};
                                draw->AddRect(vStart, vEnd, IM_COL32(RedLine, GreenLine, BlueLine, 255), 0, 240, 1.7f);
                            }
                            if (Config.ESP.Monster.Health || OnAllEsp) {
                                float boxHeight = abs(HeadPosVec2.y - RootPosVec2.y);
                                float boxWidth = boxHeight * 0.75f;
                                float PercentHP = ((float)CurHP * boxHeight) / (float)MaxHP;
                                draw->AddRectFilled(ImVec2(RootPosVec2.x + (boxWidth / 2) + 5, RootPosVec2.y), ImVec2(RootPosVec2.x + (boxWidth / 2) + 25, RootPosVec2.y - PercentHP), IM_COL32(0, 180, 0, 180));
                                draw->AddRect(ImVec2(RootPosVec2.x + (boxWidth / 2) + 5, RootPosVec2.y), ImVec2(RootPosVec2.x + (boxWidth / 2) + 25, HeadPosVec2.y), IM_COL32(255, 255, 255, 255), 0, 240, 0.5);
                            }
                            if (Config.ESP.Monster.Name || OnAllEsp) {
                                std::string strName = MonsterToString(m_ID);
                                auto textSize = ImGui::CalcTextSize2(strName.c_str(), 0, ((float) s_Height / 39.0f));
                                draw->AddText(NULL, ((float) s_Height / 39.0f), {RootPosVec2.x - (textSize.x / 2), RootPosVec2.y + 25}, IM_COL32(255, 255, 100, 255), strName.c_str());
                            }
                            if (Config.ESP.Monster.Alert || OnAllEsp) {
                                if (m_ID == 2002 && CurHP < MaxHP) {
                                    std::string strAlert = "ALERT!!! Lord is under attack!";
                                    auto textSize = ImGui::CalcTextSize2(strAlert.c_str(), 0, ((float) s_Height / 31.0f));
                                    draw->AddText(NULL, ((float) s_Height / 31.0f), {(float)(s_Width / 2) - (textSize.x / 2), (float)(s_Height - s_Height) + (float)(s_Height / 8.7f)}, IM_COL32(255, 255, 100, 255), strAlert.c_str());
                                }
                                if (m_ID == 2003 && CurHP < MaxHP) {
                                    std::string strAlert = "ALERT!!! Turtle is under attack!";
                                    auto textSize = ImGui::CalcTextSize2(strAlert.c_str(), 0, ((float) s_Height / 31.0f));
                                    draw->AddText(NULL, ((float) s_Height / 31.0f), {(float)(s_Width / 2) - (textSize.x / 2), (float)(s_Height - s_Height) + (float)(s_Height / 8.7f)}, IM_COL32(255, 255, 100, 255), strAlert.c_str());
								}
                            }
                        }
                    }

                }
            }
        }
    }
}

