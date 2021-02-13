#include "raylib.h"

int main() // the function header
{ // start of the main function

	// Initialization
	InitWindow(800, 450, "Dodge the Axe!");

	// X position of the dot
	int dotX = 200;
	// Y position of the axe
	int squareY = 0;
	// direction (will change sign based on axe's direction)
    int direction = 30;

	// Refresh the canvas twice per second
	SetTargetFPS(60);

	while (WindowShouldClose() == false) 
	{

		// Set up the canvas to start drawing
		BeginDrawing();

		// Clear the background
		ClearBackground(WHITE);

		// is there a fatal hit by the axe?
		if ((squareY < 240 && squareY > 160) && (dotX > 360 && dotX < 440))
		{
			DrawText("Game Over!", 400, 200, 20, RED);
		}
		else
		{
			// Draw the dot to the screen
			DrawCircle(dotX, 200, 30, BLUE);
			DrawRectangle(400, squareY, 20, 20, RED);

			if (IsKeyDown(KEY_D))
			{
				// D key is being pressed
				dotX = dotX + 20;
			}
			if (IsKeyDown(KEY_A))
			{
				// A key is being pressed
				dotX = dotX - 20;
			}
			// Update the axe's location
			squareY = squareY + direction;
			// Check to see if the axe reaches the upper/lower bounds
			if (squareY > 450 || squareY < 0)
			{
				direction = -direction;
			}
		}



		// End drawing to the canvas
		EndDrawing();
	}

	// the return statement
	return 0;
} // end of the main function