#include <iostream>
#include <cstring>

class Counter
{
private:
    int x = 0;
public:
    void increment() { ++x;}
    void decrement()   { --x;}
    int checkState() { return x; }
    Counter()              { x = 1; }
    Counter(int x)         { this->x = x; }
    
};

void game(Counter res)
{
    char comcom = 0;
    do
    {

        std::cout << "Введите команду('+', '-', '=' или 'x') :";
        std::cin >> comcom;
        switch (comcom)
        {
        case '+': res.increment(); break;
        case '-': res.decrement(); break;
        case '=':
        {
            std::cout << res.checkState() << std::endl;
            break;
        }
        case 'x': std::cout << "До свидания!"; break;
        default: std::cout << "Нет такой команды! Еще раз!" << std::endl;
        }

    } while (comcom != 'x');
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int xx = 0;
    std::string ansans = "";
    char comcom = 0;
    do
    {
        std::cout << "Вы хотите указать начальное значение счётчика? Введите yes или no: ";
        std::cin >> ansans;
        if (ansans == "no")
        {
            Counter res;
            game(res);
            
        }
        else if (ansans == "yes")
        {
            std::cout << "Введите начальное значение счётчика: ";
            std::cin >> xx;
            Counter res(xx);
            game(res);
        }
        else
        {
            std::cout << "Неверный ввод. Попробуйте снова!" << std::endl;
        }
    } while (ansans != "no" && ansans != "yes");

    return 0;
}
