#include <stdio.h>      // использовать стандартные функции ввода-вывода
#include <math.h>       // функции математики
#include <assert.h>     // чтобы работал assert (вывод ошибки)

// сравнивает числа a и b с точностью до EPS
#define EPS 0.0001      // требуемая точность сравнения
int eps(float a, float b) { return fabs(a-b)<EPS; } // |a-b|<EPS

int main()                      // здесь начинается программа
{
    printf("Start test: \t\tHello, world!!!\n");

    // Если в консоли написать -DAAA, то программа будет считать,
    // что определен макрос "AAA": #define AAA
    #ifdef AAA
        printf("\n");
    #endif

    // Тестовый вывод (начало обучения)
    if (1 == 0) {
        printf("Возврат корректки \'\\r\'----\r~~~~!!!\n");
        printf("ab\t12345\tz\n");
        printf("<\t<\t<\t<\n");
        printf("Ускорение свободного падения g = [%6d]\n", 10);
        printf("Ускорение свободного падения g = [%6.3f]\n", 9.81);
        printf("как %12f или %12f\n", 22.f/7, 3.9999);
    }

    // Считывание по маске
    if (1 == 0) {
        int a = -1, b = -1;           // объявили переменные x и y типа int
        printf("Input a by mask: \'a#a\' = ");
        scanf("a%da", &a);    // ввели число и записали его в х
        printf("Input b by mask: \'b#b\' = ");
        scanf(" b%db", &b);    // ввели число и записали его в y
        printf("a(%d) + b(%d) = %d\n", a, b, a+b);    // печатаем ответ
    }

    // Считываем несколько чисел
    if (1 == 0) {
        int a = -1, b = -1;           // объявили переменные x и y типа int
        scanf("%d%d", &a, &b);
        printf("%d+%d = %d\n", a,b,a+b);    // печатаем ответ
    }

    // Инкремент и декремент
    if (1 == 0) {
        int x, y;
        x = 0; y = x + x;
        printf("x = 0; y = x   + x    res: x=%d y=%d\n", x,y);    // печатаем ответ
        x = 0; y = x++ + x;
        printf("x = 0; y = x++ + x    res: x=%d y=%d\n", x,y);    // печатаем ответ
        x = 0; y = ++x + x;
        printf("x = 0; y = ++x + x    res: x=%d y=%d\n", x,y);    // печатаем ответ
        x = 0; y = x + x++;
        printf("x = 0; y = x   + x++  res: x=%d y=%d\n", x,y);    // печатаем ответ
        x = 0; y = x + ++x;
        printf("x = 0; y = x   + ++x  res: x=%d y=%d\n", x,y);    // печатаем ответ
        x = 0; y = x++ + x++;
        printf("x = 0; y = x++ + x++  res: x=%d y=%d\n", x,y);    // печатаем ответ
        x = 0; y = ++x + x++;
        printf("x = 0; y = ++x + x++  res: x=%d y=%d \?\n", x,y);    // печатаем ответ
        x = 0; y = x++ + ++x;
        printf("x = 0; y = x++ + ++x  res: x=%d y=%d \?\n", x,y);    // печатаем ответ.
        x = 0; y = ++x + ++x;
        printf("x = 0; y = ++x + ++x  res: x=%d y=%d \?\n", x,y);    // печатаем ответ
    }

    // Тест вывода целых и вещественных чисел
    if (1 == 0) {
        float z = 0.375;
        int   x = 32;
        printf("Печатаю int   правильно:   \t x=%d\n", x);
        //printf("Печатаю int   неправильно: \t x=%f\n", x);
        printf("Печатаю float правильно:   \t z=%f\n", z);
        //printf("Печатаю float неправильно: \t z=%d\n", z);
    }

    // Округление чисел
    if (1 == 0) {
        float x = 0; // Будем округлять к целым и дробным числам
                  printf("    x  \t    ceil(x) floor(x) round(x) int(x) float(int(x))\n");
        x =  2.1; printf("x=%4.1f\t\t%2d\t %2d\t  %2d\t %2d\t%4.1f\n",
                         x, (int)ceil(x), (int)floor(x), (int)round(x), (int)x, (float)(int)x ) ;
        x =  2.7; printf("x=%4.1f\t\t%2d\t %2d\t  %2d\t %2d\t%4.1f\n",
                         x, (int)ceil(x), (int)floor(x), (int)round(x), (int)x, (float)(int)x ) ;
        x =  2.5; printf("x=%4.1f\t\t%2d\t %2d\t  %2d\t %2d\t%4.1f\n",
                         x, (int)ceil(x), (int)floor(x), (int)round(x), (int)x, (float)(int)x ) ;
        x = -2.1; printf("x=%4.1f\t\t%2d\t %2d\t  %2d\t %2d\t%4.1f\n",
                         x, (int)ceil(x), (int)floor(x), (int)round(x), (int)x, (float)(int)x ) ;
        x = -2.7; printf("x=%4.1f\t\t%2d\t %2d\t  %2d\t %2d\t%4.1f\n",
                         x, (int)ceil(x), (int)floor(x), (int)round(x), (int)x, (float)(int)x ) ;
        x = -2.5; printf("x=%4.1f\t\t%2d\t %2d\t  %2d\t %2d\t%4.1f\n",
                         x, (int)ceil(x), (int)floor(x), (int)round(x), (int)x, (float)(int)x ) ;
    }

    // Форматированный ввод-вывод (%% - экранирование процента)
    // %[флаги][ширина][.точность][размер]тип
    // Тип - это d, u, i, c, f и так далее (есть ещё %p и %z). l, ll, h, hh - это размер типа
    //  Флаг "+" - указывать явно знак числа, в том числе положительного.
    //  Флаг "-" - выравнивание влево по указанной ширине
    //  Флаг "0" - дополнять слева числа до указанной ширины не пробелами, а 0.
    // [ширина][.точность] %7.3 - число не меньше 7 символов, при этом после . 3 символа
    if (1 == 0) {
        int a = 3, b = -5;
        float c = 0.1234567890, d = -0.4567890123456789;
        printf("({%%d} {%%f}) a={%d} b={%d} c={%f} d={%f} (c=0.1234567890) (d=-0.4567890123456789)\n", a, b, c, d);
        printf("({%%d} {%%20.18f}) a={%d} b={%d} c={%20.18f} d={%20.18f}\n", a, b, c, d);
        printf("({%%9d}   {%%9f})     a={%9d} b={%9d} c={%9f} d={%9f}\n", a, b, c, d);
        printf("({%%9d}   {%%9.3f})   a={%9d} b={%9d} c={%9.3f} d={%9.3f}\n", a, b, c, d);
        printf("({%%+9d}  {%%+9.3f})  a={%+9d} b={%+9d} c={%+9.3f} d={%+9.3f}\n", a, b, c, d);
        printf("({%%+-9d} {%%+-9.3f}) a={%+-9d} b={%+-9d} c={%+-9.3f} d={%+-9.3f}\n", a, b, c, d);
        printf("({%%09d}  {%%09.3f})  a={%09d} b={%09d} c={%09.3f} d={%09.3f}\n", a, b, c, d);
        printf("({%%03d}  {%%07.3f})  a={%03d}       b={%03d}       c={%07.3f}   d={%07.3f}\n", a, b, c, d);


        // Вместо [ширина][.точность] можно записать %*.*f и подставить два доп. аргумента вначале
        int x = 15, y = 10;
        printf("{%%*.*f}   {%%15.10f}   M_PI={%*.*f}\n"  , x, y, M_PI); //M_PI={   3.1415926536}
        printf("{%%+*.*f}  {%%+15.10f}  M_PI={%+*.*f}\n" , x, y, M_PI); //M_PI={  +3.1415926536}
        printf("{%%-*.*f}  {%%-15.10f}  M_PI={%-*.*f}\n" , x, y, M_PI); //M_PI={3.1415926536   }
        printf("{%%+0*.*f} {%%+015.10f} M_PI={%+0*.*f}\n", x, y, M_PI); //M_PI={+003.1415926536}
    }

    // Форматированный вывод строк (%% - экранирование процента)
    // %[флаги][ширина][.точность]тип
    // Тип - это s
    // Флаг "-" - выравнивание влево по указанной ширине
    // Ширина - печатать n или более символов, с выравниванием вправо или влево (отрицательная ширина), дополняя пробелами.
    // Если строка длиннее, то ширина игнорируется.
    // Точность - если нужно обрезать строку. %.5s - не более 5 символов.
    if (1 == 0) {
        printf("{%%5s} \t"  " <%5s> \ts=\'abc\'\n"        , "abc");           // <  abc>
        printf("{%%-5s}\t"  " <%-5s> \ts=\'abc\'\n"        , "abc");           // <abc  >
        printf("{%%5s} \t"  " <%5s> \ts=\'\abcdefghijk'\n", "abcdefghijk");   // <abcdefghijk>
        printf("{%%.5s}\t"  " <%.5s> \ts=\'abcdefghijk\'\n", "abcdefghijk");   // <abcde>
        printf("{%%.5s}\t"  " <%.5s> \t\ts=\'abc\'\n"      , "abc");           // <abc>
        printf("{%%5.5s}\t" " <%5.5s> \ts=\'abc\'\n"       , "abc");           // <  abc>
        printf("{%%-5.5s}"  " <%-5.5s> \ts=\'abc\'\n"      , "abc");           // <abc  >
    }

    // #include <assert.h>     // чтобы работал assert (вывод ошибки)
    // #define EPS 0.0001      // требуемая точность сравнения
    // А Вообще, лучше не использовать функцию assert - она останавливает программу и не имеет описания ошибки.
    if (1 == 0) {
        float pi = 22/7.003f;    // Так Архимед вывел число Pi (Добавил 7.003 и точность стала устраивать)
        //float pi = 22/7.0f;    // Так Архимед вывел число Pi (Не проходит точность)
        printf("Pi={%f} M_PI={%f} |a-b|={%f} EPS={%f} eps={%d}\n",
               pi, M_PI, fabs(pi - M_PI), EPS, eps(pi, M_PI) ); // Сравниваем вещественные числа с точностью EPS
        assert(eps(M_PI, pi)); // Если False, то остановка программы и вывод текстового описания условия в консоль
        printf("Pi={%f} M_PI={%f} |a-b|={%f} EPS={%f} eps={%d}\n",
               pi, M_PI, fabs(pi - M_PI), EPS, eps(pi, M_PI) ); // Сравниваем вещественные числа с точностью EPS
    }

    // Демонстрация работы с указателями
    if (1 == 0) {
        int       x = 123;
        int   *   p = &x;
        int  **  pp = &p;
        int *** ppp = &pp;

        printf("     x = %d\n",      x);    // целое
        printf("     p = %p\n",      p);    // ссылка
        printf("    *p = %d\n",     *p);
        printf("    pp = %p\n",     pp);
        printf("   *pp = %p\n",    *pp);
        printf("  **pp = %d\n",   **pp);
        printf("   ppp = %p\n",    ppp);
        printf("  *ppp = %p\n",   *ppp);
        printf(" **ppp = %p\n",  **ppp);
        printf("***ppp = %d\n", ***ppp);
    }

    // Демонстрация размера типа данных
    if (1 == 0) {
        int x = 123;
        printf("sizeof x          ); %zu\n", sizeof x          ); // 4 в моей системе и на repl.it
        printf("sizeof(x)         ); %zu\n", sizeof(x)         ); // 4 в моей системе и на repl.it
        printf("sizeof(1 + 2)     ); %zu\n", sizeof(1 + 2)     ); // 4 в моей системе и на repl.it
        printf("sizeof 3.5        ); %zu\n", sizeof 3.5        ); // 8 в моей системе и на repl.it
        printf("sizeof(3.5)       ); %zu\n", sizeof(3.5)       ); // 8 в моей системе и на repl.it
        printf("sizeof(char)      ); %zu\n", sizeof(char)      ); // 1 всегда
        printf("sizeof(short)     ); %zu\n", sizeof(short)     );
        printf("sizeof(int)       ); %zu\n", sizeof(int)       );
        printf("sizeof(long)      ); %zu\n", sizeof(long)      );
        printf("sizeof(long long) ); %zu\n", sizeof(long long) );
        printf("sizeof(float)     ); %zu\n", sizeof(float)     );
        printf("sizeof(double)    ); %zu\n", sizeof(double)    );
        printf("sizeof(char*  )   ); %zu\n", sizeof(char*  )   ); // указатели
        printf("sizeof(double*)   ); %zu\n", sizeof(double*)   ); // указатели
        printf("sizeof(int*   )   ); %zu\n", sizeof(int*   )   ); // указатели
        printf("sizeof(void*  )   ); %zu\n", sizeof(void*  )   ); // указатели
        printf("sizeof(int**  )   ); %zu\n", sizeof(int**  )   ); // указатели
        printf("sizeof(int*** )   ); %zu\n", sizeof(int*** )   ); // указатели
      //printf("sizeof char       ); %zu\n", sizeof char       ); // ОШИБКА, тип необходимо указывать в скобках ()
      //printf("sizeof x          ); %zu\n", sizeof x          ); // Ошибки не будет. можно "sizeof x" или "sizeof(x)"
    }

    // Демонстрация инициализации указателей
    if (1 == 0) {
        int x = 123;
        int *p = NULL;
        printf("int *p = NULL   |  p = <%p> \t\t| &p = <%p>\n", p, &p);    // ссылка
        if (p == NULL) printf("(p == NULL) - Указатель p не инициализирован \n");
        if (!p)        printf("(!p)        - Указатель p не инициализирован \n");
        p = &x;
        printf("x = <%d>,        &x = <%p>\n", x, &x);         // int and ссылка
        printf("p = &x, x = 123 |  p = <%p> | &p = <%p>\n",  p, &p);    // ссылка
        printf("p = &x, x = 123 | *p = <%d> \t\t| &p = <%p>\n", *p, &p);    // int
        p = NULL;
        printf("p = NULL        |  p = <%p> \t\t| &p = <%p>\n", p, &p);    // ссылка на ссылку
    }

    // Демонстрация работы с кодировками
    if (1 == 0) {
        int x = 0;
        for(unsigned char c = 0; c >= 0 && c <= 255 && 1==0; c++) {
            // печать ASCII код символа
            printf("символ %c \tASCII код %d \tsizeof(char)=%zu\n", c, c, sizeof(c));
            if (c == '!') x++;
            if (x == 2) break;
        }
        // char c = 'Я';
        // printf("символ %c, ASCII код %d\n", c, c);
        // unsigned char c = 200;
        // printf("символ %c, ASCII код %d\n", c, c);

        // ДЕЛАЕМ ВЫВОД:
        // В Убунту и в языке Си - Русских символов нет (в char точно)
    }

    // Демонстрация работы с кодировками (считывание символа с клавы)
    if (1 == 0) {
        // Так было раньше (char)
        if (1 == 0) {
            char с;
            scanf("%c", &с);                            // нажмем на клавиатуре клавишу Q и далее Enter
            printf("символ %c, ASCII код %d\n", с, с);  // символ Q, ASCII код 81
            // Считать удалось только Английские символы.
        }

        if (1 == 1) {
            // Так сейчас (2026 год)
            int x /*, y*/;       // да, именно int
            x = getchar();  // нажмем на клавиатуре клавишу Q и далее Enter
            putchar(x);     // Q
            printf("символ %c, ASCII код %d\n", x, x);  // символ Q, ASCII код 81
            // scanf("%c", &y);
            // printf("символ %c, ASCII код %d\n", y, y);  // символ Q, ASCII код 81
        }

        // ВЫВОД:
        // Данная хрень тоже не работает. Нормально счтать не получается
        // Либо компилятор, либо консоль Русские символы не обрабатывает.
    }


    return 0;                   // конец программы
}
