#pragma once
#include "Data.h"


#define Transform_get_position (uintptr_t) Il2CppGetMethodOffset("UnityEngine.dll", "UnityEngine", "Transform", "get_position")

class Transform2 {
public:
    Vector3 get_position() {
        auto get_position = (Vector3 (*)(Transform2 *)) (Transform_get_position);
        return get_position(this);
    }
};

//combo
#define BattleManager_m_ShowMonstersdraike (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleManager", "m_ShowMonsters")
#define BattleManager_m_ShowPlayersdraike (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleManager", "m_ShowPlayers")
#define EntityBase_m_bSameCampTypedraike (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "m_bSameCampType")
#define EntityBase_m_bDeathdraike (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "<m_bDeath>k__BackingField")
#define EntityBase_m_Hpdraike (uintptr_t)  Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "m_Hp")
#define EntityBase_m_HpMaxdraike (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "m_HpMax")
#define EntityBase_m_IDdraike (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "m_ID")

//new

#define Bullet_transform (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "Bullet", "transform")
#define EntityBase_m_ID (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "m_ID")
#define ShowEntity__logicFighter (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "_logicFighter")
#define ShowEntity__Position (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "_Position")
#define BattleManager_m_LocalPlayerShow (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleManager", "m_LocalPlayerShow")

struct {
bool Kimmy;
bool WanWan;
bool Iritel;
 }AutoSword;
 




 
float lingSkillControl2;
void Auto_Take_Sword_Ling2(void *unk) {
    
		  auto ShowSelfPlayer_TryUseSkill = (void (*)(void *, int, Vector3, bool, Vector3, bool, bool)) (OffsetFunc_ShowSelfPlayer_TryUseSkill);

        float MaxDist = std::numeric_limits<float>::infinity();
        Vector3 EntityPos = Vector3::zero();
        Vector3 Hp;
        float MaxEnemyHP = std::numeric_limits<float>::infinity();
        void *BattleManager_Instance;
        Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &BattleManager_Instance);
        if (BattleManager_Instance) {
            auto m_LocalPlayerShow = *(uintptr_t *) ((uintptr_t)BattleManager_Instance + BattleManager_m_LocalPlayerShow);
            if (m_LocalPlayerShow) {
                auto selfPos = *(Vector3 *) ((uintptr_t)m_LocalPlayerShow + ShowEntity__Position);
                auto LogicPlayerFighter = *(void **)((long)m_LocalPlayerShow + ShowEntity__logicFighter);  
                auto HeroID = *(int *) ((uintptr_t)m_LocalPlayerShow + EntityBase_m_ID);
                if (selfPos != Vector3::zero()) {
                /////for enemy
                monoList<void **> *m_ShowPlayers = *(monoList<void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_ShowPlayersdraike);
                    if (m_ShowPlayers) {
                        for (int i = 0; i < m_ShowPlayers->getSize(); i++) {
                            auto Pawn = m_ShowPlayers->getItems()[i];
                            if (!Pawn) continue;
                            auto m_bSameCampType = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bSameCampTypedraike);
                            if (m_bSameCampType) continue;
                            auto m_bDeath = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bDeathdraike);
                            if (m_bDeath) continue;
                            auto _Position = *(Vector3 *) ((uintptr_t)Pawn + ShowEntity__Position);
                            float Distance = (int) Vector3::Distance(selfPos, _Position);
                            float CurHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_Hpdraike);
                            					
                            float MaxHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_HpMaxdraike);
                            float PercentHP = CurHP * 100 / MaxHP;
                            
                            monoList<void **> *m_ShowMonsters = *(monoList<void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_ShowMonstersdraike);
                        if (m_ShowMonsters) {
                            for (int j = 0; j < m_ShowMonsters->getSize(); j++) {
                                auto Pawnio = m_ShowMonsters->getItems()[j];
                                if (!Pawnio) continue;
                                auto m_ID = *(int *) ((uintptr_t)Pawnio + EntityBase_m_ID);
                                if (MonsterToString(m_ID) == "") continue;
                                auto m_bSameCampType = *(bool *) ((uintptr_t)Pawnio + EntityBase_m_bSameCampTypedraike);
                                if (m_bSameCampType) continue;
                                auto m_bDeath = *(bool *) ((uintptr_t)Pawnio + EntityBase_m_bDeathdraike);
                                if (m_bDeath) continue;
                                auto _Position1 = *(Vector3 *) ((uintptr_t)Pawnio + ShowEntity__Position);
                                float Distance1 = (int) Vector3::Distance(selfPos, _Position1);
                                float CurHP1 = *(int *) ((uintptr_t)Pawnio + EntityBase_m_Hpdraike);
                                float MaxHP1 = *(int *) ((uintptr_t)Pawnio + EntityBase_m_HpMaxdraike);
                                float PercentHP1 = CurHP1 * 100 / MaxHP1;
                        
                
                
 
	  
		//Kimmy	
		if (AutoSword.Kimmy) {         
        if (_Position != Vector3::zero() && Distance < 6.5f) {  
        ShowSelfPlayer_TryUseSkill(unk, 7113, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);       
        lingSkillControl2 = 0;}
        
        else if (_Position1 != Vector3::zero() && Distance1 < 6.5f) { 
        ShowSelfPlayer_TryUseSkill(unk, 7110, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);  
        lingSkillControl2 = 0;}
         }

        if (AutoSword.WanWan) {
        if (_Position1 != Vector3::zero() && Distance1 < 6.5f) {
		ShowSelfPlayer_TryUseSkill(unk, 8900, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);		   	 
        lingSkillControl2 = 0;}
	    else if (_Position != Vector3::zero() && Distance < 6.5f) {
		ShowSelfPlayer_TryUseSkill(unk, 8900, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);		
        ShowSelfPlayer_TryUseSkill(unk, 8910, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);		
        lingSkillControl2 = 0;}
	    }
	        
	    //Irithel
		if (AutoSword.Iritel) {
        if (_Position != Vector3::zero() && Distance < 6.5f) {
		ShowSelfPlayer_TryUseSkill(unk, 4300, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);		   	 
        lingSkillControl2 = 0;}
	    else if (_Position1 != Vector3::zero() && Distance1 < 6.5f) {
		ShowSelfPlayer_TryUseSkill(unk, 4300, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);		
        lingSkillControl2 = 0;}
		if (PercentHP <= 50 && Distance < 6.5f && _Position != Vector3::zero()){         
		ShowSelfPlayer_TryUseSkill(unk, 4310, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
       lingSkillControl2 = 0;  
		ShowSelfPlayer_TryUseSkill(unk, 4320, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
        lingSkillControl2 = 0;  
        ShowSelfPlayer_TryUseSkill(unk, 4330, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
        lingSkillControl2 = 0;
	    }} 
       			
}}}}}}}}

DefineHook(void, ShowSelfPlayer_OnUpdate2, (void * unk)) {
    if (unk != NULL){
	if (AutoSword.Kimmy || AutoSword.WanWan || AutoSword.Iritel){
   
        lingSkillControl2++;
        if (lingSkillControl2 > 15) {
            Auto_Take_Sword_Ling2(unk);
        }

    }
    }
    return oShowSelfPlayer_OnUpdate2(unk);
}

void Auto_Skill() {

   
    OffsetFunc_ShowSelfPlayer_TryUseSkill = (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("ShowSelfPlayer"), OBFUSCATE("TryUseSkill"), 7);
    DobbyHook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("ShowSelfPlayer"), OBFUSCATE("OnUpdate")), (void *) ShowSelfPlayer_OnUpdate2, (void **) &oShowSelfPlayer_OnUpdate2);

}

