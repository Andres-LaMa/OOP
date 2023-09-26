class Point{
private:
    int x;
    int y;
public:
    int speed_x;
    int speed_y;
    int *rgba_color;

    Point();
    void reflection(int x, int y);
    int get_x();
    int get_y();
    void set_x(int new_x);
    void set_y(int new_y);
};