#pragma once

struct sAim {
    struct sHelper {
		int TargetPriority = 0;
        struct sSkills {
			
            bool Basic;
            bool Spell;
            bool Skill1;
            bool Skill2;
            bool Skill3;
            bool Skill4;
        };
        sSkills Skills{0};

        struct sPriority {
            
            bool AutoTakeSword;
        };
        sPriority Priority{0};
        
        struct sAutoRetribution {
            bool Buff;
			bool All;
            bool Turtle;
            bool Lord;
            bool Crab;
            bool Lito;
			bool Trigger;
			bool Kontol;
            bool Buff2;
			bool Rockursa;
			bool Scaled;
			bool Scaled2;
			bool Rockursa2;
            bool Turtle2;
            bool Lord2;
            bool Crab2;
            bool Lito2;
            bool ling;
        };
        sAutoRetribution AutoRetribution{0};
        
    };
    sHelper Helper{0};
};
sAim Aim{0};

enum ETargetPriority {
	 Dist = 0,
	 
     LowHP = 1,
	 LowHPPercent = 2,
    };
	
bool Bypass;
bool AutoSpell;
bool Pharsa;
bool AutoSteall;
bool Argus2;
bool BlockBanned;
bool BlockReport;
bool AutoSteallB;
bool AutoSteallA;
bool Flameshot;
bool AutoSteallP;
bool ServerBypass;
bool AutoCombo;
bool StuckGoblok;
bool AutoOn;
bool AutoSteallTrigger;
bool AutoOff;
bool Goblok;
bool Sprint;
bool DropFPS;
bool Aegis;
bool Vengeance;
bool ComboSkill;
bool Fliker;
bool Revitalize;
bool Execute;
bool FlameShot;
bool AutoLing;
bool AutoSwordKimmy;
bool DropJaringan;
bool isHighFPS;
bool isSetFPS;
bool damage;
static float RangeFOV = 10.0f;

static float speedAtt = -1.0f;

/*float lingSkillControl2;
void Auto_Take_Sword_Ling2(void *unk) {
	auto ShowSelfPlayer_TryUseSkill = (void (*)(void *, int skillId, Vector3 dir, bool dirDefault, Vector3, bool, bool)) (OffsetFunc_ShowSelfPlayer_TryUseSkill);
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
				monoList<void **> *m_ShowPlayers = *(monoList<void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_ShowPlayers);
				auto m_Level = *(int *) ((uintptr_t)m_LocalPlayerShow + EntityBase_m_Level);
                auto _logicFighter = *(uintptr_t *) ((uintptr_t)m_LocalPlayerShow + ShowEntity__logicFighter);
                auto mLevel = *(int *) ((uintptr_t)m_LocalPlayerShow + EntityBase_m_Level);
                auto logicFighter = *(uintptr_t *) ((uintptr_t)m_LocalPlayerShow + ShowEntity__logicFighter);
                int iCalculateDamage;
                if (logicFighter) {
					auto mKillWildTimes = *(int *) ((uintptr_t)logicFighter + LogicPlayer_m_KillWildTimes);
					iCalculateDamage = CalculateRetriDamage(mLevel, mKillWildTimes);
                }
                        
						int iCalcRetribution;
						if (logicFighter) {
							auto mKillWildTimes = *(int *) ((uintptr_t)logicFighter + LogicPlayer_m_KillWildTimes);
							iCalcRetribution = CalcRetribution(mLevel, mKillWildTimes);
						}
						
                        if (_logicFighter) {
                            auto m_KillWildTimes = *(int *) ((uintptr_t)_logicFighter + LogicPlayer_m_KillWildTimes);
                            int AddRetriDmg = (m_KillWildTimes>4) ? 380 + ((m_Level-3)*40) : 0;
                            Aim.Helper.AutoRetribution.iCalculateDamage = 520 + (80 * m_Level) + AddRetriDmg;
                        }
                if (m_ShowPlayers) {
					for (int i = 0; i < m_ShowPlayers->getSize(); i++) {
						auto Pawn = m_ShowPlayers->getItems()[i];
                        if (!Pawn) continue;
                        auto m_bSameCampType = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bSameCampType);
                        if (m_bSameCampType) continue;
                        auto m_bDeath = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bDeath);
                        if (m_bDeath) continue;
						auto m_IsDeathProgress = *(bool *) ((uintptr_t)Pawn + EntityBase_m_IsDeathProgress);
                        if (m_IsDeathProgress) continue;
                        auto _Position = *(Vector3 *) ((uintptr_t)Pawn + ShowEntity__Position);
                        float Distance = (int) Vector3::Distance(selfPos, _Position);
                        float CurHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_Hp);       					
                        float MaxHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_HpMax);
                        float PercentHP = CurHP * 100 / MaxHP;
						
						monoList<void **> *m_ShowMonsters = *(monoList<void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_ShowMonsters);
                        if (m_ShowMonsters) {
							for (int j = 0; j < m_ShowMonsters->getSize(); j++) {
								auto Pawnio = m_ShowMonsters->getItems()[j];
                                if (!Pawnio) continue;
                                auto m_ID = *(int *) ((uintptr_t)Pawnio + EntityBase_m_ID);
                                if (MonsterToString(m_ID) == "") continue;
                                auto m_bSameCampType = *(bool *) ((uintptr_t)Pawnio + EntityBase_m_bSameCampType);
                                if (m_bSameCampType) continue;
                                auto m_bDeath = *(bool *) ((uintptr_t)Pawnio + EntityBase_m_bDeath);
                                if (m_bDeath) continue;
								int monsterType = *(int *) ((uintptr_t)Pawnio + EntityBase_m_iType);
                                auto _Position1 = *(Vector3 *) ((uintptr_t)Pawnio + ShowEntity__Position);
                                float Distance1 = (int) Vector3::Distance(selfPos, _Position1);
                                float CurHP1 = *(int *) ((uintptr_t)Pawnio + EntityBase_m_Hp);
                                float MaxHP1 = *(int *) ((uintptr_t)Pawnio + EntityBase_m_HpMax);
                                float PercentHP1 = CurHP1 * 100 / MaxHP1;
								
								if (Aim.AutoSkills.KimmyV2) {
									auto skillUser0 = 100 * HeroID + 00;
									auto skillUser1 = 100 * HeroID + 10;
									auto skillUser2 = 100 * HeroID + 20;
									auto skillUser3 = 100 * HeroID + 30;
									if ((monsterType == 1 || monsterType == 1)) {
		                                    ShowSelfPlayer_TryUseSkill(unk, skillUser0, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
									    	lingSkillControl2 = speedAtt;
									}
                                    if (_Position != Vector3::zero() && Distance < RangeCombo) {
		                                ShowSelfPlayer_TryUseSkill(unk, skillUser0, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
										lingSkillControl2 = speedAtt;
									}
	                                 else if (_Position1 != Vector3::zero() && Distance1 < RangeCombo) {
		                                 ShowSelfPlayer_TryUseSkill(unk, skillUser0, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
										 lingSkillControl2 = speedAtt;
									}
		                             if (PercentHP <= TargetHPPer && Distance < 10.0f && _Position != Vector3::zero()) {
                                         ShowSelfPlayer_TryUseSkill(unk, skillUser3, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
                                         lingSkillControl2 = speedAtt;
	                                }
								}
							}
						}
					}
				}
			}
		}
	}
}

DefineHook(void, ShowSelfPlayer_OnUpdate2, (void * unk)) {
    if (unk != NULL){
	    if ( Aim.AutoSkills.KimmyV2) {
            lingSkillControl2++;
            if (lingSkillControl2 > 5) {
                Auto_Take_Sword_Ling2(unk);
            }
        }
    }
    return oShowSelfPlayer_OnUpdate2(unk);
}*/

