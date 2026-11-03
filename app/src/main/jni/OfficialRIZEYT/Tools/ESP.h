#pragma once

#define ARGB(a, r, g, b) 0 | a << 24 | r << 16 | g << 8 | b

float Rainbow() {
	static float x = 0, y = 0;
	static float r = 0, g = 0, b = 0;
	if (y >= 0.0f && y < 255.0f) {
		r = 255.0f;
		g = 0.0f;
		b = x;
	} else if (y >= 255.0f && y < 510.0f) {
		r = 255.0f - x;
		g = 0.0f;
		b = 255.0f;
	} else if (y >= 510.0f && y < 765.0f) {
		r = 0.0f;
		g = x;
		b = 255.0f;
	} else if (y >= 765.0f && y < 1020.0f) {
		r = 0.0f;
		g = 255.0f;
		b = 255.0f - x;
	} else if (y >= 1020.0f && y < 1275.0f) {
		r = x;
		g = 255.0f;
		b = 0.0f;
	} else if (y >= 1275.0f && y < 1530.0f) {
		r = 255.0f;
		g = 255.0f - x;
		b = 0.0f;
	}
	x+= 0.25f; 
	
	if (x >= 255.0f)
		x = 0.0f;
	y+= 0.25f;
	if (y > 1530.0f)
		y = 0.0f;
	return ImColor((int)r, (int)g, (int)b, 255);
}

bool isOutsideScreen(ImVec2 pos, ImVec2 screen) {
    if (pos.y < 0) {
        return true;
    }
    if (pos.x > screen.x) {
        return true;
    }
    if (pos.y > screen.y) {
        return true;
    }
    return pos.x < 0;
}

ImVec2 pushToScreenBorder(ImVec2 Pos, ImVec2 screen, int offset) {
    int x = (int) Pos.x;
    int y = (int) Pos.y;
    if (Pos.y < 0) {
        // top
        y = -offset;
    }
    if (Pos.x > screen.x) {
        // right
        x = (int) screen.x + offset;
    }
    if (Pos.y > screen.y) {
        // bottom
        y = (int) screen.y + offset;
    }
    if (Pos.x < 0) {
        // left
        x = -offset;
    }
    return ImVec2(x, y);
}

void drawLine(long color, float thickness, Vector3 start, Vector3 end) {
	ImGui::GetBackgroundDrawList()->PathLineTo(ImVec2(start.x, start.y));
    ImGui::GetBackgroundDrawList()->PathLineTo(ImVec2(end.x, end.y));
    ImGui::GetBackgroundDrawList()->PathStroke(color, 0, thickness);
}

void DrawBoxEnemy(ImVec2 X, ImVec2 Y, float thicc, int color) {
    drawLine(color, thicc, {X.x, X.y}, {Y.x, Y.y});
}

void drawBox(long color, float stroke, ImVec4 rect) {
	ImVec2 v1(rect.x, rect.y);
	ImVec2 v2(rect.x + rect.z, rect.y);
	ImVec2 v3(rect.x + rect.z, rect.y + rect.w);
	ImVec2 v4(rect.x, rect.y + rect.w);
	
	ImGui::GetBackgroundDrawList()->AddLine({v1.x, v1.y}, {v2.x, v2.y}, color, 2.0f);
	ImGui::GetBackgroundDrawList()->AddLine({v2.x, v2.y}, {v3.x, v3.y}, color, 2.0f);
	ImGui::GetBackgroundDrawList()->AddLine({v3.x, v3.y}, {v4.x, v4.y}, color, 2.0f);
	ImGui::GetBackgroundDrawList()->AddLine({v4.x, v4.y}, {v1.x, v1.y}, color, 2.0f);
}

void drawBoxDistance(ImVec2 pos) {
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(pos.x - 44.0f, pos.y - 18.0f), ImVec2(pos.x - 79.0f, pos.y + 6.0f), ImColor(255, 0, 255, 100), 0);
	ImGui::GetBackgroundDrawList()->AddRect(ImVec2(pos.x - 44.0f, pos.y - 18.0f), ImVec2(pos.x - 79.0f, pos.y + 6.0f), ImColor(255, 255, 255, 255), 2.0f);
}

void drawAlertBot(ImVec2 pos, long color) {
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(pos.x - 44.0f, pos.y - 18.0f), ImVec2(pos.x - 79.0f, pos.y + 6.0f), color, 0);
	ImGui::GetBackgroundDrawList()->AddRect(ImVec2(pos.x - 44.0f, pos.y - 18.0f), ImVec2(pos.x - 79.0f, pos.y + 6.0f), ImColor(255, 255, 255, 255), 2.0f);
}

void drawAlertPlayer(ImVec2 pos, long color) {
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(pos.x - 44.0f, pos.y - 18.0f), ImVec2(pos.x - 79.0f, pos.y + 6.0f), color, 0);
	ImGui::GetBackgroundDrawList()->AddRect(ImVec2(pos.x - 44.0f, pos.y - 18.0f), ImVec2(pos.x - 79.0f, pos.y + 6.0f), ImColor(255, 255, 255, 255), 2.0f);
}

void drawHorizontalHealthBar(Vector3 screenPos, float width, float maxHealth, float currentHealth) {
	screenPos -= Vector3(0.0f, 8.0f);
	drawBox(ImColor(0, 0, 0, 255), 3, ImVec4(screenPos.x, screenPos.y, width + 2, 5.0f));
	
	screenPos += Vector3(1.0f, 1.0f);
	long clr = ImColor(0, 255, 0, 255);
	
	float hpWidth = (currentHealth * width) / maxHealth;
	if (currentHealth <= (maxHealth * 0.6)) {
		clr = ImColor(255, 255, 0, 255);
	}
	
	if (currentHealth < (maxHealth * 0.3)) {
		clr = ImColor(255, 0, 0, 255);
	}
	drawBox(clr, 3, ImVec4(screenPos.x, screenPos.y, hpWidth, 3.0f));
}
