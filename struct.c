#include <stdio.h>      // использовать стандартные функции ввода-вывода
#include <math.h>       // функции математики
#include <assert.h>     // чтобы работал assert (вывод ошибки)

// сравнивает числа a и b с точностью до EPS
#define EPS 0.0001      // требуемая точность сравнения
int eps(float a, float b) { return fabs(a-b)<EPS; } // |a-b|<EPS


int main() // здесь начинается программа
{
    printf("Start test: \t\tStruct!!!\n");  // печать строки Hello, world!

    // Если в консоли написать -DAAA, то программа будет считать,
    // что определен макрос "AAA": #define AAA
    #ifdef AAA
        printf("\n");
    #endif


    // Объявление структуры Student
    if (1 == 1) {
        // Объявление структуры
        struct Student {
            long id;
            int birth_year;         // год рождения
            float weight;           // вес, кг
            float height;           // рост, м
            float run100;           // время забега на 100м, сек
            unsigned char pushup;   // отжиманий
            unsigned char pullup;   // подтягиваний
        };  // <---- Не забудь про ;

        void infoStudent(struct Student student) {
            printf("%6ld %4d %4.1f %4.2f %5.2f %u %u\n",
            student.id, student.birth_year, student.weight, student.height, student.run100, student.pullup, student.pullup);
        };

        struct Student gusev;       // объявили переменную `gusev` типа `struct Student`
        struct Student ivanov = {315101, 2000, 70.4, 1.86, 17.6, 14, 5}; // С явной идентификацией переменной
        struct Student petrov = {315102, 1999}; // указаны только id и birth_year остальные поля 0
        struct Student sidorov = {.weight=56.6, .height=1.62, .id=315103}; // При инициализации можно указать имя поля, тогда данные можно перечислять в любом порядке:
        struct Student zotov;           // ok
        //zotov = {315109, 2001, 61.8};   // Ошибка! // Нельзя (можно только при инициализации переменной):
        zotov = (struct Student){315109, 2001, 61.8};   // ok // Однако, можно создать анонимную структуру {315109, 2001, 61.8}, привести ее к типу struct Student и присвоить (дальше разберем этот пример подробнее).
        gusev = sidorov;   // sidorov того же типа, что и gusev
        // Нельзя копировать структуры разных типов, даже если у них одинаковое количество и типы полей.

        infoStudent((struct Student){});
        infoStudent(ivanov);
        infoStudent(petrov);
        infoStudent(sidorov);
        infoStudent(zotov);
        infoStudent(gusev);
    }//Student

    // Инициализация и копирование структур
    if (1 == 1) {
        struct Fruit {
            int price;    // рубли
            float weight; // кг
        };
        struct Human {
            int age;      // возраст, полных лет
            float height; // рост, метры
        };

        // полтора килограмма по 200 рублей за килограмм
        struct Fruit apple = {.price = 200, .weight = 1.5};
        struct Human vasya;
        //vasya = apple;                                      // Ошибка
        vasya = (struct Human){18, 1.76};                   // ок
        vasya = (struct Human){.age = 18, .height = 1.76};  // ок, начиная с C99 (или GNU extension)
        //Здесь {18, 1.76} - экземпляр анонимной структуры, в этой структуре неизвестно заранее сколько полей, какого они типа и тем более - название полей.
        //Поэтому написать в анонимной структуре {.age = 18, .height = 1.76}, как мы писали раньше, при инициализации переменной apple, можно только начиная с С99 или если вы используете компилятор с поддержкой GNU extension.
        //scanf("%d", &zotov.id); // скобки не нужны, приоритет . больше, чем приоритет &

        printf("%2d %4.2f\n", vasya.age, vasya.height);
    }//Student


    return 0;                   // конец программы
}