void (*orig_TryUseSkill)(...);
void TryUseSkill(void *instance, int skillId, Vector3 dir, bool dirDefault, Vector3 pos, bool bCommonAtk, bool bAuto, bool bAlong, bool bCache) {
    bool isDoneAim = false;
    if (instance != NULL) {
        float MaxDist = std::numeric_limits<float>::infinity();
        float MaxEnemyHP = std::numeric_limits<float>::infinity();
        float MaxPercentHP = std::numeric_limits<float>::infinity();
        float MaxSwordDist = std::numeric_limits<float>::infinity();
        Vector3 EntityPos = Vector3::zero();
        Vector3 SwordPos = Vector3::zero();

        void *BattleManager_Instance;
        Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &BattleManager_Instance);
        if (BattleManager_Instance) {
            auto m_LocalPlayerShow = *(uintptr_t *) ((uintptr_t)BattleManager_Instance + BattleManager_m_LocalPlayerShow);
            if (m_LocalPlayerShow) {
                auto selfPos = *(Vector3 *) ((uintptr_t)m_LocalPlayerShow + ShowEntity__Position);
                auto HeroID = *(int *) ((uintptr_t)m_LocalPlayerShow + EntityBase_m_ID);
                if (selfPos != Vector3::zero()) {
                    monoList<void **> *m_ShowPlayers = *(monoList<void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_ShowPlayers);
                    if (m_ShowPlayers) {
                        for (int i = 0; i < m_ShowPlayers->getSize(); i++) {
                            auto Pawn = m_ShowPlayers->getItems()[i];
                            if (!Pawn) continue;
                            auto m_bSameCampType = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bSameCampType);
                            if (m_bSameCampType) continue;
                            auto m_bFakeDeath = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bDeath);
                            if (m_bFakeDeath) continue;
                            auto _Position = *(Vector3 *) ((uintptr_t)Pawn + ShowEntity__Position);
							auto EnHeroID = *(int *) ((uintptr_t)Pawn + EntityBase_m_ID);          
                            float Distance = (int) Vector3::Distance(selfPos, _Position);
                            float CurHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_Hp);
                            float MaxHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_HpMax);
						    int m_Level3 = *(int *) ((uintptr_t)Pawn + EntityBase_m_Level); 
                            float PercentHP = CurHP * 100 / MaxHP;
                            if (Distance < RangeFOV) {
                                if (Aim.Helper.TargetPriority == ETargetPriority::Dist && Distance < MaxDist) {
                                    EntityPos = _Position;
                                    MaxDist = Distance;
                                }
								
                                if (Aim.Helper.TargetPriority == ETargetPriority::LowHP && CurHP < MaxEnemyHP) {
                                    EntityPos = _Position;
                                    MaxEnemyHP = CurHP;
                                }
								
                                if (Aim.Helper.TargetPriority == ETargetPriority::LowHPPercent && PercentHP < MaxPercentHP) {
                                    EntityPos = _Position;
                                    MaxPercentHP = PercentHP;
                                }
                            }
											  				   
					     if (Distance < DistCombo && skillId == 11520 && Config.Visual.ComboXavier21) {
                            if (Vector3::Normalized(EntityPos - selfPos) != Vector3::zero() && HeroID) { 								
							orig_TryUseSkill(instance, 100 * 115 + 10, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
							}}
							
						if (Config.Visual.ComboGS || AutoCombo){	
						if (Distance < 10 && skillId == 100 * 56 + 00){
						   	orig_TryUseSkill(instance, 100 * 56 + 20, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);						
							isDoneAim = true;												
							orig_TryUseSkill(instance, 100 * 56 + 30, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache); 
							}
						if (Distance < 3){
							orig_TryUseSkill(instance, 100 * 56 + 20, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);						
							orig_TryUseSkill(instance, 100 * 56 + 10, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache); 							
						   }}
							
						if (Distance < DistCombo && 100 * HeroID + 10 && 100 * HeroID + 20 && 100 * HeroID + 30 && Config.Visual.ComboSkill1 || ComboSkill) {
                            if (Vector3::Normalized(EntityPos - selfPos) != Vector3::zero() && HeroID) { 								
							orig_TryUseSkill(instance, 100 * HeroID + 10, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
							}}
						if (Distance < DistCombo && 100 * HeroID + 10 && 100 * HeroID + 20 && Config.Visual.ComboSkill2 || ComboSkill) {
                            if (Vector3::Normalized(EntityPos - selfPos) != Vector3::zero() && HeroID) { 						
							orig_TryUseSkill(instance, 100 * HeroID + 20, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
							}}
						if (Distance < DistCombo && 100 * HeroID + 10 && 100 * HeroID + 20 && Config.Visual.ComboSkill3 || ComboSkill) {
                            if (Vector3::Normalized(EntityPos - selfPos) != Vector3::zero() && HeroID) { 							
						    orig_TryUseSkill(instance, 100 * HeroID + 30, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
					         }}	
						if (Distance < DistCombo && 100 * HeroID + 10 && 100 * HeroID + 20 && Config.Visual.ComboSkill4 || ComboSkill) {
                            if (Vector3::Normalized(EntityPos - selfPos) != Vector3::zero() && HeroID) { 							
						    orig_TryUseSkill(instance, 100 * HeroID + 40, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
					        }}
							
						if (Distance < DistCombo && 100 * HeroID + 10 && 100 * HeroID + 20 && 100 * HeroID + 20 && Config.Visual.ComboSkill21) {
                            if (Vector3::Normalized(EntityPos - selfPos) != Vector3::zero() && HeroID) { 								
							orig_TryUseSkill(instance, 100 * HeroID + 20, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
							orig_TryUseSkill(instance, 100 * HeroID + 10, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);					
							}}
						if (Distance < DistCombo && 100 * HeroID + 10 && 100 * HeroID + 20 && Config.Visual.ComboSkill31 || ComboSkill) {
                            if (Vector3::Normalized(EntityPos - selfPos) != Vector3::zero() && HeroID) { 						
							orig_TryUseSkill(instance, 100 * HeroID + 30, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
							orig_TryUseSkill(instance, 100 * HeroID + 10, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);					
							}}
						if (Distance < DistCombo && 100 * HeroID + 10 && 100 * HeroID + 20 && Config.Visual.ComboSkill32 || ComboSkill) {
                            if (Vector3::Normalized(EntityPos - selfPos) != Vector3::zero() && HeroID) { 							
						    orig_TryUseSkill(instance, 100 * HeroID + 30, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
							orig_TryUseSkill(instance, 100 * HeroID + 20, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);					
					         }}	
						if (Distance < DistCombo && 100 * HeroID + 10 && 100 * HeroID + 20 && Config.Visual.ComboSkill321 || ComboSkill) {
                            if (Vector3::Normalized(EntityPos - selfPos) != Vector3::zero() && HeroID) { 							
						    orig_TryUseSkill(instance, 100 * HeroID + 30, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
							orig_TryUseSkill(instance, 100 * HeroID + 20, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
						    orig_TryUseSkill(instance, 100 * HeroID + 10, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);					
					        }}
						if (Distance < DistCombo && 100 * HeroID + 30 && Config.Visual.Skill1Flicker || ComboSkill) {
                            if (Vector3::Normalized(EntityPos - selfPos) != Vector3::zero() && HeroID) { 							
						    orig_TryUseSkill(instance, 20100, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
							orig_TryUseSkill(instance, 100 * HeroID + 10, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);						
					         }}		
						if (Distance < DistCombo && 100 * HeroID + 30 && Config.Visual.Skill2Flicker || ComboSkill) {
                            if (Vector3::Normalized(EntityPos - selfPos) != Vector3::zero() && HeroID) { 							
						    orig_TryUseSkill(instance, 20100, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
							orig_TryUseSkill(instance, 100 * HeroID + 20, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);						
					         }}		
						if (Distance < DistCombo && 100 * HeroID + 30 && Config.Visual.UltiFlicker || ComboSkill) {
                            if (Vector3::Normalized(EntityPos - selfPos) != Vector3::zero() && HeroID) { 							
						    orig_TryUseSkill(instance, 20100, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
							orig_TryUseSkill(instance, 100 * HeroID + 30, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);						
					         }}		
						if (Distance < DistCombo && 100 * HeroID + 30 && Config.Visual.Skill4Flicker || ComboSkill) {
                            if (Vector3::Normalized(EntityPos - selfPos) != Vector3::zero() && HeroID) { 							
						    orig_TryUseSkill(instance, 20100, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
							orig_TryUseSkill(instance, 100 * HeroID + 40, Vector3::Normalized(EntityPos - selfPos), dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);						
					         }}		
							 
					     if (Config.Visual.Martis || AutoOff) {
                         if (Distance < 5.0f && CurHP < MaxEnemyHP) {
                         if (CurHP <= 1000.0f) {
                         if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                              orig_TryUseSkill(instance, 5830, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                            }}}}
                            
                          if (Config.Visual.Freedrin2 || AutoOff) {
                         if (Distance < 5.0f && CurHP < MaxEnemyHP) {
                         if (CurHP <= 1000.0f) {
                         if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                              orig_TryUseSkill(instance, 11740, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                            }}}}
                          if (Config.Visual.Dyrroth2 || AutoOff) {
                         if (Distance < 5.0f && CurHP < MaxEnemyHP) {
                         if (CurHP <= 1000.0f) {
                         if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                              orig_TryUseSkill(instance, 8530, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                            }}}}
                          if (Config.Visual.Balmond || AutoOff) {
                          if (Distance < 5.0f && CurHP < MaxEnemyHP) {
                          if (CurHP <= 1000.0f) {
                          if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                              orig_TryUseSkill(instance, 230, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                             }}}}
                                    
                         if (Config.Visual.Moskov || AutoOff) {
                         if (Distance < 1000.0f && CurHP < MaxEnemyHP) {
                         if (CurHP <= 1000.0f) {
                         if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                              orig_TryUseSkill(instance, 3130, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                            }}}}

                      if (Config.Visual.Xavier || AutoOff) {
                         if (Distance < 1000.0f && CurHP < MaxEnemyHP) {
                         if (CurHP <= 1000.0f) {
                         if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                              orig_TryUseSkill(instance, 11530, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                            }}}}
       
                          if (Config.Visual.Granger || AutoOff) {
                          if (Distance < 20.0f && CurHP < MaxEnemyHP) {
                          if (CurHP <= 1000.0f) {
                          if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                              orig_TryUseSkill(instance, 7930, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                             }}}}
                                    
              if (Config.Visual.Hilda2 || AutoOff) {
                          if (Distance < 20.0f && CurHP < MaxEnemyHP) {
                          if (CurHP <= 1000.0f) {
                          if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                              orig_TryUseSkill(instance, 3530, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                             }}}}
                          if (Config.Visual.YinUlti || AutoOff) {
                          if (Distance < 5.0f && CurHP < MaxEnemyHP) {
                          if (CurHP <= 1500.0f) {
                          if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                              orig_TryUseSkill(instance, 11330, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                            }}}}
                          if (Config.Visual.YinUlti2 || AutoOff) {
                          if (Distance < 5.0f && CurHP < MaxEnemyHP) {
                          if (CurHP <= 4000.0f) {
                          if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                              orig_TryUseSkill(instance, 11330, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                            }}}}
                         if (Config.Visual.YinUlti3 || AutoOff) {
                          if (Distance < 5.0f && CurHP < MaxEnemyHP) {
                          if (CurHP <= 6000.0f) {
                          if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                              orig_TryUseSkill(instance, 11330, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                            }}}}
                       
       
                          if (Config.Visual.Argus || AutoOff) {
                          if (Distance < 5.0f && MaxHP) {
                          if (MaxHP <= 1500.0f) {
                          if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                              orig_TryUseSkill(instance, 4530, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                             }}}}
                                    
                                                      								
                 if (EntityPos != Vector3::zero()) {
                        auto targetLockPos = Vector3::Normalized(EntityPos - selfPos);
							if (Config.Visual.BeatrixUlti) {
                            if (skillId == 100 * HeroID + 30 || skillId == 2010530 /*Beatrix Ulti*/) {
                                isDoneAim = true;
                                orig_TryUseSkill(instance, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAlong);
                            }
                        }
					    if (Config.Visual.Pharsa || AutoCombo) {
                                        if (Distance < 10 && skillId == 5230) {
                                            if (_Position != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 5230, targetLockPos, true, _Position, false, true);
                                                sleep(0.5);
                                                orig_TryUseSkill(instance, 5230, targetLockPos, true, _Position, false, true);
                                                sleep(0.5);
                                                orig_TryUseSkill(instance, 5230, targetLockPos, true, _Position, false, true);
                                                if (Distance < 10 && skillId == 5230) {
                                                    if (_Position != Vector3::zero()) {
                                                        orig_TryUseSkill(instance, 5230, targetLockPos, true, _Position, false, true);
                                                        sleep(0.5);
                                                        orig_TryUseSkill(instance, 5230, targetLockPos, true, _Position, false, true);
                                                        sleep(0.5);
                                                        orig_TryUseSkill(instance, 5230, targetLockPos, true, _Position, false, true);
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
						if (Config.Visual.Yve || AutoCombo) {
                                        if (Distance < 10 && skillId == 10130) {
                                            if (_Position != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 10140, targetLockPos, true, _Position, false, true);
                                                sleep(0.5);
                                                orig_TryUseSkill(instance, 10140, targetLockPos, true, _Position, false, true);
                                                sleep(0.5);
                                                orig_TryUseSkill(instance, 10140, targetLockPos, true, _Position, false, true);
                                                if (Distance < 10 && skillId == 10130) {
                                                    if (_Position != Vector3::zero()) {
                                                        orig_TryUseSkill(instance, 10140, targetLockPos, true, _Position, false, true);
                                                        sleep(0.5);
                                                        orig_TryUseSkill(instance, 10140, targetLockPos, true, _Position, false, true);
                                                        sleep(0.5);
                                                        orig_TryUseSkill(instance, 10140, targetLockPos, true, _Position, false, true);
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
					

                        if (Config.Visual.Chou2 || AutoCombo) {
                            if (skillId == 20100 && Distance<5) {
                                isDoneAim = true;
                                orig_TryUseSkill(instance, 20100, targetLockPos, true, _Position, false, true);
								orig_TryUseSkill(instance, 2630, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
                                
                               }
                        }
                        if (Config.Visual.Helcurt || AutoCombo) {
                            if (skillId == 5120 && Distance<5) {
                                isDoneAim = true;
                                orig_TryUseSkill(instance, 5120, targetLockPos, true, _Position, false, true);
								orig_TryUseSkill(instance, 5130, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
                                
                               }
                        }
                        if (Config.Visual.Harley || AutoCombo) {
                            if (skillId == 4220 && Distance<5) {
                                isDoneAim = true;
                                orig_TryUseSkill(instance, 4220, targetLockPos, true, _Position, false, true);
								orig_TryUseSkill(instance, 4230, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
                                
                               }
                        }
						if (Config.Visual.ComboXavier12 || AutoCombo){
                            if (Distance < 10 && skillId == 11510) {
                               
                               orig_TryUseSkill(instance, 11520, targetLockPos, true, _Position, false, true);
                               
								}	
						     }
							 if (Config.Visual.Selena || AutoCombo) {
                                        if (Distance < 10 && skillId == 6320) {

                               orig_TryUseSkill(instance, 6310, targetLockPos, true, _Position, false, true);
                                        }
                                    }
							 if (Config.Visual.Esmeralda || AutoCombo) {
                                        if (Distance < 10 && skillId == 8110) {
                               orig_TryUseSkill(instance, 8110, targetLockPos, true, _Position, false, true);
                               orig_TryUseSkill(instance, 8120, targetLockPos, true, _Position, false, true);
                                        }
                                    }
									if (Config.Visual.Esmeralda2 || AutoCombo) {
                                        if (Distance < 10 && skillId == 8120) {
                                            
                               orig_TryUseSkill(instance, 8110, targetLockPos, true, _Position, false, true);
                                        }
                                    }
										if (Config.Visual.Gusion2 || AutoCombo) {
										if (Distance < 10 && skillId == 5600) {
                                        //if (EnemyDistance < TargetDistance && skillId == 5600) {
                                            if (_Position != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 5610, targetLockPos, true, _Position, false, true);
                                                orig_TryUseSkill(instance, 5620, targetLockPos, true, _Position, false, true);
											    if (Distance < 10 && skillId == 5630) {
                                                //if (EnemyDistance < TargetDistance && skillId == 5630) {
                                                    if (_Position != Vector3::zero()) {
                                                        orig_TryUseSkill(instance, 5610, targetLockPos, true, _Position, false, true);
                                                        orig_TryUseSkill(instance, 5620, targetLockPos, true, _Position, false, true);
                                                        //orig_TryUseSkill(instance, 5600, iTargetPos, true, _Position, false, true);
                                                    }
                                                }
                                            }
                                        }
                                    }
							if (Config.Visual.Selena2 || AutoCombo) {
                                        if (skillId == 6310 && Distance<19.7) {
                                        orig_TryUseSkill(instance, 6310, targetLockPos, true, _Position, false, true);
                                        orig_TryUseSkill(instance, 6320, targetLockPos, true, _Position, false, true);
                                        }
                                    }
									if (Config.Visual.Franco || AutoCombo) {
                                        if (skillId == 1030 && Distance<5) {
                                        orig_TryUseSkill(instance, 1030, targetLockPos, true, _Position, false, true);

                                        }
                                    }
									if (Config.Visual.Eudora22 || AutoCombo) {
                                                                    if (skillId == 1520 && Distance<5) {
                                isDoneAim = true;
                                orig_TryUseSkill(instance, 1520, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                                orig_TryUseSkill(instance, 1530, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                                orig_TryUseSkill(instance, 1510, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);                                
                               }
                        }

									if (Config.Visual.Freya || AutoCombo) {
                                        if (skillId == 2200 && Distance<19.7) {
                                        orig_TryUseSkill(instance, 2210, targetLockPos, true, _Position, false, true);
                                        orig_TryUseSkill(instance, 2220, targetLockPos, true, _Position, false, true);
                                        orig_TryUseSkill(instance, 2230, targetLockPos, true, _Position, false, true);
                                        }
                                    }
					   if (Config.Visual.ComboXavier122 || AutoCombo){
                            if (Distance < 10 && skillId == 11510) {
                               orig_TryUseSkill(instance, 11510, targetLockPos, true, _Position, false, true);
                               orig_TryUseSkill(instance, 11520, targetLockPos, true, _Position, false, true);
                               
								}	
						     }
							 if (Config.Visual.Vale || AutoCombo) {
                            if (Distance < 10 && skillId == 6610) {
                               // isDoneAim = true;
							   orig_TryUseSkill(instance, 6620, targetLockPos, true, _Position, false, true);
							   orig_TryUseSkill(instance, 6630, targetLockPos, true, _Position, false, true);
                                //orig_TryUseSkill(instance, 6610, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                                //orig_TryUseSkill(instance, 6630, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
								//orig_TryUseSkill(instance, 6610, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
 //                              orig_TryUseSkill(instance, 6610, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                               }
                        }
						if (Config.Visual.Vale2 || AutoCombo) {
							   if (skillId ==  6600&& Distance<10) {
								  orig_TryUseSkill(instance, 6610, targetLockPos, true, _Position, false, true);
                               
							   
                               // isDoneAim = true;
							   orig_TryUseSkill(instance, 6620, targetLockPos, true, _Position, false, true);
							   orig_TryUseSkill(instance, 6630, targetLockPos, true, _Position, false, true);
							   orig_TryUseSkill(instance, 20100, targetLockPos, true, _Position, false, true);
                                //orig_TryUseSkill(instance, 6610, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                                //orig_TryUseSkill(instance, 6630, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
								//orig_TryUseSkill(instance, 6610, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
 //                              orig_TryUseSkill(instance, 6610, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
								}	
						     }
							  if (Config.Visual.Ruby || AutoCombo) {
        if (skillId ==  2900&& Distance<10) {
        if (_Position != Vector3::zero()) {     
                                isDoneAim = true;
		orig_TryUseSkill(instance, 20100, targetLockPos, true, _Position, false, true);
		orig_TryUseSkill(instance, 2930, targetLockPos, true, _Position, false, true);
       // orig_TryUseSkill(instance, 20100, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
        //orig_TryUseSkill(instance, 2930, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
        if (skillId ==  2900&& Distance<10) {
        if (_Position != Vector3::zero()) {     
        isDoneAim = true;
		orig_TryUseSkill(instance, 2920, targetLockPos, true, _Position, false, true);
		orig_TryUseSkill(instance, 2910, targetLockPos, true, _Position, false, true);
        //orig_TryUseSkill(instance, 2920, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
        //orig_TryUseSkill(instance, 2910, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
        }
        }}}}
		
		if (Config.Visual.Dragons || AutoCombo) {
        if (skillId ==  9500&& Distance<10) {
        if (_Position != Vector3::zero()) {     
                                isDoneAim = true;
		orig_TryUseSkill(instance, 9510, targetLockPos, true, _Position, false, true);
		orig_TryUseSkill(instance, 9530, targetLockPos, true, _Position, false, true);
        //orig_TryUseSkill(instance, 9510, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
       // orig_TryUseSkill(instance, 9530, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
        if (skillId ==  9500&& Distance<10) {
        if (_Position != Vector3::zero()) {     
        isDoneAim = true;
		orig_TryUseSkill(instance, 9520, targetLockPos, true, _Position, false, true);
		orig_TryUseSkill(instance, 9540, targetLockPos, true, _Position, false, true);
        //orig_TryUseSkill(instance, 9520, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
        //orig_TryUseSkill(instance, 9540, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
        }
        }}}}
		if (Config.Visual.Hayabusa || AutoCombo) {
                            if (skillId == 2100 && Distance<8) {
								if (_Position != Vector3::zero()) {
                                isDoneAim = true;
							    orig_TryUseSkill(instance, 2110, targetLockPos, true, _Position, false, true);
								orig_TryUseSkill(instance, 2130, targetLockPos, true, _Position, false, true);
                                //orig_TryUseSkill(instance, 2110, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                               // orig_TryUseSkill(instance, 2130, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                                     }
                                }}
		if (Config.Visual.Eudora || AutoCombo) {
                            if (skillId == 1520 && Distance<5) {
								if (_Position != Vector3::zero()) {
                                isDoneAim = true;
							    orig_TryUseSkill(instance, 1520, targetLockPos, true, _Position, false, true);
                                orig_TryUseSkill(instance, 1520, targetLockPos, true, _Position, false, true);
								orig_TryUseSkill(instance, 1530, targetLockPos, true, _Position, false, true);
								orig_TryUseSkill(instance, 1530, targetLockPos, true, _Position, false, true);
								orig_TryUseSkill(instance, 1510, targetLockPos, true, _Position, false, true);
                                orig_TryUseSkill(instance, 1510, targetLockPos, true, _Position, false, true);
                                //orig_TryUseSkill(instance, 2110, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                               // orig_TryUseSkill(instance, 2130, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                                     }
                                }}
		if (Config.Visual.Hanzo || AutoCombo) {
        if (skillId ==  6900&& Distance<10) {
        if (_Position != Vector3::zero()) {     
                                isDoneAim = true;
		orig_TryUseSkill(instance, 6920, targetLockPos, true, _Position, false, true);
		orig_TryUseSkill(instance, 6930, targetLockPos, true, _Position, false, true);
        //orig_TryUseSkill(instance, 3810, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
        //orig_TryUseSkill(instance, 3820, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
        
		orig_TryUseSkill(instance, 6920, targetLockPos, true, _Position, false, true);
        orig_TryUseSkill(instance, 6910, targetLockPos, true, _Position, false, true);
                                     }
                                }}
								   if (Config.Visual.Xevana2 || AutoCombo){
                            if (Distance < 10 && skillId == 3810) {
                               orig_TryUseSkill(instance, 3810, targetLockPos, true, _Position, false, true);
                               orig_TryUseSkill(instance, 3820, targetLockPos, true, _Position, false, true);
                               		}	
						     }
							     if (Config.Visual.Lylia2 || AutoCombo){
                            if (Distance < 10 && skillId == 8610) {
                               orig_TryUseSkill(instance, 8610, targetLockPos, true, _Position, false, true);
                               orig_TryUseSkill(instance, 8620, targetLockPos, true, _Position, false, true);
                               		}	
						     }
							     if (Config.Visual.Lylia || AutoCombo){
                            if (Distance < 15 && skillId == 8620) {

                               orig_TryUseSkill(instance, 8610, targetLockPos, true, _Position, false, true);
								}	
						     }
		if (Config.Visual.Xevana || AutoCombo) {
        if (skillId ==  3810&& Distance<10) {
        if (_Position != Vector3::zero()) {     
                                isDoneAim = true;
		orig_TryUseSkill(instance, 3820, targetLockPos, true, _Position, false, true);
		orig_TryUseSkill(instance, 3830, targetLockPos, true, _Position, false, true);
		orig_TryUseSkill(instance, 3830, targetLockPos, true, _Position, false, true);
                                     }
                                }}
						    if (Config.Visual.Kagura || AutoCombo) {
        if (skillId ==  2500&& Distance<10) {
        if (_Position != Vector3::zero()) {     
        orig_TryUseSkill(instance, 20100, targetLockPos, true, _Position, false, true);
		orig_TryUseSkill(instance, 2510, targetLockPos, true, _Position, false, true);
      //  orig_TryUseSkill(instance, 20100, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
       // orig_TryUseSkill(instance, 2510, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
        if (skillId ==  2500&& Distance<10) {
        if (_Position != Vector3::zero()) {     
        
		orig_TryUseSkill(instance, 2530, targetLockPos, true, _Position, false, true);
       // orig_TryUseSkill(instance, 2530, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
	   orig_TryUseSkill(instance, 2510, targetLockPos, true, _Position, false, true);
        //orig_TryUseSkill(instance, 2510, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
        if (skillId ==  2500&& Distance<10) {
        if (_Position != Vector3::zero()) {     
        orig_TryUseSkill(instance, 2520, targetLockPos, true, _Position, false, true);
		orig_TryUseSkill(instance, 2530, targetLockPos, true, _Position, false, true);
        //orig_TryUseSkill(instance, 2520, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
        //orig_TryUseSkill(instance, 2530, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
        }
        }}}}}}
					    if (Config.Visual.ComboXavier21 || AutoCombo){
                            if (Distance < 15 && skillId == 11520) {

                               orig_TryUseSkill(instance, 11510, targetLockPos, true, _Position, false, true);
								}	
						     }
							                                 if  (Config.Visual.Yve2233 || AutoCombo) {
        if (skillId ==  10130&& Distance<15) {
        if (_Position != Vector3::zero()) {
                                
        orig_TryUseSkill(instance, 10130, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
                                     }
                                }}
					   if (Config.Visual.ComboXavier221 || AutoCombo){
                            if (Distance < 15 && skillId == 11520) {
                               orig_TryUseSkill(instance, 11520, targetLockPos, true, _Position, false, true);
                               orig_TryUseSkill(instance, 11510, targetLockPos, true, _Position, false, true);
								}	
						     }
                        //Basic
                        if (Aim.Helper.Skills.Basic) {
                            if (skillId == 100 * HeroID + 00 || skillId == 2010500) {
                                isDoneAim = true;
                                orig_TryUseSkill(instance, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
                            }
                        }
                        //Spell
                        if (Aim.Helper.Skills.Spell) {
                            if (skillId == 20100 || skillId == 20140) {
                                isDoneAim = true;
                                orig_TryUseSkill(instance, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
                            }
                        }
                        //Skill 1
                        if (Aim.Helper.Skills.Skill1) {
                            if (skillId == 100 * HeroID + 10) {
                                isDoneAim = true;
                                orig_TryUseSkill(instance, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
                            }
                        }
                        //Skill 2
                        if (Aim.Helper.Skills.Skill2) {
                            if (skillId == 100 * HeroID + 20 || skillId == 2010520 /*Beatrix Skill2*/) {
                                isDoneAim = true;
                                orig_TryUseSkill(instance, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
                            }
                        }
                        //Skill 3
                        if (Aim.Helper.Skills.Skill3) {
                            if (skillId == 100 * HeroID + 30 || skillId == 2010530 /*Beatrix Ulti*/) {
                                isDoneAim = true;
                                orig_TryUseSkill(instance, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
                            }
                        }
						if (Config.Visual.Beatrix2) {
                            if (skillId == 100 * HeroID + 30 || skillId == 2010530 /*Beatrix Ulti*/) {
                                isDoneAim = true;
                                orig_TryUseSkill(instance, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
                            }
                        }
                        //Skill 4
                        if (Aim.Helper.Skills.Skill4) {
                            if (skillId == 100 * HeroID + 40) {
                                isDoneAim = true;
                                orig_TryUseSkill(instance, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
                            }
                        }
                    }

                }
            }
        }
		}}
		if (Aim.Helper.Priority.AutoTakeSword){
		float MaxDist = std::numeric_limits<float>::infinity();
          Vector3 EntityPos2 = Vector3::zero();
            Vector3 Hp;
             float MaxEnemyHP = std::numeric_limits<float>::infinity();
               void *BattleManager_Instance;
                 Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &BattleManager_Instance);
                     if (BattleManager_Instance) {
                       auto m_LocalPlayerShow = *(uintptr_t *) ((uintptr_t)BattleManager_Instance + BattleManager_m_LocalPlayerShow);
                          if (m_LocalPlayerShow) {
                            auto selfPos = *(Vector3 *) ((uintptr_t)m_LocalPlayerShow + ShowEntity__Position);
                            auto HeroID = *(int *) ((uintptr_t)m_LocalPlayerShow + EntityBase_m_ID);
                            if (selfPos != Vector3::zero()) {
							               
					monoList<void **> *_RunBullets;
                            Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "_RunBullets", &_RunBullets);
                            if (_RunBullets) {
                        for (int i = 0; i < _RunBullets->getSize(); i++) {
                            auto Pawn = _RunBullets->getItems()[i];
                            if (!Pawn) continue;
                            auto m_ID = *(int *) ((uintptr_t)Pawn + Bullet_m_Id);
                            if (m_ID != 8452) continue;
                            auto transform = *(Transform **) ((uintptr_t)Pawn + Bullet_transform);
                            float Distance = (int) Vector3::Distance(selfPos, transform->get_position());
                         
							 if (Distance < 5.0f) {
                                    EntityPos2 = transform->get_position();
                            }
                        }
                    }

                    if (EntityPos2 != Vector3::zero() && HeroID == 84) {
                        auto targetLockPos = Vector3::Normalized(EntityPos2 - selfPos);
                        if (skillId == 100 * HeroID + 20) {
                            isDoneAim = true;
                            orig_TryUseSkill(instance, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
                        }}}}}
                    } 
					
    }
    if (!isDoneAim) {
        orig_TryUseSkill(instance, skillId, dir, dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
    }
}


int CalculateRetriDamage(int m_Level, int m_KillWildTimes) {
int AddRetriDmg, CalculateRetriDamage = (m_KillWildTimes>5) ? 520 + ((m_Level+5)*80), 520 + ((m_Level+5)*160), 520 + ((m_Level+5)*240), /*Next 7*/ 780 + ((m_Level+5)*480), 780 + ((m_Level+6)*600), 780 + ((m_Level+7)*720), 780 + ((m_Level+8)*840), 780 + ((m_Level+9)*960), 780 + ((m_Level+10)*1080), 780 + ((m_Level+11)*1200), 780 + ((m_Level+12)*1440), 780 + ((m_Level+13)*1560), 780 + ((m_Level+14)*1680), 780 + ((m_Level+15)*1800) : 0;
    if (m_KillWildTimes < 5) {
        return 520 + (80 * m_Level);
		return 520 + (160 * m_Level);
		return 520 + (240 * m_Level);
		return 780 + (480 * m_Level);
		return 780 + (600 * m_Level);
		return 780 + (720 * m_Level);
		return 780 + (840 * m_Level);
		return 780 + (960 * m_Level);
		return 780 + (1080 * m_Level);
		return 780 + (1200 * m_Level);
		return 780 + (1320 * m_Level);
		return 780 + (1440 * m_Level);
		return 780 + (1560 * m_Level);
		return 780 + (1680 * m_Level);
		return 780 + (1800 * m_Level);
    } else {
		return 1.5 * (520 + (80 * m_Level));
        return 1.5 * (520 + (160 * m_Level));
		return 1.5 * (520 + (240 * m_Level));
        return 1.5 * (780 + (480 * m_Level));
		return 1.5 * (780 + (600 * m_Level));
		return 1.5 * (780 + (720 * m_Level));
        return 1.5 * (780 + (840 * m_Level));
		return 1.5 * (780 + (960 * m_Level));
        return 1.5 * (780 + (1080 * m_Level));
		return 1.5 * (780 + (1200 * m_Level));
		return 1.5 * (780 + (1320 * m_Level));
        return 1.5 * (780 + (1440 * m_Level));
		return 1.5 * (780 + (1560 * m_Level));
        return 1.5 * (780 + (1680 * m_Level));
		return 1.5 * (780 + (1800 * m_Level));
    }
}


void (*orig_UpdateRetribution)(void *thiz);
void UpdateRetribution(void *thiz) {
       if (thiz != NULL) {
		
            void *BattleManager_Instance;
            Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &BattleManager_Instance);
            if (BattleManager_Instance) {
                auto m_LocalPlayerShow = *(uintptr_t *) ((uintptr_t)BattleManager_Instance + BattleManager_m_LocalPlayerShow);
                if (m_LocalPlayerShow) {
                    auto selfPos = *(Vector3 *) ((uintptr_t)m_LocalPlayerShow + ShowEntity__Position);
                    if (selfPos != Vector3::zero()) {
                        auto m_Level = *(int *) ((uintptr_t)m_LocalPlayerShow + EntityBase_m_Level);
						auto HeroID = *(int *) ((uintptr_t)m_LocalPlayerShow + EntityBase_m_ID);
                        auto _logicFighter = *(uintptr_t *) ((uintptr_t)m_LocalPlayerShow + ShowEntity__logicFighter);
                        int iCalculateDamage;
                        if (_logicFighter) {
                            auto m_KillWildTimes = *(int *) ((uintptr_t)_logicFighter + LogicPlayer_m_KillWildTimes);
                            iCalculateDamage = CalculateRetriDamage(m_Level, m_KillWildTimes);
                        }
						float CurHP = *(int *) ((uintptr_t)m_LocalPlayerShow + EntityBase_m_Hp);                                                        
						  if (CurHP <= 300 + (40 * m_Level)){
                                 if (HeroID && Aegis || AutoSpell) {                                                  
						        	orig_TryUseSkill(thiz, 20060);									
								}}	
								
								 if (CurHP <= 300 + (40 * m_Level)){
                                    if (HeroID && Vengeance || AutoSpell) {                                                  						        
									orig_TryUseSkill(thiz, 20190);						
								}}		
								
								if (CurHP <= 300 + (40 * m_Level)){
                                    if (HeroID && Sprint || AutoSpell) {                                                  						        
									orig_TryUseSkill(thiz,  20040);						
								}}		
								
								if (CurHP <= 300 + (40 * m_Level)){
                                    if (HeroID && Fliker || AutoSpell) {                                                  						        
									orig_TryUseSkill(thiz,  20100);						
								}}		 
								
								 if (CurHP <= 300 + (40 * m_Level)){
                                    if (HeroID && Revitalize || AutoSpell) {                                                  					        	
									orig_TryUseSkill(thiz, 20050);
								}}		
								
				      monoList<void **> *m_ShowPlayers = *(monoList<void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_ShowPlayers);
                        if (m_ShowPlayers) {
                            for (int i = 0; i < m_ShowPlayers->getSize(); i++) {
                                auto Pawn2 = m_ShowPlayers->getItems()[i];
                                if (!Pawn2) continue;													  
							    auto m_bSameCampType = *(bool *) ((uintptr_t)Pawn2 + EntityBase_m_bSameCampType);
                                if (m_bSameCampType) continue;
                                auto m_bDeath = *(bool *) ((uintptr_t)Pawn2 + EntityBase_m_bDeath);
                                if (m_bDeath) continue;									
								auto _Position2 = *(Vector3 *) ((uintptr_t)Pawn2 + ShowEntity__Position);					
								float Distance = (int) Vector3::Distance(selfPos, _Position2);
                                float CurHP = *(int *) ((uintptr_t)Pawn2 + EntityBase_m_Hp); 
								float MaxHP = *(int *) ((uintptr_t)Pawn2 + EntityBase_m_HpMax);                       
							    int m_Level2 = *(int *) ((uintptr_t)Pawn2 + EntityBase_m_Level); 					
                                if (Distance < 5 && CurHP) {
                                    if (CurHP <= 300 + (40 * m_Level2)) {
                                        if (HeroID && Execute || AutoSpell) {                           
                                    if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero() && HeroID) { 							
							orig_TryUseSkill(thiz, 20150, Vector3::Normalized(_Position2 - selfPos)); 
				            
							}}}}
							if (Distance < 8 && CurHP) {
							if (CurHP <= 200 + (40 * m_Level2)) {
                                        if (HeroID && Flameshot || AutoSpell) {                           
                                    if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero() && HeroID) { 							
							orig_TryUseSkill(thiz, 20140, Vector3::Normalized(_Position2 - selfPos)); 
				            }}}}
							if (Distance < 7 && CurHP) {
							if (CurHP <= 300 + (40 * m_Level2)) {
                                        if (HeroID && Argus2 || AutoSpell) {                           
                                    if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero() && HeroID) { 							
							orig_TryUseSkill(thiz, 4530, Vector3::Normalized(_Position2 - selfPos)); 
				            }}}}
							if (Config.Visual.Kagura2) {
        if (Distance < 1000.0f && CurHP) {
        if (CurHP <= 2281) {
        if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero()) {  
      //  orig_TryUseSkill(instance, 20100, targetLockPos, true, _Position, false, true);
		//orig_TryUseSkill(instance, 2510, targetLockPos, true, _Position, false, true);
       orig_TryUseSkill(thiz, 20100, Vector3::Normalized(_Position2 - selfPos), true, selfPos, false, true);
       orig_TryUseSkill(thiz, 2510, Vector3::Normalized(_Position2 - selfPos), true, selfPos, false, true);
		//orig_TryUseSkill(thiz, 2530, targetLockPos, true, _Position, false, true);
        orig_TryUseSkill(thiz, 2530, Vector3::Normalized(_Position2 - selfPos), true, selfPos, false, true);
	 //  orig_TryUseSkill(instance, 2510, targetLockPos, true, _Position, false, true);
        orig_TryUseSkill(thiz, 2510, Vector3::Normalized(_Position2 - selfPos), true, selfPos, false, true);
       // orig_TryUseSkill(instance, 2520, targetLockPos, true, _Position, false, true);
		//orig_TryUseSkill(instance, 2530, targetLockPos, true, _Position, false, true);
        orig_TryUseSkill(thiz, 2520, Vector3::Normalized(_Position2 - selfPos), true, selfPos, false, true);
        orig_TryUseSkill(thiz, 2530, Vector3::Normalized(_Position2 - selfPos), true, selfPos, false, true);
                            }}}}
  
                            if (Config.Visual.BeatrixSniper || AutoOn) {
        if (Distance < 1000.0f && CurHP) {
        if (CurHP <= 1037) {
        if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero()) {  
      //  orig_TryUseSkill(instance, 20100, targetLockPos, true, _Position, false, true);
		//orig_TryUseSkill(instance, 2510, targetLockPos, true, _Position, false, true);
       
        orig_TryUseSkill(thiz, 6305, Vector3::Normalized(_Position2 - selfPos), true, selfPos, false, true);
                            }}}}
							if (Config.Visual.Freya2) {
					     if (Distance < 1000.0f && CurHP) {
                         if (CurHP <= 2281) {
                         if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero()) {
                                       // if (skillId == 2200 && Distance<19.7) {
										  orig_TryUseSkill(thiz, 2210, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
										  orig_TryUseSkill(thiz, 2220, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
										  orig_TryUseSkill(thiz, 2230, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
                                        //orig_TryUseSkill(instance, 2210, targetLockPos, true, _Position, false, true);
                                        //orig_TryUseSkill(instance, 2220, targetLockPos, true, _Position, false, true);
                                        //orig_TryUseSkill(instance, 2230, targetLockPos, true, _Position, false, true);
                            }}}}
							if (Config.Visual.ComboXavierAutomatic){
					     if (Distance < 1000.0f && CurHP) {
                         if (CurHP <= 1500.0f) {
                         if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero()) {
                                orig_TryUseSkill(thiz, 11510, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
							    orig_TryUseSkill(thiz, 11520, _Position2, true,  selfPos, false, true);
                            }}}}
 
                            if (Config.Visual.ComboXavierAutomatic2){
					     if (Distance < 1000.0f && CurHP) {
                         if (CurHP <= 1500.0f) {
                         if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero()) {
							    orig_TryUseSkill(thiz, 11520, _Position2, true,  selfPos, false, true);
							    orig_TryUseSkill(thiz, 11510, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
                            }}}}
							if (Config.Visual.Moskov22 || AutoOn) {
                         if (Distance < 1000.0f && CurHP) {
                         if (CurHP <= 1037) {
                         if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero()) {
                              orig_TryUseSkill(thiz, 3130, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
                            }}}}
                         if (Config.Visual.Granger3 || AutoOn) {
                         if (Distance < 1000.0f && CurHP) {
                         if (CurHP <= 1037) {
                         if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero()) {
                              orig_TryUseSkill(thiz, 7930, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
                            }}}}
                             if (Config.Visual.Balmond222 || AutoOn) {
                         if (Distance < 4.0f && CurHP) {
                         if (CurHP <= 1037) {
                         if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero()) {
                             orig_TryUseSkill(thiz, 230, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
                            }}}}
                        if (Config.Visual.YinUlti4 || AutoOn) {
                         if (Distance < 4.0f && CurHP) {
                         if (CurHP <= 1037) {
                         if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero()) {
                             orig_TryUseSkill(thiz, 11330, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
                            }}}}
                         if (Config.Visual.YinUlti5 || AutoOn) {
                         if (Distance < 4.0f && CurHP) {
                         if (CurHP <= 4000) {
                         if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero()) {
                             orig_TryUseSkill(thiz, 11330, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
                            }}}}
                         if (Config.Visual.YinUlti6 || AutoOn) {
                         if (Distance < 4.0f && CurHP) {
                         if (CurHP <= 6000) {
                         if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero()) {
                             orig_TryUseSkill(thiz, 11330, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
                            }}}}
                       if (Config.Visual.Dyrroth || AutoOn) {
                         if (Distance < 5.0f && CurHP) {
                         if (CurHP <= 1037) {
                         if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero()) {
                             orig_TryUseSkill(thiz, 8530, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
                            }}}}
                        if (Config.Visual.Hilda || AutoOn) {
                         if (Distance < 5.0f && CurHP) {
                         if (CurHP <= 1037) {
                         if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero()) {
                             orig_TryUseSkill(thiz, 3530, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
                            }}}}
                              if (Config.Visual.Martis222 || AutoOn) {
                         if (Distance < 5.0f && CurHP) {
                         if (CurHP <= 1037) {
                         if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero()) {
                             orig_TryUseSkill(thiz, 5830, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
                            }}}}
                              if (Config.Visual.Xavier22 || AutoOn) {
                         if (Distance < 1000.0f && CurHP) {
                         if (CurHP <= 1037) {
                         if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero()) {
                         orig_TryUseSkill(thiz, 11530, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
                            }}}}
                         if (Config.Visual.Freedrin || AutoOn) {
                         if (Distance < 1000.0f && CurHP) {
                         if (CurHP <= 1037) {
                         if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero()) {
                         orig_TryUseSkill(thiz, 11740, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
                            }}}}
                         if (Config.Visual.Edith) {
                         if (Distance < 5.0f && CurHP) {
                         if (CurHP <= 3000) {
                         if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero()) {
	                     orig_TryUseSkill(thiz, 11110, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
	                     orig_TryUseSkill(thiz, 11120, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
	                     orig_TryUseSkill(thiz, 11130, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);

					     orig_TryUseSkill(thiz, 11110, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
						 orig_TryUseSkill(thiz, 11120, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
						 orig_TryUseSkill(thiz, 11100, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
						 orig_TryUseSkill(thiz, 11100, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
                            }}}}
								 if (Distance < 15 && CurHP) {
                                    if (CurHP <= 300 + (40 * m_Level2)) {
                                        if (HeroID && FlameShot) {                           
                                    if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero() && HeroID) { 							
							orig_TryUseSkill(thiz, 20140, Vector3::Normalized(_Position2 - selfPos)); 
				                           		                            						 				                	                            
						    }}}}	
							
					     if (Config.Visual.Beatrix || AutoOn){  
                         if (Distance < 20.0f && CurHP) {
                          if (CurHP <= 1037) {
                          if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero()) {
                              orig_TryUseSkill(thiz, 2010530, Vector3::Normalized(_Position2 - selfPos), true, Vector3::zero(), false, true);
                             }}}}

                        /* monoList<void **> *m_ShowMonsters = *(monoList<void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_ShowMonsters);
                         if (m_ShowMonsters) {
                            for (int i = 0; i < m_ShowMonsters->getSize(); j++) {
                                auto Pawn3 = m_ShowMonsters->getItems()[j];
                                if (!Pawn3) continue;
                                auto m_ID = *(int *) ((uintptr_t)Pawn + EntityBase_m_ID);
                                if (MonsterToString(m_ID) == "") continue;
								
                                auto m_bSameCampType = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bSameCampType);
                                if (m_bSameCampType) continue;
                                auto m_bDeath = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bDeath);
                                if (m_bDeath) continue;
                                auto _Position1 = *(Vector3 *) ((uintptr_t)Pawn + ShowEntity__Position);
                                float Distance1 = (int) Vector3::Distance(selfPos, _Position1);
								float EnemyDistance1 = Vector3::Distance(selfPos, _Position1);
                                float CurHP1 = *(int *) ((uintptr_t)Pawn + EntityBase_m_Hp);
                                float MaxHP1 = *(int *) ((uintptr_t)Pawn + EntityBase_m_HpMax);
                                float PercentHP1 = CurHP1 * 100 / MaxHP1;*/
								
							//if (EnemyDistance < TargetDistance || CurHP <= TargetHP) {
								
                            
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                        
                                                           /*monoList<void **> *m_ShowMonsters = *(monoList<void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_ShowMonsters);
                        if (m_ShowMonsters) {
                            for (int j = 0; j < m_ShowMonsters->getSize(); j++) {
                                auto Pawn = m_ShowMonsters->getItems()[j];
                                if (!Pawn) continue;
                                auto m_ID = *(int *) ((uintptr_t)Pawn + EntityBase_m_ID);
                                if (MonsterToString(m_ID) == "") continue;
								
                                auto m_bSameCampType = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bSameCampType);
                                if (m_bSameCampType) continue;
                                auto m_bDeath = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bDeath);
                                if (m_bDeath) continue;
                                auto _Position1 = *(Vector3 *) ((uintptr_t)Pawn + ShowEntity__Position);
                                float Distance1 = (int) Vector3::Distance(selfPos, _Position1);
								float EnemyDistance1 = Vector3::Distance(selfPos, _Position1);
                                float CurHP1 = *(int *) ((uintptr_t)Pawn + EntityBase_m_Hp);
                                float MaxHP1 = *(int *) ((uintptr_t)Pawn + EntityBase_m_HpMax);
                                float PercentHP1 = CurHP1 * 100 / MaxHP1;
								
							//if (EnemyDistance < TargetDistance || CurHP <= TargetHP) {
								
                            if (Distance < RangeFOV) {
                                static float AutoStealBuff = 0;*/
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                        /*if (Config.Visual.Granger2) {
        if (Distance1 < 15.7f) {
        if (CurHP1 <= 1500) {
        if (_Position1 - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 7930, Vector3::Normalized(_Position1 - selfPos), true, _Position1, false, true);
        }}
		
		if (Config.Visual.Layla2) {
        if (Distance1 < 16.0f) {
        if (CurHP1 <= 1000) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position1 - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 1830, Vector3::Normalized(_Position1 - selfPos), true, _Position1, false, true);
AutoStealBuff= 0;
orig_TryUseSkill(thiz, 1830, Vector3::Normalized(_Position1 - selfPos), true, _Position1, false, true);
AutoStealBuff= 0;
        }}}}}*/
      
                          																                        
							if (AutoLing) {  
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
                          //  auto LogicPlayerFighter = *(void **)((long)m_LocalPlayerShow + ShowEntity__logicFighter);  
                            auto HeroID = *(int *) ((uintptr_t)m_LocalPlayerShow + EntityBase_m_ID);
                            if (selfPos != Vector3::zero()) {
                            monoList<void **> *_RunBullets;
                            Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "_RunBullets", &_RunBullets);
                            if (_RunBullets) {
                            for (int i = 1; i < _RunBullets->getSize(); i++) {
                            auto Pawn = _RunBullets->getItems()[i];
                            if (!Pawn) continue;
                            auto m_ID = *(int *) ((uintptr_t)Pawn + Bullet_m_Id);
                            if (m_ID != 8452) continue;
                            
                            auto _Position = *(Transform **) ((uintptr_t)Pawn + Bullet_transform);
                            float Distance = (int) Vector3::Distance(selfPos, _Position->get_position());                        
                             if (Distance < 5.0f) {
                                    EntityPos = _Position->get_position();
                            }
                            if (EntityPos != Vector3::zero()) {
                            orig_TryUseSkill(thiz, 8420, Vector3::Normalized(EntityPos - selfPos), true, Vector3::Distance(selfPos, _Position->get_position()), true, true);
                            }
                            }}}}}}
							
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
                                auto _Position = *(Vector3 *) ((uintptr_t)Pawn + ShowEntity__Position);
								float Distance2 = (int) Vector3::Distance(selfPos, _Position2);
                                float Distance = (int) Vector3::Distance(selfPos, _Position);
                                float CurHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_Hp);
                                float MaxHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_HpMax);
                                if (Distance < 5.4f && CurHP < MaxHP) {
                                    if (CurHP <= iCalculateDamage) {
                                        if (m_ID == 2004 && Aim.Helper.AutoRetribution.Buff /*Red Buff*/ || m_ID == 2005 && Aim.Helper.AutoRetribution.Buff /*Blue Buff*/ || m_ID == 2002 && Aim.Helper.AutoRetribution.Trigger /*Blue Buff*/ || m_ID == 2003 && Aim.Helper.AutoRetribution.Trigger /*Blue Buff*/ || m_ID == 2004 && Aim.Helper.AutoRetribution.Kontol /*Blue Buff*/ || m_ID == 2005 && Aim.Helper.AutoRetribution.Kontol /*Blue Buff*/ || m_ID == 2002 && Aim.Helper.AutoRetribution.Lord /*Lord*/ || m_ID == 2011 && Aim.Helper.AutoRetribution.Crab || m_ID == 2003 && Aim.Helper.AutoRetribution.Turtle || m_ID == 2072 && Aim.Helper.AutoRetribution.Lito /*Lito*/|| m_ID == 2056 && Aim.Helper.AutoRetribution.Lito /*Lito*/ || Aim.Helper.AutoRetribution.Rockursa /*Rockursa*/ || m_ID == 2006 && Aim.Helper.AutoRetribution.Scaled /*Scaled*/ ) {
                                            if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                                orig_TryUseSkill(thiz, 20020, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                                            }
                                          }
                                       }
								   }
								   if (m_ID == 2004 && Config.Visual.XavierRed) {	
        if (Distance < 16.0f) {
        if (CurHP <= iCalculateDamage) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 11530, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);

                        }}}}
						if (m_ID == 2004 && Config.Visual.HanzoRed) {	
        if (Distance < 16.0f) {
        if (CurHP <= 3000) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 6910, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);

                        }}}}
						if (m_ID == 2005 && Config.Visual.XavierBlue) {	
        if (Distance < 16.0f) {
        if (CurHP <= iCalculateDamage) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 11530, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);

                        }}}}
						if (m_ID == 2005 && Config.Visual.HanzoBlue) {	
        if (Distance < 16.0f) {
        if (CurHP <= 3000) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 6910, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);

                        }}}}
								    if (m_ID == 2002 && Config.Visual.GusionLord) {
        if (Distance < 15.7f) {
        if (CurHP <= 5840) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 5610, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 5620, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 5630, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 5610, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
	    orig_TryUseSkill(thiz, 5620, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
        }}}}
								  if (m_ID == 2002 && Config.Visual.GrangerLord) {
        if (Distance < 15.7f) {
        if (CurHP <= iCalculateDamage) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 7930, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
        }}}}
								   if (m_ID == 2002 && Config.Visual.PharsaLord || AutoSteall) {
        if (Distance < 15.7f) {
        if (CurHP <= iCalculateDamage) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 5230, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
          }}}}
								   if (m_ID == 2002 && Config.Visual.YveLord) {
        if (Distance < 15.7f) {
        if (CurHP <= 5840) {
        if (_Position - selfPos != Vector3::zero()) {
			//isDoneAim = true;
        orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
								   if (m_ID == 2002 && Config.Visual.PapuquitoLord) {
        if (Distance < 5.0f) {
        if (CurHP <= 5840) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 10300, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10320, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10330, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10300, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
	    orig_TryUseSkill(thiz, 10320, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
	    orig_TryUseSkill(thiz, 10300, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
        orig_TryUseSkill(thiz, 10320, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10310, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10330, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
								   if (m_ID == 2002 && Config.Visual.LaylaLord || AutoSteall) {
        if (Distance < 16.0f) {
        if (CurHP <= iCalculateDamage) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 1830, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);

                        }}}}
								   if (m_ID == 2002 && Config.Visual.XavierLord || AutoSteall) {	
        if (Distance < 16.0f) {
        if (CurHP <= iCalculateDamage) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 11530, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);

                        }}}}
								   
								   if (m_ID == 2002 && Config.Visual.MoskovLord || AutoSteall) {		   
        if (Distance < 16.0f) {
        if (CurHP <= iCalculateDamage) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 3130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
								   
								   if (m_ID == 2002 && Config.Visual.BeatrixLord || AutoSteall) {		   
        if (Distance < 16.0f) {
        if (CurHP <= iCalculateDamage) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 2010530, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
								   
	    if (m_ID == 2002 && Config.Visual.BalmondLord || AutoSteall) {		   
        if (Distance < 16.0f) {
        if (CurHP <= iCalculateDamage) {
             
                                                if (_Position - selfPos != Vector3::zero()) {
                                                    orig_TryUseSkill(thiz, 230, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
						if (m_ID == 2002 && Config.Visual.GusionLord) {		   
        if (Distance < 16.0f) {
        if (CurHP <= iCalculateDamage) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 5610, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 5620, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 5630, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 5610, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
	    orig_TryUseSkill(thiz, 5620, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
        if (m_ID == 2002 && Config.Visual.YveLord) {		   
        if (Distance < 16.0f) {
        if (CurHP <= iCalculateDamage) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
								   
								   if (m_ID == 2002 && Config.Visual.PapuquitoLord) {		   
        if (Distance < 16.0f) {
        if (CurHP <= iCalculateDamage) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 10300, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10320, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10330, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10300, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
	    orig_TryUseSkill(thiz, 10320, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
	    orig_TryUseSkill(thiz, 10300, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
        orig_TryUseSkill(thiz, 10320, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10310, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10330, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
						if (m_ID == 2003 && Config.Visual.GusionTurtle) {
        if (Distance < 15.7f) {
        if (CurHP <= 5840) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 5610, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 5620, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 5630, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 5610, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
	    orig_TryUseSkill(thiz, 5620, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
        }}}}
								  if (m_ID == 2003 && Config.Visual.GrangerTurtle) {
        if (Distance < 15.7f) {
        if (CurHP <= iCalculateDamage) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 7930, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
        }}}}
								   if (m_ID == 2003 && Config.Visual.PharsaTurtle || AutoSteall) {
        if (Distance < 15.7f) {
        if (CurHP <= iCalculateDamage) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 5230, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
          }}}}
								   if (m_ID == 2003 && Config.Visual.YveTurtle) {
        if (Distance < 15.7f) {
        if (CurHP <= 5840) {
        if (_Position - selfPos != Vector3::zero()) {
			//isDoneAim = true;
        orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
								   if (m_ID == 2003 && Config.Visual.PapuquitoTurtle) {
        if (Distance < 5.0f) {
        if (CurHP <= 5840) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 10300, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10320, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10330, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10300, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
	    orig_TryUseSkill(thiz, 10320, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
	    orig_TryUseSkill(thiz, 10300, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
        orig_TryUseSkill(thiz, 10320, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10310, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10330, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
								   if (m_ID == 2003 && Config.Visual.LaylaTurtle || AutoSteallB) {
        if (Distance < 16.0f) {
        if (CurHP <= iCalculateDamage) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 1830, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);

                        }}}}
								   if (m_ID == 2003 && Config.Visual.XavierTurtle || AutoSteallB) {	
        if (Distance < 16.0f) {
        if (CurHP <= iCalculateDamage) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 11530, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);

                        }}}}
								   
								   if (m_ID == 2003 && Config.Visual.MoskovTurtle || AutoSteallB) {		   
        if (Distance < 16.0f) {
        if (CurHP <= iCalculateDamage) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 3130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
								   
								   if (m_ID == 2003 && Config.Visual.BeatrixTurtle || AutoSteallB) {		   
        if (Distance < 16.0f) {
        if (CurHP <= iCalculateDamage) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 2010530, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
								   
	    if (m_ID == 2003 && Config.Visual.BalmondTurtle || AutoSteallB) {		   
        if (Distance < 16.0f) {
        if (CurHP <= iCalculateDamage) {
             
                                                if (_Position - selfPos != Vector3::zero()) {
                                                    orig_TryUseSkill(thiz, 230, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
						if (m_ID == 2003 && Config.Visual.GusionTurtle) {		   
        if (Distance < 16.0f) {
        if (CurHP <= iCalculateDamage) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 5610, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 5620, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 5630, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 5610, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
	    orig_TryUseSkill(thiz, 5620, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
        if (m_ID == 2003 && Config.Visual.YveTurtle) {		   
        if (Distance < 16.0f) {
        if (CurHP <= iCalculateDamage) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
								   if (m_ID == 2002 && Config.Visual.GrangerTriggerLord) {		
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
                                    if (CurHP <= iCalculateDamage) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 7930, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
								   if (m_ID == 2002 && Config.Visual.LaylaTriggerLord || AutoSteallA) {		
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
                                    if (CurHP <= iCalculateDamage) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 1830, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);

}}}}
								   if (m_ID == 2002 && Config.Visual.PharsaTriggerLord || AutoSteallA) {		
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
                                    if (CurHP <= iCalculateDamage) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
orig_TryUseSkill(thiz, 5230, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);

}}}}
								   if (m_ID == 2002 && Config.Visual.XavierTriggerLord || AutoSteallA) {		
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
        if (CurHP <= iCalculateDamage) {//This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 11530, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);

}}}}
								   if (m_ID == 2002 && Config.Visual.MoskovTriggerLord || AutoSteallA) {		
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
        if (CurHP <= iCalculateDamage) {
        //if (CurHP <= iCalculateDamage) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 3130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                
}}}}
								   if (m_ID == 2002 && Config.Visual.BeatrixTriggerLord || AutoSteallA) {	
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
        if (CurHP <= iCalculateDamage) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 2010530, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
}}}}   
                                   if (m_ID == 2002 && Config.Visual.BalmondTriggerLord || AutoSteallA) {	
								  // if (Config.Visual.BalmondTriggerLord) {
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
        if (CurHP <= iCalculateDamage) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 230, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
}}}}
                                   if (m_ID == 2002 && Config.Visual.YveTriggerLord ) {
                                  // if (Config.Visual.YveTriggerLord) {
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
        if (CurHP <= iCalculateDamage) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
}}}}
                                    if (m_ID == 2002 && Config.Visual.PapuquitoTriggerLord) {
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
        if (CurHP <= 5840) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 10300, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10320, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10330, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10300, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
	    orig_TryUseSkill(thiz, 10320, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
	    orig_TryUseSkill(thiz, 10300, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
        orig_TryUseSkill(thiz, 10320, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10310, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10330, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
						             if (m_ID == 2002 && Config.Visual.GusionTriggerLord) {		   
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
        if (CurHP <= iCalculateDamage) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 5610, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 5620, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 5630, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 5610, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
	    orig_TryUseSkill(thiz, 5620, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
						              if (m_ID == 2003 && Config.Visual.GrangerTriggerTurtle) {		
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
                                    if (CurHP <= iCalculateDamage) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 7930, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
								   if (m_ID == 2003 && Config.Visual.LaylaTriggerTurtle || AutoSteallP) {		
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
                                    if (CurHP <= iCalculateDamage) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 1830, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);

}}}}
								   if (m_ID == 2003 && Config.Visual.PharsaTriggerTurtle || AutoSteallP) {		
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
                                    if (CurHP <= iCalculateDamage) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
orig_TryUseSkill(thiz, 5230, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);

}}}}
								   if (m_ID == 2003 && Config.Visual.XavierTriggerTurtle || AutoSteallP) {		
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
        if (CurHP <= iCalculateDamage) {//This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 11530, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);

}}}}
								   if (m_ID == 2003 && Config.Visual.MoskovTriggerTurtle || AutoSteallP) {		
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
        if (CurHP <= iCalculateDamage) {
        //if (CurHP <= iCalculateDamage) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 3130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                
}}}}
								   if (m_ID == 2003 && Config.Visual.BeatrixTriggerTurtle || AutoSteallP) {	
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
        if (CurHP <= iCalculateDamage) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 2010530, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
}}}}   
                                   if (m_ID == 2003 && Config.Visual.BalmondTriggerTurtle || AutoSteallP) {	
								  // if (Config.Visual.BalmondTriggerLord) {
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
        if (CurHP <= iCalculateDamage) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 230, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
}}}}
                                   if (m_ID == 2003 && Config.Visual.YveTriggerLord) {
                                  // if (Config.Visual.YveTriggerLord) {
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
        if (CurHP <= iCalculateDamage) { //This CurHp1 Means The Buff Hp Is It Accurate 
      if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
}}}}
                                    if (m_ID == 2003 && Config.Visual.PapuquitoTriggerTurtle) {
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
        if (CurHP <= 5840) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 10300, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10320, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10330, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10300, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
	    orig_TryUseSkill(thiz, 10320, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
	    orig_TryUseSkill(thiz, 10300, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
        orig_TryUseSkill(thiz, 10320, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10310, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 10330, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
						             if (m_ID == 2003 && Config.Visual.GusionTriggerTurtle) {		   
        if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
        if (CurHP <= iCalculateDamage) {
        if (_Position - selfPos != Vector3::zero()) {
        orig_TryUseSkill(thiz, 5610, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 5620, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 5630, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
		orig_TryUseSkill(thiz, 5610, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
	    orig_TryUseSkill(thiz, 5620, Vector3::Normalized(_Position - selfPos), true, _Position, false, true);
                        }}}}
                                if (Distance < 5.4f && Distance2 < 10 && CurHP < MaxHP) {
                                    if (CurHP <= iCalculateDamage) {
                                        if (m_ID == 2004 && Aim.Helper.AutoRetribution.Buff2 /*Red Buff*/ || m_ID == 2005 && Aim.Helper.AutoRetribution.Buff2 /*Blue Buff*/ || m_ID == 2004 && Aim.Helper.AutoRetribution.All || m_ID == 2005 && Aim.Helper.AutoRetribution.All || m_ID == 2002 && Aim.Helper.AutoRetribution.Lord2 /*Lord*/ || m_ID == 2011 && Aim.Helper.AutoRetribution.Crab2 || m_ID == 2003 && Aim.Helper.AutoRetribution.Turtle2 || m_ID == 2072 && Aim.Helper.AutoRetribution.Lito2 /*Lito*/|| m_ID == 2056 && Aim.Helper.AutoRetribution.Lito2 /*Lito*/ || Aim.Helper.AutoRetribution.Rockursa2 /*Rockursa*/ || m_ID == 2006 && Aim.Helper.AutoRetribution.Scaled2 /*Scaled*/ ) {
                                            if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                                orig_TryUseSkill(thiz, 20020, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                                            }
                                          }
                                       }
								   }
							    }
						    }                                                        
                        }
                    }
                }
            }
        }
    }
    orig_UpdateRetribution(thiz);
}
