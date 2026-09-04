#include "raylib.h"
#include <cmath>

static constexpr int screenWidth = 1920 / 2, screenHeight = 1080 / 2;

int main()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);
    InitWindow(screenWidth, screenHeight, "Game name");

    while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);

		// rainbow triangle
		{
			static unsigned char rainbowNum{0};

			DrawTriangle(
				Vector2{static_cast<float>(screenWidth / 2), static_cast<float>(screenHeight / 2 - 100)},
				Vector2{static_cast<float>(screenWidth / 2 - 100), static_cast<float>(screenHeight / 2 + 100)},
				Vector2{static_cast<float>(screenWidth / 2 + 100), static_cast<float>(screenHeight / 2 + 100)},
				Color{
					static_cast<unsigned char>((1 + sin(0.3 * rainbowNum)) * 127.5),
					static_cast<unsigned char>((1 + sin(0.3 * rainbowNum + 2)) * 127.5),
					static_cast<unsigned char>((1 + sin(0.3 * rainbowNum + 4)) * 127.5),
					255}
			);

			rainbowNum++;
			if (rainbowNum > 256) {
				rainbowNum = 0;
			}
		}

		EndDrawing();
    }

    return 0;
}