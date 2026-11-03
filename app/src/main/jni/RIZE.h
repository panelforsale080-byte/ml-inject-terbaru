#pragma once

#include "Includes/obfuscate.h"
#include "OfficialRIZEYT/Call_Me.h"
#include "RIZEYT.h"
bool mvp = false;

bool show_another_esp = false;
bool show_another_bt = false;
bool show_another_demon = false;
bool show_another_hack = true;
bool show_another_bypass = false;
bool show_another_kontol = false;

void SetStyle() {
    ImGuiStyle& style = ImGui::GetStyle();
    
    style.WindowRounding = 5.3f;
    style.FrameRounding = 2.3f;
    style.ScrollbarRounding = 0;
    style.FramePadding = ImVec2(8, 6);
    style.ScaleAllSizes(2.0f);
    style.ScrollbarSize /= 1;
    
        style.Colors[ImGuiCol_Text] = ImColor(240, 240, 240, 255);
        style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.36f, 0.42f, 0.47f, 1.00f);
        style.Colors[ImGuiCol_WindowBg] = ImColor(29, 34, 38, 255);
        style.Colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
        style.Colors[ImGuiCol_Border] = ImColor(198, 147, 37, 255);
        style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        style.Colors[ImGuiCol_FrameBg] = ImColor(40, 50, 60, 255);
        style.Colors[ImGuiCol_FrameBgHovered] = ImColor(40, 50, 60, 255);
        style.Colors[ImGuiCol_FrameBgActive] = ImColor(40, 50, 60, 255);
        style.Colors[ImGuiCol_TitleBg] = ImColor(0, 0, 0, 155);
        style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(0, 0, 0, 155);
        style.Colors[ImGuiCol_TitleBgActive] = ImColor(0, 0, 0, 155);
        style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.39f);
        style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.18f, 0.22f, 0.25f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.09f, 0.21f, 0.31f, 1.00f);
        style.Colors[ImGuiCol_CheckMark] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
        style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
        style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
        style.Colors[ImGuiCol_Button] = ImColor(51, 64, 73, 255);
        style.Colors[ImGuiCol_ButtonHovered] = ImColor(51, 64, 73, 255);
        style.Colors[ImGuiCol_ButtonActive] = ImColor(51, 64, 73, 255);
        style.Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.15f, 0.19f, 0.55f);
        style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.16f, 0.19f, 0.15f, 1.00f);
        style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.16f, 0.19f, 0.15f, 1.00f);
        style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
        style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
        style.Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
        style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
        style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
        style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
		style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
    
}

void SetupImgui() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    
    ImGui::StyleColorsClassic();
    
    ImGui_ImplAndroid_Init();
    ImGui_ImplOpenGL3_Init(OBFUSCATE("#version 300 es"));
    
    ImGuiIO* io = &ImGui::GetIO();
    io->ConfigWindowsMoveFromTitleBarOnly = true;
    io->IniFilename = NULL;
    
    static const ImWchar icons_ranges[] = {0x0020, 0x00FF, 0x3000, 0x30FF, 0x31F0, 0x31FF, 0xFF00, 0xFFEF, 0x4e00, 0x9FAF, 0};
    
    ImFontConfig icons_config;
    
    ImFontConfig CustomFont;
    CustomFont.FontDataOwnedByAtlas = false;
    
    icons_config.MergeMode = true;
    icons_config.PixelSnapH = true;
    icons_config.OversampleH = 2.5;
    icons_config.OversampleV = 2.5;
    
    io->Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 21.f, &CustomFont);
    io->Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 19.0f, &icons_config, icons_ranges);
    
    ImFontConfig font_cfg;
    font_cfg.SizePixels = 23.0f;
    io->Fonts->AddFontDefault(&font_cfg);
}

    
       
    

