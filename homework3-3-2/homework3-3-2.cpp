#include <iostream>
#include <cstring>

class Counter
{
private:
    int x = 0;
public:
    int increment(int x) { this->x = this->x++; return this->x; }
    int decrement(int x)   { this->x = this->x--; return this->x;}
    void checkState(int x)  { this->x = this->x; std::cout << x << std::endl; }
    Counter()              { this->x = 1; }
    Counter(int x)         { this->x = x; }
    void game()
    {
        char comcom = 0;
        do
        {
            std::cout << "Введите команду('+', '-', '=' или 'x') :";
            std::cin >> comcom;
            switch (comcom)
            {
            case '+': increment(x); break;
            case '-': decrement(x); break;
            case '=': checkState(x); break;
            case 'x': std::cout << "До свидания!"; break;
            default: std::cout << "Нет такой команды! Еще раз!" << std::endl;
            }

        } while (comcom != 'x');
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int xx = 0;
    std::string ansans = "";
    do
    {
        std::cout << "Вы хотите указать начальное значение счётчика? Введите yes или no: ";
        std::cin >> ansans;
        if (ansans == "no")
        {
            Counter res;
            res.game();
            
        }
        else if (ansans == "yes")
        {
            std::cout << "Введите начальное значение счётчика: ";
            std::cin >> xx;
            Counter res(xx);
            res.game();
        }
        else
        {
            std::cout << "Неверный ввод. Попробуйте снова!" << std::endl;
        }
    } while (ansans != "no" && ansans != "yes");

    return 0;
}
