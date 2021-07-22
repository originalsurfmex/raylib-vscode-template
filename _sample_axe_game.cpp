#include "raylib.h"

int main()
{
    //window dims
    int width{399};
    int height{230};
    InitWindow(width, height, "caca's window");

    //circle coords
    int circle_x{width / 2};
    int circle_y{height / 2};
    int circle_r{25};
    int l_circle_x{circle_x - circle_r};
    int r_circle_x{circle_x + circle_r};
    int t_circle_y{circle_y - circle_r};
    int b_circle_y{circle_y + circle_r};

    //axe coords
    int axe_x{width - (width / 3)};
    int axe_y{0};
    int axe_size{50};
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_size};
    int t_axe_y{axe_y};
    int b_axe_y{axe_y + axe_size};

    //stuff
    SetTargetFPS(60);
    int direction{2};
    bool collision_with_axe{false};
    int cacacount{0};

    while (WindowShouldClose() != true)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        DrawCircle(circle_x, circle_y, circle_r, ORANGE);
        DrawRectangle(axe_x, axe_y, axe_size, axe_size, GREEN);

        //move circle
        if (IsKeyDown(KEY_D) && circle_x < width)
        {
            circle_x++;
        }
        else if (IsKeyDown(KEY_A) && circle_x > 0)
        {
            circle_x--;
        }
        else if (IsKeyDown(KEY_W) && circle_y > 0)
        {
            circle_y--;
        }
        else if (IsKeyDown(KEY_S) && circle_y < height)
        {
            circle_y++;
        }

        //move axe
        axe_y += direction;
        if (axe_y >= height - axe_size || axe_y <= 0)
        {
            direction = -direction;
        }

        //collisions
        l_circle_x = circle_x - circle_r;
        r_circle_x = circle_x + circle_r;
        t_circle_y = circle_y - circle_r;
        b_circle_y = circle_y + circle_r;
        l_axe_x = axe_x;
        r_axe_x = axe_x + axe_size;
        t_axe_y = axe_y;
        b_axe_y = axe_y + axe_size;

        DrawText(TextFormat("circle left: %i", l_circle_x), 3, 10, 10, BLACK);
        DrawText(TextFormat("circle right: %i", r_circle_x), 3, 20, 10, BLACK);
        DrawText(TextFormat("circle top: %i", t_circle_y), 3, 30, 10, BLACK);
        DrawText(TextFormat("circle bottom: %i", b_circle_y), 3, 40, 10, BLACK);
        DrawText(TextFormat("axe left: %i", l_axe_x), 3, 60, 10, BLACK);
        DrawText(TextFormat("axe right: %i", r_axe_x), 3, 70, 10, BLACK);
        DrawText(TextFormat("axe top: %i", t_axe_y), 3, 80, 10, BLACK);
        DrawText(TextFormat("axe bottom: %i", b_axe_y), 3, 90, 10, BLACK);
        DrawText(TextFormat("such caca: %i", cacacount), 3, height - 10, 10, RED);
        if ((r_circle_x > l_axe_x && l_circle_x < r_axe_x && t_circle_y < b_axe_y && b_circle_y > t_axe_y))// ||
            //(r_circle_x > l_axe_x && b_circle_y > t_axe_y) ||
            //(t_circle_y < b_axe_y && l_circle_x < r_axe_x) ||
            //(r_circle_x > l_axe_x && b_circle_y > t_axe_y) )
        {
            collision_with_axe = true;
        }
        else
        {
            collision_with_axe = false;
        }
        if (collision_with_axe == true)
        {
            DrawText("caca!", width / 2, height / 2, 20, RED);
            cacacount++;
        }

        EndDrawing();
    }
}