//MenuSafe
void DrawMenuSafe() {
            if (ImGui::BeginTabBar("Tab", ImGuiTabBarFlags_FittingPolicyScroll)) {
            if (ImGui::BeginTabItem(OBFUSCATE("Bypass Menu"))) {
         bool show_another_kontol = false;
            ImGui::BeginGroupPanel(OBFUSCATE("Use While on The Loby To Avoid Banned!!"), ImVec2(0.0f, 0.0f));
			ImGui::Checkbox(OBFUSCATE("Click To Fix Drop Jaringan"), &DropJaringan);
			ImGui::Checkbox(OBFUSCATE("Click To Fix Drop FPS"), &DropFPS);
			ImGui::Checkbox(OBFUSCATE("Click To Fix Freeze/Stuck"), &StuckGoblok);
			ImGui::Checkbox(OBFUSCATE("Click To Fix Server Cheat"), &Goblok);
            ImGui::Checkbox(OBFUSCATE("Server Bypass"), &ServerBypass);  
            ImGui::Checkbox(OBFUSCATE("Block Report"), &BlockReport);
            ImGui::Checkbox(OBFUSCATE("Block Banned"), &BlockBanned);
            ImGui::Checkbox(OBFUSCATE("Bypass+++"), &Bypass);
            ImGui::Spacing();
            ImGui::EndGroupPanel();
           
            ImGui::Spacing();
            ImGui::EndTabItem();
            }
            
          if (ImGui::BeginTabItem(OBFUSCATE("Special Menu"))) {
		  bool show_another_kontol = false;
            ImGui::BeginGroupPanel(OBFUSCATE("Damage Physical"), ImVec2(0.0f, 0.0f));
            ImGui::Checkbox(OBFUSCATE("Damage Physical Up (+5%)"), &damage);  
            ImGui::Checkbox(OBFUSCATE("Damage Physical Up (+15%)"), &damage); 
            ImGui::Checkbox(OBFUSCATE("Damage Physical Up (+25%)"), &damage); 
            ImGui::Checkbox(OBFUSCATE("Damage Physical Up (+35%)"), &damage); 
            ImGui::Spacing();
            ImGui::EndGroupPanel();
            
            ImGui::SameLine();
            
            ImGui::BeginGroupPanel(OBFUSCATE("Damage Magical"), ImVec2(0.0f, 0.0f));
            ImGui::Checkbox(OBFUSCATE("Damage Magical Up (+5%)"), &damage);  
            ImGui::Checkbox(OBFUSCATE("Damage Magical Up (+15%)"), &damage); 
            ImGui::Checkbox(OBFUSCATE("Damage Magical Up (+25%)"), &damage); 
            ImGui::Checkbox(OBFUSCATE("Damage Magical Up (+35%)"), &damage); 
            ImGui::Spacing();
            ImGui::EndGroupPanel();
            
            ImGui::BeginGroupPanel(OBFUSCATE("Defence Physical"), ImVec2(0.0f, 0.0f));
            ImGui::Checkbox(OBFUSCATE("Defence Physical Up (+5%)"), &damage);  
            ImGui::Checkbox(OBFUSCATE("Defence Physical Up (+15%)"), &damage); 
            ImGui::Checkbox(OBFUSCATE("Defence Physical Up (+25%)"), &damage); 
            ImGui::Checkbox(OBFUSCATE("Defence Physical Up (+35%)"), &damage); 
            ImGui::Spacing();
            ImGui::EndGroupPanel();
            
            ImGui::SameLine();
            
            ImGui::BeginGroupPanel(OBFUSCATE("Defence Magical"), ImVec2(0.0f, 0.0f));
            ImGui::Checkbox(OBFUSCATE("Defence Magical Up (+5%)"), &damage);  
            ImGui::Checkbox(OBFUSCATE("Defence Magical Up (+15%)"), &damage); 
            ImGui::Checkbox(OBFUSCATE("Defence Magical Up (+25%)"), &damage); 
            ImGui::Checkbox(OBFUSCATE("Defence Magical Up (+35%)"), &damage); 
            ImGui::Spacing();
            ImGui::EndGroupPanel();
            
            ImGui::Spacing();
            ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem(OBFUSCATE("ESP Menu"))) {
             bool show_another_kontol = false;
            ImGui::BeginGroupPanel(OBFUSCATE("Visual Menu, ESP, Drone"), ImVec2(0.0f, 0.0f));            
            ImGui::BeginGroupPanel(OBFUSCATE("Player ESP"), ImVec2(0.0f, 0.0f));
			
			ImGui::Checkbox(OBFUSCATE("OnAllEsp"), &OnAllEsp);
			ImGui::Checkbox(OBFUSCATE("Line"), &Config.ESP.Player.Line);
		    ImGui::Checkbox(OBFUSCATE("Box"), &Config.ESP.Player.Box);
		    ImGui::Checkbox(OBFUSCATE("Health"), &Config.ESP.Player.Health);
		    ImGui::Checkbox(OBFUSCATE("Name"), &Config.ESP.Player.Name);
   		    ImGui::Checkbox(OBFUSCATE("Distance"), &Config.ESP.Player.Distance);
		    ImGui::Checkbox(OBFUSCATE("Hero"), &Config.ESP.Player.Hero);
		    ImGui::Checkbox(OBFUSCATE("Alert"), &Config.ESP.Player.Alert);
	        ImGui::Checkbox(OBFUSCATE("Visible Check"), &Config.ESP.Player.Visible);
			ImGui::Checkbox(OBFUSCATE("CoolDown"), &Config.ESP.Player.CoolDown);     
	        ImGui::Spacing();
            ImGui::EndGroupPanel();
            
            ImGui::SameLine();
            
            ImGui::BeginGroupPanel(OBFUSCATE("Aditional"), ImVec2(0.0f, 0.0f));
            
            ImGui::BeginGroupPanel(OBFUSCATE("Monster ESP"), ImVec2(0.0f, 0.0f));
            ImGui::Checkbox(OBFUSCATE("Show Jungle"), &showjungle);
            ImGui::Checkbox(OBFUSCATE("Monster Box"), &Config.ESP.Monster.Box);
		    ImGui::Checkbox(OBFUSCATE("Monster Health"), &Config.ESP.Monster.Health);
		    ImGui::Checkbox(OBFUSCATE("Monster Name"), &Config.ESP.Monster.Name);
		    ImGui::Checkbox(OBFUSCATE("Monster Alert"), &Config.ESP.Monster.Alert);
		    ImGui::Spacing();
		    ImGui::EndGroupPanel();
		    
		ImGui::BeginGroupPanel(OBFUSCATE("Colors"), ImVec2(0.0f, 0.0f));
           ImGui::Text(OBFUSCATE("Choose Themes"));
                   static int e = -1;
                   ImGui::RadioButton(OBFUSCATE("Classic"), &e, 0);
                   ImGui::SameLine();
                   ImGui::RadioButton(OBFUSCATE("Drak"), &e, 1);
                   ImGui::SameLine();
                   ImGui::RadioButton(OBFUSCATE("Light"), &e, 2);
                   switch (e) {
                   case 0:
                   ImGui::StyleColorsClassic();
                   break;
                   case 1:
                   ImGui::StyleColorsDark();
                   break;
                   case 2:
                   ImGui::StyleColorsLight();
                   break;
        }
       /*ImGui::ColorEdit4("Text COLOR", Config.ColorsESP.Text);
       ImGui::PushStyleColor(ImGuiCol_Text,ToColor(Config.ColorsESP.Text));*/

                
		    ImGui::BeginGroupPanel(OBFUSCATE("Show Menu"), ImVec2(0.0f, 0.0f));
		    ImGui::Checkbox(OBFUSCATE("Show Icon Minimap"), &Config.Visual.MaphackIcon);	
		    ImGui::Checkbox(OBFUSCATE("Show HealthBar"), &Config.Visual.HealthBar);	
            ImGui::Text(OBFUSCATE("Drone View:"));
		    ImGui::SliderFloat(OBFUSCATE("##DroneView"), &SetFieldOfView, 0, 30, "%.1f");
		    ImGui::Spacing();
		    ImGui::EndGroupPanel;
		    
		    ImGui::Spacing();
		    ImGui::EndGroupPanel();
		    
		    ImGui::Spacing();
            ImGui::EndGroupPanel();
            
		    ImGui::Spacing();
		    ImGui::EndGroupPanel();
		    ImGui::EndTabItem();
		    }
         
         
         
         
                
            if (ImGui::BeginTabItem(OBFUSCATE("Aim Menu"))) {
           bool show_another_kontol = false;

            ImGui::BeginGroupPanel(OBFUSCATE("Aim Skill & Priority"), ImVec2(0.0f, 0.0f));
            
            ImGui::BeginGroupPanel(OBFUSCATE("Aim Skill"), ImVec2(0.0f, 0.0f));
            ImGui::Checkbox(OBFUSCATE("Skill 1"), &Aim.Helper.Skills.Skill1);
		    ImGui::Checkbox(OBFUSCATE("Skill 2"), &Aim.Helper.Skills.Skill2);
		    ImGui::Checkbox(OBFUSCATE("Skill 3"), &Aim.Helper.Skills.Skill3);
		    ImGui::Checkbox(OBFUSCATE("Skill 4"), &Aim.Helper.Skills.Skill4);
		    ImGui::Checkbox(OBFUSCATE("Basic Attack"), &Aim.Helper.Skills.Basic);
	  	    ImGui::Checkbox(OBFUSCATE("Spell"), &Aim.Helper.Skills.Spell);
	  	    ImGui::Spacing();
	  	    ImGui::EndGroupPanel();
	  	    
	  	    ImGui::SameLine();
	  	    
	  	    ImGui::BeginGroupPanel(OBFUSCATE("Priority"), ImVec2(0.0f, 0.0f));
	  	    ImGui::Text(OBFUSCATE("TargetAim: "));
		    static const char *targets[] = {"Distance", "LowHP", "LowHPPercent"};
            ImGui::Combo(OBFUSCATE("##Target"), (int *) &Aim.Helper.TargetPriority, targets, 3, -1);
		    ImGui::Text(OBFUSCATE("RangeAim:"));
		    ImGui::SliderFloat(OBFUSCATE("##RangeFOV"), &RangeFOV, 0, 150, "%.1fm");
		    ImGui::Text(OBFUSCATE("Dist Combo:"));
            ImGui::SliderFloat(OBFUSCATE("##DistCombo"), &DistCombo, 0, 10, "%.1fm");
            ImGui::Spacing();
            ImGui::EndGroupPanel();
            
            ImGui::Spacing();
            ImGui::EndGroupPanel();
            
            ImGui::BeginGroupPanel(OBFUSCATE("Special Hero Auto Skill"), ImVec2(0.0f, 0.0f));
	  	    ImGui::Checkbox(OBFUSCATE("Manual Tap Sword (Ling)"), &Aim.Helper.Priority.AutoTakeSword);
		    ImGui::Checkbox(OBFUSCATE("Auto Tap Sword (Ling)"), &AutoLing);
		    ImGui::Checkbox(OBFUSCATE("Auto Sword (Kimmy)"), &AutoSword.Kimmy);
			//ImGui::Checkbox(OBFUSCATE("Auto Sword (Kimmy V2)"), &AutoSword.Kimmy2);
		    ImGui::Checkbox(OBFUSCATE("Auto Sword (WanWan)"), &AutoSword.WanWan);	 
		    ImGui::Checkbox(OBFUSCATE("Auto Sword (Iritel)"), &AutoSword.Iritel);
			ImGui::Checkbox(OBFUSCATE("Auto Sword (Eudora)"), &Config.Visual.Eudora22);
			ImGui::Spacing();
		    ImGui::EndGroupPanel();
			
			ImGui::SameLine();
			
			ImGui::BeginGroupPanel(OBFUSCATE("V3"), ImVec2(0.0f, 0.0f));
			ImGui::Checkbox(OBFUSCATE("Combo Pharsa"), &Config.Visual.Pharsa);
			ImGui::Checkbox(OBFUSCATE("Combo Kagura"), &Config.Visual.Kagura);
			ImGui::Checkbox(OBFUSCATE("Combo Kagura (Automatic)"), &Config.Visual.Kagura2);
			ImGui::Checkbox(OBFUSCATE("Combo Vale"), &Config.Visual.Vale);
			ImGui::Checkbox(OBFUSCATE("Combo Freya"), &Config.Visual.Freya);
	        ImGui::Checkbox(OBFUSCATE("Combo Ruby"), &Config.Visual.Ruby);
			ImGui::Spacing();
		    ImGui::EndGroupPanel();
			
			
		    
		    ImGui::SameLine();
			ImGui::BeginGroupPanel(OBFUSCATE("V4"), ImVec2(0.0f, 0.0f));
			ImGui::Checkbox(OBFUSCATE("Combo Edith"), &Config.Visual.Edith2);
			ImGui::Checkbox(OBFUSCATE("Combo Franco"), &Config.Visual.Franco);
			ImGui::Checkbox(OBFUSCATE("Combo Yu Zhong"), &Config.Visual.Dragons);
			ImGui::Checkbox(OBFUSCATE("Combo Xevana"), &Config.Visual.Xevana);
			ImGui::Checkbox(OBFUSCATE("Combo Freya (Automatic)"), &Config.Visual.Freya2);
			ImGui::Checkbox(OBFUSCATE("Combo Hayabusa"), &Config.Visual.Hayabusa);
			//ImGui::Checkbox(OBFUSCATE("Combo Hanzo"), &Config.Visual.Hanzo);
			ImGui::Spacing();
		    ImGui::EndGroupPanel();
			
			
		    
		    ImGui::SameLine();
			 ImGui::BeginGroupPanel("Auto Battle Spell", ImVec2(0.0f, 0.0f));
			 ImGui::Checkbox(OBFUSCATE("Auto Sprint"), &Sprint);
			 ImGui::Checkbox(OBFUSCATE("Auto Fliker"), &Fliker);
            ImGui::Checkbox(OBFUSCATE("Auto Execute"), &Execute);
		    ImGui::Checkbox(OBFUSCATE("Auto FlameShot"), &FlameShot);
	    	ImGui::Checkbox(OBFUSCATE("Auto Aegis"), &Aegis);
		    ImGui::Checkbox(OBFUSCATE("Auto Revitalize"), &Revitalize);
	    	ImGui::Spacing();
		    ImGui::EndGroupPanel();
		    
            ImGui::EndTabItem();
		    }
				
            if (ImGui::BeginTabItem(OBFUSCATE("Retribution Menu"))) {
bool show_another_kontol = false;
            ImGui::BeginGroupPanel(OBFUSCATE("Auto Retribution"), ImVec2(0.0f, 0.0f));
		   
            ImGui::Checkbox(OBFUSCATE("Reti Buff"), &Aim.Helper.AutoRetribution.Buff);
	        ImGui::Checkbox(OBFUSCATE("Retri Turtle"), &Aim.Helper.AutoRetribution.Turtle);		  
		    ImGui::Checkbox(OBFUSCATE("Retri Lord"), &Aim.Helper.AutoRetribution.Lord);	  
    	    ImGui::Checkbox(OBFUSCATE("Retri Litho"), &Aim.Helper.AutoRetribution.Lito);
		    ImGui::Checkbox(OBFUSCATE("Retri Crab"), &Aim.Helper.AutoRetribution.Crab);	
			ImGui::Checkbox(OBFUSCATE("Retri Rockursa"), &Aim.Helper.AutoRetribution.Rockursa);
			ImGui::Checkbox(OBFUSCATE("Retri Scaled"), &Aim.Helper.AutoRetribution.Scaled);
		    ImGui::Spacing();
		    ImGui::EndGroupPanel();
			
			ImGui::SameLine();
			ImGui::BeginGroupPanel(OBFUSCATE("Auto Retribution (Trigger)"), ImVec2(0.0f, 0.0f));
            ImGui::Checkbox(OBFUSCATE("Reti Buff (Trigger)"), &Aim.Helper.AutoRetribution.Buff2);
	        ImGui::Checkbox(OBFUSCATE("Retri Turtle (Trigger)"), &Aim.Helper.AutoRetribution.Turtle2);
		    ImGui::Checkbox(OBFUSCATE("Retri Lord (Trigger)"), &Aim.Helper.AutoRetribution.Lord2);
		    ImGui::Checkbox(OBFUSCATE("Retri Litho (Trigger)"), &Aim.Helper.AutoRetribution.Lito2);
		    ImGui::Checkbox(OBFUSCATE("Retri Crab (Trigger)"), &Aim.Helper.AutoRetribution.Crab2);	
			ImGui::Checkbox(OBFUSCATE("Retri Rockursa (Trigger)"), &Aim.Helper.AutoRetribution.Rockursa2);
			ImGui::Checkbox(OBFUSCATE("Retri Scaled (Trigger)"), &Aim.Helper.AutoRetribution.Scaled2);
		    ImGui::Spacing();
		    ImGui::EndGroupPanel();
			
			
		    
			ImGui::EndTabItem();
		    }
		    if (ImGui::BeginTabItem(OBFUSCATE("Auto Menu"))) {
         bool show_another_kontol = false;
            ImGui::BeginGroupPanel(OBFUSCATE("Auto Combo & Ulti Hero"), ImVec2(0.0f, 0.0f));
            
            ImGui::BeginGroupPanel("*", ImVec2(0.0f, 0.0f));
            ImGui::Checkbox(OBFUSCATE("Combo Gusion"), &Config.Visual.ComboGS);
			ImGui::Checkbox(OBFUSCATE("Combo Gusion (V2)"), &Config.Visual.Gusion2);
		    ImGui::Checkbox(OBFUSCATE("Balmond Ulti (Manual)"), &Config.Visual.Balmond);	
			ImGui::Checkbox(OBFUSCATE("Balmond Ulti (Automatic)"), &Config.Visual.Balmond222);
	    	ImGui::Checkbox(OBFUSCATE("Martis Ulti (Manual)"), &Config.Visual.Martis);
			ImGui::Checkbox(OBFUSCATE("Martis Ulti (Automatic)"), &Config.Visual.Martis222);
			ImGui::Checkbox(OBFUSCATE("Fredrinn Ulti (Manual)"), &Config.Visual.Freedrin2);
			ImGui::Checkbox(OBFUSCATE("Fredrinn Ulti (Automatic)"), &Config.Visual.Freedrin);
			ImGui::Checkbox(OBFUSCATE("Dyrroth Ulti (Manual)"), &Config.Visual.Dyrroth2);
			ImGui::Checkbox(OBFUSCATE("Dyrroth Ulti (Automatic)"), &Config.Visual.Dyrroth);
			ImGui::Checkbox(OBFUSCATE("Hilda Ulti (Manual)"), &Config.Visual.Hilda2);
			ImGui::Checkbox(OBFUSCATE("Hilda Ulti (Automatic)"), &Config.Visual.Hilda);
			ImGui::Checkbox(OBFUSCATE("Granger Ulti (Manual)"), &Config.Visual.Granger);
			ImGui::Checkbox(OBFUSCATE("Granger Ulti (Automatic"), &Config.Visual.Granger3);
		    ImGui::Checkbox(OBFUSCATE("Yin Ulti (Low Hp)(Manual)"), &Config.Visual.YinUlti);
			ImGui::Checkbox(OBFUSCATE("Yin Ulti (Standar Hp)(Manual)"), &Config.Visual.YinUlti2);
			ImGui::Checkbox(OBFUSCATE("Yin Ulti (Full Hp)(Manual)"), &Config.Visual.YinUlti3);
			ImGui::Checkbox(OBFUSCATE("Yin Ulti (Low Hp)(Automatic)"), &Config.Visual.YinUlti4);
			ImGui::Checkbox(OBFUSCATE("Yin Ulti (Standar Hp)(Automatic)"), &Config.Visual.YinUlti5);
			ImGui::Checkbox(OBFUSCATE("Yin Ulti (Full Hp)(Automatic)"), &Config.Visual.YinUlti6);
			ImGui::Checkbox(OBFUSCATE("Argus Ulti (Manual)"), &Config.Visual.Argus);
			ImGui::Checkbox(OBFUSCATE("Argus Ulti (Automatic)"), &Config.Visual.Argus2);
			ImGui::Checkbox(OBFUSCATE("Beatrix Ulti"), &Config.Visual.BeatrixUlti);
            
	    	ImGui::Spacing();
	    	ImGui::EndGroupPanel();
	    	
	    	ImGui:: SameLine();
	    	
	    	
			ImGui::BeginGroupPanel("*", ImVec2(0.0f, 0.0f));
			//ImGui::Checkbox(OBFUSCATE("Combo Xavier1+2"), &Config.Visual.ComboXavier12);	
			ImGui::Checkbox(OBFUSCATE("Xavier1+2"), &Config.Visual.ComboXavier122);
			//ImGui::Checkbox(OBFUSCATE("Combo Xavier1+2 (Automatic)"), &Config.Visual.ComboXavierAutomatic);
		    ImGui::Checkbox(OBFUSCATE("Xavier2+1"), &Config.Visual.ComboXavier21);
		//	ImGui::Checkbox(OBFUSCATE("Combo Xavier2+1 (V2)"), &Config.Visual.ComboXavier221);
			//ImGui::Checkbox(OBFUSCATE("Combo Xavier2+1 (Automatic)"), &Config.Visual.ComboXavierAutomatic2);
			
		    ImGui::Spacing();
		    ImGui::EndGroupPanel();
		    
			ImGui:: SameLine();
			ImGui::BeginGroupPanel("*", ImVec2(0.0f, 0.0f));
			//ImGui::Checkbox(OBFUSCATE("Selena 2+1"), &Config.Visual.Selena);
			
			ImGui::Checkbox(OBFUSCATE("Selena 1+2"), &Config.Visual.Selena2);
			ImGui::Checkbox(OBFUSCATE("Selena 2+1"), &Config.Visual.Selena);
			
			//ImGui::Checkbox(OBFUSCATE("Combo Vale (V2)"), &Config.Visual.Vale2);
			
			//ImGui::Checkbox(OBFUSCATE("Combo Freya (Automatic)"), &Config.Visual.Freya2);
			//ImGui::Checkbox(OBFUSCATE("Combo Yve"), &Config.Visual.Yve2233);
		    ImGui::Spacing();
		    ImGui::EndGroupPanel();
			
			ImGui:: SameLine();
			ImGui::BeginGroupPanel("*", ImVec2(0.0f, 0.0f));
			//ImGui::Checkbox(OBFUSCATE("Selena 2+1"), &Config.Visual.Selena);
			
			ImGui::Checkbox(OBFUSCATE("Xevana 1+2"), &Config.Visual.Xevana2);
			ImGui::Checkbox(OBFUSCATE("Xevana 2+1"), &Config.Visual.Xevana);
			
			//ImGui::Checkbox(OBFUSCATE("Combo Vale (V2)"), &Config.Visual.Vale2);
			
			//ImGui::Checkbox(OBFUSCATE("Combo Freya (Automatic)"), &Config.Visual.Freya2);
			//ImGui::Checkbox(OBFUSCATE("Combo Yve"), &Config.Visual.Yve2233);
		    ImGui::Spacing();
		    ImGui::EndGroupPanel();
			
			ImGui:: SameLine();
			ImGui::BeginGroupPanel("*", ImVec2(0.0f, 0.0f));
			ImGui::Checkbox(OBFUSCATE("Lylia 1+2"), &Config.Visual.Lylia2);
			ImGui::Checkbox(OBFUSCATE("Lylia 2+1"), &Config.Visual.Lylia);
			ImGui::Spacing();
		    ImGui::EndGroupPanel();
			
			
            ImGui::BeginGroupPanel("*", ImVec2(0.0f, 0.0f));
			ImGui::Checkbox(OBFUSCATE("Esmeralda 1+2"), &Config.Visual.Esmeralda);
			ImGui::Checkbox(OBFUSCATE("Esmeralda 2+1"), &Config.Visual.Esmeralda2);
			ImGui::Spacing();
		    ImGui::EndGroupPanel();
		
			ImGui:: SameLine();
			ImGui::BeginGroupPanel("*", ImVec2(0.0f, 0.0f));
			ImGui::Checkbox(OBFUSCATE("Helcurt 2+3"), &Config.Visual.Helcurt);
			ImGui::Checkbox(OBFUSCATE("Harley 2+3"), &Config.Visual.Harley);
			ImGui::Spacing();
		    ImGui::EndGroupPanel();
			
			ImGui::EndGroupPanel();
			/*ImGui::BeginGroupPanel("*", ImVec2(0.0f, 0.0f));
			ImGui::Checkbox(OBFUSCATE("Selena 1+2"), &Config.Visual.Selena2);
			ImGui::Checkbox(OBFUSCATE("Selena 2+1"), &Config.Visual.Selena);
			ImGui::Spacing();
		    ImGui::EndGroupPanel();
			ImGui:: SameLine();
			ImGui::BeginGroupPanel("*", ImVec2(0.0f, 0.0f));
			ImGui::Checkbox(OBFUSCATE("Lylia 1+2"), &Config.Visual.Lylia2);
			ImGui::Checkbox(OBFUSCATE("Lylia 2+1"), &Config.Visual.Lylia);
			ImGui::Spacing();
		    ImGui::EndGroupPanel();
			ImGui:: SameLine();
			ImGui::BeginGroupPanel("*", ImVec2(0.0f, 0.0f));
			ImGui::Checkbox(OBFUSCATE("Pharsa"), &Config.Visual.Pharsa);
ImGui::Spacing();
		    ImGui::EndGroupPanel();
			ImGui:: SameLine();
ImGui::BeginGroupPanel("*", ImVec2(0.0f, 0.0f));
			ImGui::Checkbox(OBFUSCATE("Chou"), &Config.Visual.Chou2);
			ImGui::BeginGroupPanel("*", ImVec2(0.0f, 0.0f));
			ImGui::Checkbox(OBFUSCATE("Franco"), &Config.Visual.Franco);
		    ImGui::Spacing();
		    ImGui::EndGroupPanel();
			ImGui:: SameLine();
			ImGui::BeginGroupPanel("*", ImVec2(0.0f, 0.0f));
			ImGui::Checkbox(OBFUSCATE("Eudora"), &Config.Visual.Eudora22);
		    
		    ImGui::EndGroupPanel();*/
			
			
			
			
		    
		    
		    
		    ImGui::BeginGroupPanel("Autto Skill", ImVec2(0.0f, 0.0f));
		    
		    ImGui::BeginGroupPanel("*", ImVec2(0.0f, 0.0f));
		    ImGui::Checkbox(OBFUSCATE("Combo Skill1"), &Config.Visual.ComboSkill1);
		    ImGui::Checkbox(OBFUSCATE("Combo Skill2"), &Config.Visual.ComboSkill2);
		    ImGui::Checkbox(OBFUSCATE("Combo Skill3"), &Config.Visual.ComboSkill3);
		    ImGui::Checkbox(OBFUSCATE("Combo Skill4"), &Config.Visual.ComboSkill4);
		    ImGui::Spacing();
		    ImGui::EndGroupPanel();
		    
		    ImGui::SameLine();
		    
		    ImGui::BeginGroupPanel("*", ImVec2(0.0f, 0.0f));
		    ImGui::Checkbox(OBFUSCATE("Combo Skill21"), &Config.Visual.ComboSkill21);
		    ImGui::Checkbox(OBFUSCATE("Combo Skill31"), &Config.Visual.ComboSkill31);
		    ImGui::Checkbox(OBFUSCATE("Combo Skill32"), &Config.Visual.ComboSkill32);
		    ImGui::Checkbox(OBFUSCATE("Combo Skill321"), &Config.Visual.ComboSkill321);
		    ImGui::Spacing();
		    ImGui::EndGroupPanel();
		    
		    ImGui::SameLine();
		  
		    ImGui::BeginGroupPanel("*", ImVec2(0.0f, 0.0f));
	   	    ImGui::Checkbox(OBFUSCATE("Combo Skill1+Flicker"), &Config.Visual.Skill1Flicker);	
		    ImGui::Checkbox(OBFUSCATE("Combo Skill2+Flicker"), &Config.Visual.Skill2Flicker);	
		    ImGui::Checkbox(OBFUSCATE("Combo Ulti+Flicker"), &Config.Visual.UltiFlicker);		
		    ImGui::Checkbox(OBFUSCATE("Combo Skill4+Flicker"), &Config.Visual.Skill4Flicker);
		    ImGui::Spacing();
		    ImGui::EndGroupPanel();
		    
			ImGui::EndTabItem();
		    }
		    
		    if (ImGui::BeginTabItem(OBFUSCATE("Auto Steal"))) {
		   ImGui::BeginGroupPanel("Auto Steal", ImVec2(0.0f, 0.0f));
			ImGui::Checkbox(OBFUSCATE("Auto Steal Granger"), &Config.Visual.Granger2);
			ImGui::Checkbox(OBFUSCATE("Auto Steal Layla"), &Config.Visual.Layla2);
			ImGui::Checkbox(OBFUSCATE("Auto Steal Xavier"), &Config.Visual.Xavier223);
			ImGui::Checkbox(OBFUSCATE("Auto Steal Moskov"), &Config.Visual.Moskov2);
			ImGui::Checkbox(OBFUSCATE("Auto Steal Balmond"), &Config.Visual.Balmond2);
			ImGui::Checkbox(OBFUSCATE("Auto Steal Beatrix"), &Config.Visual.Beatrix3);
			ImGui::Checkbox(OBFUSCATE("Auto Steal Pharsa"), &Config.Visual.Pharsa3);
			ImGui::Checkbox(OBFUSCATE("Auto Steal Gusion"), &Config.Visual.Gusion3);
			ImGui::Checkbox(OBFUSCATE("Auto Steal Papuquito"), &Config.Visual.Papuquito3);
	        ImGui::Checkbox(OBFUSCATE("Auto Steal Yve"), &Config.Visual.Yve3);
		    ImGui::Spacing();
		    ImGui::EndGroupPanel();
			
			ImGui:: SameLine();
			
			ImGui::BeginGroupPanel("Auto Steal (Trigger)", ImVec2(0.0f, 0.0f));
			ImGui::Checkbox(OBFUSCATE("Auto Steal Granger (Trigger)"), &Config.Visual.GrangerTrigger);
			ImGui::Checkbox(OBFUSCATE("Auto Steal Layla (Trigger)"), &Config.Visual.LaylaTrigger);
			ImGui::Checkbox(OBFUSCATE("Auto Steal Xavier (Trigger)"), &Config.Visual.XavierTrigger);
			ImGui::Checkbox(OBFUSCATE("Auto Steal Moskov (Trigger)"), &Config.Visual.MoskovTrigger);
			ImGui::Checkbox(OBFUSCATE("Auto Steal Balmond (Trigger)"), &Config.Visual.BalmondTrigger);
			ImGui::Checkbox(OBFUSCATE("Auto Steal Beatrix (Trigger)"), &Config.Visual.BeatrixTrigger);
			ImGui::Checkbox(OBFUSCATE("Auto Steal Pharsa (Trigger)"), &Config.Visual.PharsaTrigger);
	        ImGui::Checkbox(OBFUSCATE("Auto Steal Gusion (Trigger)"), &Config.Visual.Gusion33);
			ImGui::Checkbox(OBFUSCATE("Auto Steal Papuquito (Trigger)"), &Config.Visual.Papuquito33);
			ImGui::Checkbox(OBFUSCATE("Auto Steal Yve (Trigger)"), &Config.Visual.Yve33);
			ImGui::Spacing();
		    ImGui::EndGroupPanel();
			
			
			
			
				
		    ImGui::EndTabItem();
		    }
                
               if (ImGui::BeginTabItem("Other Menu")) {
	            show_another_hack = false;
	            ImGui::BeginGroupPanel("Unlock Menu (Risk)", ImVec2(0.0f, 0.0f));
				
				//Config.Visual.UnlockSkin = true;
				//Config.Visual.UnlockEmblem = true;
	           ImGui::Checkbox(OBFUSCATE("Unlock All Skin"), &Config.Visual.UnlockSkin);
		       ImGui::Checkbox(OBFUSCATE("Unlock All Emblem"), &Config.Visual.UnlockEmblem);
		        ImGui::Checkbox(OBFUSCATE("Unlock All Spell"), &Config.Visual.UnlockSpell);	
		        ImGui::Spacing();
		        
		        ImGui::BeginGroupPanel("Frame Rate", ImVec2(0.0f, 0.0f));
				
	            ImGui::Checkbox(OBFUSCATE("Set High FPS"), &isSetFPS);
		        ImGui::Checkbox(OBFUSCATE("High FPS Mode"), &isHighFPS);
				//ImGui::Text( "Dm To Buy Vip Mod Safe @erenmodzdev %s", expiretime.c_str());
				ImGui::Text("Owner KIMMY MODS");  
        ImGui::Text("Contract Details Rian127");  
        ImGui::Text("Telegram Channel https://t.me/kimychan21");
				
				
				
		        ImGui::Spacing();
		        ImGui::EndGroupPanel();
		        
		        
				
				
		        ImGui::Text(OBFUSCATE("Color ESP:"));
			             static int CLine = 0;
                        ImGui::Text(OBFUSCATE("Line & Box: "));
                        ImGui::SliderInt(OBFUSCATE("Colors"), &CLine, 0, 10);
                    switch (CLine) {
                        case 0: //White
                            RedLine = 255, GreenLine = 255, BlueLine = 255;
                      break;
                        case 1: //Red
                            RedLine = 255, GreenLine = 0, BlueLine = 0;
                        break;
                        case 2: //Green
                            RedLine = 0, GreenLine = 255, BlueLine = 0;
                        break;
                        case 3: //Blue
                            RedLine = 0, GreenLine = 0, BlueLine = 255;
                        break;
                        case 4: //Orange
                            RedLine = 255, GreenLine = 102, BlueLine = 0;
                        break;
                        case 5: //Yellow
                            RedLine = 255, GreenLine = 255, BlueLine = 0;
                        break;
                        case 6: //Cyan
                            RedLine = 0, GreenLine = 255, BlueLine = 255;
                        break;
                        case 7: //Black
                            RedLine = 0, GreenLine = 0, BlueLine = 0;
                	    break;
                        case 8: //Magenta
                            RedLine = 255, GreenLine = 0, BlueLine = 255;
                	    break;
                        case 9: //Purpel
                            RedLine = 213, GreenLine = 0, BlueLine = 249;
                        break;
                        case 10: //Teal
                            RedLine = 0, GreenLine = 128, BlueLine = 128;
                        break;
						}
                ImGui::Spacing();
		        ImGui::EndGroupPanel();
		        
		        ImGui::SameLine();
		        
		        
	            ImGui::EndTabItem();
	            }
           
            if (ImGui::BeginTabItem(OBFUSCATE("Room Info"))) {
			   show_another_hack = false;
			   bool show_another_kontol = false;
		   		 RoomInfoList();
					
					ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), OBFUSCATE("Team"));
					if (ImGui::BeginTable(OBFUSCATE("##Team"), 6, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
						ImGui::TableSetupColumn(OBFUSCATE("Name"), 0, 150);
						ImGui::TableSetupColumn(OBFUSCATE("User ID"), 0, 160);
						ImGui::TableSetupColumn(OBFUSCATE("Squad"), 0, 190);
						ImGui::TableSetupColumn(OBFUSCATE("Rank"), 0, 180);
						ImGui::TableSetupColumn(OBFUSCATE("Hero"), 0, 130);
						ImGui::TableSetupColumn(OBFUSCATE("Spell"), 0, 120);
						ImGui::TableSetupColumn(OBFUSCATE("Country"), 0, 200);
						ImGui::TableHeadersRow();
						
						for (int row = 0; row < 5; row++) {
							ImGui::TableNextRow();
							for (int column = 0; column < 6; column++) {
								ImGui::TableSetColumnIndex(column);
								char buf[32];
								if (column == 0) {
									sprintf(buf, OBFUSCATE("%s"), RoomInfo.PlayerR[row].Name.c_str());
									ImGui::TextUnformatted(buf);
								} else if (column == 1) {
									sprintf(buf, OBFUSCATE("%s"), RoomInfo.PlayerR[row].UserID.c_str());
									ImGui::TextUnformatted(buf);
								} else if (column == 2) {
									sprintf(buf, OBFUSCATE("%s"), RoomInfo.PlayerR[row].Squad.c_str());
									ImGui::TextUnformatted(buf);
								} else if (column == 3) {
									sprintf(buf, OBFUSCATE("%s"), RoomInfo.PlayerR[row].Rank.c_str());
									ImGui::TextUnformatted(buf);
								} else if (column == 4) {
									sprintf(buf, OBFUSCATE("%s"), RoomInfo.PlayerR[row].Hero.c_str());
									ImGui::TextUnformatted(buf);
								} else if (column == 5) {
									sprintf(buf, OBFUSCATE("%s"), RoomInfo.PlayerR[row].Spell.c_str());
									ImGui::TextUnformatted(buf);
								} else if (column == 6) {
									sprintf(buf, OBFUSCATE("%s"), RoomInfo.PlayerR[row].Country.c_str());
									ImGui::TextUnformatted(buf);
								}
							}
						}
						ImGui::EndTable();
					}
					
					ImGui::TextColored(ImVec4(0.0f, 0.8f, 1.0f, 1.0f), OBFUSCATE("Enemy"));
			if (ImGui::BeginTable(OBFUSCATE("##Enemy"), 6, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
						ImGui::TableSetupColumn(OBFUSCATE("Name"), 0, 150);
						ImGui::TableSetupColumn(OBFUSCATE("User ID"), 0, 160);
						ImGui::TableSetupColumn(OBFUSCATE("Squad"), 0, 190);
						ImGui::TableSetupColumn(OBFUSCATE("Rank"), 0, 180);
						ImGui::TableSetupColumn(OBFUSCATE("Hero"), 0, 130);
						ImGui::TableSetupColumn(OBFUSCATE("Spell"), 0, 120);
						ImGui::TableSetupColumn(OBFUSCATE("Country"), 0, 200);
						ImGui::TableHeadersRow();
						
						for (int row = 0; row < 5; row++) {
							ImGui::TableNextRow();
							
							for (int column = 0; column < 6; column++) {
								ImGui::TableSetColumnIndex(column);
								
								char buf[32];
								if (column == 0) {
									sprintf(buf, OBFUSCATE("%s"), RoomInfo.PlayerB[row].Name.c_str());
									ImGui::TextUnformatted(buf);
								} else if (column == 1) {
									sprintf(buf, OBFUSCATE("%s"), RoomInfo.PlayerB[row].UserID.c_str());
									ImGui::TextUnformatted(buf);
								} else if (column == 2) {
									sprintf(buf, OBFUSCATE("%s"), RoomInfo.PlayerB[row].Squad.c_str());
									ImGui::TextUnformatted(buf);
								} else if (column == 3) {
									sprintf(buf, OBFUSCATE("%s"), RoomInfo.PlayerB[row].Rank.c_str());
									ImGui::TextUnformatted(buf);
								} else if (column == 4) {
									sprintf(buf, OBFUSCATE("%s"), RoomInfo.PlayerB[row].Hero.c_str());
									ImGui::TextUnformatted(buf);
								} else if (column == 5) {
									sprintf(buf, OBFUSCATE("%s"), RoomInfo.PlayerB[row].Spell.c_str());
									ImGui::TextUnformatted(buf);
								} else if (column == 6) {
									sprintf(buf, OBFUSCATE("%s"), RoomInfo.PlayerR[row].Country.c_str());
									ImGui::TextUnformatted(buf);
											}
							}
						}
						ImGui::EndTable();
					}				
					
    }
            ImGui::EndTabBar();
            
     }

}



void DrawMenu() {
    //if (ImGui::Begin(OBFUSCATE("GMC TEST - Mobile Legends")), 0, ImGuiWindowFlags_NoSavedSettings) {          
    
    
if (ImGui::Begin(OBFUSCATE("VIP MIKASA|EXTERNAL|MODZ V0.1")), 0, ImGuiWindowFlags_AlwaysAutoResize) {        
        static bool isLogin = false, logginIn = false;
        static std::string err;
        if (!isLogin) {
            ImGui::Text(OBFUSCATE(" Please Login! (Copy Key to Clipboard)"));
                                
            ImGui::PushItemWidth(-1);
            static char s[150];
            ImGui::InputText("##key", s, sizeof s);
            
            ImGui::PopItemWidth();
            ImGui::PushItemWidth(-1);
            if (ImGui::Button(OBFUSCATE(" Paste Key  "), ImVec2(ImGui::GetWindowContentRegionWidth(), 0))) {
                auto key = getClipboard();
                strncpy(s, key.c_str(), sizeof s);
            }
            ImGui::PopItemWidth();
            
            ImGui::PushItemWidth(-1);
            
            if (ImGui::Button(OBFUSCATE("Login"), ImVec2(ImGui::GetWindowContentRegionWidth(), 0))) {
                err = Login(s);
                if (err == "OK") {
                    isLogin = bValid && g_Auth == g_Token;
                }
            }
            ImGui::PopItemWidth();
            
            if (!err.empty() && err != std::string(OBFUSCATE("OK"))) {
                ImGui::Text(OBFUSCATE("Error: %s"), err.c_str());
            }
            ImGui::PopItemWidth();
            
        } else {
    
    
    
    
    
    
            
                
                        
        static int draWStaticMenu;
    /*  ImGui::Text(OBFUSCATE("Hacks Options :"));
        ImGui::Spacing();
        ImGui::RadioButton(OBFUSCATE("Bypass"), &draWStaticMenu, 0);
            */
        if (draWStaticMenu == 0) {
            DrawMenuSafe();
        }       
        
    }
}}

void Tick() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(s_Width, s_Height);
    ImGui::NewFrame();
    
    //Draw ESP
    DrawESP(ImGui::GetBackgroundDrawList());
    UnlockSkin();
    
    handle_OnTouchEvent();
    ImGui::SetNextWindowCollapsed(true, ImGuiCond_::ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2((float) s_Width * 0.35f, (float) s_Height * 0.70f), ImGuiCond_FirstUseEver);
    
    DrawMenu();
    
    ImGui::End();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

